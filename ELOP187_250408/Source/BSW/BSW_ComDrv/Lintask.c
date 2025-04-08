#include "linmain.h"
//#include "genLinConfig.h"
//#include "lin_driver_api.h"

//#include "Lintask.h"
#include "LinTp.h"
#include "uds.h"
//#include "MID_Interface.h"


//SRAM_GLOBAL_UINT16 LIN_rpmRecTargetSpeed_mp;/* y=x; read ELOP target speed;0~65534 is valid; 65536 is invalid*/
//SRAM_GLOBAL_UINT8  LIN_stRecTargetState_mp; /* read ELOP target status;1:normal mode;2:sleep mode*/
//SRAM_GLOBAL_UINT8  LIN_OpcStartOn_mp;

//SRAM_GLOBAL_UINT16  EOP_MosTemperature;
//SRAM_GLOBAL_UINT8  EOP_BatteryVoltage;
//SRAM_GLOBAL_UINT16  EOP_ActualSpeed;
//SRAM_GLOBAL_UINT8  EOP_MosTOutRngSts;
//SRAM_GLOBAL_UINT8  EOP_SensorPowSupplyFau;
//SRAM_GLOBAL_UINT8  EOP_SpdBaseAngleValueSts;
//SRAM_GLOBAL_UINT8  EOP_SpdBaseUVWIncPosSts;
//SRAM_GLOBAL_UINT8  EOP_PhaseOverCurrent;
//SRAM_GLOBAL_UINT8  EOP_IgnitionStatus;
//SRAM_GLOBAL_UINT8  EOP_PumpNotReady;
//SRAM_GLOBAL_UINT8  EOP_ASAValueInValid;
//SRAM_GLOBAL_UINT8  EOP_StartFailure;
//SRAM_GLOBAL_UINT8  EOP_FaultSelfMos;
//SRAM_GLOBAL_UINT8  EOP_GDUOverCurrent;
//SRAM_GLOBAL_UINT8  EOP_CanNodeLoss;
//SRAM_GLOBAL_UINT8  EOP_OffseVoltageFailure;
//SRAM_GLOBAL_UINT8  EOP_OverTemperature;
//SRAM_GLOBAL_UINT8  EOP_AngleSignalError;
//SRAM_GLOBAL_UINT8  EOP_OverVoltage;
//SRAM_GLOBAL_UINT8  EOP_UnderVoltage;
//SRAM_GLOBAL_UINT8  EOP_UnderSpeed;
//SRAM_GLOBAL_UINT16  EOP_BusCurrent;
//SRAM_GLOBAL_UINT8  EOP_MssgCounterInvalid;
//SRAM_GLOBAL_UINT8  EOP_MssgCheckSumInvalid;
//SRAM_GLOBAL_UINT8  EOP_RunningStatus;
//SRAM_GLOBAL_UINT8  EOP_OffCmdRecFb;
//SRAM_GLOBAL_UINT8  EOP_GmrSpiCommErr;
//SRAM_GLOBAL_UINT16  ETP_PhaseCurrent;
//SRAM_GLOBAL_UINT8   EOP_MosTFaultSts;
//SRAM_GLOBAL_UINT8   EOP_McuTOutRngSts;

////#include "SleepMode_interface.h"

//static uint8  LinAppl_LinRqsStatus = 1;
//static uint8 LinAppl_Rx_AlvCnt;
//static uint8 CountCrcWrong =0;
//static uint8 PhaseLinComCtrl =1;
//static uint8 LIN_RollingCounter_mp[16];
//static uint8 rc_i=0;
//static uint8 Flag_RollingCounter_add =0;
//static uint8 Flag_RollingCounter_Fault =0;
//static uint8 Flag_LinCrcWrong = 0;

//#define MAX_COUNT_NOT_RECEIVED_MSG (2000)  //750
//#define MAX_WRONG_CRC_RC  (5)


//uint16 CountMessageNotReceived =0;
//uint16 Count_LinSleep = 0;
//uint8 Flag_Count_LinSleep = 0;
//uint8 Flag_LinMessageNotReceived = 0;

//uint8 test7=0x10;
//uint8 test8=0x20;
//uint8  Status =0;
//uint16  refspeed =0;
//uint8 Flag_LinSlave_GotoSleepMid=0;


