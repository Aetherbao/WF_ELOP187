/*
 * File: ASW_PhVltgGen.c
 *
 * Code generated for Simulink model 'ASW_PhVltgGen'.
 *
 * Model version                  : 6.211
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Mar 25 10:39:31 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ASW_PhVltgGen.h"
#include "../ASW_par/motor_control_param.h"
#include "../ASW_par/motor_param.h"
#include "../ASW_share/custom_type_definition.h"
#include "../ASW_share/look2_iu8s16lu32n16tu16_binlcse.h"
#include "../ASW_share/motor_control_interface.h"
#include "../ASW_share/mul_ssu32_loSR.h"
#include "../ASW_share/rtwtypes.h"
#include "ASW_PhVltgGen_private.h"
//#include "../ASW_share/const_params.c"
#include <string.h>

/* Named constants for Chart: '<S194>/sfc_IntegratorScheduler' */
#define IN_INTG1OFF_INTG2ON ((uint8)1U)
#define IN_INTG1ON_INTG2OFF ((uint8)2U)
#define IN_INTG1ON_INTG2ON ((uint8)3U)
#define IN_NO_ACTIVE_CHILD ((uint8)0U)

/* Named constants for Chart: '<S68>/sfc_FaultDebounce' */
#define IN_Confirm ((uint8)1U)
#define IN_Confirming ((uint8)2U)
#define IN_NO_ACTIVE_CHILD_izdp ((uint8)0U)
#define IN_Repairing ((uint8)3U)
#define IN_Wait ((uint8)4U)

const BUS_PHVLTGGEN_MED_TASK_OUT ASW_PhVltgGen_rtZBUS_PHVLTGGEN_MED_TASK_OUT = {
    0U, /* u16_ampDycAmp */
    0U, /* u16_phiDaxQaxVltgAg */
    0U, /* u16_phiActElecAg */
    0,  /* s16_nActElecSpd */

    {0, 0}, /* s16_iActDaxQaxCurr */
    0,      /* s16_nPredActElecSpd */

    {0, 0}, /* s16_uModulDaxQaxVltg */
    0U,     /* u16_phiSenlElecAgSensElecAgDvt */
    0U,     /* u16_psiEstPermMagFlx */
    0       /* s16_phiOpnLpAgClsLpAgDvt */
};          /* BUS_PHVLTGGEN_MED_TASK_OUT ground */

/* Exported block signals */
BUS_PHVLTGGEN_MED_TASK_IN
    busPhVltgGen_MedTaskIn; /* '<Root>/busPhVltgGen_MedTaskIn' */
BUS_PHVLTGGEN_MED_TASK_OUT busPhVltgGen_MedTaskOut; /* '<S339>/Bus Creator1' */

/* Block signals (default storage) */
B_ASW_PhVltgGen ASW_PhVltgGen_B;

/* Block states (default storage) */
DW_ASW_PhVltgGen ASW_PhVltgGen_DW;

