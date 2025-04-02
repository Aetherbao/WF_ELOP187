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
#ifndef UDS_TYPES_H_
#define UDS_TYPES_H_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/
/* UDS defined session type */
#define sessionType_std   0x01 /* default session */
#define sessionType_prog  0x02 /* program session */
#define sessionType_ext   0x03 /* extend session */
#define sessionType_safetySystem 0x04 /* For e.g. airbag deployment */
/* Session switch mask (MSB: form, LSB: to), General used */
#define ssSwitchMask(from, to) ((((from) << 8) & 0xFF00u) | ((to) & 0x00FFu))
#define ssSwitch_stdTostd 0x0101u
#define ssSwitch_stdToProg 0x0102u
#define ssSwitch_stdToExt  0x0103u
#define ssSwitch_progToStd 0x0201u
#define ssSwitch_progToExt 0x0203u
#define ssSwitch_extToStd  0x0301u
#define ssSwitch_extToProg 0x0302u
#define ssSwitch_extToExt  0x0303u
#define ssSwitch_progToprog 0x0202u
/* Switch with safetySystem session */
#define ssSwitch_stdToSafety  0x0104u
#define ssSwitch_progToSafety 0x0204u
#define ssSwitch_extToSafety  0x0304u
#define ssSwitch_safetyToStd  0x0401u
#define ssSwitch_safetyToProg 0x0402u
#define ssSwitch_safetyToExt  0x0403u

/* ------------------- UDS service define ------------------- */
/* Service ID define */
/* Diagnostic and communication management */
#define sid_sessionControl                   (0x10u)
#define sid_ecuReset                         (0x11u)
#define sid_securityAccess                   (0x27u)
#define sid_communicationControl             (0x28u)
#define sid_testPresent                      (0x3Eu)
#define sid_accessTimingParamenter           (0x83u)
#define sid_seuredDataTransmission           (0x84u)
#define sid_controlDTCSetting                (0x85u)
#define sid_responseOnEvent                  (0x86u)
#define sid_linkControl                      (0x87u)
/* Data transmission */
#define sid_readDataByIdentifier             (0x22u)
#define sid_readMemoryByAddress              (0x23u)
#define sid_readScalingDataByIdentifier      (0x24u)
#define sid_readDataByPeriodicIdentifier     (0x2Au)
#define sid_dynamicallyDefineDataIdentifier  (0x2Cu)
#define sid_writeDataByIdentifier            (0x2Eu)
#define sid_writeMemoryByAddress             (0x3Du)
/* Store data transmission */
#define sid_clearDiagnosticInformation       (0x14u)
#define sid_readDTCInformation               (0x19u)
/* Input Output Control */
#define sid_inputOutputControlByIdentifier   (0x2Fu)
/* Remote activation of routine function */
#define sid_routineControl                   (0x31u)
/* Upload download */
#define sid_requestDownload                  (0x34u)
#define sid_requestUpload                    (0x35u)
#define sid_transferData                     (0x36u)
#define sid_requestTransferExit              (0x37u)
/* Service sub-function mask */
#define uds_actSubFunctionMask               (0x7Fu) /* get active subfunction code */
#define uds_actResponseHideBySubFunctionMask (0x80u) /* get subfunction active response hide bit */
/* ------------------- End UDS service ID define ------------------- */

/* ------------------- Standard Negative Response Code (ISO-14229-1) ----------------------- */
#define nrsp_positiveResponse                          (0x00u)
#define nrsp_generalReject                             (0x10u)
#define nrsp_serviceNotSupported                       (0x11u)
#define nrsp_subFunctionNotSupported                   (0x12u)
#define nrsp_incorrectMessageLengthOrInvalidFormat     (0x13u)
#define nrsp_responseTooLong                           (0x14u)
#define nrsp_busyRepeatRequest                         (0x21u)
#define nrsp_conditionsNotCorrect                      (0x22u)
#define nrsp_requestSequenceError                      (0x24u)
#define nrsp_noResponseFromSubnetComponent             (0x25u)
#define nrsp_failurePreventsExecutionOfRequestedAction (0x26u)
#define nrsp_requestOutOfRange                         (0x31u)
#define nrsp_securityAccessDenied                      (0x33u)
#define nrsp_invalidKey                                (0x35u)
#define nrsp_exceedNumberOfAttempts                    (0x36u)
#define nrsp_requiredTimeDelayNotExpired               (0x37u)
#define nrsp_uploadDownloadNotAccepted                 (0x70u)
#define nrsp_transferDataSuspended                     (0x71u)
#define nrsp_generalProgrammingFailure                 (0x72u)
#define nrsp_wrongBlockSequenceCounter                 (0x73u)
#define nrsp_requestCorrectlyReceivedResponsePending   (0x78u)
#define nrsp_subFunctionNotSupportedInActiveSession    (0x7Eu)
#define nrsp_serviceNotSupportedInActiveSession        (0x7Fu)
#define nrsp_temperatureTooHigh                        (0x86u)
#define nrsp_temperatureTooLow                         (0x87u)
#define nrsp_voltageTooHigh                            (0x92u)
#define nrsp_voltageTooLow                             (0x93u)
/*0x38 ~ 0x4F for ISO 15764 Extended */
#define nrsp_downloadNotAccepted                       (0x40u)
#define nrsp_improperDownloadType                      (0x41u)
#define nrsp_cantDownloadToSpecialAddress              (0x42u)
#define nrsp_cantDownloadNumberOfBytesRequested        (0x43u)
/* ------------------- End Standard Negative Response Code (ISO-14229-1) ----------------------- */

