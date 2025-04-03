/*
* Copyright (c) File 2016-08-11,SHENZHEN HANGSHENG NEW ENERGY Co.,Ltd.
* All Rights Reserved.
* Dept.: Software Department
* File:
* Description: network layer parameters configurations
* REQ IDs:
* History:
* 2017-12-25 Draft version
*/

/* ---- Source switch on ------------------------------------------------------*/
#define UDS_C_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "LinTp_export.h"
#include "uds_types.h"
#include "uds_pri.h"
#include "uds_cfg.h"
#include "uds.h"
#include "uds_user.h"
#include "fbl_infor.h"
#include "tle_device.h"
//#include "Flash_IF.h"
#include "MID_Interface.h"
/*-----------------------------------------------------------------------------
                   		Module local defines and constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                                 Module local types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                Local data at RAM
------------------------------------------------------------------------------*/
/* ------------ UDS service session and security management ------- */
static uds_byte_t actSessionIndex = 0;
static uds_byte_t actSaLockerMask  = servm_saLv_allLocked; /* 1 for locked, 0 for unlocked */
/* UDS current request service ID */
static uds_byte_t curRequestServID = servm_servID_empty; /* Current request service ID */
static uds_byte_t curRequestSubFunc = 0u;   /* Current request service sub-function */
static uds_bool_t rspSizeValid = TRUE;         /* Response message size valid flag (Not out range of NT response buffer size) */

/* ------------ RAM variables for [pre-define service] ------------ */
/* Automatic switch and locked session time */
static uds_dWord_t sv_swStdAutoLockTick = 0;
/* security access protect related */
static uds_byte_t sv_saOrgType = 0; /* Log the last security access type. It will reset to 0 when session switch */
static uds_byte_t sv_saSeedUnCheckMask = servm_saLv_allSeedChecked; /* Mask the target access, Mask position as same as SA level mask */
/* DID read, write */
static udsDIDrwBkc_t sv_didRwBkcItem =
{
    /* bkcState */ servm_didRwBkcState_idle,
    /* index    */ servm_didRwBkcInvalidIndex
};

static udsMemBkc_t sv_memBkcItem =
{
	servm_memRwBkcState_idle,
	servm_memRwBkcInvalidIndx
};


/*------------------------------------------------------------------------------
                                Local data at ROM
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Local data at EEPROM
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                Global data at RAM
------------------------------------------------------------------------------*/
/* Routine ID control */
uds_dWord_t rtCtrlBkcMask = 0ul; /* Max support first 32 routine to have task */
/* ------------ End RAM variables for [pre-define service] -------- */

/* -------- Non-Volatile varialbes for [pre-define service] ------- */
/* SA service invalid access count */
uds_byte_t sv_saInvalidAccessCnt = 0u;
//#define sv_saInvalidAccessCnt (fblNvmDts_ram2.saInvalidAccessCnt)
/* SA service protect delay tick
 * When delay tick is zero(0) it will can allowed access SA service */
uds_dWord_t sv_saProtectDelayTick = 0u;
/* -------- End Non-Volatile varialbes for [pre-define service] --- */
/*------------------------------------------------------------------------------
                                Global data at ROM
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Global data at EEPROM
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                         Declaration of local functions
------------------------------------------------------------------------------*/
static void uds_requestValid(void);
static void uds_enterDefaultSession(void);
static void uds_autoRtSaProtect_task(void); /* auto sw default ss, Sa protect */
static void uds_didRwBkc_task(void);        /* DID read, write background callback task  */
static void serv_pushDIDtoRsp(uds_word_t did_i);
static void serv_didWriteActiveRsp(uds_word_t did_i);
static void uds_didRwBkc_clear(void);
static void uds_rtCtrBkc_task(void);
static void uds_memRwBkc_task(void);
static void uds_memRwBck_clear(void);
static void serv_memoryReadPositiveRsp(uds_dWord_t memoryAddr,uds_word_t memorySize);

static uint32 JumpAddress;
static uint32 APPLICATION_ADDRESS;



void RunbootCode(void)
{

  APPLICATION_ADDRESS = 0x0;      
	INT_Disable_Global_Int();
	(void)WDT1_Service();
	WDT1_SOW_Service(3);
  CPU->VTOR.reg = APPLICATION_ADDRESS;
	JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS+4);
	__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
  ((void(*)(void))JumpAddress)();


}



/*------------------------------------------------------------------------------
                      Implementation of global functions
------------------------------------------------------------------------------*/
/*
 * Function: uds_requestProcess
 * Param<void>:
 * Return<void>:
 * Discription: UDS service request process
 * Note: Call by NT layer, when call this function the NT is been locked.
 *       It will can not handle any NT frame before NT unlock
 *       We can call nt_rsp_start or nt_unlock function to unlock NT layer
*/
void uds_requestProcess(void)
{
    uds_byte_t serv_i = 0;

    /* Get request service basic information */
    curRequestServID = nt_req_pop_dt(0u);
    curRequestSubFunc = nt_req_pop_dt(0u);
    /* Set the load data pointer to SID + 1 (SID is store in 0 index) */
    nt_req_pos_set(1); /* Make sure the service process function first read data is the service request first data or sub-function */

    /* Set response size to valid */
    rspSizeValid = TRUE;
    /* Pre-push positive response service id */
    nt_rsp_reset();
    nt_rsp_push_dt(servm_positiveResponeCode(curRequestServID));

	uds_requestValid();
		
    /* Search service, and get service index if it is support */
    for (; serv_i < udsServCnt; serv_i++)
    {
        if (udsServCfg[serv_i].sid == curRequestServID)
        {
            /* Find service */
            break;
        }
    }

    /* check search result */
    if (serv_i < udsServCnt)
    {
        /* Find service */
        /* Session Support Check */
        if (0 != (udsServCfg[serv_i].ssSptMask & servm_ssSptMask(actSessionIndex)))
        {
            /* Service support in active session */
            /* Security unlock denied check */
            if ((0u == udsServCfg[serv_i].saDeniedMask)
                || ((udsServCfg[serv_i].saDeniedMask & actSaLockerMask) != udsServCfg[serv_i].saDeniedMask))
            {
                /* Have one or more SA level was be unlocked of this request service ID */
                /* Min. data length check. */
                if (nt_req_remain_len() >= udsServCfg[serv_i].minDLC)
                {
                    /* Request data length is above or equre the min. length limit */
                    /* Call back function valid check */
                    if (NULL_PTR != udsServCfg[serv_i].processCallBack)
                    {
                        /* call service process function */
                        udsServCfg[serv_i].processCallBack();
                    }
                    else
                    {
                        uds_negativeRsp(nrsp_serviceNotSupported);
                    }
                }
                else
                {
                    uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
                }
            }
            else
            {
                uds_negativeRsp(nrsp_securityAccessDenied);
            }
        }
        else
        {
            uds_negativeRsp(nrsp_serviceNotSupportedInActiveSession);
        }
    }
    else
    {
        //uds_negativeRsp(nrsp_serviceNotSupportedInActiveSession);
        uds_negativeRsp(nrsp_serviceNotSupported);
    }

    /* dead lock detect */
    if ((TRUE == uds_isNotYetRsp())
        && (FALSE == uds_isRspPending()))
    {
        /* If not send real response or no response pending, unlock NT layer */
        nt_unlock();
    }

}

