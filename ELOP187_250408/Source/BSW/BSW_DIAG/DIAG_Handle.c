/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "bdrv.h"
#include "DIAG_Handle.h"
#include "BDRV_BDRV.h"
#include "HSI_SW.h"
#include "Task_Task.h"
#include "PWM_Pwm.h"
#include "PWM_Clac.h"
#include "ADC_Meas.h"
#include "PosSCD_PosSensor.h"
#include "MID_Interface.h"
/*******************************************************************************
**                          Private Type Declarations                         **
*******************************************************************************/
#if 0
typedef struct
{
  uint32 StatusFlag;       
  uint8  ErrVar;           
  void   (*Func)(void);    
  uint8  RestFlag;         
}ST_DIAG_BDRVMon;
#endif

typedef struct
{     
  uint8  DIAG_HS1_OC;
  uint8  DIAG_HS2_OC;
  uint8  DIAG_HS3_OC;
  uint8  DIAG_LS1_OC;
  uint8  DIAG_LS2_OC;
  uint8  DIAG_LS3_OC;
}ST_DIAG_HSLS_OC;

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
#define DIAG_HSLSOC_WARN_CNT_MAX                  (2u)
#define DIAG_HSLSOC_WARN_DELAY_4S                 (40u)//8000u
#define DIAG_VCP_UVFAIL_BIT                       (0x3030000)
#define DIAG_VCPUV_WARN_CNT_MAX                   (5u)
#define DIAG_VCPVDH_DIFF_MIN                      (8000u)//8v
#define DIAG_VCPVDH_DIFF_MAX                      (18000u)//18v
#define DIAG_OPENLOAD_CHECKMAX                    (10u)      

/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS1_DSMonitor;   /*HS1 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS2_DSMonitor;   /*HS2 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS3_DSMonitor;   /*HS3 DSMonitor error status */

// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS1_DSMonitor;   /*LS1 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS2_DSMonitor;   /*LS2 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS3_DSMonitor;   /*LS3 DSMonitor error status */


SRAM_GLOBAL_UINT8 Gu8_DIAG_VDD_1V5OV;      /*VDD 1.5V under voltage error status */
SRAM_GLOBAL_UINT8 Gu8_DIAG_VDD_5VOV;       /*VDD   5V under voltage error status */

// SRAM_GLOBAL_UINT8 Gu8_DIAG_PMU_1V5OverLoad;/*PMU 1.5V over load error status */
// SRAM_GLOBAL_UINT8 Gu8_DIAG_PMU_5VOverLoad; /*PMU   5V over load error status */

SRAM_GLOBAL_UINT16 Gu16_BSWToAPPFault_IF;/*BSW fault status*/
SRAM_GLOBAL_UINT8  Gu8_DIAG_HSLS_OCWarning;/*HS LS overcurrent count*/


SRAM_GLOBAL_UINT8 Gu8_DIAG_PSCDFault;/*TLE5012B error status,0 no error ,1 error*/

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/
static SRAM_GLOBAL_UINT8  Su8_DIAG_VCPLOWTH2Warning;/*VCP LOWTH2 eroor count,when the count is bigger than 3,software will judge tle9879 VCPLOWTH2 fault happen*/
static SRAM_GLOBAL_UINT8  Su8_DIAG_VCPLOWTH2Fault;   /*Charge Pump output voltage low threshold comparator in BDRV module*/
static SRAM_GLOBAL_UINT8  Su8_DIAG_VCPLOWTH1Fault;   /*Charge Pump output voltage low threshold comparator in BDRV module*/
static SRAM_GLOBAL_UINT8  Su8_DIAG_VCPLOWTH1Warning;/*VCP LOWTH2 eroor count,when the count is bigger than 3,software will judge tle9879 VCPLOWTH1 fault happen*/
static SRAM_GLOBAL_UINT8  Su8_DIAG_HSLS_OCStatus;/* HS LS over current monitor*/
static SRAM_GLOBAL_UINT16 Su16_DIAG_HSLS_OCCnt; /*HS LS over current time count*/
static SRAM_GLOBAL_UINT8  Su8_DIAG_500usOpen;//Open 500us timer status, 1 Open  ,0 Close
static SRAM_GLOBAL_UINT16 Su16_DIAG_VCPVDHDiff;   /* VCP and VDH difference value*/
static SRAM_GLOBAL_UINT8  Su8_DIAG_VCPVDHDiffLow;   /* VCP and VDH difference value is lower than 8000mv*/
static SRAM_GLOBAL_UINT8  Su8_DIAG_VCPVDHDiffHigh;  /* VCP and VDH difference value is bigger than 18000mv*/

