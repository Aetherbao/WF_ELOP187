#include <stdlib.h>
#include "ComIf_RdDaByID_HAL.h"
#include "uds_cfg.h"


//#include "ComIf_RdDTCInf_HAL.h"
//#include "ComIf_UdsDspCfg.h"
//#include "Mem_mem.h"


BUS_COMIF_UDSREAD_IN busComIf_UDSRead_In;

SRAM_PRODUCTINFO_UINT8 Gu8_ComIf_uBootSofwareVersion[10] = {'Y', '2', 'E', 'O', 'P', 'B','1', '0', '5', 'B'};
//SRAM_ProductInfo_UINT8 Gu8_ComIf_uSofwareVersion[10] = {'Y', '2', 'P', 'S', '0', '0','3', '.', '0', '1'};
SRAM_PRODUCTINFO_UINT8 Gu8_ComIf_uOrdernumber[15] = {'X', 'X', 'X', 'X', 'X', 'X','X', 'X', 'X', 'X', 'X','X','X', 'X', 'X'};
//SRAM_ProductInfo_UINT8 Gu8_ComIf_uDataVersion[25] = {'X', 'X', 'X', 'X', 'X', 'X','X', 'X', 'X', 'X', 'X','X','X', 'X', 'X', 'X','X', 'X', 'X', 'X', 'X','X','X', 'X', 'X'};
//SRAM_ProductInfo_UINT8 Gu8_ComIf_uSystemName[7]  = {'E','L','O','P','1','8','7'};
SRAM_RW_PRODUCT_INFODATA_SERNUM_UINT8 Gu8_ComIf_uSerialNumber[12];
SRAM_RW_PRODUCT_INFODATA_HWV_UINT8 Gu8_ComIf_HWVersion[10];
SRAM_RW_PRODUCT_INFODATA_ECUTIME_UINT8 Gu8_ComIf_uECUProductionTime[4];


//const uint8 Cu8_uWFBootVersion[20] __attribute__((section(".ARM.__at_0x1203FF00")))={0};
//const uint8 Cu8_uBootVersion[6] __attribute__((section(".ARM.__at_0x1203FF14")))={0x0}; 
//const uint8 Cu8_uSupplierSWVerInfo[8] __attribute__((section(".ARM.__at_0x1203FF80")))={0x0};


//static uint8_t Su8_uSystemName[7] ={'E','L','O','P','1','X','X'};
//static uint8_t Su8_uAssemblyPartNumber[14] ={0};



//uint8_t Gu8_ComIf_uPumpManufacturingDate[6]  MEM_PRODUCT_INFO_RAM ={0}; 
//uint8_t Gu8_ComIf_uPumpSerialNumber[5]       MEM_PRODUCT_INFO_RAM ={0};
//uint8_t Gu8_ComIf_uSerialNumber[9]           MEM_PRODUCT_INFO_RAM ={0};
//uint8_t Gu8_ComIf_uOrdernumber[15]           MEM_PRODUCT_INFO_RAM ={0};
//uint8_t Gu8_ComIf_uSupplierID[4]             MEM_PRODUCT_INFO_RAM ={0};
//uint8_t Gu8_ComIf_uHardwareID[10]            MEM_PRODUCT_INFO_RAM ={0};
//uint8_t Gu8_ComIf_uSofwareVersion[10]        MEM_PRODUCT_INFO_RAM ={0};
//uint8_t Gu8_ComIf_uFingerPrint[9]            MEM_FP_RAM ={0};




//0xF187   
void ComIf_Set_ReadFunc_01(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_01;j++)
	{
		Data[j] = Gu8_ComIf_uOrdernumber[j];
	}
}

//0xF18C  
void ComIf_Set_ReadFunc_02(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_02;j++)
	{
		Data[j] = Gu8_ComIf_uSerialNumber[j];
	}
}

//0xF193   
void ComIf_Set_ReadFunc_03(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_03;j++)
	{
		Data[j] = busComIf_UDSRead_In.u8_WF_HWVersion[j];
	}
}

//0xF19D  
void ComIf_Set_ReadFunc_04(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_04;j++)
	{
		Data[j] = Gu8_ComIf_uECUProductionTime[j];
	}
}

