/*
 * File: ASW_PhCurrGen.c
 *
 * Code generated for Simulink model 'ASW_PhCurrGen'.
 *
 * Model version                  : 6.181
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Mar 25 10:39:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ASW_PhCurrGen.h"
#include "../ASW_par/motor_control_param.h"
#include "../ASW_par/motor_param.h"
#include "../ASW_share/custom_type_definition.h"
#include "../ASW_share/motor_control_interface.h"
#include "../ASW_share/mul_ssu32_hiSR.h"
#include "../ASW_share/mul_ssu32_loSR.h"
#include "../ASW_share/rtwtypes.h"
#include "ASW_PhCurrGen_private.h"
#include <string.h>

/* Named constants for Chart: '<S53>/sfc_MotoSTMHybr' */
#define IN_CLOSED_LOOP ((uint8)1U)
#define IN_NO_ACTIVE_CHILD ((uint8)0U)
#define IN_OFF ((uint8)2U)
#define IN_OPEN_LOOP ((uint8)3U)

/* Named constants for Chart: '<S63>/sfc_TrqDecre' */
#define IN_TRQ_CST ((uint8)1U)
#define IN_TRQ_DECRE ((uint8)2U)

const BUS_PHCURRGEN_SLW_TASK_OUT ASW_PhCurrGen_rtZBUS_PHCURRGEN_SLW_TASK_OUT = {
    {0, 0}, /* s16_iRefDaxQaxCurr */
    OFF     /* enm_stMotoSt */
};          /* BUS_PHCURRGEN_SLW_TASK_OUT ground */

/* Exported block signals */
BUS_PHCURRGEN_SLW_TASK_IN
    busPhCurrGen_SlwTaskIn; /* '<Root>/busPhCurrGen_SlwTaskIn' */
BUS_PHCURRGEN_SLW_TASK_OUT busPhCurrGen_SlwTaskOut; /* '<S56>/Bus Creator1' */

/* Block signals (default storage) */
B_ASW_PhCurrGen ASW_PhCurrGen_B;

/* Block states (default storage) */
DW_ASW_PhCurrGen ASW_PhCurrGen_DW;

