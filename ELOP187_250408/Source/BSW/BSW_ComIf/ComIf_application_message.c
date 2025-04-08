#include "ComIf_application_message.h"
#include "genLinConfig.h"

uint8_t Gu8_ComIf_APPRxMsgData[8];
//uint8_t Gu8_ComIf_APPRxMesDlc;
uint8_t Gu8_ComIf_APPRxMesCnt;

uint8_t Gu8_ComIf_SleepReqFlag;

uint8_t Gu8_ComIf_APPTxMesFlagFirst;
uint8_t Gu8_ComIf_APPTxMesFlagSecond;

void ComIf_Get_APPRxMsgData(uint8_t *u8_APPRxMsgData)
{
	  uint8_t l_DataIndx;
			/* Get the recived data */
		for (l_DataIndx = 0; l_DataIndx < 8; l_DataIndx++)
		{
			Gu8_ComIf_APPRxMsgData[l_DataIndx] = u8_APPRxMsgData[l_DataIndx];
		}
}

//void ComIf_Get_APPRxMesDlc(uint8_t u8_APPRxMesDlc)
//{
//	Gu8_ComIf_APPRxMesDlc = u8_APPRxMesDlc;
//}

void ComIf_Get_APPRxMesCnt(uint8_t u8_APPRxMesCnt)
{
	Gu8_ComIf_APPRxMesCnt = u8_APPRxMesCnt;
}


void ComIf_Set_APPTxMsgData(uint8_t*TxMsg,uint32_t LINID)
{
	
	 ComDrv_Set_APPTxMsgData(TxMsg, LINID);
}

void ComIf_Get_SleepReqFlag(uint8_t u8_SleepReqFlag)
{
	Gu8_ComIf_SleepReqFlag = u8_SleepReqFlag;
}

void ComIf_Get_APPTxMesFlagFirst(uint8_t u8_TxMesFlag)
{
	Gu8_ComIf_APPTxMesFlagFirst = u8_TxMesFlag;
}

void ComIf_Get_APPTxMesFlagSecond(uint8_t u8_TxMesFlag)
{
	Gu8_ComIf_APPTxMesFlagSecond = u8_TxMesFlag;
}