/* ------------------- Standard DID define ----------------------- */




/* ------------------- End standard DID define ------------------- */

/* ------------------- Standard routine ID define ---------------- */
#define rtid_eraseMemory                                (0xFF00u)
#define rtid_checkProgrammingDependencies               (0xFF01u)
#define rtid_checkAppDataIntegrity               		(0x0202u)
#define rtid_eraseMirrorMemoryDTCs                      (0xFF02u)

/* ------------------- End standard routine ID define ------------ */

/* ------------------- HSAE pre-define routine ID ---------------- */
#define rtid_hs_stayInBoot                              (0xFE00u)
#define rtid_hs_slaveProgramMode                        (0xFE01u)
#define rtid_hs_reprogramConditionCheck                 (0xFF03u)

/* ------------------- HSAE pre-define routine ID ---------------- */


/* ------------------- For pre-set frequently used service ------------------------------ */
/* Service: session control */
#define servm_ssSptMask(ss_index)    ((uint8_t)(0x01u << (ss_index))) /* ssMap_i is the session index of ssSpt_t enum (also session map item index) */
/* For security access */
#define servm_saLvSptMask(saLv_index)  ((uint8_t)(0x01u << (saLv_index)))
#define servm_saIsGetSeed(saType)   (0x01u == ((saType) & 0x01u))


/* Service: DID read or write */
/* DID access type flags */
#define servm_didReadOnly           (0x01u)
#define servm_didWriteOnly          (0x02u)
#define servm_didReadWrite          (0x03u)
#define servm_didReadAllow(acFlag)  (0 != ((acFlag) & 0x01))
#define servm_didWriteAllow(acFlag) (0 != ((acFlag) & 0x02))


/* Service: routine control */
/* Routine control sub-function */
#define servm_rtidStartRoutine        0x01
#define servm_rtidStopRoutine         0x02
#define servm_rtidGetRoutineResult    0x03
/* Global mask for routine control sub-function: (0x01 << Sub-function) */
#define servm_rtGlobalMask_start      0x02 /* 0x01 << servm_rtidStartRoutine */
#define servm_rtGlobalMask_stop       0x04 /* 0x01 << servm_rtidStopRoutine */
#define servm_rtGlobalMask_getResult  0x08 /* 0x01 << servm_rtidGetRoutineResult */
#define servm_rtGlobalMask_all        0xFF



#define servm_didRwBkcState_idle   (0x00u)
#define servm_didRwBkcState_Read   (0x01u)
#define servm_didRwBkcState_Write  (0x02u)
#define servm_didRwBkcInvalidIndex (0xFFFFu)

/*Memory read/write background process item define*/
#define servm_memRwBkcState_idle	(0x00u)
#define servm_memRwBkcState_read	(0x01u)
#define servm_memRwBkcState_write	(0x02u)
#define servm_memRwBkcInvalidIndx	(0xFFu)

/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/
typedef unsigned short int   uds_word_t;
typedef unsigned char  uds_bool_t;
typedef unsigned char  uds_byte_t;
typedef unsigned long int   uds_dWord_t;





/* Service support config type define */
typedef struct
{
	uds_byte_t sid;    /* Service ID */
	uds_byte_t ssSptMask; /* service session support mask */
	uds_byte_t saDeniedMask; /* 0x00 for not need SA unlock, others for need one of any SA unlock */
	uds_word_t minDLC; /* not include service name */
    void (* processCallBack) (void); /* Process callback function */
}udsServCfg_t;


