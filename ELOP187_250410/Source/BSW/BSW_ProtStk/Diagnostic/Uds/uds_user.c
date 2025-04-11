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
#define UDS_USER_C_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
//#include "Mcu.h"
//#include "Irq.h"
#include "utils.h"
//#include "Flash_IF.h"
#include "uds_types.h"
#include "uds_cfg.h"
#include "uds_user.h"
#include "uds.h"
//#include "TLF35584.h"
//#include "LinTrcv.h"
#include "LinTp_export.h"
//#include "Spi.h"




#include "motor_control_param.h"

#include "ComIf_ECUReset_HAL.h"

#include "ComIf_RdDaByID_HAL.h"

#include "ComIf_WrDaByID_HAL.h"

/*-----------------------------------------------------------------------------
                   		Module local defines and constants
------------------------------------------------------------------------------*/
#define APP_START_ADDR   0x1100A080   //0x80020000
#define APP_END_ADDR     0x1101E000   //0x80200000
#define APP_ADDR_LEN     0x001E0000

#define BT_START_ADDR   0x7001AC00
#define BT_ADDR_LEN     0x00000C00

/*------------------------------------------------------------------------------
                                 Module local types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                Local data at RAM
------------------------------------------------------------------------------*/
/* User static variables */
static progStatus_t progStatus = progSt_idle;
static uds_dWord_t progBlockSn = 0ul; /* Transfer full block sn. when transmit is start form 1. used LSB (1byte) only for SN check */
static uds_dWord_t progMta0 = 0ul; /* Memory Transfer Address 0 */
static uds_dWord_t progOrgMta0 = servm_invalidMta0;
 uds_byte_t  progBlockCache[servm_tdBlockCacheDLC]; /* Not need initial in define.  */
static uds_dWord_t progCRC32 = 0ul;
static uds_word_t stayInBootFlag = 0u;


/*------------------------------------------------------------------------------
                                Local data at ROM
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Local data at EEPROM
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                Global data at RAM
------------------------------------------------------------------------------*/
//uint8_t didBuf_F101[16];
//uint8_t didBuf_F102[16];
//uint8_t didBuf_F103[16];
//uint8_t didBuf_F104[16];
//uint8_t didBuf_F186[1];
uint8_t didBuf_F100[4];
//uint8_t didBuf_F18C[5];
//uint8_t didBuf_F18B[3];
//uint8_t didBuf_F152[2];
//uint8_t didBuf_1600[16];
//uint8_t didBuf_1601[16];
//uint8_t didBuf_2504[12];
//uint8_t didBuf_250A[2];
//uint8_t didBuf_250B[20];
//uint8_t didBuf_2501[10];
//uint8_t didBuf_2502[4];
//uint8_t didBuf_2503[2];
//uint8_t didBuf_2506[4];
//uint8_t didBuf_2507[1];
//uint8_t didBuf_F18A[3];
//uint8_t didBuf_F190[17];
//uint8_t didBuf_100A[16];
//uint8_t didBuf_100E[16];
//uint8_t didBuf_F15A[4] = {0x21, 0x10, 0x14, 0x11};
//uint8_t didBuf_F190[17] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	
uint8_t didBuf_F187[15];	
uint8_t didBuf_F18C[12];
uint8_t didBuf_F193[10];
uint8_t didBuf_F19D[4];
uint8_t didBuf_F180[10];
uint8_t didBuf_F182[25];
uint8_t didBuf_F195[10];
uint8_t didBuf_F197[7];






uint8_t didBuf_F101[2];
uint8_t didBuf_F102[2];
uint8_t didBuf_F103[2];
uint8_t didBuf_F104[2];
uint8_t didBuf_F105[2];
uint8_t didBuf_F106[2];
uint8_t didBuf_F107[2];
uint8_t didBuf_F108[2];
uint8_t didBuf_F109[2];
uint8_t didBuf_F110[2];
uint8_t didBuf_F111[2];
uint8_t didBuf_F112[2];
uint8_t didBuf_F113[1];
uint8_t didBuf_F114[2];
uint8_t didBuf_F115[2];
uint8_t didBuf_F116[2];
uint8_t didBuf_F117[2];
uint8_t didBuf_F118[2];
uint8_t didBuf_F119[2];
uint8_t didBuf_F120[2];
uint8_t didBuf_F121[2];







/*------------------------------------------------------------------------------
                                Global data at ROM
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Global data at EEPROM
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                         Declaration of local functions
------------------------------------------------------------------------------*/
//static void ecuResetTrig(void);
/*------------------------------------------------------------------------------
                      Implementation of global functions
------------------------------------------------------------------------------*/
//unsigned char	Flag_ecureset=0;
/* Service: ECU reset */
void serv_ecuReset(void)
{
    uds_byte_t resetType = uds_popRequestData(0x00)  & uds_actSubFunctionMask;

    switch(resetType)
    {
        case servm_resetType_hardware:
        case servm_resetTYpe_keyOffOn:
        case servm_resetType_software:
            uds_pushRspData(resetType);            
            uds_sendResponse();
				    
				    
			      ecuResetTrig();
          
            break;
        default:
            uds_negativeRsp(nrsp_subFunctionNotSupported);
            break;
    }
}

/* Service: communication control */
void serv_comControl(void)
{
	uds_byte_t ctrlType = uds_popRequestData(0x00) & uds_actSubFunctionMask;
	uds_byte_t comType = uds_popRequestData(0x00);
    /* Control type check */
    if (ctrlType <= servm_comCtrl_disableRxAndTx)
    {
        /* Check communication type */
        if ((comType >= servm_comType_normal)
            && (comType <= servm_comType_normalAndNm))
        {
            /* Communication supported, send positive response */
            /* For fit program from application only no any real porocess */
            uds_pushRspData(ctrlType);
            uds_sendResponse();
        }
        else
        {
            /* communication type not supported */
            uds_negativeRsp(nrsp_requestOutOfRange);
        }
    }
    else
    {
        /* sub-function not supported */
        uds_negativeRsp(nrsp_subFunctionNotSupported);
    }
}



