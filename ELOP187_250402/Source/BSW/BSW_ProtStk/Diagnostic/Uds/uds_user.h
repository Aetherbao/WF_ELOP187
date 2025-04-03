/*
* Copyright (c) File 2016-08-11,SHENZHEN HANGSHENG NEW ENERGY Co.,Ltd.
* All Rights Reserved.
* Dept.: Software Department
* File:p
* Description:
* REQ IDs:
* History:
* 2017-12-25
*/

/* ---- Source switch on ------------------------------------------------------*/
#ifndef UDS_USER_H_
#define UDS_USER_H_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "uds_types.h"
#include "fbl_infor.h"
//#include "address_area_allocation_define.h"
/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/
/* Service: ECU reset */
#define servm_resetType_hardware                    (0x01u)
#define servm_resetTYpe_keyOffOn                    (0x02u)
#define servm_resetType_software                    (0x03u)
#define servm_resetType_enableRapidPowerShutDown    (0x04u)
#define servm_resetType_disableRapidPowerShutDown   (0x05u)
/* Service: Communication control */
#define servm_comCtrl_enableRxAndTx                 (0x00u)
#define servm_comCtrl_enableRxAndDisableTx          (0x01u)
#define servm_comCtrl_disableRxAndEnableTx          (0x02u)
#define servm_comCtrl_disableRxAndTx                (0x03u)
#define servm_comType_normal                        (0x01u)
#define servm_comType_networkManagement             (0x02u)
#define servm_comType_normalAndNm                   (0x03u)
/* Service: Control DTC setting */
#define servm_dtcSetting_on                         (0x01u)
#define servm_dtcSetting_off                        (0x02u)
/* Service: request download */
#define servm_reqDL_dataFormatOriginal              (0x00u) /* no compressionMethod nor encryptingMethod is used */
#define servm_invalidMta0                           (0xFFFFFFFFul)
/* Service: downloading (transfer data) */
/* Block valid data only, not include service ID and block SN.
 * Must aline with 8 bytes and can be divisible by 1kbyte.
 * And for transfer data stability, do not above 1024. (Actually max buffer size can be 65528) */
#define servm_tdBlockCacheDLC                       (5u)  //512u
/* Service: routine control, for eraseMemory */
#define servm_rtEraseMem_allAppProgFlash            (0x0Fu)
#define servm_rtEraseMem_allAppDataFlash            (0x0Eu)
#define servm_rtEraseMem_allExEEPROM                (0xEEu)
/* Service: routine - stayInBoot */
#define servm_stayInBootAcceptFlag                  (0x19A7u)
#define servm_stayInBootRejectFlag                  (0x0000u)

/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/
typedef enum
{
    progSt_idle = 0,
    progSt_appFingerprintValid,
    progSt_fdDownloadAllowed,
    progSt_fdDownloading,
    progSt_fdDownloadCompelete,
    progSt_fdDownloadCheckPass,
    progSt_eraseSuccess,
    progSt_downloadAllowed,
    progSt_downloading,
    progSt_downloadCompelete,
    progSt_downloadCheckPass, /* Program compelete */
    progErr_appFingerprintSaveFail,
    progErr_flashDriverInvalid,
    progErr_eraseFlashFail,
    progErr_downloadReject,
    progErr_downloadProgFail,
    progErr_downloadUnExpectTerminal,
    progErr_programFlashFail,
    progErr_unExpectTerminal
}progStatus_t;


/*------------------------------------------------------------------------------
                      External declaration of global RAM-Variables
------------------------------------------------------------------------------*/

/* Export: variable */
//extern uint8_t didBuf_F101[16];
//extern uint8_t didBuf_F102[16];
//extern uint8_t didBuf_F103[16];
//extern uint8_t didBuf_F104[16];
//extern uint8_t didBuf_F186[1];
extern uint8_t didBuf_F100[4];
//extern uint8_t didBuf_F18C[5];
//extern uint8_t didBuf_F18B[3];
//extern uint8_t didBuf_F152[2];
//extern uint8_t didBuf_1600[16];
//extern uint8_t didBuf_1601[16];
//extern uint8_t didBuf_2504[12];
//extern uint8_t didBuf_250A[2];
//extern uint8_t didBuf_250B[20];
//extern uint8_t didBuf_2501[10];
//extern uint8_t didBuf_2502[4];
//extern uint8_t didBuf_2503[2];
//extern uint8_t didBuf_2506[4];
//extern uint8_t didBuf_2507[1];
//extern uint8_t didBuf_F18A[3];
//extern uint8_t didBuf_F190[17];
//extern uint8_t didBuf_100A[16];
//extern uint8_t didBuf_100E[16];
//extern uint8_t didBuf_F15A[4];
//extern uint8_t didBuf_F190[17];


extern uint8_t didBuf_F187[15];	
extern uint8_t didBuf_F18C[12];
extern uint8_t didBuf_F193[10];
extern uint8_t didBuf_F19D[4];
extern uint8_t didBuf_F180[10];
extern uint8_t didBuf_F182[25];
extern uint8_t didBuf_F195[10];
extern uint8_t didBuf_F197[7];