//0xF180  
void ComIf_Set_ReadFunc_05(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_05;j++)
	{
		Data[j] = Gu8_ComIf_uBootSofwareVersion[j];
	}
}

//0xF182 
void ComIf_Set_ReadFunc_06(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_06;j++)
	{
		Data[j] = busComIf_UDSRead_In.u8_CalibDataVersion[j];
	}
}

//0xF195  
void ComIf_Set_ReadFunc_07(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_07;j++)
	{
		Data[j] = busComIf_UDSRead_In.u8_WF_SWVersion[j];
	}
}

//0xF197   
void ComIf_Set_ReadFunc_08(unsigned char * Data)
{
	for(unsigned short j = 0; j < DATA_BYTE_SIZE_08;j++)
	{
		Data[j] = busComIf_UDSRead_In.u8_SysName[j];
	}
}


//0x0100
//void ComIf_Set_ReadFunc_01(unsigned char *Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_vVehSpd >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_vVehSpd & 0xFF);	
//}

////0x0101
//void ComIf_Set_ReadFunc_02(unsigned char * Data)
//{	
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u32_Ode >> 24)&0xFF);
//	Data[1] = (unsigned char)((busComIf_UDSRead_In.u32_Ode >> 16)&0xFF);
//	Data[2] = (unsigned char)((busComIf_UDSRead_In.u32_Ode >> 8)&0xFF);
//  Data[3] = (unsigned char)(busComIf_UDSRead_In.u32_Ode & 0xFF);
//}



////0x0103  DATA_BYTE_SIZE_03:7
//void ComIf_Set_ReadFunc_03(unsigned char * Data)
//{
//	Data[0] = (unsigned char)(busComIf_UDSRead_In.u32_TiStamLo & 0xFF);	       //hour
//	Data[1] = (unsigned char)((busComIf_UDSRead_In.u32_TiStamLo >> 8)&0xFF);   //minute
//	Data[2] = (unsigned char)((busComIf_UDSRead_In.u32_TiStamLo >> 16)&0xFF);  //second  
//	Data[3] = (unsigned char)((busComIf_UDSRead_In.u32_TiStamLo >> 24)&0xFF);  //year
//	Data[4] = (unsigned char)(busComIf_UDSRead_In.u32_TiStamHi &0xFF);         //month
//  Data[5] = (unsigned char)((busComIf_UDSRead_In.u32_TiStamHi >> 8)&0xFF);   //day
//	Data[6] = (unsigned char)((busComIf_UDSRead_In.u32_TiStamHi >> 16)&0xFF);  //millisecond
//}



////0x04C1  DATA_BYTE_SIZE_04:1
//void ComIf_Set_ReadFunc_04(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_ActOilFlow;	
//}




////0x04C5   DATA_BYTE_SIZE_05:2
//void ComIf_Set_ReadFunc_05(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_flgPhiCalibSuc;
//}



////0x04C7    DATA_BYTE_SIZE_06:1
//void ComIf_Set_ReadFunc_06(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_UpLimOilFlow;
//}

////0x04C8   DATA_BYTE_SIZE_07:2
//void ComIf_Set_ReadFunc_07(unsigned char * Data)
//{
//	Data[0] = 0;
//	Data[1] = 0;
//	if((busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[13]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[29]))
//	{
//		Data[0] |= (1 << 0);
//	}
//	if((busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[9]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[10]))
//	{
//		Data[0] |= (1 << 1);
//	}
//	if((busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[6]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[7]))
//	{
//		Data[0] |= (1 << 2);
//	}
//	if(busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[8])
//	{
//		Data[0] |= (1 << 3);
//	}
//	if((busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[4]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[5]))
//	{
//		Data[0] |= (1 << 4);
//	}
//	if((busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[14]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[15]))
//	{
//		Data[0] |= (1 << 5);
//	}
//	if(busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[24])
//	{
//		Data[0] |= (1 << 7);
//	}
//	if(busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[19])
//	{
//		Data[1] |= (1 << 0);
//	}
//	if((busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[25]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[26]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[27]) || (busComIf_FrzFrm_In.u8_EE_FrzFrmstDTCBit3[28]))
//	{
//		Data[1] |= (1 << 1);
//	}
//}