/* Service: security access */
typedef struct
{
	uds_byte_t level;
	uds_byte_t * seedBuf; /* Seed buffer need to be store when generate for used to check key */
	uds_word_t seedLen;  /* Seed data length (Bytes) */
}saLevelMap_t;

/* DID config struct */
typedef struct
{
	uds_word_t did;      /* DID value */
    uds_byte_t acFlag;    /* Access flag, used access type flag */
    uds_byte_t dlc;       /* DID data length (bytes) */
    uds_byte_t * dtCache; /* Data buffer */
    /* Process callback function.
     * Read: callback, if return success, then response dtCache.
     * Write: set request data to dtCache then callback. If return success, active response.
     * Return value: NRSP code (You can only used 5 NRSP code and 1 positive response code: 0x00 to return)
     *                  nrsp_incorrectMessageLengthOrInvalidFormat
     *                  nrsp_conditionsNotCorrect
     *                  nrsp_securityAccessDenied
     *                  nrsp_generalProgrammingFailure
     *                  nrsp_requestCorrectlyReceivedResponsePending: Will trig a background call by cycle(UDS task cycle) of read/write function.
     *                  nrsp_positiveResponse: Will push data cache to response buffer (read) or send active response only(write).
     *               The nrsp_requestOutOfRange is auto assert in DID read/write service
     * Note: 1. If a value have condition write, please do not set the real value to dtCache.
     *          You need used another buffer cache, and control the real write in callback function.
     *       2. Do not used any UDS response or request function in callback function.
     *          You can used data cache and return value only to get request or set response.
    */
    uds_byte_t (*readCallBack)(void);
    uds_byte_t (*writeCallBack)(void);
}udsDIDcfg_t;


/* Routine control config struct */
/* Note:
 *      1. Routine control (Start: rtStart, Stop: rtStop, Get Result: rtGetResult) return value is NRSP code, but only start routine can support response pending NRSP.
 *      2. For the start routine, both return no NRSP (0x00) or response pending (0x78) will be add the rtTask to UDS background task if rtTask is not empty.
 *      3. If start routine with response pending NRSP. You must support rtTask also. And you need send valid response (Pos. or Neg.) when task compelete(return TRUE).
 *         If you not send real response. It will send response pending always by cycle and will be locked by NT layer always, the UDS will can not receive any more request.
 *         In others, if return response pending NRSP, UDS will autmaticly instead it with conditionsNotCorrect NRSP.
 *      4. Routine task will be always call with uds task cycle after rtTask start till stop call or rtTask return TRUE.
 *         That also means, if a routine is runing with response pending, it will can not start any more other routine.
 *         In addition, the routine task can be call only in uds task. Not call in start routine process.
 *      5. Do not response or read any information of uds in routine task callback (rtTask) if the start routine is not return response pending.
 *      6. Only the first 32 routines can have rtTask, after 32 routine, rtTask is in-valid.
 *      7. You can used UDS data push function to push active response data, but do not trig response send in any callback expect rtTask when rtStart return response pending.
 *      9. It will can not stop task when the uds service automaticly return to default session.
 *         If you need stop it when return to default session or session switch to another, please do it in uds_sessionTimeout or uds_sessionSwitch funtion.
*/
typedef struct
{
	uds_word_t rtid;                   /* Routine Control ID */
    uds_byte_t (*rtStart)(void);       /* Start routine callback */
    uds_byte_t (*rtStop)(void);        /* Stop routine callback */
    uds_byte_t (*rtGetResult)(void);   /* Get routine result callback */
    uds_bool_t (*rtTask)(void);           /* routine task process callback */
}udsRtIDcfg_t;

typedef struct
{
	uds_byte_t bkcState;    /* 0: for IDLE, 1: for read, 2: for write */
	uds_word_t index; /* DID index in DID config array */
}udsDIDrwBkc_t; /* Used bkcState & index to double check background call condition when a DID pending */


typedef struct
{
	uds_byte_t memOperation;
	uds_byte_t memIndx;
}udsMemBkc_t;

typedef struct
{

	uds_dWord_t startAddr;
	uds_dWord_t endAddr;
	uds_byte_t (*readCallback)(void);
	uds_byte_t (*writeCallback)(void);
}chipMemCfg_t;

/*------------------------------------------------------------------------------
                      External declaration of global RAM-Variables
------------------------------------------------------------------------------*/




/*------------------------------------------------------------------------------
                      External declaration of global ROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                    External declaration of global EEPROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/



#endif