void serv_dtcSetting(void)
{
    uds_byte_t ctrlType = uds_popRequestData(0x00) & uds_actSubFunctionMask;
    /* DTC setting type check */
    if ((servm_dtcSetting_on == ctrlType )
        || (servm_dtcSetting_off == ctrlType))
    {
        /* is support type, send positive response */
        /* For fit program from application only no any real porocess */
        uds_pushRspData(ctrlType);
        uds_sendResponse();
    }
    else
    {
        /* un-support type */
        uds_negativeRsp(nrsp_subFunctionNotSupported);
    }
}


void serv_requestDownload(void)
{
	uds_byte_t dataFormat = uds_popRequestData(0x00u);
	uds_byte_t addrSizeFormat = uds_popRequestData(0x00u);
	uds_byte_t addrDLC = (uint8_t)(addrSizeFormat & 0x0Fu); /* donwload data start address discript length(bytes) */
	uds_byte_t sizeDLC = (uint8_t)(addrSizeFormat >> 4); /* download data size discript length(bytes) */
	uds_dWord_t startAddr = 0ul; /* Download data start address */
	uds_dWord_t dataSize = 0ul; /* Bytes of download data */
    uds_byte_t dlc_i = 0;
    bool addrCheckValid = FALSE;
    /* prog sequence check */
    if ((progSt_appFingerprintValid != progStatus)
        && (progSt_eraseSuccess != progStatus)
	&& (progSt_downloadCompelete != progStatus))
    {
        /* not in fingerprint write or download flash driver success */
        /* Reject and set error */
        progStatus = progErr_downloadReject;
        //uds_negativeRsp(nrsp_requestSequenceError);
        uds_negativeRsp(nrsp_uploadDownloadNotAccepted);
    }
    else
    {
        /* data format check */
        if (servm_reqDL_dataFormatOriginal != dataFormat)
        {
            /* data is been compression or encrypted */
            /* negative response and set program error */
            progStatus = progErr_downloadReject;
            uds_negativeRsp(nrsp_requestOutOfRange);
        }
        else
        {
            if ((addrDLC <= 2) || (addrDLC  > 4) /* Length(bytes) of address valid check: address bytes must in [3, 4] */
                || (sizeDLC <= 2) || (sizeDLC > 4)) /* Length of size valid check: size bytes must in [3, 4] */
            {
                progStatus = progErr_downloadReject;
                uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
            }
            else
            {
                if (uds_remainRequestDLC() != (addrDLC + sizeDLC)) /* Data length valid check: remain request data length must equre addrDLC + size DLC */
                {
                    progStatus = progErr_downloadReject;
                    uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
                }
                else
                {
                    /* Format, Length valid */
                    /* Get download start address */
                    for (dlc_i = 0; dlc_i < addrDLC; dlc_i++)
                    {
                        startAddr = startAddr << 8;
                        startAddr = startAddr + uds_popRequestData(0u);
                    }
                    /* Get download size (Bytes) */
                    for (dlc_i = 0; dlc_i < sizeDLC; dlc_i++)
                    {
                        dataSize = dataSize << 8;
                        dataSize = dataSize + uds_popRequestData(0u);
                    }
                    
                    /* Check request download start address and size
                     * If is after fingerprint write and need download flash driver:
                     *   Two types of download data(Flash Driver or Application)
                     * Else (not need download flash driver):
                     *   One type of download data(Application).
                    */
                    /* Program status check
                     * If memory was been erase, can request download application now
                    */

		if (	 (progSt_eraseSuccess == progStatus)
		     ||(progSt_downloadCompelete == progStatus))
	        {
                
				/* Request Downloading Application */
				if ((startAddr >= APP_START_ADDR) /* Start address match */
				    && ((startAddr + dataSize) <= APP_END_ADDR))   /* Memory Size match */		

                        {
                            /* Address valid */
                            addrCheckValid = TRUE;
                            /* set program status to next step for application downloading */
                            progStatus = progSt_downloadAllowed;		
                        }			
                    }
                    else
                    {
                        /* Request Downloading Flash Driver */
                        if ((startAddr == BT_START_ADDR) /* Start address match */
                            && (dataSize == BT_ADDR_LEN))   /* Memory Size match */
                        {
                            /* Address valid */
                            addrCheckValid = TRUE;
                            /* set program status to next step for flash driver downloading */
                            progStatus = progSt_fdDownloadAllowed;
    			    progCRC32 = 0;
                        }
                    }

                    if (TRUE == addrCheckValid) /* And data size match */
                    {
                        /* address size valid */
                        /* set start SN to one(1) for start ready to receive first block */
                        progBlockSn = 1ul;
                        /* set mta0 to start address */
                        progMta0 = startAddr;
                        /* set orginal mta0 to 0xFFFFFFFFul */
                        progOrgMta0 = servm_invalidMta0;                        

                        /* send positive response
                            * 0: bit7..4, length format. bit3..0, set to 0
                            * 1: MSB for block size (full message size for transfer service)
                            * 2: LSB for block size
                        */
                        uds_pushRspData(0x20u); /* Bit7..4 */
                        uds_pushRspData((uint8_t)((servm_tdBlockCacheDLC + 2) >> 8));
                        uds_pushRspData((uint8_t)((servm_tdBlockCacheDLC + 2) & 0x00FFu));
                        uds_sendResponse();
                    }
                    else
                    {
                        progStatus = progErr_downloadReject;
                        uds_negativeRsp(nrsp_requestOutOfRange);
                    }
                }
            }
        }
    }
}


static void saveDownloadAddr(void)
{
	uint8_t loop_sector = 0;		
//	for(loop_sector=8; loop_sector<PFLASH_EACH_SECTOR_NUM; loop_sector++)
//	{
//		if(	(progMta0 >= PFlash0SectorInfoGrp[loop_sector].CacheAddr)
//		    &&(progMta0 < (PFlash0SectorInfoGrp[loop_sector].CacheAddr + PFlash0SectorInfoGrp[loop_sector].len)))
//		{
//			break;
//		}
//	}

//	if(fblNvmDts_ram1.RequestDownloadAddr != PFlash0SectorInfoGrp[loop_sector].CacheAddr)
//	{
//		fblNvmDts_ram1.RequestDownloadAddr = PFlash0SectorInfoGrp[loop_sector].CacheAddr;
//		fblNvmDts_ram2.RequestDownloadAddr = fblNvmDts_ram1.RequestDownloadAddr;
//		fblNvm_save1();
//	}
}


