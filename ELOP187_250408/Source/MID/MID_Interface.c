/***************************************************************************//**
 * \file       MID_Interface.c
 * \brief      Motor Control wrapper
 * \author     ECD SW Team - YuanXiaoqiang
 * \date       21/11/2024
 *
 * \par        Copyright (c) 2024, WEIFU Group Technology All rights reserved
 * 
 * \defgroup   MID_Interface    MID_Interface - Motor Control Wrapper
 * @{
 ******************************************************************************/

// Includes
#include "MID_Interface.h"
#include "ASW_AST_private.h"
#include "ASW_DcycGen_private.h"
#include "ASW_OBD_private.h"
#include "ASW_PhCurrGen_private.h"
#include "ASW_PhVltgGen_private.h"
#include "ASW_SigIn_private.h"
#include "motor_control_interface.h"
#include "custom_type_definition.h"

#include "Lintask.h"
#include "lin_slave_task.h"
#include "Mem_Mem.h"
#include "PosSCD_PosSensor.h"
#include "PWM_PWM.h"
#include "PWM_Clac.h"
#include "ADC_Meas.h"
#include "DIAG_Handle.h"
#include "Sys_Int.h"
#include "Sys_McuInit.h"
#include "ComIf_application_message.h"
#include "ComIf_RdDaByID_HAL.h"
#include "ComIf_WrDaByID_HAL.h"
#include "Sys_SCU.h"

/***************************************************************************//**
 * \defgroup    MotCtrl_wrap_Defines     MotCtrl_wrap Defines/Macros
 * @{
 ******************************************************************************/
#define Cdbl_nMechSpdPeakVal 32768u
#define Cdbl_nElecAgSpdPeakVal 4096u
#define Cdbl_uSplyVltgPeakVal 64u
#define Cdbl_iPhCurrPeakVal 256u
#define PI 3.14159265
#define Cdbl_uCtlBrdVltgPeakVal 64u
#define Cdbl_iSplyCurrPeakVal 256u

/** @} MotCtrl_wrap_Defines */ 
/***************************************************************************//**
 * \defgroup    MotCtrl_wrap_LocalVariables    MotCtrl_wrap_ Local variables
 * @{
 ******************************************************************************/

////////////////////////////////////////////////////////////////////////////////

