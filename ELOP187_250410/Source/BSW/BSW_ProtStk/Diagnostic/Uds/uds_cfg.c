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
#define UDS_CFG_C_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "utils.h"
#include "LinTp_types.h"
#include "uds_types.h"
#include "uds.h"
#include "uds_cfg.h"
#include "uds_user.h"


#include "ComIf_RdDaByID_HAL.h"
#include "ComIf_SA_HAL.h"
/*-----------------------------------------------------------------------------
                   		Module local defines and constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                                 Module local types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                Local data at RAM
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                Local data at ROM
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Local data at EEPROM
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                Global data at RAM
------------------------------------------------------------------------------*/
/* ----------------- UDS security access level map ------------------- */
uds_byte_t saLvBuf_fbl[3] = {0, 0, 0};  //saLvBuf_fbl[4] = {0, 0, 0, 0};
/*------------------------------------------------------------------------------
                                Global data at ROM
------------------------------------------------------------------------------*/

/* ------------------- UDS Session map define ------------------- */
/* Map order mast fit with ssSpt_t enum item define order */
const uds_byte_t sessionTypeMap[ssSptCnt] =
{
    /* ssSpt_std  --> */ sessionType_std,
    /* ssSpt_prog --> */ sessionType_prog,
    /* ssSpt_ext  --> */ sessionType_ext
};

/* Session support count */
const uds_byte_t sessionTypeCnt = ssSptCnt;

const saLevelMap_t saLevelMap[saLvSptCnt] =
{
                       /* SA Level,   Seed Buffer,   Buf DLC  */
    /* saLvSpt_fbl --> */ {0x1,      saLvBuf_fbl,   3}  //{0x11,      saLvBuf_fbl,   4}
};

/* Security access suport levels count */
const uds_byte_t saLevelCnt = saLvSptCnt;
/* ----------------- End UDS Session map define ---------------------- */


/* ----------------- Session Control and Security Access related configs -------------- */
/* Automatic switch and locked session time */
const uds_dWord_t ssSwStd_saLockTime = 5000ul; /* [UDS task cycle] */
/* Security access protect paramters */
const uds_byte_t saProtectLimitCnt = 3;
const uds_dWord_t saProtectDelayTime = 60000ul; /* [UDS task cycle], Delay to access unlock forbid after protect active */
const uds_dWord_t saProtectPowerOnDelayTime = 100ul; /* [UDS task cycle, Delay to access unlock forbit after reset or power-on  */
/* ----------------- End Session Control and Security Access related configs ---------- */

/* ----------------- UDS service support config ---------------------- */
/* Note: Set callback funtion to serv_sessionControl and serv_securityAccess
 *       if need used preset Session & Security Management of UDS module */
const udsServCfg_t udsServCfg[udsServiceSptCnt] =
{
    /* SID,                          Session Support Mask,              saDeniedMask,     minDLC, process function */
/* Pre-define service */
    {sid_sessionControl,             ssSptMask_all,                     FALSE,            1,      &serv_sessionControl},
    {sid_securityAccess,             ssSptMask_ext,    					FALSE,            1,      &serv_securityAccess},
    {sid_testPresent,                ssSptMask_all,                     FALSE,            1,      &serv_testPresent},
    {sid_readDataByIdentifier,       ssSptMask_all,                     FALSE,            2,      &serv_didRead},
    {sid_writeDataByIdentifier,      ssSptMask_ext,                    saLvSptMask_fbl,            3,      &serv_didWrite},    //saLvSptMask_fbl
   // {sid_readMemoryByAddress,        ssSptMask_all,                     saLvSptMask_none, 3,      &serv_readMemoryByAddr},
    {sid_routineControl,             ssSptMask_all,                     FALSE,            3,      &serv_routineControl},
/* User define service */
    {sid_ecuReset,                   ssSptMask_all,                     FALSE,            1,      &serv_ecuReset},
   // {sid_communicationControl,       ssSptMask_ext,                     FALSE,            2,      &serv_comControl},
   // {sid_controlDTCSetting,          ssSptMask_ext,                     FALSE,            1,      &serv_dtcSetting},
    {sid_requestDownload,            ssSptMask_prog,                    FALSE,  5,      &serv_requestDownload}, //saLvSptMask_fbl
//    {sid_transferData,               ssSptMask_prog,                    FALSE,  3,      &serv_transferData}, //saLvSptMask_fbl
    {sid_requestTransferExit,        ssSptMask_prog,                    FALSE,  0,      &serv_requestTransferExit}//saLvSptMask_fbl
};
/* Service support count */
const uint8_t udsServCnt = udsServiceSptCnt;

