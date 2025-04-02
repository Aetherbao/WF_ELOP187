/*
 * motor_control_param.h
 *
 * Declaration of constants related to motor control 
 *
 */
 
 
#include "custom_type_definition.h"

 
 extern const PWM_MODE parPwmMode;

 extern const boolean parFocDcplFlag;
 
 extern const dt_MotTrq_s16p14b0 parTrqInitCond;
 
 extern const sint16 parRefSpdFallSlewRate;
 
 extern const sint16 parRefSpdRisSlewRate;

 extern const dt_MotTrq_s16p14b0 parTrqUpLim;
 
 extern const dt_SpdCtrlPropGain_u16p23b0 parSpdCtrlPropGain;
 
 extern const dt_SpdCtrlIntgGain_u16p22b0 parSpdCtrlIntgGain;
 
 extern const dt_CurrCtrlPropGain_u16p14b0 parQdrtCurrCtrlPropGain;
 
 extern const dt_CurrCtrlPropGain_u16p14b0 parDirCurrCtrlPropGain;
 
 extern const dt_CurrCtrlIntgGain_u16p10b0 parDirCurrCtrlIntgGain;
 
 extern const dt_CurrCtrlIntgGain_u16p10b0 parQdrtCurrCtrlIntgGain;
 
 extern const dt_ElctCurr_s16p7b0 parPhsCurrLim;
 
 extern const uint16 parSpdFiltCoef;
 
 extern const uint16 parEstAngErrCompFreq;
 
 extern const uint16 parSplyCurrLimIntgGain;
 
 extern const dt_OmodFact_u16p15b0 parOmodFact;

 extern const dt_RpmMechSpd_sint16 parMinRefMechSpd;

 extern const dt_RpsElctSpd_s16p3b0 parTurnOffActElctSpd;
