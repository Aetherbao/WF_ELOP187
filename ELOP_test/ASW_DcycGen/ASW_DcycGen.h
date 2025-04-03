/*
 * File: ASW_DcycGen.h
 *
 * Code generated for Simulink model 'ASW_DcycGen'.
 *
 * Model version                  : 6.161
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:33:47 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ASW_DcycGen_h_
#define RTW_HEADER_ASW_DcycGen_h_
#ifndef ASW_DcycGen_COMMON_INCLUDES_
#define ASW_DcycGen_COMMON_INCLUDES_
#include "../ASW_share/rtwtypes.h"
#endif                                 /* ASW_DcycGen_COMMON_INCLUDES_ */

//#include "ASW_DcycGen_types.h"
#include "../ASW_share/custom_type_definition.h"
#include "../ASW_share/motor_control_interface.h"
#include <string.h>

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    uint_T UnitDelay1_DSTATE:1;        /* '<S94>/Unit Delay1' */
  } bitsForTID0;

  uint16 UnitDelay_DSTATE;             /* '<S94>/Unit Delay' */
} DW_ASW_DcycGen;

/* Block states (default storage) */
extern DW_ASW_DcycGen ASW_DcycGen_DW;

/* External data declarations for dependent source files */
extern const BUS_DCYCGEN_FST_TASK_IN ASW_DcycGen_rtZBUS_DCYCGEN_FST_;/* BUS_DCYCGEN_FST_TASK_IN ground */
extern const BUS_DCYCGEN_FST_TASK_OUT ASW_DcycGen_rtZBUS_DCYCGEN_FST_TASK_OUT;/* BUS_DCYCGEN_FST_TASK_OUT ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BUS_DCYCGEN_FST_TASK_IN busDcycGen_FstTaskIn;/* '<Root>/busDcycGen_FstTaskIn' */
extern BUS_DCYCGEN_FST_TASK_OUT busDcycGen_FstTaskOut;/* '<S82>/Bus Creator1' */

/* Model entry point functions */
extern void ASW_DcycGen_Init(void);
extern void ASW_DcycGen_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ASW_DcycGen'
 * '<S1>'   : 'ASW_DcycGen/DcycGen_FstTask'
 * '<S2>'   : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc'
 * '<S3>'   : 'ASW_DcycGen/DcycGen_FstTask/vrs_FstTaskIn'
 * '<S4>'   : 'ASW_DcycGen/DcycGen_FstTask/vrs_FstTaskOut'
 * '<S5>'   : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc'
 * '<S6>'   : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl'
 * '<S7>'   : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM'
 * '<S8>'   : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM'
 * '<S9>'   : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM'
 * '<S10>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM'
 * '<S11>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl'
 * '<S12>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/lib_u16p15b0_1'
 * '<S13>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/lib_u16r15b0_1'
 * '<S14>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/lib_u16r15b0_2'
 * '<S15>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator'
 * '<S16>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/lib_s16p15b0_1'
 * '<S17>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/lib_s16p15b0_2'
 * '<S18>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/lib_u16n0b0_1'
 * '<S19>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/lib_u16p15b0_1'
 * '<S20>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/lib_u16r15b0_1'
 * '<S21>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/lib_u16r15b0_2'
 * '<S22>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/sss_DutyCycleMapper'
 * '<S23>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_1'
 * '<S24>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_Dfl/lib_DycWvfGenr_dfl/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_2'
 * '<S25>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3'
 * '<S26>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/lib_u16p15b0_1'
 * '<S27>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/lib_u16r15b0_1'
 * '<S28>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/lib_u16r15b0_2'
 * '<S29>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator'
 * '<S30>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/lib_s16p15b0_1'
 * '<S31>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/lib_s16p15b0_2'
 * '<S32>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/lib_u16n0b0_1'
 * '<S33>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/lib_u16p15b0_1'
 * '<S34>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/lib_u16r15b0_1'
 * '<S35>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/lib_u16r15b0_2'
 * '<S36>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/sss_DutyCycleMapper'
 * '<S37>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_1'
 * '<S38>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_DisnMinPWM/lib_DycWvfGenr_3/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_2'
 * '<S39>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2'
 * '<S40>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/lib_u16p15b0_1'
 * '<S41>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/lib_u16r15b0_1'
 * '<S42>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/lib_u16r15b0_2'
 * '<S43>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator'
 * '<S44>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/lib_s16p15b0_1'
 * '<S45>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/lib_s16p15b0_2'
 * '<S46>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/lib_u16n0b0_1'
 * '<S47>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/lib_u16p15b0_1'
 * '<S48>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/lib_u16r15b0_1'
 * '<S49>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/lib_u16r15b0_2'
 * '<S50>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/sss_DutyCycleMapper'
 * '<S51>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_1'
 * '<S52>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SVPWM/lib_DycWvfGenr_2/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_2'
 * '<S53>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1'
 * '<S54>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/lib_u16p15b0_1'
 * '<S55>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/lib_u16r15b0_1'
 * '<S56>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/lib_u16r15b0_2'
 * '<S57>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator'
 * '<S58>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/lib_s16p15b0_1'
 * '<S59>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/lib_s16p15b0_2'
 * '<S60>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/lib_u16n0b0_1'
 * '<S61>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/lib_u16p15b0_1'
 * '<S62>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/lib_u16r15b0_1'
 * '<S63>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/lib_u16r15b0_2'
 * '<S64>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/sss_DutyCycleMapper'
 * '<S65>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_1'
 * '<S66>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuAddThrdHarmPWM/lib_DycWvfGenr_1/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_2'
 * '<S67>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0'
 * '<S68>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/lib_u16p15b0_1'
 * '<S69>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/lib_u16r15b0_1'
 * '<S70>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/lib_u16r15b0_2'
 * '<S71>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator'
 * '<S72>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/lib_s16p15b0_1'
 * '<S73>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/lib_s16p15b0_2'
 * '<S74>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/lib_u16n0b0_1'
 * '<S75>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/lib_u16p15b0_1'
 * '<S76>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/lib_u16r15b0_1'
 * '<S77>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/lib_u16r15b0_2'
 * '<S78>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/sss_DutyCycleMapper'
 * '<S79>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_1'
 * '<S80>'  : 'ASW_DcycGen/DcycGen_FstTask/rss_DycCalc/sas_SinuPWM/lib_DycWvfGenr_0/sss_DutyCycleCalculator/sss_DutyCycleMapper/lib_s16p10b0_2'
 * '<S81>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_FstTaskIn/sss_FstTaskInSens'
 * '<S82>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_FstTaskOut/sss_FstTaskOutSens'
 * '<S83>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens'
 * '<S84>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/Compare To Constant'
 * '<S85>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_Cnvr_1'
 * '<S86>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_Cnvr_2'
 * '<S87>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0'
 * '<S88>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0/vss_IntegrationMode'
 * '<S89>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode'
 * '<S90>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_Conversion_1'
 * '<S91>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_Conversion_2'
 * '<S92>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_Conversion_3'
 * '<S93>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_DynamicSaturator_1'
 * '<S94>'  : 'ASW_DcycGen/DcycGen_FstTask/vrs_ModulElecAgCalc/rss_ModulElecAgCalcSens/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_ResettableUnitDelay_1'
 */
#endif                                 /* RTW_HEADER_ASW_DcycGen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