////0xD000   DATA_BYTE_SIZE_08:1
//void ComIf_Set_ReadFunc_08(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u16_uSplyVltg;
//}



////0xD001    DATA_BYTE_SIZE_09:2
//void ComIf_Set_ReadFunc_09(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_nActMechSpd >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_nActMechSpd & 0xFF);	
//}

////0xD002   DATA_BYTE_SIZE_10:1
//void ComIf_Set_ReadFunc_10(unsigned char * Data)
//{
//	  Data[0] = (unsigned char)busComIf_UDSRead_In.enm_stSysSt;
//}

////0xD003   DATA_BYTE_SIZE_11:1
//void ComIf_Set_ReadFunc_11(unsigned char * Data)
//{	
//  Data[0] = (unsigned char)busComIf_UDSRead_In.u8_tPCBTemp;
//}

////0xD004   DATA_BYTE_SIZE_12:1
//void ComIf_Set_ReadFunc_12(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_ActOilTemp;
//}

////0xD005    DATA_BYTE_SIZE_13:1
//void ComIf_Set_ReadFunc_13(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u16_iEstSplyCurr;
//}


////0xD010   DATA_BYTE_SIZE_14:2
//void ComIf_Set_ReadFunc_14(unsigned char * Data)
//{
//	
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_WakeupSignalTimes >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_WakeupSignalTimes & 0xFF);	
//}


////0xD011    DATA_BYTE_SIZE_15:2
//void ComIf_Set_ReadFunc_15(unsigned char * Data)
//{    
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_SleepSignalTimes >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_SleepSignalTimes & 0xFF);	
//}



////0xD012   DATA_BYTE_SIZE_16:2
//void ComIf_Set_ReadFunc_16(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_LimphomeSpeedSignal >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_LimphomeSpeedSignal & 0xFF);	
//}


////0xD100   DATA_BYTE_SIZE_17:1
//void ComIf_Set_ReadFunc_17(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_stMaxFaltLvl;
//}


////0xD102    DATA_BYTE_SIZE_18:2
//void ComIf_Set_ReadFunc_18(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_iRefQaxCurr >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_iRefQaxCurr & 0xFF);
//}

////0xD103    DATA_BYTE_SIZE_19:2
//void ComIf_Set_ReadFunc_19(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_nRmpRefMechSpd >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_nRmpRefMechSpd & 0xFF);
//}

////0xD104     DATA_BYTE_SIZE_20:2
//void ComIf_Set_ReadFunc_20(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_uCtlBrdVltg >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_uCtlBrdVltg & 0xFF);
//}


////0xD105   DATA_BYTE_SIZE_21:1
//void ComIf_Set_ReadFunc_21(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_stMotoSt;
//}

////0xD106     DATA_BYTE_SIZE_22:1
//void ComIf_Set_ReadFunc_22(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_flgShOffFlg;
//}

////0xD107      DATA_BYTE_SIZE_23:1
//void ComIf_Set_ReadFunc_23(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_tMotoTemp;
//}

////0xD108     DATA_BYTE_SIZE_24:1
//void ComIf_Set_ReadFunc_24(unsigned char * Data)
//{
//	Data[0] = (unsigned char)busComIf_UDSRead_In.u8_tPwrTubTemp;
//}



////0xD110     DATA_BYTE_SIZE_25:2
//void ComIf_Set_ReadFunc_25(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_iActQaxCurr >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_iActQaxCurr & 0xFF);
//}

////0xD118      DATA_BYTE_SIZE_26:25
//void ComIf_Set_ReadFunc_26(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_26;j++)
//	{
//     Data[j] = (unsigned char)busComIf_UDSRead_In.u8_CalibDataVersion[j];
//	}
//}


////0xD119      DATA_BYTE_SIZE_27:6
//void ComIf_Set_ReadFunc_27(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_27;j++)
//	{
//     Data[j] = (unsigned char)busComIf_UDSRead_In.u8_Custom_SWVersion[j];
//	}
//}

