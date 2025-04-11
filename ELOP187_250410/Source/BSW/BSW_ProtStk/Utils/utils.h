/*
* Copyright (c) 2016, SHENZHEN HANGSHENG ELECTRONICS Co.,Ltd.
* All Rights Reserved.
* Dept.: Software Department
* File: utils.h
* Description:
* History:
* 2016-6-3, 1007040, original
*/

#ifndef __UTILS_H__
#define __UTILS_H__

#include "typedefs.h"
#include "stdint.h"



extern void memoryCopy(uint8_t *pScr, uint8_t *pDst, uint16_t dlc);
extern uint32_t crc32_discrete(uint32_t seed, uint8_t ckDatas[], uint32_t dlc);
extern uint32_t crc32(uint8_t ckDatas[], uint32_t dlc);
extern uint16_t crc16_discrete(uint16_t seed, uint8_t ckDatas[], uint16_t dlc);
extern uint16_t crc16(uint8_t ckDatas[], uint16_t dlc);
//extern uint32_t canculate_security_access_jili(uint32_t wSeed,uint64_t FMASK,uint32_t initialvalueA);
#endif /*End of __UTILS_H__ */
/*--------EOF--------*/