/*
 * Function:ProtStk_UDS_Init
 * Param<void>:
 * Return<void>:
 * Discription: Initial UDS service to default state.
 * Note: Will check SA protect denied.
*/
void ProtStk_UDS_Init(void)
{
    /* initial service and security access locker to default state */
    /* Clear uds session auto switch timer */
    sv_swStdAutoLockTick = 0;
    /* Reset session to default and locked all SA */
    actSessionIndex = 0;    /* set session to default again */
    /* Clear seed un-check mask */
    sv_saSeedUnCheckMask = servm_saLv_allSeedChecked;
    /* re-locked all SA levels */
    actSaLockerMask = servm_saLv_allLocked;
    /* reset uds current request service ID log */
    curRequestServID = servm_servID_empty;

    /* clear background task */
    /* clear DID read,write background task */
    sv_didRwBkcItem.bkcState = servm_didRwBkcState_idle;
    sv_didRwBkcItem.index = servm_didRwBkcInvalidIndex;
    /* clear routine control background task */
    rtCtrlBkcMask = 0ul;

    /*refer to FAW req, protect time shall be invoked if fail cnt != 0*/
	if(sv_saInvalidAccessCnt > 0)	
	{
		sv_saProtectDelayTick = saProtectDelayTime;
	}
	else
	{
		//sv_saProtectDelayTick = 1;
	}
}

/*
 * Function:uds_task
 * Param<void>:
 * Return<void>:
 * Discription: UDS backgroud task process
 * Note: call it by cycle (eg. 1ms). Some timer prameter is calculate with this function call cycle (eg. sv_swStdAutoLockTick, sv_saProtectDelayTick).
*/
void uds_task(void)
{
	if(nt_is_RequestCompleted())
	{
		uds_requestProcess();
	}
	
    /* Auto return to default session(& locked SA) and SA protect task */
    uds_autoRtSaProtect_task();
    /* DID read, write background process task */
    uds_didRwBkc_task();

    /*uds read write background task process*/
    uds_memRwBkc_task();

    /* Routine control background process (Not need for FBL) */
    uds_rtCtrBkc_task();
}

void uds_enterProgSession(void)
{
    /* Clear uds session auto switch timer */
    sv_swStdAutoLockTick = ssSwStd_saLockTime;
    /* Reset session to default and locked all SA */
    actSessionIndex = 1;    /* set session to prog session */
}



#define NVM_BootFlag_Address              (0x1101F000)
#define NVM_BootFlag_Size                 (4)
#define NVM_BootFlag_Reprogramming        (0xA5A55A5A)  /* User-defined BL update flag */

 const uint32 progReqFlag = NVM_BootFlag_Reprogramming;
/* Service management (Session control & Security Access) */
void serv_sessionControl(void)
{
    uint8_t targetSessionType = uds_popRequestData(0x00) & uds_actSubFunctionMask; /* Get request target session */
    uint8_t actSessionType = sessionType_std;         /* active session ID */
    uint8_t switchRst = nrsp_positiveResponse;
    uint8_t  ss_i = 0; /* session index */

    /* Pre-push active response first data (request switch session)  */
    uds_pushRspData(targetSessionType);
    if(0x00 == uds_remainRequestDLC())
	{
		uds_word_t Uds_u16_ActualSpeed =0;

			Uds_u16_ActualSpeed = (sint16)Gs16_ComIf_ActSpdBOOTChk;
		 if((targetSessionType == sessionType_prog)&& (Uds_u16_ActualSpeed > 10))
		 {

			   uds_negativeRsp(nrsp_conditionsNotCorrect);

		 }
		 else
		 {
        /* Get real active session ID */
        if (actSessionIndex < sessionTypeCnt)
        {
           actSessionType = sessionTypeMap[actSessionIndex];
        }

    /* Call session switch callback function */
    switchRst = uds_sessionSwitch(actSessionType, targetSessionType);
    if (nrsp_positiveResponse == switchRst)
    {
        /* Request switch to default session check */
        if ((actSessionType != targetSessionType)
            &&  (sessionType_std == targetSessionType))
        {
            /* Enter default session */
            uds_enterDefaultSession();
        }

           /* Switch to target session (modify session index) */
           /* session index search */
           for (; ss_i < sessionTypeCnt; ss_i++)
           {
               if (sessionTypeMap[ss_i] == targetSessionType)
               {
                   /* Find session index */
                   /* Modify active session index to target session index */
                   actSessionIndex = ss_i;
                   break;
               }
           }
					 
					if(sessionType_prog != targetSessionType)
					{
						
						 uds_pushRspData(0x00);
						 uds_pushRspData(0x32); //0x32
						 uds_pushRspData(0x01);
						 uds_pushRspData(0xF4); //0xF4
						 /* Positive response */
						 uds_sendResponse();
					}
					else
					{
						
						
					
		//					 (void)Fls_Write((uint32) NVM_BootFlag_Address,
		//                          (uint8*) &progReqFlag, (uint32) NVM_BootFlag_Size);
							 
								PMU->GPUDATA00.reg = 0x5A;
								PMU->GPUDATA01.reg = 0x5A;
								PMU->GPUDATA02.reg = 0xA5;
								PMU->GPUDATA03.reg = 0xA5;
							 
									
								uds_negativeRsp(0x78);
								
								Delay_us(15000);
							
								//RunbootCode();
								 __NVIC_SystemReset();
							
						
					
					 
					
					}


            /* check SA state */
	    if (0xFF != actSaLockerMask)
	    {
	        /* sa is unlocked */
	        /* Clear seed un-check mask */
	        sv_saSeedUnCheckMask = 0u;
	        /* re-locked all SA levels */
	        actSaLockerMask = 0xFF;
	    }
		
	   if (		(sessionType_prog == actSessionType)
		   &&   (sessionType_std == targetSessionType))
	   {
		   /* reset */
		   ecuResetTrig();
	   }
	   
        }
        else
        {
           /* Switch fail, response negative code */
           uds_negativeRsp(switchRst);
        } 
    }
	}
    else
    {
		/* Switch fail, response negative code */
		uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
    }
   
}

