/* To avoid multi-inclusions */
#ifndef ISOUDS_RDDABYID_HAL_H
#define ISOUDS_RDDABYID_HAL_H
//#include <stdint.h>
//#include "Rte_Type.h"
#include "Std_Types.h"
#include "Mem_Mem.h"





#define    DATA_DID_01                0xF187     //R
#define    DATA_DID_02                0xF18C     //RW
#define    DATA_DID_03                0xF193     //RW
#define    DATA_DID_04                0xF19D     //RW
#define    DATA_DID_05                0xF180     //R
#define    DATA_DID_06                0xF182     //R
#define    DATA_DID_07                0xF195     //R
#define    DATA_DID_08                0xF197     //R

#define DATA_BYTE_SIZE_01  15
#define DATA_BYTE_SIZE_02  12
#define DATA_BYTE_SIZE_03  10
#define DATA_BYTE_SIZE_04  4
#define DATA_BYTE_SIZE_05  10
#define DATA_BYTE_SIZE_06  25
#define DATA_BYTE_SIZE_07  10
#define DATA_BYTE_SIZE_08  7






//typedef struct
//{
//	uint16_t u16_uSplyVltg;                    //����ĸ�ߵ�ѹ
//	uint8_t u8_stMaxFaltLvl;                   //���ϵȼ�
//	uint16_t u16_iRefQaxCurr;                  //Q��Ŀ�����
//	uint16_t u16_iActQaxCurr;                  // Q��ʵ�ʵ���
//	uint16_t u16_iEstSplyCurr;                 //����ĸ�ߵ���ֵ
//	uint16_t u16_nRmpRefMechSpd;               //Ŀ�����ٶ�
//	uint16_t u16_nActMechSpd;                  //ʵ�ʵ���ٶ�
//	uint16_t u16_uCtlBrdVltg;                  //��ѹ��ѹ
//	uint8_t u8_stMotoSt;                       //���״̬
//	uint8_t u8_flgShOffFlg;                    //�ع�״̬
//	uint8_t u8_tPCBTemp;                       //PCB�¶�
//	uint8_t u8_tMotoTemp;                      //����¶�
//	uint8_t u8_tPwrTubTemp;                    //���ʹ��¶�
//	uint16_t u16_iActPhUCurr;                  //U�����
//	uint16_t u16_iActPhVCurr;                  //V�����
//	uint16_t u16_vVehSpd;                      //����
//	uint32_t u32_Ode;                          //���
//	uint32_t u32_TiStamLo;                     //hour:Byte0(bit0~bit4); minute: Byte1(bit0~bit5); second: Byte2(bit0~bit5); year: Byte3(bit0~bit6);
//	uint32_t u32_TiStamHi;                     //month: Byte0(bit0~bit3); day��Byte1(bit0~bit6); millisecond��Byte2(bit0~bit9);
//	uint8_t u8_ActOilFlow;					           //�ͱ������ȴ����
//	uint8_t u8_ActOilTemp;                     //�ͱý���MCU����
//	uint8_t u8_flgPhiCalibSuc;                 //�ͱõ���Ա궨״̬
//	uint8_t u8_UpLimOilFlow;                   //�ͱõ�ǰ��ȴ������ֵ
//	uint8_t u8_WF_SWVersion[20];                   //WF�����汾��
//	uint8_t u8_CalibDataVersion[25];               //���ݰ汾��
//	uint8_t u8_Custom_SWVersion[6];               //�ͻ������汾��
//	uint16_t u16_WakeupSignalTimes;            //�ϵ绽��ʱ��
//	uint16_t u16_SleepSignalTimes;             //�µ�����ʱ��
//	uint16_t u16_LimphomeSpeedSignal;          // ����ת��
//	uint8_t enm_stSysSt;                       //ϵͳ״̬
//	
//	//uint8_t u8_PumpManufacturing_Date[6];                //������ʱ��
//	//uint8_t u8_Pump_Serial_Number[5];                    //�����к�
//	//uint8_t u8_System_Name[7];                           //ϵͳ����
//	//uint8_t u8_Supplier_Boot_Version[6];                 //��Ӧ��BootLoader�汾��
//	//uint8_t u8_Assembly_Part_Number[14];                 //˽��ECU����ż�
//	//uint8_t u8_Serial_Number[9];                         //˽��ECU������кż�
//	//uint8_t u8_Finger_Print[9];                          //ָ��
//	//uint8_t u8_Boot_Version[20];                         //BootLoader�汾��
//	//uint8_t u8_Order_number[15];                         //�������
//	//uint8_t u8_Supplier_ID[4];                           //��Ӧ��ʶ����
//	//uint8_t u8_Hardware_ID[6];                           //Ӳ��ID
//	uint8_t u8_WF_HWVersion[6];                          //WFӲ���汾��
//	//uint8_t u8_Sofware_Version[10];                      //����ID
//	//uint8_t u8_Supplier_SWVer_Info[8];                   //��Ӧ�������汾��Ϣ
//	
//}BUS_COMIF_UDSREAD_IN;