/* ----------------- DID config -------------------------------------- */
const udsDIDcfg_t udsDIDcfg[udsDIDsptCnt] =
{
//    	{0xF101, servm_didReadOnly,  16, didBuf_F101, NULL_PTR,         NULL_PTR},
//    	{0xF102, servm_didReadOnly,  16, didBuf_F102, NULL_PTR,         NULL_PTR},
//    	{0xF103, servm_didReadOnly,  16, didBuf_F103, NULL_PTR,         NULL_PTR},
//    	{0xF104, servm_didReadOnly,  16, didBuf_F104, NULL_PTR,         NULL_PTR},
//    	{0xF186, servm_didReadOnly,  1,   didBuf_F186, NULL_PTR,         NULL_PTR},
    	{0xF100, servm_didReadOnly,  4,   didBuf_F100, &didrd_ActiveSessionState,         NULL_PTR},
//    	{0xF18C, servm_didReadOnly,  5,   didBuf_F18C, NULL_PTR,         NULL_PTR},
//    	{0xF18B, servm_didReadOnly,  3,   didBuf_F18B, NULL_PTR,         NULL_PTR},
//    	{0xF152, servm_didReadOnly,  2,   didBuf_F152, NULL_PTR,         NULL_PTR},
//    	{0x1600, servm_didReadOnly,  16, didBuf_1600, NULL_PTR,         NULL_PTR},
//    	{0x1601, servm_didReadOnly,  16, didBuf_1601, NULL_PTR,         NULL_PTR},
//    	{0x2504, servm_didReadOnly,  12, didBuf_2504, NULL_PTR,         NULL_PTR},
//    	{0x250A, servm_didReadOnly,  2,  didBuf_250A, NULL_PTR,         NULL_PTR},
//    	{0x250B, servm_didReadOnly,  20, didBuf_250B, NULL_PTR,         NULL_PTR},
//    	{0x2501, servm_didReadOnly,  10, didBuf_2501, NULL_PTR,         NULL_PTR},
//    	{0x2502, servm_didReadOnly,  4,   didBuf_2502, &didrd_programCnt,         NULL_PTR},
//    	{0x2503, servm_didReadOnly,  2,   didBuf_2503, NULL_PTR,         NULL_PTR},
//    	{0x2506, servm_didReadOnly,  4,   didBuf_2506, &didrd_BreakMemoryAddress,         NULL_PTR},
//    	{0x2507, servm_didReadOnly,  1,   didBuf_2507, NULL_PTR,         NULL_PTR},
//    	{0xF18A, servm_didReadOnly,  3,   didBuf_F18A, NULL_PTR,         NULL_PTR},
//   	{0xF190, servm_didReadWrite, 17,  didBuf_F190, &didrd_VehicleIndentifyNumber,         &didwt_VehicleIndentifyNumber},
//    	{0x100A, servm_didReadOnly,  16,  didBuf_100A, NULL_PTR,         NULL_PTR},
//    	{0x100E, servm_didReadOnly,  16,  didBuf_100E, NULL_PTR,         NULL_PTR},
//    	{0xF15A, servm_didWriteOnly,  4,   didBuf_F15A, NULL_PTR,         &didwt_Fingerprint}
//			  {0xF180, servm_didReadOnly,  4,   didBuf_F180, &didrd_BootVersion,         NULL_PTR},
//				{0xF195, servm_didReadOnly,  6,   didBuf_F195, &didrd_AppVersion,         NULL_PTR},
				{0xF101, servm_didReadWrite, 2,   didBuf_F101, &didrd_parSpdCtrlPropGain,         &didwt_parSpdCtrlPropGain},
				{0xF102, servm_didReadWrite, 2,   didBuf_F102, &didrd_parSpdCtrlIntgGain,         &didwt_parSpdCtrlIntgGain},
				{0xF103, servm_didReadWrite, 2,  didBuf_F103, &didrd_parDirCurrCtrlPropGain,         &didwt_parDirCurrCtrlPropGain},
				{0xF104, servm_didReadWrite, 2,  didBuf_F104, &didrd_parDirCurrCtrlIntgGain,         &didwt_parDirCurrCtrlIntgGain},
				{0xF105, servm_didReadWrite, 2,  didBuf_F105, &didrd_parQdrtCurrCtrlPropGain,         &didwt_parQdrtCurrCtrlPropGain},
				{0xF106, servm_didReadWrite, 2,  didBuf_F106, &didrd_parQdrtCurrCtrlIntgGain,         &didwt_parQdrtCurrCtrlIntgGain},
				{0xF107, servm_didReadWrite, 2,  didBuf_F107, &didrd_parPLLCtrlPropGain,         &didwt_parPLLCtrlPropGain},
				{0xF108, servm_didReadWrite, 2,  didBuf_F108, &didrd_parPLLCtrlIntgGain,         &didwt_parPLLCtrlIntgGain},
				{0xF109, servm_didReadWrite, 2,  didBuf_F109, &didrd_parMinSnslRefElctSpd,         &didwt_parMinSnslRefElctSpd},
				{0xF110, servm_didReadWrite, 2,  didBuf_F110, &didrd_parMinStrtUpElctSpd,         &didwt_parMinStrtUpElctSpd},
				{0xF111, servm_didReadWrite, 2,  didBuf_F111, &didrd_parStlgStrtUpElctSpd,         &didwt_parStlgStrtUpElctSpd},
				{0xF112, servm_didReadWrite, 2,  didBuf_F112, &didrd_parSnslElctAngDely,         &didwt_parSnslElctAngDely},
				{0xF113, servm_didReadWrite, 1,  didBuf_F113, &didrd_parAngPosEvalMode,         &didwt_parAngPosEvalMode},
				{0xF114, servm_didReadWrite, 2,  didBuf_F114, &didrd_parStrtUpProcTolElctSpd,         &didwt_parStrtUpProcTolElctSpd},
				{0xF115, servm_didReadWrite, 2,  didBuf_F115, &didrd_parOlClAngRiseRate,         &didwt_parOlClAngRiseRate},
				{0xF116, servm_didReadWrite, 2,  didBuf_F116, &didrd_parRefSpdRisSlewRate,         &didwt_parRefSpdRisSlewRate},
				{0xF117, servm_didReadWrite, 2,  didBuf_F117, &didrd_parRefSpdRisOLSlewRate,         &didwt_parRefSpdRisOLSlewRate},
				{0xF118, servm_didReadWrite, 2,  didBuf_F118, &didrd_u16_cntOLWait,         &didwt_u16_cntOLWait},
        {0xF119, servm_didReadWrite, 2,  didBuf_F119, &didrd_parPLLCtrlPropGainColdStart,         &didwt_parPLLCtrlPropGainColdStart},
				{0xF120, servm_didReadWrite, 2,  didBuf_F120, &didrd_parPLLCtrlIntgGainColdStart,         &didwt_parPLLCtrlIntgGainColdStart},
				{0xF121, servm_didReadWrite, 2,  didBuf_F121, &didrd_parPCBTempColdStart_C,         &didwt_parPCBTempColdStart_C},
				{DATA_DID_01, servm_didReadOnly,  DATA_BYTE_SIZE_01,   didBuf_F187,  &didrd_OrderNumber,         NULL_PTR},
				{DATA_DID_02, servm_didReadWrite, DATA_BYTE_SIZE_02,   didBuf_F18C, &didrd_SerialNumber,         &didwt_SerialNumber},
				{DATA_DID_03, servm_didReadWrite, DATA_BYTE_SIZE_03,   didBuf_F193, &didrd_HardwareVersionNumber,  &didwt_HardwareVersionNumber},
				{DATA_DID_04, servm_didReadWrite, DATA_BYTE_SIZE_04,   didBuf_F19D, &didrd_ECUProductionTime,         &didwt_ECUProductionTime},
				{DATA_DID_05, servm_didReadOnly,  DATA_BYTE_SIZE_05,   didBuf_F180, &didrd_BootVersion,         NULL_PTR},
				{DATA_DID_06, servm_didReadOnly,  DATA_BYTE_SIZE_06,   didBuf_F182, &didrd_DataVersion,         NULL_PTR},
				{DATA_DID_07, servm_didReadOnly,  DATA_BYTE_SIZE_07,   didBuf_F195, &didrd_AppVersion,         NULL_PTR},
				{DATA_DID_08, servm_didReadOnly,  DATA_BYTE_SIZE_08,   didBuf_F197, &didrd_SystemName,         NULL_PTR},
};
/* DID support count */
const uds_word_t udsDIDcnt = udsDIDsptCnt;
/* ----------------- End DID config ---------------------------------- */