void serv_securityAccess(void)
{
    uds_byte_t saType = uds_popRequestData(0x00)  & uds_actSubFunctionMask; /* Load security access type */
    uds_byte_t saLevel_i = 0; /* security access level */
    uds_bool_t    saGetSeed = TRUE;

	if (TRUE == nt_req_is_functional_check())
	{
		uds_negativeRsp(nrsp_requestOutOfRange);
		return;
	}

    /* Pre-push security access type for active response */
    uds_pushRspData(saType);

	/* Security access level search */
	for (; saLevel_i < saLevelCnt; saLevel_i++)
	{
		if (saLevelMap[saLevel_i].level == saType)
		{
			/* Find support level and get seed */
			break;
		}
		else if ((saLevelMap[saLevel_i].level + 1) == saType)
		{
			/* Find support level and check key */
			saGetSeed = FALSE;
			break;
		}
		else
		{
			/* continue search */
		}
	}
	
	/* Check search result */
	if (saLevel_i >= saLevelCnt)
	{
		/* not support request security access level */
		uds_negativeRsp(nrsp_subFunctionNotSupported); /* negative response */

		/* Log last SA type */
		sv_saOrgType = saType;
	}
	else if (TRUE == saGetSeed)
	{
		if(uds_remainRequestDLC() != 0)
		{
			uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
		}
		else 	if (sv_saProtectDelayTick > 0)/* SA Protect check */
		{
			/* Delay not complete, negative response */
			uds_negativeRsp(nrsp_requiredTimeDelayNotExpired);
		}
		else
		{
			if (0 == (sv_saSeedUnCheckMask & servm_saLvSptMask(saLevel_i)))
			{
				/* Call update seed position */
				uds_saUpdateSeed(saLevelMap[saLevel_i].level);
				//actSaLockerMask |= servm_saLvSptMask(saLevel_i);
			}
			/* response seed */
			uds_pushRspBuf(saLevelMap[saLevel_i].seedBuf, saLevelMap[saLevel_i].seedLen);
			uds_sendResponse();

			/*only accepted seed request shall be considered, otherwise response a NRC24 to the sendkey request.
			details, please ref to faw request.*/
			/* Log last SA type */
			sv_saOrgType = saType;
		}
	}
	else
	{
		if(uds_remainRequestDLC() != 3)    //if(uds_remainRequestDLC() != 4)
		{
			uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
		}
		else	if (sv_saOrgType != saLevelMap[saLevel_i].level)
		{
			/* negative response */
			uds_negativeRsp(nrsp_requestSequenceError);
		}
		else 	if (TRUE == uds_saLevelUnlockCheckByIndex(saLevel_i)) /* is in unlock state */
		{
			/* negative response */
			uds_negativeRsp(nrsp_requestSequenceError);/*faw requirement*/
		}	
		else 	if (sv_saProtectDelayTick > 0)/* SA Protect check */
		{
			/* Delay not complete, negative response */
			uds_negativeRsp(nrsp_requiredTimeDelayNotExpired);
		}				
		else
		{			
			/* Check Key */
			sv_saSeedUnCheckMask &= (~ servm_saLvSptMask(saLevel_i));
			if (TRUE == uds_saCheckKey(saLevelMap[saLevel_i].level))			
			{
				/* Check pass, unlock target level and send positive response */
				actSaLockerMask = actSaLockerMask & (~(servm_saLvSptMask(saLevel_i)));
				if(sv_saInvalidAccessCnt > 0)
				{
					sv_saInvalidAccessCnt = 0;
					sv_saProtectDelayTick = 0;
				}
				uds_sendResponse();				
			}
			else
			{
				/* Check fail, (re-)locked all and send negative response */
				uds_rspPending();

				actSaLockerMask = 0xFFu;
				if (sv_saInvalidAccessCnt < saProtectLimitCnt)
				{
					sv_saInvalidAccessCnt++;					
					uds_negativeRsp(nrsp_invalidKey);
				}
				else
				{
					/* SA invalid access times has exceeded the limited times, start protect */
					sv_saProtectDelayTick = saProtectDelayTime;
					uds_negativeRsp(nrsp_exceedNumberOfAttempts);								
				}
			}
		}

		/* Log last SA type */
		sv_saOrgType = saType;
	}
}

void serv_testPresent(void)
{
    /* Check sub-function */
	uds_byte_t sub_function = uds_popRequestData(0xFF) & uds_actSubFunctionMask;
    if (0x00 == sub_function)
    {
        /* Sub-function valid (Only support sub-function 0x00) */
        /* Positive response */
        uds_pushRspData(0x00);
        uds_sendResponse();		
    }
    else
    {
        /* Negtive response */
        uds_negativeRsp(nrsp_subFunctionNotSupported);
    }
}

void serv_readMemoryByAddr(void)
{
	uds_byte_t addrAndLenFormat = uds_popRequestData(0x00);
	uds_byte_t memAddrLen	= addrAndLenFormat & 0x0F;			/*the bytes number of the memory address parameters*/
	uds_byte_t memSizeLen	= (addrAndLenFormat >> 4) & 0x0F;	/*the bytes number of the memory size parameters*/
	uds_dWord_t memAddr = 0;
	uds_word_t memSize = 0;
	uds_byte_t byteIndx = 0;
	uds_byte_t memoryIndx = 0xFF;		/*0xFF: invalid memoryIndx*/
	uds_byte_t memAcNrspRst = nrsp_positiveResponse;
	uds_memRwBck_clear();
	if(uds_remainRequestDLC() == memAddrLen + memSizeLen)
	{
		if((memAddrLen >0) && (memAddrLen <= 4) && (memSizeLen > 0) && (memSizeLen <= 2))
		{
			for(byteIndx = 0;byteIndx < memAddrLen; byteIndx ++)
			{
				memAddr <<= 8;
				memAddr |= uds_popRequestData(0x00);
			}
			for(byteIndx = 0;byteIndx < memSizeLen; byteIndx ++)
			{
				memSize <<= 8;
				memSize |= uds_popRequestData(0x00);
			}
			memoryIndx = uds_getMemIndx(memAddr,memSize);
			if(memoryIndx < chipMem_cnt)
			{
				if(NULL_PTR != chipMemCfg[memoryIndx].readCallback)
				{
					memAcNrspRst = chipMemCfg[memoryIndx].readCallback();
					if(nrsp_positiveResponse == memAcNrspRst)
					{
						uds_sendResponse();
					}
					else if(nrsp_requestCorrectlyReceivedResponsePending == memAcNrspRst)
					{
						if (FALSE == uds_isRspPending())
	                    {
	                        uds_rspPending();
	                    }
						sv_memBkcItem.memIndx = memoryIndx;
						sv_memBkcItem.memOperation = servm_memRwBkcState_read;
					}
					else
					{
						uds_negativeRsp(memAcNrspRst);
					}
				}
				else
				{
					 /* Not need callback */
	                 /* Send positive response */
	                 serv_memoryReadPositiveRsp(memAddr,memSize);

				}
			}
			else
			{
				uds_negativeRsp(nrsp_requestOutOfRange);
			}
		}
		else
		{
			uds_negativeRsp(nrsp_requestOutOfRange);
		}
	}
	else
	{
		uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
	}
}