typedef struct
{

   uint8_t u8_WF_HWVersion[10];                             //WFӲ���汾��
	 uint8_t u8_CalibDataVersion[25];                        //DATAVersion
	 uint8_t u8_WF_SWVersion[10];                        //SoftwareVersion
	 uint8_t u8_SysName[7];                         //SystemName

}BUS_COMIF_UDSREAD_IN;


extern BUS_COMIF_UDSREAD_IN busComIf_UDSRead_In;

extern SRAM_RW_PRODUCT_INFODATA_SERNUM_UINT8 Gu8_ComIf_uSerialNumber[12];
extern SRAM_RW_PRODUCT_INFODATA_HWV_UINT8 Gu8_ComIf_HWVersion[10];
extern SRAM_RW_PRODUCT_INFODATA_ECUTIME_UINT8 Gu8_ComIf_uECUProductionTime[4];
extern SRAM_PRODUCTINFO_UINT8 Gu8_ComIf_uBootSofwareVersion[10];
extern SRAM_PRODUCTINFO_UINT8 Gu8_ComIf_uSofwareVersion[10];
extern SRAM_PRODUCTINFO_UINT8 Gu8_ComIf_uOrdernumber[15];

extern SRAM_PRODUCTINFO_UINT8 Gu8_ComIf_uDataVersion[25];
extern SRAM_PRODUCTINFO_UINT8 Gu8_ComIf_uSystemName[7];

////extern uint8_t Gu8_ComIf_uWakeupSignalTimes[2]; 
////extern uint8_t Gu8_ComIf_uSleepSignalTimes[2]; 
////extern uint8_t Gu8_ComIf_uLimphomeSpeedSignal[2]; 
//extern uint8_t Gu8_ComIf_uPumpManufacturingDate[6]; 
//extern uint8_t Gu8_ComIf_uPumpSerialNumber[5];
//extern uint8_t Gu8_ComIf_uSerialNumber[9];
//extern uint8_t Gu8_ComIf_uOrdernumber[15];
//extern uint8_t Gu8_ComIf_uSupplierID[4];
//extern uint8_t Gu8_ComIf_uHardwareID[10];
//extern uint8_t Gu8_ComIf_uSofwareVersion[10];
//extern uint8_t Gu8_ComIf_uFingerPrint[9];







extern void ComIf_Set_ReadFunc_01(unsigned char * Data);
extern void ComIf_Set_ReadFunc_02(unsigned char * Data);
extern void ComIf_Set_ReadFunc_03(unsigned char * Data);
extern void ComIf_Set_ReadFunc_04(unsigned char * Data);
extern void ComIf_Set_ReadFunc_05(unsigned char * Data);
extern void ComIf_Set_ReadFunc_06(unsigned char * Data);
extern void ComIf_Set_ReadFunc_07(unsigned char * Data);
extern void ComIf_Set_ReadFunc_08(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_09(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_10(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_11(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_12(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_13(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_14(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_15(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_16(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_17(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_18(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_19(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_20(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_21(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_22(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_23(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_24(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_25(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_26(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_27(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_29(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_30(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_31(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_32(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_33(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_34(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_35(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_36(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_37(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_38(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_39(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_40(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_41(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_42(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_43(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_44(unsigned char * Data);
//extern void ComIf_Set_ReadFunc_45(unsigned char * Data);


#endif  /* ISOUDS_RDDABYID_HAL_H */
