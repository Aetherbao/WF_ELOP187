#ifndef PWM_CLAC_H
#define PWM_CLAC_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "PWM_Pwm.h"
#include "ccu6.h"
/*******************************************************************************
**                          Private Type Declarations                         **
*******************************************************************************/
/** This enum orders the motor phases (see #PWM_EvaluateSector) */
typedef enum
{
  PWM_CALC_PHASE_U = 0,     /**< Phase U is placed at 0 deg */
  PWM_CALC_PHASE_V,         /**< Phase V is placed at 120 deg */
  PWM_CALC_PHASE_W,         /**< Phase W is placed at 240 deg */
  PWM_CALC_NUM_OF_PHASES
} ENM_PWM_PHASES;
/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
extern SRAM_GLOBAL_UINT16 Gu16_uPWM_CsaCalibResult_IF;
extern SRAM_GLOBAL_UINT8 Gu8_PWMSectorRaw;/* PWM sector raw value*/
extern SRAM_GLOBAL_UINT16 Gu16_uPWM_PhFstCurr_IF; //phase current monitor first point
extern SRAM_GLOBAL_UINT16 Gu16_uPWM_PhScndCurr_IF;//phase current monitor second point
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void PWM_CalcStart(void);
void PWM_Set_ClacPwmVals(const uint16 Cu16_Duty[PWM_CALC_NUM_OF_PHASES], const uint16 Cu16_Period);
// void MotPwm_get_currentMeasInfo(uint16* compFirMeas, uint16* compSecMeas);
// ENM_PWM_SECTOR MotPwm_get_currentSect(void);//no use
void PWM_Set_CompareRiseValues(void);
void PWM_Set_CompareFallValues(void);
// void PWM_MotorStateChange_Handle(void);
void PWM_3PhStart(void);
void PWM_3PhStop(void);

void PWM_SSM_Init(void);
void PWM_Set_SampleTimer(void);
void PWM_SSM_ReconstructCurr(void);
#endif