/* Real-time model */
static RT_MODEL_ASW_PhCurrGen ASW_PhCurrGen_M_;
RT_MODEL_ASW_PhCurrGen *const ASW_PhCurrGen_M = &ASW_PhCurrGen_M_;
static void rate_scheduler(void);
const BUS_PHCURRGEN_SLW_TASK_IN ASW_PhCurrGen_rtZBUS_PHCURRGEN_ = {
    0,     /* s16_nRefElecSpd */
    0,     /* s16_nActElecSpd */
    0,     /* s16_nRmpRefElecSpd */
    0,     /* s16_trqRefTqLim */
    false, /* bol_flgShOffFlg */
    false, /* bol_enPosSCDCalibEnFlg */
    0,     /* s16_trqPosSCDCalibRefTq */
    0U,    /* enm_modeAgEvalMode */
    0      /* s16_phiOpnLpAgClsLpAgDvt */
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
  (ASW_PhCurrGen_M->Timing.TaskCounters.TID[1])++;
  if ((ASW_PhCurrGen_M->Timing.TaskCounters.TID[1]) >
      79) { /* Sample time: [0.01s, 0.0s] */
    ASW_PhCurrGen_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for atomic system: '<Root>/PhCurrGen_SlwTask' */
void PhCurrGen_SlwTask_Init(void) {
  sint32 i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S61>/Tapped Delay' */
  for (i = 0; i < 19; i++) {
    ASW_PhCurrGen_DW.TappedDelay_DWORK1[i] = 0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S61>/Tapped
   * Delay' */

  /* SystemInitialize for Chart: '<S53>/sfc_MotoSTMHybr' */
  ASW_PhCurrGen_DW.is_active_c1_ASW_PhCurrGen = 0U;
  ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S63>/sfc_TrqDecre' */
  ASW_PhCurrGen_DW.is_active_c2_ASW_PhCurrGen = 0U;
  ASW_PhCurrGen_DW.is_c2_ASW_PhCurrGen = IN_NO_ACTIVE_CHILD;
}

/* Output and update for atomic system: '<Root>/PhCurrGen_SlwTask' */
void PhCurrGen_SlwTask(void) {
  sint32 i;
  sint32 i_0;
  sint32 rtb_DataTypeConversion;
  sint32 rtb_DataTypeConversion1;
  sint32 rtb_Sum;
  sint32 rtb_Switch;
  sint32 rtb_Switch1;
  sint32 rtb_Switch2;
  sint32 rtb_lb_propActn;
  dt_SpdCtrlPropGain_u16p12b0 tmp;
  dt_Standardize_s16p15b0 rtb_VectorConcatenate[20];
  dt_Standardize_s16p15b0 rtb_Add1;
  dt_Standardize_s16p15b0 rtb_Add1_gfx5;
  dt_Standardize_s16p15b0 rtb_Add_hfyp;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_hrkx;
  dt_Standardize_s16p15b0 rtb_DataTypeConversion2_nzfu;
  dt_Standardize_s16p15b0 rtb_Divide;
  dt_Standardize_s16p15b0 rtb_Merge2;
  dt_Standardize_s16p15b0 rtb_Saturation1_dbnw;
  dt_Standardize_s16p15b0 rtb_Saturation1_phnk;
  dt_Standardize_s16p15b0 rtb_Saturation2;
  dt_Standardize_s16p15b0 rtb_Saturation3;
  dt_Standardize_s16p15b0 rtb_Saturation4;
  dt_Standardize_s16p15b0 rtb_Switch1_iv22;
  dt_Standardize_s16p15b0 rtb_Switch_ijfv;
  dt_Standardize_s16p15b0 rtb_Switch_kmfj;
  dt_Standardize_s16p15b0 rtb_VectorConcatenate_0;
  dt_Standardize_u16p15b0 rtb_Gain2;
  dt_Standardize_u16p15b0 rtb_Saturation1;
  sint16 maxV;
  sint16 rtb_Add2;
  sint16 rtb_DataTypeConversion1_bu1w;
  sint16 rtb_DataTypeConversion_c14a;
  sint16 rtb_Divide2;
  sint16 rtb_Sum_mxox;
  sint16 rtb_Switch2_m2rf;
  sint16 tmp_0;
  sint16 tmp_1;
  sint16 tmp_2;
  ENM_MOTO_STATUS rtb_enm_stMotoSt;
  ENM_STRTUP_TRQ_STATUS rtb_enm_stStrtupTrqSt;
  uint8 tmp_3;
  boolean guard1;
  boolean guard2;
  boolean guard3;
  boolean guard4;
  boolean guard5;
  boolean out;
  boolean rtb_Compare_oo4d;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_jkyj;
  boolean rtb_LogicalOperator_lo00;
  boolean rtb_lb_incrRatLimReq;
  boolean rtb_lb_noRatLimReq;

  /* Saturate: '<S18>/Saturation4' incorporates:
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   */
  if (busPhCurrGen_SlwTaskIn.s16_trqRefTqLim >= -32767) {
    rtb_Saturation4 = busPhCurrGen_SlwTaskIn.s16_trqRefTqLim;
  } else {
    rtb_Saturation4 = -32767;
  }

  /* End of Saturate: '<S18>/Saturation4' */

  /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
   *  Saturate: '<S18>/Saturation4'
   */
  rtb_DataTypeConversion_c14a = (sint16)(rtb_Saturation4 >> 1);

  /* Saturate: '<S53>/Saturation2' incorporates:
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   */
  if (busPhCurrGen_SlwTaskIn.s16_nRefElecSpd >= -32767) {
    rtb_Saturation2 = busPhCurrGen_SlwTaskIn.s16_nRefElecSpd;
  } else {
    rtb_Saturation2 = -32767;
  }

  /* End of Saturate: '<S53>/Saturation2' */

  /* Saturate: '<S53>/Saturation1' incorporates:
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   */
  if (busPhCurrGen_SlwTaskIn.s16_nActElecSpd >= -32767) {
    rtb_Saturation1_phnk = busPhCurrGen_SlwTaskIn.s16_nActElecSpd;
  } else {
    rtb_Saturation1_phnk = -32767;
  }

  /* End of Saturate: '<S53>/Saturation1' */

  /* Saturate: '<S53>/Saturation3' incorporates:
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   */
  if (busPhCurrGen_SlwTaskIn.s16_nRmpRefElecSpd >= -32767) {
    rtb_Saturation3 = busPhCurrGen_SlwTaskIn.s16_nRmpRefElecSpd;
  } else {
    rtb_Saturation3 = -32767;
  }

  /* End of Saturate: '<S53>/Saturation3' */

  /* Chart: '<S53>/sfc_MotoSTMHybr' incorporates:
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   *  Saturate: '<S53>/Saturation1'
   *  Saturate: '<S53>/Saturation2'
   *  Saturate: '<S53>/Saturation3'
   *  UnitDelay: '<S53>/Unit Delay1'
   *  UnitDelay: '<S53>/Unit Delay19'
   */
  /* Gateway: PhCurrGen_SlwTask/vrs_MotoSTM/rss_MotoSTMHybr/sfc_MotoSTMHybr */
  /* During: PhCurrGen_SlwTask/vrs_MotoSTM/rss_MotoSTMHybr/sfc_MotoSTMHybr */
  if (ASW_PhCurrGen_DW.is_active_c1_ASW_PhCurrGen == 0U) {
    /* Entry: PhCurrGen_SlwTask/vrs_MotoSTM/rss_MotoSTMHybr/sfc_MotoSTMHybr */
    ASW_PhCurrGen_DW.is_active_c1_ASW_PhCurrGen = 1U;

    /* Entry Internal:
     * PhCurrGen_SlwTask/vrs_MotoSTM/rss_MotoSTMHybr/sfc_MotoSTMHybr */
    /* Transition: '<S54>:2' */
    ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_OFF;

    /* Entry 'OFF': '<S54>:1' */
    rtb_enm_stMotoSt = OFF;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen) {
    case IN_CLOSED_LOOP:
      rtb_enm_stMotoSt = CLOSED_LOOP;

      /* During 'CLOSED_LOOP': '<S54>:4' */
      if (rtb_Saturation2 == 0) {
        if (rtb_Saturation1_phnk < 0) {
          i_0 = -rtb_Saturation1_phnk;
          if ((-rtb_Saturation1_phnk) > 32767) {
            i_0 = 32767;
          }

          maxV = (sint16)i_0;
        } else {
          maxV = rtb_Saturation1_phnk;
        }

        if (Gs16_nShOffActElecSpd_C < 0) {
          i_0 = -Gs16_nShOffActElecSpd_C;
          if ((-Gs16_nShOffActElecSpd_C) > 32767) {
            i_0 = 32767;
          }

          rtb_VectorConcatenate_0 = (sint16)i_0;
        } else {
          rtb_VectorConcatenate_0 = Gs16_nShOffActElecSpd_C;
        }

        if ((maxV < rtb_VectorConcatenate_0) &&
            (!busPhCurrGen_SlwTaskIn.bol_enPosSCDCalibEnFlg)) {
          guard3 = true;
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }
      break;

    case IN_OFF:
      rtb_enm_stMotoSt = OFF;

      /* During 'OFF': '<S54>:1' */
      if (rtb_Saturation2 < 0) {
        i_0 = -rtb_Saturation2;
        if ((-rtb_Saturation2) > 32767) {
          i_0 = 32767;
        }

        maxV = (sint16)i_0;
      } else {
        maxV = rtb_Saturation2;
      }

      if (((maxV > 0) || (busPhCurrGen_SlwTaskIn.bol_enPosSCDCalibEnFlg)) &&
          (!busPhCurrGen_SlwTaskIn.bol_flgShOffFlg)) {
        /* Transition: '<S54>:9' */
        /* Transition: '<S54>:125' */
        if (busPhCurrGen_SlwTaskIn.enm_modeAgEvalMode != SENSORLESS) {
          /* Transition: '<S54>:121' */
          ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_CLOSED_LOOP;

          /* Entry 'CLOSED_LOOP': '<S54>:4' */
          rtb_enm_stMotoSt = CLOSED_LOOP;
        } else {
          /* Transition: '<S54>:110' */
          ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_OPEN_LOOP;

          /* Entry 'OPEN_LOOP': '<S54>:3' */
          rtb_enm_stMotoSt = OPEN_LOOP;
        }
      }
      break;

    default:
      rtb_enm_stMotoSt = OPEN_LOOP;

      /* During 'OPEN_LOOP': '<S54>:3' */
      if (ASW_PhCurrGen_DW.UnitDelay19_DSTATE == TRQ_DECRE) {
        /* Abs: '<S53>/Abs' incorporates:
         *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
         */
        if (busPhCurrGen_SlwTaskIn.s16_phiOpnLpAgClsLpAgDvt < 0) {
          maxV = (sint16)(-busPhCurrGen_SlwTaskIn.s16_phiOpnLpAgClsLpAgDvt);
        } else {
          maxV = busPhCurrGen_SlwTaskIn.s16_phiOpnLpAgClsLpAgDvt;
        }

        /* End of Abs: '<S53>/Abs' */
        if (((uint16)maxV) <= Gu16_phiMinOpnLpClsLpAgDvt_C) {
          guard2 = true;
        } else {
          if (ASW_PhCurrGen_DW.UnitDelay1_DSTATE < 0) {
            i_0 = -ASW_PhCurrGen_DW.UnitDelay1_DSTATE;
            if ((-ASW_PhCurrGen_DW.UnitDelay1_DSTATE) > 32767) {
              i_0 = 32767;
            }

            maxV = (sint16)i_0;
          } else {
            maxV = ASW_PhCurrGen_DW.UnitDelay1_DSTATE;
          }

          if (Gs16_trqMinStrtUpRefTq_C < 0) {
            i_0 = -Gs16_trqMinStrtUpRefTq_C;
            if ((-Gs16_trqMinStrtUpRefTq_C) > 32767) {
              i_0 = 32767;
            }

            rtb_VectorConcatenate_0 = (sint16)i_0;
          } else {
            rtb_VectorConcatenate_0 = Gs16_trqMinStrtUpRefTq_C;
          }

          if (maxV <= rtb_VectorConcatenate_0) {
            guard2 = true;
          } else {
            guard1 = true;
          }
        }
      } else {
        guard1 = true;
      }
      break;
    }

    if (guard4) {
      if (busPhCurrGen_SlwTaskIn.bol_flgShOffFlg) {
        guard3 = true;
      } else if (rtb_Saturation2 != 0) {
        if (rtb_Saturation3 < 0) {
          i_0 = -rtb_Saturation3;
          if ((-rtb_Saturation3) > 32767) {
            i_0 = 32767;
          }

          maxV = (sint16)i_0;
        } else {
          maxV = rtb_Saturation3;
        }

        if (Gs16_nMinSenlRefElecSpd_C < 0) {
          i_0 = -Gs16_nMinSenlRefElecSpd_C;
          if ((-Gs16_nMinSenlRefElecSpd_C) > 32767) {
            i_0 = 32767;
          }

          rtb_VectorConcatenate_0 = (sint16)i_0;
        } else {
          rtb_VectorConcatenate_0 = Gs16_nMinSenlRefElecSpd_C;
        }

        if (maxV < rtb_VectorConcatenate_0) {
          if (rtb_Saturation1_phnk < 0) {
            i_0 = -rtb_Saturation1_phnk;
            if ((-rtb_Saturation1_phnk) > 32767) {
              i_0 = 32767;
            }

            maxV = (sint16)i_0;
          } else {
            maxV = rtb_Saturation1_phnk;
          }

          if (Gs16_nOpnLpConvActElecSpd_C < 0) {
            i_0 = -Gs16_nOpnLpConvActElecSpd_C;
            if ((-Gs16_nOpnLpConvActElecSpd_C) > 32767) {
              i_0 = 32767;
            }

            rtb_VectorConcatenate_0 = (sint16)i_0;
          } else {
            rtb_VectorConcatenate_0 = Gs16_nOpnLpConvActElecSpd_C;
          }

          if ((maxV < rtb_VectorConcatenate_0) &&
              (busPhCurrGen_SlwTaskIn.enm_modeAgEvalMode == SENSORLESS)) {
            /* Transition: '<S54>:32' */
            ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_OPEN_LOOP;

            /* Entry 'OPEN_LOOP': '<S54>:3' */
            rtb_enm_stMotoSt = OPEN_LOOP;
          }
        }
      }
    }

    if (guard3) {
      /* Transition: '<S54>:16' */
      /* Transition: '<S54>:15' */
      ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_OFF;

      /* Entry 'OFF': '<S54>:1' */
      rtb_enm_stMotoSt = OFF;
    }

    if (guard2) {
      /* Transition: '<S54>:28' */
      ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_CLOSED_LOOP;

      /* Entry 'CLOSED_LOOP': '<S54>:4' */
      rtb_enm_stMotoSt = CLOSED_LOOP;
    }

    if (guard1) {
      out = false;
      guard5 = false;
      if (rtb_Saturation2 == 0) {
        if (rtb_Saturation1_phnk < 0) {
          i_0 = -rtb_Saturation1_phnk;
          if ((-rtb_Saturation1_phnk) > 32767) {
            i_0 = 32767;
          }

          maxV = (sint16)i_0;
        } else {
          maxV = rtb_Saturation1_phnk;
        }

        if (Gs16_nShOffActElecSpd_C < 0) {
          i_0 = -Gs16_nShOffActElecSpd_C;
          if ((-Gs16_nShOffActElecSpd_C) > 32767) {
            i_0 = 32767;
          }

          rtb_VectorConcatenate_0 = (sint16)i_0;
        } else {
          rtb_VectorConcatenate_0 = Gs16_nShOffActElecSpd_C;
        }

        if ((maxV < rtb_VectorConcatenate_0) &&
            (!busPhCurrGen_SlwTaskIn.bol_enPosSCDCalibEnFlg)) {
          out = true;
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }

      if (guard5) {
        if (busPhCurrGen_SlwTaskIn.bol_flgShOffFlg) {
          out = true;
        }
      }

      if (out) {
        /* Transition: '<S54>:111' */
        ASW_PhCurrGen_DW.is_c1_ASW_PhCurrGen = IN_OFF;

        /* Entry 'OFF': '<S54>:1' */
        rtb_enm_stMotoSt = OFF;
      }
    }
  }

  /* End of Chart: '<S53>/sfc_MotoSTMHybr' */

  /* Logic: '<S18>/Logical Operator' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   *  RelationalOperator: '<S19>/Compare'
   */
  rtb_LogicalOperator = ((rtb_enm_stMotoSt != CLOSED_LOOP) ||
                         (busPhCurrGen_SlwTaskIn.bol_enPosSCDCalibEnFlg));

  /* DataTypeConversion: '<S36>/Data Type Conversion' incorporates:
   *  Saturate: '<S18>/Saturation4'
   */
  rtb_DataTypeConversion = (rtb_Saturation4 << 12);

  /* DataTypeConversion: '<S36>/Data Type Conversion1' incorporates:
   *  Gain: '<S18>/Gain1'
   *  Saturate: '<S18>/Saturation4'
   */
  rtb_DataTypeConversion1 =
      (((dt_Standardize_s16p15b0)(-rtb_Saturation4)) << 12);

  /* Switch: '<S47>/Switch2' incorporates:
   *  DataTypeConversion: '<S36>/Data Type Conversion'
   *  DataTypeConversion: '<S36>/Data Type Conversion1'
   *  RelationalOperator: '<S47>/Relational Operator2'
   */
  if (rtb_DataTypeConversion > rtb_DataTypeConversion1) {
    /* Saturate: '<S25>/Saturation' incorporates:
     *  Constant: '<S25>/Constant'
     */
    if (Gu16_facSpdCtlKp_C <= 32768) {
      tmp = Gu16_facSpdCtlKp_C;
    } else {
      tmp = 32768U;
    }

    /* Saturate: '<S18>/Saturation1' incorporates:
     *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
     */
    if (busPhCurrGen_SlwTaskIn.s16_nRmpRefElecSpd >= -32767) {
      maxV = busPhCurrGen_SlwTaskIn.s16_nRmpRefElecSpd;
    } else {
      maxV = -32767;
    }

    /* Saturate: '<S18>/Saturation2' incorporates:
     *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
     */
    if (busPhCurrGen_SlwTaskIn.s16_nActElecSpd >= -32767) {
      rtb_VectorConcatenate_0 = busPhCurrGen_SlwTaskIn.s16_nActElecSpd;
    } else {
      rtb_VectorConcatenate_0 = -32767;
    }

    /* Product: '<S36>/Product' incorporates:
     *  Saturate: '<S18>/Saturation1'
     *  Saturate: '<S18>/Saturation2'
     *  Saturate: '<S25>/Saturation'
     *  Sum: '<S22>/Add1'
     */
    rtb_lb_propActn = ((tmp * ((maxV - rtb_VectorConcatenate_0) >> 1)) << 1);

    /* Switch: '<S47>/Switch1' incorporates:
     *  Product: '<S36>/Product'
     *  RelationalOperator: '<S47>/Relational Operator1'
     */
    if (rtb_lb_propActn <= rtb_DataTypeConversion) {
      /* Switch: '<S47>/Switch' incorporates:
       *  RelationalOperator: '<S47>/Relational Operator'
       */
      if (rtb_lb_propActn >= rtb_DataTypeConversion1) {
        /* Switch: '<S47>/Switch2' */
        rtb_Switch2 = rtb_lb_propActn;
      } else {
        /* Switch: '<S47>/Switch2' */
        rtb_Switch2 = rtb_DataTypeConversion1;
      }

      /* End of Switch: '<S47>/Switch' */
    } else {
      /* Switch: '<S47>/Switch2' */
      rtb_Switch2 = rtb_DataTypeConversion;
    }

    /* End of Switch: '<S47>/Switch1' */
  } else {
    rtb_Switch2 = rtb_DataTypeConversion;
  }

  /* End of Switch: '<S47>/Switch2' */

  /* DataTypeConversion: '<S36>/Data Type Conversion2' incorporates:
   *  Switch: '<S47>/Switch2'
   */
  rtb_DataTypeConversion2_hrkx = (dt_Standardize_s16p15b0)(rtb_Switch2 >> 12);

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S30>/Constant4'
   *  DataTypeConversion: '<S36>/Data Type Conversion2'
   *  Sum: '<S36>/Add'
   */
  if (rtb_LogicalOperator) {
    rtb_Switch1_iv22 = 0;

    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S30>/Constant4'
     *  Constant: '<S38>/Constant'
     *  Switch: '<S36>/Switch1'
     */
    rtb_Switch1 = 0;
  } else {
    rtb_Switch1_iv22 = rtb_DataTypeConversion2_hrkx;

    /* Saturate: '<S27>/Saturation' incorporates:
     *  Constant: '<S27>/Constant'
     *  DataTypeConversion: '<S36>/Data Type Conversion2'
     *  Sum: '<S36>/Add'
     *  Switch: '<S36>/Switch1'
     *  Switch: '<S38>/Switch1'
     */
    if (Gu16_facSpdCtlKi_C <= 100) {
      tmp = Gu16_facSpdCtlKi_C;
    } else {
      tmp = 100U;
    }

    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S22>/Constant5'
     *  DataTypeConversion: '<S36>/Data Type Conversion2'
     *  Product: '<S38>/Product1'
     *  Product: '<S38>/Product2'
     *  Saturate: '<S27>/Saturation'
     *  Sum: '<S30>/Add1'
     *  Sum: '<S30>/Add3'
     *  UnitDelay: '<S30>/Unit Delay'
     *  UnitDelay: '<S30>/Unit Delay1'
     */
    rtb_Switch1 = mul_ssu32_loSR(
        ((sint16)(rtb_DataTypeConversion2_hrkx +
                  (((sint16)((ASW_PhCurrGen_DW.UnitDelay_DSTATE_gwvm -
                              (ASW_PhCurrGen_DW.UnitDelay1_DSTATE_lr2t << 1)) >>
                             1))
                   << 1))) *
            41943,
        tmp, 6U);
  }

  /* End of Switch: '<S36>/Switch1' */

  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Constant: '<S64>/Constant'
   *  RelationalOperator: '<S19>/Compare'
   */
  rtb_Compare_oo4d = (rtb_enm_stMotoSt != OPEN_LOOP);

  /* Switch: '<S71>/Switch1' incorporates:
   *  Constant: '<S63>/Cu16_tiSlwTaskSmpTi'
   *  Constant: '<S63>/Gs16_facStrtUpTqRiseRate_C1'
   *  Constant: '<S71>/Constant'
   *  Logic: '<S71>/NOT'
   *  Product: '<S71>/Product1'
   */
  if (!rtb_Compare_oo4d) {
    maxV = (sint16)((Gs16_facStrtUpTqRiseRate_C * 41943) >> 15);
  } else {
    maxV = 0;
  }

  /* Switch: '<S76>/Switch1' incorporates:
   *  Constant: '<S76>/Constant1'
   *  UnitDelay: '<S76>/Unit Delay1'
   */
  if (ASW_PhCurrGen_DW.bitsForTID1.UnitDelay1_DSTATE_m2pk) {
    out = rtb_Compare_oo4d;
  } else {
    out = true;
  }

  /* Switch: '<S76>/Switch' incorporates:
   *  Switch: '<S76>/Switch1'
   *  UnitDelay: '<S63>/Unit Delay2'
   *  UnitDelay: '<S76>/Unit Delay'
   */
  if (out) {
    rtb_VectorConcatenate_0 = ASW_PhCurrGen_DW.UnitDelay2_DSTATE;
  } else {
    rtb_VectorConcatenate_0 = ASW_PhCurrGen_DW.UnitDelay_DSTATE_cvdq;
  }

  /* Sum: '<S71>/Sum' incorporates:
   *  Switch: '<S71>/Switch1'
   *  Switch: '<S76>/Switch'
   */
  rtb_Sum_mxox = (sint16)((maxV << 6) + rtb_VectorConcatenate_0);

  /* Saturate: '<S57>/Saturation2' incorporates:
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   */
  if (busPhCurrGen_SlwTaskIn.s16_nActElecSpd >= -32767) {
    /* Saturate: '<S57>/Saturation2' */
    ASW_PhCurrGen_B.Saturation2 = busPhCurrGen_SlwTaskIn.s16_nActElecSpd;
  } else {
    /* Saturate: '<S57>/Saturation2' */
    ASW_PhCurrGen_B.Saturation2 = -32767;
  }

  /* End of Saturate: '<S57>/Saturation2' */

  /* SignalConversion generated from: '<S61>/Vector Concatenate' incorporates:
   *  Saturate: '<S57>/Saturation2'
   */
  rtb_VectorConcatenate[0] = ASW_PhCurrGen_B.Saturation2;

  /* MinMax: '<S57>/Max' incorporates:
   *  Saturate: '<S57>/Saturation2'
   *  SignalConversion generated from: '<S61>/Vector Concatenate'
   */
  maxV = ASW_PhCurrGen_B.Saturation2;
  for (i_0 = 0; i_0 < 19; i_0++) {
    /* S-Function (sfix_udelay): '<S61>/Tapped Delay' */
    rtb_VectorConcatenate_0 = ASW_PhCurrGen_DW.TappedDelay_DWORK1[i_0];
    rtb_VectorConcatenate[i_0 + 1] = rtb_VectorConcatenate_0;

    /* MinMax: '<S57>/Max' incorporates:
     *  Concatenate: '<S61>/Vector Concatenate'
     */
    if (maxV >= rtb_VectorConcatenate_0) {
    } else {
      maxV = rtb_VectorConcatenate_0;
    }
  }

  /* Sum: '<S61>/Sum of Elements' incorporates:
   *  Concatenate: '<S61>/Vector Concatenate'
   */
  i_0 = 0;
  for (i = 0; i < 20; i++) {
    i_0 += rtb_VectorConcatenate[i];
  }

  /* Product: '<S61>/Divide' incorporates:
   *  Sum: '<S61>/Sum of Elements'
   */
  rtb_Divide = (dt_Standardize_s16p15b0)((i_0 >> 1) / 10);

  /* Sum: '<S57>/Add' incorporates:
   *  MinMax: '<S57>/Max'
   *  Product: '<S61>/Divide'
   */
  rtb_Add_hfyp = (dt_Standardize_s16p15b0)(maxV - rtb_Divide);

  /* MinMax: '<S57>/Max1' incorporates:
   *  Concatenate: '<S61>/Vector Concatenate'
   */
  maxV = rtb_VectorConcatenate[0];
  for (i_0 = 0; i_0 < 19; i_0++) {
    rtb_VectorConcatenate_0 = rtb_VectorConcatenate[i_0 + 1];
    if (maxV <= rtb_VectorConcatenate_0) {
    } else {
      maxV = rtb_VectorConcatenate_0;
    }
  }

  /* Sum: '<S57>/Add1' incorporates:
   *  MinMax: '<S57>/Max1'
   *  Product: '<S61>/Divide'
   */
  rtb_Add1 = (dt_Standardize_s16p15b0)(rtb_Divide - maxV);

  /* Saturate: '<S63>/Saturation1' incorporates:
   *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
   */
  if (busPhCurrGen_SlwTaskIn.s16_nRmpRefElecSpd >= -32767) {
    rtb_Saturation1_dbnw = busPhCurrGen_SlwTaskIn.s16_nRmpRefElecSpd;
  } else {
    rtb_Saturation1_dbnw = -32767;
  }

  /* End of Saturate: '<S63>/Saturation1' */

  /* Chart: '<S63>/sfc_TrqDecre' incorporates:
   *  Abs: '<S57>/Abs'
   *  Abs: '<S57>/Abs1'
   *  Abs: '<S57>/Abs2'
   *  Abs: '<S57>/Abs3'
   *  Constant: '<S57>/Gs16_nStrtUpProcTolcElecSpd_C_1'
   *  Constant: '<S57>/Gs16_nStrtUpProcTolcElecSpd_C_2'
   *  Constant: '<S58>/Constant'
   *  Logic: '<S57>/AND'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S57>/Relational Operator'
   *  RelationalOperator: '<S57>/Relational Operator1'
   *  RelationalOperator: '<S57>/Relational Operator2'
   *  RelationalOperator: '<S58>/Compare'
   *  Saturate: '<S63>/Saturation1'
   *  Saturate: '<S63>/Saturation2'
   */
  /* Gateway:
   * PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/sfc_TrqDecre
   */
  /* During:
   * PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/sfc_TrqDecre
   */
  if (ASW_PhCurrGen_DW.is_active_c2_ASW_PhCurrGen == 0U) {
    /* Entry:
     * PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/sfc_TrqDecre
     */
    ASW_PhCurrGen_DW.is_active_c2_ASW_PhCurrGen = 1U;

    /* Entry Internal:
     * PhCurrGen_SlwTask/vrs_StrtUpRefTqCalc/rss_StrtUpRefTqCalcNeed/sfc_TrqDecre
     */
    /* Transition: '<S69>:2' */
    ASW_PhCurrGen_DW.is_c2_ASW_PhCurrGen = IN_TRQ_CST;

    /* Entry 'TRQ_CST': '<S69>:1' */
    rtb_enm_stStrtupTrqSt = TRQ_CST;
  } else if (ASW_PhCurrGen_DW.is_c2_ASW_PhCurrGen == IN_TRQ_CST) {
    rtb_enm_stStrtupTrqSt = TRQ_CST;

    /* Saturate: '<S63>/Saturation2' incorporates:
     *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
     */
    /* During 'TRQ_CST': '<S69>:1' */
    if (busPhCurrGen_SlwTaskIn.s16_nRefElecSpd >= -32767) {
      maxV = busPhCurrGen_SlwTaskIn.s16_nRefElecSpd;
    } else {
      maxV = -32767;
    }

    /* Abs: '<S57>/Abs' incorporates:
     *  Sum: '<S57>/Add'
     */
    if (rtb_Add_hfyp < 0) {
      rtb_VectorConcatenate_0 = (sint16)(-rtb_Add_hfyp);
    } else {
      rtb_VectorConcatenate_0 = rtb_Add_hfyp;
    }

    /* Abs: '<S57>/Abs1' incorporates:
     *  Sum: '<S57>/Add1'
     */
    if (rtb_Add1 < 0) {
      tmp_0 = (sint16)(-rtb_Add1);
    } else {
      tmp_0 = rtb_Add1;
    }

    /* Abs: '<S57>/Abs2' incorporates:
     *  Product: '<S61>/Divide'
     */
    if (rtb_Divide < 0) {
      tmp_1 = (sint16)(-rtb_Divide);
    } else {
      tmp_1 = rtb_Divide;
    }

    /* Abs: '<S57>/Abs3' incorporates:
     *  Constant: '<S57>/Gs16_nMinStrtUpElecSpd_C'
     */
    if (Gs16_nMinStrtUpElecSpd_C < 0) {
      tmp_2 = (sint16)(-Gs16_nMinStrtUpElecSpd_C);
    } else {
      tmp_2 = Gs16_nMinStrtUpElecSpd_C;
    }

    guard1 = false;
    guard2 = false;
    if ((maxV != 0) &&
        ((((rtb_VectorConcatenate_0 <= Gs16_nStrtUpProcTolcElecSpd_C) &&
           (tmp_0 <= Gs16_nStrtUpProcTolcElecSpd_C)) &&
          (tmp_1 >= tmp_2)) &&
         (rtb_enm_stMotoSt == OPEN_LOOP))) {
      if (rtb_Saturation1_dbnw < 0) {
        i_0 = -rtb_Saturation1_dbnw;
        if ((-rtb_Saturation1_dbnw) > 32767) {
          i_0 = 32767;
        }

        maxV = (sint16)i_0;
      } else {
        maxV = rtb_Saturation1_dbnw;
      }

      if (Gs16_nMinSenlRefElecSpd_C < 0) {
        i_0 = -Gs16_nMinSenlRefElecSpd_C;
        if ((-Gs16_nMinSenlRefElecSpd_C) > 32767) {
          i_0 = 32767;
        }

        rtb_VectorConcatenate_0 = (sint16)i_0;
      } else {
        rtb_VectorConcatenate_0 = Gs16_nMinSenlRefElecSpd_C;
      }

      if (maxV >= rtb_VectorConcatenate_0) {
        guard1 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      if (busPhCurrGen_SlwTaskIn.enm_modeAgEvalMode != SENSORLESS) {
        guard1 = true;
      }
    }

    if (guard1) {
      if (rtb_enm_stMotoSt == OPEN_LOOP) {
        /* Transition: '<S69>:127' */
        ASW_PhCurrGen_DW.is_c2_ASW_PhCurrGen = IN_TRQ_DECRE;

        /* Entry 'TRQ_DECRE': '<S69>:3' */
        rtb_enm_stStrtupTrqSt = TRQ_DECRE;
      }
    }
  } else {
    rtb_enm_stStrtupTrqSt = TRQ_DECRE;

    /* During 'TRQ_DECRE': '<S69>:3' */
    if (rtb_enm_stMotoSt != OPEN_LOOP) {
      /* Transition: '<S69>:111' */
      ASW_PhCurrGen_DW.is_c2_ASW_PhCurrGen = IN_TRQ_CST;

      /* Entry 'TRQ_CST': '<S69>:1' */
      rtb_enm_stStrtupTrqSt = TRQ_CST;
    }
  }

  /* End of Chart: '<S63>/sfc_TrqDecre' */

  /* Switch: '<S81>/Switch1' incorporates:
   *  Constant: '<S65>/Constant'
   *  Constant: '<S81>/Constant1'
   *  RelationalOperator: '<S65>/Compare'
   *  UnitDelay: '<S81>/Unit Delay1'
   */
  if (ASW_PhCurrGen_DW.bitsForTID1.UnitDelay1_DSTATE_ofwc) {
    out = (rtb_enm_stStrtupTrqSt == TRQ_CST);
  } else {
    out = true;
  }

  /* Switch: '<S81>/Switch' incorporates:
   *  Constant: '<S63>/Gs16_trqMaxStrtUpTq_C'
   *  Switch: '<S81>/Switch1'
   *  UnitDelay: '<S81>/Unit Delay'
   */
  if (out) {
    rtb_Switch_kmfj = Gs16_trqMaxStrtUpTq_C;
  } else {
    rtb_Switch_kmfj = ASW_PhCurrGen_DW.UnitDelay_DSTATE_evau;
  }

  /* End of Switch: '<S81>/Switch' */

  /* RelationalOperator: '<S80>/Equal1' incorporates:
   *  Product: '<S80>/Product'
   *  RelationalOperator: '<S79>/Equal1'
   *  Sum: '<S80>/Add'
   *  Switch: '<S81>/Switch'
   */
  i_0 = (sint16)mul_ssu32_hiSR((-rtb_Switch_kmfj) << 15, 26214425U, 9U);

  /* Logic: '<S80>/Logical Operator' incorporates:
   *  Constant: '<S80>/Constant1'
   *  DataTypeConversion: '<S80>/Data Type Conversion'
   *  RelationalOperator: '<S80>/Equal'
   *  RelationalOperator: '<S80>/Equal1'
   *  Switch: '<S81>/Switch'
   */
  rtb_LogicalOperator_lo00 = ((i_0 >= (Gs16_facStrtUpTrqDecRiseRate_C >> 2)) &&
                              (rtb_Switch_kmfj <= 0));

  /* Logic: '<S79>/Logical Operator' incorporates:
   *  Constant: '<S79>/Constant1'
   *  DataTypeConversion: '<S79>/Data Type Conversion'
   *  RelationalOperator: '<S79>/Equal'
   *  RelationalOperator: '<S79>/Equal1'
   *  Switch: '<S81>/Switch'
   */
  rtb_LogicalOperator_jkyj = ((i_0 <= (Gs16_facStrtUpTrqDecFallRate_C >> 2)) &&
                              (rtb_Switch_kmfj >= 0));

  /* Chart: '<S68>/Chart' */
  /* Gateway: lib_RateLimiter_YXQ_0/Chart */
  /* During: lib_RateLimiter_YXQ_0/Chart */
  /* Entry Internal: lib_RateLimiter_YXQ_0/Chart */
  /* Transition: '<S77>:24' */
  if ((!rtb_LogicalOperator_lo00) && rtb_LogicalOperator_jkyj) {
    /* Transition: '<S77>:31' */
    /* Transition: '<S77>:34' */
    rtb_lb_noRatLimReq = false;
    rtb_lb_incrRatLimReq = false;

    /* Transition: '<S77>:36' */

    /* Transition: '<S77>:27' */
  } else if (rtb_LogicalOperator_lo00 && (!rtb_LogicalOperator_jkyj)) {
    /* Transition: '<S77>:5' */
    /* Transition: '<S77>:7' */
    rtb_lb_noRatLimReq = false;
    rtb_lb_incrRatLimReq = true;

    /* Transition: '<S77>:8' */
  } else {
    /* Transition: '<S77>:9' */
    rtb_lb_noRatLimReq = true;
    rtb_lb_incrRatLimReq = false;

    /* Transition: '<S77>:29' */
  }

  /* End of Chart: '<S68>/Chart' */

  /* Switch: '<S78>/Switch1' incorporates:
   *  Constant: '<S78>/Constant'
   *  Constant: '<S78>/Constant1'
   *  Switch: '<S78>/Switch'
   */
  /* Transition: '<S77>:39' */
  if (rtb_lb_noRatLimReq) {
    maxV = 0;
  } else if (rtb_lb_incrRatLimReq) {
    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S78>/Constant2'
     */
    maxV = Gs16_facStrtUpTrqDecRiseRate_C;
  } else {
    maxV = Gs16_facStrtUpTrqDecFallRate_C;
  }

  /* Sum: '<S78>/Add1' incorporates:
   *  Constant: '<S78>/Constant4'
   *  Product: '<S78>/Divide1'
   *  Switch: '<S78>/Switch1'
   *  Switch: '<S81>/Switch'
   */
  rtb_Add1_gfx5 = (dt_Standardize_s16p15b0)((((sint16)((maxV * 41943) >> 9)) +
                                             (rtb_Switch_kmfj << 7)) >>
                                            7);

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S63>/Gs16_trqMaxStrtUpTq_C1'
   *  Sum: '<S78>/Add1'
   */
  if (rtb_lb_noRatLimReq) {
    rtb_Switch_ijfv = 0;
  } else {
    rtb_Switch_ijfv = rtb_Add1_gfx5;
  }

  /* End of Switch: '<S68>/Switch' */

  /* Switch: '<S75>/Switch2' incorporates:
   *  Gain: '<S63>/Gain1'
   *  RelationalOperator: '<S75>/Relational Operator2'
   *  Switch: '<S68>/Switch'
   */
  if (rtb_Switch_ijfv > ((dt_Standardize_s16p15b0)(-rtb_Switch_ijfv))) {
    /* Switch: '<S75>/Switch1' incorporates:
     *  RelationalOperator: '<S75>/Relational Operator1'
     *  Sum: '<S71>/Sum'
     */
    if (rtb_Sum_mxox <= rtb_Switch_ijfv) {
      /* Switch: '<S75>/Switch' incorporates:
       *  RelationalOperator: '<S75>/Relational Operator'
       */
      if (rtb_Sum_mxox >= ((dt_Standardize_s16p15b0)(-rtb_Switch_ijfv))) {
        /* Switch: '<S75>/Switch2' */
        rtb_Switch2_m2rf = rtb_Sum_mxox;
      } else {
        /* Switch: '<S75>/Switch2' */
        rtb_Switch2_m2rf = (dt_Standardize_s16p15b0)(-rtb_Switch_ijfv);
      }

      /* End of Switch: '<S75>/Switch' */
    } else {
      /* Switch: '<S75>/Switch2' */
      rtb_Switch2_m2rf = rtb_Switch_ijfv;
    }

    /* End of Switch: '<S75>/Switch1' */
  } else {
    rtb_Switch2_m2rf = rtb_Switch_ijfv;
  }

  /* End of Switch: '<S75>/Switch2' */

  /* SwitchCase: '<S23>/Switch Case1' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion2'
   */
  switch (rtb_enm_stMotoSt) {
  case 0:
    /* Outputs for IfAction SubSystem: '<S23>/sas_OffCs' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* SignalConversion generated from: '<S51>/s16_trqInitTqOffCs' incorporates:
     *  Constant: '<S51>/Gs16_trqInitCondTq_C'
     *  Merge: '<S23>/Merge2'
     */
    rtb_Merge2 = Gs16_trqInitCondTq_C;

    /* End of Outputs for SubSystem: '<S23>/sas_OffCs' */
    break;

  case 1:
    /* Saturate: '<S18>/Saturation3' incorporates:
     *  Switch: '<S71>/Switch'
     *  Switch: '<S75>/Switch2'
     */
    if (rtb_Switch2_m2rf >= -32767) {
      /* Outputs for IfAction SubSystem: '<S23>/sas_OpnLpCs' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      /* SignalConversion generated from: '<S52>/s16_trqStrtUpRefTq'
       * incorporates: Merge: '<S23>/Merge2'
       */
      rtb_Merge2 = rtb_Switch2_m2rf;

      /* End of Outputs for SubSystem: '<S23>/sas_OpnLpCs' */
    } else {
      /* Outputs for IfAction SubSystem: '<S23>/sas_OpnLpCs' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      /* SignalConversion generated from: '<S52>/s16_trqStrtUpRefTq'
       * incorporates: Merge: '<S23>/Merge2'
       */
      rtb_Merge2 = -32767;

      /* End of Outputs for SubSystem: '<S23>/sas_OpnLpCs' */
    }

    /* End of Saturate: '<S18>/Saturation3' */
    break;

  default:
    /* Outputs for IfAction SubSystem: '<S23>/sas_ClsLpCs' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* SignalConversion: '<S49>/Signal Copy' incorporates:
     *  Constant: '<S49>/Gs16_trqInitCondTq_C'
     *  Merge: '<S23>/Merge2'
     */
    rtb_Merge2 = Gs16_trqInitCondTq_C;

    /* End of Outputs for SubSystem: '<S23>/sas_ClsLpCs' */
    break;
  }

  /* End of SwitchCase: '<S23>/Switch Case1' */

  /* Switch: '<S44>/Switch' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion2'
   *  Switch: '<S23>/Switch1'
   *  Switch: '<S44>/Switch1'
   *  UnitDelay: '<S44>/Unit Delay'
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  if ((!ASW_PhCurrGen_DW.bitsForTID1.UnitDelay1_DSTATE_jjio) ||
      rtb_LogicalOperator) {
    /* Switch: '<S23>/Switch1' incorporates:
     *  Constant: '<S48>/Constant'
     *  Merge: '<S23>/Merge2'
     *  RelationalOperator: '<S19>/Compare'
     *  RelationalOperator: '<S48>/Compare'
     */
    if (rtb_enm_stMotoSt != OFF) {
      /* Switch: '<S23>/Switch2' incorporates:
       *  Inport: '<Root>/busPhCurrGen_SlwTaskIn'
       *  Merge: '<S23>/Merge2'
       */
      if (busPhCurrGen_SlwTaskIn.bol_enPosSCDCalibEnFlg) {
        /* Saturate: '<S18>/Saturation9' */
        if (busPhCurrGen_SlwTaskIn.s16_trqPosSCDCalibRefTq >= -32767) {
          maxV = busPhCurrGen_SlwTaskIn.s16_trqPosSCDCalibRefTq;
        } else {
          maxV = -32767;
        }

        /* End of Saturate: '<S18>/Saturation9' */
      } else {
        maxV = rtb_Merge2;
      }

      /* End of Switch: '<S23>/Switch2' */
    } else {
      maxV = rtb_Merge2;
    }

    rtb_Switch = (maxV << 16);
  } else {
    rtb_Switch = ASW_PhCurrGen_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Sum: '<S38>/Sum' incorporates:
   *  Switch: '<S38>/Switch1'
   *  Switch: '<S44>/Switch'
   */
  rtb_Sum = rtb_Switch1 + rtb_Switch;

  /* Sum: '<S30>/Add2' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   *  Sum: '<S38>/Sum'
   *  Switch: '<S36>/Switch1'
   *  Switch: '<S38>/Switch'
   */
  rtb_Add2 = (sint16)((rtb_Switch1_iv22 + (rtb_Sum >> 16)) >> 1);

  /* DataTypeConversion: '<S30>/Data Type Conversion1' incorporates:
   *  Gain: '<S18>/Gain1'
   *  Saturate: '<S18>/Saturation4'
   */
  rtb_DataTypeConversion1_bu1w =
      (sint16)(((dt_Standardize_s16p15b0)(-rtb_Saturation4)) >> 1);

  /* Switch: '<S35>/Switch2' incorporates:
   *  DataTypeConversion: '<S30>/Data Type Conversion'
   *  DataTypeConversion: '<S30>/Data Type Conversion1'
   *  RelationalOperator: '<S35>/Relational Operator2'
   */
  if (rtb_DataTypeConversion_c14a > rtb_DataTypeConversion1_bu1w) {
    /* Switch: '<S35>/Switch1' incorporates:
     *  RelationalOperator: '<S35>/Relational Operator1'
     *  Sum: '<S30>/Add2'
     */
    if (rtb_Add2 <= rtb_DataTypeConversion_c14a) {
      /* Switch: '<S35>/Switch' incorporates:
       *  RelationalOperator: '<S35>/Relational Operator'
       */
      if (rtb_Add2 >= rtb_DataTypeConversion1_bu1w) {
        maxV = rtb_Add2;
      } else {
        maxV = rtb_DataTypeConversion1_bu1w;
      }

      /* End of Switch: '<S35>/Switch' */
    } else {
      maxV = rtb_DataTypeConversion_c14a;
    }

    /* End of Switch: '<S35>/Switch1' */
  } else {
    maxV = rtb_DataTypeConversion_c14a;
  }

  /* DataTypeConversion: '<S30>/Data Type Conversion2' incorporates:
   *  Switch: '<S35>/Switch2'
   */
  rtb_DataTypeConversion2_nzfu = (dt_Standardize_s16p15b0)(maxV << 1);

  /* Saturate: '<S2>/Saturation' incorporates:
   *  DataTypeConversion: '<S30>/Data Type Conversion2'
   */
  if (rtb_DataTypeConversion2_nzfu >= -32767) {
    maxV = rtb_DataTypeConversion2_nzfu;
  } else {
    maxV = -32767;
  }

  /* Saturate: '<S17>/Saturation' incorporates:
   *  Constant: '<S17>/Constant'
   */
  if (Gu8_numPPNum_C > 6) {
    tmp_3 = 6U;
  } else if (Gu8_numPPNum_C < 2) {
    tmp_3 = 2U;
  } else {
    tmp_3 = Gu8_numPPNum_C;
  }

  /* Product: '<S9>/Divide2' incorporates:
   *  Gain: '<S9>/Gain1'
   *  Saturate: '<S17>/Saturation'
   *  Saturate: '<S2>/Saturation'
   */
  rtb_Divide2 = (sint16)((((21845 * maxV) >> 15) << 1) / tmp_3);

  /* Saturate: '<S2>/Saturation1' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  if (Gu16_psiPermMagFlx_C > 10922) {
    rtb_Saturation1 = 10922U;
  } else if (Gu16_psiPermMagFlx_C < 55) {
    rtb_Saturation1 = 55U;
  } else {
    rtb_Saturation1 = Gu16_psiPermMagFlx_C;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Abs: '<S9>/Abs' incorporates:
   *  Product: '<S9>/Divide2'
   */
  if (rtb_Divide2 < 0) {
    maxV = (sint16)(-rtb_Divide2);
  } else {
    maxV = rtb_Divide2;
  }

  /* Gain: '<S9>/Gain2' incorporates:
   *  Abs: '<S9>/Abs'
   */
  rtb_Gain2 = (dt_Standardize_u16p15b0)((18963 * maxV) >> 17);

  /* BusCreator: '<S56>/Bus Creator1' incorporates:
   *  Constant: '<S9>/Constant1'
   *  SignalConversion generated from: '<S56>/Bus Creator1'
   */
  busPhCurrGen_SlwTaskOut.s16_iRefDaxQaxCurr[0] = 0;

  /* Switch: '<S9>/Switch' incorporates:
   *  Gain: '<S9>/Gain2'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  Saturate: '<S2>/Saturation1'
   */
  if (rtb_Saturation1 >= rtb_Gain2) {
    tmp = rtb_Saturation1;
  } else {
    tmp = rtb_Gain2;
  }

  /* BusCreator: '<S56>/Bus Creator1' incorporates:
   *  Gain: '<S9>/Gain'
   *  Product: '<S9>/Divide'
   *  Product: '<S9>/Divide2'
   *  Switch: '<S9>/Switch'
   */
  busPhCurrGen_SlwTaskOut.s16_iRefDaxQaxCurr[1] =
      (dt_Standardize_s16p15b0)((rtb_Divide2 << 12) /
                                ((uint16)((62915U * tmp) >> 15)));
  busPhCurrGen_SlwTaskOut.enm_stMotoSt = rtb_enm_stMotoSt;

  /* Update for UnitDelay: '<S53>/Unit Delay19' */
  ASW_PhCurrGen_DW.UnitDelay19_DSTATE = rtb_enm_stStrtupTrqSt;

  /* Saturate: '<S53>/Saturation4' incorporates:
   *  Switch: '<S71>/Switch'
   *  Switch: '<S75>/Switch2'
   */
  if (rtb_Switch2_m2rf >= -32767) {
    /* Update for UnitDelay: '<S53>/Unit Delay1' */
    ASW_PhCurrGen_DW.UnitDelay1_DSTATE = rtb_Switch2_m2rf;
  } else {
    /* Update for UnitDelay: '<S53>/Unit Delay1' */
    ASW_PhCurrGen_DW.UnitDelay1_DSTATE = -32767;
  }

  /* End of Saturate: '<S53>/Saturation4' */

  /* Update for UnitDelay: '<S30>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S30>/Data Type Conversion2'
   */
  ASW_PhCurrGen_DW.UnitDelay_DSTATE_gwvm = rtb_DataTypeConversion2_nzfu;

  /* Update for UnitDelay: '<S30>/Unit Delay1' incorporates:
   *  Sum: '<S30>/Add2'
   */
  ASW_PhCurrGen_DW.UnitDelay1_DSTATE_lr2t = rtb_Add2;

  /* Saturate: '<S63>/Saturation3' incorporates:
   *  DataTypeConversion: '<S30>/Data Type Conversion2'
   */
  if (rtb_DataTypeConversion2_nzfu >= -32767) {
    /* Update for UnitDelay: '<S63>/Unit Delay2' */
    ASW_PhCurrGen_DW.UnitDelay2_DSTATE = rtb_DataTypeConversion2_nzfu;
  } else {
    /* Update for UnitDelay: '<S63>/Unit Delay2' */
    ASW_PhCurrGen_DW.UnitDelay2_DSTATE = -32767;
  }

  /* End of Saturate: '<S63>/Saturation3' */

  /* Update for UnitDelay: '<S76>/Unit Delay1' incorporates:
   *  Constant: '<S76>/Constant'
   */
  ASW_PhCurrGen_DW.bitsForTID1.UnitDelay1_DSTATE_m2pk = true;

  /* Update for UnitDelay: '<S76>/Unit Delay' incorporates:
   *  Switch: '<S71>/Switch'
   *  Switch: '<S75>/Switch2'
   */
  ASW_PhCurrGen_DW.UnitDelay_DSTATE_cvdq = rtb_Switch2_m2rf;

  /* Update for S-Function (sfix_udelay): '<S61>/Tapped Delay' incorporates:
   *  MinMax: '<S57>/Max'
   *  MinMax: '<S57>/Max1'
   *  Saturate: '<S57>/Saturation2'
   *  Sum: '<S61>/Sum of Elements'
   */
  for (i_0 = 0; i_0 < 18; i_0++) {
    ASW_PhCurrGen_DW.TappedDelay_DWORK1[i_0] =
        ASW_PhCurrGen_DW.TappedDelay_DWORK1[i_0 + 1];
  }

  ASW_PhCurrGen_DW.TappedDelay_DWORK1[18] = ASW_PhCurrGen_B.Saturation2;

  /* End of Update for S-Function (sfix_udelay): '<S61>/Tapped Delay' */

  /* Update for UnitDelay: '<S81>/Unit Delay1' incorporates:
   *  Constant: '<S81>/Constant'
   */
  ASW_PhCurrGen_DW.bitsForTID1.UnitDelay1_DSTATE_ofwc = true;

  /* Update for UnitDelay: '<S81>/Unit Delay' incorporates:
   *  Sum: '<S78>/Add1'
   */
  ASW_PhCurrGen_DW.UnitDelay_DSTATE_evau = rtb_Add1_gfx5;

  /* Update for UnitDelay: '<S44>/Unit Delay1' incorporates:
   *  Constant: '<S44>/Constant'
   */
  ASW_PhCurrGen_DW.bitsForTID1.UnitDelay1_DSTATE_jjio = true;

  /* Update for UnitDelay: '<S44>/Unit Delay' incorporates:
   *  Sum: '<S38>/Sum'
   *  Switch: '<S38>/Switch'
   */
  ASW_PhCurrGen_DW.UnitDelay_DSTATE = rtb_Sum;
}

/* Model step function */
void ASW_PhCurrGen_step(void) {
  if (ASW_PhCurrGen_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/PhCurrGen_SlwTask' */
    PhCurrGen_SlwTask();

    /* End of Outputs for SubSystem: '<Root>/PhCurrGen_SlwTask' */
  }

  rate_scheduler();
}

/* Model initialize function */
void ASW_PhCurrGen_Init(void) {
  /* Registration code */

  /* initialize real-time model */
  (void)memset((void *)ASW_PhCurrGen_M, 0, sizeof(RT_MODEL_ASW_PhCurrGen));

  /* block I/O */
  (void)memset(((void *)&ASW_PhCurrGen_B), 0, sizeof(B_ASW_PhCurrGen));

  /* exported global signals */
  busPhCurrGen_SlwTaskOut = ASW_PhCurrGen_rtZBUS_PHCURRGEN_SLW_TASK_OUT;

  /* states (dwork) */
  (void)memset((void *)&ASW_PhCurrGen_DW, 0, sizeof(DW_ASW_PhCurrGen));

  /* external inputs */
  busPhCurrGen_SlwTaskIn = ASW_PhCurrGen_rtZBUS_PHCURRGEN_;

  /* SystemInitialize for Atomic SubSystem: '<Root>/PhCurrGen_SlwTask' */
  PhCurrGen_SlwTask_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/PhCurrGen_SlwTask' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