static ST_DIAG_HSLS_OC SstDIAG_HSLS_OCState;

static SRAM_GLOBAL_UINT8 Su8_DIAG_PSCDErrCnt;/* TLE5012B error count*/

// static SRAM_GLOBAL_UINT8 Su8_VollowFlag;
static SRAM_GLOBAL_UINT8 Su8_OpenLoad_Fault;
static SRAM_GLOBAL_UINT8 Su8_DIAG_VDD_1V5OVFault;
static SRAM_GLOBAL_UINT8 Su8_DIAG_VDD_5VOVFault;
static SRAM_GLOBAL_UINT8 Su8_DIAG_VDD_1V5OVCnt;
static SRAM_GLOBAL_UINT8 Su8_DIAG_VDD_5VOVCnt;
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS1_OC; /*HS1 Over Current error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS2_OC; /*HS2 Over Current error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS3_OC; /*HS3 Over Current error status */

// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS1_OC; /*LS1 Over Current error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS2_OC; /*LS2 Over Current error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS3_OC; /*LS3 Over Current error status */

// static SRAM_GLOBAL_UINT16 Su16_DIAG_BSWFault;/*BSW fault status*/

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/
static void DIAG_BDRVFault_Monitor(void);
static void DIAG_HSLS_OC_Handle(void);
static uint8 DIAG_3PhaseOpenLoad_Check(void);
static void DIAG_BDRV_1PhaseOC_Monitor(void);
static void DIAG_BDRV_2PhaseOC_Monitor(void);
static void DIAG_BDRV_3PhaseOC_Monitor(void);
static void DIAG_BDRV_1PhaseDS_Monitor(void);
static void DIAG_BDRV_2PhaseDS_Monitor(void);
static void DIAG_BDRV_3PhaseDS_Monitor(void);
static void DIAG_BDRV_3PhaseFault_Monitor(void);
static void DIAG_BDRV_VCPFault_Monitor(void);
static void DIAG_BDRV_VSDFault_Monitor(void);
static void DIAG_VREF_Fault_Handle(void);
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
void DIAG_SysSupply_Err(void)
{
    if (1u == HSI_DIAG_Get_VSUV_State())//VS lower than 5.78 ,need reset
    {
        while(1);
    }
    else
    {
        ;
    }

    if (1u == HSI_DIAG_Get_VSOV_State())
    {
        ADC2_VS_OV_Int_Clr();
    }
    else
    {
        ;
    }
}
    
void DIAG_VCPAndVDHDiff_Handle(void)
{
	if(Gu16_uADC2VCP>=Gu16_uADCVDH_IF)
	{
		Su16_DIAG_VCPVDHDiff=Gu16_uADC2VCP-Gu16_uADCVDH_IF;/* VDP and VDH diff*/
		if(Su16_DIAG_VCPVDHDiff<DIAG_VCPVDH_DIFF_MIN)
		{
			Su8_DIAG_VCPVDHDiffLow=1u;
			Su8_DIAG_VCPVDHDiffHigh=0u;
		
		}
        else if(Su16_DIAG_VCPVDHDiff>DIAG_VCPVDH_DIFF_MAX)
		{
			Su8_DIAG_VCPVDHDiffLow=0u;
			Su8_DIAG_VCPVDHDiffHigh=1u;
		}
        else
        {
			Su8_DIAG_VCPVDHDiffLow=0u;
			Su8_DIAG_VCPVDHDiffHigh=0u;
		}
	}
    else
    {
		Su8_DIAG_VCPVDHDiffLow=1u;
	}
}