/* DID Process */
void serv_didRead(void)
{
	uds_word_t curDID = 0; /* Current need read DID */
	uds_word_t did_i = 0;  /* For search current DID in DID config index */
	uds_byte_t  didAcNrspRst = nrsp_positiveResponse; /* DID read callback result */

    /* clear bkc */
    uds_didRwBkc_clear();
    /* Notice DID read/write ready */
    uds_didRwReady();

    /* Request data length check */
    if (0 != (uds_remainRequestDLC() & 0x01))
    {
        /* DID is not aligned with 2 bytes */
        uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
    }
    else
    {
            /* Load current need read DID */
            curDID = uds_popRequestData(0x00);
            curDID = curDID << 8;
            curDID = curDID | uds_popRequestData(0x00);

            /* DID support check */
            for (did_i = 0; did_i < udsDIDcnt; did_i++)
            {
                /* Find DID in support(config) list */
                if (curDID == udsDIDcfg[did_i].did)
                {
                    /* Read access allowed check */
                    if (servm_didReadAllow(udsDIDcfg[did_i].acFlag))
                    {
                        /* DID can be read */
                        /* Check callback function */
                        if (NULL_PTR == udsDIDcfg[did_i].readCallBack)
                        {
                            /* Do not need handle call back */
                            /* Push data to response buffer */
                            serv_didWriteActiveRsp(did_i);
                        }
                        else
                        {
                            /* Callback pre-process */
                            didAcNrspRst = udsDIDcfg[did_i].readCallBack();
                            /* Check callback result */
                            if (nrsp_positiveResponse == didAcNrspRst)
                            {
                                /* Callback compelete */
                                /* Push data to response buffer */
                                serv_pushDIDtoRsp(did_i);
				uds_sendResponse();
                            }
                            else if (nrsp_requestCorrectlyReceivedResponsePending == didAcNrspRst)
                            {
                                /* Callback pending */
                                /* If not start auto-response-pending-notice, start it */
                                if (FALSE == uds_isRspPending())
                                {
                                    uds_rspPending();
                                }

                                /* Add DID read background call process */
                                /* Note: if already have bkc in process means a fault, ignore it */
                                sv_didRwBkcItem.index = did_i;
                                sv_didRwBkcItem.bkcState = servm_didRwBkcState_Read;
                            }
                            else
                            {
                                /* DID support but condition invalid or SA denied */
                                uds_negativeRsp(didAcNrspRst);
                            }
                        }
                    }
                    else
                    {
                        /* DID find but not support read */
                        /* Send negative response */
                        uds_negativeRsp(nrsp_requestOutOfRange);
                    }                    
	            break;
		}
            }

	    if(did_i >= udsDIDcnt)
	    {
		/* DID not found*/
		uds_negativeRsp(nrsp_requestOutOfRange);
	     }
        }
}

void serv_didWrite(void)
{
	uds_word_t curDID = 0;
	uds_word_t did_i = 0;
	uds_word_t dt_i = 0;
	uds_byte_t didAcNrspRst = nrsp_requestOutOfRange;

    /* clear bkc */
    uds_didRwBkc_clear();
    /* Notice DID read/write ready */
    uds_didRwReady();
    /* Load current need read DID */
    curDID = uds_popRequestData(0x00);
    curDID = curDID << 8;
    curDID = curDID | uds_popRequestData(0x00);

    /* DID support check */
    for (; did_i < udsDIDcnt; did_i++)
    {
        /* Find DID in support(config) list */
        if (curDID == udsDIDcfg[did_i].did)
        {
            /* Find DID */
            /* Write access allowed check */
            if (servm_didWriteAllow(udsDIDcfg[did_i].acFlag))
            {
                /* DLC valid check */
                if (uds_remainRequestDLC() == udsDIDcfg[did_i].dlc)
                {
                    /* Length valid */
                    /* Load request write data to DID data cache */
                    for (; dt_i < udsDIDcfg[did_i].dlc; dt_i++)
                    {
                        udsDIDcfg[did_i].dtCache[dt_i] = uds_popRequestData(0x00);
                    }
                    /* Check callback denied */
                    if (NULL_PTR != udsDIDcfg[did_i].writeCallBack)
                    {
                        /* Need callback for write */
                        /* Call write callback function */
                        didAcNrspRst = udsDIDcfg[did_i].writeCallBack();
                        /* Check callback result */
                        if (nrsp_positiveResponse == didAcNrspRst)
                        {
                            /* Callback handle compelete and success */
                            /* Send positive response */
                            serv_didWriteActiveRsp(did_i);

                        }
                        else if (nrsp_requestCorrectlyReceivedResponsePending == didAcNrspRst)
                        {
                            /* Callback pending */
                            /* If not start auto-response-pending-notice, start it */
                            if (FALSE == uds_isRspPending())
                            {
                                uds_rspPending();
                            }

                            /* Add DID write background call process */
                            /* Note: if already have bkc in process means a fault, ignore it */
                            sv_didRwBkcItem.index = did_i;
                            sv_didRwBkcItem.bkcState = servm_didRwBkcState_Write;
                        }
                        else
                        {
                            /* Callback process fail, may write fail, write condition invalid or SA denied */
                            /* Send negative response */
                            uds_negativeRsp(didAcNrspRst);
                        }
                    }
                    else
                    {
                        /* Not need callback */
                        /* Send positive response */
                        serv_didWriteActiveRsp(did_i);
                    }
                }
                else
                {
                    /* Data length not match */
                    /* Send negative response */
                    uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
                }
            }
            else
            {
                /* DID find but not support write */
                /* send negative response */
                uds_negativeRsp(nrsp_requestOutOfRange);
            }

            break; /* find DID, stop search */
        }
    }

    if(did_i >= udsDIDcnt)
    {
	/* DID not found */
        /* send negative response */
        uds_negativeRsp(nrsp_requestOutOfRange);
   }
}