sint16 MotState_Nref_s16;
uint16_t u16_AgADOffset = 0;
static bool bol_flgCalibFin = false;
static uint8 u8_FrzFrmSaveFlg = 0;
static uint8 MCUF_OperationModel;
static sint16 s16_ComIf_nComRefMechSpd;
static uint8_t u8_ComIf_APPTxMsgData1[8];
static uint8_t u8_ComIf_APPTxMsgData2[8];
bool bol_ComIf_flgComLosFaltRaw;
static uint8_t MCUF_RollingCounter_27A;
static bool bol_ComIf_flgCRCFaltRaw;
static bool bol_ComIf_flgMesgLngthFaltRaw;
static bool bol_ComIf_flgCrashFalt;
static uint8 u8_ComIf_psiUpLimOilFlow = 0;
static uint8 u8_ComIf_TransFluidTemp = 0;
static uint8 u8_ComIf_psiOilFlow = 0;
static uint32 u32_ComIf_tiStamLo = 0;
static uint32 u32_ComIf_tiStamHi = 0;
static uint32 u32_ComIf_disOde = 0;
static uint16 u16_ComIf_vVehSpd = 0;
static sint16 s16_MID_Interface_ActSpd_CAN = 0;
SRAM_CHARACT_UINT16 offset_buff[2] = {0u};
SRAM_PRODUCTINFO_UINT8 u8_Interface_HWVersion[10] = {'Y','2','E','O','P','H','H','W','1','0'};
static uint8 u8_Interface_SysName[7] = {'E','L','O','P','1','8','7'};
static uint8 u8_Interface_SWVersion[10] = {'Y','2','P','S','0','0','3','.','0','9'};
static uint8 u8_Interface_DataVersion[25] = {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'};	
uint8 Temp_OperationModel = 0;
sint16 s16_Temp_nComRefMechSpd = 0;
uint16 Tmp_ADMosTemp = 4000;
bool Temp_FaultFlg = false;
static uint16 u16_Interface_AplHWVer = 0x01;
static uint16 u16_Interface_AplSWVer = 0x02;
static uint8 u8_Interface_SplyID = 0x02;
uint8 Gu8_flgShOffflg = 0;


////////////////////////////////////////////////////////////////////////////////

/** @} MotCtrl_wrap_LocalVariables */

/* CRC algorithm */
uint8 Interface_crc_high_first(uint8 *ptr,uint8 len)
{
//  uint8 i;
  uint8 crc=0x00;/*����ĳ�ʼcrcֵ*/

  while(len--)
  {
    crc ^= *ptr++;/*ÿ��������Ҫ�����������򣬼�����ָ����һ������*/
//    for(i=8;i>0;--i)/*����������8λ����Ҫ����8��*/
//    {
//      if(crc & 0x80)/*�ж����λ�Ƿ�Ϊ1*/
//      {
//        crc=(crc << 1)^(0x2F);/*���λΪ1��������һλ��Ȼ����0x2F���*/
//      }
//      else
//      {
//        crc=(crc << 1);/*���λΪ0������Ҫ�����������������һλ*/
//      }
//    }
  }
  crc ^=0x00;/*CRC��0x00�������*/
  return(crc);
}

/***************************************************************************//**
 * \defgroup    MotCtrl_wrap_LocalFunctions     MotCtrl_wrap Local functions
 * @{
 ******************************************************************************/
 

/** @} MotCtrl_wrap_LocalFunctions */

/***************************************************************************//**
 * \defgroup    MotCtrl_wrap_GlobalFunctions     MotCtrl_wrap Global functions 
 * @{
 ******************************************************************************/
/**
 * \fn       Interface_StartupTask
 * \brief    Initialize the ASW variables and judge enter sleep mode
 */
void Interface_StartupTask(void)
{ 
	ASW_DcycGen_Init();
	ASW_PhVltgGen_Init();
	ASW_PhCurrGen_Init();
	ASW_AST_Init();
	ASW_SigIn_Init();
	ASW_OBD_Init();
}


/**
 * \fn       Interface_FR_Task
 * \brief    Fast rate runnable (16kHz)
 */
void Interface_FR_Task(void)
{
    /* TO USE WHEN GENERATED CODE WILL HAVE A STRUCT AS INPUT
    // Update the input structure
    motCtrl_read_FR_inputs(&FR_InputStruct);

    // Call the runnable
    rss_FastRateTask_16kHz_step(&FR_InputStruct, &FR_outputStruct);
    */
	  Interface_DcycGen_FstTask_Trans();

	  DcycGen_FstTask();
}

/**
 * \fn       Interface_500usTask
 * \brief    Medium rate runnable (2kHz)
 */

void Interface_500usTask(void)
{
	Gu8_PWM_MedFreqTaskStatus=1;
	/* SigIn_MedTask */
//	Sys_IntDisIrq();
	Interface_SigIn_MedTask_Trans();
//	Sys_IntEnIrq();	
		SigIn_MedTask();
	
	/* PhVltgGen_MedTask */
//	Sys_IntDisIrq();
	Interface_PhVltgGen_MedTask_Trans();
// 	Sys_IntEnIrq();	
	
		PhVltgGen_MedTask();
	Gu8_flgShOffflg = (uint8)busAST_SlwTaskOut.bol_flgShOffFlg;
  Gu8_PWM_MedFreqTaskStatus=0;
	

//busOBD_SlwTaskIn.bol_flgComLosFaltRaw = Gu8_ComIf_APPRxMesCnt;
//	MCUF_RollingCounter_27A = (Gu8_ComIf_APPRxMsgData[6] & (0xF0))>>4;
//	busOBD_SlwTaskIn.u8_ctComRolCnt = MCUF_RollingCounter_27A;
	//Interface_ApplCom_ASW_Trans();
}
 
/**
 * \fn       Interface_1msTask
 * \brief    Slow rate runnable (100Hz)
 */
void Interface_1msTask(void)
{ 
	busOBD_SlwTaskIn.u8_ctLossNoData = Gu8_ComIf_APPRxMesCnt;
	MCUF_RollingCounter_27A = (Gu8_ComIf_APPRxMsgData[6] & (0xF0))>>4;
	busOBD_SlwTaskIn.u8_ctComRolCnt = MCUF_RollingCounter_27A;
}

/**
 * \fn       Interface_10msTask
 * \brief    Slow rate runnable (100Hz)
 */
void Interface_10msTask(void)
{              
		/* PhCurrGen_SlwTask */
	Interface_PhCurrGen_SlwTask_Trans();

  PhCurrGen_SlwTask();
   
	/* AST_SlwTask */
	Interface_AST_SlwTask_Trans();
	
	AST_SlwTask();
	
	/* OBD_SlwTask */
	Interface_OBD_SlwTask_Trans();
	
	OBD_SlwTask();
	
	/* SigIn_SlwTask */
	Interface_SigIn_SlwTask_Trans();
	
	SigIn_SlwTask();
	
	/* Communication */
	Interface_ApplCom_ASW_Trans();
	
	Interface_FrzUDSCom_ASW_Trans();
	
	/* Calibration */
		if (bol_flgCalibFin == false)
  {
      Interface_AgCalib_Trans();
  }
	
	/* Memeory */
	  Interface_Mem_Trans();
	
	/* SLEEP */
	Interface_SleepReq();
}

void Interface_DcycGen_FstTask_Trans(void)
{
		busDcycGen_FstTaskIn.u16_ampDycAmp = busPhVltgGen_MedTaskOut.u16_ampDycAmp;
    busDcycGen_FstTaskIn.u16_phiActElecAg = busPhVltgGen_MedTaskOut.u16_phiActElecAg;
    busDcycGen_FstTaskIn.u16_phiDaxQaxVltgAg = busPhVltgGen_MedTaskOut.u16_phiDaxQaxVltgAg;
    busDcycGen_FstTaskIn.enm_stMotoSt = busPhCurrGen_SlwTaskOut.enm_stMotoSt;
    busDcycGen_FstTaskIn.s16_nPredActElecSpd = busPhVltgGen_MedTaskOut.s16_nPredActElecSpd;
    busDcycGen_FstTaskIn.bol_enPosSCDCalibEnFlg = !bol_flgCalibFin;
}

void Interface_SigIn_MedTask_Trans(void)
{
 //  Sys_IntDisIrq();
	static uint16 u16_SchM_AgMech;
	PosSCD_Data_Read();
//    if( bol_flgCalibFin == false)
//	{
		u16_SchM_AgMech =(0xFFFF - (uint16_t)((0x7FFF & Gu16_PSCD_AngleData_IF)<<1));
//	}
//	else
//	{
//	  u16_SchM_AgMech = (0xFFFF - (uint16_t)(
//                  ((uint32_t)((0x7FFF & Gu16_PSCD_AngleData_IF)<<1) + (uint32_t)u16_AgADOffset)
//                              & 0x0000FFFF) );
//	}
//   Sys_IntEnIrq();
  	
//  	Sys_IntDisIrq();
    PWM_SSM_ReconstructCurr();
	  busSigIn_MedTaskIn.u16_ADSensActMechAg = u16_SchM_AgMech;
	  busSigIn_MedTaskIn.u16_phiDvtSensElecAg = u16_AgADOffset;
	  busSigIn_MedTaskIn.bol_enPosSCDCalibEnFlg = !bol_flgCalibFin;
    busSigIn_MedTaskIn.u16_uADActPhCurr[0] = Gu16_uPWM_PhFstCurr_IF;
    busSigIn_MedTaskIn.u16_uADActPhCurr[1] = Gu16_uPWM_PhScndCurr_IF;
    busSigIn_MedTaskIn.u16_uADActPhCurr[2] = 0;
    busSigIn_MedTaskIn.u16_uADActPhCurrOfs = Gu16_uPWM_CsaCalibResult_IF;
    busSigIn_MedTaskIn.u8_numSectNum = Gu8_PWMSector_IF;
	ADC_VSD_VDH_Routine();
		busSigIn_MedTaskIn.u16_uADSplyVltg = Gu16_uADCVDH_IF;
//	   Sys_IntEnIrq();
}

void Interface_PhVltgGen_MedTask_Trans(void)
{
//    Sys_IntDisIrq();

		busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[0] = busPhCurrGen_SlwTaskOut.s16_iRefDaxQaxCurr[0];
    busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[1] = busPhCurrGen_SlwTaskOut.s16_iRefDaxQaxCurr[1];
    busPhVltgGen_MedTaskIn.s16_iActPhCurr[0] = busSigIn_MedTaskOut.s16_iActPhCurr[0];
    busPhVltgGen_MedTaskIn.s16_iActPhCurr[1] = busSigIn_MedTaskOut.s16_iActPhCurr[1];
    busPhVltgGen_MedTaskIn.s16_iActPhCurr[2] = busSigIn_MedTaskOut.s16_iActPhCurr[2];
    busPhVltgGen_MedTaskIn.u16_phiSensActElecAg = busSigIn_MedTaskOut.u16_phiSensActElecAg;
    busPhVltgGen_MedTaskIn.u16_uSplyVltg = busSigIn_MedTaskOut.u16_uSplyVltg;
    busPhVltgGen_MedTaskIn.enm_stMotoSt = busPhCurrGen_SlwTaskOut.enm_stMotoSt;
    busPhVltgGen_MedTaskIn.u16_phiModulActElecAg = busDcycGen_FstTaskOut.u16_phiModulActElecAg;
    busPhVltgGen_MedTaskIn.u16_phiPosSCDCalibElecAg = busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg;
    busPhVltgGen_MedTaskIn.u16_dcycPhDyc[0] = busDcycGen_FstTaskOut.u16_dcycPhDyc[0];
    busPhVltgGen_MedTaskIn.u16_dcycPhDyc[1] = busDcycGen_FstTaskOut.u16_dcycPhDyc[1];
    busPhVltgGen_MedTaskIn.u16_dcycPhDyc[2] = busDcycGen_FstTaskOut.u16_dcycPhDyc[2];
    busPhVltgGen_MedTaskIn.bol_enPosSCDCalibEnFlg = !bol_flgCalibFin;
    busPhVltgGen_MedTaskIn.enm_modeAgEvalMode = busAST_SlwTaskOut.enm_modeAgEvalMode;
    busPhVltgGen_MedTaskIn.s16_nRmpRefElecSpd = busAST_SlwTaskOut.s16_nRmpRefElecSpd;
	  busPhVltgGen_MedTaskIn.u8_tPCBTempSubs = busSigIn_SlwTaskOut.u8_tPCBTempSubs;
	  busPhVltgGen_MedTaskIn.u16_ampMaxNrmVltgAmp = busDcycGen_FstTaskOut.u16_ampMaxNrmVltgAmp;
//    busPhVltgGen_MedTaskIn.s16_uRefDaxVltgLim = busAST_SlwTaskOut.s16_uRefDaxVltgLim;
//    busPhVltgGen_MedTaskIn.u16_ampMaxVltgAmp = busAST_SlwTaskOut.u16_ampMaxVltgAmp;
//    busPhVltgGen_MedTaskIn.s16_uRefQaxVltgLim = busAST_SlwTaskOut.s16_uRefQaxVltgLim;
//		Sys_IntEnIrq();
}

void Interface_PhCurrGen_SlwTask_Trans(void)
{
  busPhCurrGen_SlwTaskIn.s16_nRefElecSpd = busAST_SlwTaskOut.s16_nRefElecSpd;
  busPhCurrGen_SlwTaskIn.s16_nActElecSpd = busPhVltgGen_MedTaskOut.s16_nActElecSpd;
  busPhCurrGen_SlwTaskIn.s16_nRmpRefElecSpd = busAST_SlwTaskOut.s16_nRmpRefElecSpd;
  busPhCurrGen_SlwTaskIn.s16_trqRefTqLim = busAST_SlwTaskOut.s16_trqRefTqLim;
  busPhCurrGen_SlwTaskIn.bol_flgShOffFlg = busAST_SlwTaskOut.bol_flgShOffFlg;
  busPhCurrGen_SlwTaskIn.bol_enPosSCDCalibEnFlg = !bol_flgCalibFin;
  busPhCurrGen_SlwTaskIn.s16_trqPosSCDCalibRefTq = busAST_SlwTaskOut.s16_trqPosSCDCalibRefTq;
  busPhCurrGen_SlwTaskIn.enm_modeAgEvalMode = busAST_SlwTaskOut.enm_modeAgEvalMode;
	busPhCurrGen_SlwTaskIn.s16_phiOpnLpAgClsLpAgDvt = busPhVltgGen_MedTaskOut.s16_phiOpnLpAgClsLpAgDvt;
}

void Interface_AST_SlwTask_Trans(void)
{
  busAST_SlwTaskIn.s16_nComRefMechSpd = s16_ComIf_nComRefMechSpd;
  busAST_SlwTaskIn.s16_nActElecSpd = busPhVltgGen_MedTaskOut.s16_nActElecSpd;
  busAST_SlwTaskIn.s16_uModulDaxQaxVltg[0] = busPhVltgGen_MedTaskOut.s16_uModulDaxQaxVltg[0];
	busAST_SlwTaskIn.s16_uModulDaxQaxVltg[1] = busPhVltgGen_MedTaskOut.s16_uModulDaxQaxVltg[1];
  busAST_SlwTaskIn.u16_uSplyVltg = busSigIn_MedTaskOut.u16_uSplyVltg;
  busAST_SlwTaskIn.s16_iActDaxQaxCurr[0] = busPhVltgGen_MedTaskOut.s16_iActDaxQaxCurr[0];
  busAST_SlwTaskIn.s16_iActDaxQaxCurr[1] = busPhVltgGen_MedTaskOut.s16_iActDaxQaxCurr[1];
  busAST_SlwTaskIn.enm_stMotoSt = busPhCurrGen_SlwTaskOut.enm_stMotoSt;
  busAST_SlwTaskIn.bol_enPosSCDCalibEnFlg = !bol_flgCalibFin;
  busAST_SlwTaskIn.u16_phiSensActElecAg = busSigIn_MedTaskOut.u16_phiSensActElecAg;
  busAST_SlwTaskIn.u8_stMaxFaltLvl = busOBD_SlwTaskOut.u8_stMaxFaltLvl;
  busAST_SlwTaskIn.busOBD_FaltSt = busOBD_SlwTaskOut.busOBD_FaltSt;
  busAST_SlwTaskIn.s16_nFaltRefMechSpd = busOBD_SlwTaskOut.s16_nFaltRefMechSpd;
  busAST_SlwTaskIn.s16_trqFaltRefTqLim = busOBD_SlwTaskOut.s16_trqFaltRefTqLim;
  busAST_SlwTaskIn.u8_modeMCUOpMode = MCUF_OperationModel;
  busAST_SlwTaskIn.u8_tPCBTempSubs = busSigIn_SlwTaskOut.u8_tPCBTempSubs;
//  busAST_SlwTaskIn.u16_ampMaxNrmVltgAmp = busDcycGen_FstTaskOut.u16_ampMaxNrmVltgAmp;
//  busAST_SlwTaskIn.s16_uRefDaxVltg = busPhVltgGen_MedTaskOut.s16_uRefDaxVltg;
  busAST_SlwTaskIn.bol_flgPhiSensFaltRawFlg = busOBD_SlwTaskOut.bol_flgPhiSensFaltRawFlg;
//	busAST_SlwTaskIn.u8_FrzFrmSaveFlg = u8_FrzFrmSaveFlg;
	busAST_SlwTaskIn.bol_flgSlepEn = Gu8_ComIf_SleepReqFlag;
}

void Interface_OBD_SlwTask_Trans(void)
{
busOBD_SlwTaskIn.s16_nRmpRefElecSpd = busAST_SlwTaskOut.s16_nRmpRefElecSpd;
busOBD_SlwTaskIn.s16_nActElecSpd = busAST_SlwTaskOut.s16_nActElecSpdComFlt;//busPhVltgGen_MedTaskOut.s16_nActElecSpd;
busOBD_SlwTaskIn.enm_stMotoSt = busPhCurrGen_SlwTaskOut.enm_stMotoSt;
busOBD_SlwTaskIn.s16_ampActPhCurrAmp = busAST_SlwTaskOut.s16_ampActPhCurrAmp;
busOBD_SlwTaskIn.u16_uSplyVltg = busSigIn_MedTaskOut.u16_uSplyVltg;
busOBD_SlwTaskIn.u8_tPwrTubTemp = busSigIn_SlwTaskOut.u8_tPwrTubTemp;
busOBD_SlwTaskIn.u8_tPCBTemp = busSigIn_SlwTaskOut.u8_tPCBTemp;
busOBD_SlwTaskIn.u8_tPCBTempSubs = busSigIn_SlwTaskOut.u8_tPCBTempSubs;
busOBD_SlwTaskIn.u8_tMotoTemp = busSigIn_SlwTaskOut.u8_tMotoTemp;
//busOBD_SlwTaskIn.bol_flgComLosFaltRaw = Gu8_ComIf_APPRxMesCnt;//bol_ComIf_flgComLosFaltRaw;   1ms-task
//busOBD_SlwTaskIn.u8_ctComRolCnt = MCUF_RollingCounter_27A;1ms-task
busOBD_SlwTaskIn.u16_uCtlBrdVltg = busSigIn_SlwTaskOut.u16_uCtlBrdVltg;
busOBD_SlwTaskIn.enm_stSysSt = busAST_SlwTaskOut.enm_stSysSt;
busOBD_SlwTaskIn.bol_flgHWOvrCurrFalt = (Gu16_BSWToAPPFault_IF&0x10)>>4;
busOBD_SlwTaskIn.bol_flgChipFalt = ((Gu16_BSWToAPPFault_IF&0x01)>>0)||((Gu16_BSWToAPPFault_IF&0x02)>>1);
busOBD_SlwTaskIn.bol_flgPhiSensFalt = (Gu16_BSWToAPPFault_IF&0x20)>>5;
busOBD_SlwTaskIn.bol_flgGDVltgHiLvl1 = (Gu16_BSWToAPPFault_IF&0x04)>>2;
busOBD_SlwTaskIn.bol_flgGDVltgLoLvl1 = (Gu16_BSWToAPPFault_IF&0x08)>>3;
busOBD_SlwTaskIn.u16_uADActPhCurr[0] = Gu16_uPWM_PhFstCurr_IF;
busOBD_SlwTaskIn.u16_uADActPhCurr[1] = Gu16_uPWM_PhScndCurr_IF;
busOBD_SlwTaskIn.u16_uADPCBTemp = Gu16_uADC_NTCTemp_IF;
busOBD_SlwTaskIn.u8_tMCUTemp = Gu8_tMcuTemp_IF;
busOBD_SlwTaskIn.s16_pwrSplyElecPwr = busAST_SlwTaskOut.s16_pwrSplyElecPwr;
busOBD_SlwTaskIn.s16_iActPhCurr[0] = busSigIn_MedTaskOut.s16_iActPhCurr[0];
busOBD_SlwTaskIn.s16_iActPhCurr[1] = busSigIn_MedTaskOut.s16_iActPhCurr[1];
busOBD_SlwTaskIn.s16_iActPhCurr[2] = busSigIn_MedTaskOut.s16_iActPhCurr[2];
busOBD_SlwTaskIn.s16_iEstSplyCurr = busAST_SlwTaskOut.s16_iEstSplyCurr;
busOBD_SlwTaskIn.s16_iRefDaxQaxCurr[0] = busPhCurrGen_SlwTaskOut.s16_iRefDaxQaxCurr[0];
busOBD_SlwTaskIn.s16_iRefDaxQaxCurr[1] = busPhCurrGen_SlwTaskOut.s16_iRefDaxQaxCurr[1];
busOBD_SlwTaskIn.s16_iActDaxQaxCurr[0] = busPhVltgGen_MedTaskOut.s16_iActDaxQaxCurr[0];
busOBD_SlwTaskIn.s16_iActDaxQaxCurr[1] = busPhVltgGen_MedTaskOut.s16_iActDaxQaxCurr[1];
busOBD_SlwTaskIn.bol_flgShOffFlg = busAST_SlwTaskOut.bol_flgShOffFlg;
busOBD_SlwTaskIn.bol_enPosSCDCalibEnFlg = !bol_flgCalibFin;
busOBD_SlwTaskIn.bol_flgCRCFaltRaw = bol_ComIf_flgCRCFaltRaw;
busOBD_SlwTaskIn.bol_flgCrashFalt = bol_ComIf_flgCrashFalt;
busOBD_SlwTaskIn.s16_nComRefMechSpd = s16_ComIf_nComRefMechSpd;
busOBD_SlwTaskIn.u16_psiEstPermMagFlx = busPhVltgGen_MedTaskOut.u16_psiEstPermMagFlx;
busOBD_SlwTaskIn.enm_modeAgEvalMode = busAST_SlwTaskOut.enm_modeAgEvalMode;
busOBD_SlwTaskIn.bol_flgFaltEnFlgUDS85 = true;
busOBD_SlwTaskIn.u16_uADPwrTubTemp = 1500U;
busOBD_SlwTaskIn.bol_flgMosOpnCirFalt = (Gu16_BSWToAPPFault_IF&0x40)>>6;//Temp_FaultFlg;//false;
//busOBD_SlwTaskIn.bol_ComIf_flgComLosFaltRaw = Gu8_ComIf_APPRxMesCnt;//bol_ComIf_flgComLosFaltRaw;  no use
}

void Interface_SigIn_SlwTask_Trans(void)
{
//busSigIn_SlwTaskIn.u16_uADSplyVltg = Gu16_uADCVDH_IF;
busSigIn_SlwTaskIn.u8_tMCUTemp = Gu8_tMcuTemp_IF;
busSigIn_SlwTaskIn.u16_uADPCBTemp = Gu16_uADC_NTCTemp_IF;
busSigIn_SlwTaskIn.busOBD_FaltSt =  busOBD_SlwTaskOut.busOBD_FaltSt;
busSigIn_SlwTaskIn.u16_uADPwrTubTemp = 1500U;
}

sint16 Gs16_Interface_ActSpd = 0;
sint16 Gs16_ComIf_ActSpdBOOTChk = 0;
void Interface_ApplCom_ASW_Trans(void)
{
	static uint16 MCUF_PumpMotorSpeedReq;
  static uint8 MCUF_CRCCheck_27A;
  static uint8 ComIf_APPRxMesCntOld = 0;
  static sint16 ComIf_BusCurrent;
  static uint8 ComIf_RunningStatus;
  static uint8 ComIf_OffCmdRecFb;
  static sint16 ComIf_PhaseCurrent;
  sint16 ComIf_ActualSpeed = 0;
  static uint8 ComIf_AlvCnt1;
  static uint8 ComIf_AlvCnt2;
	static uint8 u8_ComIf_APPRxMesCntOld = 0;	
	static bool bol_flgHWOvrCurrComEn = false;
	static uint8 u8_ComLosCnt = 0;
	
		/* Gu8_ComIf_APPRxMesCnt */
//	if(Gu8_ComIf_APPRxMesCnt == u8_ComIf_APPRxMesCntOld)
//	{
//		busOBD_SlwTaskIn.bol_ComIf_flgComLosFaltRaw=0;
//		if (u8_ComLosCnt < 200)
//		{
//		u8_ComLosCnt++;
//		}
//		else
//		{
//	  bol_ComIf_flgComLosFaltRaw = true;
//		}
//	}
//	else
//	{
//		busOBD_SlwTaskIn.bol_ComIf_flgComLosFaltRaw=1;
//		u8_ComLosCnt = 0;
//		bol_ComIf_flgComLosFaltRaw = false;
//	}
//	 u8_ComIf_APPRxMesCntOld = Gu8_ComIf_APPRxMesCnt;	
	 MCUF_CRCCheck_27A = Gu8_ComIf_APPRxMsgData[7] & (0xFF);
	if(MCUF_CRCCheck_27A == Interface_crc_high_first(&Gu8_ComIf_APPRxMsgData[0],7))
	{
	bol_ComIf_flgCRCFaltRaw = false;
	}
	else
	{
	bol_ComIf_flgCRCFaltRaw = true;
	}
if(bol_ComIf_flgCRCFaltRaw == false)
	{
/* Receive Application message */
	MCUF_OperationModel = (Gu8_ComIf_APPRxMsgData[2] & (0x40))>>6;
  bol_ComIf_flgCrashFalt = (Gu8_ComIf_APPRxMsgData[2] & (0x20))>>5;
  MCUF_PumpMotorSpeedReq = (Gu8_ComIf_APPRxMsgData[1] & 0xFF) |((Gu8_ComIf_APPRxMsgData[2] & 0x1F)<<8);
  s16_ComIf_nComRefMechSpd = (sint16)((sint32)(MCUF_PumpMotorSpeedReq<<15)/Cdbl_nMechSpdPeakVal);
	
	/* Special Demand from Customers of GEELY*/
	if((s16_ComIf_nComRefMechSpd != 0) && (s16_ComIf_nComRefMechSpd < 250))
	{
	s16_ComIf_nComRefMechSpd = 268;
	}
	else
	{
	s16_ComIf_nComRefMechSpd = (sint16)((sint32)(s16_ComIf_nComRefMechSpd * 107)/100);
	}

	/* end */
	
//MCUF_RollingCounter_27A = (Gu8_ComIf_APPRxMsgData[6] & (0xF0))>>4;
//  MCUF_CRCCheck_27A = Gu8_ComIf_APPRxMsgData[7] & (0xFF);
//	if(MCUF_CRCCheck_27A == Interface_crc_high_first(&Gu8_ComIf_APPRxMsgData[0],7))
//	{
//	bol_ComIf_flgCRCFaltRaw = false;
//	}
//	else
//	{
//	bol_ComIf_flgCRCFaltRaw = true;
//	}
}
	
	/* Send Application message 0x1F */
if(Gu8_ComIf_APPTxMesFlagSecond == true)	
{
	Gu8_ComIf_APPTxMesFlagSecond=0;
   if (Gu8_DIAG_HSLS_OCWarning ==2)
	{
	bol_flgHWOvrCurrComEn = true;
	}
	else
	{
	bol_flgHWOvrCurrComEn = false;
	}
  u8_ComIf_APPTxMsgData1[0] = ((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgPhCurrHiLvl1Flg & (!busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPhCurrHiLvl1Tmp)) & 0x01) | 
	                            ((!bol_flgCalibFin<<2) & 0x04) | 
	                            (((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgMotoStallPermFlg & (!busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoStallPermTmp))<<3) & 0x08) | 
	                            (((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgHWOvrCurrFlg & (bol_flgHWOvrCurrComEn))<<5) & 0x20) | 
	                            (((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgComFaltFlg & busOBD_SlwTaskOut.bol_flgComNodeLosFaltDeb)<<6) & 0x40) |
	                            ((busOBD_SlwTaskOut.bol_flgPhiSensFaltRawFlg<<7) & 0x80);
  u8_ComIf_APPTxMsgData1[1] = (busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgPwrTubPCBTempHiLvl2Flg & 0x01) | 
	                            ((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgGDVltgHiLvl1Flg<<2) & 0x04) | 
	                            ((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgSplyVltgHiLvl1Flg<<3) & 0x08) | 
	                            ((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgGDVltgLoLvl1Flg<<4) & 0x10) | 
	                            ((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgSplyVltgLoLvl2Flg<<5) & 0x20) |
	                            ((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgMotoSpdLoLvl1Flg<<7) & 0x80);
	ComIf_BusCurrent = (sint16)((sint32)((sint32)(busAST_SlwTaskOut.s16_iEstSplyCurr)*Cdbl_iSplyCurrPeakVal*10)>>15);
	static uint8 ComIf_RunningStatusOld;
	if(busAST_SlwTaskOut.enm_stSysSt == SYSINIT)
	{
	ComIf_RunningStatus = 0;
	}
	else if (busAST_SlwTaskOut.enm_stSysSt == STANDBY)
	{
	ComIf_RunningStatus = 3;
	}
	else if(busAST_SlwTaskOut.enm_stSysSt == SYSFAIL) 
	{
	ComIf_RunningStatus = 7;
	}
//	else if((busAST_SlwTaskOut.enm_stSysSt == SYSFAIL) && (((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgMotoStallPermFlg == 0) &&(busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoStallPermTmp == 0))||(busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgPhCurrHiLvl1Flg == 0)))
//	{
//	ComIf_RunningStatus = 7;
//	}
	else if((busAST_SlwTaskOut.enm_stSysSt == RUN) && (busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgNoLdFlg) )
	{
	ComIf_RunningStatus = 6;
	}
	else
	{
	ComIf_RunningStatus = 5;
	}
	
	if(ComIf_RunningStatus == 7) 
	{
	if ((busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoStallPermTmp == 1) ||(busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPhCurrHiLvl1Tmp == 1))
	{
	ComIf_RunningStatus = ComIf_RunningStatusOld;
	}
	}
	ComIf_RunningStatusOld = ComIf_RunningStatus;
	
	u8_ComIf_APPTxMsgData1[2] = ComIf_BusCurrent & 0xFF;
  u8_ComIf_APPTxMsgData1[3] = ((ComIf_BusCurrent >>8) & 0x03) | 
	                            (((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgComFaltFlg & busOBD_SlwTaskOut.bol_flgComRolCntFaltDeb)<<2) & 0x04) |
	                            (((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgComFaltFlg & busOBD_SlwTaskOut.bol_flgCRCFaltDeb)<<3) & 0x08) |
	                            ((ComIf_RunningStatus<<4) & 0xF0);
  if (MCUF_OperationModel == 0 && !busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgComFaltFlg)
	{
	ComIf_OffCmdRecFb = 1;
	}
	else
	{
	ComIf_OffCmdRecFb = 0;
	}
	u8_ComIf_APPTxMsgData1[4] = (ComIf_OffCmdRecFb & 0x01) | ((u16_Interface_AplHWVer<<4) & 0xF0);
  ComIf_PhaseCurrent = (sint16)((sint32)((sint32)(busAST_SlwTaskOut.s16_ampActPhCurrAmp)*Cdbl_iPhCurrPeakVal*10)>>15);
  u8_ComIf_APPTxMsgData1[5] = ((ComIf_PhaseCurrent <<1) & 0xFE);
	if (ComIf_AlvCnt1 < 15)
	{
	ComIf_AlvCnt1 ++;
	}
	else
	{
	ComIf_AlvCnt1 = 0;
	}
	u8_ComIf_APPTxMsgData1[6] = ((ComIf_AlvCnt1<<4) & 0xF0) |  ((ComIf_PhaseCurrent >>7) & 0x0F);
  u8_ComIf_APPTxMsgData1[7] = Interface_crc_high_first(&u8_ComIf_APPTxMsgData1[0],7);
	ComIf_Set_APPTxMsgData(u8_ComIf_APPTxMsgData1,0x1F);
}

	/* Send Application message 0x20 */
 if((busPhCurrGen_SlwTaskOut.enm_stMotoSt != OFF) && (busPhVltgGen_MedTaskOut.s16_nActElecSpd > 0))
 {
      Gs16_ComIf_ActSpdBOOTChk = (sint16)((sint32)((sint32)(busAST_SlwTaskOut.s16_nActElecSpdComFlt)*7827)>>15);
 }
 else if(busPhVltgGen_MedTaskOut.s16_nActElecSpd<=0)
 {
	 Gs16_ComIf_ActSpdBOOTChk = 0;
 }
if(Gu8_ComIf_APPTxMesFlagFirst == true)
{
	Gu8_ComIf_APPTxMesFlagFirst=0;
	u8_ComIf_APPTxMsgData2[0] = (uint8)(Gu8_tMcuTemp_IF + 10) & 0xFF;
  u8_ComIf_APPTxMsgData2[1] =(uint8)(busSigIn_SlwTaskOut.u8_tPCBTemp + 10) & 0xFF;
  u8_ComIf_APPTxMsgData2[2] =  (uint8)((sint32)((sint32)(busSigIn_MedTaskOut.u16_uSplyVltg)*Cdbl_uSplyVltgPeakVal*5)>>15) & 0xFF;
  if((busPhCurrGen_SlwTaskOut.enm_stMotoSt != OFF) && (busPhVltgGen_MedTaskOut.s16_nActElecSpd > 0))
	{
		/* ComIf_ActualSpeed = (busPhVltgGen_MedTaskOut.s16_nActElecSpd*Cdbl_nElecAgSpdPeakVal*6/PI)>>15 */
//	ComIf_ActualSpeed = (sint16)((sint32)((sint32)(busPhVltgGen_MedTaskOut.s16_nActElecSpd)*7827)>>15);
		ComIf_ActualSpeed = (sint16)((sint32)((sint32)(busAST_SlwTaskOut.s16_nActElecSpdComFlt)*7827)>>15);
		if(ComIf_ActualSpeed <= 0)
		{
		ComIf_ActualSpeed = 0;
		}
		/* Special Demand from Customers of GEELY*/
		ComIf_ActualSpeed = (sint16)((sint32)(ComIf_ActualSpeed * 100)/107);
		if((ComIf_ActualSpeed >= 50) && (ComIf_ActualSpeed < 250))
		{
		ComIf_ActualSpeed = (sint16)((ComIf_ActualSpeed-100)/3 + 200);
		}
		/* end */
	}
	Gs16_Interface_ActSpd = ComIf_ActualSpeed;
	u8_ComIf_APPTxMsgData2[3] = Gs16_Interface_ActSpd & 0xFF;
  u8_ComIf_APPTxMsgData2[4] = ((Gs16_Interface_ActSpd>>8) & 0x1F) | 
	                            ((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgPwrTubPCBTempSensFaltFlg<<5) & 0x20)|
	                            (((busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgChipFaltFlg | busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgMosOpnCirFaltFlg)<<7) & 0x80);
	u8_ComIf_APPTxMsgData2[5] = ((u16_Interface_AplSWVer<<2) & 0xFC) | (u8_Interface_SplyID & 0x03);
	//ComIf_Set_APPTxMsgData(u8_ComIf_APPTxMsgData2,0x20);
	if(ComIf_AlvCnt2 < 15)
	{
	ComIf_AlvCnt2 ++;
	}
	else
	{
	ComIf_AlvCnt2 = 0;
	}
	u8_ComIf_APPTxMsgData2[6] = (ComIf_AlvCnt2<<4) & 0xF0;
  u8_ComIf_APPTxMsgData2[7] = Interface_crc_high_first(&u8_ComIf_APPTxMsgData2[0],7);
	ComIf_Set_APPTxMsgData(u8_ComIf_APPTxMsgData2,0x20);
	
//	/* Gu8_ComIf_APPRxMesCnt */
//	if(Gu8_ComIf_APPRxMesCnt == u8_ComIf_APPRxMesCntOld)
//	{
//	bol_ComIf_flgComLosFaltRaw = true;
//	}
//	else
//	{
//		bol_ComIf_flgComLosFaltRaw = false;
//	}
//	  u8_ComIf_APPRxMesCntOld = Gu8_ComIf_APPRxMesCnt;	
}
}


void Interface_FrzUDSCom_ASW_Trans(void)
{
	/* Send 22 service message */
  static uint8_t u8_NumHWVersion = 0;
	static uint8_t u8_NumSysName = 0;
	static uint8_t u8_NumSWVersion = 0;
	static uint8_t u8_NumDataVersion = 0;
	for(u8_NumSysName = 0;u8_NumSysName < 7;u8_NumSysName++)
	{
			busComIf_UDSRead_In.u8_SysName[u8_NumSysName] = u8_Interface_SysName[u8_NumSysName];
	}
  for(u8_NumSWVersion = 0;u8_NumSWVersion < 10;u8_NumSWVersion++)
	{
  busComIf_UDSRead_In.u8_WF_SWVersion[u8_NumSWVersion] = u8_Interface_SWVersion[u8_NumSWVersion];
	}
	for(u8_NumDataVersion = 0;u8_NumDataVersion < 25;u8_NumDataVersion++)
	{
  busComIf_UDSRead_In.u8_CalibDataVersion[u8_NumDataVersion] = u8_Interface_DataVersion[u8_NumDataVersion];	
	}
	for(u8_NumHWVersion = 0;u8_NumHWVersion < 10;u8_NumHWVersion++)
	{
	busComIf_UDSRead_In.u8_WF_HWVersion[u8_NumHWVersion] = u8_Interface_HWVersion[u8_NumHWVersion];
	}
}

void Interface_AgCalib_Trans(void)
{
  static uint8_t calib_sts = 0;
	static bool bol_flgPosSCDCalibSucFlgOld = false;
	uint16_t* calib_buff;
	
	switch(calib_sts)
  {
    case 0: //INIT
    {
	/**
	 * Now, charact data not at 'UC_FLASH0_UDATA_START' this address
	 * All Data stored in NVM would be copy to ram by 'Mem_DataNVM2RAM()' at first
	*/
		calib_buff = (uint16_t *)(offset_buff);
	  if ( (calib_buff[0] ^ calib_buff[1]) == 0xFFFFu )
      {
				u16_AgADOffset = calib_buff[0];
        calib_sts = 2;
      }
      else
      {
        calib_sts = 1;
      }

      break;
    }
		
    case 1: //CALIBRATION
		{
		if ((bol_flgPosSCDCalibSucFlgOld == false) && (busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg ==true))
		{
			u16_AgADOffset = busAST_SlwTaskOut.u16_phiSensElecAgDvt;
			offset_buff[0] = u16_AgADOffset;
      offset_buff[1] = ~u16_AgADOffset;

			/**This palce should make 'u16_AgADOffset' at MEM_CHARACT_DATA_RAM section which use 'MEM_CHARACT_DATA_RAM', 
			 * and call function 'Mem_DataRAM2NVM(MEM_CHARACT_DATA)', can store data to NVM
			 * */
			Sys_IntDisIrq();
			(void)Mem_DataRAM2NVM(MEM_CHARACT);
			Sys_IntEnIrq();
			/* Calibration done, execute a WD reset */ 
			for(;;);
		}
		bol_flgPosSCDCalibSucFlgOld = busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg;
	      break;
		}
	case 2: // CALIBRATED
    {
      bol_flgCalibFin = true;
      break;
    }
    default:
      break;
  }
}

void Interface_Mem_Trans(void)
{
		/* for Save product information  */
	static uint8_t NumWF_HWVersion = 0;
	for(NumWF_HWVersion = 0;NumWF_HWVersion < 10;NumWF_HWVersion++)
	{
	u8_Interface_HWVersion[NumWF_HWVersion] = Gu8_ComIf_HWVersion[NumWF_HWVersion];
	}
	
	if(Gu8_ComIf_UDSWriteFlg == 1)
	{
	  Mem_DataRAM2NVM(MEM_RWPRODUCTINFO);
    Gu8_ComIf_UDSWriteFlg = 0;
	}
}

/**
 * \fn       Interface_Set_DutyCycle
 * \brief    Get fuction to read duty cycles coputed by the control
 */
void Interface_Set_DutyCycle(uint16 u16_dutyCyc[3])
{

  u16_dutyCyc[0] = busDcycGen_FstTaskOut.u16_dcycPhDyc[0];
  u16_dutyCyc[1] = busDcycGen_FstTaskOut.u16_dcycPhDyc[1];
  u16_dutyCyc[2] = busDcycGen_FstTaskOut.u16_dcycPhDyc[2];
}
/**
 * \fn       let motor sleep
 * \brief    //
 */
void Interface_SleepReq(void)
	{ 
//	if ( (busAST_SlwTaskOut.enm_stSysSt == SYSSLEEP) &&  (busOBD_SlwTaskOut.busOBD_FaltSt.bol_flgComFaltFlg == true))
		if (busAST_SlwTaskOut.enm_stSysSt == SYSSLEEP)
		{
   Sys_SCU_SleepMode();
  }
}