void DIAG_BasicToAPPfault_Monitor(void)
{
    if((Su8_DIAG_VDD_5VOVFault==1u)||( Su8_DIAG_VDD_1V5OVFault ==1u))//bit0 
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF|0x0001;
    }
    else
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF&0xFFFE;
    }

    // if((Gu8_DIAG_PMU_5VOverLoad==1u)||(Gu8_DIAG_PMU_1V5OverLoad==1u))//bit1  
    // {
    //     Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF|0x0002;
    // }
    // else
    // {
    //     Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF&0xFFFD;
    // }
    
    if(Su8_DIAG_VCPVDHDiffHigh==1u)//bit2
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF|0x0004;
    }
    else
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF&0xFFFB;
    }
    /////////////////////////////////////////////
    if((Su8_DIAG_VCPLOWTH1Fault==1u)||(Su8_DIAG_VCPLOWTH2Fault==1u)||(Su8_DIAG_VCPVDHDiffLow==1u))//bit3
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF|0x0008;
    }
    else
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF&0xFFF7;
    }
    /////////////////////////////////////////////
    if(Su8_DIAG_HSLS_OCStatus==1u)//bit4
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF|0x0010;
    }
    else
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF&0xFFEF;
    }		
    //////////////////////////////////////////
    if(Gu8_DIAG_PSCDFault==1u)    //bit5
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF|0x0020;
    }
    else
    {
        Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF&0xFFDF;
    }		
	//////////////////////////////////////////
	if(Su8_OpenLoad_Fault==1)    //bit6
	{
		Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF|0x0040;
	}else{
		Gu16_BSWToAPPFault_IF=Gu16_BSWToAPPFault_IF&0xFFBF;
	}
}


static void DIAG_VCPLO2_Handle(void)
{
	if(BDRV_VCP_LO_Int_Sts() == 1u)
	{
		if(Su8_DIAG_VCPLOWTH2Warning<=DIAG_VCPUV_WARN_CNT_MAX)
		{
			BDRV_Clr_Sts(DIAG_VCP_UVFAIL_BIT);
			BDRV_ConfigBridgePWM();
			Su8_DIAG_VCPLOWTH2Warning++;
		}
		else
		{
			Su8_DIAG_VCPLOWTH2Fault=1;/* when the error happen continuous than 3 times,set the fault sign*/
		}
	}
	else
	{
		Su8_DIAG_VCPLOWTH2Warning=0;
	}
}

static void DIAG_VCPLO1_Handle(void)
{
	if(HSI_DIAG_Get_VCPLO1_State() == 1u)
	{
		if(Su8_DIAG_VCPLOWTH1Warning<=DIAG_VCPUV_WARN_CNT_MAX)
		{
			BDRV_Clr_Sts(DIAG_VCP_UVFAIL_BIT);
			BDRV_ConfigBridgePWM();
			Su8_DIAG_VCPLOWTH1Warning++;
		}
		else
		{
			Su8_DIAG_VCPLOWTH1Fault=1;/* when the error happen continuous than 3 times,set the fault sign*/
		}
	}
	else
	{
		Su8_DIAG_VCPLOWTH1Warning=0;
	}
}

void DIAG_VCPFault_Handle(void)
{
	if ((Gu16_uADCVSD_IF>7000u) && (BDRV_INIT_DONE == GenmBDRV_InitState))
	{
		// if( ((BDRV_VCP_LO_Int_Sts() == 1u)||(HSI_DIAG_Get_VCPLO1_State() == 1u)))
		// {
			DIAG_VCPLO2_Handle();
			DIAG_VCPLO1_Handle();
		// }
	}
	else
	{
			BDRV_Clr_Sts(DIAG_VCP_UVFAIL_BIT);
			BDRV_ConfigBridgePWM();
			Su8_DIAG_VCPLOWTH1Warning=0;
			Su8_DIAG_VCPLOWTH2Warning=0;
	}

	
}