//static const  uint8 CRC8TAB0x1D[256] =\
//{
//    0x00,0x1D,0x3A,0x27,0x74,0x69,0x4E,0x53,0xE8,0xF5,0xD2,0xCF,0x9C,0x81,0xA6,0xBB
//    ,0xCD,0xD0,0xF7,0xEA,0xB9,0xA4,0x83,0x9E,0x25,0x38,0x1F,0x02,0x51,0x4C,0x6B,0x76
//    ,0x87,0x9A,0xBD,0xA0,0xF3,0xEE,0xC9,0xD4,0x6F,0x72,0x55,0x48,0x1B,0x06,0x21,0x3C
//    ,0x4A,0x57,0x70,0x6D,0x3E,0x23,0x04,0x19,0xA2,0xBF,0x98,0x85,0xD6,0xCB,0xEC,0xF1
//    ,0x13,0x0E,0x29,0x34,0x67,0x7A,0x5D,0x40,0xFB,0xE6,0xC1,0xDC,0x8F,0x92,0xB5,0xA8
//    ,0xDE,0xC3,0xE4,0xF9,0xAA,0xB7,0x90,0x8D,0x36,0x2B,0x0C,0x11,0x42,0x5F,0x78,0x65
//    ,0x94,0x89,0xAE,0xB3,0xE0,0xFD,0xDA,0xC7,0x7C,0x61,0x46,0x5B,0x08,0x15,0x32,0x2F
//    ,0x59,0x44,0x63,0x7E,0x2D,0x30,0x17,0x0A,0xB1,0xAC,0x8B,0x96,0xC5,0xD8,0xFF,0xE2
//    ,0x26,0x3B,0x1C,0x01,0x52,0x4F,0x68,0x75,0xCE,0xD3,0xF4,0xE9,0xBA,0xA7,0x80,0x9D
//    ,0xEB,0xF6,0xD1,0xCC,0x9F,0x82,0xA5,0xB8,0x03,0x1E,0x39,0x24,0x77,0x6A,0x4D,0x50
//    ,0xA1,0xBC,0x9B,0x86,0xD5,0xC8,0xEF,0xF2,0x49,0x54,0x73,0x6E,0x3D,0x20,0x07,0x1A
//    ,0x6C,0x71,0x56,0x4B,0x18,0x05,0x22,0x3F,0x84,0x99,0xBE,0xA3,0xF0,0xED,0xCA,0xD7
//    ,0x35,0x28,0x0F,0x12,0x41,0x5C,0x7B,0x66,0xDD,0xC0,0xE7,0xFA,0xA9,0xB4,0x93,0x8E
//    ,0xF8,0xE5,0xC2,0xDF,0x8C,0x91,0xB6,0xAB,0x10,0x0D,0x2A,0x37,0x64,0x79,0x5E,0x43
//    ,0xB2,0xAF,0x88,0x95,0xC6,0xDB,0xFC,0xE1,0x5A,0x47,0x60,0x7D,0x2E,0x33,0x14,0x09
//    ,0x7F,0x62,0x45,0x58,0x0B,0x16,0x31,0x2C,0x97,0x8A,0xAD,0xB0,0xE3,0xFE,0xD9,0xC4
//};

///**************************************************************************************************
// @brief         Calc_CRC8
// @details       Returns the calculated CRC8 J1850

// @param[in]     DataBuffer, Number of Bytes, InitCrc, EndXOR

// @return        CRC8

// ****************************************************************************************************/
//uint8   CRC8_TAB_0x1D (uint8 Buf[], uint8 bDtLen, uint8 InitCrc, uint8 FlgEnd_XOR )
//{
//    uint8 crc;
//    uint8 Idx;
//    uint8 data;

//    crc = InitCrc;

//    for(Idx = 0; Idx < bDtLen ; Idx++)
//    {
//        data = (uint8)(Buf[Idx] ^ crc);
//        crc = (uint8)(CRC8TAB0x1D[data]);
//    }

//    if(FlgEnd_XOR)
//    {
//        crc ^= 0xFF;
//    }


//    return(crc);
//}






void ProtStk_UDS_1msTask(void)
{
		LinTp_task_1ms();
		uds_task();
}

