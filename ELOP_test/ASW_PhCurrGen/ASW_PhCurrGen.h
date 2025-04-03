/*
 * File: ASW_PhCurrGen.h
 *
 * Code generated for Simulink model 'ASW_PhCurrGen'.
 *
 * Model version                  : 6.173
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:34:09 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ASW_PhCurrGen_h_
#define RTW_HEADER_ASW_PhCurrGen_h_
#ifndef ASW_PhCurrGen_COMMON_INCLUDES_
#define ASW_PhCurrGen_COMMON_INCLUDES_
#include "../ASW_share/rtwtypes.h"
#endif                                 /* ASW_PhCurrGen_COMMON_INCLUDES_ */

//#include "ASW_PhCurrGen_types.h"
#include "../ASW_share/custom_type_definition.h"
#include "../ASW_share/motor_control_interface.h"
#include <string.h>

/* Block signals (default storage) */
typedef struct {
  dt_Standardize_s16p15b0 Saturation2; /* '<S57>/Saturation2' */
} B_ASW_PhCurrGen;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  sint16 TappedDelay_DWORK1[19];       /* '<S61>/Tapped Delay' */
  sint32 UnitDelay_DSTATE;             /* '<S44>/Unit Delay' */
  struct {
    uint_T UnitDelay1_DSTATE_m2pk:1;   /* '<S76>/Unit Delay1' */
    uint_T UnitDelay1_DSTATE_ofwc:1;   /* '<S81>/Unit Delay1' */
    uint_T UnitDelay1_DSTATE_jjio:1;   /* '<S44>/Unit Delay1' */
  } bitsForTID1;

  dt_Standardize_s16p15b0 UnitDelay1_DSTATE;/* '<S53>/Unit Delay1' */
  dt_Standardize_s16p15b0 UnitDelay_DSTATE_gwvm;/* '<S30>/Unit Delay' */
  dt_Standardize_s16p15b0 UnitDelay2_DSTATE;/* '<S63>/Unit Delay2' */
  sint16 UnitDelay_DSTATE_cvdq;        /* '<S76>/Unit Delay' */
  dt_Standardize_s16p15b0 UnitDelay_DSTATE_evau;/* '<S81>/Unit Delay' */
  sint16 UnitDelay1_DSTATE_lr2t;       /* '<S30>/Unit Delay1' */
  ENM_STRTUP_TRQ_STATUS UnitDelay19_DSTATE;/* '<S53>/Unit Delay19' */
  uint8 is_active_c2_ASW_PhCurrGen;    /* '<S63>/sfc_TrqDecre' */
  uint8 is_c2_ASW_PhCurrGen;           /* '<S63>/sfc_TrqDecre' */
  uint8 is_active_c1_ASW_PhCurrGen;    /* '<S53>/sfc_MotoSTMHybr' */
  uint8 is_c1_ASW_PhCurrGen;           /* '<S53>/sfc_MotoSTMHybr' */
} DW_ASW_PhCurrGen;