void DIAG_HSLSFault_Handle(void)//100ms
{
    DIAG_BDRVFault_Monitor();/*HS and LS overcurrent flag read*/
	DIAG_VREF_Fault_Handle();
    DIAG_HSLS_OC_Handle();/*HS and LS over current handle*/
}

// void DIAG_HSLS_OC_Timer_Handle_ISR(void) 
// {
// 	if(Su8_DIAG_500usOpen==0u)
// 	{
// 		TIMER21_Stop();  
// 	}
// 	else
// 	{
// 		// if(Gu8_DIAG_HSLS_OCWarning<=1)
// 		// {
// 		// 	Su16_DIAG_HSLS_OCCnt++;
// 		// 	if(Su16_DIAG_HSLS_OCCnt>=DIAG_HSLSOC_WARN_DELAY_4S)//500us*8000=4000ms=4s
// 		// 	{//run here, means just oc once
// 		// 		Su16_DIAG_HSLS_OCCnt = DIAG_HSLSOC_WARN_DELAY_4S;
// 		// 		Su8_DIAG_500usOpen=0;
// 		// 		HSI_TIMER21_ReInit10us();
// 		// 		Task_StartupTask();
// 		// 	}
// 		// 	else
// 		// 	{
// 		// 		;
// 		// 	}
// 		// }
// 		// else
// 		// {
// 		// 	;
// 		// }
// 	}
// }


void DIAG_PosSCD_Com(void)//500us 
{
	if(((Gu16_PSCD_SafetyWord_IF&PSCD_COM_SUCCESS_MASK)!=PSCD_COM_SUCCESS_VAULE)
	 ||(Gu16_PSCD_SafetyWord_IF==PSCD_SAFETY_MASK))
	{
		if(Su8_DIAG_PSCDErrCnt<8)
		{
			Su8_DIAG_PSCDErrCnt++;
		}else{
			Gu8_DIAG_PSCDFault=1;
		}
	}
	else 
	{
		if(Su8_DIAG_PSCDErrCnt>0)
		{
			Su8_DIAG_PSCDErrCnt--;
		}else{
			Gu8_DIAG_PSCDFault=0;
		}
	}
}

void DIAG_VSDFault_Handle(void)//500us
{
	if(Gu16_uADCVSD_IF < 6000)
	{
		while (1);
	}
}

/*brief : BDRV 3 phase openload diag confirm
  note  : 
*/	
void DIAG_3PhaseOpenLoadFault_Handle(void)
{
	uint8 u8_3PhaseOpenloadCnt;
	
	u8_3PhaseOpenloadCnt=0u;

	u8_3PhaseOpenloadCnt=DIAG_3PhaseOpenLoad_Check();

	if(0u == u8_3PhaseOpenloadCnt)//no openload error judge 1 time
	{
		Su8_OpenLoad_Fault=0u;
	}
	else if(DIAG_OPENLOAD_CHECKMAX > u8_3PhaseOpenloadCnt)//ever openload occur 1 time
	{
		u8_3PhaseOpenloadCnt=DIAG_3PhaseOpenLoad_Check(); 

		if(0u == u8_3PhaseOpenloadCnt) //no openload error judge 2 time
		{
			Su8_OpenLoad_Fault=0u;
		}
	  	else if(DIAG_OPENLOAD_CHECKMAX > u8_3PhaseOpenloadCnt)//ever openload occur 2 time
	  	{
			u8_3PhaseOpenloadCnt=DIAG_3PhaseOpenLoad_Check();

			if(DIAG_OPENLOAD_CHECKMAX == u8_3PhaseOpenloadCnt) 
	    	{
		    	Su8_OpenLoad_Fault=1u;//third diag openload happen
			}
			else
			{
				Su8_OpenLoad_Fault=0u;
			}
		}
		else
		{
			Su8_OpenLoad_Fault=1u;//second diag openload happen
		}
	}
	else
	{
		Su8_OpenLoad_Fault=1u;//first diag openload happen all time
	}
}