void ComDrv_1msTask(void)
{
		LIN_LLD_Service();
}

void ComDrv_500usTask(void)
{
		l_cyclic_com_task();
}

void LinAppl_Run(void)
{

//	#define CRC_BUF_LEN     8
//	#define _WRITE_ID_0  0x3D
//	#define _WRITE_ID_1  0x00
//	#define _READ_ID_0   0x3D
//	#define _READ_ID_1   0x00
//	
//	uint16 tmp_u16;
//  uint16_t uint8_temp0;
//	
//	uint8_t EOP_McuTemperature_tmp;
//	uint8_t unit8_temp0;
//	uint8_t unit8_temp1;
//	uint8 LinRqsStatus;
//	uint8 ReceivedFrmCrc, FrmCrc;

//  uint8 FrmCrcBuf[CRC_BUF_LEN];
//	
//	uint16 LIN_errOBDCode_mp =0;
//	uint8 LIN_ct9140Fualt_mp = 0;
//	uint8 LIN_MotCtlgetFault_mp = 0;
//	uint16 LIN_MotCtrl_get_ReferenceSpeed = 0;
//	uint16 LIN_MotCtrl_get_ReferenceQaxCurr_s16 = 0;
//	uint16 LIN_MotCtrl_get_ActualQaxCurr_s16 = 0;
//	uint16 LIN_Phasecurrent_mp = 0X1234;
/////////////////////////ELOP167 BYD_LIN_V11.ldf/////////////////////////////////////////////////////////	
//	if(CountMessageNotReceived < MAX_COUNT_NOT_RECEIVED_MSG )
//	{
//      CountMessageNotReceived++;
//	}
//	else
//	{
//		   Flag_LinMessageNotReceived = 1;  //communication timeout flag
//		   //Flag_Count_LinSleep = 1;
//		   
//		 
	}
//	 	///////////////xiumian huanxing////////////////////////////////////////////////////////
//	/* if(Flag_Count_LinSleep == 1)//4250+750=5000ms
//	 {
//		  Count_LinSleep ++;
//		  if(Count_LinSleep > 4250)
//		  {
//				  Flag_Count_LinSleep = 0;
//		      Count_LinSleep = 0;
//					LinSlave_GotoSleep();
//		 
//		  }
//	 
//	 
//	 }*/
//		/////////////////////////////////////////////////////////////////////////
//	
//    if (l_flg_tst_RefSpeed())/*judge whether receive new data*/
//    {
//			
//			 l_flg_clr_RefSpeed();
//			// Flag_LinSlave_GotoSleep =0;
//			 CountMessageNotReceived = 0;
//			 Flag_LinMessageNotReceived = 0;
//			 Count_LinSleep =0;
//			 Flag_Count_LinSleep =0;
//			
//		
//			/*****************************CRC*****************************************************************/					
//       ReceivedFrmCrc = l_u8_rd_Crc();
//			
//			 if ( LinAppl_Rx_AlvCnt < 15 )
//						LinAppl_Rx_AlvCnt++;
//			 else
//						LinAppl_Rx_AlvCnt = 0;
//			 
//			// LIN_RollingCounter_mp[rc_i]   = (l_u8_rd_RollingCounter());
//			 FrmCrc =  l_u8_rd_CrcCalculation();
//			

//			 
//	   if(ReceivedFrmCrc == FrmCrc)
//		 {
//				 
//			   CountCrcWrong =0;
//				 Flag_LinCrcWrong =0;
//			 
//			  if (l_u16_rd_RefSpeed()==0)
//				{
//				   LIN_rpmRecTargetSpeed_mp = ( l_u16_rd_RefSpeed());
//				}
//				else if (l_u16_rd_RefSpeed()<250)
//				{
//					 LIN_rpmRecTargetSpeed_mp = 268;
//				}
//				else
//				{
//					 LIN_rpmRecTargetSpeed_mp = ( l_u16_rd_RefSpeed()*1.07);
//				}
//				LIN_OpcStartOn_mp  = (l_u8_rd_OpcStartOn()) ;
//				
//			/******************************RollingCounter***************************************************/		
//				  LIN_RollingCounter_mp[rc_i]   = (l_u8_rd_RollingCounter());

