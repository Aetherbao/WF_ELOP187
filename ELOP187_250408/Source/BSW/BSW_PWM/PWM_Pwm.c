/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "PWM_Pwm.h"
#include "PWM_Clac.h"
#include "ADC_Meas.h"
#include "BDRV_BDRV.h"

#include "MID_Interface.h"

/*******************************************************************************
**                          Private Type Declarations                         **
*******************************************************************************/
typedef enum
{
    PWM_SAMPLE_NONE = 0u, 
    PWM_SAMPLE_SUCCESS,
    PWM_SAMPLE_FAIL
} ENM_PWM_HIGHFREQ_STATUS;
/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
#define PWM_PERIOD                  (1249u)
#define PWM_50PERCENT_DUTY          (16384u)
#define PWM_INT_PM                  (1u)
#define PWM_INT_OM                  (2u)

/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
SRAM_GLOBAL_UINT8 Gu8_PWM_GenerateWaveStatus;/*CCU6 generate wave status  [0-3]*/

SRAM_GLOBAL_UINT8 Gu8_PWM_MedFreqTaskStatus;/*enter medium frequency task status,if enter the value is 1*/
SRAM_GLOBAL_UINT16 Gu16_ADC_FstCSASample_IF;       /* ADC1_CSA T13 Capture AD */
SRAM_GLOBAL_UINT16 Gu16_ADC_ScndCSASample_IF;      /* ADC1_CSA T13 Period AD */      
SRAM_GLOBAL_UINT8 Gu8_PWMSector_IF; //PWM sector value
/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

static SRAM_GLOBAL_UINT8 Su8_PWM_EnterT12OMCnt;/* this value is used to monitor T12 OM interupt enter time*/
static SRAM_GLOBAL_UINT8 Su8_PWM_PM_SampleStatus;/*enter high frequency task status[0-2]*/
static SRAM_GLOBAL_UINT16 Su16_ADC_FstCSASampleRaw;/*first current collect value*/

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

static void PWM_INT_StateHandle(uint8 u8_IntType);
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

// void PWM_3PHASE_Stop(void)
// {
// 	/* Stop motor */
//   /* Disable bridge */
//     BDRV_ConfigBridgeOff();
    
//     /* Stop PWM */
//     CCU6_StopTmr_T12();
//     PWM_Set_T12ChannelVal(0u,0u,0u);

//     /* Clear existing BDRV interrupt status */
//     BDRV_Clr_Sts(0xFFFFFFFF);
// }

void PWM_LaunchPWM(void)
{
    uint16 u16_ComparePhaseA_Tmp;
    uint16 u16_ComparePhaseB_Tmp;
    uint16 u16_ComparePhaseC_Tmp;	

  // Reset timer value
    CCU6_T12_Rst();

    // PWM_3PHASE_Start(PWM_50PERCENT_DUTY,PWM_50PERCENT_DUTY,PWM_50PERCENT_DUTY);

    u16_ComparePhaseA_Tmp=1250u-PWM_50PERCENT_DUTY*1250u/1000u;
    u16_ComparePhaseB_Tmp=2500u-PWM_50PERCENT_DUTY*1250u/1000u;
    u16_ComparePhaseC_Tmp=1250u-PWM_50PERCENT_DUTY*1250u/1000u;

    CCU6_StartTmr_T12();/*Start CCU6 Timer T12*/
    
    PWM_Set_T12ChannelVal(u16_ComparePhaseA_Tmp,u16_ComparePhaseB_Tmp,u16_ComparePhaseC_Tmp);
    // /*Load Channel x compare value to the shadow register*/
    // CCU6_LoadShadowRegister_CC60(u16_ComparePhaseA_Tmp);
    // CCU6_LoadShadowRegister_CC61(u16_ComparePhaseB_Tmp);
    // CCU6_LoadShadowRegister_CC62(u16_ComparePhaseC_Tmp);
    // /*enables T12 Shadow Transfer*/
    // CCU6_EnableST_T12();
    /* Enable bridge (after starting PWM according to UM) */
    BDRV_ConfigBridgePWM();

}