static void DIAG_BDRV_1PhaseOC_Monitor(void)
{
/* HS1 Over Current Interrupt */
	if (BDRV_HS1_OC_Int_Sts() == 1u)
	{
		if(BDRV_OUTPUT_OPEN == Gu8_PWM_MotorRunStatus)
		{
			SstDIAG_HSLS_OCState.DIAG_HS1_OC=1u;
		}
		else
		{
			SstDIAG_HSLS_OCState.DIAG_HS1_OC=0u;
		}
		BDRV_HS1_OC_Int_Clr();
	}
	else
	{
		;
	}

	/* LS1 Over Current Interrupt */
	if (BDRV_LS1_OC_Int_Sts() == 1u)
	{
		if(BDRV_OUTPUT_OPEN == Gu8_PWM_MotorRunStatus)
		{
			SstDIAG_HSLS_OCState.DIAG_LS1_OC=1u;
		}
		else
		{
			SstDIAG_HSLS_OCState.DIAG_LS1_OC=0u;
		}
		BDRV_LS1_OC_Int_Clr();
	}
	else
	{
		;
	}
}

static void DIAG_BDRV_2PhaseOC_Monitor(void)
{
	/* HS2 Over Current Interrupt */
	if (BDRV_HS2_OC_Int_Sts() == 1u)
	{
		if(BDRV_OUTPUT_OPEN == Gu8_PWM_MotorRunStatus)
		{
			SstDIAG_HSLS_OCState.DIAG_HS2_OC=1u;
		}
		else
		{
			SstDIAG_HSLS_OCState.DIAG_HS2_OC=0u;
		}
		BDRV_HS2_OC_Int_Clr();
	}
	else
	{
		;
	}

	/* LS2 Over Current Interrupt */
	if (BDRV_LS2_OC_Int_Sts() == 1u)
	{
		if(BDRV_OUTPUT_OPEN == Gu8_PWM_MotorRunStatus)
		{
			SstDIAG_HSLS_OCState.DIAG_LS2_OC=1u;
		}
		else
		{
			SstDIAG_HSLS_OCState.DIAG_LS2_OC=0u;
		}
		BDRV_LS2_OC_Int_Clr();
	}
	else
	{
		;
	}
}

static void DIAG_BDRV_3PhaseOC_Monitor(void)
{
	/* HS3 Over Current Interrupt */
	if (BDRV_HS3_OC_Int_Sts() == 1u)
	{
		if(BDRV_OUTPUT_OPEN == Gu8_PWM_MotorRunStatus)
		{
			SstDIAG_HSLS_OCState.DIAG_HS3_OC=1u;
		}
		else
		{
			SstDIAG_HSLS_OCState.DIAG_HS3_OC=0u;
		}
		BDRV_HS3_OC_Int_Clr();
	}
	else
	{
		;
	}

	/* LS3 Over Current Interrupt */
	if (BDRV_LS3_OC_Int_Sts() == 1u)
	{
		if(BDRV_OUTPUT_OPEN == Gu8_PWM_MotorRunStatus)
		{
			SstDIAG_HSLS_OCState.DIAG_LS3_OC=1u;
		}
		else
		{
			SstDIAG_HSLS_OCState.DIAG_LS3_OC=0u;
		}
		BDRV_LS3_OC_Int_Clr();
	}
	else
	{
		;
	}
}

static void DIAG_BDRV_1PhaseDS_Monitor(void)
{
	/* HS1 Drain Source Monitoring Interrupt */
	if (BDRV_HS1_DS_Int_Sts() == 1u)
	{
		BDRV_HS1_DS_Int_Clr();
	}
	
	/* LS1 Drain Source Monitoring Interrupt */
	if (BDRV_LS1_DS_Int_Sts() == 1u)
	{
		BDRV_LS1_DS_Int_Clr();
	}
}

static void DIAG_BDRV_2PhaseDS_Monitor(void)
{
	/* HS2 Drain Source Monitoring Interrupt */
	if (BDRV_HS2_DS_Int_Sts() == 1u)
	{
		BDRV_HS2_DS_Int_Clr();
	}
	
	/* LS2 Drain Source Monitoring Interrupt */
	if (BDRV_LS2_DS_Int_Sts() == 1u)
	{
		BDRV_LS2_DS_Int_Clr();
	}
}