//				if((LIN_RollingCounter_mp[rc_i] >=0)&&(LIN_RollingCounter_mp[rc_i] <=15))
//				{
//								 if(rc_i >0)
//								 {
//												if((LIN_RollingCounter_mp[rc_i-1]+1) != (LIN_RollingCounter_mp[rc_i]))
//												{

//																 Flag_RollingCounter_add ++ ; 

//																 if(Flag_RollingCounter_add > MAX_WRONG_CRC_RC)
//																 {
//																						Flag_RollingCounter_Fault =1; // RC FAULT

//																 }

//												}
//												else
//												{
//													 Flag_RollingCounter_add =0;
//																 Flag_RollingCounter_Fault =0;

//												}
//								}

//				}

//				rc_i++;
//				if(rc_i >16)rc_i = 0;

//		
//	/**************************************************************************************************/	
//							
//								
//		}
//	  else
//    {
//			if(CountCrcWrong < MAX_WRONG_CRC_RC)
//	       {
//					   CountCrcWrong ++;
//					
//	       }
//				 else
//				 {
//						Flag_LinCrcWrong =1;
//				 }
//			
//			
//    }
// /**************************************************************************************************/				

//       

//	/*
//	
//	
//			 LIN_rpmActualSpeed_mp= 1111; 
//			 LIN_tOilTemp_mp =22;
//			 LIN_pOilPressure_mp =33;
//			 LIN_stELOPRunStatus_mp =44;
//			 LIN_iELOPWorkCurrent_mp=5555;
//			 LIN_iELOPWorkCurrent_mp=6666;
//			 LIN_MotorBlock_mp =77;
//			 LIN_errOBDCode_mp =1234;
//			 LIN_ct9140Fualt_mp =56;
//			 LIN_MotCtlgetFault_mp =12;
//			
//	*/
//	
//	
//	
////	    EOP_McuTemperature = MotCtl_get_TempECU_u8();
////			EOP_McuTemperature=EOP_McuTemperature+10;
////			l_u8_wr_McuTemp(EOP_McuTemperature) ;
////			
////			EOP_MosTemperature = ADC2_Temp_Result_C();
////			EOP_MosTemperature = (uint8_t)EOP_MosTemperature + 50;
////		  l_u8_wr_MosTemp(EOP_MosTemperature);
//			
//			
////	    EOP_McuTemperature = ADC2_Temp_Result_C();
////			if(EOP_McuTemperature<(-40))
////			{
////				EOP_McuTemperature=  -40;
////			}
////			EOP_McuTemperature=(uint8_t)EOP_McuTemperature+40;


