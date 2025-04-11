#ifndef PWM_PWM_H
#define PWM_PWM_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "tle_device.h"
#include "Mem_Mem.h"
/*******************************************************************************
**                          Global Type Declarations                         **
*******************************************************************************/
typedef enum
{
    PWM_PM_FST = 0u, 
    PWM_OM_FST, 
    PWM_PM_SCND, 
    PWM_OM_SCND
} ENM_PWM_INT_TYPE;
/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
extern SRAM_GLOBAL_UINT8 Gu8_PWM_GenerateWaveStatus;/*CCU6 generate wave status*/

extern SRAM_GLOBAL_UINT8 Gu8_PWM_MedFreqTaskStatus;/*enter medium frequency task status,if enter the value is 1*/
extern SRAM_GLOBAL_UINT16 Gu16_ADC_FstCSASample_IF;       /* ADC1_CSA T13 Capture AD */
extern SRAM_GLOBAL_UINT16 Gu16_ADC_ScndCSASample_IF;      /* ADC1_CSA T13 Period AD */      
extern SRAM_GLOBAL_UINT8 Gu8_PWMSector_IF; //PWM sector value
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void PWM_3PHASE_Start(uint16 PWM_rDutyPhaseA_tmp,uint16 PWM_rDutyPhaseB_tmp,uint16 PWM_rDutyPhaseC_tmp);
void PWM_3PHASE_Stop(void);
void PWM_LaunchPWM(void);
void PWM_Set_T12ChannelVal(uint16 u16_ch0,uint16 u16_ch1,uint16 u16_ch2);
void PWM_Set_T13CompareVal(void);
void PWM_Set_T13PeriodVal(uint16 u16_period);
#endif