static void DIAG_BDRV_3PhaseDS_Monitor(void)
{
	/* HS3 Drain Source Monitoring Interrupt */
	if (BDRV_HS3_DS_Int_Sts() == 1u)
	{
		BDRV_HS3_DS_Int_Clr();
	}

	/* LS3 Drain Source Monitoring Interrupt */
	if (BDRV_LS3_DS_Int_Sts() == 1u)
	{
		BDRV_LS3_DS_Int_Clr();
	}
}

static void DIAG_BDRV_3PhaseFault_Monitor(void)
{
	DIAG_BDRV_1PhaseOC_Monitor();
	DIAG_BDRV_2PhaseOC_Monitor();
	DIAG_BDRV_3PhaseOC_Monitor();
	DIAG_BDRV_1PhaseDS_Monitor();
	DIAG_BDRV_2PhaseDS_Monitor();
	DIAG_BDRV_3PhaseDS_Monitor();
}

static void DIAG_BDRV_VCPFault_Monitor(void)
{
	/* Charge Pump output voltage low threshold measured by ADC2-Ch3 */
	if (HSI_DIAG_Get_VCPLO1_State()== 1u)
	{
		ADC2_VCP_UV_Int_Clr();
	}
	else
	{
		;
	}

	/* Charge Pump output voltage low threshold comparator in BDRV module */
	if (BDRV_VCP_LO_Int_Sts() == 1u)
	{
		BDRV_VCP_LO_Int_Clr();
	}
	else
	{
		;
	}
}

static void DIAG_BDRV_VSDFault_Monitor(void)
{
	/* Charge Pump input voltage low threshold measured by ADC2-Ch2 */
	if (HSI_DIAG_Get_VSDLO_State() == 1u)//VSD lower than 5.78 ,need reset
	{
		while(1);
		//ADC2_VSD_UV_Int_Clr();
	}
	else
	{
		;
	}

	/* Charge Pump input voltage upper threshold measured by ADC2-Ch2 */
	if (HSI_DIAG_Get_VSDUP_State() == 1u)
	{
		ADC2_VSD_OV_Int_Clr();
	}
}

static void DIAG_BDRVFault_Monitor(void)
{
	DIAG_BDRV_3PhaseFault_Monitor();

	DIAG_BDRV_VCPFault_Monitor();

	DIAG_BDRV_VSDFault_Monitor();

}