//      EOP_McuTemperature_tmp= 0;   //EOP_McuTemperature+10;
//			l_u8_wr_McuTemp(EOP_McuTemperature_tmp);
//			
////			EOP_MosTemperature = MotCtl_get_TempECU_u8();
//			EOP_MosTemperature = (uint8_t)EOP_MosTemperature + 10;
//		  l_u8_wr_MosTemp(EOP_MosTemperature);			
//			
//			
//			
////			EOP_BatteryVoltage = MotCtl_get_SplyVltg_u16()/200;
//			l_u8_wr_BatteryVoltage(EOP_BatteryVoltage);
//			
//			
//			//EOP_ActualSpeed =  MotCtrl_get_actualSpeed()/1.07;
//			//l_u16_wr_ActSpeed(EOP_ActualSpeed);
//			
////			  EOP_ActualSpeed =  MotCtrl_get_actualSpeed()/1.07;
////          if (EOP_ActualSpeed < 50)
////						{
////             l_u16_wr_ActSpeed(0);
////               }
//					if	(EOP_ActualSpeed >= 50 && EOP_ActualSpeed < 250)
//            {
//             l_u16_wr_ActSpeed(200 + ((EOP_ActualSpeed -100)/3));
//               }
//               else
//                 {
//                   l_u16_wr_ActSpeed(EOP_ActualSpeed);
//                    }
//				
//			
//			EOP_MosTFaultSts = 0;//(MotCtl_get_NTCOpnCirFlag_b())||(MotCtl_get_NTCShortCirFlag_b());
//			l_u8_wr_Mostempsensorfault(EOP_MosTFaultSts);//NTC开路以及短路合并
//			
//			EOP_MosTOutRngSts = 0;
//			l_u8_wr_Mostempsensorrangefault(EOP_MosTOutRngSts);
//			
//			EOP_SensorPowSupplyFau = 0;
//			l_u8_wr_Mcutempsensorvoltagedetection(EOP_SensorPowSupplyFau);
//			
//			EOP_SpdBaseAngleValueSts =0;
//			l_u8_wr_SpdBaseAngleValueSts(EOP_SpdBaseAngleValueSts);
//			
//			EOP_SpdBaseUVWIncPosSts =0;
//			l_u8_wr_SpdBaseUVWIncPosSts(EOP_SpdBaseUVWIncPosSts);
//			
//			EOP_McuTOutRngSts = 0;
//			l_u8_wr_McuTOutRngSts(EOP_McuTOutRngSts);
//			
//			EOP_IgnitionStatus =0;
//			l_u8_wr_IgnitionStatus(EOP_IgnitionStatus);
//			
//			l_u8_wr_RollingCounter_32(LinAppl_Rx_AlvCnt);
//			l_u8_wr_CheckSum_32(l_u8_CheckSum32_Value);
//			
// /**************************************************************************************************/		
//		
//	   /* LIN_rpmActualSpeed_mp= MotCtrl_get_actualSpeed() ; 
//		
//			 
//			l_u16_wr_ActSpeed(LIN_rpmActualSpeed_mp);  
//			 
//		  l_u8_wr_READ_AC(LinAppl_Rx_AlvCnt); 
//			
//			LIN_tOilTemp_mp=MotCtl_get_TempECU_u8();
//			LIN_tOilTemp_mp=LIN_tOilTemp_mp+10;
//			
//		
//			l_u8_wr_ActoilTemp(LIN_tOilTemp_mp);     

//     	LIN_pOilPressure_mp =0;
//			l_u8_wr_Actoilpressure(LIN_pOilPressure_mp);        
//			
//      
//			LIN_stELOPRunStatus_mp =MotCtl_get_actualStaus();
//			l_u8_wr_Actoilstatus(LIN_stELOPRunStatus_mp); 
//			
//      l_u8_wr_RESERVED(0x0F); 
//			l_u8_wr_Ntctemp(LIN_tOilTemp_mp); 
//			  
//			FrmCrcBuf[0] = _READ_ID_0;
//			FrmCrcBuf[1] = _READ_ID_1;
//			FrmCrcBuf[2] = _s_READ_ACTUAL_SPEED_0;
//			FrmCrcBuf[3] = _s_READ_ACTUAL_SPEED_1;
//			FrmCrcBuf[4] = _s_READ_OIL_TEMPERATURE;
//			FrmCrcBuf[5] = _s_READ_OIL_PRESSURE;
//			FrmCrcBuf[6] = ((uint8)(_s_READ_STATUS )) | ((((uint8) (_s_RESERVED))  << 4));
//			FrmCrcBuf[7] = _s_RESERVED3;
//			
//			FrmCrc = CRC8_TAB_0x1D( FrmCrcBuf, CRC_BUF_LEN, 0x00, FALSE );
//			
//			l_u8_wr_READ_SPEED_CRC( FrmCrc );

//			
//			
//			LIN_iELOPWorkCurrent_mp= MotCtrl_get_supplyCurr_s16();
//			LIN_iELOPWorkCurrent_mp = LIN_iELOPWorkCurrent_mp * 1000/128;
//			
//			
//			l_u16_wr_Readcurrent(LIN_iELOPWorkCurrent_mp);
//			
//			LIN_uELOPOperateVol_mp=ADC2_uVSDVol_mp;
//			l_u16_wr_Readvoltage(LIN_uELOPOperateVol_mp);
//			
//			LIN_uELOPFault_mp =0xff;
//			if((Flag_LinMessageNotReceived ==1)||(CountCrcWrong >= MAX_WRONG_CRC))
//				 PhaseLinComCtrl =0;
//			if((CountMessageNotReceived < MAX_COUNT_NOT_RECEIVED_MSG)&&(CountCrcWrong == 0 ))
//				 PhaseLinComCtrl =1;
//			
//			
//		
//			unit8_temp0 = PhaseLinComCtrl;   //lin故障
//			LIN_uELOPFault_mp &=  (unit8_temp0 <<2) | 0xFB;
//			
//			unit8_temp0 = MotCtrl_get_DeratingActive_b();   //过载
//			unit8_temp0 = !unit8_temp0;
//			LIN_uELOPFault_mp &=  (unit8_temp0 <<4) | 0xEF;
//			
//			unit8_temp0 = MotCtl_get_OverVoltFlag_b();   //过压
//			unit8_temp0 = !unit8_temp0;
//			LIN_uELOPFault_mp &=  (unit8_temp0 <<5) | 0xDF;			
//			
//			unit8_temp0 = MotCtl_get_UnderVoltFlag_b();   //欠压
//			unit8_temp0 = !unit8_temp0;
//			LIN_uELOPFault_mp &=  (unit8_temp0 <<6) | 0xBF;		