/*
 * Function:serv_pushDIDtoRsp
 * Param<uint16_t did_i>:
 * Return<static void>:
 * Discription:
 * Note: This function not check acFlag (access type flag)
*/
static void serv_pushDIDtoRsp(uds_word_t did_i)
{
    /* DID index valid check */
    if (did_i < udsDIDcnt)
    {
        /* DID is in list */
        /* Check data cache */
        if (NULL_PTR != udsDIDcfg[did_i].dtCache)
        {
            /* Data cache valid */
            /* Push DID and Data to response buffer */
            uds_pushRspData((uint8_t)(udsDIDcfg[did_i].did >> 8));
            uds_pushRspData((uint8_t)(udsDIDcfg[did_i].did & 0x00FFu));
            uds_pushRspBuf(udsDIDcfg[did_i].dtCache, (uint16_t)(udsDIDcfg[did_i].dlc));
        }
    }
}

/*
 * Function:serv_didWriteActiveRsp
 * Param<uint16_t did_i>:
 * Return<static void>:
 * Discription:
 * Note: THis function not check acFlag (access type flag)
*/
static void serv_didWriteActiveRsp(uds_word_t did_i)
{
    /* DID index valid check */
    if (did_i < udsDIDcnt)
    {
        uds_pushRspData((uint8_t)(udsDIDcfg[did_i].did >> 8));
        uds_pushRspData((uint8_t)(udsDIDcfg[did_i].did & 0x00FFu));
        uds_sendResponse();
    }
}
static void uds_memRwBck_clear(void)
{
	sv_memBkcItem.memOperation = servm_memRwBkcState_idle;
	sv_memBkcItem.memIndx = servm_memRwBkcInvalidIndx;
}


static void uds_didRwBkc_clear(void)
{
    sv_didRwBkcItem.index = servm_didRwBkcInvalidIndex;
    sv_didRwBkcItem.bkcState = servm_didRwBkcState_idle;
}

static void uds_didRwBkc_task(void)
{
	uds_byte_t didAcNrspRst = nrsp_positiveResponse;
    /* RW background call process check */
    if (sv_didRwBkcItem.index < udsDIDcnt)
    {
        /* Have DID need background process */
        /* Read or write check */
        if (servm_didRwBkcState_Read == sv_didRwBkcItem.bkcState)
        {
            /* is DID read */
            /* Run read callback */
            didAcNrspRst = udsDIDcfg[sv_didRwBkcItem.index].readCallBack();
            //uds_requestValid();
            /* Callback result check (NRSP code) */
            if (nrsp_positiveResponse == didAcNrspRst)
            {
                /* Read process compelete */
                /* Clear bkc */
                uds_didRwBkc_clear();
                /* Push read result to response buffer */
                serv_pushDIDtoRsp(sv_didRwBkcItem.index);
                /* continue to read DIDs */
                serv_didRead();
            }
            else if (nrsp_requestCorrectlyReceivedResponsePending != didAcNrspRst)
            {
                /* not in-processing (Not pending) */
                /* Clear bkc */
                uds_didRwBkc_clear();
                /* Send negative response with return NRSP code */
                uds_negativeRsp(didAcNrspRst);
            }
            else
            {
                /* Already in process (response pending) */
                /* Do nothing */
            }
        }
        else if (servm_didRwBkcState_Write == sv_didRwBkcItem.bkcState)
        {
            /* is DID write */
            /* Run read callback */
            didAcNrspRst = udsDIDcfg[sv_didRwBkcItem.index].writeCallBack();
            /* Callback result check (NRSP code) */
            if (nrsp_positiveResponse == didAcNrspRst)
            {
                /* Read process compelete */
                /* Clear bkc */
                uds_didRwBkc_clear();
                /* send positive response for notice write success */
                serv_didWriteActiveRsp(sv_didRwBkcItem.index);
                /* Write compelete, no more things need to do */
            }
            else if (nrsp_requestCorrectlyReceivedResponsePending != didAcNrspRst)
            {
                /* not in-processing (Not pending) */
                /* Clear bkc */
                uds_didRwBkc_clear();
                /* Send negative response with return NRSP code */
                uds_negativeRsp(didAcNrspRst);
            }
            else
            {
                /* Already in process (response pending) */
                /* Do nothing */
            }
        }
        else
        {
            /* Idle state, Do nothing */
        }
    }
}


/* Routine Control */
void serv_routineControl(void)
{
	uds_byte_t rtCtrlType = uds_popRequestData(0x00) & uds_actSubFunctionMask; /* load request routine control type (sub-function) */
	uds_word_t curRTID = 0; /* Current request routine ID */
	uds_word_t rtid_i = 0; /* Routine ID index */
    uds_byte_t rtRst = nrsp_positiveResponse; /* Pre set result to positive response state */

    /* Routine control type check */
    if (0 != (udsRtGlobalMask & (0x01 << rtCtrlType)))
    {
        /* Sub function support */
        /* Get routine ID */
        curRTID = (uds_word_t)(uds_popRequestData(0x00));
        curRTID = curRTID << 8;
        curRTID = curRTID | (uds_word_t)(uds_popRequestData(0x00));

        /* Search routine */
        for (; rtid_i < udsRtIDcnt; rtid_i++)
        {
            if (curRTID == udsRtIDcfg[rtid_i].rtid)
            {
                /* Find RID */
                /* Pre-set active response information for callback function append response data */
                uds_pushRspData(rtCtrlType);
                uds_pushRspData((uint8_t)(curRTID >> 8));
                uds_pushRspData((uint8_t)(curRTID & 0x00FFu));

                /* check rtCtrl type */
                switch (rtCtrlType)
                {
                    case servm_rtidStartRoutine:
                        /* Check routine sub-function support (Callback valid check) */
                        if (NULL_PTR != udsRtIDcfg[rtid_i].rtStart)
                        {
                            /* sub-function support, call it */
                            rtRst = udsRtIDcfg[rtid_i].rtStart();
                            /* Check result */
                            if ((nrsp_positiveResponse == rtRst)
                                || (nrsp_requestCorrectlyReceivedResponsePending == rtRst))
                            {
                                /* routine start success */
                                /* Check rtTask call denied (Routine task callback valid check) */
                                if (NULL_PTR != udsRtIDcfg[rtid_i].rtTask)
                                {
                                    /* Set routine task */
                                    rtCtrlBkcMask = rtCtrlBkcMask | ((uint32_t)(0x01ul << rtid_i));
                                }
                            }
                        }
                        else
                        {
                            /* Sub-function not supported, set call result to requestOutOfRange NRSP */
                            /* Note: for start routine, please make sure never run to here */
                            rtRst = nrsp_requestOutOfRange;
                        }
                        break;
                    case servm_rtidStopRoutine:
                        /* Check routine sub-function support (Callback valid check) */
                        if (NULL_PTR != udsRtIDcfg[rtid_i].rtStop)
                        {
                            /* sub-function support, call it */
                            rtRst = udsRtIDcfg[rtid_i].rtStop();
                            /* Check task running flag */
                            if (0ul != (rtCtrlBkcMask & ((uds_dWord_t)(0x01ul << rtid_i))))
                            {
                                /* Clear task */
                                rtCtrlBkcMask = rtCtrlBkcMask & (~((uds_dWord_t)(0x01ul << rtid_i)));
                            }
                        }
                        else
                        {
                            /* Sub-function not supported, set call result to requestOutOfRange NRSP */
                            rtRst = nrsp_requestOutOfRange;
                        }
                        break;
                    case servm_rtidGetRoutineResult:
                        /* Check routine sub-function support (Callback valid check) */
                        if (NULL_PTR != udsRtIDcfg[rtid_i].rtGetResult)
                        {
                            /* sub-function support, call it */
                            rtRst = udsRtIDcfg[rtid_i].rtGetResult();
                        }
                        else
                        {
                            /* Sub-function not supported, set call result to requestOutOfRange NRSP */
                            rtRst = nrsp_requestOutOfRange;
                        }
                        break;
                    default:
                        /* Sub-function support flag set error, ignore and set rtRst (routine execute result) to sub function not support code */
                        rtRst = nrsp_subFunctionNotSupported;
                        break;
                }

                /* Routine call response check.
                 * If not start routine or routine task call back is NULL.
                 * Then if response pending, instead with nrsp_conditionsNotCorrect.
                 * (Only start routine can support response pending NRSP. */
                if ((servm_rtidStartRoutine != rtCtrlType)
                    || (NULL_PTR == udsRtIDcfg[rtid_i].rtTask))
                {
                    if (nrsp_requestCorrectlyReceivedResponsePending == rtRst)
                    {
                        rtRst = nrsp_conditionsNotCorrect;
                    }
                }

                /* routine call result check */
                if (nrsp_positiveResponse == rtRst )
                {
                    /* Active response */
                    uds_sendResponse();
                }
                else
                {
                    /* Negative response */
                    uds_negativeRsp(rtRst);
                }

                break; /* Find routine ID, stop search */
            }
        }

        /* Search result check */
        if (rtid_i >= udsRtIDcnt)
        {
            /* Not find RID */
            uds_negativeRsp(nrsp_requestOutOfRange);
        }
    }
    else
    {
        uds_negativeRsp(nrsp_subFunctionNotSupported);
    }
}