extern uint8_t didBuf_F101[2];
extern uint8_t didBuf_F102[2];
extern uint8_t didBuf_F103[2];
extern uint8_t didBuf_F104[2];
extern uint8_t didBuf_F105[2];
extern uint8_t didBuf_F106[2];
extern uint8_t didBuf_F107[2];
extern uint8_t didBuf_F108[2];
extern uint8_t didBuf_F109[2];
extern uint8_t didBuf_F110[2];
extern uint8_t didBuf_F111[2];
extern uint8_t didBuf_F112[2];
extern uint8_t didBuf_F113[1];
extern uint8_t didBuf_F114[2];
extern uint8_t didBuf_F115[2];
extern uint8_t didBuf_F116[2];
extern uint8_t didBuf_F117[2];
extern uint8_t didBuf_F118[2];
extern uint8_t didBuf_F119[2];
extern uint8_t didBuf_F120[2];
extern uint8_t didBuf_F121[2];
/*------------------------------------------------------------------------------
                      External declaration of global ROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                    External declaration of global EEPROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/

/* Export: service function */
extern void serv_ecuReset(void);
extern void serv_comControl(void);
extern void serv_dtcSetting(void);
extern void serv_requestDownload(void);
//extern void serv_transferData(void);
extern void serv_requestTransferExit(void);
/* Export: DID read, write callback function */
extern uds_byte_t didrd_ActiveSessionState(void);
extern uds_byte_t didrd_VehicleIndentifyNumber(void);
extern uds_byte_t didwt_VehicleIndentifyNumber(void);
extern uds_byte_t didwt_Fingerprint(void);
extern uds_byte_t didrd_programCnt(void);
extern uds_byte_t didrd_BreakMemoryAddress(void);

extern uds_byte_t didrd_BootVersion(void);
extern uds_byte_t didrd_AppVersion(void);
extern uds_byte_t didrd_OrderNumber(void);
extern uds_byte_t didrd_DataVersion(void);
extern uds_byte_t didrd_SystemName(void);
extern uds_byte_t didrd_SerialNumber(void);
extern uds_byte_t didwt_SerialNumber(void);
extern uds_byte_t didrd_HardwareVersionNumber(void);
extern uds_byte_t didwt_HardwareVersionNumber(void);
extern uds_byte_t didrd_ECUProductionTime(void);
extern uds_byte_t didwt_ECUProductionTime(void);

/* Export: Routine control */
//extern uds_byte_t rtStart_eraseMemory(void);
extern uds_bool_t rtSpt_appIDcheck(void);
//extern uds_byte_t rtStart_checkDependencies(void);
extern uds_byte_t rtStart_checkAppDataIntegrity(void);
extern uds_byte_t rtStart_stayInBoot(void);
extern uds_byte_t rtStart_HSAETest(void);
extern uds_bool_t uds_allowedJumpToApp(void);
extern uds_byte_t rtStart_reprogramConditionCheck(void);
extern void ecuResetTrig(void);


extern unsigned char	Flag_ecureset;


extern uds_byte_t didrd_parSpdCtrlPropGain(void);
extern uds_byte_t didwt_parSpdCtrlPropGain(void);
extern uds_byte_t didrd_parSpdCtrlIntgGain(void);
extern uds_byte_t didwt_parSpdCtrlIntgGain(void);
extern uds_byte_t didrd_parDirCurrCtrlPropGain(void);
extern uds_byte_t didwt_parDirCurrCtrlPropGain(void);
extern uds_byte_t didrd_parDirCurrCtrlIntgGain(void);
extern uds_byte_t didwt_parDirCurrCtrlIntgGain(void);
extern uds_byte_t didrd_parQdrtCurrCtrlPropGain(void);
extern uds_byte_t didwt_parQdrtCurrCtrlPropGain(void);
extern uds_byte_t didrd_parQdrtCurrCtrlIntgGain(void);
extern uds_byte_t didwt_parQdrtCurrCtrlIntgGain(void);
extern uds_byte_t didrd_parPLLCtrlPropGain(void);
extern uds_byte_t didwt_parPLLCtrlPropGain(void);
extern uds_byte_t didrd_parPLLCtrlIntgGain(void);
extern uds_byte_t didwt_parPLLCtrlIntgGain(void);
extern uds_byte_t didrd_parMinSnslRefElctSpd(void);
extern uds_byte_t didwt_parMinSnslRefElctSpd(void);
extern uds_byte_t didrd_parStlgStrtUpElctSpd(void);
extern uds_byte_t didwt_parStlgStrtUpElctSpd(void);
extern uds_byte_t didrd_parSnslElctAngDely(void);
extern uds_byte_t didwt_parSnslElctAngDely(void);
extern uds_byte_t didrd_parMinStrtUpElctSpd(void);
extern uds_byte_t didwt_parMinStrtUpElctSpd(void);
extern uds_byte_t didrd_parAngPosEvalMode(void);
extern uds_byte_t didwt_parAngPosEvalMode(void);
extern uds_byte_t didrd_parStrtUpProcTolElctSpd(void);
extern uds_byte_t didwt_parStrtUpProcTolElctSpd(void);
extern uds_byte_t didrd_parOlClAngRiseRate(void);
extern uds_byte_t didwt_parOlClAngRiseRate(void);
extern uds_byte_t didrd_parRefSpdRisSlewRate(void);
extern uds_byte_t didwt_parRefSpdRisSlewRate(void);
extern uds_byte_t didrd_parRefSpdRisOLSlewRate(void);
extern uds_byte_t didwt_parRefSpdRisOLSlewRate(void); 
extern uds_byte_t didrd_u16_cntOLWait(void);
extern uds_byte_t didwt_u16_cntOLWait(void); 

extern uds_byte_t didrd_parPLLCtrlPropGainColdStart(void);
extern uds_byte_t didwt_parPLLCtrlPropGainColdStart(void);
extern uds_byte_t didrd_parPLLCtrlIntgGainColdStart(void);
extern uds_byte_t didwt_parPLLCtrlIntgGainColdStart(void);
extern uds_byte_t didrd_parPCBTempColdStart_C(void);
extern uds_byte_t didwt_parPCBTempColdStart_C(void);

#endif