//			unit8_temp0 = MotCtl_get_OverTempFlag_b();   //过温
//			unit8_temp0 = !unit8_temp0;
//			LIN_uELOPFault_mp &=  (unit8_temp0 <<7) | 0x7F;				
//			
//		  
//			l_u8_wr_ElopFault(LIN_uELOPFault_mp);
//			
//			l_u8_wr_INFO_QS(0x0);
//			
//			LIN_iELOPPhaseCurrent_mp = MotCtrl_get_lineCurr_s16();
//			LIN_iELOPPhaseCurrent_mp = LIN_iELOPPhaseCurrent_mp * 1000/128;
//			l_u16_wr_Phasecurrent(LIN_iELOPPhaseCurrent_mp);
//			
//			
//			LIN_MotorBlock_mp = MotCtl_get_MotorBlockedPerm_b();
//			LIN_MotorBlock_mp = !LIN_MotorBlock_mp;
//			l_u8_wr_MotorBlock(LIN_MotorBlock_mp);
//			l_u8_wr_RESERVED2(0xFF);*/
//			
////			EOP_PhaseOverCurrent = MotCtl_get_OverLineCurrentFlag_b();
//			 l_u8_wr_PhaseOverCurrentFault(EOP_PhaseOverCurrent); 
//			 
//			 EOP_PumpNotReady = 0;
//			 l_u8_wr_PumpSystemFailed(EOP_PumpNotReady) ;
//			 
////			 EOP_ASAValueInValid = MotCtrl_get_calibDone();
//			 l_u8_wr_ZeropositionLearnt(EOP_ASAValueInValid) ;
//			 
////			 EOP_StartFailure = MotCtl_get_MotorBlockedPerm_b();
//			 l_u8_wr_MotorStallFault(EOP_StartFailure) ;
//			 
//			 EOP_FaultSelfMos = 0;
//			 l_u8_wr_MosSelfcheckFailure(EOP_FaultSelfMos);
//			 
////			 EOP_GDUOverCurrent = MotCtl_get_GDUOvrCurrFlag_b();
//			// if (ERR_ctHSLSOverCurrent_mp == 2 && MotCtl_get_GDUOvrCurrFlag_b())
//		//	 {
//		//		 l_u8_wr_GduOverCurrent(EOP_GDUOverCurrent);
//		//	 }
//		//	 else
//			 {
//			l_u8_wr_GduOverCurrent(0);
//			 }
//			
////			EOP_CanNodeLoss = MotCtl_get_LINLosFlag_b();
////			l_u8_wr_CanNodeLoss(EOP_CanNodeLoss) ;
//			
//			EOP_OffseVoltageFailure = 0;
//			 l_u8_wr_BaseVoltagecheckFailure(EOP_OffseVoltageFailure);
//			 
////			 EOP_OverTemperature = MotCtl_get_OverTempFlag_b();
////			l_u8_wr_MosOvertemp(EOP_OverTemperature);
//			
////			EOP_AngleSignalError = MotCtl_get_AngleFaultFlag_b();
////			l_u8_wr_AngleSensorFault(EOP_AngleSignalError);
//			
////			if ((MotCtl_get_OverVoltFlag_b() ==1) && (MotCtl_get_OverGDVoltFlag_b() ==1))
////			{
////			EOP_OverVoltage = 3;
////			}
////			else if((MotCtl_get_OverVoltFlag_b() ==1) && (MotCtl_get_OverGDVoltFlag_b() !=1))
////			{
////			EOP_OverVoltage = 2;
////			}	
////			else if((MotCtl_get_OverVoltFlag_b() !=1) && (MotCtl_get_OverGDVoltFlag_b() ==1))
////			{
////			EOP_OverVoltage = 1;
////			}	
////			else
////			{
////			EOP_OverVoltage = 0;
////			}
//			
//			l_u8_wr_GduandBatteryOverVoltage(EOP_OverVoltage);
//			