/* ----------------- Routine Control Global Mask --------------------- */
const uds_byte_t udsRtGlobalMask = servm_rtGlobalMask_start;
/* ----------------- End Routine Control Global Mask ----------------- */

/* ----------------- Routine control config -------------------------- */

const udsRtIDcfg_t udsRtIDcfg[udsRtIDsptCnt] =
{
    /* RID value,                       Start routine,             Stop routine,         Get routine result, Routine Task */
//    {rtid_eraseMemory,                  rtStart_eraseMemory,       NULL_PTR,                 NULL_PTR,               NULL_PTR},
//    {rtid_checkProgrammingDependencies, rtStart_checkDependencies, NULL_PTR,                 NULL_PTR,               NULL_PTR},
    {rtid_checkAppDataIntegrity, rtStart_checkAppDataIntegrity, NULL_PTR,                 NULL_PTR,               NULL_PTR},
    {rtid_hs_stayInBoot,                rtStart_stayInBoot,        NULL_PTR,                 NULL_PTR,               NULL_PTR},
};

const uds_word_t udsRtIDcnt = udsRtIDsptCnt;

/*chip memory range configure*/
const chipMemCfg_t chipMemCfg[chipMem_cnt] =
{
	{0xAF000000,	0xAF01FFFF,	NULL,	NULL},
	{0xA0000000,	0xA01FFFFF,	NULL,	NULL},	
	{0x70000000,	0x7002DFFF,	NULL,	NULL}
};



