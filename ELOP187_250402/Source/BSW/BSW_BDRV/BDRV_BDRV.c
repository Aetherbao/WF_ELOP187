/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "BDRV_BDRV.h"
#include "bdrv.h"
#include "ADC_Meas.h"
#include "DIAG_Handle.h"
#include "Task_Task.h"
#include "ASW_AST.h"
#include "MID_Interface.h"
/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
ENM_BDRV_INITSTATE GenmBDRV_InitState;
SRAM_GLOBAL_UINT8 Gu8_PWM_MotorRunStatus;      /*PWM work status 1:run  0:stop */
/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/
SRAM_GLOBAL_UINT8 Su8_BDRV_InitState;
SRAM_GLOBAL_UINT8 Su8_BDRV_InitCnt;

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
#define BDRV_INIT_DELAY				  ((uint8)10)//100ms
/*******************************************************************************
**                         Private Function Definitions                        **
*******************************************************************************/
static void BDRV_PWMOff(void);
static void BDRV_PWMOn(void);
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void BDRV_ConfigBridgePWM(void)
{
    BDRV_Set_Bridge(Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM);
}

// void BDRV_ConfigBridgeOff(void)
// {
//     BDRV_Set_Bridge(Ch_Off, Ch_Off, Ch_Off, Ch_Off, Ch_Off, Ch_Off);
// }

void BDRV_Clr_OC_STS(void)
{/*   0x400UL  0x800UL  0x4000UL  0x1000UL  0x2000UL  0x8000UL   */
    BDRV_Clr_Sts(LS1_OC | LS2_OC | LS3_OC | HS1_OC | HS2_OC | HS3_OC);//0xFC00
}


void BDRV_Init_Check(void)
{
    if((BDRV_INIT_IDLE == GenmBDRV_InitState) && (Gu16_uADCVSD_IF>7000u))
    {
        BDRV_Init();
        BDRV_Clr_Sts((uint32)0xFFFFFFFF);
        GenmBDRV_InitState = BDRV_INIT_STEP1;
        Su8_BDRV_InitCnt = BDRV_INIT_DELAY;
    }

    if(BDRV_INIT_STEP1 == GenmBDRV_InitState)
    {
        if(0u != Su8_BDRV_InitCnt)
        {
            Su8_BDRV_InitCnt--;
        }
        else
        {
            DIAG_3PhaseOpenLoadFault_Handle();
            /* Clear existing BDRV interrupt status */
            BDRV_Clr_Sts((uint32)0xFFFFFFFF);
            Task_StartupTask();    /*start send wave and init model parameter*/
            GenmBDRV_InitState = BDRV_INIT_DONE;
        }
    }
}

static void BDRV_PWMOff(void)
{
    BDRV_Set_Bridge(Ch_Off, Ch_Off, Ch_Off, Ch_Off, Ch_Off, Ch_Off);
    BDRV_Clr_Sts((uint32)0xFFFFFFFF);
    Gu8_PWM_MotorRunStatus = BDRV_OUTPUT_CLOSE;
}

static void BDRV_PWMOn(void)
{
    BDRV_Clr_Sts((uint32)0xFFFFFFFF);
    BDRV_Set_Bridge(Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM);
    Gu8_PWM_MotorRunStatus = BDRV_OUTPUT_OPEN;
}

void BDRV_StateSwitch(void)
{
    if((BDRV_INIT_DONE == GenmBDRV_InitState) && (Gu16_uADCVSD_IF>7000u))
    {
        if(1u == Gu8_flgShOffflg) //OBD error  busAST_SlowRateTaskInp.bolFaltTurnOffFlag
        {
            if(BDRV_OUTPUT_OPEN == Gu8_PWM_MotorRunStatus)//when OBD error ,if BDRV open,then close BDRV
            {
                BDRV_PWMOff();
            }
        }
        else
        {
            if(BDRV_OUTPUT_CLOSE == Gu8_PWM_MotorRunStatus)//when OBD is not error ,if BDRV close ,then open BDRV
            {
                BDRV_PWMOn();
            }
        }
    }
}