////			if ((MotCtl_get_UnderVoltFlag_b() ==1) && (MotCtl_get_UnderGDVoltFlag_b() ==1))
////			{
////			EOP_UnderVoltage = 3;
////			}
////			else if((MotCtl_get_UnderVoltFlag_b() ==1) && (MotCtl_get_UnderGDVoltFlag_b() !=1))
////			{
////			EOP_UnderVoltage = 2;
////			}	
////			else if((MotCtl_get_UnderVoltFlag_b() !=1) && (MotCtl_get_UnderGDVoltFlag_b() ==1))
////			{
////			EOP_UnderVoltage = 1;
////			}	
////			else
////			{
////			EOP_UnderVoltage = 0;
////			}
////			l_u8_wr_UnderGduandBatteryVoltage(EOP_UnderVoltage);
//			 
////			 if(MotCtrl_get_DeratingActive_b() ==1)
////			 {
////			 EOP_UnderSpeed =2;
////			 }
////			 else
////			 {
////			 EOP_UnderSpeed = 0;
////			 }
////			l_u8_wr_UnderSpeedModeStatus(0);
//			 
////			 EOP_BusCurrent = (MotCtrl_get_supplyCurr_s16()*10)/128;
//			 //EOP_BusCurrent = EOP_BusCurrent /128;
//			l_u16_wr_Buscurrent(EOP_BusCurrent);
//			 
//			EOP_MssgCounterInvalid = Flag_RollingCounter_Fault;  //RC FAULT
//			l_u8_wr_RollingCounterFault(EOP_MssgCounterInvalid);
//			 
//			EOP_MssgCheckSumInvalid = Flag_LinCrcWrong;       //CRC FAULT
//			l_u8_wr_ChecksumFault(EOP_MssgCheckSumInvalid) ;
//			 
////			 if (MotCtl_get_actualStaus() == 3)
////			 {
////			 EOP_RunningStatus = 0;
////			 } 
////			 else if (MotCtl_get_actualStaus() == 0)
////			 {
////			 EOP_RunningStatus = 3;
////			 }
////			 else if (MotCtl_get_actualStaus() == 4)
////			 {
////			 EOP_RunningStatus = 7;
////			 }
////			 else
////			 {
////			 EOP_RunningStatus = 5;
////			 }
////			 l_u8_wr_RunningStatus(EOP_RunningStatus) ;
////			 
//////			 EOP_OffCmdRecFb = Flag_LinSlave_GotoSleep;
//////			 l_u8_wr_EOP_OffCmdRecFb(EOP_OffCmdRecFb) ;  //add 20241016
////			 	if (LIN_OpcStartOn_mp ==0 && !MotCtl_get_LINLosFlag_b())
////	{		
////		EOP_OffCmdRecFb = 1;
////		Flag_LinSlave_GotoSleepMid = 0;    //Flag_LinSlave_GotoSleep;//ved ;//GetTgtSpdMsgSt();
////	}
////		else
////	{
////		EOP_OffCmdRecFb =0;
////		
////	}
//	 l_u8_wr_EOP_OffCmdRecFb(EOP_OffCmdRecFb) ;  //add 20241016	
//			 EOP_GmrSpiCommErr = 0;
//			l_u8_wr_SPICommunicationError(EOP_GmrSpiCommErr);
//			 
////			 ETP_PhaseCurrent = (MotCtrl_get_lineCurr_s16()*10)/128;
//			 //ETP_PhaseCurrent = ETP_PhaseCurrent /128;
//			 l_u16_wr_Phasecurrent(ETP_PhaseCurrent) ;