////0xD201     DATA_BYTE_SIZE_29:1
//void ComIf_Set_ReadFunc_29(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_iActPhUCurr >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_iActPhUCurr & 0xFF);
//}

////0xD202     DATA_BYTE_SIZE_30:1
//void ComIf_Set_ReadFunc_30(unsigned char * Data)
//{
//	Data[0] = (unsigned char)((busComIf_UDSRead_In.u16_iActPhVCurr >> 8)&0xFF);
//	Data[1] = (unsigned char)(busComIf_UDSRead_In.u16_iActPhVCurr & 0xFF);
//}


////0xE15C        DATA_BYTE_SIZE_31:6
//void ComIf_Set_ReadFunc_31(unsigned char * Data)
//{    
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_31;j++)
//	{
//     Data[j] = Gu8_ComIf_uPumpManufacturingDate[j];	
//	}
//}



////0xE15D       DATA_BYTE_SIZE_32:5
//void ComIf_Set_ReadFunc_32(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_32;j++)
//	{
//		Data[j] = Gu8_ComIf_uPumpSerialNumber[j];	
//	}
//}

////0xE15E       DATA_BYTE_SIZE_33:7
//void ComIf_Set_ReadFunc_33(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_33;j++)
//	{
//     Data[j] = Su8_uSystemName[j];	
//	}
//}

////0xE15F    DATA_BYTE_SIZE_34:6
//void ComIf_Set_ReadFunc_34(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_34;j++)
//	{
//		Data[j] = Cu8_uBootVersion[j];	
//	}
//}


////0xF100     DATA_BYTE_SIZE_35:14
//void ComIf_Set_ReadFunc_35(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_35;j++)
//	{
//		Data[j] = Su8_uAssemblyPartNumber[j];
//	}
//}

////0xF101   DATA_BYTE_SIZE_36:9
//void ComIf_Set_ReadFunc_36(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_36;j++)
//	{
//		Data[j] = Gu8_ComIf_uSerialNumber[j];
//	}
//}

////0xF15A    DATA_BYTE_SIZE_37:9
//void ComIf_Set_ReadFunc_37(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_37;j++)
//	{
//		Data[j] = Gu8_ComIf_uFingerPrint[j];
//	}
//}

////0xF180    DATA_BYTE_SIZE_38:20
//void ComIf_Set_ReadFunc_38(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_38;j++)
//	{
//		Data[j] = Cu8_uWFBootVersion[j];
//	}
//}

////0xF187     DATA_BYTE_SIZE_39:15
//void ComIf_Set_ReadFunc_39(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_39;j++)
//	{
//		Data[j] = Gu8_ComIf_uOrdernumber[j];
//	}
//}


////0xF18A     DATA_BYTE_SIZE_40:4
//void ComIf_Set_ReadFunc_40(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_40;j++)
//	{
//		Data[j] = Gu8_ComIf_uSupplierID[j];
//	}
//}



////0xF192     DATA_BYTE_SIZE_41:10
//void ComIf_Set_ReadFunc_41(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_41;j++)
//	{
//		Data[j] = Gu8_ComIf_uHardwareID[j];
//	}
//}



////0xF193     DATA_BYTE_SIZE_42:6
//void ComIf_Set_ReadFunc_42(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_42;j++)
//	{
//		Data[j] = (unsigned char)busComIf_UDSRead_In.u8_WF_HWVersion[j];
//	}
//}


////0xF194     DATA_BYTE_SIZE_43:10
//void ComIf_Set_ReadFunc_43(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_43;j++)
//	{
//		Data[j] = Gu8_ComIf_uSofwareVersion[j];
//	}
//}


////0xF195     DATA_BYTE_SIZE_44:20
//void ComIf_Set_ReadFunc_44(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_44;j++)
//	{
//		Data[j] = (unsigned char)busComIf_UDSRead_In.u8_WF_SWVersion[j];
//	}
//}

////0xFE00     DATA_BYTE_SIZE_45:8
//void ComIf_Set_ReadFunc_45(unsigned char * Data)
//{
//	for(unsigned short j = 0; j < DATA_BYTE_SIZE_45;j++)
//	{
//		Data[j] = Cu8_uSupplierSWVerInfo[j];
//	}
//}