#if 0
void serv_transferData(void)
{
	uds_byte_t blockSn = uds_popRequestData(0u);
    uint8_t  *p_curFlsDrv; /* Update flash driver use only */
    uds_word_t dt_i = 0;
    bool downloadFlsDrv = FALSE; 
    uint16_t realTime_curBlockTargetDLC = 0;
    /* prog sequence check */
    if ((progSt_downloadAllowed != progStatus)
        && (progSt_downloading != progStatus)
        && (progSt_fdDownloadAllowed != progStatus)
        && (progSt_fdDownloading != progStatus))
    {
        uds_negativeRsp(nrsp_requestSequenceError);
    }
    else
    {
    	if ((progSt_fdDownloadAllowed == progStatus)
    	    || (progSt_fdDownloading == progStatus))
        {
    	       downloadFlsDrv = TRUE;
        }

        realTime_curBlockTargetDLC = uds_remainRequestDLC();

        if ((realTime_curBlockTargetDLC > servm_tdBlockCacheDLC) ||
        	(0 == realTime_curBlockTargetDLC))/*servm_tdBlockCacheDLC is max length*/
        {
            /* Data length invalid */
            uds_negativeRsp(nrsp_incorrectMessageLengthOrInvalidFormat);
        }
        else
        {
            /* Data length match */
            /* Check block SN */
            if (blockSn != (uint8_t)(progBlockSn & 0xFFul))
            {
                /* Block SN not match */
                /* Here can set a restore transmit algorithm, Now is empty, direct send negative response */
                uds_negativeRsp(nrsp_wrongBlockSequenceCounter);
            }
            else
            {
                /* Block SN match */
                /* Get download data to block cache */
                if (TRUE == downloadFlsDrv)
                {
                    p_curFlsDrv = (uint8_t *)(progMta0);
                    for (dt_i = 0; dt_i < realTime_curBlockTargetDLC; dt_i++)
                    {
                        p_curFlsDrv[dt_i] = uds_popRequestData(0xFFu);
                    }

		    /* Calculate CRC32 */
                    progCRC32 = crc32_discrete(progCRC32, p_curFlsDrv, (uint32_t)realTime_curBlockTargetDLC);

                    /* increase global program block sn, and set mta0 to next block address */
                    progMta0 = progMta0 + realTime_curBlockTargetDLC;
                    progBlockSn++;
                    /* Update program status
                    * If is first block program, set to downloading state */
                    if (progSt_fdDownloadAllowed == progStatus)
                    {
                        progStatus = progSt_fdDownloading;
                    }
                    /* send active response with current block SN */
                    uds_pushRspData(blockSn);
                    uds_sendResponse();
                }
                else
                {
                    for (dt_i = 0; dt_i < realTime_curBlockTargetDLC; dt_i++)

                    {
                        progBlockCache[dt_i] = uds_popRequestData(0xFFu);
                    }		    

		    /*saveDownloadAddr*/
		   // saveDownloadAddr();   //zhq

		     /* Calculate CRC32 */
                    progCRC32 = crc32_discrete(progCRC32, progBlockCache, (uint32_t)realTime_curBlockTargetDLC);
			 
		    /* Send response pending for program block */
                    /* Program 512 bytes will not over 500ms, not need send response pending flag */
                    /* program flash and check result */                    

                   // if (TRUE == FLASH_Write(progMta0, progBlockCache, realTime_curBlockTargetDLC))
										if (TRUE == FLASH_Write(progMta0, (uint8_t *)progBlockCache, realTime_curBlockTargetDLC))
                    {
                        /* program fail, send negative response */
                        uds_negativeRsp(nrsp_generalProgrammingFailure);
                    }
                    else
                    {
                        /* program success */
                        /* increase global program block sn, and set mta0 to next block address */
                    	progMta0 = progMta0 + realTime_curBlockTargetDLC;
                        progBlockSn++;
                        /* Update program status
                        * If is first block program, set to downloading state */
                        if (progSt_downloadAllowed == progStatus)
                        {
                            progStatus = progSt_downloading;
                        }
                        /* send active response with current block SN */
                        uds_pushRspData(blockSn);
                        uds_sendResponse();
                    }
                }
            }
        }
    }
}

#endif

