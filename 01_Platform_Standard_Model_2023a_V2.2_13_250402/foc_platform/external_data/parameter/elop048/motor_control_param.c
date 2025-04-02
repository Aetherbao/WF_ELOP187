/*
 * motor_control_param.c
 *
 * Definition of constants related to motor control 
 *
 */
 
#include "custom_type_definition.h"
#include "motor_control_param.h"
 
const PWM_MODE parPwmMode = S3APWM;

const boolean parFocDcplFlag = false;

const dt_MotTrq_s16p14b0 parTrqInitCond = 0;

const sint16 parRefSpdFallSlewRate = -10000;
 
const sint16 parRefSpdRisSlewRate = 10000;

const dt_MotTrq_s16p14b0 parTrqUpLim = 13107;
 
const dt_SpdCtrlPropGain_u16p23b0 parSpdCtrlPropGain = 8000;
 
const dt_SpdCtrlIntgGain_u16p22b0 parSpdCtrlIntgGain = 6000;
 
const dt_CurrCtrlPropGain_u16p14b0 parQdrtCurrCtrlPropGain = 420;
 
const dt_CurrCtrlPropGain_u16p14b0 parDirCurrCtrlPropGain = 291;
 
const dt_CurrCtrlIntgGain_u16p10b0 parDirCurrCtrlIntgGain = 1000;
 
const dt_CurrCtrlIntgGain_u16p10b0 parQdrtCurrCtrlIntgGain = 1000;
 
const dt_ElctCurr_s16p7b0 parPhsCurrLim = 8320;
 
const uint16 parSpdFiltCoef = 13107;
 
const uint16 parEstAngErrCompFreq = 11312;
 
const uint16 parSplyCurrLimIntgGain = 12800;
 
const dt_OmodFact_u16p15b0 parOmodFact = 32768;

const dt_RpmMechSpd_sint16 parMinRefMechSpd = 100;

const dt_RpsElctSpd_s16p3b0 parTurnOffActElctSpd = 1047;