//			l_u8_wr_RollingCounter_31(LinAppl_Rx_AlvCnt);
//			l_u8_wr_CheckSum_31(l_u8_CheckSum31_Value);
// /**************************************************************************************************/				 
/////////////////////add test //////////////////////////////////////////////////////////////////////////////
//			
//			
//			
////			l_u16_wr_0x1DerrOBDCode(arElctAngErrTemp_mp);//(LIN_errOBDCode_mp); 
//			
//			
////			LIN_ct9140Fualt_mp=BSW_ct9140ERR_mp;
////			l_u8_wr_0x1Dct9140Fualt(LIN_ct9140Fualt_mp); 
//			
//			
//			
//			
//			unit8_temp1=0;
//			unit8_temp0=MotCtl_get_OverVoltFlag_b();
//      unit8_temp1=unit8_temp0&0x01;
//			
//			unit8_temp0=MotCtl_get_UnderVoltFlag_b();
//      unit8_temp1=((unit8_temp0&0x01)<<1)|unit8_temp1;
//			
//			unit8_temp0=MotCtl_get_OverTempFlag_b();
//      unit8_temp1=((unit8_temp0&0x01)<<2)|unit8_temp1;

//			unit8_temp0=MotCtl_get_OverLineCurrentFlag_b();
//      unit8_temp1=((unit8_temp0&0x01)<<3)|unit8_temp1;
//			
//			unit8_temp0=MotCtrl_get_DeratingActive_b();
//      unit8_temp1=((unit8_temp0&0x01)<<4)|unit8_temp1;

//			unit8_temp0=MotCtl_get_MotorBlockedPerm_b();
//      unit8_temp1=((unit8_temp0&0x01)<<5)|unit8_temp1;

//			unit8_temp0=MotCtl_get_UnderCtlBrdVoltFlag_b();
//      unit8_temp1=((unit8_temp0&0x01)<<6)|unit8_temp1;
//			
//			
//			LIN_MotCtlgetFault_mp=unit8_temp1;
//			l_u8_wr_0x1DMotCtlgetFault(LIN_MotCtlgetFault_mp); //APP fault monitor
//			l_u16_wr_0x1Dreserved1(MotCtrl_get_actualSensorSpeed());//(Err_stBSWFault_mp);//BSW software fault monitor
//			//l_u8_wr_0x1Dreserved2(0xFF);
//			//l_u8_wr_0x1Dreserved3(0xFF);
//			
//			l_u16_wr_0x1Dreserved2(u16_psiEstPermMagFlx_mp);//(0xFFFF);




//			
//		  //LIN_MotCtrl_get_ReferenceSpeed  =1111;
//			
//			LIN_MotCtrl_get_ReferenceSpeed=MotCtrl_get_ReferenceSpeed();
//			l_u16_wr_0x1BMotCtrlgetReferenceSpeed(LIN_MotCtrl_get_ReferenceSpeed);
//			
//			//LIN_MotCtrl_get_ReferenceQaxCurr_s16 =2222;
//			LIN_MotCtrl_get_ReferenceQaxCurr_s16=MotCtrl_get_ReferenceQaxCurr_s16();
//			l_u16_wr_0x1BMotCtrlgetReferenceQaxCurrs16(LIN_MotCtrl_get_ReferenceQaxCurr_s16);
//			
//		  //LIN_MotCtrl_get_ActualQaxCurr_s16=3333;
//			LIN_MotCtrl_get_ActualQaxCurr_s16=MotCtrl_get_ActualQaxCurr_s16();
//			l_u16_wr_0x1BMotCtrlgetActualQaxCurrs16(LIN_MotCtrl_get_ActualQaxCurr_s16);
//			
//			
//			
//			LIN_Phasecurrent_mp= MotCtrl_get_supplyCurr_s16();
//			LIN_Phasecurrent_mp = LIN_Phasecurrent_mp * 1000/128;
//			l_u16_wr_0x1BPhasecurrent(LIN_Phasecurrent_mp);
//			
//	///////////////////add test //////////////////////////////////////////////////////////////////////////////		
//			
//		}

//	
//}


//sint16 CanApp_get_RefSpeed(void)
//{
//  return (sint16)(LIN_rpmRecTargetSpeed_mp);
//}

//uint8 CanApp_get_RefSysStaFlag(void)
//{

//  return LIN_stRecTargetState_mp;

//}