static void DIAG_HSLS_OC_Handle(void)
{
	static uint8 Su8_DIAG_HSLS_OCExitCnt =0u;
	uint8  u8_DIAG_HSLS_OC = 0u;/* HS LS over current monitor*/
	uint16 u16_ActualSpeed = 0u;

	if(0u != Su16_DIAG_HSLS_OCCnt)
	{
		Su16_DIAG_HSLS_OCCnt--;
	}

	 if(SstDIAG_HSLS_OCState.DIAG_HS1_OC==1u)
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC|0x01;
	 }
	 else
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC&0xFE;
	 }

	 if(SstDIAG_HSLS_OCState.DIAG_HS2_OC==1u)
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC|0x02;
	 }
	 else
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC&0xFD;
	 }

	 if(SstDIAG_HSLS_OCState.DIAG_HS3_OC==1u)
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC|0x04;
	 }
	 else
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC&0xFB;
	 }

	 if(SstDIAG_HSLS_OCState.DIAG_LS1_OC==1u)
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC|0x08;
	 }
	 else
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC&0xF7;
	 }

	 if(SstDIAG_HSLS_OCState.DIAG_LS2_OC==1u)
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC|0x10;
	 }
	 else
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC&0xEF;
	 }

	 if(SstDIAG_HSLS_OCState.DIAG_LS3_OC==1u)
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC|0x20;
	 }
	 else
	 {
		 u8_DIAG_HSLS_OC=u8_DIAG_HSLS_OC&0xDF;
	 }

	 SstDIAG_HSLS_OCState.DIAG_HS1_OC=0;
	 SstDIAG_HSLS_OCState.DIAG_HS2_OC=0;
	 SstDIAG_HSLS_OCState.DIAG_HS3_OC=0;
	 SstDIAG_HSLS_OCState.DIAG_LS1_OC=0;
	 SstDIAG_HSLS_OCState.DIAG_LS2_OC=0;
	 SstDIAG_HSLS_OCState.DIAG_LS3_OC=0;
	 
	if(u8_DIAG_HSLS_OC!=0)
	{
		u8_DIAG_HSLS_OC=0;

		if (Gu8_DIAG_HSLS_OCWarning < DIAG_HSLSOC_WARN_CNT_MAX)
		{
			Gu8_DIAG_HSLS_OCWarning++;
		}
		
		Su16_DIAG_HSLS_OCCnt=DIAG_HSLSOC_WARN_DELAY_4S;
	}
	else
	{
		if(1u == Gu8_DIAG_HSLS_OCWarning)
		{
			u16_ActualSpeed = (uint16)Gs16_Interface_ActSpd;//MotCtrl_get_actualSpeed()
			
			if((0u == Su16_DIAG_HSLS_OCCnt)&&(u16_ActualSpeed>=100u))
			{
				Su8_DIAG_HSLS_OCExitCnt++;
				if(Su8_DIAG_HSLS_OCExitCnt>=50u)
				{
					Gu8_DIAG_HSLS_OCWarning = 0u;
					Su8_DIAG_HSLS_OCExitCnt = 0u;
				}
			}
		}	
	}

	if(((0u != Su16_DIAG_HSLS_OCCnt)&&(1u == Gu8_DIAG_HSLS_OCWarning))
	  ||(DIAG_HSLSOC_WARN_CNT_MAX == Gu8_DIAG_HSLS_OCWarning))
	{
		Su8_DIAG_HSLS_OCStatus=1u;
	}
	else
	{
		Su8_DIAG_HSLS_OCStatus=0u;
	}
}

static void DIAG_VREF_Fault_Handle(void)
{
	HSI_VREF_Fault_Check();
}

/*brief : BDRV 3 phase openload diag 10 times
  note  : 
*/		

static uint8 DIAG_3PhaseOpenLoad_Check(void)
{
	uint8 u8_3PhaseOpenloadCnt;
	uint8 u8_TmpCnt=0u;
	u8_3PhaseOpenloadCnt=0u;
	
	for( u8_TmpCnt=0u; u8_TmpCnt<DIAG_OPENLOAD_CHECKMAX; u8_TmpCnt++)
	{
		if (BDRV_Diag_OpenLoad() == true)    
		{
			u8_3PhaseOpenloadCnt++;
		}
		else
		{
			break;
		}
	}
	return (u8_3PhaseOpenloadCnt);
}

void DIAG_VDDFault_Handle(void)
{
	if(0u == Su8_DIAG_VDD_1V5OVFault)
	{
		if(1u == Gu8_DIAG_VDD_1V5OV)
		{
			Gu8_DIAG_VDD_1V5OV=0u;
			Su8_DIAG_VDD_1V5OVCnt++;
			if(Su8_DIAG_VDD_1V5OVCnt>=5u)
			{
				Su8_DIAG_VDD_1V5OVFault=1u;
			}
		}
		else
		{
			if(Su8_DIAG_VDD_1V5OVCnt>0u)
			{
				Su8_DIAG_VDD_1V5OVCnt--;
			}
		}
	}

	if(0u == Su8_DIAG_VDD_5VOVFault)
	{
		if(1u == Gu8_DIAG_VDD_5VOV)
		{
			Gu8_DIAG_VDD_5VOV=0u;
			Su8_DIAG_VDD_5VOVCnt++;
			if(Su8_DIAG_VDD_5VOVCnt>=5u)
			{
				Su8_DIAG_VDD_5VOVFault=1u;
			}
		}
		else
		{
			if(Su8_DIAG_VDD_5VOVCnt>0u)
			{
				Su8_DIAG_VDD_5VOVCnt--;
			}
		}
	}
}

