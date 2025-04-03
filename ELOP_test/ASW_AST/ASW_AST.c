/*
 * File: ASW_AST.c
 *
 * Code generated for Simulink model 'ASW_AST'.
 *
 * Model version                  : 6.236
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Mar 25 10:37:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ASW_AST.h"
#include "../ASW_share/rtwtypes.h"
#include "ASW_AST_private.h"
#include <string.h>
#include "../ASW_share/motor_control_interface.h"
#include "../ASW_share/custom_type_definition.h"
#include "../ASW_share/mul_ssu32_hiSR.h"
#include "../ASW_share/look2_is16lu32n16tu16_binlcse.h"
#include "../ASW_share/div_nde_s32_floor.h"
#include "../ASW_share/mul_ssu32_loSR.h"
#include "../ASW_share/look1_iu8lu32n16ts16Ds32_binlcs.h"
#include "../ASW_share/look1_iu16lu32n16ts16D_2s4GBl96.h"
#include "../ASW_par/motor_control_param.h"
#include "../ASW_par/motor_param.h"

/* Named constants for Chart: '<S75>/sfc_PhiModeStateMachine' */
#define IN_HYBRID                      ((uint8)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8)0U)
#define IN_SENSOR                      ((uint8)2U)
#define IN_SENSORLESS                  ((uint8)3U)

/* Named constants for Chart: '<S78>/sfc_OpnLpRefElecSpdConf' */
#define IN_ALGN_SPD                    ((uint8)1U)
#define IN_STRTUP_SPD                  ((uint8)2U)

/* Named constants for Chart: '<S137>/sfc_SensAgCalibSTM' */
#define IN_ALIGN_ALPHA_PHASE1          ((uint8)1U)
#define IN_ALIGN_ALPHA_PHASE2          ((uint8)2U)
#define IN_ALIGN_BETA_PHASE            ((uint8)3U)
#define IN_CALIBFAIL                   ((uint8)4U)
#define IN_SUCCESS                     ((uint8)5U)
#define IN_WAIT_ALPHA1                 ((uint8)6U)
#define IN_WAIT_ALPHA2                 ((uint8)7U)
#define IN_WAIT_BETA                   ((uint8)8U)

/* Named constants for Chart: '<S164>/sfc_SysSTM' */
#define IN_LIMPHOME                    ((uint8)1U)
#define IN_NORMAL                      ((uint8)2U)
#define IN_RUN                         ((uint8)1U)
#define IN_STANDBY                     ((uint8)2U)
#define IN_SYSFAIL                     ((uint8)3U)
#define IN_SYSINIT                     ((uint8)4U)
#define IN_SYSSLEEP                    ((uint8)5U)

const BUS_AST_SLW_TASK_OUT ASW_AST_rtZBUS_AST_SLW_TASK_OUT = {
  0,                                   /* s16_iEstSplyCurr */
  0,                                   /* s16_ampActPhCurrAmp */
  0,                                   /* s16_trqPosSCDCalibRefTq */
  0U,                                  /* u16_phiPosSCDCalibElecAg */
  false,                               /* bol_flgPosSCDCalibSucFlg */
  0U,                                  /* u16_ADSensMechAgDvt */
  CALIBFAIL,                           /* enm_stPosSCDCalibSt */
  false,                               /* bol_flgPosSCDCalibPermFail */
  0,                                   /* s16_trqRefTqLim */
  0,                                   /* s16_nRmpRefElecSpd */
  false,                               /* bol_flgShOffFlg */
  0,                                   /* s16_nRefElecSpd */
  SYSINIT,                             /* enm_stSysSt */
  0,                                   /* s16_pwrSplyElecPwr */
  SENSOR,                              /* enm_modeAgEvalMode */
  0U,                                  /* u16_phiSensElecAgDvt */
  0                                    /* s16_nActElecSpdComFlt */
};                                     /* BUS_AST_SLW_TASK_OUT ground */

/* Exported block signals */
BUS_AST_SLW_TASK_IN busAST_SlwTaskIn;  /* '<Root>/busAST_SlwTaskIn' */
BUS_AST_SLW_TASK_OUT busAST_SlwTaskOut;/* '<S163>/Bus Creator1' */

/* Block signals (default storage) */
B_ASW_AST ASW_AST_B;

/* Block states (default storage) */
DW_ASW_AST ASW_AST_DW;