/*------------------------------------------------------------------------------
                             Global data at EEPROM
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                         Declaration of local functions
------------------------------------------------------------------------------*/
static uds_byte_t uds_getSaLvIndex(uds_byte_t saLevel);
/*------------------------------------------------------------------------------
                      Implementation of global functions
------------------------------------------------------------------------------*/
/*
 * Function:uds_sessionTimeout
 * Param<void>:
 * Return<void>:
 * Discription: This callback is be called when UDS detect no any service request in not-default session.
 * Note: Before call this function, the session is auto switch to default, and SA was been auto locked.
*/
void uds_sessionTimeout(void)
{

}

/* ---------------------------------- UDS pre-set service support callback functions ---------------------------------- */
/*
 * Function: uds_sessionSwitch
 * Param<uint8_t actSession>: Current active session ID (Not index)
 * Param<uint8_t tragetSession>: Target Session ID (Not index)
 * Return<bool>: 0x00 for active response (Accept), Others for negtive response (Reject, Used NRSP Code)
 *               See uds_types.h Standard Negative Response Code
 * Discription:
 * Note: 1. For read more request data, used uds_popRequestData. It read start from next data of request switch session
 *       2. For response more data after request switch session, used uds_pushRspData function to push data to response after request switch session.
*/
uds_byte_t uds_sessionSwitch(uds_byte_t actSession, uds_byte_t targetSession)
{
	uds_word_t swMask = ssSwitchMask(actSession, targetSession);
    uds_byte_t  nrspCode = nrsp_conditionsNotCorrect;
    uds_byte_t  ss_i = 0; /* session index */

    /* Sub-function search */
    for (; ss_i < sessionTypeCnt; ss_i++)
    {
        if (targetSession == sessionTypeMap[ss_i])
        {
            break;
        }
    }
    /* Search result check */
    if (ss_i >= sessionTypeCnt)
    {
        /* Sub-function not support */
        nrspCode = nrsp_subFunctionNotSupported;
    }
    else
    {
		/* Switch support check */
		switch(swMask)
		{
			case ssSwitch_stdTostd:
			case ssSwitch_stdToExt:
			case ssSwitch_stdToProg:     //JILI
			case ssSwitch_extToStd:
			case ssSwitch_extToProg:
			case ssSwitch_extToExt:
			case ssSwitch_progToStd://positive response and reset,ref to FAW spec
			case ssSwitch_progToprog:
				nrspCode = nrsp_positiveResponse; /* Accept switch */
				break;
				
			default:
				nrspCode = nrsp_subFunctionNotSupportedInActiveSession; /* Not supported switch */
				break;
		}
    }


    return nrspCode;
}