static void uds_rtCtrBkc_task(void)
{
	uds_word_t rtid_i = 0; /* routine ID index in config */
	uds_bool_t bkcRst = TRUE;
    /* routine task run denied check */
    if (0ul != rtCtrlBkcMask)
    {
        /* have one or more task need running */
        for (; (rtid_i < udsRtIDcnt) && (rtid_i < 32); rtid_i++)
        {
            /* Check task running flag and task callback function valid state */
            if ((0ul != (rtCtrlBkcMask & ((uint32_t)(0x01ul << rtid_i))))
                && (NULL_PTR != udsRtIDcfg[rtid_i].rtTask))
            {
                /* Need to run task and task valid */
                /* Call task and check task response */
#if 0 /* Do not used conditon order relative decision */
                if ((sessionType_std == uds_getActiveSession())
                    || (TRUE == udsRtIDcfg[rtid_i].rtTask()))
                {
                    /* Task run compelete or  */
                    /* Clear task */
                    rtCtrlBkcMask = rtCtrlBkcMask & (~((uint32_t)(0x01ul << rtid_i)));
                }
#else

#if 0           /* Not auto stop when UDS switch to default session */
                /* session auto back check */
                if (sessionType_std == uds_getActiveSession())
                {
                    /* Task run compelete or  */
                    /* Stop Task if support */
                    if (NULL != udsRtIDcfg[rtid_i].rtStop)
                    {
                        udsRtIDcfg[rtid_i].rtStop();
                    }
                    /* Clear task */
                    rtCtrlBkcMask = rtCtrlBkcMask & (~((uint32_t)(0x01ul << rtid_i)));
                }
                else
#endif
                {
                    /* Run task */
                    bkcRst = udsRtIDcfg[rtid_i].rtTask();
                    /* Task compelete check */
                    if (TRUE == bkcRst)
                    {
                        /* Clear task */
                        rtCtrlBkcMask = rtCtrlBkcMask & (~((uint32_t)(0x01ul << rtid_i)));
                    }
                }
#endif

            }

            /* If no more any task need to running, break search */
            if (0ul == (rtCtrlBkcMask >> rtid_i))
            {
                break;
            }
        }
    }
}

static void uds_memRwBkc_task(void)
{
	uds_byte_t memRwBkcNrspRst = nrsp_positiveResponse;
	if (sv_memBkcItem.memIndx < chipMem_cnt)
    {
        /* Have DID need background process */
        /* Read or write check */
        if (servm_memRwBkcState_read == sv_memBkcItem.memOperation)
        {
            /* is DID read */
            /* Run read callback */
            memRwBkcNrspRst = chipMemCfg[sv_memBkcItem.memIndx].readCallback();
            //uds_requestValid();
            /* Callback result check (NRSP code) */
            if (nrsp_positiveResponse == memRwBkcNrspRst)
            {
                /* Read process compelete */
                /* Clear bkc */
                uds_memRwBck_clear();
				uds_sendResponse();
            }
            else if (nrsp_requestCorrectlyReceivedResponsePending != memRwBkcNrspRst)
            {
                /* not in-processing (Not pending) */
                /* Clear bkc */
                uds_memRwBck_clear();
                /* Send negative response with return NRSP code */
                uds_negativeRsp(memRwBkcNrspRst);
            }
            else
            {
                /* Already in process (response pending) */
                /* Do nothing */
            }
        }
        else if (servm_memRwBkcState_write == sv_memBkcItem.memOperation)
        {
            /* is DID write */
            /* Run read callback */
            memRwBkcNrspRst = chipMemCfg[sv_memBkcItem.memIndx].writeCallback();
            /* Callback result check (NRSP code) */
            if (nrsp_positiveResponse == memRwBkcNrspRst)
            {
                /* Read process compelete */
                /* Clear bkc */
                uds_memRwBck_clear();
				uds_sendResponse();
            }
            else if (nrsp_requestCorrectlyReceivedResponsePending != memRwBkcNrspRst)
            {
                /* not in-processing (Not pending) */
                /* Clear bkc */
                uds_didRwBkc_clear();
                /* Send negative response with return NRSP code */
                uds_negativeRsp(memRwBkcNrspRst);
            }
            else
            {
                /* Already in process (response pending) */
                /* Do nothing */
            }
        }
        else
        {
            /* Idle state, Do nothing */
        }
    }
}

/* DTC Process */
void serv_dtcInforClear(void)
{
    uds_negativeRsp(nrsp_serviceNotSupported);
}