/* Real-time Model Data Structure */
struct tag_RTM_ASW_PhCurrGen {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8 TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_ASW_PhCurrGen ASW_PhCurrGen_B;

/* Block states (default storage) */
extern DW_ASW_PhCurrGen ASW_PhCurrGen_DW;

/* External data declarations for dependent source files */
extern const BUS_PHCURRGEN_SLW_TASK_IN ASW_PhCurrGen_rtZBUS_PHCURRGEN_;/* BUS_PHCURRGEN_SLW_TASK_IN ground */
extern const BUS_PHCURRGEN_SLW_TASK_OUT
  ASW_PhCurrGen_rtZBUS_PHCURRGEN_SLW_TASK_OUT;/* BUS_PHCURRGEN_SLW_TASK_OUT ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BUS_PHCURRGEN_SLW_TASK_IN busPhCurrGen_SlwTaskIn;/* '<Root>/busPhCurrGen_SlwTaskIn' */
extern BUS_PHCURRGEN_SLW_TASK_OUT busPhCurrGen_SlwTaskOut;/* '<S56>/Bus Creator1' */

/* Model entry point functions */
extern void ASW_PhCurrGen_Init(void);
extern void ASW_PhCurrGen_step(void);

/* Real-time Model object */
extern RT_MODEL_ASW_PhCurrGen *const ASW_PhCurrGen_M;

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
 * '<Root>' : 'ASW_PhCurrGen'
 * '<S1>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask'
 * '<S2>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc'
 * '<S3>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl'
 * '<S4>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_MotoSTM'
 * '<S5>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_SlwTaskIn'
 * '<S6>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_SlwTaskOut'
 * '<S7>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpPrcdChk'
 * '<S8>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc'
 * '<S9>'   : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc'
 * '<S10>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_CfgPar_0'
 * '<S11>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_Cnvr_1'
 * '<S12>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_Cnvr_2'
 * '<S13>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_Cnvr_3'
 * '<S14>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_Cnvr_4'
 * '<S15>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_Cnvr_5'
 * '<S16>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_CfgPar_0/vss_SaturationActivation'
 * '<S17>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/rss_RefCurrCalc/sss_RefCurrCalc/lib_CfgPar_0/vss_SaturationActivation/vss_SaturationRequired'
 * '<S18>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr'
 * '<S19>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/Compare To Constant'
 * '<S20>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_CfgPar_1'
 * '<S21>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_CfgPar_2'
 * '<S22>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0'
 * '<S23>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/sss_InitTqSel'
 * '<S24>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_CfgPar_1/vss_SaturationActivation'
 * '<S25>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_CfgPar_1/vss_SaturationActivation/vss_SaturationRequired'
 * '<S26>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_CfgPar_2/vss_SaturationActivation'
 * '<S27>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_CfgPar_2/vss_SaturationActivation/vss_SaturationRequired'
 * '<S28>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/lib_Conversion_2'
 * '<S29>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes'
 * '<S30>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup'
 * '<S31>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_Conversion_0'
 * '<S32>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_Conversion_2'
 * '<S33>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_Conversion_3'
 * '<S34>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1'
 * '<S35>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DynamicSaturator_0'
 * '<S36>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/sss_ProportionalAction'
 * '<S37>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode'
 * '<S38>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode/vss_IntergralControlMode'
 * '<S39>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode/vss_IntergralControlMode/lib_Conversion_1'
 * '<S40>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode/vss_IntergralControlMode/lib_Conversion_2'
 * '<S41>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode/vss_IntergralControlMode/lib_Conversion_3'
 * '<S42>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode/vss_IntergralControlMode/lib_Conversion_4'
 * '<S43>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode/vss_IntergralControlMode/lib_DynamicSaturator_1'
 * '<S44>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/lib_DiscreteTimeIntegrator_1/vss_IntegrationMode/vss_IntergralControlMode/lib_ResettableUnitDelay_genInp'
 * '<S45>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/sss_ProportionalAction/lib_Conversion_1'
 * '<S46>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/sss_ProportionalAction/lib_Conversion_3'
 * '<S47>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/lib_DisTiPICtl_0/vss_PIControllerModes/vss_SaturationBackCalcAntiWindup/sss_ProportionalAction/lib_DynamicSaturator_0'
 * '<S48>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/sss_InitTqSel/Compare To Constant1'
 * '<S49>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/sss_InitTqSel/sas_ClsLpCs'
 * '<S50>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/sss_InitTqSel/sas_DflCs'
 * '<S51>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/sss_InitTqSel/sas_OffCs'
 * '<S52>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_ElecSpdCtl/rss_ElecSpdCtlHybr/sss_InitTqSel/sas_OpnLpCs'
 * '<S53>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_MotoSTM/rss_MotoSTMHybr'
 * '<S54>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_MotoSTM/rss_MotoSTMHybr/sfc_MotoSTMHybr'
 * '<S55>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_SlwTaskIn/sss_SlwTaskInHybr'
 * '<S56>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_SlwTaskOut/sss_SlwTaskOutSenl'
 * '<S57>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpPrcdChk/rss_StrtUpPrcdChkNeed'
 * '<S58>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpPrcdChk/rss_StrtUpPrcdChkNeed/Compare To Constant'
 * '<S59>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpPrcdChk/rss_StrtUpPrcdChkNeed/lib_Cnvr_2'
 * '<S60>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpPrcdChk/rss_StrtUpPrcdChkNeed/lib_Cnvr_3'
 * '<S61>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpPrcdChk/rss_StrtUpPrcdChkNeed/lib_MAF_0'
 * '<S62>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpPrcdChk/rss_StrtUpPrcdChkNeed/lib_MAF_0/lib_Conversion_1'
 * '<S63>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed'
 * '<S64>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/Compare To Constant1'
 * '<S65>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/Compare To Constant12'
 * '<S66>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_Cnvr_1'
 * '<S67>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0'
 * '<S68>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0'
 * '<S69>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/sfc_TrqDecre'
 * '<S70>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0/vss_IntegrationMode'
 * '<S71>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode'
 * '<S72>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_Conversion_1'
 * '<S73>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_Conversion_2'
 * '<S74>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_Conversion_3'
 * '<S75>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_DynamicSaturator_1'
 * '<S76>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_DisTiInteg_0/vss_IntegrationMode/vss_GenericSignalMode/lib_ResettableUnitDelay_1'
 * '<S77>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/Chart'
 * '<S78>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/Subsystem'
 * '<S79>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_DecrementFlagTrigger'
 * '<S80>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_IncrementFlagTrigger'
 * '<S81>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/Subsystem/lib_ResettableUnitDelay_1'
 * '<S82>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_DecrementFlagTrigger/lib_Conversion_1'
 * '<S83>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_DecrementFlagTrigger/lib_Conversion_2'
 * '<S84>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_DecrementFlagTrigger/lib_Conversion_3'
 * '<S85>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_IncrementFlagTrigger/lib_Conversion_1'
 * '<S86>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_IncrementFlagTrigger/lib_Conversion_2'
 * '<S87>'  : 'ASW_PhCurrGen/PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/lib_RateLim_0/sss_IncrementFlagTrigger/lib_Conversion_3'
 */
#endif                                 /* RTW_HEADER_ASW_PhCurrGen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