void serv_requestTransferExit(void)
{
	if (progSt_downloading == progStatus)
	{		
		/* transfer data is actie and data was been compelte transmit(program success also) */
		/* set program status to download compelete */
		progStatus = progSt_downloadCompelete;
		/* Send positive response */
		uds_sendResponse();
		
	}
	else if (progSt_fdDownloading == progStatus)
	{
		if ((BT_START_ADDR + BT_ADDR_LEN) == progMta0)
		{
			/* transfer flash driver is compelte */
			/* set program status to flash driver download compelete */
			progStatus = progSt_fdDownloadCompelete;
			/* Send positive response */
			uds_sendResponse();
		}
		else
		{
			/* transfer not active, programming fail or not compelte */
			uds_negativeRsp(nrsp_requestOutOfRange);
		}
	}
	else
	{
		/* Not change programming status */
		/* transfer not active, programming fail or not compelte */
		uds_negativeRsp(nrsp_requestSequenceError);
	}
}
#if 0
uint8_t rtStart_eraseMemory(void)
{
    uint8_t nrspCode = 0;
    uint32_t eraseStartAddr = 0ul;
    uint32_t eraseSize = 0ul;
    uint32_t eraseEndAddr = 0ul;
    bool eraseAccept = FALSE;
    uint8_t erasingMethod = 0;
    uint32_t loop_i = 0;

    erasingMethod = uds_popRequestData(0x00u);	
    /* support session check */
    if (uds_getActiveSession() != sessionType_prog)
    {
        /* not in program session, set negative response flag */
        nrspCode = nrsp_subFunctionNotSupportedInActiveSession;
    }
    /* SA state check */
//    else if (uds_saLevelUnlockCheckByIndex(saLvSpt_fbl) == FALSE)
//    {
//        /* SA fbl level is locked, set negative response flag */
//        nrspCode = nrsp_securityAccessDenied;
//    }
//	 /* Program status check: erase memory must after finger print write success. */
//    else if (progSt_fdDownloadCheckPass != progStatus)
//    {
//        /* Not write finger print success or write fail */
//        nrspCode = nrsp_requestSequenceError;
//    }
     /* erasing method  check */
    else if( (erasingMethod != 0x01) && (erasingMethod != 0x02))
    {
        /* SA fbl level is locked, set negative response flag */
        nrspCode = nrsp_requestOutOfRange;
    }    
    else
    {
	uint32_t tmpLen = 0;
	
	if(erasingMethod == 0x01)
	{
		uint8_t addrSizeFormat = uds_popRequestData(0x00u);
		uint8_t addrDLC  = addrSizeFormat & 0x0F;
		uint8_t sizeDLC = (addrSizeFormat >> 4) & 0x0F;
		
		if (	(addrDLC <= 2) || (addrDLC  > 4) /* Length(bytes) of address valid check: address bytes must in [3, 4] */
	         || (sizeDLC <= 2) || (sizeDLC > 4)) /* Length of size valid check: size bytes must in [3, 4] */
	        {
	            nrspCode = (nrsp_incorrectMessageLengthOrInvalidFormat);
	        }
		else
		{
			if (uds_remainRequestDLC() != (addrDLC + sizeDLC)) /* Data length valid check: remain request data length must equre addrDLC + size DLC */
			{
				nrspCode = (nrsp_incorrectMessageLengthOrInvalidFormat);
			}
			else
			{
				/* Format, Length valid */
				/* Get download start address */
				while (addrDLC > 0)
				{
					eraseStartAddr = eraseStartAddr << 8;
					eraseStartAddr = eraseStartAddr + uds_popRequestData(0u);
					addrDLC--;
				}
				/* Get download size (Bytes) */
				while (sizeDLC > 0)
				{
					eraseSize = eraseSize << 8;
					eraseSize = eraseSize + uds_popRequestData(0u);
					sizeDLC--;
				}
			}			
	 	}
	}
	else
	{
		uint8_t IdentifierLengthFormat = 0;
		uint8_t IdentifierDlc = 0ul;
		uint32_t Identifier = 0ul;

		IdentifierLengthFormat = uds_popRequestData(0x00u);

		IdentifierDlc = (IdentifierLengthFormat & 0xF0) >> 4;

		if ((IdentifierDlc <= 2) || (IdentifierDlc  > 4) )
		{
			nrspCode = (nrsp_incorrectMessageLengthOrInvalidFormat);
		}
		else
		{
			while (IdentifierDlc > 0)
			{
				Identifier = Identifier << 8;
				Identifier = Identifier + uds_popRequestData(0u);
				IdentifierDlc--;
			}
			
			for(loop_i=0; loop_i<nbOfSoftwareUnits_APP; loop_i++)
			{
				/*here shall be updated later, as it assumed that only one area is within the sw uint. */
				if(appSwUnitInfo[loop_i].appSwUnitIndex == Identifier)
				{
					eraseStartAddr = appSwUnitInfo[loop_i].startAddr;
					eraseSize = appSwUnitInfo[loop_i].length;
					break;
				}
			}
		}
     }

//	     for(loop_i=8; loop_i<PFLASH_EACH_SECTOR_NUM; loop_i++)
//	     {
//			 if(eraseStartAddr == PFlash0SectorInfoGrp[loop_i].CacheAddr)
//			 {
//				 tmpLen = 0;
//				 break;
//			 }
//	     }		 
//	   
//	    for(; loop_i<PFLASH_EACH_SECTOR_NUM; loop_i++)
//	    {
//			tmpLen += PFlash0SectorInfoGrp[loop_i].len;
//			if(eraseSize == tmpLen)
//			{
//				eraseAccept = TRUE;
//				break;
//			}
//	    } 

//	    if (TRUE == eraseAccept)
//	    {
//		if(fblNvmDts_ram1.programAttemptCounter >= 0xFFFF)
//		{
//			 nrspCode = nrsp_conditionsNotCorrect;
//			 eraseAccept = FALSE;
//		}
//		else
//		{
//			fblNvmDts_ram1.programAttemptCounter++;
//			fblNvmDts_ram2.programAttemptCounter=fblNvmDts_ram1.programAttemptCounter;
//			fblNvm_save1();

//			if( flash_eraseSectorByStartAddr(0x8001C000) == 0)
//			{
//				eraseAccept = FALSE;	
//			}
//		}
//	  }
  
//	    if (FALSE == eraseAccept)
//	    {
//		 if(nrspCode == 0)
//		 {
//			uds_pushRspData(0x01); /* response 0x01 for programming fail */
//                        nrspCode = nrsp_positiveResponse;
//                        progStatus = progErr_eraseFlashFail;
//		 }
//	    }
//	     else
//            {	
//                    uint32_t curEraseSize = 0ul;
//		eraseEndAddr = eraseStartAddr + (eraseSize - 1);
//		/* Erase memory */
//                while (eraseStartAddr <= eraseEndAddr)
//                {
//                    curEraseSize = flash_eraseSectorByStartAddr(eraseStartAddr);
//                    if (curEraseSize > 0)
//                    {
//                        eraseStartAddr = eraseStartAddr + curEraseSize;
//                    }
//                    else
//                    {
//			break;
//                    }
//                   // SBC_35584_serviceFWD();
//                }
               // uds_rspPending();
                uint8_t erasenvm_Error = 0ul;
                erasenvm_Error = FLASH_Ereae(eraseStartAddr,eraseSize);
               // if (eraseStartAddr <= eraseEndAddr)
							  if(erasenvm_Error == 1)
                {
                    uds_pushRspData(0x01); /* response 0x01 for programming fail */
                    nrspCode = nrsp_positiveResponse;
                    progStatus = progErr_eraseFlashFail;
                }
                else
                {
                    uds_pushRspData(0x00); /* response 0x00 for programming success */
                    nrspCode = nrsp_positiveResponse;
                    progStatus = progSt_eraseSuccess;

										/* reset CRC32 value */
										progCRC32 = 0ul;
                }
            }
       // }
    
    return nrspCode;
}
#endif