void serv_dtcInforRead(void)
{
    uds_negativeRsp(nrsp_serviceNotSupported);
}

/* IO Control */
void serv_ioControl(void)
{
    uds_negativeRsp(nrsp_serviceNotSupported);
}
/* ------------------ End Preset Service Process ------------------------------------ */


/* ------------------ Export UDS functions for service process ---------------------- */
uds_byte_t uds_getActiveSession(void)
{
    uint8_t actSession = sessionType_std;

    if (actSessionIndex < sessionTypeCnt)
    {
        actSession = sessionTypeMap[actSessionIndex];
    }

    return actSession;
}

uds_bool_t uds_saLevelUnlockCheck(uint8_t saLevel)
{
	uds_byte_t saLv_i = 0; /* SA level index */
    uds_bool_t isUnlock = FALSE;

    /* Search level */
    for (; saLv_i < saLevelCnt; saLv_i++)
    {
        if (saLevel == saLevelMap[saLv_i].level)
        {
            /* Find check level */
            /* Unlock state check */
            if (0 == (actSaLockerMask & servm_saLvSptMask(saLv_i)))
            {
                isUnlock = TRUE;
                break;
            }
        }
    }

    return isUnlock;
}

uds_bool_t uds_saLevelUnlockCheckByIndex(uint8_t saLv_index)
{
    bool isUnlock = FALSE;

    /* index range check */
    if (saLv_index < saLevelCnt)
    {
        /* index valid, check unlock state */
        if (0 == (actSaLockerMask & servm_saLvSptMask(saLv_index)))
        {
            /* is unlocked, set result to TRUE */
            isUnlock = TRUE;
        }
    }

    return isUnlock;
}

/* Re-make NT functions for service process */
/*
 * Function: uds_setPopDataIndex
 * Param<uint16_t index>: The request service data index (0 is the first data or sub-function after service ID)
 * Return<void>:
 * Discription:
 * Note: This function will no any response warning, if set out of range, it will always response defaltDt when pop data
*/
void uds_setPopDataIndex(uds_word_t index)
{
    nt_req_pos_set(index + 1);
}

/*
 * Function: uds_popRequestData
 * Param<uint8_t defaultDt>: Return if no more data
 * Return<uint8_t>: The current index data or defaultDt if is end to request data buffer
 * Discription: After pop, index to next data
 * Note:
*/
uds_byte_t uds_popRequestData(uds_byte_t defaultDt)
{
    return nt_req_pop_dt(defaultDt);
}

/*
 * Function:uds_remainRequestDLC
 * Param<void>:
 * Return<uint16_t>: The remain request data length after request data pot index
 * Discription: Get remain request bytes of not be read datas.
 * Note:
*/
uds_word_t uds_remainRequestDLC(void)
{
    return nt_req_remain_len();
}

/* Request process support functions */

/*
 * Function: uds_curRequestSID
 * Param<void>:
 * Return<uint8_t>: return curRequestServID
 * Discription:
 * Note:
*/
uds_byte_t uds_curRequestSID(void)
{
    return curRequestServID;
}

/*
 * Function: uds_getRequestDataLen
 * Param<void>:
 * Return<uint16_t>: The request data length (include sub-function, but not include service ID)
 * Discription:
 * Note:
*/
uds_word_t uds_getRequestDataLen(void)
{
    return (nt_req_len() - 1);
}



/*
 * Function:uds_rspPending
 * Param<void>:
 * Return<void>:
 * Discription:
 * Note: 1. Response Pending only active when NT is locked and can not auto unlock NT Layer after call this function.
 *       2. It will auto send response pengding service with uds_rsp_pd_cycle cycle in background before give the
 *          valid (Negative or Positive) response.
 *       3. This function have no effect of the original response data (The push to response buffer data is remain valid).
*/
void uds_rspPending(void)
{
    uds_rsp_pending(curRequestServID);
}


/*
 * Function: uds_isRspPending
 * Param<void>:
 * Return<bool>: Result of current request is in auto send response pending NRSP or not. FALSE for Not.
 * Discription: Check the auto response pending notice state.
 * Note:
*/
uds_bool_t uds_isRspPending(void)
{
    return (bool)(uds_rsp_is_pending());
}

/*
 * Function:uds_isNotYetRsp
 * Param<void>:
 * Return<bool>: Service response state.
 *               TRUE: not send response(Positive, hide positive, negative, but not include response pending)
 *               FALSE: response triggled
 * Discription:
 * Note:
*/
uds_bool_t uds_isNotYetRsp(void)
{
    return (bool)(nt_is_locked());
}

/*
 * Function: uds_preActiveResponse
 * Param<uint8_t servID>:
 * Return<void>:
 * Discription: If send active response, is un-necessary to call this function before push response data.
 * Note:
*/
void uds_preActiveResponse(uds_byte_t servID)
{
    /* Set response size to valid */
    rspSizeValid = TRUE;
    /* Pre-push positive response service id */
    nt_rsp_reset();
    nt_rsp_push_dt(servm_positiveResponeCode(servID));
}

/*
 * Function:uds_pushRspData
 * Param<uint8_t data>: data value
 * Return<void>:
 * Discription: Push a data to resonpse buffer
 * Note:
*/
void uds_pushRspData(uds_byte_t data)
{
    rspSizeValid = nt_rsp_push_dt(data);
}

/*
 * Function:uds_pushRspBuf
 * Param<uint8_t buf[]>: Push buffer start pointer
 * Param<uint16_t len>: Push buffer length
 * Return<void>:
 * Discription:
 * Note:
*/
void uds_pushRspBuf(uds_byte_t buf[], uds_word_t len)
{
    rspSizeValid = nt_rsp_push_buf(buf, len);
}

/*
 * Function:uds_getResponseDataLen
 * Param<void>:
 * Return<uint16_t>: The response data length (not include response service ID)
 * Discription:
 * Note:
*/
uds_word_t uds_getResponseDataLen(void)
{
    return (nt_rsp_len() - 1);
}

/* Define the uds have sub-function service count (based ISO 14229-1) */
#define uds_haveSubFuncServCnt 12