/*
 * Function:uds_saUpdateSeed
 * Param<uint8_t saLevel>: update seed SA level
 * Return<void>:
 * Discription: Update the target level seed buffer (The seed buffer will be response to client)
 * Note: You may need call the timer module counter value to random some bytes.
*/
void uds_saUpdateSeed(uds_byte_t saLevel)
{
    uds_byte_t saLv_i = uds_getSaLvIndex(saLevel); /* get SA level index */
    uds_byte_t seedDt_i = 0; /* seed data index */
    uds_byte_t u8_Seed[3] ={0};
		
    if (saLv_i < saLevelCnt) /* SA level index valid check */
    {
        /* SA level index is valid (SA Level is be support) */
        if ((NULL_PTR != saLevelMap[saLv_i].seedBuf) /* seed buffer un-empty */
            && saLevelMap[saLv_i].seedLen > 0)   /* and seed buffer size above zero(0) */
        {
            if (TRUE == uds_saLevelUnlockCheckByIndex(saLv_i)) /* is in unlock state */
            {
                /* update seed buffer with 0x00 */
                for (; seedDt_i < saLevelMap[saLv_i].seedLen; seedDt_i++)
                {
                    saLevelMap[saLv_i].seedBuf[seedDt_i] = 0x00u;
                }
            }
            else
            {
                /* initial random seed */
                //(void)sys_random(TRUE);
							
							  ComIf_UnlockedL1_GetSeed(u8_Seed,0);
									
                /* generate seed to target(saLevelMap indicate) buffer */
                for (; seedDt_i < saLevelMap[saLv_i].seedLen; seedDt_i++)
                {
                   // saLevelMap[saLv_i].seedBuf[seedDt_i] = (uint8_t)(sys_random(FALSE) & 0xFFul);
									  saLevelMap[saLv_i].seedBuf[seedDt_i] = u8_Seed[seedDt_i];
									
                }
            }
									
        }
    }
}

const uint32_t MASK = 0x59DB7D73;

uint32_t canculate_security_access_bms(uint32_t wSeed, uint32_t wMSAK)
{
	uint32_t iterations ;
	uint32_t wLastSeed ;
	uint32_t wTemp ;
	uint32_t wLSBit ;
	uint32_t wTop31Bits ;
	uint32_t jj,SB1,SB2,SB3;
	uint16_t temp;
	wLastSeed = wSeed ;
	temp =(uint16_t)(( wMSAK & 0x00000800) >> 10) | ((wMSAK & 0x00200000)>> 21);
	if(temp == 0 )
	{
		wTemp = (uint32_t)((wSeed & 0xff000000) >> 24);
	}
	else if(temp == 1)
	{
		wTemp = (uint32_t)((wSeed & 0x00ff0000) >> 16);
	}
	else if(temp == 2)
	{
		wTemp = (uint32_t)((wSeed & 0x0000ff00) >> 8);
	}
	else
	{
		wTemp = (uint32_t)(wSeed & 0x000000ff);
	}
	SB1 = (uint32_t)(( wMSAK & 0x000003FC) >> 2);
	SB2 = (uint32_t)((( wMSAK & 0x7F800000) >> 23)^0xA5);
	SB3 = (uint32_t)((( wMSAK & 0x001FE000) >> 13)^0x5A);
	iterations = (uint32_t)(((wTemp ^ SB1) & SB2) + SB3 );
	for ( jj = 0; jj < iterations; jj++ )
	{
		wTemp = ((wLastSeed & 0x40000000)/0x40000000) ^ ((wLastSeed & 0x01000000)/0x01000000)
		^ ((wLastSeed & 0x1000)/0x1000) ^ ((wLastSeed & 0x04)/0x04) ;
		wLSBit = (wTemp & 0x00000001) ;
		wLastSeed = (uint32_t)(wLastSeed << 1); /* Left Shift the bits */
		wTop31Bits = (uint32_t)(wLastSeed & 0xFFFFFFFE) ;
		wLastSeed = (uint32_t)(wTop31Bits | wLSBit);
	}
	if (wMSAK & 0x00000001)
	{
		wTop31Bits = ((wLastSeed & 0x00FF0000)>>16) | ((wLastSeed & 0xFF000000)>>8) |
		((wLastSeed & 0x000000FF)<<8) | ((wLastSeed & 0x0000FF00)<<16); }
	else
	{
		wTop31Bits = wLastSeed;
	}
	wTop31Bits = wTop31Bits ^ wMSAK;
	
	return( wTop31Bits );
}