uds_bool_t rtSpt_appIDcheck(void)
{
	uds_bool_t checkPass = FALSE;
	uint32_t * validFlgAddr;

	/*check dependency flag*/
//	validFlgAddr = (uint32_t *)(fblFingerprint.appDependencyFlgAddr);
//	if((*validFlgAddr) != fblFingerprint.appValidNumber)
//	{
//		checkPass = FALSE;
//	}
//	else
//	{
//		uint32_t loop_i = 0;
//		/*check each sw unit data integraty flag*/
//		for(loop_i=0; loop_i<nbOfSoftwareUnits_APP; loop_i++)
//		{			
//			if(appSwUnitInfo[loop_i].validFlgAddr != 0xFFFFFFFF)
//			{
//				validFlgAddr = (uint32_t *)(appSwUnitInfo[loop_i].validFlgAddr);
//				if((*validFlgAddr) != appSwUnitInfo[loop_i].validMagicNum)
//				{
//					checkPass = FALSE;
//					break;
//				}
//			}
//		}

//		if(loop_i >= nbOfSoftwareUnits_APP)
//		{
//			checkPass = TRUE;
//		}
//	}
    
		uint32_t loop_i = 0;
		/*check each sw unit data integraty flag*/
		for(loop_i=0; loop_i<nbOfSoftwareUnits_APP; loop_i++)
		{			
			if(appSwUnitInfo[loop_i].validFlgAddr != 0xFFFFFFFF)
			{
				validFlgAddr = (uint32_t *)(appSwUnitInfo[loop_i].validFlgAddr);
				if((*validFlgAddr) != appSwUnitInfo[loop_i].validMagicNum)
				{
					checkPass = FALSE;
					break;
				}
			}
		}
 
	 if(loop_i >= nbOfSoftwareUnits_APP)
		{
			checkPass = TRUE;
		}


    return checkPass;
}

#if 0
uds_byte_t rtStart_checkDependencies(void)
{
	uds_dWord_t appToolCRC32 = 0ul;
	uds_dWord_t memoryCRC32= 0ul;
    uds_byte_t nrspCode = nrsp_positiveResponse;

    uint32_t  remail_len = 0;
    uint32_t  crc_len = 0;

    // support session check 
    if (uds_getActiveSession() != sessionType_prog)
    {
        // not in program session, set negative response flag 
        nrspCode = nrsp_subFunctionNotSupportedInActiveSession;
    }
    // SA state check 
    else if (uds_saLevelUnlockCheckByIndex(saLvSpt_fbl) == FALSE)
    {
        // SA fbl level is locked, set negative response flag 
        nrspCode = nrsp_securityAccessDenied;
    }
    else if (progSt_downloadCheckPass != progStatus)
    {
    	nrspCode = nrsp_requestSequenceError;
    }
    else
    {
        // routine parameter data length check 
        if (0 != uds_remainRequestDLC())/*have no CRC*/
        {
            /* crc value is not 4 bytes, set negative response flag */
            nrspCode = nrsp_incorrectMessageLengthOrInvalidFormat;
        }
        else
        {
			/*as we have no strategy to check the dependency, so here set it pass directly*/
			uint32_t loop_i = 0;
			uint32_t offset = 0;
			//uint32_t tmpBuffer[64];

//			for(loop_i=0; loop_i<64; loop_i++){tmpBuffer[loop_i] = 0xFF;}
//			 for(loop_i=0; loop_i<nbOfSoftwareUnits_APP; loop_i++)
//			 {
//				offset = (uint8_t)((appSwUnitInfo[loop_i].validFlgAddr-0x8001C000)/4);
//				tmpBuffer[offset] = appSwUnitInfo[loop_i].validMagicNum;
//			 }

//			offset = (uint8_t)((fblFingerprint.appDependencyFlgAddr-0x8001C000)/4);
//			tmpBuffer[offset] = fblFingerprint.appValidNumber;

				if( TRUE == FLASH_Write((uint32) appSwUnitInfo[0].validFlgAddr,
                          (uint8*) &appSwUnitInfo[0].validMagicNum, (uint32) 4))
				  {
							/* program fail, send negative response */
               uds_negativeRsp(nrsp_generalProgrammingFailure);
					
					}
					else
					{
					
						  uds_pushRspData(0x00);
					
					}
					
					
					
					
//			if(FALSE == flash_program(0x8001C000, (uint8 *)tmpBuffer, 64))
//			{
//				/* program fail, send negative response */
//                        	uds_negativeRsp(nrsp_generalProgrammingFailure);
//			}
//			else
//			{
//				fblNvmDts_ram1.RequestDownloadAddr = 0;
//				fblNvmDts_ram2.RequestDownloadAddr = 0;
//				fblNvm_save2();

//				uds_pushRspData(0x00);
//			}
        }
    }
    return nrspCode;
}
#endif

uds_byte_t rtStart_checkAppDataIntegrity(void)
{
    uds_byte_t nrspCode = nrsp_positiveResponse;

    /* support session check */
    if (uds_getActiveSession() != sessionType_prog)
    {
        /* not in program session, set negative response flag */
        nrspCode = nrsp_subFunctionNotSupportedInActiveSession;
    }
    /* SA state check */
//    else if (uds_saLevelUnlockCheckByIndex(saLvSpt_fbl) == FALSE)
//    {
//        /* SA fbl level is locked, set negative response flag */
//        nrspCode = nrsp_securityAccessDenied;
//    }
	else if (	(progSt_fdDownloadCompelete != progStatus)		  
		   &&(progSt_downloadCompelete != progStatus))
	{
		nrspCode = nrsp_requestSequenceError;
	}
    else
    {
	uint8_t loop = 0;
	uint32_t memoryAddr = 0;
	uint32_t memorySize = 0;
	uint32_t receivedSignature = 0;
	uint32_t clacSignature = 0;
	uint8_t checkingMethod = uds_popRequestData(0x00u);
    	uint8_t AddrLengthFormat = uds_popRequestData(0x00u);

	/*for now, only 0x11 is supported, ignore sub service 0x12*/
	if(checkingMethod != 0x11)
	{
		nrspCode = nrsp_requestOutOfRange;
	}
	else if(AddrLengthFormat != 0x44)
	{
		nrspCode = nrsp_incorrectMessageLengthOrInvalidFormat;
	}
	else
	{
		loop = 4;
		while (loop > 0)
		{
			memoryAddr = memoryAddr << 8;
			memoryAddr = memoryAddr + uds_popRequestData(0u);
			loop--;
		}
		loop = 4;
		while (loop > 0)
		{
			memorySize = memorySize << 8;
			memorySize = memorySize + uds_popRequestData(0u);
			loop--;
		}
		loop = 4;
		while (loop > 0)
		{
			receivedSignature = receivedSignature << 8;
			receivedSignature = receivedSignature + uds_popRequestData(0u);
			loop--;
		}

		uds_rspPending();
		
		#if 0
		clacSignature = crc32_discrete(0,(uint8_t *)memoryAddr,memorySize);
		#else
		clacSignature = progCRC32;
		#endif

		if (progSt_downloadCompelete == progStatus)
		{
			fblNvmDts_ram1.RequestDownloadAddr = 0;
			fblNvmDts_ram2.RequestDownloadAddr = 0;
			fblNvm_save1();
		}		

		if (clacSignature != receivedSignature)
		{
			uds_pushRspData(0x01);
		}
		else
		{
			uds_pushRspData(0x00);		
			if (progSt_downloadCompelete == progStatus)
			{			
				progStatus = progSt_downloadCheckPass;
			}
			else
			{		
				progStatus = progSt_fdDownloadCheckPass;
			}			
		}
	    }
    }
    return nrspCode;
}