/*
 * Function: uds_sendResponse
 * Param<void>:
 * Return<void>:
 * Discription: Start send response
 * Note:
*/
void uds_sendResponse(void)
{
    /* Have sub-function service list define */
    const uds_byte_t subFunServList[uds_haveSubFuncServCnt] =
    {
        sid_sessionControl,
        sid_ecuReset,
        sid_securityAccess,
        sid_communicationControl,
        sid_testPresent,
        sid_accessTimingParamenter,
        sid_controlDTCSetting,
        sid_responseOnEvent,
        sid_linkControl,
        sid_dynamicallyDefineDataIdentifier,
        sid_readDTCInformation,
        sid_routineControl
    };

    uds_byte_t subFunServ_i = 0; /* subFunServList item index */
    uds_bool_t actRspHide = FALSE;  /* active response hide check result */
    uds_bool_t nrspCode = 0;
	/* Response pending check (If response pending, always send real response) */
    if (FALSE == uds_isRspPending())
    {
		/* Positive response check */
		if (0x7F != nt_rsp_get_data(0))
		{
		    /* Not negative response */
		    /* request valid */
		    //uds_requestValid();

		    /* have sub-function service search */
		    for (; subFunServ_i < uds_haveSubFuncServCnt; subFunServ_i++)
		    {
		        /* check request service */
		        if (subFunServList[subFunServ_i] == curRequestServID)
		        {
		            /* request service have sub-function */
		            /* check active response hide flag in sub-function code */
		            if (0 != (curRequestSubFunc & uds_actResponseHideBySubFunctionMask))
		            {
		                /* Set hide active response flag */
		                actRspHide = TRUE;
		                break;
		            }
		        }
		    }
		}
		else
		{
			nrspCode = nt_rsp_get_data(2);
			if (TRUE == nt_req_is_functional_check())
			{
				if ((nrsp_serviceNotSupported == nrspCode)
					|| (nrsp_subFunctionNotSupported == nrspCode)
					|| (nrsp_requestOutOfRange == nrspCode))
				{

					actRspHide = TRUE;
				}
			}
		}
    }

    /* Check active response hide flag */
    if (TRUE == actRspHide)
    {
        /* Not need response for active response */
        nt_unlock();
    }
    else
    {
        /* Check response size */
        if (FALSE == rspSizeValid)
        {
            /* Response data out of size */
            /* Send negative response with response too long information */
            uds_negativeRsp(nrsp_responseTooLong);
        }
        else
        {
            /* Response data in size */
            /* Send real response */
            nt_rsp_start();
        }
    }
}

/*
 * Function:uds_noRsp
 * Param<void>:
 * Return<void>:
 * Discription: The request not need send active response
 * Note:
*/
void uds_noRsp(void)
{
    nt_unlock();
}

/*
 * Function: uds_negativeRsp
 * Param<uint8_t nrspCode>: negative response code
 * Return<void>:
 * Discription: Transmit negative response and auto unlock NT Layser
 * Note: The request service ID is auto set.
*/
void uds_negativeRsp(uint8_t nrspCode)
{
	uds_byte_t nrspBuf[3];

    /* NRSP type check, if is response pending, used special response function */
    if (nrsp_requestCorrectlyReceivedResponsePending == nrspCode)
    {
        /* Is response pending */
        /* Call NT special function for response pending */
        uds_rsp_pending(curRequestServID);
    }
    else
    {
        /* Other NRSP */
		if ((TRUE == nt_req_is_functional_check())
			&& (FALSE == uds_isRspPending())
			&& ((nrsp_serviceNotSupported == nrspCode)
				|| (nrsp_subFunctionNotSupported == nrspCode)
				|| (nrsp_requestOutOfRange == nrspCode)))
		{

			nt_unlock();
		}
		else
		{
			/* Set negative response value */
			nrspBuf[0] = servm_negativeResponseSID;
			nrspBuf[1] = curRequestServID;
			nrspBuf[2] = nrspCode;
			/* Push to NT response buffer */
			nt_rsp_set(nrspBuf, 3);
			/* Transmit response and unlock NT receive buffer */
			nt_rsp_start(); /* unlock NT layer after call this function */
		}
    }
}


/*------------------------------------------------------------------------------
                      Implementation of local functions
------------------------------------------------------------------------------*/
/*
 * Function:uds_autoRtSaProtect_task
 * Param<void>:
 * Return<static void>:
 * Discription: Auto return to default session and locked SA and SA protect task
 * Note:
*/

static void uds_autoRtSaProtect_task(void)
{
    /* Auto return to default session and relocked process
     * Counter down of each task if tick above 0
     * When decrase from 1 to 0, set to default session and relock SA */
    if (sv_swStdAutoLockTick > 0)
    {
        /* Response pending check */
        if (TRUE == uds_isRspPending())
        {
            /* Stop counter down. Not call request valid becouse the result is unkown */
        }
        else
        {
            /* Tick counter down */
            sv_swStdAutoLockTick--;
            /* If conter down to zero (timeout) */
            if (0 == sv_swStdAutoLockTick)
            {

				if(uds_getActiveSession() == sessionType_ext)
				{
					/* Switch to default session */
                	uds_enterDefaultSession();
				}
				else if(uds_getActiveSession() == sessionType_prog)
				{
					/* S3 timeout from program session to default session, 
		  			reset, for details please check FAW spec*/
					ecuResetTrig();
				}
				else
				{					
				}
				
                /* Notice backgroud to enter default session */
                uds_sessionTimeout();
            }
        }
    }

    /* SA Protect handle
     * Counter down of each task if tick above 0
     * When decrease from 1 to 0, decrease invalid access counter if it above 0 */
    if (sv_saProtectDelayTick > 0)
    {
        sv_saProtectDelayTick--;

        if(0 == sv_saProtectDelayTick)
		{
			sv_saInvalidAccessCnt = 0;
		}	
    }
}

static void uds_enterDefaultSession(void)
{
    /* Clear uds session auto switch timer */
    sv_swStdAutoLockTick = 0;
    /* Reset session to default and locked all SA */
    actSessionIndex = 0;    /* set session to default again */
    /* check SA state */
    if (0xFF != actSaLockerMask)
    {
        /* sa is unlocked */
        /* Clear seed un-check mask */
        sv_saSeedUnCheckMask = 0u;
        /* re-locked all SA levels */
        actSaLockerMask = 0xFF;
    }
}


/*
 * Function:uds_requestValid
 * Param<void>:
 * Return<static void>:
 * Discription: Function call for request can be get positive response
 * Note: This function will force the current active session and security access locker state stay on require time
*/
static void uds_requestValid(void)
{
    /* Un-default session check */
   // if (actSessionIndex > 0)
    {
        /* Not default session */
        sv_swStdAutoLockTick = ssSwStd_saLockTime; /* Set tick to max */
    }
}

static void serv_memoryReadPositiveRsp(uds_dWord_t memoryAddr,uds_word_t memorySize)
{
	uds_word_t memoryByteIndx = 0;
	for(;memoryByteIndx < memorySize; memoryByteIndx++)
	{
		uds_pushRspData((uds_byte_t)(*((uds_byte_t *)(memoryAddr + memoryByteIndx))));

	}
	uds_sendResponse();
}

/* ---- Source switch off ---------------------------------------------------- */
#undef UDS_C_
/*--- End of file ------------------------------------------------------------*/