/*
 * Function:uds_saCheckKey
 * Param<uint8_t saLevel>:
 * Return<bool>: Check result, TRUE for pass, FALSE for invalid.
 * Discription: The key data need use uds_popRequestData function to get. First call return key[0]
 *              The key lenth need used uds_remainRequestDLC function to get before call uds_popRequestData function,
 *              or used uds_getRequestDataLen() - 1 to get.
 * Note: If the current saLevel is been unlock, it will not call this function and any key check after seed get will be accept.
*/
//uds_dWord_t saSeedTEMP = 0;
//uds_dWord_t saKeyTEMP111 = 0;
//uds_dWord_t saKeyTEMP222 = 0;

uds_bool_t uds_saCheckKey(uds_byte_t saLevel)
{
	uds_dWord_t saSeed = 0;
	uds_dWord_t saKey = 0;
	uds_bool_t ret_val = FALSE;
	uds_byte_t sa_i = 0;
	uds_byte_t byte_i = 0;
	uds_byte_t u8_key[3]={0};
	uds_dWord_t u24_key = 0;
	
	for(; sa_i < saLvSptCnt; sa_i ++ )
	{
		if(saLevelMap[sa_i].level == saLevel)
		{
			break;
		}
	}
	switch (sa_i)
	{
		case 0 :
			for(byte_i = 0; byte_i < saLevelMap[0].seedLen; byte_i ++)
			{
				saSeed = saSeed << 8;
				saSeed = saSeed + (uds_dWord_t)(saLevelMap[0].seedBuf[byte_i]);
				saKey = saKey << 8;
				saKey = saKey + (uds_dWord_t)(uds_popRequestData(0x00));
			}
     		//saSeedTEMP = saSeed;
			  //saKeyTEMP111 =  saKey;
			 // saKeyTEMP222 =  canculate_security_access_jili(saSeed,FMASKTEMP,initialvalueATEMP);
			//if (saKey == (canculate_security_access_bms(saSeed, MASK)& 0x00FFFFFF))
			
			ComIf_UnlockedL1_CompareKey(u8_key,0);
			u24_key= (u8_key[2]<<16)| (u8_key[1]<<8)| u8_key[0];
			//if(saKey == canculate_security_access_jili(saSeed,FMASKTEMP,initialvalueATEMP))
			if(saKey == u24_key)
			{
				ret_val = TRUE;
			}
			break;
		default:
			break;
	}
    return ret_val; /* Any key can be pass */
}

/*
 * Function:uds_didRwReady
 * Param<void>:
 * Return<void>:
 * Discription: This function used to initialize before call UDS DID read/write process function.
 * Note: Normally is empty function if not used background process for DID read/write.
*/
void uds_didRwReady(void)
{
    return;
}

uds_byte_t  uds_getMemIndx(uds_dWord_t memory, uds_word_t size)
{
	uds_byte_t chipMemIndx = 0xFF;
	if(size > 0)
	{
		for(chipMemIndx = 0;chipMemIndx < chipMem_cnt; chipMemIndx ++)
		{
			if((memory >= chipMemCfg[chipMemIndx].startAddr) && ((memory + size - 1) <= chipMemCfg[chipMemIndx].endAddr))
			{
				break;
			}
		}
	}
	return((chipMemIndx < chipMem_cnt)?(chipMemIndx):(0xFF));
}


/* ---------------------------------- End UDS pre-set service support callback functions ---------------------------------- */

/* -------------- user addition functions, macros, variables define ------------- */
/*
 * Function:uds_getSaLvIndex
 * Param<uint8_t saLevel>:
 * Return<static uint8_t>: 0xFF for not find, others for active SA level index
 * Discription:
 * Note:
*/
static uds_byte_t uds_getSaLvIndex(uds_byte_t saLevel)
{
    uint8_t saLv_i = 0;

    /* Search level */
    for (; saLv_i < saLevelCnt; saLv_i++)
    {
        if (saLevel == saLevelMap[saLv_i].level)
        {
            break;
        }
    }

    /* if not find, set index to 0xFF */
    if (saLv_i >= saLevelCnt)
    {
        saLv_i = 0xFFu;
    }

    return saLv_i;
}
/*------------------------------------------------------------------------------
                      Implementation of local functions
------------------------------------------------------------------------------*/




/* ---- Source switch off ---------------------------------------------------- */
#undef UDS_CFG_C_
/*--- End of file ------------------------------------------------------------*/


