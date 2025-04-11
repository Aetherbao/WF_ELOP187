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
#ifndef UDS_CFG_H_
#define UDS_CFG_H_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "uds_types.h"

/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/

#define ssSptCnt   3 /* Must equre ssSpt_t item count, Max support session cnt is 8 */

/* = 0x01 << ssSpt_std */
#define ssSptMask_std  0x01u
/* = 0x01 << ssSpt_prog */
#define ssSptMask_prog 0x02u
/* = 0x01 << ssSpt_ext */
#define ssSptMask_ext  0x04u
#define ssSptMask_all  0xFFu


#define saLvSptCnt 1

#define saLvSptMask_none 0x00u
#define saLvSptMask_fbl  0x01u

#define udsServiceSptCnt 10  //13

#define udsDIDsptCnt 30    //24  4 22

#define udsRtIDsptCnt 4

/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/
/* UDS Session Support Define
 * Note: Not the real uds session value
 *       The real session value used sessionTypeMap to define
 *       Max support session count is 8
 *       First session (enum value 0) must define the default session (standard session)
*/
typedef enum
{
    ssSpt_std = 0,
    ssSpt_prog,
    ssSpt_ext
}ssSpt_t; /* must start from 0, and continue index (it not used in service protocol) */

typedef enum
{
    saLvSpt_fbl = 0,
}saLvSpt_t;



#define chipMem_dataFlash0		0x00
#define chipMem_dataFlash1		0x01
#define chipMem_codeFlash		0x02
#define chipMem_lmuRam			0x03
#define chipMem_CPU0_DSPR		0x04
#define chipMem_SegmentC_Ram	0x05
#define chipMem_SegmentD_Ram	0x06
#define chipMem_cnt				0x03		/*should always be less than 0xFF*/


/*------------------------------------------------------------------------------
                      External declaration of global RAM-Variables
------------------------------------------------------------------------------*/




/*------------------------------------------------------------------------------
                      External declaration of global ROM-Variables
------------------------------------------------------------------------------*/
extern const uds_byte_t sessionTypeMap[ssSptCnt];
extern const uds_byte_t sessionTypeCnt;
extern const saLevelMap_t saLevelMap[saLvSptCnt];
extern const udsServCfg_t udsServCfg[udsServiceSptCnt];
extern const uds_byte_t udsServCnt;
extern const udsDIDcfg_t udsDIDcfg[udsDIDsptCnt];
extern const uds_word_t udsDIDcnt;
extern const uds_byte_t udsRtGlobalMask;
extern const udsRtIDcfg_t udsRtIDcfg[udsRtIDsptCnt];
extern const chipMemCfg_t chipMemCfg[chipMem_cnt];
extern const uds_word_t udsRtIDcnt;
extern const uds_dWord_t ssSwStd_saLockTime;
extern const uds_byte_t saLevelCnt;
extern const uds_byte_t saProtectLimitCnt;
extern const uds_dWord_t saProtectDelayTime;
extern void uds_sessionTimeout(void);
extern uds_byte_t uds_sessionSwitch(uds_byte_t actSession, uds_byte_t targetSession);
extern void uds_saUpdateSeed(uds_byte_t saLevel);
extern uds_bool_t uds_saCheckKey(uds_byte_t saLevel);
extern void uds_didRwReady(void);
extern uds_byte_t  uds_getMemIndx(uds_dWord_t memory, uds_word_t size);
/*------------------------------------------------------------------------------
                    External declaration of global EEPROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/



#endif