/* Real-time model */
static RT_MODEL_ASW_PhVltgGen ASW_PhVltgGen_M_;
RT_MODEL_ASW_PhVltgGen *const ASW_PhVltgGen_M = &ASW_PhVltgGen_M_;
static void rate_scheduler(void);
const BUS_PHVLTGGEN_MED_TASK_IN ASW_PhVltgGen_rtZBUS_PHVLTGGEN_ = {
    {0, 0}, /* s16_iRefDaxQaxCurr */

    {0, 0, 0}, /* s16_iActPhCurr */
    0U,        /* u16_phiSensActElecAg */
    0U,        /* u16_uSplyVltg */
    0U,        /* enm_stMotoSt */
    0U,        /* u16_phiModulActElecAg */
    0U,        /* u16_phiPosSCDCalibElecAg */

    {0U, 0U, 0U}, /* u16_dcycPhDyc */
    false,        /* bol_enPosSCDCalibEnFlg */
    0U,           /* enm_modeAgEvalMode */
    0,            /* s16_nRmpRefElecSpd */
    40U,          /* u8_tPCBTempSubs */
    0U            /* u16_ampMaxNrmVltgAmp */
};

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void) {
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ASW_PhVltgGen_M->Timing.TaskCounters.TID[1])++;
  if ((ASW_PhVltgGen_M->Timing.TaskCounters.TID[1]) >
      3) { /* Sample time: [0.0005s, 0.0s] */
    ASW_PhVltgGen_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S194>/sfc_IntegratorScheduler'
 *    '<S195>/sfc_IntegratorScheduler'
 */
void AS_sfc_IntegratorScheduler_Init(boolean *rty_bolIntg1RsetCond,
                                     boolean *rty_bolIntg2RsetCond,
                                     boolean *rty_bolIntg1Ok,
                                     DW_sfc_IntegratorScheduler_ASW_ *localDW) {
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c18_ASW_PhVltgGen = 0U;
  localDW->is_c18_ASW_PhVltgGen = IN_NO_ACTIVE_CHILD;
  *rty_bolIntg1RsetCond = false;
  *rty_bolIntg2RsetCond = false;
  *rty_bolIntg1Ok = false;
}

/*
 * Output and update for atomic system:
 *    '<S194>/sfc_IntegratorScheduler'
 *    '<S195>/sfc_IntegratorScheduler'
 */
void ASW_PhV_sfc_IntegratorScheduler(sint16 rtu_mfIntg1Outp,
                                     sint16 rtu_mfIntg2Outp,
                                     boolean *rty_bolIntg1RsetCond,
                                     boolean *rty_bolIntg2RsetCond,
                                     boolean *rty_bolIntg1Ok,
                                     DW_sfc_IntegratorScheduler_ASW_ *localDW) {
  sint32 tmp_0;
  sint16 tmp;

  /* Gateway:
   * PhVltgGen_MedTask/vrs_ActElecAgElecSpdCmpt/rss_ActElecAgElecSpdCmptHybr/sss_SenlActElecAgElecSpdEst/lib_FlxObs_0/sss_FluxAlphaBetaEstimation/sss_AlphaMagneticFlux/sfc_IntegratorScheduler
   */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S194>/sfc_IntegratorScheduler' */
  /* During:
   * PhVltgGen_MedTask/vrs_ActElecAgElecSpdCmpt/rss_ActElecAgElecSpdCmptHybr/sss_SenlActElecAgElecSpdEst/lib_FlxObs_0/sss_FluxAlphaBetaEstimation/sss_AlphaMagneticFlux/sfc_IntegratorScheduler
   */
  if (localDW->is_active_c18_ASW_PhVltgGen == 0U) {
    /* Entry:
     * PhVltgGen_MedTask/vrs_ActElecAgElecSpdCmpt/rss_ActElecAgElecSpdCmptHybr/sss_SenlActElecAgElecSpdEst/lib_FlxObs_0/sss_FluxAlphaBetaEstimation/sss_AlphaMagneticFlux/sfc_IntegratorScheduler
     */
    localDW->is_active_c18_ASW_PhVltgGen = 1U;

    /* Entry Internal:
     * PhVltgGen_MedTask/vrs_ActElecAgElecSpdCmpt/rss_ActElecAgElecSpdCmptHybr/sss_SenlActElecAgElecSpdEst/lib_FlxObs_0/sss_FluxAlphaBetaEstimation/sss_AlphaMagneticFlux/sfc_IntegratorScheduler
     */
    /* Transition: '<S205>:7' */
    localDW->is_c18_ASW_PhVltgGen = IN_INTG1ON_INTG2OFF;

    /* Entry 'INTG1ON_INTG2OFF': '<S205>:6' */
    *rty_bolIntg1RsetCond = false;
    *rty_bolIntg2RsetCond = true;
    *rty_bolIntg1Ok = true;
  } else {
    switch (localDW->is_c18_ASW_PhVltgGen) {
    case IN_INTG1OFF_INTG2ON:
      *rty_bolIntg1RsetCond = true;
      *rty_bolIntg2RsetCond = false;
      *rty_bolIntg1Ok = false;

      /* During 'INTG1OFF_INTG2ON': '<S205>:9' */
      if (rtu_mfIntg2Outp < 0) {
        tmp_0 = -rtu_mfIntg2Outp;
        if ((-rtu_mfIntg2Outp) > 32767) {
          tmp_0 = 32767;
        }

        tmp = (sint16)tmp_0;
      } else {
        tmp = rtu_mfIntg2Outp;
      }

      if (tmp >= 13107) {
        /* Transition: '<S205>:25' */
        localDW->is_c18_ASW_PhVltgGen = IN_INTG1ON_INTG2ON;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'INTG1ON_INTG2ON': '<S205>:8' */
        *rty_bolIntg1RsetCond = false;
        *rty_bolIntg2RsetCond = false;
      }
      break;

    case IN_INTG1ON_INTG2OFF:
      *rty_bolIntg1RsetCond = false;
      *rty_bolIntg2RsetCond = true;
      *rty_bolIntg1Ok = true;

      /* During 'INTG1ON_INTG2OFF': '<S205>:6' */
      if (rtu_mfIntg1Outp < 0) {
        tmp_0 = -rtu_mfIntg1Outp;
        if ((-rtu_mfIntg1Outp) > 32767) {
          tmp_0 = 32767;
        }

        tmp = (sint16)tmp_0;
      } else {
        tmp = rtu_mfIntg1Outp;
      }

      if (tmp >= 13107) {
        /* Transition: '<S205>:14' */
        localDW->is_c18_ASW_PhVltgGen = IN_INTG1ON_INTG2ON;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'INTG1ON_INTG2ON': '<S205>:8' */
        *rty_bolIntg1RsetCond = false;
        *rty_bolIntg2RsetCond = false;
      }
      break;

    default:
      *rty_bolIntg1RsetCond = false;
      *rty_bolIntg2RsetCond = false;

      /* During 'INTG1ON_INTG2ON': '<S205>:8' */
      if ((localDW->temporalCounter_i1 >= 300) && (*rty_bolIntg1Ok)) {
        /* Transition: '<S205>:20' */
        localDW->is_c18_ASW_PhVltgGen = IN_INTG1OFF_INTG2ON;

        /* Entry 'INTG1OFF_INTG2ON': '<S205>:9' */
        *rty_bolIntg1RsetCond = true;
        *rty_bolIntg2RsetCond = false;
        *rty_bolIntg1Ok = false;
      } else if ((localDW->temporalCounter_i1 >= 300) && (!(*rty_bolIntg1Ok))) {
        /* Transition: '<S205>:27' */
        localDW->is_c18_ASW_PhVltgGen = IN_INTG1ON_INTG2OFF;

        /* Entry 'INTG1ON_INTG2OFF': '<S205>:6' */
        *rty_bolIntg1RsetCond = false;
        *rty_bolIntg2RsetCond = true;
        *rty_bolIntg1Ok = true;
      }
      break;
    }
  }

  /* End of Chart: '<S194>/sfc_IntegratorScheduler' */
}

/* System initialize for atomic system: '<Root>/PhVltgGen_MedTask' */
void PhVltgGen_MedTask_Init(void) {
  boolean rtb_bolIntg1RsetCond_fyi0;
  boolean rtb_bolIntg2RsetCond_bt4j;

  /* SystemInitialize for Atomic SubSystem: '<S42>/lib_Deb_0' */
  /* SystemInitialize for Chart: '<S68>/sfc_FaultDebounce' */
  ASW_PhVltgGen_DW.is_active_c7_lib_debounce = 0U;
  ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_NO_ACTIVE_CHILD_izdp;
  ASW_PhVltgGen_DW.lb_cntDebCond = 0U;

  /* End of SystemInitialize for SubSystem: '<S42>/lib_Deb_0' */

  /* SystemInitialize for Chart: '<S194>/sfc_IntegratorScheduler' */
  AS_sfc_IntegratorScheduler_Init(&rtb_bolIntg1RsetCond_fyi0,
                                  &rtb_bolIntg2RsetCond_bt4j,
                                  &ASW_PhVltgGen_B.bolIntg1Ok_crdb,
                                  &ASW_PhVltgGen_DW.sf_sfc_IntegratorScheduler);

  /* SystemInitialize for Chart: '<S195>/sfc_IntegratorScheduler' */
  AS_sfc_IntegratorScheduler_Init(
      &rtb_bolIntg1RsetCond_fyi0, &rtb_bolIntg2RsetCond_bt4j,
      &ASW_PhVltgGen_B.bolIntg1Ok,
      &ASW_PhVltgGen_DW.sf_sfc_IntegratorScheduler_cr3h);
}

/* Output and update for atomic system: '<Root>/PhVltgGen_MedTask' */
void PhVltgGen_MedTask(void) {
  sint32 rtb_DataTypeConversion;
  sint32 rtb_DataTypeConversion1;
  sint32 rtb_DataTypeConversion1_acqu;
  sint32 rtb_DataTypeConversion1_i3ac;
  sint32 rtb_DataTypeConversion_bgrg;
  sint32 rtb_DataTypeConversion_lkol;
  sint32 rtb_Sum;
  sint32 rtb_Sum_g421;
  sint32 rtb_Sum_krjk;
  sint32 rtb_Switch1;
  sint32 rtb_Switch1_bxrl;
  sint32 rtb_Switch1_gm5h;
  sint32 rtb_Switch2;
  sint32 rtb_Switch2_obfd;
  sint32 rtb_Switch2_owyv;
  sint32 rtb_TmpSignalConversionAtBusC_2;
  sint32 rtb_TmpSignalConversionAtBusC_3;
  sint32 rtb_lb_propActn;
  sint32 rtb_lb_propActn_i4nd;
  sint32 rtb_lb_propActn_pdav;
  dt_RadAng_u16r15b0 rtb_Add1;
  dt_RadAng_u16r15b0 rtb_Add2;
  dt_RadAng_u16r15b0 rtb_Merge1;
  dt_RadAng_u16r15b0 rtb_Switch1_d0v1;
  dt_RadAng_u16r15b0 rtb_Switch_agfx;
  dt_Standardize_s16p15b0 rtb_Abs1_afkz;
  dt_Standardize_s16p15b0 rtb_Abs1_bbct;
  dt_Standardize_s16p15b0 rtb_Abs_atjh;
  dt_Standardize_s16p15b0 rtb_Abs_jfp3;
  dt_Standardize_s16p15b0 rtb_Abs_maf2;
  dt_Standardize_s16p15b0 rtb_Add1_cq0f;
  dt_Standardize_s16p15b0 rtb_Add1_f4ha;
  dt_Standardize_s16p15b0 rtb_Add_dots;
  dt_Standardize_s16p15b0 rtb_Add_in30;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_bcnl;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_gwbl;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_hco0;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_jzfl;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_mweb;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_o3w2;
  dt_Standardize_s16p15b0 rtb_Gain1_mdnf;
  dt_Standardize_s16p15b0 rtb_Merge_mz25;
  dt_Standardize_s16p15b0 rtb_Product1_ccy0;
  dt_Standardize_s16p15b0 rtb_Product1_dtaz;
  dt_Standardize_s16p15b0 rtb_Product_bnwf;
  dt_Standardize_s16p15b0 rtb_Saturation1_cdwd;
  dt_Standardize_s16p15b0 rtb_Saturation1_htvq;
  dt_Standardize_s16p15b0 rtb_Saturation3_pseh;
  dt_Standardize_s16p15b0 rtb_Saturation4_c3u0;
  dt_Standardize_s16p15b0 rtb_Saturation4_ectf;
  dt_Standardize_s16p15b0 rtb_Saturation4_ioke;
  dt_Standardize_s16p15b0 rtb_Saturation5;
  dt_Standardize_s16p15b0 rtb_Saturation_cnrk;
  dt_Standardize_s16p15b0 rtb_Saturation_f2a5_idx_0;
  dt_Standardize_s16p15b0 rtb_Saturation_lsvn;
  dt_Standardize_s16p15b0 rtb_Switch1_bgmj;
  dt_Standardize_s16p15b0 rtb_Switch1_jfzu;
  dt_Standardize_s16p15b0 rtb_Switch1_k0pc;
  dt_Standardize_s16p15b0 rtb_Switch1_ma0d;
  dt_Standardize_s16p15b0 rtb_Switch3;
  dt_Standardize_s16p15b0 rtb_Switch3_eodk;
  dt_Standardize_s16p15b0 rtb_TmpSignalConversionAtBusC_0;
  dt_Standardize_s16p15b0 rtb_TmpSignalConversionAtBusC_1;
  dt_Standardize_s16p15b0 rtb_lb_genMaxInpMods;
  dt_Standardize_s16p15b0 rtb_lb_genMaxInpMods_j3r1;
  dt_Standardize_s16p15b0 tmp;
  dt_Standardize_u16p15b0 rtb_Merge_kvzd;
  dt_Standardize_u16p15b0 rtb_Product;
  dt_Standardize_u16p15b0 rtb_Saturation1;
  dt_Standardize_u16p15b0 rtb_Saturation1_iw11;
  dt_Standardize_u16p15b0 rtb_Saturation_bskp;
  sint16 rtb_Add1_afic;
  sint16 rtb_Add1_bfl0;
  sint16 rtb_Add1_btax;
  sint16 rtb_Add1_k5op;
  sint16 rtb_Add1_mzgk;
  sint16 rtb_Add2_aalz;
  sint16 rtb_Add2_bakf;
  sint16 rtb_Add2_doeq;
  sint16 rtb_Add3;
  sint16 rtb_Add3_by2i;
  sint16 rtb_Add3_chim;
  sint16 rtb_Add3_cxwa;
  sint16 rtb_Add_d05d;
  sint16 rtb_Add_efob;
  sint16 rtb_DataTypeConversion1_dd3w;
  sint16 rtb_DataTypeConversion1_dkcs;
  sint16 rtb_DataTypeConversion1_eqye;
  sint16 rtb_DataTypeConversion_a45q;
  sint16 rtb_DataTypeConversion_bmde;
  sint16 rtb_DataTypeConversion_des1_i_0;
  sint16 rtb_DataTypeConversion_des1_idx;
  sint16 rtb_DataTypeConversion_esjp;
  sint16 rtb_Gain2;
  sint16 rtb_Gain3;
  sint16 rtb_Selector1_blvz;
  sint16 rtb_Selector1_chuf;
  sint16 rtb_Selector1_hkbk;
  sint16 rtb_Selector1_jaut;
  sint16 rtb_Selector1_ngzw;
  sint16 rtb_Selector1_prdr;
  sint16 rtb_Subtract;
  sint16 rtb_Sum_cwuo;
  sint16 rtb_Sum_d2gz;
  sint16 rtb_Sum_g2hx;
  sint16 rtb_Sum_icq1;
  sint16 rtb_Sum_juht;
  sint16 rtb_Switch1_ffta;
  sint16 rtb_Switch1_kp25;
  sint16 rtb_Switch2_aaxv;
  sint16 rtb_lb_inpDev;
  sint16 rtb_lb_tmprInpDev;
  sint16 tmp_1;
  uint16 rtb_DataTypeConversion1_gn4i;
  uint16 rtb_DataTypeConversion1_jrjz;
  uint16 rtb_Gain7;
  uint16 rtb_Gain8;
  uint16 rtb_Gu16_facPLLCtlKi_MAP;
  uint16 rtb_Gu16_facPLLCtlKp_MAP;
  uint16 rtb_Saturation_pmq2;
  uint16 rtb_Sum_e45u;
  uint16 rtb_Sum_new3;
  uint16 u0;
  boolean rtb_Compare;
  boolean rtb_Compare_chmk;
  boolean rtb_LogicalOperator1;
  boolean rtb_LogicalOperator4;
  boolean rtb_LogicalOperator_lnae;
  boolean rtb_LogicalOperator_lwqz;
  boolean rtb_OR;
  boolean rtb_OR1;
  boolean rtb_OR1_nkw1;
  boolean rtb_OR2;
  boolean rtb_bolIntg1RsetCond_gnti;
  boolean rtb_bolIntg2RsetCond_mgg0;
  boolean rtb_lb_genOutp;
  boolean tmp_0;

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.s16_iActPhCurr[0] > 14746) {
    rtb_Saturation_f2a5_idx_0 = 14746;
  } else if (busPhVltgGen_MedTaskIn.s16_iActPhCurr[0] < -14746) {
    rtb_Saturation_f2a5_idx_0 = -14746;
  } else {
    rtb_Saturation_f2a5_idx_0 = busPhVltgGen_MedTaskIn.s16_iActPhCurr[0];
  }

  /* Saturate: '<S2>/Saturation2' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.u16_dcycPhDyc[1] <= 32768) {
    u0 = busPhVltgGen_MedTaskIn.u16_dcycPhDyc[1];
  } else {
    u0 = 32768U;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Saturate: '<S2>/Saturation2'
   */
  rtb_DataTypeConversion_des1_i_0 = (sint16)(((uint32)u0) >> 1);

  /* Saturate: '<S2>/Saturation2' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.u16_dcycPhDyc[2] <= 32768) {
    u0 = busPhVltgGen_MedTaskIn.u16_dcycPhDyc[2];
  } else {
    u0 = 32768U;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Saturate: '<S2>/Saturation2'
   */
  rtb_DataTypeConversion_des1_idx = (sint16)(((uint32)u0) >> 1);

  /* RelationalOperator: '<S372>/Compare' incorporates:
   *  Constant: '<S372>/Constant'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  rtb_Compare = (busPhVltgGen_MedTaskIn.enm_stMotoSt != OPEN_LOOP);

  /* Switch: '<S377>/Switch1' incorporates:
   *  Constant: '<S377>/Constant'
   *  Gain: '<S371>/Gain'
   *  Logic: '<S377>/NOT'
   *  Product: '<S377>/Product1'
   *  Saturate: '<S371>/Saturation4'
   */
  if (!rtb_Compare) {
    /* Saturate: '<S371>/Saturation4' incorporates:
     *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
     */
    if (busPhVltgGen_MedTaskIn.s16_nRmpRefElecSpd >= -32767) {
      tmp = busPhVltgGen_MedTaskIn.s16_nRmpRefElecSpd;
    } else {
      tmp = -32767;
    }

    rtb_Switch1_ffta = (sint16)(((tmp >> 1) * 16777) >> 14);
  } else {
    rtb_Switch1_ffta = 0;
  }

  /* End of Switch: '<S377>/Switch1' */

  /* Switch: '<S382>/Switch1' incorporates:
   *  Constant: '<S382>/Constant1'
   *  UnitDelay: '<S382>/Unit Delay1'
   */
  if (ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_haua) {
    tmp_0 = rtb_Compare;
  } else {
    tmp_0 = true;
  }

  /* Switch: '<S382>/Switch' incorporates:
   *  Switch: '<S382>/Switch1'
   *  UnitDelay: '<S371>/Unit Delay'
   *  UnitDelay: '<S382>/Unit Delay'
   */
  if (tmp_0) {
    u0 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_l32u;
  } else {
    u0 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_hdmg;
  }

  /* Sum: '<S377>/Sum' incorporates:
   *  Switch: '<S377>/Switch1'
   *  Switch: '<S382>/Switch'
   */
  rtb_Sum_e45u = (uint16)(((rtb_Switch1_ffta * 20861) + (u0 << 14)) >> 14);

  /* Sum: '<S42>/Subtract' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  rtb_Subtract = (sint16)(busPhVltgGen_MedTaskIn.u16_phiSensActElecAg -
                          ASW_PhVltgGen_DW.UnitDelay1_DSTATE_hljs);

  /* Abs: '<S42>/Abs2' incorporates:
   *  Sum: '<S42>/Subtract'
   */
  if (rtb_Subtract < 0) {
    u0 = (uint16)(-rtb_Subtract);
  } else {
    u0 = (uint16)rtb_Subtract;
  }

  /* Saturate: '<S4>/Saturation4' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.s16_nRmpRefElecSpd >= -32767) {
    tmp = busPhVltgGen_MedTaskIn.s16_nRmpRefElecSpd;
  } else {
    tmp = -32767;
  }

  /* Logic: '<S42>/Logical Operator4' incorporates:
   *  Abs: '<S42>/Abs2'
   *  Constant: '<S42>/Gu16_phiMaxSenlTrnsElecAg_C'
   *  RelationalOperator: '<S42>/Relational Operator2'
   *  RelationalOperator: '<S65>/Compare'
   *  Saturate: '<S4>/Saturation4'
   */
  rtb_LogicalOperator4 = ((u0 <= Gu16_phiMaxSenlTrnsElecAg_C) && (tmp != 0));

  /* Outputs for Atomic SubSystem: '<S42>/lib_Deb_0' */
  /* Chart: '<S68>/sfc_FaultDebounce' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   */
  /* Gateway: lib_debounce_0/sfc_FaultDebounce */
  /* During: lib_debounce_0/sfc_FaultDebounce */
  if (ASW_PhVltgGen_DW.is_active_c7_lib_debounce == 0U) {
    /* Entry: lib_debounce_0/sfc_FaultDebounce */
    ASW_PhVltgGen_DW.is_active_c7_lib_debounce = 1U;

    /* Entry Internal: lib_debounce_0/sfc_FaultDebounce */
    /* Transition: '<S72>:149' */
    /* There is Fault */
    if (rtb_LogicalOperator4) {
      /* Transition: '<S72>:182' */
      /* Direct Confirm */
      if (Gu16_ctSenlTrnsElecAgConfCnt_C == 0) {
        /* Transition: '<S72>:185' */
        /* Transition: '<S72>:188' */
        ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Confirm;

        /* Entry 'Confirm': '<S72>:165' */
        /* Set Bit0 Bit1 */
        ASW_PhVltgGen_DW.lb_cntDebCond = 0U;
        rtb_lb_genOutp = true;
      } else {
        /* Transition: '<S72>:183' */
        ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Confirming;

        /* Entry 'Confirming': '<S72>:93' */
        /* Set Bit0 */
        rtb_TmpSignalConversionAtBusC_2 = ASW_PhVltgGen_DW.lb_cntDebCond + 1;
        if ((ASW_PhVltgGen_DW.lb_cntDebCond + 1) > 65535) {
          rtb_TmpSignalConversionAtBusC_2 = 65535;
        }

        ASW_PhVltgGen_DW.lb_cntDebCond =
            (uint16)rtb_TmpSignalConversionAtBusC_2;
        rtb_lb_genOutp = false;
      }
    } else {
      /* Transition: '<S72>:180' */
      ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Wait;

      /* Entry 'Wait': '<S72>:98' */
      ASW_PhVltgGen_DW.lb_cntDebCond = 0U;
      rtb_lb_genOutp = false;
    }
  } else {
    switch (ASW_PhVltgGen_DW.is_c7_lib_debounce) {
    case IN_Confirm:
      rtb_lb_genOutp = true;

      /* During 'Confirm': '<S72>:165' */
      /* There is no Fault */
      if (!rtb_LogicalOperator4) {
        /* Transition: '<S72>:196' */
        /* Direct Repair */
        if (Gu16_ctSenlTrnsElecAgRcvyCnt_C == 0) {
          /* Transition: '<S72>:197' */
          ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Wait;

          /* Entry 'Wait': '<S72>:98' */
          ASW_PhVltgGen_DW.lb_cntDebCond = 0U;
          rtb_lb_genOutp = false;
        } else {
          /* Transition: '<S72>:207' */
          /* Need Debounce */
          ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Repairing;

          /* Entry 'Repairing': '<S72>:100' */
          /* Clear Bit0 */
          rtb_TmpSignalConversionAtBusC_2 = ASW_PhVltgGen_DW.lb_cntDebCond + 1;
          if ((ASW_PhVltgGen_DW.lb_cntDebCond + 1) > 65535) {
            rtb_TmpSignalConversionAtBusC_2 = 65535;
          }

          ASW_PhVltgGen_DW.lb_cntDebCond =
              (uint16)rtb_TmpSignalConversionAtBusC_2;
        }
      }
      break;

    case IN_Confirming:
      rtb_lb_genOutp = false;

      /* During 'Confirming': '<S72>:93' */
      /* There is no Fault */
      if (!rtb_LogicalOperator4) {
        /* Transition: '<S72>:173' */
        ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Wait;

        /* Entry 'Wait': '<S72>:98' */
        ASW_PhVltgGen_DW.lb_cntDebCond = 0U;

        /* Fault Is Confirmed */
      } else if (ASW_PhVltgGen_DW.lb_cntDebCond >=
                 Gu16_ctSenlTrnsElecAgConfCnt_C) {
        /* Transition: '<S72>:167' */
        ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Confirm;

        /* Entry 'Confirm': '<S72>:165' */
        /* Set Bit0 Bit1 */
        ASW_PhVltgGen_DW.lb_cntDebCond = 0U;
        rtb_lb_genOutp = true;
      } else {
        ASW_PhVltgGen_DW.lb_cntDebCond++;
      }
      break;

    case IN_Repairing:
      rtb_lb_genOutp = true;

      /* During 'Repairing': '<S72>:100' */
      /* There is Fault */
      if (rtb_LogicalOperator4) {
        /* Transition: '<S72>:172' */
        ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Confirm;

        /* Entry 'Confirm': '<S72>:165' */
        /* Set Bit0 Bit1 */
        ASW_PhVltgGen_DW.lb_cntDebCond = 0U;

        /* Fault Is Repaired */
      } else if (ASW_PhVltgGen_DW.lb_cntDebCond >=
                 Gu16_ctSenlTrnsElecAgRcvyCnt_C) {
        /* Transition: '<S72>:169' */
        ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Wait;

        /* Entry 'Wait': '<S72>:98' */
        ASW_PhVltgGen_DW.lb_cntDebCond = 0U;
        rtb_lb_genOutp = false;
      } else {
        ASW_PhVltgGen_DW.lb_cntDebCond++;
      }
      break;

    default:
      rtb_lb_genOutp = false;

      /* During 'Wait': '<S72>:98' */
      /* There is Fault */
      if (rtb_LogicalOperator4) {
        /* Transition: '<S72>:166' */
        /* Direct Confirm */
        if (Gu16_ctSenlTrnsElecAgConfCnt_C == 0) {
          /* Transition: '<S72>:214' */
          ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Confirm;

          /* Entry 'Confirm': '<S72>:165' */
          /* Set Bit0 Bit1 */
          ASW_PhVltgGen_DW.lb_cntDebCond = 0U;
          rtb_lb_genOutp = true;
        } else {
          /* Transition: '<S72>:213' */
          /* Need Debounce */
          ASW_PhVltgGen_DW.is_c7_lib_debounce = IN_Confirming;

          /* Entry 'Confirming': '<S72>:93' */
          /* Set Bit0 */
          rtb_TmpSignalConversionAtBusC_2 = ASW_PhVltgGen_DW.lb_cntDebCond + 1;
          if ((ASW_PhVltgGen_DW.lb_cntDebCond + 1) > 65535) {
            rtb_TmpSignalConversionAtBusC_2 = 65535;
          }

          ASW_PhVltgGen_DW.lb_cntDebCond =
              (uint16)rtb_TmpSignalConversionAtBusC_2;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S68>/sfc_FaultDebounce' */
  /* End of Outputs for SubSystem: '<S42>/lib_Deb_0' */

  /* Abs: '<S42>/Abs' incorporates:
   *  UnitDelay: '<S42>/Unit Delay1'
   */
  if (ASW_PhVltgGen_DW.UnitDelay1_DSTATE < 0) {
    tmp = (sint16)(-ASW_PhVltgGen_DW.UnitDelay1_DSTATE);
  } else {
    tmp = ASW_PhVltgGen_DW.UnitDelay1_DSTATE;
  }

  /* Abs: '<S42>/Abs1' incorporates:
   *  Constant: '<S42>/Gs16_nSenlTrnsElecSpd_C'
   */
  if (Gs16_nSenlTrnsElecSpd_C < 0) {
    tmp_1 = (sint16)(-Gs16_nSenlTrnsElecSpd_C);
  } else {
    tmp_1 = Gs16_nSenlTrnsElecSpd_C;
  }

  /* Logic: '<S42>/Logical Operator1' incorporates:
   *  Abs: '<S42>/Abs'
   *  Abs: '<S42>/Abs1'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  Logic: '<S42>/Logical Operator'
   *  Logic: '<S42>/Logical Operator2'
   *  Logic: '<S42>/Logical Operator3'
   *  RelationalOperator: '<S42>/Relational Operator'
   *  RelationalOperator: '<S63>/Compare'
   *  RelationalOperator: '<S64>/Compare'
   */
  rtb_LogicalOperator1 =
      ((busPhVltgGen_MedTaskIn.enm_modeAgEvalMode == SENSOR) ||
       (((!rtb_lb_genOutp) || (tmp <= tmp_1)) &&
        (busPhVltgGen_MedTaskIn.enm_modeAgEvalMode == HYBRID)));

  /* Switch: '<S42>/Switch' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  if (rtb_LogicalOperator1) {
    rtb_Switch_agfx = busPhVltgGen_MedTaskIn.u16_phiSensActElecAg;
  } else {
    rtb_Switch_agfx = ASW_PhVltgGen_DW.UnitDelay1_DSTATE_hljs;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Outputs for Enabled SubSystem: '<S40>/ens_EnOpnLpAgClsLpAgDvtCalc'
   * incorporates: EnablePort: '<S49>/Enable'
   */
  /* RelationalOperator: '<S48>/Compare' incorporates:
   *  Constant: '<S48>/Constant'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  RelationalOperator: '<S372>/Compare'
   */
  if (busPhVltgGen_MedTaskIn.enm_stMotoSt == OPEN_LOOP) {
    /* Sum: '<S49>/Add1' incorporates:
     *  Sum: '<S377>/Sum'
     *  Switch: '<S377>/Switch'
     *  Switch: '<S42>/Switch'
     */
    ASW_PhVltgGen_B.Add1 = (dt_RadAng_u16r15b0)(rtb_Sum_e45u - rtb_Switch_agfx);
  }

  /* End of RelationalOperator: '<S48>/Compare' */
  /* End of Outputs for SubSystem: '<S40>/ens_EnOpnLpAgClsLpAgDvtCalc' */

  /* Logic: '<S40>/Logical Operator' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S47>/Constant'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  RelationalOperator: '<S372>/Compare'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S47>/Compare'
   *  UnitDelay: '<S40>/Unit Delay1'
   */
  rtb_LogicalOperator_lwqz =
      ((ASW_PhVltgGen_DW.UnitDelay1_DSTATE_hxga == OPEN_LOOP) &&
       (busPhVltgGen_MedTaskIn.enm_stMotoSt == CLOSED_LOOP));

  /* Switch: '<S53>/Switch1' incorporates:
   *  Constant: '<S53>/Constant'
   *  Logic: '<S53>/NOT'
   *  Product: '<S53>/Product1'
   *  Switch: '<S40>/Switch'
   */
  if (!rtb_LogicalOperator_lwqz) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Gs16_facOpnLpClsLpAgRiseRate_C'
     *  Gain: '<S40>/Gain'
     *  RelationalOperator: '<S46>/Compare'
     *  Sum: '<S49>/Add1'
     */
    if (ASW_PhVltgGen_B.Add1 >= 32768) {
      tmp = Gs16_facOpnLpClsLpAgRiseRate_C;
    } else {
      tmp = (sint16)(-Gs16_facOpnLpClsLpAgRiseRate_C);
    }

    rtb_Switch1_kp25 = (sint16)((tmp * 16777) >> 11);
  } else {
    rtb_Switch1_kp25 = 0;
  }

  /* End of Switch: '<S53>/Switch1' */

  /* Switch: '<S58>/Switch' incorporates:
   *  DataTypeConversion: '<S40>/Data Type Conversion'
   *  Sum: '<S49>/Add1'
   *  Switch: '<S58>/Switch1'
   *  UnitDelay: '<S58>/Unit Delay'
   *  UnitDelay: '<S58>/Unit Delay1'
   */
  if ((!ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_d5fg) ||
      rtb_LogicalOperator_lwqz) {
    tmp = (sint16)(((uint32)ASW_PhVltgGen_B.Add1) >> 2);
  } else {
    tmp = ASW_PhVltgGen_DW.UnitDelay_DSTATE_j4ol;
  }

  /* Sum: '<S53>/Sum' incorporates:
   *  Switch: '<S53>/Switch1'
   *  Switch: '<S58>/Switch'
   */
  rtb_Sum_cwuo =
      (sint16)((((rtb_Switch1_kp25 * 20861) >> 4) + (tmp << 15)) >> 15);

  /* Switch: '<S57>/Switch1' incorporates:
   *  RelationalOperator: '<S57>/Relational Operator1'
   *  Sum: '<S53>/Sum'
   *  Switch: '<S57>/Switch2'
   */
  if (rtb_Sum_cwuo <= 16384) {
    /* Switch: '<S57>/Switch' incorporates:
     *  RelationalOperator: '<S57>/Relational Operator'
     */
    if (rtb_Sum_cwuo >= 0) {
      /* Switch: '<S57>/Switch2' */
      rtb_Switch2_aaxv = rtb_Sum_cwuo;
    } else {
      /* Switch: '<S57>/Switch2' incorporates:
       *  Constant: '<S40>/minElctAng'
       */
      rtb_Switch2_aaxv = 0;
    }

    /* End of Switch: '<S57>/Switch' */
  } else {
    /* Switch: '<S57>/Switch2' incorporates:
     *  Constant: '<S40>/maxElctAng'
     */
    rtb_Switch2_aaxv = 16384;
  }

  /* End of Switch: '<S57>/Switch1' */

  /* Sum: '<S40>/Add2' incorporates:
   *  Switch: '<S42>/Switch'
   *  Switch: '<S53>/Switch'
   *  Switch: '<S57>/Switch2'
   */
  rtb_Add2 = (dt_RadAng_u16r15b0)(rtb_Switch_agfx + (rtb_Switch2_aaxv << 2));

  /* SwitchCase: '<S345>/Switch Case' incorporates:
   *  DataTypeConversion: '<S345>/Data Type Conversion1'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  switch (busPhVltgGen_MedTaskIn.enm_stMotoSt) {
  case 0:
    /* Outputs for IfAction SubSystem: '<S345>/sas_ZrAg' incorporates:
     *  ActionPort: '<S370>/Action Port'
     */
    /* SignalConversion generated from: '<S370>/u16_phiActElecAgCs0'
     * incorporates: Constant: '<S370>/Constant' Merge: '<S345>/Merge1'
     */
    rtb_Merge1 = 0U;

    /* End of Outputs for SubSystem: '<S345>/sas_ZrAg' */
    break;

  case 1:
    /* Outputs for IfAction SubSystem: '<S345>/sas_StrtUpAg' incorporates:
     *  ActionPort: '<S369>/Action Port'
     */
    /* SignalConversion: '<S369>/Signal Copy' incorporates:
     *  Merge: '<S345>/Merge1'
     *  Sum: '<S377>/Sum'
     *  Switch: '<S377>/Switch'
     */
    rtb_Merge1 = rtb_Sum_e45u;

    /* End of Outputs for SubSystem: '<S345>/sas_StrtUpAg' */
    break;

  case 2:
    /* Outputs for IfAction SubSystem: '<S345>/sas_ActAg' incorporates:
     *  ActionPort: '<S367>/Action Port'
     */
    /* SignalConversion: '<S367>/Signal Copy' incorporates:
     *  Merge: '<S345>/Merge1'
     *  Sum: '<S40>/Add2'
     */
    rtb_Merge1 = rtb_Add2;

    /* End of Outputs for SubSystem: '<S345>/sas_ActAg' */
    break;

  default:
    /* Outputs for IfAction SubSystem: '<S345>/sas_DflAg' incorporates:
     *  ActionPort: '<S368>/Action Port'
     */
    /* SignalConversion generated from: '<S368>/u16_phiActElecAgCsDfl'
     * incorporates: Constant: '<S368>/Constant' Merge: '<S345>/Merge1'
     */
    rtb_Merge1 = 0U;

    /* End of Outputs for SubSystem: '<S345>/sas_DflAg' */
    break;
  }

  /* End of SwitchCase: '<S345>/Switch Case' */

  /* Switch: '<S345>/Switch1' incorporates:
   *  Constant: '<S366>/Constant'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  Merge: '<S345>/Merge1'
   *  RelationalOperator: '<S366>/Compare'
   *  RelationalOperator: '<S372>/Compare'
   */
  if (busPhVltgGen_MedTaskIn.enm_stMotoSt != OFF) {
    /* Switch: '<S345>/Switch2' incorporates:
     *  Merge: '<S345>/Merge1'
     *  Switch: '<S345>/Switch1'
     */
    if (busPhVltgGen_MedTaskIn.bol_enPosSCDCalibEnFlg) {
      rtb_Switch1_d0v1 = busPhVltgGen_MedTaskIn.u16_phiPosSCDCalibElecAg;
    } else {
      rtb_Switch1_d0v1 = rtb_Merge1;
    }

    /* End of Switch: '<S345>/Switch2' */
  } else {
    rtb_Switch1_d0v1 = rtb_Merge1;
  }

  /* End of Switch: '<S345>/Switch1' */

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.s16_iActPhCurr[0] > 14746) {
    tmp = 14746;
  } else if (busPhVltgGen_MedTaskIn.s16_iActPhCurr[0] < -14746) {
    tmp = -14746;
  } else {
    tmp = busPhVltgGen_MedTaskIn.s16_iActPhCurr[0];
  }

  if (busPhVltgGen_MedTaskIn.s16_iActPhCurr[1] > 14746) {
    tmp_1 = 14746;
  } else if (busPhVltgGen_MedTaskIn.s16_iActPhCurr[1] < -14746) {
    tmp_1 = -14746;
  } else {
    tmp_1 = busPhVltgGen_MedTaskIn.s16_iActPhCurr[1];
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Saturate: '<S2>/Saturation'
   *  Sum: '<S21>/Add'
   */
  rtb_Gain1_mdnf =
      (dt_Standardize_s16p15b0)((18919 * ((tmp + (tmp_1 << 1)) >> 1)) >> 14);

  /* Saturate: '<S340>/Saturation1' incorporates:
   *  Gain: '<S21>/Gain1'
   */
  if (rtb_Gain1_mdnf > 14746) {
    rtb_Saturation1_htvq = 14746;
  } else if (rtb_Gain1_mdnf < -14746) {
    rtb_Saturation1_htvq = -14746;
  } else {
    rtb_Saturation1_htvq = rtb_Gain1_mdnf;
  }

  /* End of Saturate: '<S340>/Saturation1' */

  /* Product: '<S355>/Product' incorporates:
   *  Constant: '<S353>/Constant'
   *  Constant: '<S353>/Constant1'
   *  Gain: '<S353>/Gain'
   *  Product: '<S355>/Product5'
   *  Selector: '<S353>/Selector1'
   *  Sum: '<S353>/Add'
   *  Switch: '<S345>/Switch1'
   */
  rtb_TmpSignalConversionAtBusC_2 = rtCP_Constant1_Value_p1ac[(
      uint16)((1023U * ((uint16)(16384 - rtb_Switch1_d0v1))) >> 16)];

  /* Product: '<S355>/Product2' incorporates:
   *  Constant: '<S350>/Constant'
   *  Gain: '<S350>/Gain'
   *  Product: '<S355>/Product1'
   *  Selector: '<S350>/Selector1'
   */
  rtb_TmpSignalConversionAtBusC_3 =
      rtCP_Constant_Value_o231[(uint16)((1023U * rtb_Switch1_d0v1) >> 16)];

  /* SignalConversion generated from: '<S339>/Bus Creator1' incorporates:
   *  Product: '<S355>/Product'
   *  Product: '<S355>/Product1'
   *  Product: '<S355>/Product2'
   *  Product: '<S355>/Product5'
   *  Saturate: '<S340>/Saturation'
   *  Saturate: '<S340>/Saturation1'
   *  Sum: '<S355>/Add1'
   *  Sum: '<S355>/Add3'
   */
  rtb_TmpSignalConversionAtBusC_1 =
      (dt_Standardize_s16p15b0)(((rtb_Saturation_f2a5_idx_0 *
                                  rtb_TmpSignalConversionAtBusC_2) >>
                                 14) +
                                ((rtb_Saturation1_htvq *
                                  rtb_TmpSignalConversionAtBusC_3) >>
                                 14));
  rtb_TmpSignalConversionAtBusC_0 =
      (dt_Standardize_s16p15b0)(((rtb_Saturation1_htvq *
                                  rtb_TmpSignalConversionAtBusC_2) >>
                                 14) -
                                ((rtb_Saturation_f2a5_idx_0 *
                                  rtb_TmpSignalConversionAtBusC_3) >>
                                 14));

  /* Saturate: '<S2>/Saturation1' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.u16_uSplyVltg <= 32767) {
    rtb_Saturation1 = busPhVltgGen_MedTaskIn.u16_uSplyVltg;
  } else {
    rtb_Saturation1 = 32767U;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Saturate: '<S2>/Saturation2' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.u16_dcycPhDyc[0] <= 32768) {
    u0 = busPhVltgGen_MedTaskIn.u16_dcycPhDyc[0];
  } else {
    u0 = 32768U;
  }

  /* Product: '<S2>/Product' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  Gain: '<S24>/Gain'
   *  Gain: '<S24>/Gain1'
   *  Gain: '<S24>/Gain4'
   *  Saturate: '<S2>/Saturation1'
   *  Saturate: '<S2>/Saturation2'
   *  Sum: '<S24>/Add'
   */
  rtb_Product_bnwf =
      (dt_Standardize_s16p15b0)((rtb_Saturation1 *
                                 ((21845 *
                                   (((((sint16)(((uint32)u0) >> 1)) -
                                      (rtb_DataTypeConversion_des1_i_0 >> 1)) -
                                     (rtb_DataTypeConversion_des1_idx >> 1)) >>
                                    1)) >>
                                  14)) >>
                                14);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Gs16_tiPhVltgAgDel_C'
   *  Gain: '<S2>/Gain'
   *  Product: '<S2>/Product2'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_DataTypeConversion1_gn4i =
      (uint16)((((sint16)((Gs16_tiPhVltgAgDel_C *
                           (ASW_PhVltgGen_DW.UnitDelay_DSTATE_pwry >> 1)) >>
                          10)) *
                20861) >>
               14);

  /* Selector: '<S33>/Selector1' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Constant1'
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  Gain: '<S33>/Gain'
   *  Sum: '<S33>/Add'
   */
  rtb_Selector1_chuf = rtCP_Constant1_Value[(
      sint32)((1023U * ((uint16)(16384 - rtb_DataTypeConversion1_gn4i))) >>
              16)];

  /* Product: '<S2>/Product1' incorporates:
   *  Gain: '<S24>/Gain2'
   *  Gain: '<S24>/Gain3'
   *  Gain: '<S24>/Gain5'
   *  Saturate: '<S2>/Saturation1'
   *  Sum: '<S24>/Add2'
   */
  rtb_Product1_ccy0 =
      (dt_Standardize_s16p15b0)((((21845 *
                                   ((((14189 *
                                       rtb_DataTypeConversion_des1_i_0) >>
                                      14) -
                                     ((14189 *
                                       rtb_DataTypeConversion_des1_idx) >>
                                      14)) >>
                                    1)) >>
                                  14) *
                                 rtb_Saturation1) >>
                                14);

  /* Selector: '<S30>/Selector1' incorporates:
   *  Constant: '<S30>/Constant'
   *  Gain: '<S30>/Gain'
   */
  rtb_Selector1_ngzw = rtCP_Constant_Value_gyri[(
      sint32)((1023U * rtb_DataTypeConversion1_gn4i) >> 16)];

  /* Sum: '<S19>/Add' incorporates:
   *  Product: '<S19>/Product'
   *  Product: '<S19>/Product1'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Selector: '<S30>/Selector1'
   *  Selector: '<S33>/Selector1'
   */
  rtb_Add_in30 = (dt_Standardize_s16p15b0)(((sint16)((rtb_Product_bnwf *
                                                      rtb_Selector1_chuf) >>
                                                     14)) -
                                           ((sint16)((rtb_Product1_ccy0 *
                                                      rtb_Selector1_ngzw) >>
                                                     14)));

  /* Saturate: '<S340>/Saturation3' incorporates:
   *  Sum: '<S19>/Add'
   */
  if (rtb_Add_in30 >= -32767) {
    rtb_Saturation3_pseh = rtb_Add_in30;
  } else {
    rtb_Saturation3_pseh = -32767;
  }

  /* End of Saturate: '<S340>/Saturation3' */

  /* Saturate: '<S131>/Saturation' incorporates:
   *  Constant: '<S131>/Constant'
   */
  if (Gs16_nPLLElecAgSpdUpLim_C >= 0) {
    rtb_Saturation_cnrk = Gs16_nPLLElecAgSpdUpLim_C;
  } else {
    rtb_Saturation_cnrk = 0;
  }

  /* End of Saturate: '<S131>/Saturation' */

  /* DataTypeConversion: '<S141>/Data Type Conversion' incorporates:
   *  Saturate: '<S131>/Saturation'
   */
  rtb_DataTypeConversion_a45q = (sint16)(rtb_Saturation_cnrk >> 1);

  /* Logic: '<S112>/Logical Operator' incorporates:
   *  Constant: '<S114>/Constant'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  RelationalOperator: '<S114>/Compare'
   *  RelationalOperator: '<S372>/Compare'
   */
  rtb_LogicalOperator_lnae = ((busPhVltgGen_MedTaskIn.enm_stMotoSt == OFF) ||
                              (busPhVltgGen_MedTaskIn.bol_enPosSCDCalibEnFlg));

  /* DataTypeConversion: '<S147>/Data Type Conversion' incorporates:
   *  Saturate: '<S131>/Saturation'
   */
  rtb_DataTypeConversion_bgrg = (rtb_Saturation_cnrk << 6);

  /* Chart: '<S194>/sfc_IntegratorScheduler' incorporates:
   *  UnitDelay: '<S194>/Unit Delay2'
   *  UnitDelay: '<S194>/Unit Delay3'
   */
  ASW_PhV_sfc_IntegratorScheduler(
      ASW_PhVltgGen_DW.UnitDelay2_DSTATE_iu0k,
      ASW_PhVltgGen_DW.UnitDelay3_DSTATE, &rtb_bolIntg1RsetCond_gnti,
      &rtb_bolIntg2RsetCond_mgg0, &ASW_PhVltgGen_B.bolIntg1Ok_crdb,
      &ASW_PhVltgGen_DW.sf_sfc_IntegratorScheduler);

  /* Gain: '<S112>/Gain7' incorporates:
   *  Constant: '<S112>/Gu16_resPhRstn_C'
   */
  rtb_Gain7 = (uint16)((52429U * Gu16_resPhRstn_C) >> 15);

  /* Gain: '<S112>/Gain2' incorporates:
   *  Saturate: '<S111>/Saturation'
   */
  rtb_Gain2 = (sint16)(rtb_Saturation_f2a5_idx_0 >> 1);

  /* Saturate: '<S111>/Saturation3' incorporates:
   *  Sum: '<S19>/Add'
   */
  if (rtb_Add_in30 >= -32767) {
    tmp = rtb_Add_in30;
  } else {
    tmp = -32767;
  }

  /* Sum: '<S194>/Add' incorporates:
   *  Gain: '<S112>/Gain'
   *  Gain: '<S112>/Gain2'
   *  Gain: '<S112>/Gain7'
   *  Product: '<S194>/Product1'
   *  Saturate: '<S111>/Saturation3'
   */
  rtb_Add_d05d = (sint16)((((tmp >> 1) << 3) -
                           ((sint16)((rtb_Gain7 * rtb_Gain2) >> 13))) >>
                          3);

  /* Logic: '<S194>/OR' */
  rtb_OR = (rtb_LogicalOperator_lnae || rtb_bolIntg1RsetCond_gnti);

  /* Switch: '<S207>/Switch1' incorporates:
   *  Constant: '<S207>/Constant'
   *  Logic: '<S207>/NOT'
   *  Product: '<S207>/Product1'
   *  Sum: '<S194>/Add'
   */
  if (!rtb_OR) {
    tmp = (sint16)((rtb_Add_d05d * 16777) >> 14);
  } else {
    tmp = 0;
  }

  /* Switch: '<S212>/Switch' incorporates:
   *  Switch: '<S212>/Switch1'
   *  UnitDelay: '<S212>/Unit Delay'
   *  UnitDelay: '<S212>/Unit Delay1'
   */
  if ((!ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_ekpq) || rtb_OR) {
    /* Switch: '<S194>/Switch1' incorporates:
     *  Constant: '<S194>/Constant2'
     *  DataTypeConversion: '<S194>/Data Type Conversion'
     *  UnitDelay: '<S194>/Unit Delay4'
     */
    if (rtb_LogicalOperator_lnae) {
      tmp_1 = 0;
    } else {
      tmp_1 = (sint16)(ASW_PhVltgGen_DW.UnitDelay4_DSTATE >> 3);
    }

    /* End of Switch: '<S194>/Switch1' */
  } else {
    tmp_1 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_brib;
  }

  /* Sum: '<S207>/Sum' incorporates:
   *  Switch: '<S207>/Switch1'
   *  Switch: '<S212>/Switch'
   */
  rtb_Sum_icq1 = (sint16)((tmp + (tmp_1 << 2)) >> 2);

  /* Sum: '<S221>/Add2' incorporates:
   *  Constant: '<S194>/lb_parFiltCoef_1'
   *  Constant: '<S221>/Constant'
   *  Sum: '<S226>/Add2'
   *  Sum: '<S255>/Add2'
   *  Sum: '<S260>/Add2'
   */
  rtb_TmpSignalConversionAtBusC_2 = ((131072 - Gu16_facFlxObsFltCoeff_C) >> 2);

  /* Sum: '<S221>/Add1' incorporates:
   *  Constant: '<S194>/lb_parFiltCoef_1'
   *  Product: '<S221>/Product'
   *  Product: '<S221>/Product1'
   *  Sum: '<S207>/Sum'
   *  Sum: '<S221>/Add2'
   *  Switch: '<S207>/Switch'
   *  UnitDelay: '<S221>/Unit Delay'
   */
  rtb_Add1_k5op =
      (sint16)((((sint16)((rtb_Sum_icq1 * Gu16_facFlxObsFltCoeff_C) >> 14)) +
                (((rtb_TmpSignalConversionAtBusC_2 *
                   ASW_PhVltgGen_DW.UnitDelay_DSTATE_jl24) >>
                  15)
                 << 3)) >>
               3);

  /* Sum: '<S221>/Add3' incorporates:
   *  Sum: '<S207>/Sum'
   *  Sum: '<S221>/Add1'
   *  Switch: '<S207>/Switch'
   */
  rtb_Add3 = (sint16)(((sint16)(rtb_Sum_icq1 - rtb_Add1_k5op)) << 3);

  /* Logic: '<S194>/OR1' */
  rtb_OR1 = (rtb_LogicalOperator_lnae || rtb_bolIntg2RsetCond_mgg0);

  /* Switch: '<S214>/Switch1' incorporates:
   *  Constant: '<S214>/Constant'
   *  Logic: '<S214>/NOT'
   *  Product: '<S214>/Product1'
   *  Sum: '<S194>/Add'
   */
  if (!rtb_OR1) {
    tmp = (sint16)((rtb_Add_d05d * 16777) >> 14);
  } else {
    tmp = 0;
  }

  /* Switch: '<S219>/Switch' incorporates:
   *  Switch: '<S219>/Switch1'
   *  UnitDelay: '<S219>/Unit Delay'
   *  UnitDelay: '<S219>/Unit Delay1'
   */
  if ((!ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_a3qb) || rtb_OR1) {
    /* Switch: '<S194>/Switch2' incorporates:
     *  Constant: '<S194>/Constant3'
     *  DataTypeConversion: '<S194>/Data Type Conversion1'
     *  UnitDelay: '<S194>/Unit Delay5'
     */
    if (rtb_LogicalOperator_lnae) {
      tmp_1 = 0;
    } else {
      tmp_1 = (sint16)(ASW_PhVltgGen_DW.UnitDelay5_DSTATE >> 3);
    }

    /* End of Switch: '<S194>/Switch2' */
  } else {
    tmp_1 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_bhpf;
  }

  /* Sum: '<S214>/Sum' incorporates:
   *  Switch: '<S214>/Switch1'
   *  Switch: '<S219>/Switch'
   */
  rtb_Sum_d2gz = (sint16)((tmp + (tmp_1 << 2)) >> 2);

  /* Sum: '<S226>/Add1' incorporates:
   *  Constant: '<S194>/lb_parFiltCoef_2'
   *  Product: '<S226>/Product'
   *  Product: '<S226>/Product1'
   *  Sum: '<S214>/Sum'
   *  Switch: '<S214>/Switch'
   *  UnitDelay: '<S226>/Unit Delay'
   */
  rtb_Add1_btax =
      (sint16)((((sint16)((rtb_Sum_d2gz * Gu16_facFlxObsFltCoeff_C) >> 14)) +
                (((rtb_TmpSignalConversionAtBusC_2 *
                   ASW_PhVltgGen_DW.UnitDelay_DSTATE_jgqd) >>
                  15)
                 << 3)) >>
               3);

  /* Sum: '<S226>/Add3' incorporates:
   *  Sum: '<S214>/Sum'
   *  Sum: '<S226>/Add1'
   *  Switch: '<S214>/Switch'
   */
  rtb_Add3_cxwa = (sint16)(((sint16)(rtb_Sum_d2gz - rtb_Add1_btax)) << 3);

  /* Gain: '<S112>/Gain8' incorporates:
   *  Constant: '<S112>/Gu16_resPhRstn_C1'
   */
  rtb_Gain8 = (uint16)((53687U * Gu16_indQaxIndc_C) >> 15);

  /* Logic: '<S194>/NOT' incorporates:
   *  Logic: '<S133>/NOT'
   *  Logic: '<S195>/NOT'
   */
  tmp_0 = !rtb_LogicalOperator_lnae;

  /* Switch: '<S194>/Switch3' incorporates:
   *  Constant: '<S194>/Constant5'
   *  Gain: '<S112>/Gain2'
   *  Gain: '<S112>/Gain8'
   *  Gain: '<S194>/Gain2'
   *  Logic: '<S194>/NOT'
   *  Product: '<S194>/Product2'
   *  Sum: '<S194>/Add1'
   *  Switch: '<S194>/Switch'
   */
  if (tmp_0) {
    /* Switch: '<S194>/Switch' incorporates:
     *  Sum: '<S221>/Add3'
     *  Sum: '<S226>/Add3'
     */
    if (ASW_PhVltgGen_B.bolIntg1Ok_crdb) {
      tmp = rtb_Add3;
    } else {
      tmp = rtb_Add3_cxwa;
    }

    rtb_Switch3 =
        (dt_Standardize_s16p15b0)((17067 * ((sint16)(((tmp << 1) -
                                                      ((sint16)((rtb_Gain2 *
                                                                 rtb_Gain8) >>
                                                                13))) >>
                                                     1))) >>
                                  15);
  } else {
    rtb_Switch3 = 0;
  }

  /* End of Switch: '<S194>/Switch3' */

  /* DataTypeConversion: '<S112>/Data Type Conversion1' incorporates:
   *  Constant: '<S112>/Gs16_tiSenlElecAgDel_C'
   *  Gain: '<S112>/Gain6'
   *  Product: '<S112>/Product2'
   *  UnitDelay: '<S112>/Unit Delay'
   */
  rtb_DataTypeConversion1_jrjz =
      (uint16)((((sint16)((Gs16_tiSenlElecAgDel_C *
                           (ASW_PhVltgGen_DW.UnitDelay_DSTATE_bg1i >> 1)) >>
                          10)) *
                20861) >>
               14);

  /* Selector: '<S192>/Selector1' incorporates:
   *  Constant: '<S192>/Constant'
   *  Constant: '<S192>/Constant1'
   *  DataTypeConversion: '<S112>/Data Type Conversion1'
   *  Gain: '<S192>/Gain'
   *  Sum: '<S192>/Add'
   */
  rtb_Selector1_hkbk = rtCP_Constant1_Value_h4hb[(
      sint32)((1023U * ((uint16)(16384 - rtb_DataTypeConversion1_jrjz))) >>
              16)];

  /* Chart: '<S195>/sfc_IntegratorScheduler' incorporates:
   *  UnitDelay: '<S195>/Unit Delay2'
   *  UnitDelay: '<S195>/Unit Delay3'
   */
  ASW_PhV_sfc_IntegratorScheduler(
      ASW_PhVltgGen_DW.UnitDelay2_DSTATE_fpsd,
      ASW_PhVltgGen_DW.UnitDelay3_DSTATE_a0k1, &rtb_bolIntg1RsetCond_gnti,
      &rtb_bolIntg2RsetCond_mgg0, &ASW_PhVltgGen_B.bolIntg1Ok,
      &ASW_PhVltgGen_DW.sf_sfc_IntegratorScheduler_cr3h);

  /* Sum: '<S19>/Add1' incorporates:
   *  Product: '<S19>/Product2'
   *  Product: '<S19>/Product3'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Selector: '<S30>/Selector1'
   *  Selector: '<S33>/Selector1'
   */
  rtb_Add1_cq0f = (dt_Standardize_s16p15b0)(((sint16)((rtb_Product1_ccy0 *
                                                       rtb_Selector1_chuf) >>
                                                      14)) +
                                            ((sint16)((rtb_Product_bnwf *
                                                       rtb_Selector1_ngzw) >>
                                                      14)));

  /* Saturate: '<S111>/Saturation2' incorporates:
   *  Gain: '<S21>/Gain1'
   */
  if (rtb_Gain1_mdnf > 14746) {
    tmp = 14746;
  } else if (rtb_Gain1_mdnf < -14746) {
    tmp = -14746;
  } else {
    tmp = rtb_Gain1_mdnf;
  }

  /* Gain: '<S112>/Gain3' incorporates:
   *  Saturate: '<S111>/Saturation2'
   */
  rtb_Gain3 = (sint16)(tmp >> 1);

  /* Saturate: '<S111>/Saturation1' incorporates:
   *  Sum: '<S19>/Add1'
   */
  if (rtb_Add1_cq0f >= -32767) {
    tmp = rtb_Add1_cq0f;
  } else {
    tmp = -32767;
  }

  /* Sum: '<S195>/Add' incorporates:
   *  Gain: '<S112>/Gain1'
   *  Gain: '<S112>/Gain3'
   *  Gain: '<S112>/Gain7'
   *  Product: '<S195>/Product1'
   *  Saturate: '<S111>/Saturation1'
   */
  rtb_Add_efob = (sint16)((((tmp >> 1) << 3) -
                           ((sint16)((rtb_Gain7 * rtb_Gain3) >> 13))) >>
                          3);

  /* Logic: '<S195>/OR2' */
  rtb_OR2 = (rtb_LogicalOperator_lnae || rtb_bolIntg1RsetCond_gnti);

  /* Switch: '<S241>/Switch1' incorporates:
   *  Constant: '<S241>/Constant'
   *  Logic: '<S241>/NOT'
   *  Product: '<S241>/Product1'
   *  Sum: '<S195>/Add'
   */
  if (!rtb_OR2) {
    tmp = (sint16)((rtb_Add_efob * 16777) >> 14);
  } else {
    tmp = 0;
  }

  /* Switch: '<S246>/Switch' incorporates:
   *  Switch: '<S246>/Switch1'
   *  UnitDelay: '<S246>/Unit Delay'
   *  UnitDelay: '<S246>/Unit Delay1'
   */
  if ((!ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_mq3y) || rtb_OR2) {
    /* Switch: '<S195>/Switch1' incorporates:
     *  Constant: '<S195>/Constant2'
     *  DataTypeConversion: '<S195>/Data Type Conversion'
     *  UnitDelay: '<S195>/Unit Delay4'
     */
    if (rtb_LogicalOperator_lnae) {
      tmp_1 = 0;
    } else {
      tmp_1 = (sint16)(ASW_PhVltgGen_DW.UnitDelay4_DSTATE_jlzn >> 3);
    }

    /* End of Switch: '<S195>/Switch1' */
  } else {
    tmp_1 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_jfag;
  }

  /* Sum: '<S241>/Sum' incorporates:
   *  Switch: '<S241>/Switch1'
   *  Switch: '<S246>/Switch'
   */
  rtb_Sum_juht = (sint16)((tmp + (tmp_1 << 2)) >> 2);

  /* Sum: '<S255>/Add1' incorporates:
   *  Constant: '<S195>/lb_parFiltCoef_1'
   *  Product: '<S255>/Product'
   *  Product: '<S255>/Product1'
   *  Sum: '<S241>/Sum'
   *  Switch: '<S241>/Switch'
   *  UnitDelay: '<S255>/Unit Delay'
   */
  rtb_Add1_mzgk =
      (sint16)((((sint16)((rtb_Sum_juht * Gu16_facFlxObsFltCoeff_C) >> 14)) +
                (((rtb_TmpSignalConversionAtBusC_2 *
                   ASW_PhVltgGen_DW.UnitDelay_DSTATE_h5zb) >>
                  15)
                 << 3)) >>
               3);

  /* Sum: '<S255>/Add3' incorporates:
   *  Sum: '<S241>/Sum'
   *  Sum: '<S255>/Add1'
   *  Switch: '<S241>/Switch'
   */
  rtb_Add3_chim = (sint16)(((sint16)(rtb_Sum_juht - rtb_Add1_mzgk)) << 3);

  /* Logic: '<S195>/OR1' */
  rtb_OR1_nkw1 = (rtb_LogicalOperator_lnae || rtb_bolIntg2RsetCond_mgg0);

  /* Switch: '<S248>/Switch1' incorporates:
   *  Constant: '<S248>/Constant'
   *  Logic: '<S248>/NOT'
   *  Product: '<S248>/Product1'
   *  Sum: '<S195>/Add'
   */
  if (!rtb_OR1_nkw1) {
    tmp = (sint16)((rtb_Add_efob * 16777) >> 14);
  } else {
    tmp = 0;
  }

  /* Switch: '<S253>/Switch' incorporates:
   *  Switch: '<S253>/Switch1'
   *  UnitDelay: '<S253>/Unit Delay'
   *  UnitDelay: '<S253>/Unit Delay1'
   */
  if ((!ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_ljbs) || rtb_OR1_nkw1) {
    /* Switch: '<S195>/Switch2' incorporates:
     *  Constant: '<S195>/Constant3'
     *  DataTypeConversion: '<S195>/Data Type Conversion1'
     *  UnitDelay: '<S195>/Unit Delay5'
     */
    if (rtb_LogicalOperator_lnae) {
      tmp_1 = 0;
    } else {
      tmp_1 = (sint16)(ASW_PhVltgGen_DW.UnitDelay5_DSTATE_dj41 >> 3);
    }

    /* End of Switch: '<S195>/Switch2' */
  } else {
    tmp_1 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_aybk;
  }

  /* Sum: '<S248>/Sum' incorporates:
   *  Switch: '<S248>/Switch1'
   *  Switch: '<S253>/Switch'
   */
  rtb_Sum_g2hx = (sint16)((tmp + (tmp_1 << 2)) >> 2);

  /* Sum: '<S260>/Add1' incorporates:
   *  Constant: '<S195>/lb_parFiltCoef_2'
   *  Product: '<S260>/Product'
   *  Product: '<S260>/Product1'
   *  Sum: '<S248>/Sum'
   *  Switch: '<S248>/Switch'
   *  UnitDelay: '<S260>/Unit Delay'
   */
  rtb_Add1_bfl0 =
      (sint16)((((sint16)((rtb_Sum_g2hx * Gu16_facFlxObsFltCoeff_C) >> 14)) +
                (((rtb_TmpSignalConversionAtBusC_2 *
                   ASW_PhVltgGen_DW.UnitDelay_DSTATE_bffe) >>
                  15)
                 << 3)) >>
               3);

  /* Sum: '<S260>/Add3' incorporates:
   *  Sum: '<S248>/Sum'
   *  Sum: '<S260>/Add1'
   *  Switch: '<S248>/Switch'
   */
  rtb_Add3_by2i = (sint16)(((sint16)(rtb_Sum_g2hx - rtb_Add1_bfl0)) << 3);

  /* Switch: '<S195>/Switch3' incorporates:
   *  Constant: '<S195>/Constant5'
   *  Gain: '<S112>/Gain3'
   *  Gain: '<S112>/Gain8'
   *  Gain: '<S195>/Gain2'
   *  Product: '<S195>/Product2'
   *  Sum: '<S195>/Add1'
   *  Switch: '<S195>/Switch'
   */
  if (tmp_0) {
    /* Switch: '<S195>/Switch' incorporates:
     *  Sum: '<S255>/Add3'
     *  Sum: '<S260>/Add3'
     */
    if (ASW_PhVltgGen_B.bolIntg1Ok) {
      tmp = rtb_Add3_chim;
    } else {
      tmp = rtb_Add3_by2i;
    }

    rtb_Switch3_eodk =
        (dt_Standardize_s16p15b0)((17067 * ((sint16)(((tmp << 1) -
                                                      ((sint16)((rtb_Gain3 *
                                                                 rtb_Gain8) >>
                                                                13))) >>
                                                     1))) >>
                                  15);
  } else {
    rtb_Switch3_eodk = 0;
  }

  /* End of Switch: '<S195>/Switch3' */

  /* Selector: '<S189>/Selector1' incorporates:
   *  Constant: '<S189>/Constant'
   *  Gain: '<S189>/Gain'
   */
  rtb_Selector1_jaut = rtCP_Constant_Value_k3nb[(
      sint32)((1023U * rtb_DataTypeConversion1_jrjz) >> 16)];

  /* Sum: '<S160>/Add' incorporates:
   *  Product: '<S160>/Product'
   *  Product: '<S160>/Product1'
   *  Selector: '<S189>/Selector1'
   *  Selector: '<S192>/Selector1'
   *  Switch: '<S194>/Switch3'
   *  Switch: '<S195>/Switch3'
   */
  rtb_Add_dots =
      (dt_Standardize_s16p15b0)(((sint16)((rtb_Switch3 * rtb_Selector1_hkbk) >>
                                          14)) -
                                ((sint16)((rtb_Switch3_eodk *
                                           rtb_Selector1_jaut) >>
                                          14)));

  /* Sum: '<S160>/Add1' incorporates:
   *  Product: '<S160>/Product2'
   *  Product: '<S160>/Product3'
   *  Selector: '<S189>/Selector1'
   *  Selector: '<S192>/Selector1'
   *  Switch: '<S194>/Switch3'
   *  Switch: '<S195>/Switch3'
   */
  rtb_Add1_f4ha =
      (dt_Standardize_s16p15b0)(((sint16)((rtb_Switch3_eodk *
                                           rtb_Selector1_hkbk) >>
                                          14)) +
                                ((sint16)((rtb_Switch3 * rtb_Selector1_jaut) >>
                                          14)));

  /* DataTypeConversion: '<S147>/Data Type Conversion1' incorporates:
   *  Gain: '<S112>/Gain4'
   *  Saturate: '<S131>/Saturation'
   */
  rtb_DataTypeConversion1_acqu =
      (((dt_Standardize_s16p15b0)(-rtb_Saturation_cnrk)) << 6);

  /* Switch: '<S158>/Switch2' incorporates:
   *  DataTypeConversion: '<S147>/Data Type Conversion'
   *  DataTypeConversion: '<S147>/Data Type Conversion1'
   *  RelationalOperator: '<S158>/Relational Operator2'
   */
  if (rtb_DataTypeConversion_bgrg > rtb_DataTypeConversion1_acqu) {
    /* Lookup_n-D: '<S112>/Gu16_facPLLCtlKp_MAP' incorporates:
     *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
     *  UnitDelay: '<S112>/Unit Delay2'
     */
    rtb_Gu16_facPLLCtlKp_MAP = look2_iu8s16lu32n16tu16_binlcse(
        busPhVltgGen_MedTaskIn.u8_tPCBTempSubs,
        ASW_PhVltgGen_DW.UnitDelay2_DSTATE,
        &Gu8_facPLLCtlKp_MAP_tPCBTempSubs_X[0],
        &Gs16_facPLLCtlKp_MAP_nActElecSpd_Y[0], &Gu16_facPLLCtlKp_MAP[0],
        rtCP_Gu16_facPLLCtlKp_MAP_maxIn, 4U);

    /* Saturate: '<S112>/Ast' incorporates:
     *  Lookup_n-D: '<S112>/Gu16_facPLLCtlKp_MAP'
     */
    if (rtb_Gu16_facPLLCtlKp_MAP <= 64000) {
      u0 = rtb_Gu16_facPLLCtlKp_MAP;
    } else {
      u0 = 64000U;
    }

    /* Product: '<S147>/Product' incorporates:
     *  Constant: '<S268>/Constant'
     *  Constant: '<S271>/Constant'
     *  Constant: '<S271>/Constant1'
     *  Gain: '<S268>/Gain'
     *  Gain: '<S271>/Gain'
     *  Product: '<S273>/Product1'
     *  Product: '<S273>/Product5'
     *  Saturate: '<S112>/Ast'
     *  Selector: '<S268>/Selector1'
     *  Selector: '<S271>/Selector1'
     *  Sum: '<S160>/Add'
     *  Sum: '<S160>/Add1'
     *  Sum: '<S271>/Add'
     *  Sum: '<S273>/Add3'
     *  UnitDelay: '<S112>/Unit Delay1'
     */
    rtb_lb_propActn_pdav =
        u0 *
        ((sint16)(((sint16)((rtb_Add1_f4ha *
                             rtCP_Constant1_Value_dstd[(
                                 sint32)((1023U *
                                          ((uint16)(16384 -
                                                    ASW_PhVltgGen_DW
                                                        .UnitDelay1_DSTATE_hljs))) >>
                                         16)]) >>
                            14)) -
                  ((sint16)((rtb_Add_dots *
                             rtCP_Constant_Value_c1xf[(
                                 sint32)((1023U *
                                          ASW_PhVltgGen_DW
                                              .UnitDelay1_DSTATE_hljs) >>
                                         16)]) >>
                            14))));

    /* Switch: '<S158>/Switch1' incorporates:
     *  Product: '<S147>/Product'
     *  RelationalOperator: '<S158>/Relational Operator1'
     */
    if (rtb_lb_propActn_pdav <= rtb_DataTypeConversion_bgrg) {
      /* Switch: '<S158>/Switch' incorporates:
       *  RelationalOperator: '<S158>/Relational Operator'
       */
      if (rtb_lb_propActn_pdav >= rtb_DataTypeConversion1_acqu) {
        /* Switch: '<S158>/Switch2' */
        rtb_Switch2_owyv = rtb_lb_propActn_pdav;
      } else {
        /* Switch: '<S158>/Switch2' */
        rtb_Switch2_owyv = rtb_DataTypeConversion1_acqu;
      }

      /* End of Switch: '<S158>/Switch' */
    } else {
      /* Switch: '<S158>/Switch2' */
      rtb_Switch2_owyv = rtb_DataTypeConversion_bgrg;
    }

    /* End of Switch: '<S158>/Switch1' */
  } else {
    rtb_Switch2_owyv = rtb_DataTypeConversion_bgrg;
  }

  /* End of Switch: '<S158>/Switch2' */

  /* DataTypeConversion: '<S147>/Data Type Conversion2' incorporates:
   *  Switch: '<S158>/Switch2'
   */
  rtb_DataTypeConversion2_jzfl =
      (dt_Standardize_s16p15b0)(rtb_Switch2_owyv >> 6);

  /* Switch: '<S147>/Switch1' incorporates:
   *  Constant: '<S141>/Constant4'
   *  DataTypeConversion: '<S147>/Data Type Conversion2'
   *  Sum: '<S147>/Add'
   */
  if (rtb_LogicalOperator_lnae) {
    rtb_Switch1_ma0d = 0;

    /* Switch: '<S149>/Switch1' incorporates:
     *  Constant: '<S141>/Constant4'
     *  Constant: '<S149>/Constant'
     *  Switch: '<S147>/Switch1'
     */
    rtb_Switch1 = 0;
  } else {
    rtb_Switch1_ma0d = rtb_DataTypeConversion2_jzfl;

    /* Lookup_n-D: '<S112>/Gu16_facPLLCtlKi_MAP' incorporates:
     *  DataTypeConversion: '<S147>/Data Type Conversion2'
     *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
     *  Sum: '<S147>/Add'
     *  Switch: '<S147>/Switch1'
     *  Switch: '<S149>/Switch1'
     *  UnitDelay: '<S112>/Unit Delay2'
     */
    rtb_Gu16_facPLLCtlKi_MAP = look2_iu8s16lu32n16tu16_binlcse(
        busPhVltgGen_MedTaskIn.u8_tPCBTempSubs,
        ASW_PhVltgGen_DW.UnitDelay2_DSTATE,
        &Gu8_facPLLCtlKp_MAP_tPCBTempSubs_X[0],
        &Gs16_facPLLCtlKp_MAP_nActElecSpd_Y[0], &Gu16_facPLLCtlKi_MAP[0],
        rtCP_Gu16_facPLLCtlKi_MAP_maxIn, 4U);

    /* Saturate: '<S112>/Saturation3' incorporates:
     *  Lookup_n-D: '<S112>/Gu16_facPLLCtlKi_MAP'
     *  Switch: '<S149>/Switch1'
     */
    if (rtb_Gu16_facPLLCtlKi_MAP <= 64000) {
      u0 = rtb_Gu16_facPLLCtlKi_MAP;
    } else {
      u0 = 64000U;
    }

    /* Switch: '<S149>/Switch1' incorporates:
     *  Constant: '<S127>/Constant5'
     *  DataTypeConversion: '<S147>/Data Type Conversion2'
     *  Product: '<S149>/Product1'
     *  Product: '<S149>/Product2'
     *  Saturate: '<S112>/Saturation3'
     *  Sum: '<S141>/Add1'
     *  Sum: '<S141>/Add3'
     *  UnitDelay: '<S141>/Unit Delay'
     *  UnitDelay: '<S141>/Unit Delay1'
     */
    rtb_Switch1 = mul_ssu32_loSR(
        ((sint16)(rtb_DataTypeConversion2_jzfl +
                  (((sint16)((ASW_PhVltgGen_DW.UnitDelay_DSTATE_mo0h -
                              (ASW_PhVltgGen_DW.UnitDelay1_DSTATE_fzlc << 1)) >>
                             1))
                   << 1))) *
            33554,
        u0, 15U);
  }

  /* End of Switch: '<S147>/Switch1' */

  /* Switch: '<S155>/Switch1' incorporates:
   *  Constant: '<S155>/Constant1'
   *  UnitDelay: '<S155>/Unit Delay1'
   */
  if (ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_kcff) {
    rtb_bolIntg1RsetCond_gnti = rtb_LogicalOperator_lnae;
  } else {
    rtb_bolIntg1RsetCond_gnti = true;
  }

  /* Switch: '<S155>/Switch' incorporates:
   *  DataTypeConversion: '<S149>/Data Type Conversion2'
   *  Switch: '<S155>/Switch1'
   *  UnitDelay: '<S155>/Unit Delay'
   */
  if (rtb_bolIntg1RsetCond_gnti) {
    rtb_TmpSignalConversionAtBusC_2 = 0;
  } else {
    rtb_TmpSignalConversionAtBusC_2 = ASW_PhVltgGen_DW.UnitDelay_DSTATE;
  }

  /* Sum: '<S149>/Sum' incorporates:
   *  Switch: '<S149>/Switch1'
   *  Switch: '<S155>/Switch'
   */
  rtb_Sum = (rtb_Switch1 >> 1) + rtb_TmpSignalConversionAtBusC_2;

  /* Sum: '<S141>/Add2' incorporates:
   *  DataTypeConversion: '<S149>/Data Type Conversion'
   *  Sum: '<S149>/Sum'
   *  Switch: '<S147>/Switch1'
   *  Switch: '<S149>/Switch'
   */
  rtb_Add2_bakf = (sint16)((rtb_Switch1_ma0d + (rtb_Sum >> 16)) >> 1);

  /* DataTypeConversion: '<S141>/Data Type Conversion1' incorporates:
   *  Gain: '<S112>/Gain4'
   *  Saturate: '<S131>/Saturation'
   */
  rtb_DataTypeConversion1_dd3w =
      (sint16)(((dt_Standardize_s16p15b0)(-rtb_Saturation_cnrk)) >> 1);

  /* Switch: '<S146>/Switch2' incorporates:
   *  DataTypeConversion: '<S141>/Data Type Conversion'
   *  DataTypeConversion: '<S141>/Data Type Conversion1'
   *  RelationalOperator: '<S146>/Relational Operator2'
   */
  if (rtb_DataTypeConversion_a45q > rtb_DataTypeConversion1_dd3w) {
    /* Switch: '<S146>/Switch1' incorporates:
     *  RelationalOperator: '<S146>/Relational Operator1'
     *  Sum: '<S141>/Add2'
     */
    if (rtb_Add2_bakf <= rtb_DataTypeConversion_a45q) {
      /* Switch: '<S146>/Switch' incorporates:
       *  RelationalOperator: '<S146>/Relational Operator'
       */
      if (rtb_Add2_bakf >= rtb_DataTypeConversion1_dd3w) {
        tmp = rtb_Add2_bakf;
      } else {
        tmp = rtb_DataTypeConversion1_dd3w;
      }

      /* End of Switch: '<S146>/Switch' */
    } else {
      tmp = rtb_DataTypeConversion_a45q;
    }

    /* End of Switch: '<S146>/Switch1' */
  } else {
    tmp = rtb_DataTypeConversion_a45q;
  }

  /* DataTypeConversion: '<S141>/Data Type Conversion2' incorporates:
   *  Switch: '<S146>/Switch2'
   */
  rtb_DataTypeConversion2_hco0 = (dt_Standardize_s16p15b0)(tmp << 1);

  /* Switch: '<S42>/Switch1' incorporates:
   *  DataTypeConversion: '<S141>/Data Type Conversion2'
   *  Saturate: '<S4>/Saturation2'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S274>/Add' incorporates:
     *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
     *  UnitDelay: '<S274>/Unit Delay'
     */
    rtb_lb_tmprInpDev = (sint16)(busPhVltgGen_MedTaskIn.u16_phiSensActElecAg -
                                 ASW_PhVltgGen_DW.UnitDelay_DSTATE_beui);

    /* Saturate: '<S278>/Saturation' incorporates:
     *  Sum: '<S274>/Add'
     */
    if (rtb_lb_tmprInpDev > 16384) {
      tmp = 16384;
    } else if (rtb_lb_tmprInpDev < -16384) {
      tmp = -16384;
    } else {
      tmp = rtb_lb_tmprInpDev;
    }

    /* Saturate: '<S4>/Saturation1' incorporates:
     *  Gain: '<S274>/Gain'
     *  Product: '<S274>/mul_KdX_part1'
     *  Saturate: '<S278>/Saturation'
     *  Switch: '<S42>/Switch1'
     */
    rtb_Switch1_jfzu =
        (dt_Standardize_s16p15b0)((((tmp << 14) / 16777) * 3217) >> 11);
  } else if (rtb_DataTypeConversion2_hco0 >= -32767) {
    /* Saturate: '<S4>/Saturation2' incorporates:
     *  DataTypeConversion: '<S141>/Data Type Conversion2'
     *  Switch: '<S42>/Switch1'
     */
    rtb_Switch1_jfzu = rtb_DataTypeConversion2_hco0;
  } else {
    rtb_Switch1_jfzu = -32767;
  }

  /* End of Switch: '<S42>/Switch1' */

  /* Saturate: '<S71>/Saturation' incorporates:
   *  Constant: '<S71>/Constant'
   */
  if (Gu16_facSpdFltCoeff_C > 39322) {
    rtb_Saturation_pmq2 = 39322U;
  } else if (Gu16_facSpdFltCoeff_C < 4000) {
    rtb_Saturation_pmq2 = 4000U;
  } else {
    rtb_Saturation_pmq2 = Gu16_facSpdFltCoeff_C;
  }

  /* End of Saturate: '<S71>/Saturation' */

  /* Sum: '<S74>/Add1' incorporates:
   *  Constant: '<S74>/Constant'
   *  Product: '<S74>/Product'
   *  Product: '<S74>/Product1'
   *  Saturate: '<S71>/Saturation'
   *  Sum: '<S74>/Add2'
   *  Switch: '<S42>/Switch1'
   *  UnitDelay: '<S74>/Unit Delay'
   */
  rtb_Add1_afic = (sint16)((((rtb_Switch1_jfzu * rtb_Saturation_pmq2) >> 16) +
                            (((((131072 - rtb_Saturation_pmq2) >> 2) *
                               ASW_PhVltgGen_DW.UnitDelay_DSTATE_fiwk) >>
                              15)
                             << 1)) >>
                           1);

  /* Saturate: '<S340>/Saturation2' incorporates:
   *  Sum: '<S74>/Add1'
   */
  if (rtb_Add1_afic >= -32767) {
    tmp = rtb_Add1_afic;
  } else {
    tmp = -32767;
  }

  /* Sum: '<S340>/Add1' incorporates:
   *  Constant: '<S340>/Gs16_tCtlVltgDelTi_C'
   *  Gain: '<S340>/Gain'
   *  Product: '<S340>/Product2'
   *  Saturate: '<S340>/Saturation2'
   *  Switch: '<S345>/Switch1'
   */
  rtb_Add1 = (dt_RadAng_u16r15b0)(rtb_Switch1_d0v1 +
                                  ((sint16)((((sint16)(((tmp >> 1) *
                                                        Gs16_tCtlVltgDelTi_C) >>
                                                       10)) *
                                             20861) >>
                                            14)));

  /* Selector: '<S363>/Selector1' incorporates:
   *  Constant: '<S363>/Constant'
   *  Constant: '<S363>/Constant1'
   *  Gain: '<S363>/Gain'
   *  Sum: '<S340>/Add1'
   *  Sum: '<S363>/Add'
   */
  rtb_Selector1_prdr = rtCP_Constant1_Value_hq2b[(
      sint32)((1023U * ((uint16)(16384 - rtb_Add1))) >> 16)];

  /* Saturate: '<S340>/Saturation4' incorporates:
   *  Sum: '<S19>/Add1'
   */
  if (rtb_Add1_cq0f >= -32767) {
    rtb_Saturation4_ectf = rtb_Add1_cq0f;
  } else {
    rtb_Saturation4_ectf = -32767;
  }

  /* End of Saturate: '<S340>/Saturation4' */

  /* Selector: '<S360>/Selector1' incorporates:
   *  Constant: '<S360>/Constant'
   *  Gain: '<S360>/Gain'
   */
  rtb_Selector1_blvz =
      rtCP_Constant_Value_lajm[(sint32)((1023U * rtb_Add1) >> 16)];

  /* Saturate: '<S6>/Saturation1' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  if (busPhVltgGen_MedTaskIn.u16_uSplyVltg <= 32767) {
    u0 = busPhVltgGen_MedTaskIn.u16_uSplyVltg;
  } else {
    u0 = 32767U;
  }

  /* Product: '<S6>/Product' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  Saturate: '<S6>/Saturation1'
   */
  rtb_Product =
      (dt_Standardize_u16p15b0)((((uint32)u0) *
                                 busPhVltgGen_MedTaskIn.u16_ampMaxNrmVltgAmp) >>
                                15);

  /* Saturate: '<S3>/Saturation1' incorporates:
   *  Product: '<S6>/Product'
   */
  if (rtb_Product <= 32767) {
    rtb_Saturation1_iw11 = rtb_Product;
  } else {
    rtb_Saturation1_iw11 = 32767U;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Product: '<S6>/Product'
   */
  rtb_Product1_dtaz = (dt_Standardize_s16p15b0)((((uint32)rtb_Product) *
                                                 Gu16_rMaxVltgAmpRat_C) >>
                                                15);

  /* Saturate: '<S280>/Saturation4' incorporates:
   *  Product: '<S6>/Product1'
   */
  if (rtb_Product1_dtaz >= -32767) {
    rtb_Saturation4_ioke = rtb_Product1_dtaz;
  } else {
    rtb_Saturation4_ioke = -32767;
  }

  /* End of Saturate: '<S280>/Saturation4' */

  /* DataTypeConversion: '<S293>/Data Type Conversion' incorporates:
   *  Saturate: '<S280>/Saturation4'
   */
  rtb_DataTypeConversion_esjp = (sint16)(rtb_Saturation4_ioke >> 1);

  /* RelationalOperator: '<S281>/Compare' incorporates:
   *  Constant: '<S281>/Constant'
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  RelationalOperator: '<S372>/Compare'
   */
  rtb_Compare_chmk = (busPhVltgGen_MedTaskIn.enm_stMotoSt == OFF);

  /* DataTypeConversion: '<S299>/Data Type Conversion' incorporates:
   *  Saturate: '<S280>/Saturation4'
   */
  rtb_DataTypeConversion = (rtb_Saturation4_ioke << 16);

  /* DataTypeConversion: '<S299>/Data Type Conversion1' incorporates:
   *  Gain: '<S280>/Gain'
   *  Saturate: '<S280>/Saturation4'
   */
  rtb_DataTypeConversion1 =
      (((dt_Standardize_s16p15b0)(-rtb_Saturation4_ioke)) << 16);

  /* Switch: '<S310>/Switch2' incorporates:
   *  DataTypeConversion: '<S299>/Data Type Conversion'
   *  DataTypeConversion: '<S299>/Data Type Conversion1'
   *  RelationalOperator: '<S310>/Relational Operator2'
   */
  if (rtb_DataTypeConversion > rtb_DataTypeConversion1) {
    /* Saturate: '<S288>/Saturation' incorporates:
     *  Constant: '<S288>/Constant'
     */
    if (Gu16_facDaxCurrCtlKp_C <= 18204) {
      u0 = Gu16_facDaxCurrCtlKp_C;
    } else {
      u0 = 18204U;
    }

    /* Saturate: '<S280>/Saturation' incorporates:
     *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
     */
    if (busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[0] > 14746) {
      tmp = 14746;
    } else if (busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[0] < -14746) {
      tmp = -14746;
    } else {
      tmp = busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[0];
    }

    /* Saturate: '<S280>/Saturation1' */
    if (rtb_TmpSignalConversionAtBusC_1 > 14746) {
      tmp_1 = 14746;
    } else if (rtb_TmpSignalConversionAtBusC_1 < -14746) {
      tmp_1 = -14746;
    } else {
      tmp_1 = rtb_TmpSignalConversionAtBusC_1;
    }

    /* Product: '<S299>/Product' incorporates:
     *  Saturate: '<S280>/Saturation'
     *  Saturate: '<S280>/Saturation1'
     *  Saturate: '<S288>/Saturation'
     *  Sum: '<S286>/Add1'
     */
    rtb_lb_propActn_i4nd = ((u0 * (tmp - tmp_1)) << 2);

    /* Switch: '<S310>/Switch1' incorporates:
     *  Product: '<S299>/Product'
     *  RelationalOperator: '<S310>/Relational Operator1'
     */
    if (rtb_lb_propActn_i4nd <= rtb_DataTypeConversion) {
      /* Switch: '<S310>/Switch' incorporates:
       *  RelationalOperator: '<S310>/Relational Operator'
       */
      if (rtb_lb_propActn_i4nd >= rtb_DataTypeConversion1) {
        /* Switch: '<S310>/Switch2' */
        rtb_Switch2 = rtb_lb_propActn_i4nd;
      } else {
        /* Switch: '<S310>/Switch2' */
        rtb_Switch2 = rtb_DataTypeConversion1;
      }

      /* End of Switch: '<S310>/Switch' */
    } else {
      /* Switch: '<S310>/Switch2' */
      rtb_Switch2 = rtb_DataTypeConversion;
    }

    /* End of Switch: '<S310>/Switch1' */
  } else {
    rtb_Switch2 = rtb_DataTypeConversion;
  }

  /* End of Switch: '<S310>/Switch2' */

  /* DataTypeConversion: '<S299>/Data Type Conversion2' incorporates:
   *  Switch: '<S310>/Switch2'
   */
  rtb_DataTypeConversion2_mweb = (dt_Standardize_s16p15b0)(rtb_Switch2 >> 16);

  /* Switch: '<S299>/Switch1' incorporates:
   *  Constant: '<S293>/Constant4'
   *  DataTypeConversion: '<S299>/Data Type Conversion2'
   *  Sum: '<S299>/Add'
   */
  if (rtb_Compare_chmk) {
    rtb_Switch1_k0pc = 0;

    /* Switch: '<S301>/Switch1' incorporates:
     *  Constant: '<S293>/Constant4'
     *  Constant: '<S301>/Constant'
     *  Switch: '<S299>/Switch1'
     */
    rtb_Switch1_gm5h = 0;
  } else {
    rtb_Switch1_k0pc = rtb_DataTypeConversion2_mweb;

    /* Saturate: '<S290>/Saturation' incorporates:
     *  Constant: '<S290>/Constant'
     *  DataTypeConversion: '<S299>/Data Type Conversion2'
     *  Sum: '<S299>/Add'
     *  Switch: '<S299>/Switch1'
     *  Switch: '<S301>/Switch1'
     */
    if (Gu16_facDaxCurrCtlKi_C <= 63998) {
      u0 = Gu16_facDaxCurrCtlKi_C;
    } else {
      u0 = 63998U;
    }

    /* Switch: '<S301>/Switch1' incorporates:
     *  Constant: '<S286>/Constant5'
     *  DataTypeConversion: '<S299>/Data Type Conversion2'
     *  Product: '<S301>/Product1'
     *  Product: '<S301>/Product2'
     *  Saturate: '<S290>/Saturation'
     *  Sum: '<S293>/Add1'
     *  Sum: '<S293>/Add3'
     *  UnitDelay: '<S293>/Unit Delay'
     *  UnitDelay: '<S293>/Unit Delay1'
     */
    rtb_Switch1_gm5h = mul_ssu32_loSR(
        ((sint16)(rtb_DataTypeConversion2_mweb +
                  (((sint16)((ASW_PhVltgGen_DW.UnitDelay_DSTATE_p44p -
                              (ASW_PhVltgGen_DW.UnitDelay1_DSTATE_gk3t << 1)) >>
                             1))
                   << 1))) *
            33554,
        u0, 15U);
  }

  /* End of Switch: '<S299>/Switch1' */

  /* Switch: '<S307>/Switch1' incorporates:
   *  Constant: '<S307>/Constant1'
   *  UnitDelay: '<S307>/Unit Delay1'
   */
  if (ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_la0o) {
    rtb_bolIntg1RsetCond_gnti = rtb_Compare_chmk;
  } else {
    rtb_bolIntg1RsetCond_gnti = true;
  }

  /* Switch: '<S307>/Switch' incorporates:
   *  DataTypeConversion: '<S301>/Data Type Conversion2'
   *  Switch: '<S307>/Switch1'
   *  UnitDelay: '<S307>/Unit Delay'
   */
  if (rtb_bolIntg1RsetCond_gnti) {
    rtb_TmpSignalConversionAtBusC_2 = 0;
  } else {
    rtb_TmpSignalConversionAtBusC_2 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_kt4g;
  }

  /* Sum: '<S301>/Sum' incorporates:
   *  Switch: '<S301>/Switch1'
   *  Switch: '<S307>/Switch'
   */
  rtb_Sum_g421 = rtb_Switch1_gm5h + rtb_TmpSignalConversionAtBusC_2;

  /* Sum: '<S293>/Add2' incorporates:
   *  DataTypeConversion: '<S301>/Data Type Conversion'
   *  Sum: '<S301>/Sum'
   *  Switch: '<S299>/Switch1'
   *  Switch: '<S301>/Switch'
   */
  rtb_Add2_aalz = (sint16)((rtb_Switch1_k0pc + (rtb_Sum_g421 >> 16)) >> 1);

  /* DataTypeConversion: '<S293>/Data Type Conversion1' incorporates:
   *  Gain: '<S280>/Gain'
   *  Saturate: '<S280>/Saturation4'
   */
  rtb_DataTypeConversion1_dkcs =
      (sint16)(((dt_Standardize_s16p15b0)(-rtb_Saturation4_ioke)) >> 1);

  /* Switch: '<S298>/Switch2' incorporates:
   *  DataTypeConversion: '<S293>/Data Type Conversion'
   *  DataTypeConversion: '<S293>/Data Type Conversion1'
   *  RelationalOperator: '<S298>/Relational Operator2'
   */
  if (rtb_DataTypeConversion_esjp > rtb_DataTypeConversion1_dkcs) {
    /* Switch: '<S298>/Switch1' incorporates:
     *  RelationalOperator: '<S298>/Relational Operator1'
     *  Sum: '<S293>/Add2'
     */
    if (rtb_Add2_aalz <= rtb_DataTypeConversion_esjp) {
      /* Switch: '<S298>/Switch' incorporates:
       *  RelationalOperator: '<S298>/Relational Operator'
       */
      if (rtb_Add2_aalz >= rtb_DataTypeConversion1_dkcs) {
        tmp = rtb_Add2_aalz;
      } else {
        tmp = rtb_DataTypeConversion1_dkcs;
      }

      /* End of Switch: '<S298>/Switch' */
    } else {
      tmp = rtb_DataTypeConversion_esjp;
    }

    /* End of Switch: '<S298>/Switch1' */
  } else {
    tmp = rtb_DataTypeConversion_esjp;
  }

  /* DataTypeConversion: '<S293>/Data Type Conversion2' incorporates:
   *  Switch: '<S298>/Switch2'
   */
  rtb_DataTypeConversion2_gwbl = (dt_Standardize_s16p15b0)(tmp << 1);

  /* Saturate: '<S5>/Saturation' incorporates:
   *  DataTypeConversion: '<S293>/Data Type Conversion2'
   */
  if (rtb_DataTypeConversion2_gwbl >= -32767) {
    rtb_Saturation_lsvn = rtb_DataTypeConversion2_gwbl;
  } else {
    rtb_Saturation_lsvn = -32767;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* If: '<S103>/If' incorporates:
   *  Abs: '<S106>/Abs'
   *  Logic: '<S103>/AND'
   *  Product: '<S6>/Product1'
   *  RelationalOperator: '<S104>/Compare'
   *  RelationalOperator: '<S105>/Compare'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if ((rtb_Product1_dtaz == 0) &&
      (ASW_PhVltgGen_DW.UnitDelay_DSTATE_ksxz == 0)) {
    /* Outputs for IfAction SubSystem: '<S103>/ias_ZeroInput' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    /* SignalConversion generated from: '<S107>/lb_genHypt' incorporates:
     *  Constant: '<S107>/Constant'
     *  Merge: '<S103>/Merge'
     */
    rtb_Merge_mz25 = 0;

    /* End of Outputs for SubSystem: '<S103>/ias_ZeroInput' */
  } else {
    /* Outputs for IfAction SubSystem: '<S103>/ias_NonZeroInput' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    if (rtb_Product1_dtaz < 0) {
      /* Abs: '<S106>/Abs' */
      rtb_Abs_maf2 = (dt_Standardize_s16p15b0)(-rtb_Product1_dtaz);
    } else {
      /* Abs: '<S106>/Abs' */
      rtb_Abs_maf2 = rtb_Product1_dtaz;
    }

    /* Selector: '<S106>/Selector1' incorporates:
     *  Abs: '<S106>/Abs'
     *  Abs: '<S106>/Abs1'
     *  Gain: '<S106>/Gain'
     *  Product: '<S106>/Divide2'
     *  Saturate: '<S106>/Saturation'
     */
    if (ASW_PhVltgGen_DW.UnitDelay_DSTATE_ksxz < 0) {
      tmp = (sint16)(-ASW_PhVltgGen_DW.UnitDelay_DSTATE_ksxz);
    } else {
      tmp = ASW_PhVltgGen_DW.UnitDelay_DSTATE_ksxz;
    }

    u0 = (uint16)((511U * ((uint16)((tmp << 15) / rtb_Abs_maf2))) >> 15);
    if (u0 <= 511) {
    } else {
      u0 = 511U;
    }

    /* SignalConversion generated from: '<S106>/lb_genHypt' incorporates:
     *  Abs: '<S106>/Abs'
     *  Constant: '<S106>/Constant3'
     *  Merge: '<S103>/Merge'
     *  Product: '<S106>/Multiply'
     *  Saturate: '<S106>/Saturation'
     *  Selector: '<S106>/Selector1'
     */
    rtb_Merge_mz25 = (dt_Standardize_s16p15b0)((rtCP_Constant3_Value_oh4i[u0] *
                                                rtb_Abs_maf2) >>
                                               15);

    /* End of Outputs for SubSystem: '<S103>/ias_NonZeroInput' */
  }

  /* End of If: '<S103>/If' */

  /* Saturate: '<S280>/Saturation5' incorporates:
   *  Merge: '<S103>/Merge'
   */
  if (rtb_Merge_mz25 >= -32767) {
    rtb_Saturation5 = rtb_Merge_mz25;
  } else {
    rtb_Saturation5 = -32767;
  }

  /* End of Saturate: '<S280>/Saturation5' */

  /* DataTypeConversion: '<S320>/Data Type Conversion' incorporates:
   *  Saturate: '<S280>/Saturation5'
   */
  rtb_DataTypeConversion_bmde = (sint16)(rtb_Saturation5 >> 1);

  /* DataTypeConversion: '<S326>/Data Type Conversion' incorporates:
   *  Saturate: '<S280>/Saturation5'
   */
  rtb_DataTypeConversion_lkol = (rtb_Saturation5 << 16);

  /* DataTypeConversion: '<S326>/Data Type Conversion1' incorporates:
   *  Gain: '<S280>/Gain1'
   *  Saturate: '<S280>/Saturation5'
   */
  rtb_DataTypeConversion1_i3ac =
      (((dt_Standardize_s16p15b0)(-rtb_Saturation5)) << 16);

  /* Switch: '<S337>/Switch2' incorporates:
   *  DataTypeConversion: '<S326>/Data Type Conversion'
   *  DataTypeConversion: '<S326>/Data Type Conversion1'
   *  RelationalOperator: '<S337>/Relational Operator2'
   */
  if (rtb_DataTypeConversion_lkol > rtb_DataTypeConversion1_i3ac) {
    /* Saturate: '<S315>/Saturation' incorporates:
     *  Constant: '<S315>/Constant'
     */
    if (Gu16_facQaxCurrCtlKp_C <= 18204) {
      u0 = Gu16_facQaxCurrCtlKp_C;
    } else {
      u0 = 18204U;
    }

    /* Saturate: '<S280>/Saturation' incorporates:
     *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
     */
    if (busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[1] > 14746) {
      tmp = 14746;
    } else if (busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[1] < -14746) {
      tmp = -14746;
    } else {
      tmp = busPhVltgGen_MedTaskIn.s16_iRefDaxQaxCurr[1];
    }

    /* Saturate: '<S280>/Saturation1' */
    if (rtb_TmpSignalConversionAtBusC_0 > 14746) {
      tmp_1 = 14746;
    } else if (rtb_TmpSignalConversionAtBusC_0 < -14746) {
      tmp_1 = -14746;
    } else {
      tmp_1 = rtb_TmpSignalConversionAtBusC_0;
    }

    /* Product: '<S326>/Product' incorporates:
     *  Saturate: '<S280>/Saturation'
     *  Saturate: '<S280>/Saturation1'
     *  Saturate: '<S315>/Saturation'
     *  Sum: '<S313>/Add1'
     */
    rtb_lb_propActn = ((u0 * (tmp - tmp_1)) << 2);

    /* Switch: '<S337>/Switch1' incorporates:
     *  Product: '<S326>/Product'
     *  RelationalOperator: '<S337>/Relational Operator1'
     */
    if (rtb_lb_propActn <= rtb_DataTypeConversion_lkol) {
      /* Switch: '<S337>/Switch' incorporates:
       *  RelationalOperator: '<S337>/Relational Operator'
       */
      if (rtb_lb_propActn >= rtb_DataTypeConversion1_i3ac) {
        /* Switch: '<S337>/Switch2' */
        rtb_Switch2_obfd = rtb_lb_propActn;
      } else {
        /* Switch: '<S337>/Switch2' */
        rtb_Switch2_obfd = rtb_DataTypeConversion1_i3ac;
      }

      /* End of Switch: '<S337>/Switch' */
    } else {
      /* Switch: '<S337>/Switch2' */
      rtb_Switch2_obfd = rtb_DataTypeConversion_lkol;
    }

    /* End of Switch: '<S337>/Switch1' */
  } else {
    rtb_Switch2_obfd = rtb_DataTypeConversion_lkol;
  }

  /* End of Switch: '<S337>/Switch2' */

  /* DataTypeConversion: '<S326>/Data Type Conversion2' incorporates:
   *  Switch: '<S337>/Switch2'
   */
  rtb_DataTypeConversion2_bcnl =
      (dt_Standardize_s16p15b0)(rtb_Switch2_obfd >> 16);

  /* Switch: '<S326>/Switch1' incorporates:
   *  Constant: '<S320>/Constant4'
   *  DataTypeConversion: '<S326>/Data Type Conversion2'
   *  Sum: '<S326>/Add'
   */
  if (rtb_Compare_chmk) {
    rtb_Switch1_bgmj = 0;

    /* Switch: '<S328>/Switch1' incorporates:
     *  Constant: '<S320>/Constant4'
     *  Constant: '<S328>/Constant'
     *  Switch: '<S326>/Switch1'
     */
    rtb_Switch1_bxrl = 0;
  } else {
    rtb_Switch1_bgmj = rtb_DataTypeConversion2_bcnl;

    /* Saturate: '<S317>/Saturation' incorporates:
     *  Constant: '<S317>/Constant'
     *  DataTypeConversion: '<S326>/Data Type Conversion2'
     *  Sum: '<S326>/Add'
     *  Switch: '<S326>/Switch1'
     *  Switch: '<S328>/Switch1'
     */
    if (Gu16_facQaxCurrCtlKi_C <= 63998) {
      u0 = Gu16_facQaxCurrCtlKi_C;
    } else {
      u0 = 63998U;
    }

    /* Switch: '<S328>/Switch1' incorporates:
     *  Constant: '<S313>/Constant5'
     *  DataTypeConversion: '<S326>/Data Type Conversion2'
     *  Product: '<S328>/Product1'
     *  Product: '<S328>/Product2'
     *  Saturate: '<S317>/Saturation'
     *  Sum: '<S320>/Add1'
     *  Sum: '<S320>/Add3'
     *  UnitDelay: '<S320>/Unit Delay'
     *  UnitDelay: '<S320>/Unit Delay1'
     */
    rtb_Switch1_bxrl = mul_ssu32_loSR(
        ((sint16)(rtb_DataTypeConversion2_bcnl +
                  (((sint16)((ASW_PhVltgGen_DW.UnitDelay_DSTATE_gvry -
                              (ASW_PhVltgGen_DW.UnitDelay1_DSTATE_mewr << 1)) >>
                             1))
                   << 1))) *
            33554,
        u0, 15U);
  }

  /* End of Switch: '<S326>/Switch1' */

  /* Switch: '<S334>/Switch1' incorporates:
   *  Constant: '<S334>/Constant1'
   *  UnitDelay: '<S334>/Unit Delay1'
   */
  if (ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_l4aj) {
    rtb_bolIntg1RsetCond_gnti = rtb_Compare_chmk;
  } else {
    rtb_bolIntg1RsetCond_gnti = true;
  }

  /* Switch: '<S334>/Switch' incorporates:
   *  DataTypeConversion: '<S328>/Data Type Conversion2'
   *  Switch: '<S334>/Switch1'
   *  UnitDelay: '<S334>/Unit Delay'
   */
  if (rtb_bolIntg1RsetCond_gnti) {
    rtb_TmpSignalConversionAtBusC_2 = 0;
  } else {
    rtb_TmpSignalConversionAtBusC_2 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_afgq;
  }

  /* Sum: '<S328>/Sum' incorporates:
   *  Switch: '<S328>/Switch1'
   *  Switch: '<S334>/Switch'
   */
  rtb_Sum_krjk = rtb_Switch1_bxrl + rtb_TmpSignalConversionAtBusC_2;

  /* Sum: '<S320>/Add2' incorporates:
   *  DataTypeConversion: '<S328>/Data Type Conversion'
   *  Sum: '<S328>/Sum'
   *  Switch: '<S326>/Switch1'
   *  Switch: '<S328>/Switch'
   */
  rtb_Add2_doeq = (sint16)((rtb_Switch1_bgmj + (rtb_Sum_krjk >> 16)) >> 1);

  /* DataTypeConversion: '<S320>/Data Type Conversion1' incorporates:
   *  Gain: '<S280>/Gain1'
   *  Saturate: '<S280>/Saturation5'
   */
  rtb_DataTypeConversion1_eqye =
      (sint16)(((dt_Standardize_s16p15b0)(-rtb_Saturation5)) >> 1);

  /* Switch: '<S325>/Switch2' incorporates:
   *  DataTypeConversion: '<S320>/Data Type Conversion'
   *  DataTypeConversion: '<S320>/Data Type Conversion1'
   *  RelationalOperator: '<S325>/Relational Operator2'
   */
  if (rtb_DataTypeConversion_bmde > rtb_DataTypeConversion1_eqye) {
    /* Switch: '<S325>/Switch1' incorporates:
     *  RelationalOperator: '<S325>/Relational Operator1'
     *  Sum: '<S320>/Add2'
     */
    if (rtb_Add2_doeq <= rtb_DataTypeConversion_bmde) {
      /* Switch: '<S325>/Switch' incorporates:
       *  RelationalOperator: '<S325>/Relational Operator'
       */
      if (rtb_Add2_doeq >= rtb_DataTypeConversion1_eqye) {
        tmp = rtb_Add2_doeq;
      } else {
        tmp = rtb_DataTypeConversion1_eqye;
      }

      /* End of Switch: '<S325>/Switch' */
    } else {
      tmp = rtb_DataTypeConversion_bmde;
    }

    /* End of Switch: '<S325>/Switch1' */
  } else {
    tmp = rtb_DataTypeConversion_bmde;
  }

  /* DataTypeConversion: '<S320>/Data Type Conversion2' incorporates:
   *  Switch: '<S325>/Switch2'
   */
  rtb_DataTypeConversion2_o3w2 = (dt_Standardize_s16p15b0)(tmp << 1);

  /* Saturate: '<S5>/Saturation1' incorporates:
   *  DataTypeConversion: '<S320>/Data Type Conversion2'
   */
  if (rtb_DataTypeConversion2_o3w2 >= -32767) {
    rtb_Saturation1_cdwd = rtb_DataTypeConversion2_o3w2;
  } else {
    rtb_Saturation1_cdwd = -32767;
  }

  /* End of Saturate: '<S5>/Saturation1' */

  /* If: '<S78>/If' incorporates:
   *  Abs: '<S82>/Abs'
   *  Logic: '<S78>/AND'
   *  RelationalOperator: '<S80>/Compare'
   *  RelationalOperator: '<S81>/Compare'
   *  Saturate: '<S5>/Saturation'
   *  Saturate: '<S5>/Saturation1'
   */
  if ((rtb_Saturation_lsvn == 0) && (rtb_Saturation1_cdwd == 0)) {
    /* Outputs for IfAction SubSystem: '<S78>/ias_ZeroInput' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    /* SignalConversion generated from: '<S83>/lb_genHypt' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S78>/Merge'
     */
    rtb_Merge_kvzd = 0U;

    /* End of Outputs for SubSystem: '<S78>/ias_ZeroInput' */
  } else {
    /* Outputs for IfAction SubSystem: '<S78>/ias_NonZeroInput' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    if (rtb_Saturation_lsvn < 0) {
      /* Abs: '<S82>/Abs' */
      rtb_Abs_jfp3 = (dt_Standardize_s16p15b0)(-rtb_Saturation_lsvn);
    } else {
      /* Abs: '<S82>/Abs' */
      rtb_Abs_jfp3 = rtb_Saturation_lsvn;
    }

    /* Abs: '<S82>/Abs1' */
    if (rtb_Saturation1_cdwd < 0) {
      rtb_Abs1_afkz = (dt_Standardize_s16p15b0)(-rtb_Saturation1_cdwd);
    } else {
      rtb_Abs1_afkz = rtb_Saturation1_cdwd;
    }

    /* End of Abs: '<S82>/Abs1' */

    /* MinMax: '<S82>/Min1' incorporates:
     *  Abs: '<S82>/Abs'
     *  Abs: '<S82>/Abs1'
     */
    if (rtb_Abs_jfp3 >= rtb_Abs1_afkz) {
      rtb_lb_genMaxInpMods_j3r1 = rtb_Abs_jfp3;
    } else {
      rtb_lb_genMaxInpMods_j3r1 = rtb_Abs1_afkz;
    }

    /* End of MinMax: '<S82>/Min1' */

    /* Selector: '<S82>/Selector1' incorporates:
     *  Abs: '<S82>/Abs'
     *  Abs: '<S82>/Abs1'
     *  Gain: '<S82>/Gain'
     *  MinMax: '<S82>/Min'
     *  MinMax: '<S82>/Min1'
     *  Product: '<S82>/Divide2'
     *  Saturate: '<S82>/Saturation'
     */
    if (rtb_Abs_jfp3 <= rtb_Abs1_afkz) {
      tmp = rtb_Abs_jfp3;
    } else {
      tmp = rtb_Abs1_afkz;
    }

    u0 =
        (uint16)((511U * ((uint16)((tmp << 15) / rtb_lb_genMaxInpMods_j3r1))) >>
                 15);
    if (u0 <= 511) {
    } else {
      u0 = 511U;
    }

    /* SignalConversion generated from: '<S82>/lb_genHypt' incorporates:
     *  Constant: '<S82>/Constant3'
     *  Merge: '<S78>/Merge'
     *  MinMax: '<S82>/Min1'
     *  Product: '<S82>/Multiply'
     *  Saturate: '<S82>/Saturation'
     *  Selector: '<S82>/Selector1'
     */
    rtb_Merge_kvzd = (dt_Standardize_u16p15b0)((rtCP_Constant3_Value_a0ct[u0] *
                                                rtb_lb_genMaxInpMods_j3r1) >>
                                               15);

    /* End of Outputs for SubSystem: '<S78>/ias_NonZeroInput' */
  }

  /* End of If: '<S78>/If' */

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Merge: '<S78>/Merge'
   */
  if (rtb_Merge_kvzd <= 32767) {
    rtb_Saturation_bskp = rtb_Merge_kvzd;
  } else {
    rtb_Saturation_bskp = 32767U;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* If: '<S3>/If' incorporates:
   *  MinMax: '<S3>/Min'
   *  RelationalOperator: '<S35>/Compare'
   *  Saturate: '<S3>/Saturation'
   *  Saturate: '<S3>/Saturation1'
   */
  if (rtb_Saturation1_iw11 == 0) {
    /* Outputs for IfAction SubSystem: '<S3>/ias_ZrIn' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* SignalConversion generated from: '<S37>/u16_ampDycAmpZrIn' incorporates:
     *  Constant: '<S37>/Constant'
     *  Merge: '<S3>/Merge'
     */
    busPhVltgGen_MedTaskOut.u16_ampDycAmp = 0U;

    /* End of Outputs for SubSystem: '<S3>/ias_ZrIn' */
  } else {
    if (rtb_Saturation_bskp <= rtb_Saturation1_iw11) {
      /* MinMax: '<S3>/Min' incorporates:
       *  Saturate: '<S3>/Saturation'
       */
      u0 = rtb_Saturation_bskp;
    } else {
      /* MinMax: '<S3>/Min' */
      u0 = rtb_Saturation1_iw11;
    }

    /* Outputs for IfAction SubSystem: '<S3>/ias_NotZrIn' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* SignalConversion generated from: '<S36>/u16_ampDycAmpNotZrIn'
     * incorporates: Merge: '<S3>/Merge' MinMax: '<S3>/Min' Product:
     * '<S36>/Divide'
     */
    busPhVltgGen_MedTaskOut.u16_ampDycAmp =
        (dt_DutyCycl_u16p15b0)((((uint32)u0) << 15) / rtb_Saturation1_iw11);

    /* End of Outputs for SubSystem: '<S3>/ias_NotZrIn' */
  }

  /* End of If: '<S3>/If' */

  /* If: '<S79>/If' incorporates:
   *  DataTypeConversion: '<S88>/Data Type Conversion'
   *  DataTypeConversion: '<S88>/Data Type Conversion3'
   *  Gain: '<S88>/Gain'
   *  If: '<S94>/If'
   *  Logic: '<S94>/AND'
   *  Logic: '<S94>/AND1'
   *  Logic: '<S94>/OR'
   *  Merge: '<S78>/Merge'
   *  RelationalOperator: '<S87>/Compare'
   *  RelationalOperator: '<S90>/Relational Operator2'
   *  RelationalOperator: '<S95>/Compare'
   *  RelationalOperator: '<S96>/Compare'
   *  RelationalOperator: '<S97>/Compare'
   *  RelationalOperator: '<S98>/Compare'
   *  Saturate: '<S5>/Saturation'
   *  Saturate: '<S5>/Saturation1'
   *  Switch: '<S90>/Switch2'
   */
  if (rtb_Merge_kvzd == 0) {
    /* Outputs for IfAction SubSystem: '<S79>/ias_ZeroInput' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    /* SignalConversion generated from: '<S89>/lb_arOutpPhs' incorporates:
     *  Constant: '<S89>/Constant'
     *  Merge: '<S79>/Merge'
     */
    busPhVltgGen_MedTaskOut.u16_phiDaxQaxVltgAg = 0U;

    /* End of Outputs for SubSystem: '<S79>/ias_ZeroInput' */

    /* Outputs for IfAction SubSystem: '<S79>/ias_NonZeroInput' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
  } else if (((rtb_Saturation1_cdwd >= 0) && (rtb_Saturation_lsvn >= 0)) ||
             ((rtb_Saturation1_cdwd < 0) && (rtb_Saturation_lsvn >= 0))) {
    /* Switch: '<S90>/Switch2' incorporates:
     *  DataTypeConversion: '<S88>/Data Type Conversion'
     *  DataTypeConversion: '<S88>/Data Type Conversion3'
     *  Gain: '<S88>/Gain'
     *  RelationalOperator: '<S90>/Relational Operator2'
     */
    if (((dt_Standardize_s16p15b0)rtb_Merge_kvzd) >
        ((dt_Standardize_s16p15b0)(-((sint16)rtb_Merge_kvzd)))) {
      /* Switch: '<S90>/Switch1' incorporates:
       *  RelationalOperator: '<S90>/Relational Operator1'
       *  Saturate: '<S5>/Saturation1'
       */
      if (rtb_Saturation1_cdwd <= ((dt_Standardize_s16p15b0)rtb_Merge_kvzd)) {
        /* Switch: '<S90>/Switch' incorporates:
         *  RelationalOperator: '<S90>/Relational Operator'
         */
        if (rtb_Saturation1_cdwd >=
            ((dt_Standardize_s16p15b0)(-((sint16)rtb_Merge_kvzd)))) {
          tmp = rtb_Saturation1_cdwd;
        } else {
          tmp = (dt_Standardize_s16p15b0)(-((sint16)rtb_Merge_kvzd));
        }
      } else {
        tmp = (dt_Standardize_s16p15b0)rtb_Merge_kvzd;
      }
    } else {
      tmp = (dt_Standardize_s16p15b0)rtb_Merge_kvzd;
    }

    /* Outputs for IfAction SubSystem: '<S94>/ias_AngleShiftNotApplied'
     * incorporates: ActionPort: '<S100>/Action Port'
     */
    /* If: '<S94>/If' incorporates:
     *  Constant: '<S88>/Constant'
     *  Constant: '<S88>/lb_parAsinFunLkt'
     *  DataTypeConversion: '<S88>/Data Type Conversion1'
     *  DataTypeConversion: '<S88>/Data Type Conversion2'
     *  Gain: '<S88>/Gain1'
     *  Merge: '<S79>/Merge'
     *  Product: '<S88>/Divide'
     *  Selector: '<S88>/Selector1'
     *  SignalConversion: '<S100>/Signal Conversion'
     *  Sum: '<S88>/Add'
     *  Switch: '<S90>/Switch2'
     */
    busPhVltgGen_MedTaskOut.u16_phiDaxQaxVltgAg =
        (dt_RadAng_u16r15b0)rtCP_lb_parAsinFunLkt_Value[(
            sint32)((2047U * ((uint16)(((sint16)((tmp << 14) /
                                                 ((sint16)rtb_Merge_kvzd))) +
                                       16384))) >>
                    14)];

    /* End of Outputs for SubSystem: '<S94>/ias_AngleShiftNotApplied' */
  } else {
    if (((dt_Standardize_s16p15b0)rtb_Merge_kvzd) >
        ((dt_Standardize_s16p15b0)(-((sint16)rtb_Merge_kvzd)))) {
      /* Switch: '<S90>/Switch1' incorporates:
       *  DataTypeConversion: '<S88>/Data Type Conversion'
       *  RelationalOperator: '<S90>/Relational Operator1'
       *  Saturate: '<S5>/Saturation1'
       *  Switch: '<S90>/Switch2'
       */
      if (rtb_Saturation1_cdwd <= ((dt_Standardize_s16p15b0)rtb_Merge_kvzd)) {
        /* Switch: '<S90>/Switch' incorporates:
         *  DataTypeConversion: '<S88>/Data Type Conversion3'
         *  Gain: '<S88>/Gain'
         *  RelationalOperator: '<S90>/Relational Operator'
         */
        if (rtb_Saturation1_cdwd >=
            ((dt_Standardize_s16p15b0)(-((sint16)rtb_Merge_kvzd)))) {
          tmp = rtb_Saturation1_cdwd;
        } else {
          tmp = (dt_Standardize_s16p15b0)(-((sint16)rtb_Merge_kvzd));
        }
      } else {
        tmp = (dt_Standardize_s16p15b0)rtb_Merge_kvzd;
      }
    } else {
      /* Switch: '<S90>/Switch2' incorporates:
       *  DataTypeConversion: '<S88>/Data Type Conversion'
       */
      tmp = (dt_Standardize_s16p15b0)rtb_Merge_kvzd;
    }

    /* Outputs for IfAction SubSystem: '<S94>/ias_AngleShiftApplied'
     * incorporates: ActionPort: '<S99>/Action Port'
     */
    /* If: '<S94>/If' incorporates:
     *  Constant: '<S88>/Constant'
     *  Constant: '<S88>/lb_parAsinFunLkt'
     *  Constant: '<S99>/Constant'
     *  DataTypeConversion: '<S88>/Data Type Conversion1'
     *  DataTypeConversion: '<S88>/Data Type Conversion2'
     *  Gain: '<S88>/Gain1'
     *  Merge: '<S79>/Merge'
     *  Product: '<S88>/Divide'
     *  Selector: '<S88>/Selector1'
     *  SignalConversion generated from: '<S99>/lb_arOutpPhs'
     *  Sum: '<S88>/Add'
     *  Sum: '<S99>/Add'
     *  Switch: '<S90>/Switch2'
     */
    busPhVltgGen_MedTaskOut.u16_phiDaxQaxVltgAg =
        (dt_RadAng_u16r15b0)(32768 -
                             ((uint16)rtCP_lb_parAsinFunLkt_Value[(
                                 sint32)((2047U *
                                          ((uint16)(((sint16)((tmp << 14) /
                                                              ((sint16)
                                                                   rtb_Merge_kvzd))) +
                                                    16384))) >>
                                         14)]));

    /* End of Outputs for SubSystem: '<S94>/ias_AngleShiftApplied' */

    /* End of Outputs for SubSystem: '<S79>/ias_NonZeroInput' */
  }

  /* End of If: '<S79>/If' */

  /* If: '<S162>/If' incorporates:
   *  Abs: '<S166>/Abs'
   *  Logic: '<S162>/AND'
   *  RelationalOperator: '<S164>/Compare'
   *  RelationalOperator: '<S165>/Compare'
   *  Sum: '<S160>/Add'
   *  Sum: '<S160>/Add1'
   */
  if ((rtb_Add_dots == 0) && (rtb_Add1_f4ha == 0)) {
    /* Outputs for IfAction SubSystem: '<S162>/ias_ZeroInput' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    /* BusCreator: '<S339>/Bus Creator1' incorporates:
     *  Constant: '<S167>/Constant'
     *  SignalConversion generated from: '<S167>/lb_genHypt'
     */
    busPhVltgGen_MedTaskOut.u16_psiEstPermMagFlx = 0U;

    /* End of Outputs for SubSystem: '<S162>/ias_ZeroInput' */
  } else {
    /* Outputs for IfAction SubSystem: '<S162>/ias_NonZeroInput' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    if (rtb_Add_dots < 0) {
      /* Abs: '<S166>/Abs' */
      rtb_Abs_atjh = (dt_Standardize_s16p15b0)(-rtb_Add_dots);
    } else {
      /* Abs: '<S166>/Abs' */
      rtb_Abs_atjh = rtb_Add_dots;
    }

    /* Abs: '<S166>/Abs1' */
    if (rtb_Add1_f4ha < 0) {
      rtb_Abs1_bbct = (dt_Standardize_s16p15b0)(-rtb_Add1_f4ha);
    } else {
      rtb_Abs1_bbct = rtb_Add1_f4ha;
    }

    /* End of Abs: '<S166>/Abs1' */

    /* MinMax: '<S166>/Min1' incorporates:
     *  Abs: '<S166>/Abs'
     *  Abs: '<S166>/Abs1'
     */
    if (rtb_Abs_atjh >= rtb_Abs1_bbct) {
      rtb_lb_genMaxInpMods = rtb_Abs_atjh;
    } else {
      rtb_lb_genMaxInpMods = rtb_Abs1_bbct;
    }

    /* End of MinMax: '<S166>/Min1' */

    /* Selector: '<S166>/Selector1' incorporates:
     *  Abs: '<S166>/Abs'
     *  Abs: '<S166>/Abs1'
     *  Gain: '<S166>/Gain'
     *  MinMax: '<S166>/Min'
     *  MinMax: '<S166>/Min1'
     *  Product: '<S166>/Divide2'
     *  Saturate: '<S166>/Saturation'
     */
    if (rtb_Abs_atjh <= rtb_Abs1_bbct) {
      tmp = rtb_Abs_atjh;
    } else {
      tmp = rtb_Abs1_bbct;
    }

    u0 =
        (uint16)((511U * ((uint16)((tmp << 15) / rtb_lb_genMaxInpMods))) >> 15);
    if (u0 <= 511) {
    } else {
      u0 = 511U;
    }

    /* BusCreator: '<S339>/Bus Creator1' incorporates:
     *  Constant: '<S166>/Constant3'
     *  MinMax: '<S166>/Min1'
     *  Product: '<S166>/Multiply'
     *  Saturate: '<S166>/Saturation'
     *  Selector: '<S166>/Selector1'
     *  SignalConversion generated from: '<S166>/lb_genHypt'
     */
    busPhVltgGen_MedTaskOut.u16_psiEstPermMagFlx =
        (dt_Standardize_u16p15b0)((rtCP_Constant3_Value_n3oq[u0] *
                                   rtb_lb_genMaxInpMods) >>
                                  15);

    /* End of Outputs for SubSystem: '<S162>/ias_NonZeroInput' */
  }

  /* End of If: '<S162>/If' */

  /* Sum: '<S1>/Add1' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  busPhVltgGen_MedTaskOut.u16_phiSenlElecAgSensElecAgDvt =
      (dt_RadAng_u16r15b0)(busPhVltgGen_MedTaskIn.u16_phiSensActElecAg -
                           ASW_PhVltgGen_DW.UnitDelay1_DSTATE_hljs);

  /* DataTypeConversion: '<S40>/Data Type Conversion1' incorporates:
   *  Sum: '<S49>/Add1'
   */
  busPhVltgGen_MedTaskOut.s16_phiOpnLpAgClsLpAgDvt =
      (dt_RadAng_s16r15b0)ASW_PhVltgGen_B.Add1;

  /* Sum: '<S41>/Add' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   *  Sum: '<S40>/Add2'
   */
  rtb_lb_inpDev =
      (sint16)(rtb_Add2 - busPhVltgGen_MedTaskIn.u16_phiModulActElecAg);

  /* Saturate: '<S41>/Saturation' incorporates:
   *  Sum: '<S41>/Add'
   */
  if (rtb_lb_inpDev > 5215) {
    tmp = 5215;
  } else if (rtb_lb_inpDev < -5215) {
    tmp = -5215;
  } else {
    tmp = rtb_lb_inpDev;
  }

  /* Saturate: '<S44>/Saturation' incorporates:
   *  Constant: '<S44>/Constant'
   */
  if (Gu16_fEstAgDvtCompFrq_C > 32000) {
    u0 = 32000U;
  } else if (Gu16_fEstAgDvtCompFrq_C < 1130) {
    u0 = 1130U;
  } else {
    u0 = Gu16_fEstAgDvtCompFrq_C;
  }

  /* Sum: '<S41>/Add1' incorporates:
   *  Gain: '<S41>/Gain'
   *  Product: '<S41>/mul_KdX_part1'
   *  Saturate: '<S41>/Saturation'
   *  Saturate: '<S44>/Saturation'
   *  Sum: '<S74>/Add1'
   */
  busPhVltgGen_MedTaskOut.s16_nPredActElecSpd =
      (dt_Standardize_s16p15b0)((((sint16)((((sint16)((tmp * u0) >> 13)) *
                                            3217) >>
                                           11)) >>
                                 2) +
                                rtb_Add1_afic);

  /* BusCreator: '<S339>/Bus Creator1' incorporates:
   *  Product: '<S365>/Product'
   *  Product: '<S365>/Product1'
   *  Product: '<S365>/Product2'
   *  Product: '<S365>/Product5'
   *  Saturate: '<S340>/Saturation3'
   *  Saturate: '<S340>/Saturation4'
   *  Selector: '<S360>/Selector1'
   *  Selector: '<S363>/Selector1'
   *  SignalConversion generated from: '<S339>/Bus Creator1'
   *  Sum: '<S365>/Add1'
   *  Sum: '<S365>/Add3'
   *  Sum: '<S74>/Add1'
   *  Switch: '<S345>/Switch1'
   */
  busPhVltgGen_MedTaskOut.u16_phiActElecAg = rtb_Switch1_d0v1;
  busPhVltgGen_MedTaskOut.s16_nActElecSpd = rtb_Add1_afic;
  busPhVltgGen_MedTaskOut.s16_iActDaxQaxCurr[0] =
      rtb_TmpSignalConversionAtBusC_1;
  busPhVltgGen_MedTaskOut.s16_iActDaxQaxCurr[1] =
      rtb_TmpSignalConversionAtBusC_0;
  busPhVltgGen_MedTaskOut.s16_uModulDaxQaxVltg[0] =
      (dt_Standardize_s16p15b0)(((sint16)((rtb_Saturation3_pseh *
                                           rtb_Selector1_prdr) >>
                                          14)) +
                                ((sint16)((rtb_Saturation4_ectf *
                                           rtb_Selector1_blvz) >>
                                          14)));
  busPhVltgGen_MedTaskOut.s16_uModulDaxQaxVltg[1] =
      (dt_Standardize_s16p15b0)(((sint16)((rtb_Saturation4_ectf *
                                           rtb_Selector1_prdr) >>
                                          14)) -
                                ((sint16)((rtb_Saturation3_pseh *
                                           rtb_Selector1_blvz) >>
                                          14)));

  /* Saturate: '<S111>/Saturation4' incorporates:
   *  Sum: '<S74>/Add1'
   */
  if (rtb_Add1_afic >= -32767) {
    rtb_Saturation4_c3u0 = rtb_Add1_afic;
  } else {
    rtb_Saturation4_c3u0 = -32767;
  }

  /* End of Saturate: '<S111>/Saturation4' */

  /* Switch: '<S133>/Switch1' incorporates:
   *  Constant: '<S133>/Constant'
   *  DataTypeConversion: '<S141>/Data Type Conversion2'
   *  Gain: '<S112>/Gain5'
   *  Product: '<S133>/Product1'
   */
  if (tmp_0) {
    tmp = (sint16)(((rtb_DataTypeConversion2_hco0 >> 1) * 16777) >> 14);
  } else {
    tmp = 0;
  }

  /* Switch: '<S138>/Switch1' incorporates:
   *  Constant: '<S138>/Constant1'
   *  UnitDelay: '<S138>/Unit Delay1'
   */
  if (ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_ktzd) {
    tmp_0 = rtb_LogicalOperator_lnae;
  } else {
    tmp_0 = true;
  }

  /* Switch: '<S138>/Switch' incorporates:
   *  Constant: '<S112>/Cu16_tiMedTaskSmpTi1'
   *  Switch: '<S138>/Switch1'
   *  UnitDelay: '<S138>/Unit Delay'
   */
  if (tmp_0) {
    u0 = 0U;
  } else {
    u0 = ASW_PhVltgGen_DW.UnitDelay_DSTATE_naon;
  }

  /* Sum: '<S133>/Sum' incorporates:
   *  Switch: '<S133>/Switch1'
   *  Switch: '<S138>/Switch'
   */
  rtb_Sum_new3 = (uint16)(((tmp * 20861) + (u0 << 14)) >> 14);

  /* Update for UnitDelay: '<S371>/Unit Delay' incorporates:
   *  Switch: '<S345>/Switch1'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_l32u = rtb_Switch1_d0v1;

  /* Update for UnitDelay: '<S382>/Unit Delay1' incorporates:
   *  Constant: '<S382>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_haua = true;

  /* Update for UnitDelay: '<S382>/Unit Delay' incorporates:
   *  Sum: '<S377>/Sum'
   *  Switch: '<S377>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_hdmg = rtb_Sum_e45u;

  /* Update for UnitDelay: '<S112>/Unit Delay1' incorporates:
   *  Sum: '<S133>/Sum'
   *  Switch: '<S133>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay1_DSTATE_hljs = rtb_Sum_new3;

  /* Update for UnitDelay: '<S42>/Unit Delay1' incorporates:
   *  Sum: '<S74>/Add1'
   */
  ASW_PhVltgGen_DW.UnitDelay1_DSTATE = rtb_Add1_afic;

  /* Update for UnitDelay: '<S40>/Unit Delay1' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  ASW_PhVltgGen_DW.UnitDelay1_DSTATE_hxga = busPhVltgGen_MedTaskIn.enm_stMotoSt;

  /* Update for UnitDelay: '<S58>/Unit Delay1' incorporates:
   *  Constant: '<S58>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_d5fg = true;

  /* Update for UnitDelay: '<S58>/Unit Delay' incorporates:
   *  Switch: '<S53>/Switch'
   *  Switch: '<S57>/Switch2'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_j4ol = rtb_Switch2_aaxv;

  /* Saturate: '<S2>/Saturation3' incorporates:
   *  Sum: '<S74>/Add1'
   */
  if (rtb_Add1_afic >= -32767) {
    /* Update for UnitDelay: '<S2>/Unit Delay' */
    ASW_PhVltgGen_DW.UnitDelay_DSTATE_pwry = rtb_Add1_afic;
  } else {
    /* Update for UnitDelay: '<S2>/Unit Delay' */
    ASW_PhVltgGen_DW.UnitDelay_DSTATE_pwry = -32767;
  }

  /* End of Saturate: '<S2>/Saturation3' */

  /* Update for UnitDelay: '<S274>/Unit Delay' incorporates:
   *  Inport: '<Root>/busPhVltgGen_MedTaskIn'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_beui =
      busPhVltgGen_MedTaskIn.u16_phiSensActElecAg;

  /* Abs: '<S112>/Abs' incorporates:
   *  Saturate: '<S111>/Saturation4'
   */
  if (rtb_Saturation4_c3u0 < 0) {
    /* Update for UnitDelay: '<S112>/Unit Delay2' */
    ASW_PhVltgGen_DW.UnitDelay2_DSTATE =
        (dt_Standardize_s16p15b0)(-rtb_Saturation4_c3u0);
  } else {
    /* Update for UnitDelay: '<S112>/Unit Delay2' */
    ASW_PhVltgGen_DW.UnitDelay2_DSTATE = rtb_Saturation4_c3u0;
  }

  /* End of Abs: '<S112>/Abs' */

  /* Update for UnitDelay: '<S194>/Unit Delay2' incorporates:
   *  Sum: '<S207>/Sum'
   *  Switch: '<S207>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay2_DSTATE_iu0k = rtb_Sum_icq1;

  /* Update for UnitDelay: '<S194>/Unit Delay3' incorporates:
   *  Sum: '<S214>/Sum'
   *  Switch: '<S214>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay3_DSTATE = rtb_Sum_d2gz;

  /* Update for UnitDelay: '<S194>/Unit Delay4' incorporates:
   *  Sum: '<S226>/Add3'
   */
  ASW_PhVltgGen_DW.UnitDelay4_DSTATE = rtb_Add3_cxwa;

  /* Update for UnitDelay: '<S212>/Unit Delay1' incorporates:
   *  Constant: '<S212>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_ekpq = true;

  /* Update for UnitDelay: '<S212>/Unit Delay' incorporates:
   *  Sum: '<S207>/Sum'
   *  Switch: '<S207>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_brib = rtb_Sum_icq1;

  /* Update for UnitDelay: '<S221>/Unit Delay' incorporates:
   *  Sum: '<S221>/Add1'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_jl24 = rtb_Add1_k5op;

  /* Update for UnitDelay: '<S194>/Unit Delay5' incorporates:
   *  Sum: '<S221>/Add3'
   */
  ASW_PhVltgGen_DW.UnitDelay5_DSTATE = rtb_Add3;

  /* Update for UnitDelay: '<S219>/Unit Delay1' incorporates:
   *  Constant: '<S219>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_a3qb = true;

  /* Update for UnitDelay: '<S219>/Unit Delay' incorporates:
   *  Sum: '<S214>/Sum'
   *  Switch: '<S214>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_bhpf = rtb_Sum_d2gz;

  /* Update for UnitDelay: '<S226>/Unit Delay' incorporates:
   *  Sum: '<S226>/Add1'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_jgqd = rtb_Add1_btax;

  /* Update for UnitDelay: '<S112>/Unit Delay' incorporates:
   *  Saturate: '<S111>/Saturation4'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_bg1i = rtb_Saturation4_c3u0;

  /* Update for UnitDelay: '<S195>/Unit Delay2' incorporates:
   *  Sum: '<S241>/Sum'
   *  Switch: '<S241>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay2_DSTATE_fpsd = rtb_Sum_juht;

  /* Update for UnitDelay: '<S195>/Unit Delay3' incorporates:
   *  Sum: '<S248>/Sum'
   *  Switch: '<S248>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay3_DSTATE_a0k1 = rtb_Sum_g2hx;

  /* Update for UnitDelay: '<S195>/Unit Delay4' incorporates:
   *  Sum: '<S260>/Add3'
   */
  ASW_PhVltgGen_DW.UnitDelay4_DSTATE_jlzn = rtb_Add3_by2i;

  /* Update for UnitDelay: '<S246>/Unit Delay1' incorporates:
   *  Constant: '<S246>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_mq3y = true;

  /* Update for UnitDelay: '<S246>/Unit Delay' incorporates:
   *  Sum: '<S241>/Sum'
   *  Switch: '<S241>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_jfag = rtb_Sum_juht;

  /* Update for UnitDelay: '<S255>/Unit Delay' incorporates:
   *  Sum: '<S255>/Add1'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_h5zb = rtb_Add1_mzgk;

  /* Update for UnitDelay: '<S195>/Unit Delay5' incorporates:
   *  Sum: '<S255>/Add3'
   */
  ASW_PhVltgGen_DW.UnitDelay5_DSTATE_dj41 = rtb_Add3_chim;

  /* Update for UnitDelay: '<S253>/Unit Delay1' incorporates:
   *  Constant: '<S253>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_ljbs = true;

  /* Update for UnitDelay: '<S253>/Unit Delay' incorporates:
   *  Sum: '<S248>/Sum'
   *  Switch: '<S248>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_aybk = rtb_Sum_g2hx;

  /* Update for UnitDelay: '<S260>/Unit Delay' incorporates:
   *  Sum: '<S260>/Add1'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_bffe = rtb_Add1_bfl0;

  /* Update for UnitDelay: '<S141>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S141>/Data Type Conversion2'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_mo0h = rtb_DataTypeConversion2_hco0;

  /* Update for UnitDelay: '<S141>/Unit Delay1' incorporates:
   *  Sum: '<S141>/Add2'
   */
  ASW_PhVltgGen_DW.UnitDelay1_DSTATE_fzlc = rtb_Add2_bakf;

  /* Update for UnitDelay: '<S155>/Unit Delay1' incorporates:
   *  Constant: '<S155>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_kcff = true;

  /* Update for UnitDelay: '<S155>/Unit Delay' incorporates:
   *  Sum: '<S149>/Sum'
   *  Switch: '<S149>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE = rtb_Sum;

  /* Update for UnitDelay: '<S74>/Unit Delay' incorporates:
   *  Sum: '<S74>/Add1'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_fiwk = rtb_Add1_afic;

  /* Update for UnitDelay: '<S293>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S293>/Data Type Conversion2'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_p44p = rtb_DataTypeConversion2_gwbl;

  /* Update for UnitDelay: '<S293>/Unit Delay1' incorporates:
   *  Sum: '<S293>/Add2'
   */
  ASW_PhVltgGen_DW.UnitDelay1_DSTATE_gk3t = rtb_Add2_aalz;

  /* Update for UnitDelay: '<S307>/Unit Delay1' incorporates:
   *  Constant: '<S307>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_la0o = true;

  /* Update for UnitDelay: '<S307>/Unit Delay' incorporates:
   *  Sum: '<S301>/Sum'
   *  Switch: '<S301>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_kt4g = rtb_Sum_g421;

  /* Saturate: '<S6>/Saturation' incorporates:
   *  DataTypeConversion: '<S293>/Data Type Conversion2'
   */
  if (rtb_DataTypeConversion2_gwbl >= -32767) {
    /* Update for UnitDelay: '<S6>/Unit Delay' */
    ASW_PhVltgGen_DW.UnitDelay_DSTATE_ksxz = rtb_DataTypeConversion2_gwbl;
  } else {
    /* Update for UnitDelay: '<S6>/Unit Delay' */
    ASW_PhVltgGen_DW.UnitDelay_DSTATE_ksxz = -32767;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Update for UnitDelay: '<S320>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S320>/Data Type Conversion2'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_gvry = rtb_DataTypeConversion2_o3w2;

  /* Update for UnitDelay: '<S320>/Unit Delay1' incorporates:
   *  Sum: '<S320>/Add2'
   */
  ASW_PhVltgGen_DW.UnitDelay1_DSTATE_mewr = rtb_Add2_doeq;

  /* Update for UnitDelay: '<S334>/Unit Delay1' incorporates:
   *  Constant: '<S334>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_l4aj = true;

  /* Update for UnitDelay: '<S334>/Unit Delay' incorporates:
   *  Sum: '<S328>/Sum'
   *  Switch: '<S328>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_afgq = rtb_Sum_krjk;

  /* Update for UnitDelay: '<S138>/Unit Delay1' incorporates:
   *  Constant: '<S138>/Constant'
   */
  ASW_PhVltgGen_DW.bitsForTID1.UnitDelay1_DSTATE_ktzd = true;

  /* Update for UnitDelay: '<S138>/Unit Delay' incorporates:
   *  Sum: '<S133>/Sum'
   *  Switch: '<S133>/Switch'
   */
  ASW_PhVltgGen_DW.UnitDelay_DSTATE_naon = rtb_Sum_new3;
}

/* Model step function */
void ASW_PhVltgGen_step(void) {
  if (ASW_PhVltgGen_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/PhVltgGen_MedTask' */
    PhVltgGen_MedTask();

    /* End of Outputs for SubSystem: '<Root>/PhVltgGen_MedTask' */
  }

  rate_scheduler();
}

/* Model initialize function */
void ASW_PhVltgGen_Init(void) {
  /* Registration code */

  /* initialize real-time model */
  (void)memset((void *)ASW_PhVltgGen_M, 0, sizeof(RT_MODEL_ASW_PhVltgGen));

  /* block I/O */
  (void)memset(((void *)&ASW_PhVltgGen_B), 0, sizeof(B_ASW_PhVltgGen));

  /* exported global signals */
  busPhVltgGen_MedTaskOut = ASW_PhVltgGen_rtZBUS_PHVLTGGEN_MED_TASK_OUT;

  /* states (dwork) */
  (void)memset((void *)&ASW_PhVltgGen_DW, 0, sizeof(DW_ASW_PhVltgGen));

  /* external inputs */
  busPhVltgGen_MedTaskIn = ASW_PhVltgGen_rtZBUS_PHVLTGGEN_;

  /* SystemInitialize for Atomic SubSystem: '<Root>/PhVltgGen_MedTask' */
  PhVltgGen_MedTask_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/PhVltgGen_MedTask' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
