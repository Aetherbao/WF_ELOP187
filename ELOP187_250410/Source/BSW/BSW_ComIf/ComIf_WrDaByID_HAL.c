/**************************************** Inclusion files *********************/

#include "ComIf_WrDaByID_HAL.h"
#include "ComIf_RdDaByID_HAL.h"
#include "uds_cfg.h"
//#include "Mem_Mem.h"

////static unsigned char writedata[20];
uint8_t Gu8_ComIf_UDSWriteFlg = 0;
//uint16_t Gu16_ComIf_WakeupSignalTimes;
//uint16_t Gu16_ComIf_SleepSignalTimes;
//uint16_t Gu16_ComIf_LimphomeSpeedSignal;



//0xF18C
void ComIf_Get_WriteFunc_02(const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
{
	
    for(unsigned short j = 0; j < DATA_BYTE_SIZE_02;j++)
    {
       Gu8_ComIf_uSerialNumber[j] = Data[j];
    }
		Gu8_ComIf_UDSWriteFlg = 1;
		*u8_ErrorCode = 0;
	
	
}

//0xF193
void ComIf_Get_WriteFunc_03(const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
{
	
    for(unsigned short j = 0; j < DATA_BYTE_SIZE_03;j++)
    {
       Gu8_ComIf_HWVersion[j] = Data[j];  
    }
		Gu8_ComIf_UDSWriteFlg = 1;
		*u8_ErrorCode = 0;
	
	
}

//0xF19D
void ComIf_Get_WriteFunc_04(const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
{
	
    for(unsigned short j = 0; j < DATA_BYTE_SIZE_04;j++)
    {
       Gu8_ComIf_uECUProductionTime[j] = Data[j];
    }
		Gu8_ComIf_UDSWriteFlg = 1;
		*u8_ErrorCode = 0;
	
	
}








////0xD010   DATA_BYTE_SIZE_14:2
//void ComIf_Get_WriteFunc_14 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{	
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//		Gu16_ComIf_WakeupSignalTimes = (uint16_t)((Data[0] << 8)||Data[1]);
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//	
//}

////0xD011   DATA_BYTE_SIZE_15:2
//void ComIf_Get_WriteFunc_15 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//		Gu16_ComIf_SleepSignalTimes = (uint16_t)((Data[0] << 8)||Data[1]);
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//}

////0xD012   DATA_BYTE_SIZE_16:2
//void ComIf_Get_WriteFunc_16 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//		Gu16_ComIf_LimphomeSpeedSignal = (uint16_t)((Data[0] << 8)||Data[1]);
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//}

////0xE15C   DATA_BYTE_SIZE_31:6
//void ComIf_Get_WriteFunc_31 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//		for(unsigned short j = 0; j < DATA_BYTE_SIZE_31;j++)
//    {
//        Gu8_ComIf_uPumpManufacturingDate[j] = Data[j];
//    }
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//}

////0xE15D   DATA_BYTE_SIZE_32:5
//void ComIf_Get_WriteFunc_32 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//    for(unsigned short j = 0; j < DATA_BYTE_SIZE_32;j++)
//    {
//        Gu8_ComIf_uPumpSerialNumber[j] = Data[j];
//    }
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}

//}

////0xF101   DATA_BYTE_SIZE_36:9
//void ComIf_Get_WriteFunc_36 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//    for(unsigned short j = 0; j < DATA_BYTE_SIZE_36;j++)
//    {
//       Gu8_ComIf_uSerialNumber[j] = Data[j];
//    }
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}

//}

////0xF15A   DATA_BYTE_SIZE_37:9
//void ComIf_Get_WriteFunc_37 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//     for(unsigned short j = 0; j < DATA_BYTE_SIZE_37;j++)
//    {
//         Gu8_ComIf_uFingerPrint[j] = Data[j];
//    }
//		Mem_DataRAM2NVM(MEM_FP);
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
// 
//}

////0xF187   DATA_BYTE_SIZE_39:15
//void ComIf_Get_WriteFunc_39 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//    for(unsigned short j = 0; j < DATA_BYTE_SIZE_39;j++)
//    {
//       Gu8_ComIf_uOrdernumber[j] = Data[j];
//    }
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//}

////0xF18A   DATA_BYTE_SIZE_40:4
//void ComIf_Get_WriteFunc_40 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//    for(unsigned short j = 0; j < DATA_BYTE_SIZE_40;j++)
//    {
//         Gu8_ComIf_uSupplierID[j] = Data[j];
//    }
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//}

////0xF192   DATA_BYTE_SIZE_41:10
//void ComIf_Get_WriteFunc_41 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//    for(unsigned short j = 0; j < DATA_BYTE_SIZE_41;j++)
//    {
//         Gu8_ComIf_uHardwareID[j] = Data[j];
//    }
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//	

//}

////0xF194   DATA_BYTE_SIZE_41:10
//void ComIf_Get_WriteFunc_43 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode)
//{
//	if((busComIf_UDSRead_In.u16_nActMechSpd < 10)|| ((busComIf_UDSRead_In.u16_nRmpRefMechSpd < 10)))
//	{
//    for(unsigned short j = 0; j < DATA_BYTE_SIZE_43;j++)
//    {
//        Gu8_ComIf_uSofwareVersion[j] = Data[j];
//    }
//		Gu8_ComIf_UDSWriteFlg = 1;
//		*u8_ErrorCode = 0;
//	}
//	else
//	{
//		*u8_ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//	}
//}

