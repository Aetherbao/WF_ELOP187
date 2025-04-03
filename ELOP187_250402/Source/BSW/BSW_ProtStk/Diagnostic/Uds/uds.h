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
#ifndef UDS_H_
#define UDS_H_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/

#include "uds_types.h"
#include "uds_cfg.h"
#include "uds_user.h"
/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/



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
/* Export for UDS callback and task */
extern void uds_requestProcess(void); /* callback by NT layer */
extern void ProtStk_UDS_Init(void);
extern void uds_task(void); /* Background task (NT task called in this function) */

/* Export for UDS service process */
extern uds_byte_t uds_getActiveSession(void);
extern void uds_enterProgSession(void);
extern uds_bool_t uds_saLevelUnlockCheck(uds_byte_t saLevel);
extern uds_bool_t uds_saLevelUnlockCheckByIndex(uds_byte_t saLv_index);
extern void uds_setPopDataIndex(uds_word_t index);
extern uds_byte_t uds_popRequestData(uds_byte_t defaultDt);
extern uds_word_t uds_remainRequestDLC(void);
extern uds_byte_t uds_curRequestSID(void);
extern uds_word_t uds_getRequestDataLen(void);
extern void uds_rspPending(void);
extern uds_bool_t uds_isRspPending(void);
extern uds_bool_t uds_isNotYetRsp(void);
extern void uds_preActiveResponse(uds_byte_t servID);
extern void uds_pushRspData(uds_byte_t data);
extern void uds_pushRspBuf(uds_byte_t buf[], uds_word_t len);
extern uds_word_t uds_getResponseDataLen(void);
extern void uds_sendResponse(void);
extern void uds_noRsp(void);
extern void uds_positiveRsp(uds_byte_t rspDts[], uds_word_t rspLen);
extern void uds_negativeRsp(uds_byte_t nrspCode);

/* Export of pre-define service */
extern void serv_sessionControl(void);
extern void serv_securityAccess(void);
extern void serv_testPresent(void);
extern void serv_didRead(void);
extern void serv_didWrite(void);
extern void serv_readMemoryByAddr(void);
extern void serv_routineControl(void);
extern void serv_dtcInforClear(void);
extern void serv_dtcInforRead(void);
extern void serv_ioControl(void);


#endif