uds_byte_t rtStart_reprogramConditionCheck(void)
{
    uds_word_t rxFlag = 0u;
    uds_byte_t nrspCode = nrsp_positiveResponse;

    /* check flag size */

    uds_pushRspData((uint8_t)(0x00));
    nrspCode = nrsp_positiveResponse;



    return nrspCode;
}

uds_byte_t rtStart_stayInBoot(void)
{
    uds_word_t rxFlag = 0u;
    uds_byte_t nrspCode = nrsp_requestOutOfRange;

    /* check flag size */
    if (uds_remainRequestDLC() != 2)
    {
        nrspCode = nrsp_incorrectMessageLengthOrInvalidFormat;
    }
    else
    {
        /* size match */
        /* get flag */
        rxFlag = uds_popRequestData(0);
        rxFlag = rxFlag << 8;
        rxFlag = rxFlag + uds_popRequestData(0);
        /* check flag */
        if (servm_stayInBootAcceptFlag == rxFlag)
        {
            /* Flag match, accept stay in boot */
            stayInBootFlag = servm_stayInBootAcceptFlag;
            nrspCode = nrsp_positiveResponse;
        }
        else
        {
            /* Flag not match, cancel accept */
            stayInBootFlag = servm_stayInBootRejectFlag;
        }
    }

    return nrspCode;
}

uds_bool_t uds_allowedJumpToApp(void)
{
    return (uds_bool_t)(servm_stayInBootAcceptFlag != stayInBootFlag);
}


void ecuResetTrig(void)
{
    //disableInterrupts;
    /* Makesure watchdog is enable */
	  unsigned int tick = 150000;

    while((tick >0) && (TRUE == uds_rsp_is_pending()))
    {
        /* Waiting watchdog timeout reset */
    	tick --;
    }
		

	
    ComIf_ExecuteEcuReset();
//		while(1)
//		{}
	
	

//  Irq_ClearAllInterruptFlags();
//	LinTrcv_GotoSleep();
//	Spi_DeInit();
//  Mcu_PerformReset();
}



//uds_byte_t didrd_BootVersion(void)
//{
//	
//	return nrsp_positiveResponse;
//}

//uds_byte_t didrd_AppVersion(void)
//{
//	
//	return nrsp_positiveResponse;
//}


uds_byte_t didrd_ActiveSessionState(void)
{

	didBuf_F100[0] = uds_getActiveSession();
	didBuf_F100[1] = 0;
	didBuf_F100[2] = 0;
	didBuf_F100[3] = 0;
	
	return nrsp_positiveResponse;
}