void PWM_Set_T12ChannelVal(uint16 u16_ch0,uint16 u16_ch1,uint16 u16_ch2)
{
      // Write the Shadow registers
  CCU6_LoadShadowRegister_CC60(u16_ch0);
  CCU6_LoadShadowRegister_CC61(u16_ch1);
  CCU6_LoadShadowRegister_CC62(u16_ch2);

  // Trigger the Shadow Transfer
  CCU6_EnableST_T12();
}

void PWM_Set_T13CompareVal(void)
{
    CCU6_LoadShadowRegister_CC63((uint16)1);
}

void PWM_Set_T13PeriodVal(uint16 u16_period)
{
    CCU6_T13_Period_Value_Set(u16_period);
    CCU6_EnableST_T13();
}

/*brief : Timer12 One-Match Interrupt Call Back
  note  : 
*/
void ISR_T12_OneMatch(void)//62.5us
{
    

    PWM_Set_CompareFallValues();
    
    // PWM_INT_StateHandle(PWM_INT_OM);
    if(PWM_OM_FST == Gu8_PWM_GenerateWaveStatus)
    {
        Gu8_PWM_GenerateWaveStatus=PWM_PM_SCND;
        Su8_PWM_PM_SampleStatus = (Su8_PWM_PM_SampleStatus<<1);//0x02
    }
    else if(PWM_OM_SCND == Gu8_PWM_GenerateWaveStatus)
    {
        Gu8_PWM_GenerateWaveStatus=PWM_PM_FST;
        Su8_PWM_PM_SampleStatus = (Su8_PWM_PM_SampleStatus<<1);//0x08
    }

    Su8_PWM_EnterT12OMCnt++;

    if(Su8_PWM_EnterT12OMCnt>=8)
    {
        Su8_PWM_EnterT12OMCnt=0;
        TIMER21_Start();/*    every 500us will trigger this-lcj */
    }
    
}


void ISR_T12_PeriodMatch(void)
{
    static uint16 Su16_Duty[3] = {0}; 
	uint16 u16_CSAAD_Tmp=0u;
    // PWM_INT_StateHandle(PWM_INT_PM);
    if(PWM_PM_FST == Gu8_PWM_GenerateWaveStatus)
    {
        if (ADC1_GetChResult(&u16_CSAAD_Tmp, ADC1_CSA) == true)
        {/*(4 == Su8_PWM_PM_SampleStatus) means get CSA AD value is success in '(Gu8_PWM_GenerateWaveStatus==2)' this branch */
            if((0x08 == Su8_PWM_PM_SampleStatus)&&(0u == Gu8_PWM_MedFreqTaskStatus))
            {
                Gu16_ADC_FstCSASample_IF=Su16_ADC_FstCSASampleRaw;
                Gu16_ADC_ScndCSASample_IF=u16_CSAAD_Tmp;
                Gu8_PWMSector_IF=Gu8_PWMSectorRaw;
            }
        }
        Gu8_PWM_GenerateWaveStatus=PWM_OM_FST;
        Interface_FR_Task();
        Interface_Set_DutyCycle(&Su16_Duty[0]);
        PWM_Set_ClacPwmVals(&Su16_Duty[0], PWM_PERIOD);
        Su8_PWM_PM_SampleStatus=0x01;
    }
    else if(PWM_PM_SCND == Gu8_PWM_GenerateWaveStatus)
    {
        if (ADC1_GetChResult(&u16_CSAAD_Tmp, ADC1_CSA) == true)
        {
            Su16_ADC_FstCSASampleRaw=u16_CSAAD_Tmp;
            Su8_PWM_PM_SampleStatus = (Su8_PWM_PM_SampleStatus<<1);//0x04
        }
        Gu8_PWM_GenerateWaveStatus=PWM_OM_SCND;
    }
	
	PWM_Set_CompareRiseValues();
    PWM_Set_SampleTimer();
	
}
