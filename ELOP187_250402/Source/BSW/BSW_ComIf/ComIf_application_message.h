#ifndef _APPLICATION_MESSAGE_H
#define _APPLICATION_MESSAGE_H

#include <stdint.h>


extern uint8_t Gu8_ComIf_APPRxMsgData[8];
//extern uint8_t Gu8_ComIf_APPRxMesDlc;
extern uint8_t Gu8_ComIf_APPRxMesCnt;
extern uint8_t Gu8_ComIf_SleepReqFlag;
extern uint8_t Gu8_ComIf_APPTxMesFlagFirst;
extern uint8_t Gu8_ComIf_APPTxMesFlagSecond;


void ComIf_Get_APPRxMsgData(uint8_t *u8_APPRxMsgData);
//void ComIf_Get_APPRxMesDlc(uint8_t u8_APPRxMesDlc);
void ComIf_Get_APPRxMesCnt(uint8_t u8_APPRxMesCnt);
void ComIf_Set_APPTxMsgData(uint8_t*TxMsg,uint32_t LINID);
void ComIf_Get_SleepReqFlag(uint8_t u8_SleepReqFlag);

void ComIf_Get_APPTxMesFlagFirst(uint8_t u8_TxMesFlag);
void ComIf_Get_APPTxMesFlagSecond(uint8_t u8_TxMesFlag);
#endif    //_APPLICATION_MESSAGE_H