uds_byte_t didrd_VehicleIndentifyNumber(void)
{
	unsigned char loop_i;
//	for(loop_i=0; loop_i<17; loop_i++)
//	{
//		didBuf_F190[loop_i] = fblNvmDts_ram1.VehicleIdentificationNumber[loop_i];
//	}
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_VehicleIndentifyNumber(void)
{
	unsigned char loop_i;
//	for(loop_i=0; loop_i<17; loop_i++)
//	{
//		fblNvmDts_ram2.VehicleIdentificationNumber[loop_i] = didBuf_F190[loop_i];
//	}

	return nrsp_positiveResponse;
}



uds_byte_t didwt_Fingerprint(void)
{
//	if((didBuf_F190[1] <= 12)	&&(didBuf_F190[2] <= 30))
//	{
//		fblNvmDts_ram2.progarmmingDate[0] = didBuf_F15A[0];
//		fblNvmDts_ram2.progarmmingDate[1] = didBuf_F15A[1];
//		fblNvmDts_ram2.progarmmingDate[2] = didBuf_F15A[2];
//		fblNvmDts_ram2.TestUsageId = didBuf_F15A[3];
//	}
//	progStatus = progSt_appFingerprintValid;
	return nrsp_positiveResponse;
}

uds_byte_t didrd_programCnt(void)
{
//	didBuf_2502[0] = 0;
//	didBuf_2502[1] = 0;
//	didBuf_2502[0] = (uint8_t)(fblNvmDts_ram1.programAttemptCounter & 0xFF00)>>8;
//	didBuf_2502[1] = (uint8_t)(fblNvmDts_ram1.programAttemptCounter & 0xFF);	

	return nrsp_positiveResponse;
}


uds_byte_t didrd_BreakMemoryAddress(void)
{
	uint8_t nrspCode = 0;
	 if (uds_getActiveSession() != sessionType_prog)
	{
		/* not in program session, set negative response flag */
		nrspCode = nrsp_subFunctionNotSupportedInActiveSession;
	}
	 else
	 {
		uint32_t savedAddr = 0;

//		savedAddr = fblNvmDts_ram1.RequestDownloadAddr;

//		if((savedAddr == 0) ||(savedAddr == 0xFFFFFFFF))
//		{
//			didBuf_2506[0] = 0;
//			didBuf_2506[1] = 0;
//			didBuf_2506[2] = 0;
//			didBuf_2506[3] = 0;
//		}
//		else
//		{			
//			didBuf_2506[0] = (uint8_t)(savedAddr >>24);
//			didBuf_2506[1] = (uint8_t)(savedAddr >>16);
//			didBuf_2506[2] = (uint8_t)(savedAddr >>8);
//			didBuf_2506[3] = (uint8_t)(savedAddr);			
//		}

		nrspCode = nrsp_positiveResponse;
	}
	

	return nrspCode; 
}


uds_byte_t didrd_parSpdCtrlPropGain(void)
{
	
//	 didBuf_F101[0] = parSpdCtrlPropGain & 0xFF;
//	 didBuf_F101[1] = (parSpdCtrlPropGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parSpdCtrlPropGain(void)
{
//     parSpdCtrlPropGain  = (didBuf_F101[1]<<8)| didBuf_F101[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parSpdCtrlIntgGain(void)
{
	
//	 didBuf_F102[0] = parSpdCtrlIntgGain & 0xFF;
//	 didBuf_F102[1] = (parSpdCtrlIntgGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parSpdCtrlIntgGain(void)
{
//     parSpdCtrlIntgGain  = (didBuf_F102[1]<<8)| didBuf_F102[0];

	return nrsp_positiveResponse;
}


uds_byte_t didrd_parDirCurrCtrlPropGain(void)
{
	
//	 didBuf_F103[0] = parDirCurrCtrlPropGain & 0xFF;
//	 didBuf_F103[1] = (parDirCurrCtrlPropGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parDirCurrCtrlPropGain(void)
{
//     parDirCurrCtrlPropGain  = (didBuf_F103[1]<<8)| didBuf_F103[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parDirCurrCtrlIntgGain(void)
{
	
//	 didBuf_F104[0] = parDirCurrCtrlIntgGain & 0xFF;
//	 didBuf_F104[1] = (parDirCurrCtrlIntgGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parDirCurrCtrlIntgGain(void)
{
//     parDirCurrCtrlIntgGain  = (didBuf_F104[1]<<8)| didBuf_F104[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parQdrtCurrCtrlPropGain(void)
{
	
	// didBuf_F105[0] = parQdrtCurrCtrlPropGain & 0xFF;
	// didBuf_F105[1] = (parQdrtCurrCtrlPropGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parQdrtCurrCtrlPropGain(void)
{
//     parQdrtCurrCtrlPropGain  = (didBuf_F105[1]<<8)| didBuf_F105[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parQdrtCurrCtrlIntgGain(void)
{
	
//	 didBuf_F106[0] = parQdrtCurrCtrlIntgGain & 0xFF;
//	 didBuf_F106[1] = (parQdrtCurrCtrlIntgGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parQdrtCurrCtrlIntgGain(void)
{
 //    parQdrtCurrCtrlIntgGain  = (didBuf_F106[1]<<8)| didBuf_F106[0];

	return nrsp_positiveResponse;
}
uds_byte_t didrd_parPLLCtrlPropGain(void)
{
	
//	 didBuf_F107[0] = parPLLCtrlPropGain & 0xFF;
//	 didBuf_F107[1] = (parPLLCtrlPropGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parPLLCtrlPropGain(void)
{
//     parPLLCtrlPropGain  = (didBuf_F107[1]<<8)| didBuf_F107[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parPLLCtrlIntgGain(void)
{
	
//	 didBuf_F108[0] = parPLLCtrlIntgGain & 0xFF;
//	 didBuf_F108[1] = (parPLLCtrlIntgGain >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parPLLCtrlIntgGain(void)
{
 //    parPLLCtrlIntgGain  = (didBuf_F108[1]<<8)| didBuf_F108[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parMinSnslRefElctSpd(void)
{
	
//	 didBuf_F109[0] = parMinSnslRefElctSpd & 0xFF;
//	 didBuf_F109[1] = (parMinSnslRefElctSpd >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parMinSnslRefElctSpd(void)
{
 //    parMinSnslRefElctSpd  = (didBuf_F109[1]<<8)| didBuf_F109[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parMinStrtUpElctSpd(void)
{
	
//	 didBuf_F110[0] = parMinStrtUpElctSpd & 0xFF;
//	 didBuf_F110[1] = (parMinStrtUpElctSpd >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parMinStrtUpElctSpd(void)
{
 //    parMinStrtUpElctSpd  = (didBuf_F110[1]<<8)| didBuf_F110[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parStlgStrtUpElctSpd(void)
{
	
//	 didBuf_F111[0] = parStlgStrtUpElctSpd & 0xFF;
//	 didBuf_F111[1] = (parStlgStrtUpElctSpd >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parStlgStrtUpElctSpd(void)
{
//     parStlgStrtUpElctSpd  = (didBuf_F111[1]<<8)| didBuf_F111[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parSnslElctAngDely(void)
{
	
//	 didBuf_F112[0] = parSnslElctAngDely & 0xFF;
//	 didBuf_F112[1] = (parSnslElctAngDely >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parSnslElctAngDely(void)
{
//     parSnslElctAngDely  = (didBuf_F112[1]<<8)| didBuf_F112[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parAngPosEvalMode(void)
{
	
//	 didBuf_F113[0] = parAngPosEvalMode & 0xFF;
	 
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parAngPosEvalMode(void)
{
 //    parAngPosEvalMode  = didBuf_F113[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parStrtUpProcTolElctSpd(void)
{
	
//	 didBuf_F114[0] = parStrtUpProcTolElctSpd & 0xFF;
//	 didBuf_F114[1] = (parStrtUpProcTolElctSpd >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parStrtUpProcTolElctSpd(void)
{
    // parStrtUpProcTolElctSpd = (didBuf_F114[1]<<8)| didBuf_F114[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parOlClAngRiseRate(void)
{
	
//	 didBuf_F115[0] = parOlClAngRiseRate & 0xFF;
//	 didBuf_F115[1] = (parOlClAngRiseRate >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parOlClAngRiseRate(void)
{
//     parOlClAngRiseRate = (didBuf_F115[1]<<8)| didBuf_F115[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parRefSpdRisSlewRate(void)
{
	
//	 didBuf_F116[0] = parRefSpdRisSlewRate & 0xFF;
//	 didBuf_F116[1] = (parRefSpdRisSlewRate >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parRefSpdRisSlewRate(void)
{
 //    parRefSpdRisSlewRate = (didBuf_F116[1]<<8)| didBuf_F116[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parRefSpdRisOLSlewRate(void)
{
	
	// didBuf_F117[0] = parRefSpdRisOLSlewRate & 0xFF;
	// didBuf_F117[1] = (parRefSpdRisOLSlewRate >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parRefSpdRisOLSlewRate(void)
{
  //   parRefSpdRisOLSlewRate = (didBuf_F117[1]<<8)| didBuf_F117[0];

	return nrsp_positiveResponse;
}


//uds_word_t u16_cntOLWait = 0;

uds_byte_t didrd_u16_cntOLWait(void)
{
	
//	 didBuf_F118[0] = u16_cntOLWait & 0xFF;
//	 didBuf_F118[1] = (u16_cntOLWait >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_u16_cntOLWait(void)
{
//     u16_cntOLWait = (didBuf_F118[1]<<8)| didBuf_F118[0];

	return nrsp_positiveResponse;
}


uds_byte_t didrd_parPLLCtrlPropGainColdStart(void)
{
	
//	 didBuf_F119[0] = parPLLCtrlPropGainColdStart & 0xFF;
//	 didBuf_F119[1] = (parPLLCtrlPropGainColdStart >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parPLLCtrlPropGainColdStart(void)
{
 //    parPLLCtrlPropGainColdStart = (didBuf_F119[1]<<8)| didBuf_F119[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parPLLCtrlIntgGainColdStart(void)
{
	
//	 didBuf_F120[0] = parPLLCtrlIntgGainColdStart & 0xFF;
//	 didBuf_F120[1] = (parPLLCtrlIntgGainColdStart >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parPLLCtrlIntgGainColdStart(void)
{
 //    parPLLCtrlIntgGainColdStart = (didBuf_F120[1]<<8)| didBuf_F120[0];

	return nrsp_positiveResponse;
}

uds_byte_t didrd_parPCBTempColdStart_C(void)
{
	
//	 didBuf_F121[0] = parPCBTempColdStart_C & 0xFF;
//	 didBuf_F121[1] = (parPCBTempColdStart_C >>8) & 0xFF;
	
	return nrsp_positiveResponse;
}


uds_byte_t didwt_parPCBTempColdStart_C(void)
{
//     parPCBTempColdStart_C = (didBuf_F121[1]<<8)| didBuf_F121[0];

	return nrsp_positiveResponse;
}

/******************************product information******************************************************/
uds_byte_t didrd_OrderNumber(void)
{
	
  ComIf_Set_ReadFunc_01(didBuf_F187);
	return nrsp_positiveResponse;
}

uds_byte_t didrd_SerialNumber(void)
{
//	unsigned char loop_i;
//	for(loop_i=0; loop_i<12; loop_i++)
//	{
//		didBuf_F18C[loop_i] = fblNvmDts_ram1.VehicleIdentificationNumber[loop_i];
//	}
  ComIf_Set_ReadFunc_02(didBuf_F18C);
	return nrsp_positiveResponse;
}

uds_byte_t didrd_HardwareVersionNumber(void)
{
//	unsigned char loop_i;
//	for(loop_i=0; loop_i<6; loop_i++)
//	{
//		didBuf_F193[loop_i] = fblNvmDts_ram1.VehicleIdentificationNumber[loop_i];
//	}
//	
	 ComIf_Set_ReadFunc_03(didBuf_F193);
	return nrsp_positiveResponse;
}
uds_byte_t didrd_ECUProductionTime(void)
{
//	unsigned char loop_i;
//	for(loop_i=0; loop_i<4; loop_i++)
//	{
//		didBuf_F19D[loop_i] = fblNvmDts_ram1.VehicleIdentificationNumber[loop_i];
//	}
	ComIf_Set_ReadFunc_04(didBuf_F19D); 
	return nrsp_positiveResponse;
}

uds_byte_t didrd_BootVersion(void)
{
	ComIf_Set_ReadFunc_05(didBuf_F180);
	return nrsp_positiveResponse;
}

uds_byte_t didrd_DataVersion(void)
{
	ComIf_Set_ReadFunc_06(didBuf_F182);
	return nrsp_positiveResponse;
}

uds_byte_t didrd_AppVersion(void)
{
	ComIf_Set_ReadFunc_07(didBuf_F195);
	return nrsp_positiveResponse;
}

uds_byte_t didrd_SystemName(void)
{
  ComIf_Set_ReadFunc_08(didBuf_F197);
	return nrsp_positiveResponse;
}






uds_byte_t didwt_SerialNumber(void)
{
//	unsigned char loop_i;
//	for(loop_i=0; loop_i<12; loop_i++)
//	{
//		fblNvmDts_ram2.VehicleIdentificationNumber[loop_i] = didBuf_F18C[loop_i];
//	}
	
	ComIf_Get_WriteFunc_02(didBuf_F18C, 0);
//  Memory_CopyEEPOMRAMToROM();
	return nrsp_positiveResponse;
}



uds_byte_t didwt_HardwareVersionNumber(void)
{
	//unsigned char loop_i;
//	for(loop_i=0; loop_i<6; loop_i++)
//	{
//		fblNvmDts_ram2.VehicleIdentificationNumber[loop_i] = didBuf_F193[loop_i];
//	}
	  ComIf_Get_WriteFunc_03(didBuf_F193, 0);
//	  Memory_CopyEEPOMRAMToROM();
	

	return nrsp_positiveResponse;
}



uds_byte_t didwt_ECUProductionTime(void)
{
//	unsigned char loop_i;
//	for(loop_i=0; loop_i<4; loop_i++)
//	{
//		fblNvmDts_ram2.VehicleIdentificationNumber[loop_i] = didBuf_F19D[loop_i];
//	}
	 ComIf_Get_WriteFunc_04(didBuf_F19D, 0);
//   Memory_CopyEEPOMRAMToROM();
	return nrsp_positiveResponse;
}

/************************************************************************************/

/* ---- Source switch off ---------------------------------------------------- */
#undef UDS_USER_C_
/*--- End of file ------------------------------------------------------------*/