/* Real-time model */
static RT_MODEL_ASW_AST ASW_AST_M_;
RT_MODEL_ASW_AST *const ASW_AST_M = &ASW_AST_M_;
static void rate_scheduler(void);
const BUS_AST_SLW_TASK_IN ASW_AST_rtZBUS_AST_SLW_TASK_IN = { 0,/* s16_nComRefMechSpd */
  0,                                   /* s16_nActElecSpd */

  { 0, 0 },                            /* s16_uModulDaxQaxVltg */
  0U,                                  /* u16_uSplyVltg */

  { 0, 0 },                            /* s16_iActDaxQaxCurr */
  0U,                                  /* enm_stMotoSt */
  false,                               /* bol_enPosSCDCalibEnFlg */
  0U,                                  /* u16_phiSensActElecAg */
  0U,                                  /* u8_stMaxFaltLvl */

  { false,                             /* bol_flgPhCurrHiLvl1Flg */
    false,                             /* bol_flgHWOvrCurrFlg */
    false,                             /* bol_flgSplyVltgLoLvl1Flg */
    false,                             /* bol_flgSplyVltgLoLvl2Flg */
    false,                             /* bol_flgSplyVltgHiLvl1Flg */
    false,                             /* bol_flgPwrTubPCBTempHiLvl1Flg */
    false,                             /* bol_flgPwrTubPCBTempHiLvl2Flg */
    false,                             /* bol_flgMotoTempHiLvl1Flg */
    false,                             /* bol_flgMotoTempHiLvl2Flg */
    false,                             /* bol_flgComFaltFlg */
    false,                             /* bol_flgMotoStallPermFlg */
    false,                             /* bol_flgMotoStallTmpFlg */
    false,                             /* bol_flgNoLdFlg */
    false,                             /* bol_flgBattPwrHiLvl1Flg */
    false,                             /* bol_flgMotoSpdHiLvl1Flg */
    false,                             /* bol_flgMotoSpdLoLvl1Flg */
    false,                             /* bol_flgCtlBrdVltgLoLvl1Flg */
    false,                             /* bol_flgCtlBrdVltgHiLvl1Flg */
    false,                             /* bol_flgGDVltgLoLvl1Flg */
    false,                             /* bol_flgGDVltgHiLvl1Flg */
    false,                             /* bol_flgChipFaltFlg */
    false,                             /* bol_flgPhiSensFaltFlg */
    false,                             /* bol_flgPhCurrSensFaltFlg */
    false,                             /* bol_flgPwrTubPCBTempSensFaltFlg */
    false,                             /* bol_flgMotoTempSensFaltFlg */
    false,                             /* bol_flgBusOffFaltFlg */
    false,                             /* bol_flgCrashFaltFlg */
    false,                             /* bol_flgMosOpnCirFaltFlg */
    false,                             /* bol_flgReserved4Flg */
    false                              /* bol_flgReserved5Flg */
  },                                   /* busOBD_FaltSt */
  0,                                   /* s16_nFaltRefMechSpd */
  0,                                   /* s16_trqFaltRefTqLim */
  0U,                                  /* u8_modeMCUOpMode */
  40U,                                 /* u8_tPCBTempSubs */
  false,                               /* bol_flgOvrTstCtlUDS2F */
  false,                               /* bol_flgPhiSensFaltRawFlg */
  0U,                                  /* u8_FrzFrmSaveFlg */
  false                                /* bol_flgSlepEn */
};

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ASW_AST_M->Timing.TaskCounters.TID[1])++;
  if ((ASW_AST_M->Timing.TaskCounters.TID[1]) > 79) {/* Sample time: [0.01s, 0.0s] */
    ASW_AST_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S92>/Chart'
 *    '<S93>/Chart'
 *    '<S139>/Chart'
 */
void ASW_AST_Chart_Init(boolean *rty_lb_noRatLimReq, boolean
  *rty_lb_incrRatLimReq, boolean *rty_lb_decrRatLimReq)
{
  *rty_lb_noRatLimReq = false;
  *rty_lb_incrRatLimReq = false;
  *rty_lb_decrRatLimReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S92>/Chart'
 *    '<S93>/Chart'
 *    '<S139>/Chart'
 */
void ASW_AST_Chart(boolean rtu_lb_incrRatLimOn, boolean rtu_lb_decrRatLimOn,
                   boolean *rty_lb_noRatLimReq, boolean *rty_lb_incrRatLimReq,
                   boolean *rty_lb_decrRatLimReq)
{
  /* Chart: '<S92>/Chart' */
  /* Gateway: lib_RateLimiter_YXQ_0/Chart */
  /* During: lib_RateLimiter_YXQ_0/Chart */
  /* Entry Internal: lib_RateLimiter_YXQ_0/Chart */
  /* Transition: '<S97>:24' */
  if ((!rtu_lb_incrRatLimOn) && rtu_lb_decrRatLimOn) {
    /* Transition: '<S97>:31' */
    /* Transition: '<S97>:34' */
    *rty_lb_noRatLimReq = false;
    *rty_lb_incrRatLimReq = false;
    *rty_lb_decrRatLimReq = true;

    /* Transition: '<S97>:36' */

    /* Transition: '<S97>:27' */
  } else if (rtu_lb_incrRatLimOn && (!rtu_lb_decrRatLimOn)) {
    /* Transition: '<S97>:5' */
    /* Transition: '<S97>:7' */
    *rty_lb_noRatLimReq = false;
    *rty_lb_incrRatLimReq = true;
    *rty_lb_decrRatLimReq = false;

    /* Transition: '<S97>:8' */
  } else {
    /* Transition: '<S97>:9' */
    *rty_lb_noRatLimReq = true;
    *rty_lb_incrRatLimReq = false;
    *rty_lb_decrRatLimReq = false;

    /* Transition: '<S97>:29' */
  }

  /* End of Chart: '<S92>/Chart' */
  /* Transition: '<S97>:39' */
}

/* Output and update for atomic system: '<Root>/AST_SlwTask' */
void AST_SlwTask(void)
{
  sint32 i;
  sint32 i_0;
  sint32 rtb_Add1;
  uint32 tmp;
  dt_RadAng_u16r15b0 rtb_Add1_gqbm;
  dt_RadAng_u16r15b0 rtb_Switch3;
  dt_Standardize_s16p15b0 rtb_VectorConcatenate_kzws[40];
  dt_Standardize_s16p15b0 rtb_VectorConcatenate[20];
  dt_Standardize_s16p15b0 rtb_Abs1_pahi;
  dt_Standardize_s16p15b0 rtb_Abs3;
  dt_Standardize_s16p15b0 rtb_Abs4;
  dt_Standardize_s16p15b0 rtb_Abs5;
  dt_Standardize_s16p15b0 rtb_Abs_lsfq;
  dt_Standardize_s16p15b0 rtb_Add1_ceyr;
  dt_Standardize_s16p15b0 rtb_Add1_jyuu;
  dt_Standardize_s16p15b0 rtb_Add1_np2v;
  dt_Standardize_s16p15b0 rtb_Divide1_azfz;
  dt_Standardize_s16p15b0 rtb_Divide2;
  dt_Standardize_s16p15b0 rtb_Divide5;
  dt_Standardize_s16p15b0 rtb_Divide_gqgg;
  dt_Standardize_s16p15b0 rtb_Gain1_nzn1;
  dt_Standardize_s16p15b0 rtb_Gain2;
  dt_Standardize_s16p15b0 rtb_Gain3;
  dt_Standardize_s16p15b0 rtb_Gain4;
  dt_Standardize_s16p15b0 rtb_Merge;
  dt_Standardize_s16p15b0 rtb_Merge_cgss;
  dt_Standardize_s16p15b0 rtb_Product2_hnnw;
  dt_Standardize_s16p15b0 rtb_Saturation10;
  dt_Standardize_s16p15b0 rtb_Saturation2_d1yk;
  dt_Standardize_s16p15b0 rtb_Saturation2_lgdr;
  dt_Standardize_s16p15b0 rtb_Saturation5;
  dt_Standardize_s16p15b0 rtb_Saturation_b4dz;
  dt_Standardize_s16p15b0 rtb_Saturation_ktxb;
  dt_Standardize_s16p15b0 rtb_Saturation_mwki;
  dt_Standardize_s16p15b0 rtb_Switch2_hbuz;
  dt_Standardize_s16p15b0 rtb_Switch2_nvvx;
  dt_Standardize_s16p15b0 rtb_Switch3_acfy;
  dt_Standardize_s16p15b0 rtb_Switch4;
  dt_Standardize_s16p15b0 rtb_Switch_ardc;
  dt_Standardize_s16p15b0 rtb_Switch_eeka;
  dt_Standardize_s16p15b0 rtb_Switch_mzyp;
  dt_Standardize_s16p15b0 rtb_Switch_oqhk;
  dt_Standardize_s16p15b0 rtb_iPhsCurrLimMap_tPCB;
  dt_Standardize_s16p15b0 rtb_iSplyCurrLimMap_SplyVltg;
  dt_Standardize_s16p15b0 rtb_iSplyCurrLimMap_tPCB;
  dt_Standardize_s16p15b0 rtb_lb_genMaxInpMods;
  dt_Standardize_u16p15b0 rtb_Gu16_etaCtlBrd_MAP;
  dt_Standardize_u16p15b0 rtb_Saturation1;
  dt_Standardize_u16p15b0 rtb_Saturation_k1hr;
  sint16 rtb_Abs1_ih4a;
  sint16 rtb_Add1_dcaq;
  sint16 rtb_Add2_gdfb;
  sint16 rtb_DataTypeConversion_ei10;
  sint16 y;
  sint16 y_0;
  uint16 rtb_Abs;
  uint16 rtb_Divide;
  uint16 rtb_Gain1_mnsi;
  uint16 rtb_Min2;
  uint16 rtb_Product;
  uint16 rtb_Product1;
  uint16 rtb_Saturation;
  uint16 rtb_Saturation_exxs;
  uint16 rtb_Switch2;
  uint16 u0;
  ENM_AG_POS_EVAL_MODE rtb_enm_modeAgEvalMode;
  ENM_SYS_STATUS rtb_enmSysStas;
  uint8 tmp_0;
  boolean rtb_lb_decrRatLimReq_e0p2;
  boolean rtb_lb_decrRatLimReq_ja4e;
  boolean rtb_lb_incrRatLimReq_bzay;
  boolean rtb_lb_noRatLimReq_m20l;

  /* Saturate: '<S3>/Saturation1' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[0] > 14746) {
    y = 14746;
  } else if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[0] < -14746) {
    y = -14746;
  } else {
    y = busAST_SlwTaskIn.s16_iActDaxQaxCurr[0];
  }

  if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[1] > 14746) {
    y_0 = 14746;
  } else if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[1] < -14746) {
    y_0 = -14746;
  } else {
    y_0 = busAST_SlwTaskIn.s16_iActDaxQaxCurr[1];
  }

  /* If: '<S21>/If' incorporates:
   *  Abs: '<S25>/Abs'
   *  Logic: '<S21>/AND'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   *  Saturate: '<S3>/Saturation1'
   */
  if ((y == 0) && (y_0 == 0)) {
    /* Outputs for IfAction SubSystem: '<S21>/ias_ZeroInput' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* Merge: '<S21>/Merge' incorporates:
     *  Constant: '<S26>/Constant'
     *  SignalConversion generated from: '<S26>/lb_genHypt'
     */
    ASW_AST_B.Merge = 0;

    /* End of Outputs for SubSystem: '<S21>/ias_ZeroInput' */
  } else {
    /* Outputs for IfAction SubSystem: '<S21>/ias_NonZeroInput' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    if (y < 0) {
      /* Abs: '<S25>/Abs' */
      rtb_Abs_lsfq = (dt_Standardize_s16p15b0)(-y);
    } else {
      /* Abs: '<S25>/Abs' */
      rtb_Abs_lsfq = y;
    }

    /* Abs: '<S25>/Abs1' */
    if (y_0 < 0) {
      rtb_Abs1_pahi = (dt_Standardize_s16p15b0)(-y_0);
    } else {
      rtb_Abs1_pahi = y_0;
    }

    /* End of Abs: '<S25>/Abs1' */

    /* MinMax: '<S25>/Min1' incorporates:
     *  Abs: '<S25>/Abs'
     *  Abs: '<S25>/Abs1'
     */
    if (rtb_Abs_lsfq >= rtb_Abs1_pahi) {
      rtb_lb_genMaxInpMods = rtb_Abs_lsfq;
    } else {
      rtb_lb_genMaxInpMods = rtb_Abs1_pahi;
    }

    /* End of MinMax: '<S25>/Min1' */

    /* Selector: '<S25>/Selector1' incorporates:
     *  Abs: '<S25>/Abs'
     *  Abs: '<S25>/Abs1'
     *  Gain: '<S25>/Gain'
     *  MinMax: '<S25>/Min'
     *  MinMax: '<S25>/Min1'
     *  Product: '<S25>/Divide2'
     *  Saturate: '<S25>/Saturation'
     */
    if (rtb_Abs_lsfq <= rtb_Abs1_pahi) {
      y = rtb_Abs_lsfq;
    } else {
      y = rtb_Abs1_pahi;
    }

    u0 = (uint16)((511U * ((uint16)((y << 15) / rtb_lb_genMaxInpMods))) >> 15);
    if (u0 <= 511) {
    } else {
      u0 = 511U;
    }

    /* Merge: '<S21>/Merge' incorporates:
     *  Constant: '<S25>/Constant3'
     *  MinMax: '<S25>/Min1'
     *  Product: '<S25>/Multiply'
     *  Saturate: '<S25>/Saturation'
     *  Selector: '<S25>/Selector1'
     *  SignalConversion generated from: '<S25>/lb_genHypt'
     */
    ASW_AST_B.Merge = (dt_Standardize_s16p15b0)((rtCP_Constant3_Value[u0] *
      rtb_lb_genMaxInpMods) >> 15);

    /* End of Outputs for SubSystem: '<S21>/ias_NonZeroInput' */
  }

  /* End of If: '<S21>/If' */

  /* Saturate: '<S5>/Saturation6' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_uModulDaxQaxVltg[0] >= -32767) {
    y = busAST_SlwTaskIn.s16_uModulDaxQaxVltg[0];
  } else {
    y = -32767;
  }

  /* Saturate: '<S5>/Saturation7' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[0] > 14746) {
    y_0 = 14746;
  } else if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[0] < -14746) {
    y_0 = -14746;
  } else {
    y_0 = busAST_SlwTaskIn.s16_iActDaxQaxCurr[0];
  }

  /* Gain: '<S5>/Gain1' incorporates:
   *  Product: '<S5>/Product'
   *  Saturate: '<S5>/Saturation6'
   *  Saturate: '<S5>/Saturation7'
   */
  rtb_Gain1_nzn1 = (dt_Standardize_s16p15b0)((16777 * ((y * y_0) >> 14)) >> 11);

  /* Saturate: '<S5>/Saturation6' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_uModulDaxQaxVltg[1] >= -32767) {
    y = busAST_SlwTaskIn.s16_uModulDaxQaxVltg[1];
  } else {
    y = -32767;
  }

  /* Saturate: '<S5>/Saturation7' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[1] > 14746) {
    y_0 = 14746;
  } else if (busAST_SlwTaskIn.s16_iActDaxQaxCurr[1] < -14746) {
    y_0 = -14746;
  } else {
    y_0 = busAST_SlwTaskIn.s16_iActDaxQaxCurr[1];
  }

  /* Gain: '<S5>/Gain2' incorporates:
   *  Product: '<S5>/Product2'
   *  Saturate: '<S5>/Saturation6'
   *  Saturate: '<S5>/Saturation7'
   */
  rtb_Gain2 = (dt_Standardize_s16p15b0)((16777 * ((y * y_0) >> 14)) >> 11);

  /* Saturate: '<S5>/Saturation1' incorporates:
   *  Gain: '<S5>/Gain1'
   */
  if (rtb_Gain1_nzn1 > 16384) {
    y = 16384;
  } else if (rtb_Gain1_nzn1 < -16384) {
    y = -16384;
  } else {
    y = rtb_Gain1_nzn1;
  }

  /* Saturate: '<S5>/Saturation2' incorporates:
   *  Gain: '<S5>/Gain2'
   */
  if (rtb_Gain2 > 16384) {
    y_0 = 16384;
  } else if (rtb_Gain2 < -16384) {
    y_0 = -16384;
  } else {
    y_0 = rtb_Gain2;
  }

  /* Sum: '<S5>/Add2' incorporates:
   *  Saturate: '<S5>/Saturation1'
   *  Saturate: '<S5>/Saturation2'
   */
  rtb_Add2_gdfb = (sint16)((y + y_0) >> 1);

  /* Abs: '<S5>/Abs1' incorporates:
   *  Sum: '<S5>/Add2'
   */
  if (rtb_Add2_gdfb < 0) {
    rtb_Abs1_ih4a = (sint16)(-rtb_Add2_gdfb);
  } else {
    rtb_Abs1_ih4a = rtb_Add2_gdfb;
  }

  /* End of Abs: '<S5>/Abs1' */

  /* Saturate: '<S5>/Saturation' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.u16_uSplyVltg > 32767) {
    rtb_Saturation_k1hr = 32767U;
  } else if (busAST_SlwTaskIn.u16_uSplyVltg < 3072) {
    rtb_Saturation_k1hr = 3072U;
  } else {
    rtb_Saturation_k1hr = busAST_SlwTaskIn.u16_uSplyVltg;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Saturate: '<S5>/Saturation3' incorporates:
   *  Abs: '<S5>/Abs1'
   */
  if (rtb_Abs1_ih4a > 8192) {
    y = 8192;
  } else {
    y = rtb_Abs1_ih4a;
  }

  /* Gain: '<S5>/Gain3' incorporates:
   *  Gain: '<S5>/Gain'
   *  Product: '<S5>/Divide'
   *  Saturate: '<S5>/Saturation'
   *  Saturate: '<S5>/Saturation3'
   */
  rtb_Gain3 = (dt_Standardize_s16p15b0)((125U * ((uint16)((((uint32)(6 * y)) <<
    11) / rtb_Saturation_k1hr))) >> 8);

  /* Saturate: '<S5>/Saturation4' incorporates:
   *  Gain: '<S5>/Gain3'
   */
  if (rtb_Gain3 > 14746) {
    /* Saturate: '<S5>/Saturation4' */
    ASW_AST_B.Saturation4 = 14746;
  } else {
    /* Saturate: '<S5>/Saturation4' */
    ASW_AST_B.Saturation4 = rtb_Gain3;
  }

  /* End of Saturate: '<S5>/Saturation4' */

  /* SignalConversion generated from: '<S73>/Vector Concatenate' incorporates:
   *  Saturate: '<S5>/Saturation4'
   */
  rtb_VectorConcatenate_kzws[0] = ASW_AST_B.Saturation4;

  /* SignalConversion generated from: '<S22>/Vector Concatenate' incorporates:
   *  Merge: '<S21>/Merge'
   */
  rtb_VectorConcatenate[0] = ASW_AST_B.Merge;

  /* S-Function (sfix_udelay): '<S22>/Tapped Delay' */
  for (i_0 = 0; i_0 < 19; i_0++) {
    rtb_VectorConcatenate[i_0 + 1] = ASW_AST_DW.TappedDelay_DWORK1[i_0];
  }

  /* End of S-Function (sfix_udelay): '<S22>/Tapped Delay' */

  /* Sum: '<S22>/Sum of Elements' incorporates:
   *  Concatenate: '<S22>/Vector Concatenate'
   *  Sum: '<S73>/Sum of Elements'
   */
  i_0 = 0;
  for (i = 0; i < 20; i++) {
    i_0 += rtb_VectorConcatenate[i];
  }

  /* Product: '<S22>/Divide' incorporates:
   *  Sum: '<S22>/Sum of Elements'
   */
  rtb_Divide_gqgg = (dt_Standardize_s16p15b0)((i_0 << 4) / 320);

  /* Saturate: '<S5>/Saturation10' incorporates:
   *  Product: '<S22>/Divide'
   */
  if (rtb_Divide_gqgg > 14746) {
    rtb_Saturation10 = 14746;
  } else if (rtb_Divide_gqgg < -14746) {
    rtb_Saturation10 = -14746;
  } else {
    rtb_Saturation10 = rtb_Divide_gqgg;
  }

  /* End of Saturate: '<S5>/Saturation10' */

  /* Logic: '<S164>/Logical Operator' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  Logic: '<S77>/Logical Operator'
   *  Switch: '<S79>/Switch3'
   */
  rtb_lb_incrRatLimReq_bzay = ((busAST_SlwTaskIn.busOBD_FaltSt.bol_flgComFaltFlg)
    || (busAST_SlwTaskIn.busOBD_FaltSt.bol_flgBusOffFaltFlg));

  /* Saturate: '<S164>/Saturation2' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_nActElecSpd >= -32767) {
    rtb_Saturation2_lgdr = busAST_SlwTaskIn.s16_nActElecSpd;
  } else {
    rtb_Saturation2_lgdr = -32767;
  }

  /* End of Saturate: '<S164>/Saturation2' */

  /* Chart: '<S164>/sfc_SysSTM' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  Logic: '<S164>/Logical Operator'
   *  Saturate: '<S164>/Saturation2'
   */
  /* Gateway: AST_SlwTask/vrs_SysSTM/rss_SysSTM_GEELY/sfc_SysSTM */
  /* During: AST_SlwTask/vrs_SysSTM/rss_SysSTM_GEELY/sfc_SysSTM */
  if (ASW_AST_DW.is_active_c2_ASW_AST == 0U) {
    /* Entry: AST_SlwTask/vrs_SysSTM/rss_SysSTM_GEELY/sfc_SysSTM */
    ASW_AST_DW.is_active_c2_ASW_AST = 1U;

    /* Entry Internal: AST_SlwTask/vrs_SysSTM/rss_SysSTM_GEELY/sfc_SysSTM */
    /* Transition: '<S165>:2' */
    ASW_AST_DW.is_c2_ASW_AST = IN_SYSINIT;

    /* Entry 'SYSINIT': '<S165>:1' */
    rtb_enmSysStas = SYSINIT;
    ASW_AST_DW.u16_ctSysStInitWaitCnt = 0U;
  } else {
    switch (ASW_AST_DW.is_c2_ASW_AST) {
     case IN_LIMPHOME:
      rtb_enmSysStas = LIMPHOME;

      /* During 'LIMPHOME': '<S165>:131' */
      if (busAST_SlwTaskIn.u8_stMaxFaltLvl == 3) {
        /* Transition: '<S165>:132' */
        ASW_AST_DW.is_c2_ASW_AST = IN_SYSFAIL;

        /* Entry 'SYSFAIL': '<S165>:129' */
        rtb_enmSysStas = SYSFAIL;
      } else if (!rtb_lb_incrRatLimReq_bzay) {
        /* Transition: '<S165>:135' */
        ASW_AST_DW.is_c2_ASW_AST = IN_NORMAL;

        /* Entry 'NORMAL': '<S165>:4' */
        /* Entry Internal 'NORMAL': '<S165>:4' */
        /* Transition: '<S165>:127' */
        ASW_AST_DW.is_NORMAL = IN_RUN;

        /* Entry 'RUN': '<S165>:128' */
        rtb_enmSysStas = RUN;
      }
      break;

     case IN_NORMAL:
      /* During 'NORMAL': '<S165>:4' */
      if (busAST_SlwTaskIn.u8_stMaxFaltLvl == 3) {
        /* Transition: '<S165>:130' */
        /* Exit Internal 'NORMAL': '<S165>:4' */
        ASW_AST_DW.is_NORMAL = IN_NO_ACTIVE_CHILD;
        ASW_AST_DW.is_c2_ASW_AST = IN_SYSFAIL;

        /* Entry 'SYSFAIL': '<S165>:129' */
        rtb_enmSysStas = SYSFAIL;
      } else if (ASW_AST_DW.is_NORMAL == IN_RUN) {
        rtb_enmSysStas = RUN;

        /* During 'RUN': '<S165>:128' */
        if (busAST_SlwTaskIn.u8_modeMCUOpMode == 0) {
          /* Transition: '<S165>:137' */
          ASW_AST_DW.is_NORMAL = IN_STANDBY;

          /* Entry 'STANDBY': '<S165>:126' */
          rtb_enmSysStas = STANDBY;
        } else if (rtb_lb_incrRatLimReq_bzay) {
          /* Transition: '<S165>:133' */
          ASW_AST_DW.is_NORMAL = IN_NO_ACTIVE_CHILD;
          ASW_AST_DW.is_c2_ASW_AST = IN_LIMPHOME;

          /* Entry 'LIMPHOME': '<S165>:131' */
          rtb_enmSysStas = LIMPHOME;
        }
      } else {
        rtb_enmSysStas = STANDBY;

        /* During 'STANDBY': '<S165>:126' */
        if (busAST_SlwTaskIn.u8_modeMCUOpMode == 1) {
          /* Transition: '<S165>:136' */
          ASW_AST_DW.is_NORMAL = IN_RUN;

          /* Entry 'RUN': '<S165>:128' */
          rtb_enmSysStas = RUN;
        } else if ((busAST_SlwTaskIn.bol_flgSlepEn) || rtb_lb_incrRatLimReq_bzay)
        {
          if (rtb_Saturation2_lgdr < 0) {
            i_0 = -rtb_Saturation2_lgdr;
            if ((-rtb_Saturation2_lgdr) > 32767) {
              i_0 = 32767;
            }

            y = (sint16)i_0;
          } else {
            y = rtb_Saturation2_lgdr;
          }

          if (Gs16_nShOffActElecSpd_C < 0) {
            i_0 = -Gs16_nShOffActElecSpd_C;
            if ((-Gs16_nShOffActElecSpd_C) > 32767) {
              i_0 = 32767;
            }

            y_0 = (sint16)i_0;
          } else {
            y_0 = Gs16_nShOffActElecSpd_C;
          }

          if (y < y_0) {
            rtb_lb_noRatLimReq_m20l = true;

            /* Transition: '<S165>:146' */
            /* Transition: '<S165>:168' */
            ASW_AST_DW.is_NORMAL = IN_NO_ACTIVE_CHILD;
            ASW_AST_DW.is_c2_ASW_AST = IN_SYSSLEEP;

            /* Entry 'SYSSLEEP': '<S165>:139' */
            rtb_enmSysStas = SYSSLEEP;
          } else {
            rtb_lb_noRatLimReq_m20l = false;
          }
        } else {
          rtb_lb_noRatLimReq_m20l = false;
        }
      }
      break;

     case IN_SYSFAIL:
      rtb_enmSysStas = SYSFAIL;

      /* During 'SYSFAIL': '<S165>:129' */
      if (busAST_SlwTaskIn.u8_stMaxFaltLvl != 3) {
        /* Transition: '<S165>:134' */
        ASW_AST_DW.is_c2_ASW_AST = IN_NORMAL;

        /* Entry 'NORMAL': '<S165>:4' */
        /* Entry Internal 'NORMAL': '<S165>:4' */
        /* Transition: '<S165>:127' */
        ASW_AST_DW.is_NORMAL = IN_RUN;

        /* Entry 'RUN': '<S165>:128' */
        rtb_enmSysStas = RUN;
      } else if (((busAST_SlwTaskIn.bol_flgSlepEn) || rtb_lb_incrRatLimReq_bzay)
                 && (busAST_SlwTaskIn.u8_modeMCUOpMode == 0)) {
        if (rtb_Saturation2_lgdr < 0) {
          i_0 = -rtb_Saturation2_lgdr;
          if ((-rtb_Saturation2_lgdr) > 32767) {
            i_0 = 32767;
          }

          y = (sint16)i_0;
        } else {
          y = rtb_Saturation2_lgdr;
        }

        if (Gs16_nShOffActElecSpd_C < 0) {
          i_0 = -Gs16_nShOffActElecSpd_C;
          if ((-Gs16_nShOffActElecSpd_C) > 32767) {
            i_0 = 32767;
          }

          y_0 = (sint16)i_0;
        } else {
          y_0 = Gs16_nShOffActElecSpd_C;
        }

        if (y < y_0) {
          rtb_lb_noRatLimReq_m20l = true;

          /* Transition: '<S165>:143' */
          /* Transition: '<S165>:147' */
          /* Transition: '<S165>:168' */
          ASW_AST_DW.is_c2_ASW_AST = IN_SYSSLEEP;

          /* Entry 'SYSSLEEP': '<S165>:139' */
          rtb_enmSysStas = SYSSLEEP;
        } else {
          rtb_lb_noRatLimReq_m20l = false;
        }
      } else {
        rtb_lb_noRatLimReq_m20l = false;
      }
      break;

     case IN_SYSINIT:
      rtb_enmSysStas = SYSINIT;

      /* During 'SYSINIT': '<S165>:1' */
      if (ASW_AST_DW.u16_ctSysStInitWaitCnt >= Gu16_ctSysStInitWaitCnt_C) {
        /* Transition: '<S165>:153' */
        /* Exit 'SYSINIT': '<S165>:1' */
        ASW_AST_DW.u16_ctSysStInitWaitCnt = 0U;
        ASW_AST_DW.is_c2_ASW_AST = IN_NORMAL;

        /* Entry 'NORMAL': '<S165>:4' */
        /* Entry Internal 'NORMAL': '<S165>:4' */
        /* Transition: '<S165>:127' */
        ASW_AST_DW.is_NORMAL = IN_RUN;

        /* Entry 'RUN': '<S165>:128' */
        rtb_enmSysStas = RUN;
      } else {
        ASW_AST_DW.u16_ctSysStInitWaitCnt++;
      }
      break;

     default:
      rtb_enmSysStas = SYSSLEEP;

      /* During 'SYSSLEEP': '<S165>:139' */
      break;
    }
  }

  /* End of Chart: '<S164>/sfc_SysSTM' */

  /* SwitchCase: '<S80>/Switch Case' incorporates:
   *  DataTypeConversion: '<S80>/Data Type Conversion1'
   */
  switch (rtb_enmSysStas) {
   case 1:
    /* Saturate: '<S77>/Saturation3' incorporates:
     *  Inport: '<Root>/busAST_SlwTaskIn'
     */
    if (busAST_SlwTaskIn.s16_nComRefMechSpd > 10000) {
      /* Outputs for IfAction SubSystem: '<S80>/sas_SysStRunCs' incorporates:
       *  ActionPort: '<S132>/Action Port'
       */
      /* SignalConversion generated from: '<S132>/s16_nComRefMechSpd' incorporates:
       *  Merge: '<S80>/Merge'
       */
      rtb_Merge = 10000;

      /* End of Outputs for SubSystem: '<S80>/sas_SysStRunCs' */
    } else if (busAST_SlwTaskIn.s16_nComRefMechSpd < -10000) {
      /* Outputs for IfAction SubSystem: '<S80>/sas_SysStRunCs' incorporates:
       *  ActionPort: '<S132>/Action Port'
       */
      /* SignalConversion generated from: '<S132>/s16_nComRefMechSpd' incorporates:
       *  Merge: '<S80>/Merge'
       */
      rtb_Merge = -10000;

      /* End of Outputs for SubSystem: '<S80>/sas_SysStRunCs' */
    } else {
      /* Outputs for IfAction SubSystem: '<S80>/sas_SysStRunCs' incorporates:
       *  ActionPort: '<S132>/Action Port'
       */
      /* SignalConversion generated from: '<S132>/s16_nComRefMechSpd' incorporates:
       *  Merge: '<S80>/Merge'
       */
      rtb_Merge = busAST_SlwTaskIn.s16_nComRefMechSpd;

      /* End of Outputs for SubSystem: '<S80>/sas_SysStRunCs' */
    }

    /* End of Saturate: '<S77>/Saturation3' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S80>/sas_SysStLmpHmeCs' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    /* SignalConversion generated from: '<S131>/s16_nSysSTMRefMechSpdLmpHmeCs' incorporates:
     *  Constant: '<S131>/Constant'
     *  Merge: '<S80>/Merge'
     */
    rtb_Merge = Gs16_nLmpHmeRefMechSpd_C;

    /* End of Outputs for SubSystem: '<S80>/sas_SysStLmpHmeCs' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S80>/sas_SysStDflCs' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    /* SignalConversion generated from: '<S130>/s16_nSysSTMRefMechSpdDflCs' incorporates:
     *  Constant: '<S130>/Constant'
     *  Merge: '<S80>/Merge'
     */
    rtb_Merge = 0;

    /* End of Outputs for SubSystem: '<S80>/sas_SysStDflCs' */
    break;
  }

  /* End of SwitchCase: '<S80>/Switch Case' */

  /* Saturate: '<S77>/Saturation2' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_nFaltRefMechSpd > 10000) {
    rtb_Saturation2_d1yk = 10000;
  } else if (busAST_SlwTaskIn.s16_nFaltRefMechSpd < -10000) {
    rtb_Saturation2_d1yk = -10000;
  } else {
    rtb_Saturation2_d1yk = busAST_SlwTaskIn.s16_nFaltRefMechSpd;
  }

  /* End of Saturate: '<S77>/Saturation2' */

  /* Saturate: '<S127>/Saturation' incorporates:
   *  Constant: '<S127>/Constant'
   */
  if (Gs16_nMaxRefMechSpd_C > 10000) {
    rtb_Saturation_mwki = 10000;
  } else if (Gs16_nMaxRefMechSpd_C < -10000) {
    rtb_Saturation_mwki = -10000;
  } else {
    rtb_Saturation_mwki = Gs16_nMaxRefMechSpd_C;
  }

  /* End of Saturate: '<S127>/Saturation' */

  /* Abs: '<S79>/Abs5' incorporates:
   *  Saturate: '<S127>/Saturation'
   */
  if (rtb_Saturation_mwki < 0) {
    rtb_Abs5 = (dt_Standardize_s16p15b0)(-rtb_Saturation_mwki);
  } else {
    rtb_Abs5 = rtb_Saturation_mwki;
  }

  /* End of Abs: '<S79>/Abs5' */

  /* Switch: '<S79>/Switch3' incorporates:
   *  Constant: '<S79>/Constant1'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  Logic: '<S79>/Logical Operator1'
   *  Merge: '<S80>/Merge'
   *  MinMax: '<S79>/Min'
   *  Saturate: '<S77>/Saturation2'
   *  Switch: '<S79>/Switch'
   */
  if (busAST_SlwTaskIn.bol_flgOvrTstCtlUDS2F) {
    rtb_Switch3_acfy = Gs16_nUDS2FRefMechSpd_C;
  } else if ((busAST_SlwTaskIn.busOBD_FaltSt.bol_flgMotoStallTmpFlg) ||
             rtb_lb_incrRatLimReq_bzay) {
    /* Switch: '<S79>/Switch' incorporates:
     *  Saturate: '<S77>/Saturation2'
     *  Switch: '<S79>/Switch3'
     */
    rtb_Switch3_acfy = rtb_Saturation2_d1yk;
  } else if (rtb_Merge <= rtb_Saturation2_d1yk) {
    /* MinMax: '<S79>/Min' incorporates:
     *  Merge: '<S80>/Merge'
     *  Switch: '<S79>/Switch'
     *  Switch: '<S79>/Switch3'
     */
    rtb_Switch3_acfy = rtb_Merge;
  } else {
    /* Switch: '<S79>/Switch3' incorporates:
     *  MinMax: '<S79>/Min'
     *  Saturate: '<S77>/Saturation2'
     *  Switch: '<S79>/Switch'
     */
    rtb_Switch3_acfy = rtb_Saturation2_d1yk;
  }

  /* Saturate: '<S129>/Saturation' incorporates:
   *  Constant: '<S129>/Constant'
   */
  if (Gs16_nMinRefMechSpd_C > 10000) {
    rtb_Saturation_ktxb = 10000;
  } else if (Gs16_nMinRefMechSpd_C < -10000) {
    rtb_Saturation_ktxb = -10000;
  } else {
    rtb_Saturation_ktxb = Gs16_nMinRefMechSpd_C;
  }

  /* End of Saturate: '<S129>/Saturation' */

  /* Abs: '<S79>/Abs4' incorporates:
   *  Saturate: '<S129>/Saturation'
   */
  if (rtb_Saturation_ktxb < 0) {
    rtb_Abs4 = (dt_Standardize_s16p15b0)(-rtb_Saturation_ktxb);
  } else {
    rtb_Abs4 = rtb_Saturation_ktxb;
  }

  /* End of Abs: '<S79>/Abs4' */

  /* Switch: '<S125>/Switch2' incorporates:
   *  Abs: '<S79>/Abs4'
   *  Abs: '<S79>/Abs5'
   *  RelationalOperator: '<S125>/Relational Operator2'
   */
  if (rtb_Abs5 > rtb_Abs4) {
    /* Abs: '<S79>/Abs3' incorporates:
     *  Switch: '<S79>/Switch3'
     */
    if (rtb_Switch3_acfy < 0) {
      rtb_Abs3 = (dt_Standardize_s16p15b0)(-rtb_Switch3_acfy);
    } else {
      rtb_Abs3 = rtb_Switch3_acfy;
    }

    /* End of Abs: '<S79>/Abs3' */

    /* Switch: '<S125>/Switch1' incorporates:
     *  Abs: '<S79>/Abs3'
     *  RelationalOperator: '<S125>/Relational Operator1'
     */
    if (rtb_Abs3 <= rtb_Abs5) {
      /* Switch: '<S125>/Switch' incorporates:
       *  RelationalOperator: '<S125>/Relational Operator'
       */
      if (rtb_Abs3 >= rtb_Abs4) {
        /* Switch: '<S125>/Switch2' */
        rtb_Switch2_hbuz = rtb_Abs3;
      } else {
        /* Switch: '<S125>/Switch2' */
        rtb_Switch2_hbuz = rtb_Abs4;
      }

      /* End of Switch: '<S125>/Switch' */
    } else {
      /* Switch: '<S125>/Switch2' */
      rtb_Switch2_hbuz = rtb_Abs5;
    }

    /* End of Switch: '<S125>/Switch1' */
  } else {
    rtb_Switch2_hbuz = rtb_Abs5;
  }

  /* End of Switch: '<S125>/Switch2' */

  /* Switch: '<S79>/Switch1' incorporates:
   *  Constant: '<S122>/Constant'
   *  Constant: '<S79>/Constant'
   *  Gain: '<S79>/Gain'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  Logic: '<S79>/Logical Operator'
   *  Merge: '<S80>/Merge'
   *  RelationalOperator: '<S119>/Compare'
   *  RelationalOperator: '<S120>/Compare'
   *  RelationalOperator: '<S121>/Compare'
   *  RelationalOperator: '<S122>/Compare'
   *  Saturate: '<S77>/Saturation2'
   *  Switch: '<S125>/Switch2'
   *  Switch: '<S79>/Switch2'
   *  Switch: '<S79>/Switch3'
   */
  if ((((rtb_Merge == 0) || (rtb_Saturation2_d1yk == 0)) ||
       (busAST_SlwTaskIn.u8_modeMCUOpMode == 6)) ||
      (busAST_SlwTaskIn.bol_flgSlepEn)) {
    y = 0;
  } else if (rtb_Switch3_acfy > 0) {
    /* Switch: '<S79>/Switch2' incorporates:
     *  Switch: '<S125>/Switch2'
     */
    y = rtb_Switch2_hbuz;
  } else {
    y = (dt_Standardize_s16p15b0)(-rtb_Switch2_hbuz);
  }

  /* Saturate: '<S96>/Saturation' incorporates:
   *  Constant: '<S96>/Constant'
   */
  if (Gu8_numPPNum_C > 6) {
    tmp_0 = 6U;
  } else if (Gu8_numPPNum_C < 2) {
    tmp_0 = 2U;
  } else {
    tmp_0 = Gu8_numPPNum_C;
  }

  /* Product: '<S78>/Divide2' incorporates:
   *  Gain: '<S78>/RpmToRdps_1'
   *  Saturate: '<S96>/Saturation'
   *  Switch: '<S79>/Switch1'
   */
  rtb_Divide2 = (dt_Standardize_s16p15b0)(((6863 * y) >> 13) * tmp_0);

  /* Abs: '<S78>/Abs' incorporates:
   *  Product: '<S78>/Divide2'
   */
  if (rtb_Divide2 < 0) {
    y = (sint16)(-rtb_Divide2);
  } else {
    y = rtb_Divide2;
  }

  /* Abs: '<S78>/Abs1' incorporates:
   *  Constant: '<S78>/parMinSnslRefElctSpd'
   */
  if (Gs16_nMinSenlRefElecSpd_C < 0) {
    y_0 = (sint16)(-Gs16_nMinSenlRefElecSpd_C);
  } else {
    y_0 = Gs16_nMinSenlRefElecSpd_C;
  }

  /* Switch: '<S78>/Switch2' incorporates:
   *  Abs: '<S78>/Abs'
   *  Abs: '<S78>/Abs1'
   *  Constant: '<S85>/Constant'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  Logic: '<S78>/AND'
   *  Product: '<S78>/Divide2'
   *  RelationalOperator: '<S78>/Relational Operator'
   *  RelationalOperator: '<S85>/Compare'
   */
  if ((y >= y_0) && (busAST_SlwTaskIn.enm_stMotoSt == OPEN_LOOP)) {
    /* Switch: '<S91>/Switch2' incorporates:
     *  Constant: '<S78>/parStlgStrtUpElctSpd'
     *  Gain: '<S78>/Gain1'
     *  RelationalOperator: '<S91>/Relational Operator2'
     */
    if (Gs16_nMaxStrtUpRefElecSpd_C > ((dt_Standardize_s16p15b0)
         (-Gs16_nMaxStrtUpRefElecSpd_C))) {
      /* Switch: '<S91>/Switch1' incorporates:
       *  Product: '<S78>/Divide2'
       *  RelationalOperator: '<S91>/Relational Operator1'
       */
      if (rtb_Divide2 <= Gs16_nMaxStrtUpRefElecSpd_C) {
        /* Switch: '<S91>/Switch' incorporates:
         *  RelationalOperator: '<S91>/Relational Operator'
         */
        if (rtb_Divide2 >= ((dt_Standardize_s16p15b0)
                            (-Gs16_nMaxStrtUpRefElecSpd_C))) {
          /* Switch: '<S78>/Switch2' */
          rtb_Switch2_nvvx = rtb_Divide2;
        } else {
          /* Switch: '<S78>/Switch2' */
          rtb_Switch2_nvvx = (dt_Standardize_s16p15b0)
            (-Gs16_nMaxStrtUpRefElecSpd_C);
        }

        /* End of Switch: '<S91>/Switch' */
      } else {
        /* Switch: '<S78>/Switch2' */
        rtb_Switch2_nvvx = Gs16_nMaxStrtUpRefElecSpd_C;
      }

      /* End of Switch: '<S91>/Switch1' */
    } else {
      /* Switch: '<S78>/Switch2' */
      rtb_Switch2_nvvx = Gs16_nMaxStrtUpRefElecSpd_C;
    }

    /* End of Switch: '<S91>/Switch2' */
  } else {
    rtb_Switch2_nvvx = rtb_Divide2;
  }

  /* End of Switch: '<S78>/Switch2' */

  /* Chart: '<S78>/sfc_OpnLpRefElecSpdConf' incorporates:
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  Logic: '<S78>/Logical Operator1'
   *  RelationalOperator: '<S85>/Compare'
   *  RelationalOperator: '<S86>/Compare'
   *  RelationalOperator: '<S87>/Compare'
   *  Switch: '<S78>/Switch2'
   *  UnitDelay: '<S78>/Unit Delay'
   */
  /* Gateway: AST_SlwTask/vrs_RefElecSpdCalc/rss_RefElecSpdCalcHybr/rss_RefElecSpdCalc/sfc_OpnLpRefElecSpdConf */
  /* During: AST_SlwTask/vrs_RefElecSpdCalc/rss_RefElecSpdCalcHybr/rss_RefElecSpdCalc/sfc_OpnLpRefElecSpdConf */
  if (ASW_AST_DW.is_active_c1_ASW_AST == 0U) {
    /* Entry: AST_SlwTask/vrs_RefElecSpdCalc/rss_RefElecSpdCalcHybr/rss_RefElecSpdCalc/sfc_OpnLpRefElecSpdConf */
    ASW_AST_DW.is_active_c1_ASW_AST = 1U;

    /* Entry Internal: AST_SlwTask/vrs_RefElecSpdCalc/rss_RefElecSpdCalcHybr/rss_RefElecSpdCalc/sfc_OpnLpRefElecSpdConf */
    /* Transition: '<S94>:2' */
    ASW_AST_DW.is_c1_ASW_AST = IN_STRTUP_SPD;

    /* Entry 'STRTUP_SPD': '<S94>:4' */
  } else if (ASW_AST_DW.is_c1_ASW_AST == IN_ALGN_SPD) {
    /* During 'ALGN_SPD': '<S94>:3' */
    if (ASW_AST_DW.u16_ctAlgnStEndCnt >= Gu16_ctAlgnStEndCnt_C) {
      /* Transition: '<S94>:28' */
      /* Exit 'ALGN_SPD': '<S94>:3' */
      ASW_AST_DW.u16_ctAlgnStEndCnt = 0U;
      ASW_AST_DW.is_c1_ASW_AST = IN_STRTUP_SPD;

      /* Entry 'STRTUP_SPD': '<S94>:4' */
    } else {
      ASW_AST_DW.u16_ctAlgnStEndCnt++;
    }

    /* During 'STRTUP_SPD': '<S94>:4' */
  } else if ((ASW_AST_DW.UnitDelay_DSTATE_jm5t == OFF) &&
             (busAST_SlwTaskIn.enm_stMotoSt == OPEN_LOOP)) {
    /* Transition: '<S94>:111' */
    ASW_AST_DW.is_c1_ASW_AST = IN_ALGN_SPD;

    /* Entry 'ALGN_SPD': '<S94>:3' */
    ASW_AST_B.s16_nOpnLpRefElecSpd = Gs16_nAlgnRefElecSpd_C;
    ASW_AST_DW.u16_ctAlgnStEndCnt = 0U;
  } else {
    ASW_AST_B.s16_nOpnLpRefElecSpd = rtb_Switch2_nvvx;
  }

  /* End of Chart: '<S78>/sfc_OpnLpRefElecSpdConf' */

  /* Switch: '<S101>/Switch1' incorporates:
   *  Constant: '<S101>/Constant1'
   *  Constant: '<S84>/Constant'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  RelationalOperator: '<S84>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  UnitDelay: '<S101>/Unit Delay1'
   */
  if (ASW_AST_DW.bitsForTID1.UnitDelay1_DSTATE_hx0c) {
    rtb_lb_incrRatLimReq_bzay = (busAST_SlwTaskIn.enm_stMotoSt != CLOSED_LOOP);
  } else {
    rtb_lb_incrRatLimReq_bzay = true;
  }

  /* Switch: '<S101>/Switch' incorporates:
   *  Switch: '<S101>/Switch1'
   *  UnitDelay: '<S101>/Unit Delay'
   *  UnitDelay: '<S78>/Unit Delay1'
   */
  if (rtb_lb_incrRatLimReq_bzay) {
    rtb_Switch_mzyp = ASW_AST_DW.UnitDelay1_DSTATE;
  } else {
    rtb_Switch_mzyp = ASW_AST_DW.UnitDelay_DSTATE_m2qg;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Chart: '<S92>/Chart' incorporates:
   *  Constant: '<S100>/Constant1'
   *  Constant: '<S99>/Constant1'
   *  DataTypeConversion: '<S100>/Data Type Conversion'
   *  DataTypeConversion: '<S99>/Data Type Conversion'
   *  Logic: '<S100>/Logical Operator'
   *  Logic: '<S99>/Logical Operator'
   *  Product: '<S100>/Product'
   *  Product: '<S99>/Product'
   *  RelationalOperator: '<S100>/Equal'
   *  RelationalOperator: '<S100>/Equal1'
   *  RelationalOperator: '<S99>/Equal'
   *  RelationalOperator: '<S99>/Equal1'
   *  Sum: '<S100>/Add'
   *  Sum: '<S99>/Add'
   *  Switch: '<S101>/Switch'
   */
  ASW_AST_Chart(((((sint16)mul_ssu32_hiSR((ASW_AST_B.s16_nOpnLpRefElecSpd -
    rtb_Switch_mzyp) << 15, 26214425U, 9U)) >= (Gs16_facRefSpdRisSlwRate_C >> 5))
                 && (ASW_AST_B.s16_nOpnLpRefElecSpd >= rtb_Switch_mzyp)),
                ((((sint16)mul_ssu32_hiSR((ASW_AST_B.s16_nOpnLpRefElecSpd -
    rtb_Switch_mzyp) << 15, 26214425U, 9U)) <= (Gs16_facRefSpdFallSlwRate_C >> 5))
                 && (ASW_AST_B.s16_nOpnLpRefElecSpd <= rtb_Switch_mzyp)),
                &rtb_lb_noRatLimReq_m20l, &rtb_lb_incrRatLimReq_bzay,
                &rtb_lb_decrRatLimReq_e0p2);

  /* Switch: '<S98>/Switch1' incorporates:
   *  Constant: '<S98>/Constant'
   *  Constant: '<S98>/Constant1'
   *  Switch: '<S98>/Switch'
   */
  if (rtb_lb_noRatLimReq_m20l) {
    y = 0;
  } else if (rtb_lb_incrRatLimReq_bzay) {
    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S98>/Constant2'
     */
    y = Gs16_facRefSpdRisSlwRate_C;
  } else {
    y = Gs16_facRefSpdFallSlwRate_C;
  }

  /* Sum: '<S98>/Add1' incorporates:
   *  Constant: '<S98>/Constant4'
   *  Product: '<S98>/Divide1'
   *  Switch: '<S101>/Switch'
   *  Switch: '<S98>/Switch1'
   */
  rtb_Add1_jyuu = (dt_Standardize_s16p15b0)((((sint16)((y * 41943) >> 14)) +
    (rtb_Switch_mzyp << 5)) >> 5);

  /* Switch: '<S112>/Switch1' incorporates:
   *  Constant: '<S112>/Constant1'
   *  Constant: '<S83>/Constant'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  RelationalOperator: '<S83>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  if (ASW_AST_DW.bitsForTID1.UnitDelay1_DSTATE_k25k) {
    rtb_lb_incrRatLimReq_bzay = (busAST_SlwTaskIn.enm_stMotoSt != OPEN_LOOP);
  } else {
    rtb_lb_incrRatLimReq_bzay = true;
  }

  /* Switch: '<S112>/Switch' incorporates:
   *  Switch: '<S112>/Switch1'
   *  UnitDelay: '<S112>/Unit Delay'
   *  UnitDelay: '<S78>/Unit Delay2'
   */
  if (rtb_lb_incrRatLimReq_bzay) {
    rtb_Switch_oqhk = ASW_AST_DW.UnitDelay2_DSTATE;
  } else {
    rtb_Switch_oqhk = ASW_AST_DW.UnitDelay_DSTATE_ozdy;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Chart: '<S93>/Chart' incorporates:
   *  Constant: '<S110>/Constant1'
   *  Constant: '<S111>/Constant1'
   *  DataTypeConversion: '<S110>/Data Type Conversion'
   *  DataTypeConversion: '<S111>/Data Type Conversion'
   *  Logic: '<S110>/Logical Operator'
   *  Logic: '<S111>/Logical Operator'
   *  Product: '<S110>/Product'
   *  Product: '<S111>/Product'
   *  RelationalOperator: '<S110>/Equal'
   *  RelationalOperator: '<S110>/Equal1'
   *  RelationalOperator: '<S111>/Equal'
   *  RelationalOperator: '<S111>/Equal1'
   *  Sum: '<S110>/Add'
   *  Sum: '<S111>/Add'
   *  Switch: '<S112>/Switch'
   */
  ASW_AST_Chart(((((sint16)mul_ssu32_hiSR((ASW_AST_B.s16_nOpnLpRefElecSpd -
    rtb_Switch_oqhk) << 15, 26214425U, 9U)) >= (Gs16_facRefSpdOLRiseSlwRate_C >>
    5)) && (ASW_AST_B.s16_nOpnLpRefElecSpd >= rtb_Switch_oqhk)), ((((sint16)
    mul_ssu32_hiSR((ASW_AST_B.s16_nOpnLpRefElecSpd - rtb_Switch_oqhk) << 15,
                   26214425U, 9U)) <= (Gs16_facRefSpdOLFallSlwRate_C >> 5)) &&
    (ASW_AST_B.s16_nOpnLpRefElecSpd <= rtb_Switch_oqhk)),
                &rtb_lb_incrRatLimReq_bzay, &rtb_lb_decrRatLimReq_e0p2,
                &rtb_lb_decrRatLimReq_ja4e);

  /* Switch: '<S109>/Switch1' incorporates:
   *  Constant: '<S109>/Constant'
   *  Constant: '<S109>/Constant1'
   *  Switch: '<S109>/Switch'
   */
  if (rtb_lb_incrRatLimReq_bzay) {
    y = 0;
  } else if (rtb_lb_decrRatLimReq_e0p2) {
    /* Switch: '<S109>/Switch' incorporates:
     *  Constant: '<S109>/Constant2'
     */
    y = Gs16_facRefSpdOLRiseSlwRate_C;
  } else {
    y = Gs16_facRefSpdOLFallSlwRate_C;
  }

  /* Sum: '<S109>/Add1' incorporates:
   *  Constant: '<S109>/Constant4'
   *  Product: '<S109>/Divide1'
   *  Switch: '<S109>/Switch1'
   *  Switch: '<S112>/Switch'
   */
  rtb_Add1_ceyr = (dt_Standardize_s16p15b0)((((sint16)((y * 41943) >> 10)) +
    (rtb_Switch_oqhk << 9)) >> 9);

  /* Switch: '<S78>/Switch4' incorporates:
   *  Constant: '<S78>/Constant1'
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  Logic: '<S78>/Logical Operator'
   *  RelationalOperator: '<S81>/Compare'
   *  RelationalOperator: '<S82>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  Switch: '<S78>/Switch5'
   *  Switch: '<S93>/Switch'
   */
  if ((busAST_SlwTaskIn.enm_stMotoSt == OFF) ||
      (busAST_SlwTaskIn.bol_enPosSCDCalibEnFlg)) {
    rtb_Switch4 = 0;
  } else if (busAST_SlwTaskIn.enm_stMotoSt == CLOSED_LOOP) {
    /* Switch: '<S92>/Switch' incorporates:
     *  Switch: '<S78>/Switch5'
     */
    if (rtb_lb_noRatLimReq_m20l) {
      /* Switch: '<S78>/Switch4' */
      rtb_Switch4 = ASW_AST_B.s16_nOpnLpRefElecSpd;
    } else {
      /* Switch: '<S78>/Switch4' incorporates:
       *  Sum: '<S98>/Add1'
       */
      rtb_Switch4 = rtb_Add1_jyuu;
    }

    /* End of Switch: '<S92>/Switch' */
  } else if (rtb_lb_incrRatLimReq_bzay) {
    /* Switch: '<S93>/Switch' incorporates:
     *  Switch: '<S78>/Switch4'
     *  Switch: '<S78>/Switch5'
     */
    rtb_Switch4 = ASW_AST_B.s16_nOpnLpRefElecSpd;
  } else {
    /* Switch: '<S78>/Switch4' incorporates:
     *  Sum: '<S109>/Add1'
     *  Switch: '<S78>/Switch5'
     *  Switch: '<S93>/Switch'
     */
    rtb_Switch4 = rtb_Add1_ceyr;
  }

  /* End of Switch: '<S78>/Switch4' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S62>/Constant'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  RelationalOperator: '<S62>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  Saturate: '<S5>/Saturation11'
   */
  if (busAST_SlwTaskIn.enm_stMotoSt == OPEN_LOOP) {
    /* Saturate: '<S5>/Saturation12' incorporates:
     *  Switch: '<S5>/Switch'
     *  Switch: '<S78>/Switch4'
     */
    if (rtb_Switch4 >= -32767) {
      rtb_Switch_ardc = rtb_Switch4;
    } else {
      rtb_Switch_ardc = -32767;
    }

    /* End of Saturate: '<S5>/Saturation12' */
  } else if (busAST_SlwTaskIn.s16_nActElecSpd >= -32767) {
    /* Saturate: '<S5>/Saturation11' incorporates:
     *  Switch: '<S5>/Switch'
     */
    rtb_Switch_ardc = busAST_SlwTaskIn.s16_nActElecSpd;
  } else {
    rtb_Switch_ardc = -32767;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Abs: '<S5>/Abs' incorporates:
   *  Saturate: '<S5>/Saturation10'
   */
  if (rtb_Saturation10 < 0) {
    y = (sint16)(-rtb_Saturation10);
  } else {
    y = rtb_Saturation10;
  }

  /* Abs: '<S5>/Abs2' incorporates:
   *  Switch: '<S5>/Switch'
   */
  if (rtb_Switch_ardc < 0) {
    y_0 = (sint16)(-rtb_Switch_ardc);
  } else {
    y_0 = rtb_Switch_ardc;
  }

  /* Lookup_n-D: '<S5>/Gu16_etaCtlBrd_MAP' incorporates:
   *  Abs: '<S5>/Abs'
   *  Abs: '<S5>/Abs2'
   */
  rtb_Gu16_etaCtlBrd_MAP = look2_is16lu32n16tu16_binlcse(y, y_0,
    &Gu16_etaCtlBrd_MAP_ampActPhCurrAmp_X[0], &Gu16_etaCtlBrd_MAP_nActElecSpd_Y
    [0], &Gu16_etaCtlBrd_MAP[0], rtCP_Gu16_etaCtlBrd_MAP_maxInde, 6U);

  /* S-Function (sfix_udelay): '<S73>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_kzws[1], &ASW_AST_DW.TappedDelay_DWORK1_msrl[0],
         39U * (sizeof(dt_Standardize_s16p15b0)));

  /* Sum: '<S73>/Sum of Elements' incorporates:
   *  Concatenate: '<S73>/Vector Concatenate'
   *  Sum: '<S22>/Sum of Elements'
   */
  i_0 = 0;
  for (i = 0; i < 40; i++) {
    i_0 += rtb_VectorConcatenate_kzws[i];
  }

  /* Product: '<S5>/Divide1' incorporates:
   *  Lookup_n-D: '<S5>/Gu16_etaCtlBrd_MAP'
   *  Product: '<S73>/Divide'
   *  Sum: '<S73>/Sum of Elements'
   */
  rtb_Divide1_azfz = (dt_Standardize_s16p15b0)div_nde_s32_floor(((i_0 << 4) /
    640) << 15, rtb_Gu16_etaCtlBrd_MAP);

  /* Gain: '<S5>/Gain4' incorporates:
   *  Product: '<S5>/Divide1'
   *  Product: '<S5>/Product1'
   *  Saturate: '<S5>/Saturation'
   */
  rtb_Gain4 = (dt_Standardize_s16p15b0)((16777 * ((sint16)((rtb_Saturation_k1hr *
    rtb_Divide1_azfz) >> 14))) >> 11);

  /* Saturate: '<S5>/Saturation9' incorporates:
   *  Gain: '<S5>/Gain4'
   */
  if (rtb_Gain4 > 16384) {
    busAST_SlwTaskOut.s16_pwrSplyElecPwr = 16384;
  } else if (rtb_Gain4 < -16384) {
    busAST_SlwTaskOut.s16_pwrSplyElecPwr = -16384;
  } else {
    busAST_SlwTaskOut.s16_pwrSplyElecPwr = rtb_Gain4;
  }

  /* End of Saturate: '<S5>/Saturation9' */

  /* If: '<S155>/If' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.bol_enPosSCDCalibEnFlg) {
    /* Outputs for IfAction SubSystem: '<S155>/ias_NoPosSCDCalib' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* SignalConversion generated from: '<S157>/bolFaltTurnOffFlag' incorporates:
     *  Constant: '<S156>/Constant'
     *  RelationalOperator: '<S156>/Compare'
     */
    busAST_SlwTaskOut.bol_flgShOffFlg = (busAST_SlwTaskIn.u8_stMaxFaltLvl == 3);

    /* End of Outputs for SubSystem: '<S155>/ias_NoPosSCDCalib' */
  } else {
    /* Outputs for IfAction SubSystem: '<S155>/ias_PosSCDCalib' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S155>/ias_NoPosSCDCalib' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* Logic: '<S158>/OR' incorporates:
     *  Constant: '<S156>/Constant'
     *  Constant: '<S159>/Constant'
     *  Constant: '<S160>/Constant'
     *  Constant: '<S161>/Constant'
     *  Logic: '<S158>/Logical Operator'
     *  RelationalOperator: '<S156>/Compare'
     *  RelationalOperator: '<S159>/Compare'
     *  RelationalOperator: '<S160>/Compare'
     *  RelationalOperator: '<S161>/Compare'
     *  SignalConversion generated from: '<S157>/bolFaltTurnOffFlag'
     */
    busAST_SlwTaskOut.bol_flgShOffFlg = ((busAST_SlwTaskIn.u8_stMaxFaltLvl == 3)
      || (((rtb_enmSysStas == SYSINIT) || (rtb_enmSysStas == STANDBY)) ||
          (rtb_enmSysStas == SYSFAIL)));

    /* End of Outputs for SubSystem: '<S155>/ias_NoPosSCDCalib' */
    /* End of Outputs for SubSystem: '<S155>/ias_PosSCDCalib' */
  }

  /* End of If: '<S155>/If' */

  /* Saturate: '<S16>/Saturation' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (Gu16_facComSpdFltCoeff_C > 39322) {
    rtb_Saturation = 39322U;
  } else if (Gu16_facComSpdFltCoeff_C < 4000) {
    rtb_Saturation = 4000U;
  } else {
    rtb_Saturation = Gu16_facComSpdFltCoeff_C;
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Saturate: '<S2>/Saturation11' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_nActElecSpd >= -32767) {
    y = busAST_SlwTaskIn.s16_nActElecSpd;
  } else {
    y = -32767;
  }

  /* Sum: '<S18>/Add1' incorporates:
   *  Constant: '<S18>/Constant'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Saturate: '<S16>/Saturation'
   *  Saturate: '<S2>/Saturation11'
   *  Sum: '<S18>/Add2'
   *  UnitDelay: '<S18>/Unit Delay'
   */
  rtb_Add1_dcaq = (sint16)((((y * rtb_Saturation) >> 16) + (((((131072 -
    rtb_Saturation) >> 2) * ASW_AST_DW.UnitDelay_DSTATE_i2ls) >> 15) << 1)) >> 1);

  /* Saturate: '<S4>/Saturation5' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_trqFaltRefTqLim >= -32767) {
    rtb_Saturation5 = busAST_SlwTaskIn.s16_trqFaltRefTqLim;
  } else {
    rtb_Saturation5 = -32767;
  }

  /* End of Saturate: '<S4>/Saturation5' */

  /* Saturate: '<S4>/Saturation4' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  if (Gu16_psiPermMagFlx_C > 10922) {
    u0 = 10922U;
  } else if (Gu16_psiPermMagFlx_C < 55) {
    u0 = 55U;
  } else {
    u0 = Gu16_psiPermMagFlx_C;
  }

  /* Gain: '<S31>/Gain1' incorporates:
   *  Saturate: '<S4>/Saturation4'
   */
  rtb_Gain1_mnsi = (uint16)((62915U * u0) >> 15);

  /* Product: '<S31>/Divide' incorporates:
   *  Constant: '<S31>/Cdbl_trqTqMaxVal'
   *  Gain: '<S31>/Gain1'
   */
  rtb_Divide = (uint16)(67106816U / rtb_Gain1_mnsi);

  /* MinMax: '<S31>/Min2' incorporates:
   *  Constant: '<S31>/maxPolePairPerCurr'
   *  Product: '<S31>/Divide'
   */
  if (rtb_Divide >= 33178) {
    rtb_Min2 = 33178U;
  } else {
    rtb_Min2 = rtb_Divide;
  }

  /* End of MinMax: '<S31>/Min2' */

  /* Saturate: '<S57>/Saturation' incorporates:
   *  Constant: '<S57>/Constant'
   */
  if (Gu16_facDrtnVltgFltCoeff_C <= 39322) {
    rtb_Saturation_exxs = Gu16_facDrtnVltgFltCoeff_C;
  } else {
    rtb_Saturation_exxs = 39322U;
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Saturate: '<S4>/Saturation' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.s16_uModulDaxQaxVltg[1] >= -32767) {
    y = busAST_SlwTaskIn.s16_uModulDaxQaxVltg[1];
  } else {
    y = -32767;
  }

  /* Sum: '<S59>/Add1' incorporates:
   *  Constant: '<S59>/Constant'
   *  Gain: '<S33>/Gain3'
   *  Product: '<S59>/Product'
   *  Product: '<S59>/Product1'
   *  Saturate: '<S4>/Saturation'
   *  Saturate: '<S57>/Saturation'
   *  Sum: '<S59>/Add2'
   *  UnitDelay: '<S59>/Unit Delay'
   */
  rtb_Add1 = (((((3 * y) >> 2) * rtb_Saturation_exxs) << 1) >> 2) +
    mul_ssu32_loSR(ASW_AST_DW.UnitDelay_DSTATE, (uint32)((131072 -
    rtb_Saturation_exxs) >> 2), 15U);

  /* DataTypeConversion: '<S59>/Data Type Conversion' incorporates:
   *  Sum: '<S59>/Add1'
   */
  rtb_DataTypeConversion_ei10 = (sint16)(rtb_Add1 >> 16);

  /* Abs: '<S33>/Abs' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   */
  if (rtb_DataTypeConversion_ei10 < 0) {
    rtb_Abs = (uint16)(((uint16)(-rtb_DataTypeConversion_ei10)) << 1);
  } else {
    rtb_Abs = (uint16)(rtb_DataTypeConversion_ei10 << 1);
  }

  /* End of Abs: '<S33>/Abs' */

  /* Saturate: '<S4>/Saturation1' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  if (busAST_SlwTaskIn.u16_uSplyVltg <= 32767) {
    rtb_Saturation1 = busAST_SlwTaskIn.u16_uSplyVltg;
  } else {
    rtb_Saturation1 = 32767U;
  }

  /* End of Saturate: '<S4>/Saturation1' */

  /* Lookup_n-D: '<S33>/iSplyCurrLimMap_tPCB' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  rtb_iSplyCurrLimMap_tPCB = look1_iu8lu32n16ts16Ds32_binlcs
    (busAST_SlwTaskIn.u8_tPCBTempSubs, &Gs16_iSplyCurrTempLim_CUR_tPCBTemp_X[0],
     &Gs16_iSplyCurrTempLim_CUR[0], 5U);

  /* Lookup_n-D: '<S33>/iSplyCurrLimMap_SplyVltg' incorporates:
   *  Saturate: '<S4>/Saturation1'
   */
  rtb_iSplyCurrLimMap_SplyVltg = look1_iu16lu32n16ts16D_2s4GBl96(rtb_Saturation1,
    &Gs16_iSplyCurrVltgLim_CUR_uSplyVltg_X[0], &Gs16_iSplyCurrVltgLim_CUR[0], 6U);

  /* MinMax: '<S33>/Min' incorporates:
   *  Lookup_n-D: '<S33>/iSplyCurrLimMap_SplyVltg'
   *  Lookup_n-D: '<S33>/iSplyCurrLimMap_tPCB'
   */
  if (rtb_iSplyCurrLimMap_tPCB <= rtb_iSplyCurrLimMap_SplyVltg) {
    y = rtb_iSplyCurrLimMap_tPCB;
  } else {
    y = rtb_iSplyCurrLimMap_SplyVltg;
  }

  /* Product: '<S33>/Product' incorporates:
   *  Lookup_n-D: '<S5>/Gu16_etaCtlBrd_MAP'
   *  MinMax: '<S33>/Min'
   *  Product: '<S33>/Product1'
   *  Saturate: '<S4>/Saturation1'
   */
  rtb_Product = (uint16)((((sint16)((y * rtb_Gu16_etaCtlBrd_MAP) >> 15)) *
    rtb_Saturation1) >> 13);

  /* If: '<S33>/If' incorporates:
   *  Abs: '<S33>/Abs'
   *  Logic: '<S33>/OR'
   *  Product: '<S33>/Divide'
   *  Product: '<S33>/Product'
   *  RelationalOperator: '<S33>/Relational Operator'
   *  RelationalOperator: '<S46>/Compare'
   */
  if ((rtb_Abs == 0) || (((sint32)((((uint32)rtb_Product) << 12) / 7373U)) >
                         rtb_Abs)) {
    /* Outputs for IfAction SubSystem: '<S33>/ias_Case1' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* SignalConversion generated from: '<S47>/s16_iSplyCurrEqvPhCurrLimCs1' incorporates:
     *  Constant: '<S47>/Cdbl_iPhCurrMaxVal'
     *  Merge: '<S33>/Merge'
     */
    rtb_Merge_cgss = 14746;

    /* End of Outputs for SubSystem: '<S33>/ias_Case1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S33>/ias_Case2' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* Product: '<S48>/Divide5' incorporates:
     *  Switch: '<S55>/Switch2'
     */
    rtb_Divide5 = (dt_Standardize_s16p15b0)((((uint32)rtb_Product) << 13) /
      rtb_Abs);

    /* Switch: '<S55>/Switch1' incorporates:
     *  Product: '<S48>/Divide5'
     *  RelationalOperator: '<S55>/Relational Operator1'
     *  Switch: '<S55>/Switch2'
     */
    if (rtb_Divide5 <= 14746) {
      /* Switch: '<S55>/Switch' incorporates:
       *  RelationalOperator: '<S55>/Relational Operator'
       */
      if (rtb_Divide5 >= 0) {
        /* Merge: '<S33>/Merge' */
        rtb_Merge_cgss = rtb_Divide5;
      } else {
        /* Merge: '<S33>/Merge' incorporates:
         *  Constant: '<S48>/Constant'
         */
        rtb_Merge_cgss = 0;
      }

      /* End of Switch: '<S55>/Switch' */
    } else {
      /* Merge: '<S33>/Merge' incorporates:
       *  Constant: '<S48>/Cdbl_iPhCurrMaxVal'
       */
      rtb_Merge_cgss = 14746;
    }

    /* End of Switch: '<S55>/Switch1' */
    /* End of Outputs for SubSystem: '<S33>/ias_Case2' */
  }

  /* End of If: '<S33>/If' */

  /* Switch: '<S40>/Switch2' incorporates:
   *  MinMax: '<S31>/Min2'
   *  RelationalOperator: '<S40>/Relational Operator2'
   */
  if (rtb_Min2 > 0) {
    /* Lookup_n-D: '<S31>/iPhsCurrLimMap_tPCB' incorporates:
     *  Inport: '<Root>/busAST_SlwTaskIn'
     */
    rtb_iPhsCurrLimMap_tPCB = look1_iu8lu32n16ts16Ds32_binlcs
      (busAST_SlwTaskIn.u8_tPCBTempSubs, &Gs16_iPhCurrLim_CUR_tPCBTemp_X[0],
       &Gs16_iPhCurrLim_CUR[0], 5U);

    /* MinMax: '<S31>/Min1' incorporates:
     *  Lookup_n-D: '<S31>/iPhsCurrLimMap_tPCB'
     *  Merge: '<S33>/Merge'
     */
    if (rtb_iPhsCurrLimMap_tPCB <= rtb_Merge_cgss) {
      y = rtb_iPhsCurrLimMap_tPCB;
    } else {
      y = rtb_Merge_cgss;
    }

    /* Saturate: '<S42>/Saturation' incorporates:
     *  Constant: '<S42>/Constant'
     */
    if (Gu8_numPPNum_C > 6) {
      tmp_0 = 6U;
    } else if (Gu8_numPPNum_C < 2) {
      tmp_0 = 2U;
    } else {
      tmp_0 = Gu8_numPPNum_C;
    }

    /* Product: '<S31>/Product1' incorporates:
     *  Gain: '<S31>/Gain'
     *  MinMax: '<S31>/Min1'
     *  Saturate: '<S42>/Saturation'
     */
    rtb_Product1 = (uint16)((((uint32)((uint16)(3 * y))) * tmp_0) >> 3);

    /* Switch: '<S40>/Switch1' incorporates:
     *  Product: '<S31>/Product1'
     *  RelationalOperator: '<S40>/Relational Operator1'
     */
    if (rtb_Product1 <= rtb_Min2) {
      /* Switch: '<S40>/Switch' incorporates:
       *  Switch: '<S40>/Switch2'
       */
      rtb_Switch2 = rtb_Product1;
    } else {
      /* Switch: '<S40>/Switch2' */
      rtb_Switch2 = rtb_Min2;
    }

    /* End of Switch: '<S40>/Switch1' */
  } else {
    rtb_Switch2 = 0U;
  }

  /* End of Switch: '<S40>/Switch2' */

  /* Product: '<S31>/Product2' incorporates:
   *  Gain: '<S31>/Gain1'
   *  Switch: '<S40>/Switch2'
   */
  rtb_Product2_hnnw = (dt_Standardize_s16p15b0)((((uint32)rtb_Switch2) *
    rtb_Gain1_mnsi) >> 11);

  /* Saturate: '<S45>/Saturation' incorporates:
   *  Constant: '<S45>/Constant'
   */
  if (Gs16_trqTqUpLim_C >= 0) {
    rtb_Saturation_b4dz = Gs16_trqTqUpLim_C;
  } else {
    rtb_Saturation_b4dz = 0;
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* MinMax: '<S32>/Min' incorporates:
   *  Product: '<S31>/Product2'
   *  Saturate: '<S45>/Saturation'
   *  Saturate: '<S4>/Saturation5'
   */
  if (rtb_Saturation_b4dz <= rtb_Saturation5) {
    y = rtb_Saturation_b4dz;
  } else {
    y = rtb_Saturation5;
  }

  if (y <= rtb_Product2_hnnw) {
    busAST_SlwTaskOut.s16_trqRefTqLim = y;
  } else {
    busAST_SlwTaskOut.s16_trqRefTqLim = rtb_Product2_hnnw;
  }

  /* End of MinMax: '<S32>/Min' */

  /* Chart: '<S75>/sfc_PhiModeStateMachine' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  RelationalOperator: '<S85>/Compare'
   */
  /* Gateway: AST_SlwTask/vrs_AgEvalModeCalc/rss_AgEvalModeCalcNeed/sfc_PhiModeStateMachine */
  /* During: AST_SlwTask/vrs_AgEvalModeCalc/rss_AgEvalModeCalcNeed/sfc_PhiModeStateMachine */
  if (ASW_AST_DW.is_active_c11_ASW_AST == 0U) {
    /* Entry: AST_SlwTask/vrs_AgEvalModeCalc/rss_AgEvalModeCalcNeed/sfc_PhiModeStateMachine */
    ASW_AST_DW.is_active_c11_ASW_AST = 1U;

    /* Entry Internal: AST_SlwTask/vrs_AgEvalModeCalc/rss_AgEvalModeCalcNeed/sfc_PhiModeStateMachine */
    /* Transition: '<S76>:2' */
    ASW_AST_DW.is_c11_ASW_AST = IN_SENSOR;

    /* Entry 'SENSOR': '<S76>:1' */
    rtb_enm_modeAgEvalMode = SENSOR;
  } else {
    switch (ASW_AST_DW.is_c11_ASW_AST) {
     case IN_HYBRID:
      rtb_enm_modeAgEvalMode = HYBRID;

      /* During 'HYBRID': '<S76>:3' */
      if (Genm_modeAgEvallMode_C == SENSOR) {
        /* Transition: '<S76>:111' */
        ASW_AST_DW.is_c11_ASW_AST = IN_SENSOR;

        /* Entry 'SENSOR': '<S76>:1' */
        rtb_enm_modeAgEvalMode = SENSOR;
      } else if (((busAST_SlwTaskIn.enm_stMotoSt == OFF) &&
                  (busAST_SlwTaskIn.bol_flgPhiSensFaltRawFlg)) ||
                 (Genm_modeAgEvallMode_C == SENSORLESS)) {
        /* Transition: '<S76>:124' */
        ASW_AST_DW.is_c11_ASW_AST = IN_SENSORLESS;

        /* Entry 'SENSORLESS': '<S76>:4' */
        rtb_enm_modeAgEvalMode = SENSORLESS;
      }
      break;

     case IN_SENSOR:
      rtb_enm_modeAgEvalMode = SENSOR;

      /* During 'SENSOR': '<S76>:1' */
      if (Genm_modeAgEvallMode_C == HYBRID) {
        /* Transition: '<S76>:9' */
        ASW_AST_DW.is_c11_ASW_AST = IN_HYBRID;

        /* Entry 'HYBRID': '<S76>:3' */
        rtb_enm_modeAgEvalMode = HYBRID;
      } else if (((busAST_SlwTaskIn.enm_stMotoSt == OFF) &&
                  (busAST_SlwTaskIn.bol_flgPhiSensFaltRawFlg)) ||
                 (Genm_modeAgEvallMode_C == SENSORLESS)) {
        /* Transition: '<S76>:120' */
        ASW_AST_DW.is_c11_ASW_AST = IN_SENSORLESS;

        /* Entry 'SENSORLESS': '<S76>:4' */
        rtb_enm_modeAgEvalMode = SENSORLESS;
      }
      break;

     default:
      rtb_enm_modeAgEvalMode = SENSORLESS;

      /* During 'SENSORLESS': '<S76>:4' */
      rtb_lb_incrRatLimReq_bzay = !busAST_SlwTaskIn.bol_flgPhiSensFaltRawFlg;
      if ((Genm_modeAgEvallMode_C == SENSOR) && rtb_lb_incrRatLimReq_bzay) {
        /* Transition: '<S76>:121' */
        ASW_AST_DW.is_c11_ASW_AST = IN_SENSOR;

        /* Entry 'SENSOR': '<S76>:1' */
        rtb_enm_modeAgEvalMode = SENSOR;
      } else if ((Genm_modeAgEvallMode_C == HYBRID) && rtb_lb_incrRatLimReq_bzay)
      {
        /* Transition: '<S76>:123' */
        ASW_AST_DW.is_c11_ASW_AST = IN_HYBRID;

        /* Entry 'HYBRID': '<S76>:3' */
        rtb_enm_modeAgEvalMode = HYBRID;
      }
      break;
    }
  }

  /* End of Chart: '<S75>/sfc_PhiModeStateMachine' */

  /* Outputs for Enabled SubSystem: '<S133>/ens_SensAgCalibNeed' incorporates:
   *  EnablePort: '<S135>/Enable'
   */
  /* Logic: '<S133>/Logical Operator' incorporates:
   *  Constant: '<S134>/Constant'
   *  Inport: '<Root>/busAST_SlwTaskIn'
   *  RelationalOperator: '<S134>/Compare'
   */
  if ((busAST_SlwTaskIn.bol_enPosSCDCalibEnFlg) && (rtb_enmSysStas != SYSINIT))
  {
    /* Sum: '<S135>/Add1' incorporates:
     *  Constant: '<S135>/parBetaPhsElecAngCont'
     *  Sum: '<S135>/Add'
     *  UnitDelay: '<S135>/Unit Delay1'
     *  UnitDelay: '<S135>/Unit Delay2'
     */
    rtb_Add1_gqbm = (dt_RadAng_u16r15b0)(ASW_AST_DW.UnitDelay2_DSTATE_bxby -
      ((uint16)(ASW_AST_DW.UnitDelay1_DSTATE_degb - Gu16_phiTheoBePhElecAg_C)));

    /* Switch: '<S136>/Switch3' incorporates:
     *  Constant: '<S136>/Constant2'
     *  RelationalOperator: '<S136>/Relational Operator'
     *  Sum: '<S135>/Add1'
     *  Sum: '<S136>/Add3'
     */
    if (rtb_Add1_gqbm >= 32768) {
      rtb_Switch3 = (dt_RadAng_u16r15b0)(65535 - rtb_Add1_gqbm);
    } else {
      rtb_Switch3 = rtb_Add1_gqbm;
    }

    /* End of Switch: '<S136>/Switch3' */

    /* Chart: '<S137>/sfc_SensAgCalibSTM' incorporates:
     *  Constant: '<S137>/s16_trqInitCalibRefTq'
     *  Constant: '<S137>/u16_phiInitCalibElecAg'
     *  Switch: '<S136>/Switch3'
     *  UnitDelay: '<S135>/Unit Delay3'
     */
    /* Gateway: AST_SlwTask/vrs_SensAgCalib/rss_SensAgCalibNeed/ens_SensAgCalibNeed/sss_SensAgCalib/sfc_SensAgCalibSTM */
    /* During: AST_SlwTask/vrs_SensAgCalib/rss_SensAgCalibNeed/ens_SensAgCalibNeed/sss_SensAgCalib/sfc_SensAgCalibSTM */
    if (ASW_AST_DW.is_active_c3_ASW_AST == 0U) {
      /* Entry: AST_SlwTask/vrs_SensAgCalib/rss_SensAgCalibNeed/ens_SensAgCalibNeed/sss_SensAgCalib/sfc_SensAgCalibSTM */
      ASW_AST_DW.is_active_c3_ASW_AST = 1U;

      /* Entry Internal: AST_SlwTask/vrs_SensAgCalib/rss_SensAgCalibNeed/ens_SensAgCalibNeed/sss_SensAgCalib/sfc_SensAgCalibSTM */
      /* Transition: '<S141>:2' */
      ASW_AST_DW.u8_ctTryAlgCnt = 0U;
      ASW_AST_DW.is_c3_ASW_AST = IN_ALIGN_ALPHA_PHASE1;

      /* Entry 'ALIGN_ALPHA_PHASE1': '<S141>:1' */
      ASW_AST_B.enm_stPosSCDCalibSt = ALPHA_PHASE1;
      ASW_AST_B.s16_trqPosSCDCalibRefTq = Gs16_trqRefTqAlgnVal_C;
      busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = Gu16_phiAlgnAlPhElecAg_C;
      busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
      busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
      ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
    } else {
      switch (ASW_AST_DW.is_c3_ASW_AST) {
       case IN_ALIGN_ALPHA_PHASE1:
        ASW_AST_B.enm_stPosSCDCalibSt = ALPHA_PHASE1;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;

        /* During 'ALIGN_ALPHA_PHASE1': '<S141>:1' */
        if (ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnAlPhStCnt_C) {
          /* Transition: '<S141>:113' */
          /* Exit 'ALIGN_ALPHA_PHASE1': '<S141>:1' */
          ASW_AST_B.u16_phiAlPhElecAg = busAST_SlwTaskIn.u16_phiSensActElecAg;
          ASW_AST_DW.is_c3_ASW_AST = IN_WAIT_ALPHA1;

          /* Entry 'WAIT_ALPHA1': '<S141>:137' */
          ASW_AST_B.enm_stPosSCDCalibSt = WAIT_ALPHA1;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = 0;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = 0U;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        } else {
          ASW_AST_DW.u16_ctCalibStWaitCnt++;
        }
        break;

       case IN_ALIGN_ALPHA_PHASE2:
        ASW_AST_B.enm_stPosSCDCalibSt = ALPHA_PHASE2;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;

        /* During 'ALIGN_ALPHA_PHASE2': '<S141>:142' */
        if (ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnAlPhStCnt_C) {
          /* Transition: '<S141>:145' */
          /* Exit 'ALIGN_ALPHA_PHASE2': '<S141>:142' */
          ASW_AST_B.u16_phiAlPhElecAg = busAST_SlwTaskIn.u16_phiSensActElecAg;
          ASW_AST_DW.is_c3_ASW_AST = IN_WAIT_ALPHA2;

          /* Entry 'WAIT_ALPHA2': '<S141>:144' */
          ASW_AST_B.enm_stPosSCDCalibSt = WAIT_ALPHA2;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = 0;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = 0U;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        } else {
          ASW_AST_DW.u16_ctCalibStWaitCnt++;
        }
        break;

       case IN_ALIGN_BETA_PHASE:
        ASW_AST_B.enm_stPosSCDCalibSt = BETA_PHASE;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;

        /* During 'ALIGN_BETA_PHASE': '<S141>:111' */
        if (ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnBePhStCnt_C) {
          /* Transition: '<S141>:135' */
          /* Exit 'ALIGN_BETA_PHASE': '<S141>:111' */
          ASW_AST_B.u16_phiBePhElecAg = busAST_SlwTaskIn.u16_phiSensActElecAg;
          ASW_AST_DW.is_c3_ASW_AST = IN_WAIT_BETA;

          /* Entry 'WAIT_BETA': '<S141>:134' */
          ASW_AST_B.enm_stPosSCDCalibSt = WAIT_BETA;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = 0;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = 0U;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        } else {
          ASW_AST_DW.u16_ctCalibStWaitCnt++;
        }
        break;

       case IN_CALIBFAIL:
        ASW_AST_B.enm_stPosSCDCalibSt = CALIBFAIL;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;

        /* During 'CALIBFAIL': '<S141>:117' */
        if (ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnTmpFailStCnt_C) {
          /* Transition: '<S141>:120' */
          /* Exit 'CALIBFAIL': '<S141>:117' */
          ASW_AST_DW.is_c3_ASW_AST = IN_ALIGN_ALPHA_PHASE1;

          /* Entry 'ALIGN_ALPHA_PHASE1': '<S141>:1' */
          ASW_AST_B.enm_stPosSCDCalibSt = ALPHA_PHASE1;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = Gs16_trqRefTqAlgnVal_C;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = Gu16_phiAlgnAlPhElecAg_C;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        } else if (ASW_AST_DW.u8_ctTryAlgCnt < 2) {
          ASW_AST_DW.u16_ctCalibStWaitCnt++;
        } else {
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        }
        break;

       case IN_SUCCESS:
        ASW_AST_B.enm_stPosSCDCalibSt = SUCCESS;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = true;

        /* During 'SUCCESS': '<S141>:114' */
        break;

       case IN_WAIT_ALPHA1:
        ASW_AST_B.enm_stPosSCDCalibSt = WAIT_ALPHA1;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;

        /* During 'WAIT_ALPHA1': '<S141>:137' */
        if (ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnWaitAlStCnt_C) {
          /* Transition: '<S141>:138' */
          /* Exit 'WAIT_ALPHA1': '<S141>:137' */
          ASW_AST_DW.is_c3_ASW_AST = IN_ALIGN_BETA_PHASE;

          /* Entry 'ALIGN_BETA_PHASE': '<S141>:111' */
          ASW_AST_B.enm_stPosSCDCalibSt = BETA_PHASE;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = Gs16_trqRefTqAlgnVal_C;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = Gu16_phiAlgnBePhElecAg_C;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        } else {
          ASW_AST_DW.u16_ctCalibStWaitCnt++;
        }
        break;

       case IN_WAIT_ALPHA2:
        ASW_AST_B.enm_stPosSCDCalibSt = WAIT_ALPHA2;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;

        /* During 'WAIT_ALPHA2': '<S141>:144' */
        if ((ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnWaitAlStCnt_C) &&
            (rtb_Switch3 <= Gu16_phiMinAlgnElecAngDvt_C)) {
          /* Transition: '<S141>:116' */
          /* Exit 'WAIT_ALPHA2': '<S141>:144' */
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
          ASW_AST_DW.is_c3_ASW_AST = IN_SUCCESS;

          /* Entry 'SUCCESS': '<S141>:114' */
          ASW_AST_B.enm_stPosSCDCalibSt = SUCCESS;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = 0;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = 0U;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = true;
          ASW_AST_B.u16_phiSensElecAgDvt = ASW_AST_DW.UnitDelay3_DSTATE;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
        } else if ((ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnWaitAlStCnt_C)
                   && (rtb_Switch3 > Gu16_phiMinAlgnElecAngDvt_C)) {
          /* Transition: '<S141>:118' */
          /* Exit 'WAIT_ALPHA2': '<S141>:144' */
          ASW_AST_DW.is_c3_ASW_AST = IN_CALIBFAIL;

          /* Entry 'CALIBFAIL': '<S141>:117' */
          ASW_AST_B.enm_stPosSCDCalibSt = CALIBFAIL;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = 0;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = 0U;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail =
            ((ASW_AST_DW.u8_ctTryAlgCnt == 2) ||
             (busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail));
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        } else {
          tmp = ASW_AST_DW.u16_ctCalibStWaitCnt + 1U;
          if ((ASW_AST_DW.u16_ctCalibStWaitCnt + 1U) > 65535U) {
            tmp = 65535U;
          }

          ASW_AST_DW.u16_ctCalibStWaitCnt = (uint16)tmp;
        }
        break;

       default:
        ASW_AST_B.enm_stPosSCDCalibSt = WAIT_BETA;
        busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;

        /* During 'WAIT_BETA': '<S141>:134' */
        if (ASW_AST_DW.u16_ctCalibStWaitCnt >= Gu16_ctAlgnWaitBeStCnt_C) {
          /* Transition: '<S141>:143' */
          /* Exit 'WAIT_BETA': '<S141>:134' */
          i_0 = (sint32)(ASW_AST_DW.u8_ctTryAlgCnt + 1U);
          if ((ASW_AST_DW.u8_ctTryAlgCnt + 1U) > 255U) {
            i_0 = 255;
          }

          ASW_AST_DW.u8_ctTryAlgCnt = (uint8)i_0;
          ASW_AST_DW.is_c3_ASW_AST = IN_ALIGN_ALPHA_PHASE2;

          /* Entry 'ALIGN_ALPHA_PHASE2': '<S141>:142' */
          ASW_AST_B.enm_stPosSCDCalibSt = ALPHA_PHASE2;
          ASW_AST_B.s16_trqPosSCDCalibRefTq = Gs16_trqRefTqAlgnVal_C;
          busAST_SlwTaskOut.u16_phiPosSCDCalibElecAg = Gu16_phiAlgnAlPhElecAg_C;
          busAST_SlwTaskOut.bol_flgPosSCDCalibSucFlg = false;
          busAST_SlwTaskOut.bol_flgPosSCDCalibPermFail = false;
          ASW_AST_DW.u16_ctCalibStWaitCnt = 0U;
        } else {
          ASW_AST_DW.u16_ctCalibStWaitCnt++;
        }
        break;
      }
    }

    /* End of Chart: '<S137>/sfc_SensAgCalibSTM' */

    /* Saturate: '<S143>/Saturation' incorporates:
     *  Constant: '<S143>/Constant'
     */
    if (Gu8_numPPNum_C > 6) {
      tmp_0 = 6U;
    } else if (Gu8_numPPNum_C < 2) {
      tmp_0 = 2U;
    } else {
      tmp_0 = Gu8_numPPNum_C;
    }

    /* Product: '<S137>/Divide' incorporates:
     *  Gain: '<S137>/Gain1'
     *  Saturate: '<S143>/Saturation'
     */
    busAST_SlwTaskOut.u16_ADSensMechAgDvt = (uint16)(((((20861U *
      ASW_AST_B.u16_phiSensElecAgDvt) >> 15) * 3217U) >> 11) / tmp_0);

    /* Switch: '<S148>/Switch1' incorporates:
     *  UnitDelay: '<S148>/Unit Delay1'
     */
    if (ASW_AST_DW.bitsForTID1.UnitDelay1_DSTATE_hfoe) {
      /* Switch: '<S148>/Switch' incorporates:
       *  UnitDelay: '<S148>/Unit Delay'
       */
      rtb_Switch_eeka = ASW_AST_DW.UnitDelay_DSTATE_aj2h;
    } else {
      /* Switch: '<S148>/Switch' incorporates:
       *  Constant: '<S137>/Constant2'
       */
      rtb_Switch_eeka = 0;
    }

    /* End of Switch: '<S148>/Switch1' */

    /* Chart: '<S139>/Chart' incorporates:
     *  Constant: '<S146>/Constant1'
     *  Constant: '<S147>/Constant1'
     *  DataTypeConversion: '<S146>/Data Type Conversion'
     *  DataTypeConversion: '<S147>/Data Type Conversion'
     *  Logic: '<S146>/Logical Operator'
     *  Logic: '<S147>/Logical Operator'
     *  Product: '<S146>/Product'
     *  Product: '<S147>/Product'
     *  RelationalOperator: '<S146>/Equal'
     *  RelationalOperator: '<S146>/Equal1'
     *  RelationalOperator: '<S147>/Equal'
     *  RelationalOperator: '<S147>/Equal1'
     *  Sum: '<S146>/Add'
     *  Sum: '<S147>/Add'
     *  Switch: '<S148>/Switch'
     */
    ASW_AST_Chart(((((sint16)mul_ssu32_hiSR((ASW_AST_B.s16_trqPosSCDCalibRefTq -
      rtb_Switch_eeka) << 15, 26214425U, 9U)) >= (Gs16_facAlgnTqRiseRate_C >> 2))
                   && (ASW_AST_B.s16_trqPosSCDCalibRefTq >= rtb_Switch_eeka)),
                  ((((sint16)mul_ssu32_hiSR((ASW_AST_B.s16_trqPosSCDCalibRefTq -
      rtb_Switch_eeka) << 15, 26214425U, 9U)) <= (Gs16_facAlgnTqFallRate_C >> 2))
                   && (ASW_AST_B.s16_trqPosSCDCalibRefTq <= rtb_Switch_eeka)),
                  &rtb_lb_noRatLimReq_m20l, &rtb_lb_incrRatLimReq_bzay,
                  &rtb_lb_decrRatLimReq_e0p2);

    /* Switch: '<S145>/Switch1' incorporates:
     *  Constant: '<S145>/Constant'
     *  Constant: '<S145>/Constant1'
     *  Switch: '<S145>/Switch'
     */
    if (rtb_lb_noRatLimReq_m20l) {
      y = 0;
    } else if (rtb_lb_incrRatLimReq_bzay) {
      /* Switch: '<S145>/Switch' incorporates:
       *  Constant: '<S145>/Constant2'
       */
      y = Gs16_facAlgnTqRiseRate_C;
    } else {
      y = Gs16_facAlgnTqFallRate_C;
    }

    /* Sum: '<S145>/Add1' incorporates:
     *  Constant: '<S145>/Constant4'
     *  Product: '<S145>/Divide1'
     *  Switch: '<S145>/Switch1'
     *  Switch: '<S148>/Switch'
     */
    rtb_Add1_np2v = (dt_Standardize_s16p15b0)((((sint16)((y * 41943) >> 11)) +
      (rtb_Switch_eeka << 5)) >> 5);

    /* Switch: '<S139>/Switch' incorporates:
     *  Sum: '<S145>/Add1'
     */
    if (rtb_lb_noRatLimReq_m20l) {
      busAST_SlwTaskOut.s16_trqPosSCDCalibRefTq =
        ASW_AST_B.s16_trqPosSCDCalibRefTq;
    } else {
      busAST_SlwTaskOut.s16_trqPosSCDCalibRefTq = rtb_Add1_np2v;
    }

    /* End of Switch: '<S139>/Switch' */

    /* Update for UnitDelay: '<S135>/Unit Delay1' */
    ASW_AST_DW.UnitDelay1_DSTATE_degb = ASW_AST_B.u16_phiBePhElecAg;

    /* Update for UnitDelay: '<S135>/Unit Delay2' */
    ASW_AST_DW.UnitDelay2_DSTATE_bxby = ASW_AST_B.u16_phiAlPhElecAg;

    /* Update for UnitDelay: '<S135>/Unit Delay3' */
    ASW_AST_DW.UnitDelay3_DSTATE = ASW_AST_B.u16_phiAlPhElecAg;

    /* Update for UnitDelay: '<S148>/Unit Delay1' incorporates:
     *  Constant: '<S148>/Constant'
     */
    ASW_AST_DW.bitsForTID1.UnitDelay1_DSTATE_hfoe = true;

    /* Update for UnitDelay: '<S148>/Unit Delay' incorporates:
     *  Sum: '<S145>/Add1'
     */
    ASW_AST_DW.UnitDelay_DSTATE_aj2h = rtb_Add1_np2v;
  }

  /* End of Logic: '<S133>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S133>/ens_SensAgCalibNeed' */

  /* BusCreator: '<S163>/Bus Creator1' incorporates:
   *  Product: '<S22>/Divide'
   *  Product: '<S5>/Divide1'
   *  Product: '<S78>/Divide2'
   *  Sum: '<S18>/Add1'
   *  Switch: '<S78>/Switch4'
   */
  busAST_SlwTaskOut.s16_iEstSplyCurr = rtb_Divide1_azfz;
  busAST_SlwTaskOut.s16_ampActPhCurrAmp = rtb_Divide_gqgg;
  busAST_SlwTaskOut.enm_stPosSCDCalibSt = ASW_AST_B.enm_stPosSCDCalibSt;
  busAST_SlwTaskOut.s16_nRmpRefElecSpd = rtb_Switch4;
  busAST_SlwTaskOut.s16_nRefElecSpd = rtb_Divide2;
  busAST_SlwTaskOut.enm_stSysSt = rtb_enmSysStas;
  busAST_SlwTaskOut.enm_modeAgEvalMode = rtb_enm_modeAgEvalMode;
  busAST_SlwTaskOut.u16_phiSensElecAgDvt = ASW_AST_B.u16_phiSensElecAgDvt;
  busAST_SlwTaskOut.s16_nActElecSpdComFlt = rtb_Add1_dcaq;

  /* Update for S-Function (sfix_udelay): '<S22>/Tapped Delay' incorporates:
   *  Merge: '<S21>/Merge'
   *  S-Function (sfix_udelay): '<S73>/Tapped Delay'
   *  Sum: '<S22>/Sum of Elements'
   *  Sum: '<S73>/Sum of Elements'
   */
  for (i_0 = 0; i_0 < 18; i_0++) {
    ASW_AST_DW.TappedDelay_DWORK1[i_0] = ASW_AST_DW.TappedDelay_DWORK1[i_0 + 1];
  }

  ASW_AST_DW.TappedDelay_DWORK1[18] = ASW_AST_B.Merge;

  /* Update for UnitDelay: '<S78>/Unit Delay' incorporates:
   *  Inport: '<Root>/busAST_SlwTaskIn'
   */
  ASW_AST_DW.UnitDelay_DSTATE_jm5t = busAST_SlwTaskIn.enm_stMotoSt;

  /* Update for UnitDelay: '<S78>/Unit Delay1' incorporates:
   *  Switch: '<S78>/Switch4'
   */
  ASW_AST_DW.UnitDelay1_DSTATE = rtb_Switch4;

  /* Update for UnitDelay: '<S101>/Unit Delay1' incorporates:
   *  Constant: '<S101>/Constant'
   */
  ASW_AST_DW.bitsForTID1.UnitDelay1_DSTATE_hx0c = true;

  /* Update for UnitDelay: '<S101>/Unit Delay' incorporates:
   *  Sum: '<S98>/Add1'
   */
  ASW_AST_DW.UnitDelay_DSTATE_m2qg = rtb_Add1_jyuu;

  /* Update for UnitDelay: '<S78>/Unit Delay2' incorporates:
   *  Switch: '<S78>/Switch4'
   */
  ASW_AST_DW.UnitDelay2_DSTATE = rtb_Switch4;

  /* Update for UnitDelay: '<S112>/Unit Delay1' incorporates:
   *  Constant: '<S112>/Constant'
   */
  ASW_AST_DW.bitsForTID1.UnitDelay1_DSTATE_k25k = true;

  /* Update for UnitDelay: '<S112>/Unit Delay' incorporates:
   *  Sum: '<S109>/Add1'
   */
  ASW_AST_DW.UnitDelay_DSTATE_ozdy = rtb_Add1_ceyr;

  /* Update for S-Function (sfix_udelay): '<S73>/Tapped Delay' incorporates:
   *  S-Function (sfix_udelay): '<S22>/Tapped Delay'
   *  Saturate: '<S5>/Saturation4'
   *  Sum: '<S22>/Sum of Elements'
   *  Sum: '<S73>/Sum of Elements'
   */
  for (i_0 = 0; i_0 < 38; i_0++) {
    ASW_AST_DW.TappedDelay_DWORK1_msrl[i_0] =
      ASW_AST_DW.TappedDelay_DWORK1_msrl[i_0 + 1];
  }

  ASW_AST_DW.TappedDelay_DWORK1_msrl[38] = ASW_AST_B.Saturation4;

  /* Update for UnitDelay: '<S18>/Unit Delay' incorporates:
   *  Sum: '<S18>/Add1'
   */
  ASW_AST_DW.UnitDelay_DSTATE_i2ls = rtb_Add1_dcaq;

  /* Update for UnitDelay: '<S59>/Unit Delay' incorporates:
   *  Sum: '<S59>/Add1'
   */
  ASW_AST_DW.UnitDelay_DSTATE = rtb_Add1;
}


/*
 * File trailer for generated code.
 *
 * [EOF]
 */
