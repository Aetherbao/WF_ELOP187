/*
 * File: ASW_OBD.c
 *
 * Code generated for Simulink model 'ASW_OBD'.
 *
 * Model version                  : 6.304
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Mar 25 10:57:19 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ASW_OBD.h"
#include "../ASW_share/rtwtypes.h"
#include "../ASW_share/custom_type_definition.h"
#include "ASW_OBD_private.h"
#include "../ASW_share/motor_control_interface.h"
#include "../ASW_par/motor_control_param.h"
#include "../ASW_share/look1_is16lu32n32ys16n_eAC3J1UD.h"
#include "../ASW_share/zero_crossing_types.h"
#include <string.h>

/* Named constants for Chart: '<S38>/sfc_FaultDebounce' */
#define IN_Confirm                     ((uint8)1U)
#define IN_Confirming                  ((uint8)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8)0U)
#define IN_Repairing                   ((uint8)3U)
#define IN_Wait                        ((uint8)4U)

/* Named constants for Chart: '<S37>/sfc_FaultDefiniteness' */
#define IN_Confirmed                   ((uint8)1U)
#define IN_Confirming_mgd1             ((uint8)2U)
#define IN_DisableDiagnosis            ((uint8)1U)
#define IN_EnableDiagnosis             ((uint8)2U)
#define IN_NO_ACTIVE_CHILD_crf3        ((uint8)0U)
#define IN_Normal                      ((uint8)3U)
#define IN_Wait_le4k                   ((uint8)4U)

/* Named constants for Chart: '<S81>/sfc_Debounce' */
#define IN_Confirm_az00                ((uint8)1U)
#define IN_Confirming_n43e             ((uint8)2U)
#define IN_NO_ACTIVE_CHILD_jdh3        ((uint8)0U)
#define IN_Wait_j43f                   ((uint8)3U)

/* Named constants for Chart: '<S62>/sfc_FaultDefiniteness' */
#define IN_Confirmed_fog5              ((uint8)1U)
#define IN_Confirming_p012             ((uint8)2U)
#define IN_DisableDiagnosis_ixht       ((uint8)1U)
#define IN_EnableDiagnosis_mjfq        ((uint8)2U)
#define IN_NO_ACTIVE_CHILD_lvm4        ((uint8)0U)
#define IN_Normal_iv3m                 ((uint8)3U)
#define IN_Wait_ax3z                   ((uint8)4U)

const BUS_OBD_SLW_TASK_OUT ASW_OBD_rtZBUS_OBD_SLW_TASK_OUT = {
  {
    false,                             /* bol_flgPhCurrHiLvl1Flg */
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
  0U,                                  /* u8_stMaxFaltLvl */
  0,                                   /* s16_nFaltRefMechSpd */
  0,                                   /* s16_trqFaltRefTqLim */
  false,                               /* bol_flgPhiSensFaltRawFlg */
  false,                               /* bol_flgComNodeLosFaltDeb */
  false,                               /* bol_flgComRolCntFaltDeb */
  false,                               /* bol_flgCRCFaltDeb */

  {
    false,                             /* bol_flgPhCurrHiLvl1Tmp */
    false,                             /* bol_flgHWOvrCurrTmp */
    false,                             /* bol_flgSplyVltgLoLvl1Tmp */
    false,                             /* bol_flgSplyVltgLoLvl2Tmp */
    false,                             /* bol_flgSplyVltgHiLvl1Tmp */
    false,                             /* bol_flgPwrTubPCBTempHiLvl1Tmp */
    false,                             /* bol_flgPwrTubPCBTempHiLvl2Tmp */
    false,                             /* bol_flgMotoTempHiLvl1Tmp */
    false,                             /* bol_flgMotoTempHiLvl2Tmp */
    false,                             /* bol_flgComFaltTmp */
    false,                             /* bol_flgMotoStallPermTmp */
    false,                             /* bol_flgMotoStallTmpTmp */
    false,                             /* bol_flgNoLdTmp */
    false,                             /* bol_flgBattPwrHiLvl1Tmp */
    false,                             /* bol_flgMotoSpdHiLvl1Tmp */
    false,                             /* bol_flgMotoSpdLoLvl1Tmp */
    false,                             /* bol_flgCtlBrdVltgLoLvl1Tmp */
    false,                             /* bol_flgCtlBrdVltgHiLvl1Tmp */
    false,                             /* bol_flgGDVltgLoLvl1Tmp */
    false,                             /* bol_flgGDVltgHiLvl1Tmp */
    false,                             /* bol_flgChipFaltTmp */
    false,                             /* bol_flgPhiSensFaltTmp */
    false,                             /* bol_flgPhCurrSensFaltTmp */
    false,                             /* bol_flgPwrTubPCBTempSensFaltTmp */
    false,                             /* bol_flgMotoTempSensFaltTmp */
    false,                             /* bol_flgBusOffFaltTmp */
    false,                             /* bol_flgCrashFaltTmp */
    false,                             /* bol_flgMosOpnCirFaltTmp */
    false,                             /* bol_flgReserved4Tmp */
    false                              /* bol_flgReserved5Tmp */
  }                                    /* busOBD_FaltStTmp */
};                                     /* BUS_OBD_SLW_TASK_OUT ground */

/* Exported block signals */
BUS_OBD_SLW_TASK_IN busOBD_SlwTaskIn;  /* '<Root>/busOBD_SlwTaskIn' */
BUS_OBD_SLW_TASK_OUT busOBD_SlwTaskOut;/* '<S309>/Bus Creator1' */
uint8 test9;                           /* '<S73>/Signal Copy1' */
uint8 test10;                          /* '<S73>/Add' */
uint8 test6;                           /* '<S73>/Data Type Conversion2' */
boolean test2;                         /* '<S72>/Data Type Conversion' */

/* Block signals (default storage) */
B_ASW_OBD ASW_OBD_B;

/* Block states (default storage) */
DW_ASW_OBD ASW_OBD_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ASW_OBD ASW_OBD_PrevZCX;

/* Real-time model */
static RT_MODEL_ASW_OBD ASW_OBD_M_;
RT_MODEL_ASW_OBD *const ASW_OBD_M = &ASW_OBD_M_;
static void rate_scheduler(void);
const BUS_OBD_SLW_TASK_IN ASW_OBD_rtZBUS_OBD_SLW_TASK_IN = { 0,/* s16_nRmpRefElecSpd */
  0,                                   /* s16_nActElecSpd */
  0U,                                  /* enm_stMotoSt */
  0,                                   /* s16_ampActPhCurrAmp */
  0U,                                  /* u16_uSplyVltg */
  40U,                                 /* u8_tPwrTubTemp */
  40U,                                 /* u8_tPCBTemp */
  40U,                                 /* u8_tMotoTemp */
  0U,                                  /* bol_flgComLosFaltRaw */
  0U,                                  /* u8_ctComRolCnt */
  0U,                                  /* u16_uCtlBrdVltg */
  3U,                                  /* enm_stSysSt */
  false,                               /* bol_flgHWOvrCurrFalt */
  false,                               /* bol_flgChipFalt */
  false,                               /* bol_flgPhiSensFalt */

  { 0U, 0U, 0U },                      /* u16_uADActPhCurr */
  0U,                                  /* u16_uADPwrTubTemp */
  0U,                                  /* u16_uADPCBTemp */
  0U,                                  /* u16_uADMotoTemp */
  0,                                   /* s16_pwrSplyElecPwr */

  { 0, 0, 0 },                         /* s16_iActPhCurr */
  0,                                   /* s16_iEstSplyCurr */

  { 0, 0 },                            /* s16_iRefDaxQaxCurr */

  { 0, 0 },                            /* s16_iActDaxQaxCurr */
  false,                               /* bol_flgShOffFlg */
  false,                               /* bol_enFaltInfoClrUDS14 */
  0U,                                  /* u16_vVehSpd */
  0U,                                  /* u32_disOde */
  0U,                                  /* u32_tiStamHi */
  0U,                                  /* u32_tiStamLo */
  0U,                                  /* u8_psiOilFlow */
  40U,                                 /* u8_tOilTemp */
  false,                               /* bol_enPosSCDCalibEnFlg */
  0U,                                  /* u8_psiUpLimOilFlow */
  false,                               /* bol_flgBusOffFaltRaw */
  false,                               /* bol_flgFaltEnFlgUDS85 */
  false,                               /* bol_flgWBSSt */
  false,                               /* bol_flgCRCFaltRaw */
  false,                               /* bol_flgMesgLngthFaltRaw */
  0,                                   /* s16_nComRefMechSpd */
  0U,                                  /* u16_psiEstPermMagFlx */
  0U,                                  /* enm_modeAgEvalMode */
  false,                               /* bol_flgCrashFalt */
  false,                               /* bol_flgGDVltgHiLvl1 */
  false,                               /* bol_flgGDVltgLoLvl1 */
  40U,                                 /* u8_tMCUTemp */
  40U,                                 /* u8_tPCBTempSubs */
  0U,                                  /* u16_uGDVltg */
  false,                               /* bol_flgMosOpnCirFalt */
  false                                /* bol_ComIf_flgComLosFaltRaw */
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
  (ASW_OBD_M->Timing.TaskCounters.TID[1])++;
  if ((ASW_OBD_M->Timing.TaskCounters.TID[1]) > 79) {/* Sample time: [0.01s, 0.0s] */
    ASW_OBD_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S38>/sfc_FaultDebounce'
 *    '<S45>/sfc_FaultDebounce'
 *    '<S51>/sfc_FaultDebounce'
 *    '<S57>/sfc_FaultDebounce'
 *    '<S66>/sfc_FaultDebounce'
 *    '<S67>/sfc_FaultDebounce'
 *    '<S68>/sfc_FaultDebounce'
 *    '<S139>/sfc_FaultDebounce'
 *    '<S146>/sfc_FaultDebounce'
 *    '<S152>/sfc_FaultDebounce'
 *    ...
 */
void ASW_OBD_sfc_FaultDebounce_Init(boolean *rty_lb_genOutp,
  DW_sfc_FaultDebounce_ASW_OBD *localDW)
{
  localDW->is_active_c7_lib_debounce = 0U;
  localDW->is_c7_lib_debounce = IN_NO_ACTIVE_CHILD;
  localDW->lb_cntDebCond = 0U;
  *rty_lb_genOutp = false;
}

/*
 * Output and update for atomic system:
 *    '<S38>/sfc_FaultDebounce'
 *    '<S45>/sfc_FaultDebounce'
 *    '<S51>/sfc_FaultDebounce'
 *    '<S57>/sfc_FaultDebounce'
 *    '<S66>/sfc_FaultDebounce'
 *    '<S67>/sfc_FaultDebounce'
 *    '<S68>/sfc_FaultDebounce'
 *    '<S139>/sfc_FaultDebounce'
 *    '<S146>/sfc_FaultDebounce'
 *    '<S152>/sfc_FaultDebounce'
 *    ...
 */
void ASW_OBD_sfc_FaultDebounce(boolean rtu_lb_bolInp, uint16 rtu_lb_cntDebConf,
  uint16 rtu_lb_cntDebRcvy, boolean *rty_lb_genOutp,
  DW_sfc_FaultDebounce_ASW_OBD *localDW)
{
  sint32 tmp;

  /* Chart: '<S38>/sfc_FaultDebounce' */
  /* Gateway: lib_debounce_0/sfc_FaultDebounce */
  /* During: lib_debounce_0/sfc_FaultDebounce */
  if (localDW->is_active_c7_lib_debounce == 0U) {
    /* Entry: lib_debounce_0/sfc_FaultDebounce */
    localDW->is_active_c7_lib_debounce = 1U;

    /* Entry Internal: lib_debounce_0/sfc_FaultDebounce */
    /* Transition: '<S40>:149' */
    /* There is Fault */
    if (rtu_lb_bolInp) {
      /* Transition: '<S40>:182' */
      /* Direct Confirm */
      if (rtu_lb_cntDebConf == 0) {
        /* Transition: '<S40>:185' */
        /* Transition: '<S40>:188' */
        localDW->is_c7_lib_debounce = IN_Confirm;

        /* Entry 'Confirm': '<S40>:165' */
        /* Set Bit0 Bit1 */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = true;
      } else {
        /* Transition: '<S40>:183' */
        localDW->is_c7_lib_debounce = IN_Confirming;

        /* Entry 'Confirming': '<S40>:93' */
        /* Set Bit0 */
        tmp = localDW->lb_cntDebCond + 1;
        if ((localDW->lb_cntDebCond + 1) > 65535) {
          tmp = 65535;
        }

        localDW->lb_cntDebCond = (uint16)tmp;
        *rty_lb_genOutp = false;
      }
    } else {
      /* Transition: '<S40>:180' */
      localDW->is_c7_lib_debounce = IN_Wait;

      /* Entry 'Wait': '<S40>:98' */
      localDW->lb_cntDebCond = 0U;
      *rty_lb_genOutp = false;
    }
  } else {
    switch (localDW->is_c7_lib_debounce) {
     case IN_Confirm:
      *rty_lb_genOutp = true;

      /* During 'Confirm': '<S40>:165' */
      /* There is no Fault */
      if (!rtu_lb_bolInp) {
        /* Transition: '<S40>:196' */
        /* Direct Repair */
        if (rtu_lb_cntDebRcvy == 0) {
          /* Transition: '<S40>:197' */
          localDW->is_c7_lib_debounce = IN_Wait;

          /* Entry 'Wait': '<S40>:98' */
          localDW->lb_cntDebCond = 0U;
          *rty_lb_genOutp = false;
        } else {
          /* Transition: '<S40>:207' */
          /* Need Debounce */
          localDW->is_c7_lib_debounce = IN_Repairing;

          /* Entry 'Repairing': '<S40>:100' */
          /* Clear Bit0 */
          tmp = localDW->lb_cntDebCond + 1;
          if ((localDW->lb_cntDebCond + 1) > 65535) {
            tmp = 65535;
          }

          localDW->lb_cntDebCond = (uint16)tmp;
          *rty_lb_genOutp = true;
        }
      }
      break;

     case IN_Confirming:
      *rty_lb_genOutp = false;

      /* During 'Confirming': '<S40>:93' */
      /* There is no Fault */
      if (!rtu_lb_bolInp) {
        /* Transition: '<S40>:173' */
        localDW->is_c7_lib_debounce = IN_Wait;

        /* Entry 'Wait': '<S40>:98' */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = false;

        /* Fault Is Confirmed */
      } else if (localDW->lb_cntDebCond >= rtu_lb_cntDebConf) {
        /* Transition: '<S40>:167' */
        localDW->is_c7_lib_debounce = IN_Confirm;

        /* Entry 'Confirm': '<S40>:165' */
        /* Set Bit0 Bit1 */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = true;
      } else {
        localDW->lb_cntDebCond++;
      }
      break;

     case IN_Repairing:
      *rty_lb_genOutp = true;

      /* During 'Repairing': '<S40>:100' */
      /* There is Fault */
      if (rtu_lb_bolInp) {
        /* Transition: '<S40>:172' */
        localDW->is_c7_lib_debounce = IN_Confirm;

        /* Entry 'Confirm': '<S40>:165' */
        /* Set Bit0 Bit1 */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = true;

        /* Fault Is Repaired */
      } else if (localDW->lb_cntDebCond >= rtu_lb_cntDebRcvy) {
        /* Transition: '<S40>:169' */
        localDW->is_c7_lib_debounce = IN_Wait;

        /* Entry 'Wait': '<S40>:98' */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = false;
      } else {
        localDW->lb_cntDebCond++;
      }
      break;

     default:
      *rty_lb_genOutp = false;

      /* During 'Wait': '<S40>:98' */
      /* There is Fault */
      if (rtu_lb_bolInp) {
        /* Transition: '<S40>:166' */
        /* Direct Confirm */
        if (rtu_lb_cntDebConf == 0) {
          /* Transition: '<S40>:214' */
          localDW->is_c7_lib_debounce = IN_Confirm;

          /* Entry 'Confirm': '<S40>:165' */
          /* Set Bit0 Bit1 */
          localDW->lb_cntDebCond = 0U;
          *rty_lb_genOutp = true;
        } else {
          /* Transition: '<S40>:213' */
          /* Need Debounce */
          localDW->is_c7_lib_debounce = IN_Confirming;

          /* Entry 'Confirming': '<S40>:93' */
          /* Set Bit0 */
          tmp = localDW->lb_cntDebCond + 1;
          if ((localDW->lb_cntDebCond + 1) > 65535) {
            tmp = 65535;
          }

          localDW->lb_cntDebCond = (uint16)tmp;
          *rty_lb_genOutp = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S38>/sfc_FaultDebounce' */
}

/*
 * System initialize for atomic system:
 *    '<S36>/lib_Deb_11'
 *    '<S43>/lib_Deb_4'
 *    '<S49>/lib_Deb_17'
 *    '<S55>/lib_Deb_1'
 *    '<S63>/lib_Deb_5'
 *    '<S63>/lib_Deb_6'
 *    '<S63>/lib_Deb_7'
 *    '<S138>/lib_Deb_16'
 *    '<S145>/lib_Deb_15'
 *    '<S150>/lib_Deb_0'
 *    ...
 */
void ASW_OBD_lib_Deb_11_Init(boolean *rty_lb_genOutp, DW_lib_Deb_11_ASW_OBD
  *localDW)
{
  /* SystemInitialize for Chart: '<S38>/sfc_FaultDebounce' */
  ASW_OBD_sfc_FaultDebounce_Init(rty_lb_genOutp, &localDW->sf_sfc_FaultDebounce);
}

/*
 * Output and update for atomic system:
 *    '<S36>/lib_Deb_11'
 *    '<S43>/lib_Deb_4'
 *    '<S49>/lib_Deb_17'
 *    '<S55>/lib_Deb_1'
 *    '<S63>/lib_Deb_5'
 *    '<S63>/lib_Deb_6'
 *    '<S63>/lib_Deb_7'
 *    '<S138>/lib_Deb_16'
 *    '<S145>/lib_Deb_15'
 *    '<S150>/lib_Deb_0'
 *    ...
 */
void ASW_OBD_lib_Deb_11(boolean rtu_lb_bolInp, uint16 rtu_lb_cntDebConf, uint16
  rtu_lb_cntDebRcvy, boolean *rty_lb_genOutp, DW_lib_Deb_11_ASW_OBD *localDW)
{
  /* Chart: '<S38>/sfc_FaultDebounce' */
  ASW_OBD_sfc_FaultDebounce(rtu_lb_bolInp, rtu_lb_cntDebConf, rtu_lb_cntDebRcvy,
    rty_lb_genOutp, &localDW->sf_sfc_FaultDebounce);
}

/*
 * System initialize for atomic system:
 *    '<S37>/sfc_FaultDefiniteness'
 *    '<S44>/sfc_FaultDefiniteness'
 *    '<S50>/sfc_FaultDefiniteness'
 *    '<S56>/sfc_FaultDefiniteness'
 *    '<S80>/sfc_FaultDefiniteness'
 *    '<S87>/sfc_FaultDefiniteness'
 *    '<S137>/sfc_FaultDefiniteness'
 *    '<S144>/sfc_FaultDefiniteness'
 *    '<S151>/sfc_FaultDefiniteness'
 *    '<S157>/sfc_FaultDefiniteness'
 *    ...
 */
void ASW__sfc_FaultDefiniteness_Init(boolean *rty_stFaltDef_Tmpr, boolean
  *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt, DW_sfc_FaultDefiniteness_ASW_OB
  *localDW)
{
  localDW->is_EnableDiagnosis = IN_NO_ACTIVE_CHILD_crf3;
  localDW->is_active_c2_sv8YVlxvCwKOd9Te1t = 0U;
  localDW->is_c2_sv8YVlxvCwKOd9Te1tJVaiH_l = IN_NO_ACTIVE_CHILD_crf3;
  localDW->FaltWaitRecvCnt = 0U;
  *rty_stFaltDef_Tmpr = false;
  *rty_stFaltDef_Perm = false;
  *rty_FaltCycAccCnt = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S37>/sfc_FaultDefiniteness'
 *    '<S44>/sfc_FaultDefiniteness'
 *    '<S50>/sfc_FaultDefiniteness'
 *    '<S56>/sfc_FaultDefiniteness'
 *    '<S80>/sfc_FaultDefiniteness'
 *    '<S87>/sfc_FaultDefiniteness'
 *    '<S137>/sfc_FaultDefiniteness'
 *    '<S144>/sfc_FaultDefiniteness'
 *    '<S151>/sfc_FaultDefiniteness'
 *    '<S157>/sfc_FaultDefiniteness'
 *    ...
 */
void ASW_OBD_sfc_FaultDefiniteness(boolean rtu_stFaltDeb, boolean
  rtu_bolFaltEnFlg, uint8 rtu_stFaltCycDiaCnt, boolean rtu_bolFaltRecEnFlag,
  boolean *rty_stFaltDef_Tmpr, boolean *rty_stFaltDef_Perm, uint8
  *rty_FaltCycAccCnt, uint16 rtp_lb_FaltWaitRecvCnt,
  DW_sfc_FaultDefiniteness_ASW_OB *localDW)
{
  sint32 tmp;
  sint32 tmp_0;

  /* Chart: '<S37>/sfc_FaultDefiniteness' */
  /* Gateway: FaultDefiniteness_0/sfc_FaultDefiniteness */
  /* During: FaultDefiniteness_0/sfc_FaultDefiniteness */
  if (localDW->is_active_c2_sv8YVlxvCwKOd9Te1t == 0U) {
    /* Entry: FaultDefiniteness_0/sfc_FaultDefiniteness */
    localDW->is_active_c2_sv8YVlxvCwKOd9Te1t = 1U;

    /* Entry Internal: FaultDefiniteness_0/sfc_FaultDefiniteness */
    /* Transition: '<S41>:222' */
    localDW->is_c2_sv8YVlxvCwKOd9Te1tJVaiH_l = IN_DisableDiagnosis;

    /* Entry 'DisableDiagnosis': '<S41>:221' */
    /* Clear Bit0 Bit1 */
    *rty_stFaltDef_Tmpr = false;
    *rty_stFaltDef_Perm = false;
    *rty_FaltCycAccCnt = 0U;
  } else if (localDW->is_c2_sv8YVlxvCwKOd9Te1tJVaiH_l == IN_DisableDiagnosis) {
    *rty_stFaltDef_Tmpr = false;
    *rty_stFaltDef_Perm = false;

    /* During 'DisableDiagnosis': '<S41>:221' */
    /* Fault Need Enable */
    if (rtu_bolFaltEnFlg) {
      /* Transition: '<S41>:223' */
      localDW->is_c2_sv8YVlxvCwKOd9Te1tJVaiH_l = IN_EnableDiagnosis;

      /* Entry Internal 'EnableDiagnosis': '<S41>:220' */
      /* Transition: '<S41>:149' */
      localDW->is_EnableDiagnosis = IN_Normal;

      /* Entry 'Normal': '<S41>:225' */
      /* Clear Bit0 Bit1 */
      *rty_stFaltDef_Tmpr = false;
      *rty_stFaltDef_Perm = false;
      *rty_FaltCycAccCnt = 0U;
    }
  } else {
    /* During 'EnableDiagnosis': '<S41>:220' */
    switch (localDW->is_EnableDiagnosis) {
     case IN_Confirmed:
      *rty_stFaltDef_Tmpr = false;
      *rty_stFaltDef_Perm = true;

      /* During 'Confirmed': '<S41>:165' */
      /* Need Recovery */
      if (rtu_bolFaltRecEnFlag && (!rtu_stFaltDeb)) {
        /* Transition: '<S41>:219' */
        /* Transition: '<S41>:230' */
        localDW->is_EnableDiagnosis = IN_Normal;

        /* Entry 'Normal': '<S41>:225' */
        /* Clear Bit0 Bit1 */
        *rty_stFaltDef_Tmpr = false;
        *rty_stFaltDef_Perm = false;
        *rty_FaltCycAccCnt = 0U;
      }
      break;

     case IN_Confirming_mgd1:
      *rty_stFaltDef_Tmpr = true;
      *rty_stFaltDef_Perm = true;

      /* During 'Confirming': '<S41>:93' */
      /* There is no Fault */
      if (!rtu_stFaltDeb) {
        /* Transition: '<S41>:173' */
        localDW->is_EnableDiagnosis = IN_Wait_le4k;

        /* Entry 'Wait': '<S41>:98' */
        /* Set Bit0 Clear Bit1 */
        *rty_stFaltDef_Tmpr = true;
        *rty_stFaltDef_Perm = false;
        localDW->FaltWaitRecvCnt = 0U;
      }
      break;

     case IN_Normal:
      *rty_stFaltDef_Tmpr = false;
      *rty_stFaltDef_Perm = false;

      /* During 'Normal': '<S41>:225' */
      /* There is Fault */
      if (rtu_stFaltDeb) {
        /* Transition: '<S41>:182' */
        /* Direct Confirm */
        if (rtu_stFaltCycDiaCnt == 0) {
          /* Transition: '<S41>:185' */
          /* Transition: '<S41>:188' */
          localDW->is_EnableDiagnosis = IN_Confirmed;

          /* Entry 'Confirmed': '<S41>:165' */
          /* Set Bit1 Clear Bit0 */
          *rty_stFaltDef_Tmpr = false;
          *rty_stFaltDef_Perm = true;
          *rty_FaltCycAccCnt = 0U;
        } else {
          /* Transition: '<S41>:183' */
          localDW->is_EnableDiagnosis = IN_Confirming_mgd1;

          /* Entry 'Confirming': '<S41>:93' */
          /* Set Bit0 Bit1 */
          *rty_stFaltDef_Tmpr = true;
          *rty_stFaltDef_Perm = true;
          tmp = (*rty_FaltCycAccCnt) + 1;
          if (((*rty_FaltCycAccCnt) + 1) > 255) {
            tmp = 255;
          }

          *rty_FaltCycAccCnt = (uint8)tmp;
        }
      }
      break;

     default:
      *rty_stFaltDef_Tmpr = true;
      *rty_stFaltDef_Perm = false;

      /* During 'Wait': '<S41>:98' */
      /* There is Fault */
      if (rtu_stFaltDeb) {
        /* Transition: '<S41>:166' */
        /* Fault is Confirmed */
        if ((*rty_FaltCycAccCnt) >= rtu_stFaltCycDiaCnt) {
          /* Transition: '<S41>:214' */
          /* Transition: '<S41>:232' */
          /* Exit 'Wait': '<S41>:98' */
          localDW->FaltWaitRecvCnt = 0U;
          localDW->is_EnableDiagnosis = IN_Confirmed;

          /* Entry 'Confirmed': '<S41>:165' */
          /* Set Bit1 Clear Bit0 */
          *rty_stFaltDef_Tmpr = false;
          *rty_stFaltDef_Perm = true;
          *rty_FaltCycAccCnt = 0U;
        } else {
          /* Transition: '<S41>:213' */
          /* Need Confirm */
          /* Exit 'Wait': '<S41>:98' */
          localDW->FaltWaitRecvCnt = 0U;
          localDW->is_EnableDiagnosis = IN_Confirming_mgd1;

          /* Entry 'Confirming': '<S41>:93' */
          /* Set Bit0 Bit1 */
          *rty_stFaltDef_Tmpr = true;
          *rty_stFaltDef_Perm = true;
          tmp = (*rty_FaltCycAccCnt) + 1;
          if (((*rty_FaltCycAccCnt) + 1) > 255) {
            tmp = 255;
          }

          *rty_FaltCycAccCnt = (uint8)tmp;
        }
      } else {
        /* Confirm to Recovery */
        tmp = (rtp_lb_FaltWaitRecvCnt << 1);
        if (tmp > 65535) {
          tmp = 65535;
        }

        tmp_0 = tmp + 100;
        if ((tmp + 100) > 65535) {
          tmp_0 = 65535;
        }

        if ((localDW->FaltWaitRecvCnt > tmp_0) && rtu_bolFaltEnFlg) {
          /* Transition: '<S41>:226' */
          /* Transition: '<S41>:234' */
          /* Exit 'Wait': '<S41>:98' */
          localDW->FaltWaitRecvCnt = 0U;
          localDW->is_EnableDiagnosis = IN_Normal;

          /* Entry 'Normal': '<S41>:225' */
          /* Clear Bit0 Bit1 */
          *rty_stFaltDef_Tmpr = false;
          *rty_stFaltDef_Perm = false;
          *rty_FaltCycAccCnt = 0U;
        } else {
          tmp = localDW->FaltWaitRecvCnt + 1;
          if ((localDW->FaltWaitRecvCnt + 1) > 65535) {
            tmp = 65535;
          }

          localDW->FaltWaitRecvCnt = (uint16)tmp;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S37>/sfc_FaultDefiniteness' */
}

/*
 * System initialize for atomic system:
 *    '<S35>/lib_FaltDefd_21'
 *    '<S42>/lib_FaltDefd_12'
 *    '<S48>/lib_FaltDefd_9'
 *    '<S54>/lib_FaltDefd_9'
 *    '<S78>/lib_FaltDefd_1'
 *    '<S85>/lib_FaltDefd_0'
 *    '<S135>/lib_FaltDefd_8'
 *    '<S142>/lib_FaltDefd_7'
 *    '<S155>/lib_FaltDefd_9'
 *    '<S161>/lib_FaltDefd_22'
 *    ...
 */
void ASW_OBD_lib_FaltDefd_21_Init(boolean *rty_stFaltDef_Tmpr, boolean
  *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt, DW_lib_FaltDefd_21_ASW_OBD
  *localDW)
{
  /* SystemInitialize for Chart: '<S37>/sfc_FaultDefiniteness' */
  ASW__sfc_FaultDefiniteness_Init(rty_stFaltDef_Tmpr, rty_stFaltDef_Perm,
    rty_FaltCycAccCnt, &localDW->sf_sfc_FaultDefiniteness);
}

/*
 * Output and update for atomic system:
 *    '<S35>/lib_FaltDefd_21'
 *    '<S42>/lib_FaltDefd_12'
 *    '<S48>/lib_FaltDefd_9'
 *    '<S54>/lib_FaltDefd_9'
 *    '<S78>/lib_FaltDefd_1'
 *    '<S85>/lib_FaltDefd_0'
 *    '<S135>/lib_FaltDefd_8'
 *    '<S142>/lib_FaltDefd_7'
 *    '<S155>/lib_FaltDefd_9'
 *    '<S161>/lib_FaltDefd_22'
 *    ...
 */
void ASW_OBD_lib_FaltDefd_21(boolean rtu_stFaltDeb, boolean rtu_bolFaltEnFlg,
  uint8 rtu_stFaltCycDiaCnt, boolean rtu_bolFaltRecEnFlag, boolean
  *rty_stFaltDef_Tmpr, boolean *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt,
  uint16 rtp_lb_FaltWaitRecvCnt, DW_lib_FaltDefd_21_ASW_OBD *localDW)
{
  /* Chart: '<S37>/sfc_FaultDefiniteness' */
  ASW_OBD_sfc_FaultDefiniteness(rtu_stFaltDeb, rtu_bolFaltEnFlg,
    rtu_stFaltCycDiaCnt, rtu_bolFaltRecEnFlag, rty_stFaltDef_Tmpr,
    rty_stFaltDef_Perm, rty_FaltCycAccCnt, rtp_lb_FaltWaitRecvCnt,
    &localDW->sf_sfc_FaultDefiniteness);
}

/* Output and update for atomic system: '<S63>/CANHeartLos' */
void CANHeartLosCheck(void)
{
  /* RelationalOperator: '<S69>/Equal' incorporates:
   *  Inport: '<Root>/busOBD_SlwTaskIn'
   *  UnitDelay: '<S69>/Unit Delay'
   */
  ASW_OBD_B.bitsForTID1.Equal_azvi = (ASW_OBD_DW.UnitDelay_DSTATE_bxev ==
    busOBD_SlwTaskIn.bol_flgComLosFaltRaw);

  /* Update for UnitDelay: '<S69>/Unit Delay' incorporates:
   *  Inport: '<Root>/busOBD_SlwTaskIn'
   */
  ASW_OBD_DW.UnitDelay_DSTATE_bxev = busOBD_SlwTaskIn.bol_flgComLosFaltRaw;
}

/* Output and update for enable system: '<S65>/COMLosDia' */
void CANSigLosCheck(void)
{
  uint8 rtb_UnitDelay_fura;

  /* Outputs for Enabled SubSystem: '<S65>/COMLosDia' incorporates:
   *  EnablePort: '<S70>/Enable'
   */
  if (ASW_OBD_B.bitsForTID1.Equal) {
    /* SignalConversion: '<S73>/Signal Copy1' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    test9 = busOBD_SlwTaskIn.u8_ctComRolCnt;

    /* UnitDelay: '<S73>/Unit Delay' */
    rtb_UnitDelay_fura = ASW_OBD_DW.UnitDelay_DSTATE_npzl;

    /* Sum: '<S73>/Add' */
    test10 = (uint8)(test9 - rtb_UnitDelay_fura);

    /* DataTypeConversion: '<S73>/Data Type Conversion2' incorporates:
     *  Constant: '<S73>/Constant'
     *  Constant: '<S73>/Constant1'
     *  Constant: '<S73>/Constant2'
     *  Logic: '<S73>/Logical Operator'
     *  Logic: '<S73>/Logical Operator1'
     *  Logic: '<S73>/NOT'
     *  RelationalOperator: '<S73>/Equal'
     *  RelationalOperator: '<S73>/Equal1'
     *  RelationalOperator: '<S73>/Equal2'
     */
    test6 = (uint8)((test10 != 1) && ((test9 != Gu8_RollingMin_C) ||
      (rtb_UnitDelay_fura != Gu8_RollingMax_C)));

    /* DataTypeConversion: '<S71>/Data Type Conversion1' */
    ASW_OBD_B.bitsForTID1.DataTypeConversion1 = (test6 != 0);

    /* DataTypeConversion: '<S72>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    test2 = busOBD_SlwTaskIn.bol_flgCRCFaltRaw;

    /* DataTypeConversion: '<S71>/Data Type Conversion' */
    ASW_OBD_B.bitsForTID1.DataTypeConversion = test2;

    /* Update for UnitDelay: '<S73>/Unit Delay' */
    ASW_OBD_DW.UnitDelay_DSTATE_npzl = test9;
  }

  /* End of Outputs for SubSystem: '<S65>/COMLosDia' */
}

/*
 * System initialize for atomic system:
 *    '<S81>/sfc_Debounce'
 *    '<S81>/sfc_Debounce1'
 *    '<S88>/sfc_Debounce'
 *    '<S88>/sfc_Debounce1'
 *    '<S164>/sfc_Debounce'
 *    '<S164>/sfc_Debounce1'
 *    '<S174>/sfc_Debounce'
 *    '<S174>/sfc_Debounce1'
 *    '<S181>/sfc_Debounce'
 *    '<S181>/sfc_Debounce1'
 *    ...
 */
void ASW_OBD_sfc_Debounce_Init(boolean *rty_lb_genOutp, DW_sfc_Debounce_ASW_OBD *
  localDW)
{
  localDW->is_active_c7_vhit_control_libra = 0U;
  localDW->is_c7_vhit_control_library = IN_NO_ACTIVE_CHILD_jdh3;
  localDW->lb_cntDebCond = 0U;
  *rty_lb_genOutp = false;
}

/*
 * Output and update for atomic system:
 *    '<S81>/sfc_Debounce'
 *    '<S81>/sfc_Debounce1'
 *    '<S88>/sfc_Debounce'
 *    '<S88>/sfc_Debounce1'
 *    '<S164>/sfc_Debounce'
 *    '<S164>/sfc_Debounce1'
 *    '<S174>/sfc_Debounce'
 *    '<S174>/sfc_Debounce1'
 *    '<S181>/sfc_Debounce'
 *    '<S181>/sfc_Debounce1'
 *    ...
 */
void ASW_OBD_sfc_Debounce(boolean rtu_lb_bolInp, uint16 rtu_lb_cntDebConf,
  boolean *rty_lb_genOutp, DW_sfc_Debounce_ASW_OBD *localDW)
{
  sint32 tmp;

  /* Chart: '<S81>/sfc_Debounce' */
  /* Gateway: lib_HysDeb_1/sfc_Debounce */
  /* During: lib_HysDeb_1/sfc_Debounce */
  if (localDW->is_active_c7_vhit_control_libra == 0U) {
    /* Entry: lib_HysDeb_1/sfc_Debounce */
    localDW->is_active_c7_vhit_control_libra = 1U;

    /* Entry Internal: lib_HysDeb_1/sfc_Debounce */
    /* Transition: '<S82>:149' */
    /* There is Fault */
    if (rtu_lb_bolInp) {
      /* Transition: '<S82>:182' */
      /* Direct Confirm */
      if (rtu_lb_cntDebConf == 0) {
        /* Transition: '<S82>:185' */
        /* Transition: '<S82>:188' */
        localDW->is_c7_vhit_control_library = IN_Confirm_az00;

        /* Entry 'Confirm': '<S82>:165' */
        /* Set Bit0 Bit1 */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = true;
      } else {
        /* Transition: '<S82>:183' */
        localDW->is_c7_vhit_control_library = IN_Confirming_n43e;

        /* Entry 'Confirming': '<S82>:93' */
        /* Set Bit0 */
        tmp = localDW->lb_cntDebCond + 1;
        if ((localDW->lb_cntDebCond + 1) > 65535) {
          tmp = 65535;
        }

        localDW->lb_cntDebCond = (uint16)tmp;
        *rty_lb_genOutp = false;
      }
    } else {
      /* Transition: '<S82>:180' */
      localDW->is_c7_vhit_control_library = IN_Wait_j43f;

      /* Entry 'Wait': '<S82>:98' */
      localDW->lb_cntDebCond = 0U;
      *rty_lb_genOutp = false;
    }
  } else {
    switch (localDW->is_c7_vhit_control_library) {
     case IN_Confirm_az00:
      *rty_lb_genOutp = true;

      /* During 'Confirm': '<S82>:165' */
      /* There is no Fault */
      if (!rtu_lb_bolInp) {
        /* Transition: '<S82>:196' */
        localDW->is_c7_vhit_control_library = IN_Wait_j43f;

        /* Entry 'Wait': '<S82>:98' */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = false;
      }
      break;

     case IN_Confirming_n43e:
      *rty_lb_genOutp = false;

      /* During 'Confirming': '<S82>:93' */
      /* There is no Fault */
      if (!rtu_lb_bolInp) {
        /* Transition: '<S82>:173' */
        localDW->is_c7_vhit_control_library = IN_Wait_j43f;

        /* Entry 'Wait': '<S82>:98' */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = false;

        /* Fault Is Confirmed */
      } else if (localDW->lb_cntDebCond >= rtu_lb_cntDebConf) {
        /* Transition: '<S82>:167' */
        localDW->is_c7_vhit_control_library = IN_Confirm_az00;

        /* Entry 'Confirm': '<S82>:165' */
        /* Set Bit0 Bit1 */
        localDW->lb_cntDebCond = 0U;
        *rty_lb_genOutp = true;
      } else {
        localDW->lb_cntDebCond++;
      }
      break;

     default:
      *rty_lb_genOutp = false;

      /* During 'Wait': '<S82>:98' */
      /* There is Fault */
      if (rtu_lb_bolInp) {
        /* Transition: '<S82>:166' */
        /* Direct Confirm */
        if (rtu_lb_cntDebConf == 0) {
          /* Transition: '<S82>:214' */
          localDW->is_c7_vhit_control_library = IN_Confirm_az00;

          /* Entry 'Confirm': '<S82>:165' */
          /* Set Bit0 Bit1 */
          localDW->lb_cntDebCond = 0U;
          *rty_lb_genOutp = true;
        } else {
          /* Transition: '<S82>:213' */
          /* Need Debounce */
          localDW->is_c7_vhit_control_library = IN_Confirming_n43e;

          /* Entry 'Confirming': '<S82>:93' */
          /* Set Bit0 */
          tmp = localDW->lb_cntDebCond + 1;
          if ((localDW->lb_cntDebCond + 1) > 65535) {
            tmp = 65535;
          }

          localDW->lb_cntDebCond = (uint16)tmp;
          *rty_lb_genOutp = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S81>/sfc_Debounce' */
}

/*
 * System initialize for atomic system:
 *    '<S79>/lib_HysDeb_1'
 *    '<S86>/lib_HysDeb_0'
 *    '<S259>/lib_HysDeb_5'
 *    '<S266>/lib_HysDeb_3'
 *    '<S273>/lib_HysDeb_4'
 */
void ASW_OBD_lib_HysDeb_1_Init(boolean rtp_lb_parInitOutp,
  DW_lib_HysDeb_1_ASW_OBD *localDW)
{
  boolean rtb_lb_genOutp_eunr;

  /* InitializeConditions for UnitDelay: '<S81>/Unit Delay2' */
  localDW->bitsForTID1.UnitDelay2_DSTATE = rtp_lb_parInitOutp;

  /* SystemInitialize for Chart: '<S81>/sfc_Debounce1' */
  ASW_OBD_sfc_Debounce_Init(&rtb_lb_genOutp_eunr, &localDW->sf_sfc_Debounce1);

  /* SystemInitialize for Chart: '<S81>/sfc_Debounce' */
  ASW_OBD_sfc_Debounce_Init(&rtb_lb_genOutp_eunr, &localDW->sf_sfc_Debounce);
}

/*
 * Output and update for atomic system:
 *    '<S79>/lib_HysDeb_1'
 *    '<S86>/lib_HysDeb_0'
 *    '<S259>/lib_HysDeb_5'
 *    '<S266>/lib_HysDeb_3'
 *    '<S273>/lib_HysDeb_4'
 */
void ASW_OBD_lib_HysDeb_1(dt_Standardize_u16p15b0 rtu_lb_genInp,
  dt_Standardize_u16p15b0 rtu_lb_genUpLim, dt_Standardize_u16p15b0
  rtu_lb_genLowLim, uint16 rtu_lb_cntSetConf, uint16 rtu_lb_cntRsetConf, boolean
  rtu_lb_bolSet, boolean rtu_lb_bolRset, boolean *rty_lb_bolDebOutp, boolean
  *rty_lb_bolHiOccOutp, boolean *rty_lb_bolLoOccOutp, DW_lib_HysDeb_1_ASW_OBD
  *localDW)
{
  boolean rtb_lb_genOutp_iqys;
  boolean rtb_lb_genOutp_l21w;

  /* RelationalOperator: '<S81>/Relational Operator' */
  *rty_lb_bolLoOccOutp = (rtu_lb_genInp < rtu_lb_genLowLim);

  /* Chart: '<S81>/sfc_Debounce1' */
  ASW_OBD_sfc_Debounce(*rty_lb_bolLoOccOutp, rtu_lb_cntRsetConf,
                       &rtb_lb_genOutp_iqys, &localDW->sf_sfc_Debounce1);

  /* RelationalOperator: '<S81>/Relational Operator1' */
  *rty_lb_bolHiOccOutp = (rtu_lb_genInp > rtu_lb_genUpLim);

  /* Chart: '<S81>/sfc_Debounce' */
  ASW_OBD_sfc_Debounce(*rty_lb_bolHiOccOutp, rtu_lb_cntSetConf,
                       &rtb_lb_genOutp_l21w, &localDW->sf_sfc_Debounce);

  /* Switch: '<S81>/Switch1' incorporates:
   *  Switch: '<S81>/Switch'
   *  UnitDelay: '<S81>/Unit Delay2'
   */
  if (rtb_lb_genOutp_l21w) {
    *rty_lb_bolDebOutp = rtu_lb_bolSet;
  } else if (rtb_lb_genOutp_iqys) {
    /* Switch: '<S81>/Switch' */
    *rty_lb_bolDebOutp = rtu_lb_bolRset;
  } else {
    *rty_lb_bolDebOutp = localDW->bitsForTID1.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S81>/Switch1' */

  /* Update for UnitDelay: '<S81>/Unit Delay2' */
  localDW->bitsForTID1.UnitDelay2_DSTATE = *rty_lb_bolDebOutp;
}

/* Output and update for iterator system: '<S10>/sss_FaltLvlConf' */
void ASW_OBD_sss_FaltLvlConf(void)
{
  sint32 i;
  uint8 rtb_Switch;
  uint8 s102_iter;
  boolean tmp[30];

  /* Outputs for Iterator SubSystem: '<S10>/sss_FaltLvlConf' incorporates:
   *  ForIterator: '<S102>/For Iterator'
   */
  /* SignalConversion generated from: '<S102>/Selector1' */
  tmp[0] = ASW_OBD_B.BusCreator1.bol_flgPhCurrHiLvl1Flg;
  tmp[1] = ASW_OBD_B.BusCreator1.bol_flgHWOvrCurrFlg;
  tmp[2] = ASW_OBD_B.BusCreator1.bol_flgSplyVltgLoLvl1Flg;
  tmp[3] = ASW_OBD_B.BusCreator1.bol_flgSplyVltgLoLvl2Flg;
  tmp[4] = ASW_OBD_B.BusCreator1.bol_flgSplyVltgHiLvl1Flg;
  tmp[5] = ASW_OBD_B.BusCreator1.bol_flgPwrTubPCBTempHiLvl1Flg;
  tmp[6] = ASW_OBD_B.BusCreator1.bol_flgPwrTubPCBTempHiLvl2Flg;
  tmp[7] = ASW_OBD_B.BusCreator1.bol_flgMotoTempHiLvl1Flg;
  tmp[8] = ASW_OBD_B.BusCreator1.bol_flgMotoTempHiLvl2Flg;
  tmp[9] = ASW_OBD_B.BusCreator1.bol_flgComFaltFlg;
  tmp[10] = ASW_OBD_B.BusCreator1.bol_flgMotoStallPermFlg;
  tmp[11] = ASW_OBD_B.BusCreator1.bol_flgMotoStallTmpFlg;
  tmp[12] = ASW_OBD_B.BusCreator1.bol_flgNoLdFlg;
  tmp[13] = ASW_OBD_B.BusCreator1.bol_flgBattPwrHiLvl1Flg;
  tmp[14] = ASW_OBD_B.BusCreator1.bol_flgMotoSpdHiLvl1Flg;
  tmp[15] = ASW_OBD_B.BusCreator1.bol_flgMotoSpdLoLvl1Flg;
  tmp[16] = ASW_OBD_B.BusCreator1.bol_flgCtlBrdVltgLoLvl1Flg;
  tmp[17] = ASW_OBD_B.BusCreator1.bol_flgCtlBrdVltgHiLvl1Flg;
  tmp[18] = ASW_OBD_B.BusCreator1.bol_flgGDVltgLoLvl1Flg;
  tmp[19] = ASW_OBD_B.BusCreator1.bol_flgGDVltgHiLvl1Flg;
  tmp[20] = ASW_OBD_B.BusCreator1.bol_flgChipFaltFlg;
  tmp[21] = ASW_OBD_B.BusCreator1.bol_flgPhiSensFaltFlg;
  tmp[22] = ASW_OBD_B.BusCreator1.bol_flgPhCurrSensFaltFlg;
  tmp[23] = ASW_OBD_B.BusCreator1.bol_flgPwrTubPCBTempSensFaltFlg;
  tmp[24] = ASW_OBD_B.BusCreator1.bol_flgMotoTempSensFaltFlg;
  tmp[25] = ASW_OBD_B.BusCreator1.bol_flgBusOffFaltFlg;
  tmp[26] = ASW_OBD_B.BusCreator1.bol_flgCrashFaltFlg;
  tmp[27] = ASW_OBD_B.BusCreator1.bol_flgMosOpnCirFaltFlg;
  tmp[28] = ASW_OBD_B.BusCreator1.bol_flgReserved4Flg;
  tmp[29] = ASW_OBD_B.BusCreator1.bol_flgReserved5Flg;
  for (s102_iter = 1; s102_iter < 31; s102_iter++) {
    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S102>/Constant1'
     *  Selector: '<S102>/Selector'
     *  Selector: '<S102>/Selector1'
     */
    if (tmp[s102_iter - 1]) {
      rtb_Switch = ASW_OBD_B.DataTypeConversion3[s102_iter - 1];
    } else {
      rtb_Switch = 0U;
    }

    /* End of Switch: '<S102>/Switch' */

    /* Assignment: '<S102>/Assignment' incorporates:
     *  Selector: '<S102>/Selector1'
     */
    if (s102_iter == 1) {
      for (i = 0; i < 30; i++) {
        ASW_OBD_B.Assignment_czft[i] = 0U;
      }
    }

    ASW_OBD_B.Assignment_czft[s102_iter - 1] = rtb_Switch;

    /* End of Assignment: '<S102>/Assignment' */
  }

  /* End of Outputs for SubSystem: '<S10>/sss_FaltLvlConf' */
}

/* Output and update for iterator system: '<S106>/sss_FaltLvl2Conf' */
void ASW_OBD_sss_FaltLvl2Conf(void)
{
  sint32 i;
  dt_Standardize_s16p15b0 tmp[30];
  dt_Standardize_s16p15b0 rtb_Switch;
  dt_Standardize_s16p15b0 rtb_Switch1;
  uint8 Assignment_czft;
  uint8 s133_iter;

  /* Outputs for Iterator SubSystem: '<S106>/sss_FaltLvl2Conf' incorporates:
   *  ForIterator: '<S133>/For Iterator'
   */
  for (s133_iter = 1; s133_iter < 31; s133_iter++) {
    /* Selector: '<S133>/Selector1' */
    Assignment_czft = ASW_OBD_B.Assignment_czft[s133_iter - 1];

    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S133>/Constant2'
     *  Constant: '<S133>/Constant5'
     *  RelationalOperator: '<S133>/Relational Operator'
     *  Selector: '<S133>/Selector'
     *  Selector: '<S133>/Selector1'
     */
    if (Assignment_czft == 2) {
      /* SignalConversion generated from: '<S133>/Selector' incorporates:
       *  Constant: '<S111>/Constant2'
       *  Constant: '<S113>/Constant17'
       *  Constant: '<S114>/Constant17'
       *  Constant: '<S115>/Constant17'
       *  Constant: '<S116>/Constant17'
       *  Constant: '<S117>/Constant17'
       *  Constant: '<S118>/Constant17'
       *  Constant: '<S120>/Constant17'
       */
      tmp[0] = Gs16_nMaxRefMechSpd_C;
      tmp[1] = Gs16_nMaxRefMechSpd_C;
      tmp[2] = Gs16_nMaxRefMechSpd_C;
      tmp[3] = Gs16_nMaxRefMechSpd_C;
      tmp[4] = Gs16_nMaxRefMechSpd_C;
      tmp[5] = Gs16_nMaxRefMechSpd_C;
      tmp[6] = Gs16_nMaxRefMechSpd_C;
      tmp[7] = Gs16_nMaxRefMechSpd_C;
      tmp[8] = Gs16_nMaxRefMechSpd_C;
      tmp[9] = ASW_OBD_B.Switch3;
      tmp[10] = Gs16_nMaxRefMechSpd_C;
      tmp[11] = ASW_OBD_B.Switch1;
      tmp[12] = Gs16_nMaxRefMechSpd_C;
      tmp[13] = Gs16_nMaxRefMechSpd_C;
      tmp[14] = Gs16_nMaxRefMechSpd_C;
      tmp[15] = Gs16_nMaxRefMechSpd_C;
      tmp[16] = Gs16_nMaxRefMechSpd_C;
      tmp[17] = Gs16_nMaxRefMechSpd_C;
      tmp[18] = Gs16_nMaxRefMechSpd_C;
      tmp[19] = Gs16_nMaxRefMechSpd_C;
      tmp[20] = Gs16_nMaxRefMechSpd_C;
      tmp[21] = Gs16_nMaxRefMechSpd_C;
      tmp[22] = Gs16_nMaxRefMechSpd_C;
      tmp[23] = Gs16_nMaxRefMechSpd_C;
      tmp[24] = Gs16_nMaxRefMechSpd_C;
      tmp[25] = ASW_OBD_B.Switch3;
      tmp[26] = Gs16_nMaxRefMechSpd_C;
      tmp[27] = Gs16_nMaxRefMechSpd_C;
      tmp[28] = Gs16_nMaxRefMechSpd_C;
      tmp[29] = Gs16_nMaxRefMechSpd_C;
      rtb_Switch = tmp[s133_iter - 1];
    } else {
      rtb_Switch = Gs16_nMaxRefMechSpd_C;
    }

    /* End of Switch: '<S133>/Switch' */

    /* Assignment: '<S133>/Assignment' incorporates:
     *  Selector: '<S133>/Selector1'
     *  Switch: '<S133>/Switch'
     */
    if (s133_iter == 1) {
      for (i = 0; i < 30; i++) {
        ASW_OBD_B.Assignment[i] = 0;
      }
    }

    ASW_OBD_B.Assignment[s133_iter - 1] = rtb_Switch;

    /* End of Assignment: '<S133>/Assignment' */

    /* Switch: '<S133>/Switch1' incorporates:
     *  Constant: '<S133>/Constant3'
     *  Constant: '<S133>/Constant4'
     *  RelationalOperator: '<S133>/Relational Operator1'
     *  Selector: '<S133>/Selector1'
     *  Selector: '<S133>/Selector2'
     *  Selector: '<S133>/Selector3'
     */
    if (Assignment_czft == 2) {
      /* SignalConversion generated from: '<S133>/Selector2' incorporates:
       *  Constant: '<S112>/Constant1'
       *  Constant: '<S126>/Constant1'
       *  Constant: '<S127>/Constant'
       *  Constant: '<S127>/Constant1'
       *  Constant: '<S128>/Constant1'
       *  Constant: '<S129>/Constant1'
       *  Constant: '<S130>/Constant1'
       *  Constant: '<S131>/Constant1'
       *  Constant: '<S132>/Constant1'
       */
      tmp[0] = Gs16_trqTqUpLim_C;
      tmp[1] = Gs16_trqTqUpLim_C;
      tmp[2] = Gs16_trqTqUpLim_C;
      tmp[3] = Gs16_trqTqUpLim_C;
      tmp[4] = Gs16_trqTqUpLim_C;
      tmp[5] = Gs16_trqTqUpLim_C;
      tmp[6] = Gs16_trqTqUpLim_C;
      tmp[7] = Gs16_trqTqUpLim_C;
      tmp[8] = Gs16_trqTqUpLim_C;
      tmp[9] = Gs16_trqTqUpLim_C;
      tmp[10] = Gs16_trqTqUpLim_C;
      tmp[11] = Gs16_trqTmpStallTqUpLim_C;
      tmp[12] = Gs16_trqTqUpLim_C;
      tmp[13] = Gs16_trqTqUpLim_C;
      tmp[14] = Gs16_trqTqUpLim_C;
      tmp[15] = Gs16_trqTqUpLim_C;
      tmp[16] = Gs16_trqTqUpLim_C;
      tmp[17] = Gs16_trqTqUpLim_C;
      tmp[18] = Gs16_trqTqUpLim_C;
      tmp[19] = Gs16_trqTqUpLim_C;
      tmp[20] = Gs16_trqTqUpLim_C;
      tmp[21] = Gs16_trqTqUpLim_C;
      tmp[22] = Gs16_trqTqUpLim_C;
      tmp[23] = Gs16_trqTqUpLim_C;
      tmp[24] = Gs16_trqTqUpLim_C;
      tmp[25] = Gs16_trqTqUpLim_C;
      tmp[26] = Gs16_trqTqUpLim_C;
      tmp[27] = Gs16_trqTqUpLim_C;
      tmp[28] = Gs16_trqTqUpLim_C;
      tmp[29] = Gs16_trqTqUpLim_C;
      rtb_Switch1 = tmp[s133_iter - 1];
    } else {
      rtb_Switch1 = Gs16_trqTqUpLim_C;
    }

    /* End of Switch: '<S133>/Switch1' */

    /* Assignment: '<S133>/Assignment1' incorporates:
     *  Selector: '<S133>/Selector1'
     *  Switch: '<S133>/Switch1'
     */
    if (s133_iter == 1) {
      for (i = 0; i < 30; i++) {
        ASW_OBD_B.Assignment1[i] = 0;
      }
    }

    ASW_OBD_B.Assignment1[s133_iter - 1] = rtb_Switch1;

    /* End of Assignment: '<S133>/Assignment1' */
  }

  /* End of Outputs for SubSystem: '<S106>/sss_FaltLvl2Conf' */
}

/*
 * System initialize for atomic system:
 *    '<S162>/lib_HysDeb_14'
 *    '<S207>/lib_HysDeb_2'
 */
void ASW_OBD_lib_HysDeb_14_Init(boolean rtp_lb_parInitOutp,
  DW_lib_HysDeb_14_ASW_OBD *localDW)
{
  boolean rtb_lb_genOutp_lpaf;

  /* InitializeConditions for UnitDelay: '<S164>/Unit Delay2' */
  localDW->bitsForTID1.UnitDelay2_DSTATE = rtp_lb_parInitOutp;

  /* SystemInitialize for Chart: '<S164>/sfc_Debounce1' */
  ASW_OBD_sfc_Debounce_Init(&rtb_lb_genOutp_lpaf, &localDW->sf_sfc_Debounce1);

  /* SystemInitialize for Chart: '<S164>/sfc_Debounce' */
  ASW_OBD_sfc_Debounce_Init(&rtb_lb_genOutp_lpaf, &localDW->sf_sfc_Debounce);
}

/*
 * Output and update for atomic system:
 *    '<S162>/lib_HysDeb_14'
 *    '<S207>/lib_HysDeb_2'
 */
void ASW_OBD_lib_HysDeb_14(dt_Standardize_s16p15b0 rtu_lb_genInp,
  dt_Standardize_s16p15b0 rtu_lb_genUpLim, dt_Standardize_s16p15b0
  rtu_lb_genLowLim, uint16 rtu_lb_cntSetConf, uint16 rtu_lb_cntRsetConf, boolean
  rtu_lb_bolSet, boolean rtu_lb_bolRset, boolean *rty_lb_bolDebOutp, boolean
  *rty_lb_bolHiOccOutp, boolean *rty_lb_bolLoOccOutp, DW_lib_HysDeb_14_ASW_OBD
  *localDW)
{
  boolean rtb_lb_genOutp_e5ea;
  boolean rtb_lb_genOutp_o3zp;

  /* RelationalOperator: '<S164>/Relational Operator' */
  *rty_lb_bolLoOccOutp = (rtu_lb_genInp < rtu_lb_genLowLim);

  /* Chart: '<S164>/sfc_Debounce1' */
  ASW_OBD_sfc_Debounce(*rty_lb_bolLoOccOutp, rtu_lb_cntRsetConf,
                       &rtb_lb_genOutp_o3zp, &localDW->sf_sfc_Debounce1);

  /* RelationalOperator: '<S164>/Relational Operator1' */
  *rty_lb_bolHiOccOutp = (rtu_lb_genInp > rtu_lb_genUpLim);

  /* Chart: '<S164>/sfc_Debounce' */
  ASW_OBD_sfc_Debounce(*rty_lb_bolHiOccOutp, rtu_lb_cntSetConf,
                       &rtb_lb_genOutp_e5ea, &localDW->sf_sfc_Debounce);

  /* Switch: '<S164>/Switch1' incorporates:
   *  Switch: '<S164>/Switch'
   *  UnitDelay: '<S164>/Unit Delay2'
   */
  if (rtb_lb_genOutp_e5ea) {
    *rty_lb_bolDebOutp = rtu_lb_bolSet;
  } else if (rtb_lb_genOutp_o3zp) {
    /* Switch: '<S164>/Switch' */
    *rty_lb_bolDebOutp = rtu_lb_bolRset;
  } else {
    *rty_lb_bolDebOutp = localDW->bitsForTID1.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S164>/Switch1' */

  /* Update for UnitDelay: '<S164>/Unit Delay2' */
  localDW->bitsForTID1.UnitDelay2_DSTATE = *rty_lb_bolDebOutp;
}

/*
 * System initialize for atomic system:
 *    '<S179>/lib_HysDeb_12'
 *    '<S186>/lib_HysDeb_13'
 *    '<S221>/lib_HysDeb_8'
 *    '<S221>/lib_HysDeb_9'
 *    '<S231>/lib_HysDeb_10'
 *    '<S231>/lib_HysDeb_11'
 */
void ASW_OBD_lib_HysDeb_12_Init(boolean rtp_lb_parInitOutp,
  DW_lib_HysDeb_12_ASW_OBD *localDW)
{
  boolean rtb_lb_genOutp_cmne;

  /* InitializeConditions for UnitDelay: '<S181>/Unit Delay2' */
  localDW->bitsForTID1.UnitDelay2_DSTATE = rtp_lb_parInitOutp;

  /* SystemInitialize for Chart: '<S181>/sfc_Debounce1' */
  ASW_OBD_sfc_Debounce_Init(&rtb_lb_genOutp_cmne, &localDW->sf_sfc_Debounce1);

  /* SystemInitialize for Chart: '<S181>/sfc_Debounce' */
  ASW_OBD_sfc_Debounce_Init(&rtb_lb_genOutp_cmne, &localDW->sf_sfc_Debounce);
}

/*
 * Output and update for atomic system:
 *    '<S179>/lib_HysDeb_12'
 *    '<S186>/lib_HysDeb_13'
 *    '<S221>/lib_HysDeb_8'
 *    '<S221>/lib_HysDeb_9'
 *    '<S231>/lib_HysDeb_10'
 *    '<S231>/lib_HysDeb_11'
 */
void ASW_OBD_lib_HysDeb_12(dt_Temp_u8p0bn40 rtu_lb_genInp, dt_Temp_u8p0bn40
  rtu_lb_genUpLim, dt_Temp_u8p0bn40 rtu_lb_genLowLim, uint16 rtu_lb_cntSetConf,
  uint16 rtu_lb_cntRsetConf, boolean rtu_lb_bolSet, boolean rtu_lb_bolRset,
  boolean *rty_lb_bolDebOutp, boolean *rty_lb_bolHiOccOutp, boolean
  *rty_lb_bolLoOccOutp, DW_lib_HysDeb_12_ASW_OBD *localDW)
{
  boolean rtb_lb_genOutp_ftg2;
  boolean rtb_lb_genOutp_pzt3;

  /* RelationalOperator: '<S181>/Relational Operator' */
  *rty_lb_bolLoOccOutp = (rtu_lb_genInp < rtu_lb_genLowLim);

  /* Chart: '<S181>/sfc_Debounce1' */
  ASW_OBD_sfc_Debounce(*rty_lb_bolLoOccOutp, rtu_lb_cntRsetConf,
                       &rtb_lb_genOutp_ftg2, &localDW->sf_sfc_Debounce1);

  /* RelationalOperator: '<S181>/Relational Operator1' */
  *rty_lb_bolHiOccOutp = (rtu_lb_genInp > rtu_lb_genUpLim);

  /* Chart: '<S181>/sfc_Debounce' */
  ASW_OBD_sfc_Debounce(*rty_lb_bolHiOccOutp, rtu_lb_cntSetConf,
                       &rtb_lb_genOutp_pzt3, &localDW->sf_sfc_Debounce);

  /* Switch: '<S181>/Switch1' incorporates:
   *  Switch: '<S181>/Switch'
   *  UnitDelay: '<S181>/Unit Delay2'
   */
  if (rtb_lb_genOutp_pzt3) {
    *rty_lb_bolDebOutp = rtu_lb_bolSet;
  } else if (rtb_lb_genOutp_ftg2) {
    /* Switch: '<S181>/Switch' */
    *rty_lb_bolDebOutp = rtu_lb_bolRset;
  } else {
    *rty_lb_bolDebOutp = localDW->bitsForTID1.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S181>/Switch1' */

  /* Update for UnitDelay: '<S181>/Unit Delay2' */
  localDW->bitsForTID1.UnitDelay2_DSTATE = *rty_lb_bolDebOutp;
}

/*
 * System initialize for atomic system:
 *    '<S230>/lib_FaltDefd_14'
 *    '<S230>/lib_FaltDefd_15'
 */
void ASW_OBD_lib_FaltDefd_14_Init(boolean *rty_stFaltDef_Tmpr, boolean
  *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt, DW_lib_FaltDefd_14_ASW_OBD
  *localDW)
{
  /* SystemInitialize for Chart: '<S232>/sfc_FaultDefiniteness' */
  ASW__sfc_FaultDefiniteness_Init(rty_stFaltDef_Tmpr, rty_stFaltDef_Perm,
    rty_FaltCycAccCnt, &localDW->sf_sfc_FaultDefiniteness);
}

/*
 * Output and update for atomic system:
 *    '<S230>/lib_FaltDefd_14'
 *    '<S230>/lib_FaltDefd_15'
 */
void ASW_OBD_lib_FaltDefd_14(boolean rtu_stFaltDeb, boolean rtu_bolFaltEnFlg,
  uint8 rtu_stFaltCycDiaCnt, boolean rtu_bolFaltRecEnFlag, boolean
  *rty_stFaltDef_Tmpr, boolean *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt,
  uint16 rtp_lb_FaltWaitRecvCnt, DW_lib_FaltDefd_14_ASW_OBD *localDW)
{
  /* Chart: '<S232>/sfc_FaultDefiniteness' */
  ASW_OBD_sfc_FaultDefiniteness(rtu_stFaltDeb, rtu_bolFaltEnFlg,
    rtu_stFaltCycDiaCnt, rtu_bolFaltRecEnFlag, rty_stFaltDef_Tmpr,
    rty_stFaltDef_Perm, rty_FaltCycAccCnt, rtp_lb_FaltWaitRecvCnt,
    &localDW->sf_sfc_FaultDefiniteness);
}

/*
 * System initialize for atomic system:
 *    '<S243>/lib_Deb_12'
 *    '<S243>/lib_Deb_13'
 */
void ASW_OBD_lib_Deb_12_Init(boolean *rty_lb_genOutp, DW_lib_Deb_12_ASW_OBD
  *localDW)
{
  /* SystemInitialize for Chart: '<S245>/sfc_FaultDebounce' */
  ASW_OBD_sfc_FaultDebounce_Init(rty_lb_genOutp, &localDW->sf_sfc_FaultDebounce);
}

/*
 * Output and update for atomic system:
 *    '<S243>/lib_Deb_12'
 *    '<S243>/lib_Deb_13'
 */
boolean ASW_OBD_lib_Deb_12(boolean rtu_lb_bolInp, uint16 rtu_lb_cntDebConf,
  uint16 rtu_lb_cntDebRcvy, DW_lib_Deb_12_ASW_OBD *localDW)
{
  boolean rty_lb_genOutp_0;

  /* Chart: '<S245>/sfc_FaultDebounce' */
  ASW_OBD_sfc_FaultDebounce(rtu_lb_bolInp, rtu_lb_cntDebConf, rtu_lb_cntDebRcvy,
    &rty_lb_genOutp_0, &localDW->sf_sfc_FaultDebounce);
  return rty_lb_genOutp_0;
}

/* Output and update for iterator system: '<S279>/sss_FaltEnFlgConf' */
void ASW_OBD_sss_FaltEnFlgConf(void)
{
  sint32 i;
  uint8 s281_iter;
  boolean tmp[30];

  /* Outputs for Iterator SubSystem: '<S279>/sss_FaltEnFlgConf' incorporates:
   *  ForIterator: '<S281>/For Iterator'
   */
  /* SignalConversion generated from: '<S281>/Selector1' incorporates:
   *  Constant: '<S282>/Constant1'
   *  Constant: '<S289>/bolSplVltgLoLvl4EnFlag_C'
   *  Constant: '<S289>/bolSplVltgLoLvl4EnFlag_C1'
   *  Constant: '<S290>/Constant'
   *  Constant: '<S290>/Constant1'
   */
  tmp[0] = ASW_OBD_B.bitsForTID1.LogicalOperator3;
  tmp[1] = ASW_OBD_B.bitsForTID1.LogicalOperator1;
  tmp[2] = ASW_OBD_B.bitsForTID1.LogicalOperator5;
  tmp[3] = true;
  tmp[4] = true;
  tmp[5] = ASW_OBD_B.bitsForTID1.LogicalOperator8;
  tmp[6] = ASW_OBD_B.bitsForTID1.LogicalOperator3_k1jc;
  tmp[7] = ASW_OBD_B.bitsForTID1.LogicalOperator9;
  tmp[8] = ASW_OBD_B.bitsForTID1.LogicalOperator5_opu4;
  tmp[9] = ASW_OBD_B.bitsForTID1.LogicalOperator11;
  tmp[10] = ASW_OBD_B.bitsForTID1.LogicalOperator3_lgwh;
  tmp[11] = ASW_OBD_B.bitsForTID1.LogicalOperator3_lgwh;
  tmp[12] = ASW_OBD_B.bitsForTID1.LogicalOperator5_oi54;
  tmp[13] = ASW_OBD_B.bitsForTID1.LogicalOperator8_eron;
  tmp[14] = ASW_OBD_B.bitsForTID1.LogicalOperator3_mlkr;
  tmp[15] = ASW_OBD_B.bitsForTID1.LogicalOperator4;
  tmp[16] = true;
  tmp[17] = true;
  tmp[18] = true;
  tmp[19] = true;
  tmp[20] = ASW_OBD_B.bitsForTID1.LogicalOperator1;
  tmp[21] = ASW_OBD_B.bitsForTID1.LogicalOperator1;
  tmp[22] = ASW_OBD_B.bitsForTID1.LogicalOperator1;
  tmp[23] = ASW_OBD_B.bitsForTID1.LogicalOperator1;
  tmp[24] = ASW_OBD_B.bitsForTID1.LogicalOperator1;
  tmp[25] = true;
  tmp[26] = true;
  tmp[27] = ASW_OBD_B.bitsForTID1.LogicalOperator1;
  tmp[28] = false;
  tmp[29] = false;
  for (s281_iter = 1; s281_iter < 31; s281_iter++) {
    /* Assignment: '<S281>/Assignment' incorporates:
     *  Logic: '<S281>/Logical Operator'
     *  Selector: '<S281>/Selector'
     *  Selector: '<S281>/Selector1'
     */
    if (s281_iter == 1) {
      for (i = 0; i < 30; i++) {
        ASW_OBD_B.Assignment_al4c[i] = false;
      }
    }

    ASW_OBD_B.Assignment_al4c[s281_iter - 1] =
      ((ASW_OBD_B.DataTypeConversion2[s281_iter - 1]) && (tmp[s281_iter - 1]));

    /* End of Assignment: '<S281>/Assignment' */
  }

  /* End of Outputs for SubSystem: '<S279>/sss_FaltEnFlgConf' */
}

/* System initialize for atomic system: '<Root>/OBD_SlwTask' */
void OBD_SlwTask_Init(void)
{
  boolean rtb_stFaltDef_Perm_b0pb;
  boolean rtb_stFaltDef_Tmpr_mcdl;

  /* InitializeConditions for UnitDelay: '<S100>/Unit Delay' */
  ASW_OBD_DW.UnitDelay_DSTATE_aj4e = 1U;

  /* InitializeConditions for UnitDelay: '<S99>/Unit Delay' */
  ASW_OBD_DW.UnitDelay_DSTATE_e34g = 1U;

  /* InitializeConditions for UnitDelay: '<S98>/Unit Delay' */
  ASW_OBD_DW.UnitDelay_DSTATE_c13u = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_BattPwrHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S35>/ens_JudgDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S36>/lib_Deb_11' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_hlnt, &ASW_OBD_DW.lib_Deb_11);

  /* End of SystemInitialize for SubSystem: '<S36>/lib_Deb_11' */
  /* End of SystemInitialize for SubSystem: '<S35>/ens_JudgDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S35>/lib_FaltDefd_21' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_lhdo,
    &ASW_OBD_B.stFaltDef_Perm_iopf, &ASW_OBD_B.FaltCycAccCnt_if4y,
    &ASW_OBD_DW.lib_FaltDefd_21);

  /* End of SystemInitialize for SubSystem: '<S35>/lib_FaltDefd_21' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_BattPwrHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_BusOffFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S42>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S43>/lib_Deb_4' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_euom, &ASW_OBD_DW.lib_Deb_4);

  /* End of SystemInitialize for SubSystem: '<S43>/lib_Deb_4' */
  /* End of SystemInitialize for SubSystem: '<S42>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S42>/lib_FaltDefd_12' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_m0mb,
    &ASW_OBD_B.stFaltDef_Perm_nx2u, &ASW_OBD_B.FaltCycAccCnt_ozl3,
    &ASW_OBD_DW.lib_FaltDefd_12);

  /* End of SystemInitialize for SubSystem: '<S42>/lib_FaltDefd_12' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_BusOffFaltDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_CRASHFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S48>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S49>/lib_Deb_17' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_gufh, &ASW_OBD_DW.lib_Deb_17);

  /* End of SystemInitialize for SubSystem: '<S49>/lib_Deb_17' */
  /* End of SystemInitialize for SubSystem: '<S48>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S48>/lib_FaltDefd_9' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_nqix,
    &ASW_OBD_B.stFaltDef_Perm_bpps, &ASW_OBD_B.FaltCycAccCnt_okl0,
    &ASW_OBD_DW.lib_FaltDefd_9);

  /* End of SystemInitialize for SubSystem: '<S48>/lib_FaltDefd_9' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_CRASHFaltDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_ChipFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S54>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S55>/lib_Deb_1' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_j4ya, &ASW_OBD_DW.lib_Deb_1);

  /* End of SystemInitialize for SubSystem: '<S55>/lib_Deb_1' */
  /* End of SystemInitialize for SubSystem: '<S54>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S54>/lib_FaltDefd_9' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_cbrr,
    &ASW_OBD_B.stFaltDef_Perm_mvmh, &ASW_OBD_B.FaltCycAccCnt_be2m,
    &ASW_OBD_DW.lib_FaltDefd_9_drq2);

  /* End of SystemInitialize for SubSystem: '<S54>/lib_FaltDefd_9' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_ChipFaltDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_ComFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S61>/ens_HysDeb_GEELY' */
  /* SystemInitialize for Atomic SubSystem: '<S63>/lib_Deb_5' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_eatq, &ASW_OBD_DW.lib_Deb_5);

  /* End of SystemInitialize for SubSystem: '<S63>/lib_Deb_5' */

  /* SystemInitialize for Atomic SubSystem: '<S63>/lib_Deb_6' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_lgdu, &ASW_OBD_DW.lib_Deb_6);

  /* End of SystemInitialize for SubSystem: '<S63>/lib_Deb_6' */

  /* SystemInitialize for Atomic SubSystem: '<S63>/lib_Deb_7' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_ojfd, &ASW_OBD_DW.lib_Deb_7);

  /* End of SystemInitialize for SubSystem: '<S63>/lib_Deb_7' */
  /* End of SystemInitialize for SubSystem: '<S61>/ens_HysDeb_GEELY' */

  /* SystemInitialize for Atomic SubSystem: '<S60>/lib_FaltDefd_18' */
  /* SystemInitialize for Chart: '<S62>/sfc_FaultDefiniteness' */
  ASW_OBD_DW.is_EnableDiagnosis = IN_NO_ACTIVE_CHILD_lvm4;
  ASW_OBD_DW.is_active_c2_swiWcj04KqK1cujXcW = 0U;
  ASW_OBD_DW.is_c2_swiWcj04KqK1cujXcWFuKxE_l = IN_NO_ACTIVE_CHILD_lvm4;
  ASW_OBD_DW.FaltWaitRecvCnt = 0U;
  ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = false;
  ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = false;
  ASW_OBD_B.FaltCycAccCnt_nakw = 0U;

  /* End of SystemInitialize for SubSystem: '<S60>/lib_FaltDefd_18' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_ComFaltDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_CtlBrdVltgHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S78>/ens_Deb' */
  /* SystemInitialize for Atomic SubSystem: '<S79>/lib_HysDeb_1' */
  ASW_OBD_lib_HysDeb_1_Init(false, &ASW_OBD_DW.lib_HysDeb_1);

  /* End of SystemInitialize for SubSystem: '<S79>/lib_HysDeb_1' */
  /* End of SystemInitialize for SubSystem: '<S78>/ens_Deb' */

  /* SystemInitialize for Atomic SubSystem: '<S78>/lib_FaltDefd_1' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_b1sa,
    &ASW_OBD_B.stFaltDef_Perm_ofvs, &ASW_OBD_B.FaltCycAccCnt_da1w,
    &ASW_OBD_DW.lib_FaltDefd_1);

  /* End of SystemInitialize for SubSystem: '<S78>/lib_FaltDefd_1' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_CtlBrdVltgHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_CtlBrdVltgLoLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S85>/ens_Deb' */
  /* SystemInitialize for Atomic SubSystem: '<S86>/lib_HysDeb_0' */
  ASW_OBD_lib_HysDeb_1_Init(false, &ASW_OBD_DW.lib_HysDeb_0);

  /* End of SystemInitialize for SubSystem: '<S86>/lib_HysDeb_0' */
  /* End of SystemInitialize for SubSystem: '<S85>/ens_Deb' */

  /* SystemInitialize for Atomic SubSystem: '<S85>/lib_FaltDefd_0' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_bk0g,
    &ASW_OBD_B.stFaltDef_Perm_nbju, &ASW_OBD_B.FaltCycAccCnt_kbad,
    &ASW_OBD_DW.lib_FaltDefd_0);

  /* End of SystemInitialize for SubSystem: '<S85>/lib_FaltDefd_0' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_CtlBrdVltgLoLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_PhCurrHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S206>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S207>/lib_HysDeb_2' */
  ASW_OBD_lib_HysDeb_14_Init(false, &ASW_OBD_DW.lib_HysDeb_2);

  /* End of SystemInitialize for SubSystem: '<S207>/lib_HysDeb_2' */
  /* End of SystemInitialize for SubSystem: '<S206>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S206>/lib_FaltDefd_2' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_glyd,
    &ASW_OBD_B.stFaltDef_Perm_lijp, &ASW_OBD_B.FaltCycAccCnt_psnz,
    &ASW_OBD_DW.lib_FaltDefd_2);

  /* End of SystemInitialize for SubSystem: '<S206>/lib_FaltDefd_2' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_PhCurrHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_HWOvrCurrDia' */
  /* SystemInitialize for Enabled SubSystem: '<S149>/ens_Deb_0' */
  /* SystemInitialize for Atomic SubSystem: '<S150>/lib_Deb_0' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_neqw, &ASW_OBD_DW.lib_Deb_0);

  /* End of SystemInitialize for SubSystem: '<S150>/lib_Deb_0' */
  /* End of SystemInitialize for SubSystem: '<S149>/ens_Deb_0' */

  /* SystemInitialize for Atomic SubSystem: '<S149>/lib_FaltDefd_3' */
  /* SystemInitialize for Chart: '<S151>/sfc_FaultDefiniteness' */
  ASW__sfc_FaultDefiniteness_Init(&rtb_stFaltDef_Tmpr_mcdl,
    &ASW_OBD_B.stFaltDef_Perm_dzb0, &ASW_OBD_B.FaltCycAccCnt_gwiq,
    &ASW_OBD_DW.sf_sfc_FaultDefiniteness_fvae);

  /* End of SystemInitialize for SubSystem: '<S149>/lib_FaltDefd_3' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_HWOvrCurrDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_SplyVltgLoLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S265>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S266>/lib_HysDeb_3' */
  ASW_OBD_lib_HysDeb_1_Init(false, &ASW_OBD_DW.lib_HysDeb_3);

  /* End of SystemInitialize for SubSystem: '<S266>/lib_HysDeb_3' */
  /* End of SystemInitialize for SubSystem: '<S265>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S265>/lib_FaltDefd_4' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_lgzj,
    &ASW_OBD_B.stFaltDef_Perm_ktdp, &ASW_OBD_B.FaltCycAccCnt_akrv,
    &ASW_OBD_DW.lib_FaltDefd_4);

  /* End of SystemInitialize for SubSystem: '<S265>/lib_FaltDefd_4' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_SplyVltgLoLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_SplyVltgLoLvl2Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S272>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S273>/lib_HysDeb_4' */
  ASW_OBD_lib_HysDeb_1_Init(false, &ASW_OBD_DW.lib_HysDeb_4);

  /* End of SystemInitialize for SubSystem: '<S273>/lib_HysDeb_4' */
  /* End of SystemInitialize for SubSystem: '<S272>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S272>/lib_FaltDefd_5' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_o3sb,
    &ASW_OBD_B.stFaltDef_Perm_efmb, &ASW_OBD_B.FaltCycAccCnt_e00n,
    &ASW_OBD_DW.lib_FaltDefd_5);

  /* End of SystemInitialize for SubSystem: '<S272>/lib_FaltDefd_5' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_SplyVltgLoLvl2Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_SplyVltgHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S258>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S259>/lib_HysDeb_5' */
  ASW_OBD_lib_HysDeb_1_Init(false, &ASW_OBD_DW.lib_HysDeb_5);

  /* End of SystemInitialize for SubSystem: '<S259>/lib_HysDeb_5' */
  /* End of SystemInitialize for SubSystem: '<S258>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S258>/lib_FaltDefd_6' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_ni5x,
    &ASW_OBD_B.stFaltDef_Perm_f4wg, &ASW_OBD_B.FaltCycAccCnt_eksn,
    &ASW_OBD_DW.lib_FaltDefd_6);

  /* End of SystemInitialize for SubSystem: '<S258>/lib_FaltDefd_6' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_SplyVltgHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S220>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S221>/lib_HysDeb_9' */
  ASW_OBD_lib_HysDeb_12_Init(false, &ASW_OBD_DW.lib_HysDeb_9);

  /* End of SystemInitialize for SubSystem: '<S221>/lib_HysDeb_9' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/lib_HysDeb_8' */
  ASW_OBD_lib_HysDeb_12_Init(false, &ASW_OBD_DW.lib_HysDeb_8);

  /* End of SystemInitialize for SubSystem: '<S221>/lib_HysDeb_8' */
  /* End of SystemInitialize for SubSystem: '<S220>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S220>/lib_FaltDefd_13' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_mpvn,
    &ASW_OBD_B.stFaltDef_Perm_dthc, &ASW_OBD_B.FaltCycAccCnt_k5ca,
    &ASW_OBD_DW.lib_FaltDefd_13);

  /* End of SystemInitialize for SubSystem: '<S220>/lib_FaltDefd_13' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl2Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S230>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S231>/lib_HysDeb_10' */
  ASW_OBD_lib_HysDeb_12_Init(false, &ASW_OBD_DW.lib_HysDeb_10);

  /* End of SystemInitialize for SubSystem: '<S231>/lib_HysDeb_10' */

  /* SystemInitialize for Atomic SubSystem: '<S231>/lib_HysDeb_11' */
  ASW_OBD_lib_HysDeb_12_Init(false, &ASW_OBD_DW.lib_HysDeb_11);

  /* End of SystemInitialize for SubSystem: '<S231>/lib_HysDeb_11' */
  /* End of SystemInitialize for SubSystem: '<S230>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S230>/lib_FaltDefd_14' */
  ASW_OBD_lib_FaltDefd_14_Init(&rtb_stFaltDef_Tmpr_mcdl,
    &rtb_stFaltDef_Perm_b0pb, &ASW_OBD_B.FaltCycAccCnt_lwpi,
    &ASW_OBD_DW.lib_FaltDefd_14);

  /* End of SystemInitialize for SubSystem: '<S230>/lib_FaltDefd_14' */

  /* SystemInitialize for Atomic SubSystem: '<S230>/lib_FaltDefd_15' */
  ASW_OBD_lib_FaltDefd_14_Init(&rtb_stFaltDef_Tmpr_mcdl,
    &rtb_stFaltDef_Perm_b0pb, &ASW_OBD_B.FaltCycAccCnt_mbzj,
    &ASW_OBD_DW.lib_FaltDefd_15);

  /* End of SystemInitialize for SubSystem: '<S230>/lib_FaltDefd_15' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl2Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_MotoTempHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S178>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S179>/lib_HysDeb_12' */
  ASW_OBD_lib_HysDeb_12_Init(false, &ASW_OBD_DW.lib_HysDeb_12);

  /* End of SystemInitialize for SubSystem: '<S179>/lib_HysDeb_12' */
  /* End of SystemInitialize for SubSystem: '<S178>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S178>/lib_FaltDefd_16' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_pjcw,
    &ASW_OBD_B.stFaltDef_Perm_h1g3, &ASW_OBD_B.FaltCycAccCnt_fxmn,
    &ASW_OBD_DW.lib_FaltDefd_16);

  /* End of SystemInitialize for SubSystem: '<S178>/lib_FaltDefd_16' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_MotoTempHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_MotoTempHiLvl2Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S185>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S186>/lib_HysDeb_13' */
  ASW_OBD_lib_HysDeb_12_Init(false, &ASW_OBD_DW.lib_HysDeb_13);

  /* End of SystemInitialize for SubSystem: '<S186>/lib_HysDeb_13' */
  /* End of SystemInitialize for SubSystem: '<S185>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S185>/lib_FaltDefd_17' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_izjl,
    &ASW_OBD_B.stFaltDef_Perm_b5ga, &ASW_OBD_B.FaltCycAccCnt_mn3a,
    &ASW_OBD_DW.lib_FaltDefd_17);

  /* End of SystemInitialize for SubSystem: '<S185>/lib_FaltDefd_17' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_MotoTempHiLvl2Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S31>/rss_MotoStallDiaHybr' */
  /* SystemInitialize for Enabled SubSystem: '<S292>/ens_JudgDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S293>/lib_Deb_9' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_hfik, &ASW_OBD_DW.lib_Deb_9);

  /* End of SystemInitialize for SubSystem: '<S293>/lib_Deb_9' */
  /* End of SystemInitialize for SubSystem: '<S292>/ens_JudgDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S292>/lib_FaltDefd_19' */
  /* SystemInitialize for Chart: '<S294>/sfc_FaultDefiniteness' */
  ASW__sfc_FaultDefiniteness_Init(&ASW_OBD_B.stFaltDef_Tmpr_gjm2,
    &ASW_OBD_B.stFaltDef_Perm_g4b1, &ASW_OBD_B.FaltCycAccCnt_advj,
    &ASW_OBD_DW.sf_sfc_FaultDefiniteness_et5q);

  /* End of SystemInitialize for SubSystem: '<S292>/lib_FaltDefd_19' */
  /* End of SystemInitialize for SubSystem: '<S31>/rss_MotoStallDiaHybr' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_NoLdDia' */
  /* SystemInitialize for Enabled SubSystem: '<S199>/ens_JudgDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S200>/lib_Deb_10' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_hhu4, &ASW_OBD_DW.lib_Deb_10);

  /* End of SystemInitialize for SubSystem: '<S200>/lib_Deb_10' */
  /* End of SystemInitialize for SubSystem: '<S199>/ens_JudgDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S199>/lib_FaltDefd_20' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_cp2o,
    &ASW_OBD_B.stFaltDef_Perm_kt5c, &ASW_OBD_B.FaltCycAccCnt_fh1w,
    &ASW_OBD_DW.lib_FaltDefd_20);

  /* End of SystemInitialize for SubSystem: '<S199>/lib_FaltDefd_20' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_NoLdDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_MotoSpdHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S161>/ens_Deb' */
  /* SystemInitialize for Atomic SubSystem: '<S162>/lib_HysDeb_14' */
  ASW_OBD_lib_HysDeb_14_Init(false, &ASW_OBD_DW.lib_HysDeb_14);

  /* End of SystemInitialize for SubSystem: '<S162>/lib_HysDeb_14' */
  /* End of SystemInitialize for SubSystem: '<S161>/ens_Deb' */

  /* SystemInitialize for Atomic SubSystem: '<S161>/lib_FaltDefd_22' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_nmp1,
    &ASW_OBD_B.stFaltDef_Perm_naf3, &ASW_OBD_B.FaltCycAccCnt_beqh,
    &ASW_OBD_DW.lib_FaltDefd_22);

  /* End of SystemInitialize for SubSystem: '<S161>/lib_FaltDefd_22' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_MotoSpdHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_MotoSpdLoLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S168>/ens_JudgDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S169>/lib_HysDeb_15' */
  /* SystemInitialize for Chart: '<S174>/sfc_Debounce1' */
  ASW_OBD_sfc_Debounce_Init(&rtb_stFaltDef_Tmpr_mcdl,
    &ASW_OBD_DW.sf_sfc_Debounce1);

  /* SystemInitialize for Chart: '<S174>/sfc_Debounce' */
  ASW_OBD_sfc_Debounce_Init(&rtb_stFaltDef_Tmpr_mcdl,
    &ASW_OBD_DW.sf_sfc_Debounce);

  /* End of SystemInitialize for SubSystem: '<S169>/lib_HysDeb_15' */
  /* End of SystemInitialize for SubSystem: '<S168>/ens_JudgDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S168>/lib_FaltDefd_23' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_j3ha,
    &ASW_OBD_B.stFaltDef_Perm_ilgb, &ASW_OBD_B.FaltCycAccCnt_fd2e,
    &ASW_OBD_DW.lib_FaltDefd_23);

  /* End of SystemInitialize for SubSystem: '<S168>/lib_FaltDefd_23' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_MotoSpdLoLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_GDVltgLoLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S143>/ens_Deb_GEELY' */
  /* SystemInitialize for Atomic SubSystem: '<S145>/lib_Deb_15' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_j4vj, &ASW_OBD_DW.lib_Deb_15);

  /* End of SystemInitialize for SubSystem: '<S145>/lib_Deb_15' */
  /* End of SystemInitialize for SubSystem: '<S143>/ens_Deb_GEELY' */

  /* SystemInitialize for Atomic SubSystem: '<S142>/lib_FaltDefd_7' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_hsig,
    &ASW_OBD_B.stFaltDef_Perm_g0ii, &ASW_OBD_B.FaltCycAccCnt_ei2t,
    &ASW_OBD_DW.lib_FaltDefd_7);

  /* End of SystemInitialize for SubSystem: '<S142>/lib_FaltDefd_7' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_GDVltgLoLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_GDVltgHiLvl1Dia' */
  /* SystemInitialize for Enabled SubSystem: '<S136>/ens_Deb_GEELY' */
  /* SystemInitialize for Atomic SubSystem: '<S138>/lib_Deb_16' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_hynf, &ASW_OBD_DW.lib_Deb_16);

  /* End of SystemInitialize for SubSystem: '<S138>/lib_Deb_16' */
  /* End of SystemInitialize for SubSystem: '<S136>/ens_Deb_GEELY' */

  /* SystemInitialize for Atomic SubSystem: '<S135>/lib_FaltDefd_8' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_im4y,
    &ASW_OBD_B.stFaltDef_Perm_dgcc, &ASW_OBD_B.FaltCycAccCnt_et1a,
    &ASW_OBD_DW.lib_FaltDefd_8);

  /* End of SystemInitialize for SubSystem: '<S135>/lib_FaltDefd_8' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_GDVltgHiLvl1Dia' */

  /* SystemInitialize for Enabled SubSystem: '<S32>/rss_PhiSensFaltDiaHybr' */
  /* SystemInitialize for Enabled SubSystem: '<S301>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S303>/lib_Deb_2' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp, &ASW_OBD_DW.lib_Deb_2);

  /* End of SystemInitialize for SubSystem: '<S303>/lib_Deb_2' */
  /* End of SystemInitialize for SubSystem: '<S301>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S301>/lib_FaltDefd_10' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr,
    &ASW_OBD_B.stFaltDef_Perm, &ASW_OBD_B.FaltCycAccCnt,
    &ASW_OBD_DW.lib_FaltDefd_10);

  /* End of SystemInitialize for SubSystem: '<S301>/lib_FaltDefd_10' */
  /* End of SystemInitialize for SubSystem: '<S32>/rss_PhiSensFaltDiaHybr' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_PhCurrSensFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S213>/ens_JudgDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S214>/lib_Deb_3' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_gw2t, &ASW_OBD_DW.lib_Deb_3);

  /* End of SystemInitialize for SubSystem: '<S214>/lib_Deb_3' */
  /* End of SystemInitialize for SubSystem: '<S213>/ens_JudgDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S213>/lib_FaltDefd_11' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_ics0,
    &ASW_OBD_B.stFaltDef_Perm_omzh, &ASW_OBD_B.FaltCycAccCnt_buyv,
    &ASW_OBD_DW.lib_FaltDefd_11);

  /* End of SystemInitialize for SubSystem: '<S213>/lib_FaltDefd_11' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_PhCurrSensFaltDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_PwrTubPCBTempSensFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S242>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S243>/lib_Deb_12' */
  ASW_OBD_lib_Deb_12_Init(&rtb_stFaltDef_Tmpr_mcdl, &ASW_OBD_DW.lib_Deb_12);

  /* End of SystemInitialize for SubSystem: '<S243>/lib_Deb_12' */

  /* SystemInitialize for Atomic SubSystem: '<S243>/lib_Deb_13' */
  ASW_OBD_lib_Deb_12_Init(&rtb_stFaltDef_Tmpr_mcdl, &ASW_OBD_DW.lib_Deb_13);

  /* End of SystemInitialize for SubSystem: '<S243>/lib_Deb_13' */
  /* End of SystemInitialize for SubSystem: '<S242>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S242>/lib_FaltDefd_24' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_keux,
    &ASW_OBD_B.stFaltDef_Perm_i2o3, &ASW_OBD_B.FaltCycAccCnt_kent,
    &ASW_OBD_DW.lib_FaltDefd_24);

  /* End of SystemInitialize for SubSystem: '<S242>/lib_FaltDefd_24' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_PwrTubPCBTempSensFaltDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_MotoTempSensFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S192>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S193>/lib_Deb_14' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_f0nq, &ASW_OBD_DW.lib_Deb_14);

  /* End of SystemInitialize for SubSystem: '<S193>/lib_Deb_14' */
  /* End of SystemInitialize for SubSystem: '<S192>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S192>/lib_FaltDefd_25' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_dr1m,
    &ASW_OBD_B.stFaltDef_Perm_cm35, &ASW_OBD_B.FaltCycAccCnt_ibsm,
    &ASW_OBD_DW.lib_FaltDefd_25);

  /* End of SystemInitialize for SubSystem: '<S192>/lib_FaltDefd_25' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_MotoTempSensFaltDia' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/rss_MosOpnCirFaltDia' */
  /* SystemInitialize for Enabled SubSystem: '<S155>/ens_HysDeb' */
  /* SystemInitialize for Atomic SubSystem: '<S156>/lib_Deb_17' */
  ASW_OBD_lib_Deb_11_Init(&ASW_OBD_B.lb_genOutp_lsbp,
    &ASW_OBD_DW.lib_Deb_17_erkz);

  /* End of SystemInitialize for SubSystem: '<S156>/lib_Deb_17' */
  /* End of SystemInitialize for SubSystem: '<S155>/ens_HysDeb' */

  /* SystemInitialize for Atomic SubSystem: '<S155>/lib_FaltDefd_9' */
  ASW_OBD_lib_FaltDefd_21_Init(&ASW_OBD_B.stFaltDef_Tmpr_otno,
    &ASW_OBD_B.stFaltDef_Perm_gulm, &ASW_OBD_B.FaltCycAccCnt_jfr4,
    &ASW_OBD_DW.lib_FaltDefd_9_hcdo);

  /* End of SystemInitialize for SubSystem: '<S155>/lib_FaltDefd_9' */
  /* End of SystemInitialize for SubSystem: '<S1>/rss_MosOpnCirFaltDia' */
}

/* Output and update for atomic system: '<Root>/OBD_SlwTask' */
void OBD_SlwTask(void)
{
  sint32 i;
  dt_Standardize_s16p15b0 rtb_Saturation;
  dt_Standardize_s16p15b0 rtb_Saturation1_fxo0;
  dt_Standardize_s16p15b0 rtb_Saturation1_h5iq;
  dt_Standardize_s16p15b0 rtb_Saturation1_kizi;
  dt_Standardize_s16p15b0 rtb_Saturation1_kx2o;
  dt_Standardize_s16p15b0 rtb_Saturation2;
  dt_Standardize_s16p15b0 rtb_Saturation2_nleq;
  dt_Standardize_s16p15b0 rtb_Saturation3;
  dt_Standardize_s16p15b0 rtb_Switch_kftc_idx_0;
  dt_Standardize_s16p15b0 rtb_Switch_kftc_idx_1;
  sint16 minV;
  sint16 rtb_Subtract;
  uint16 Gu16_stCtlDFPMSt_C_0;
  uint8 rtb_DataTypeConversion[30];
  uint8 maxV;
  uint8 rtb_Selector1_eamb;
  uint8 rtb_Selector1_eapz;
  uint8 u1;
  boolean rtb_DataTypeConversion1[30];
  boolean rtb_Switch[30];
  boolean LogicalOperator3_lgwh_tmp;
  boolean LogicalOperator8_tmp;
  boolean LogicalOperator8_tmp_tmp;
  boolean rtb_Equal_c0gx;
  boolean rtb_Equal_cipx;
  boolean rtb_Equal_kjhq;
  boolean rtb_LogicalOperator1_cf41;
  boolean rtb_LogicalOperator3;
  boolean rtb_LogicalOperator_dizb;
  boolean rtb_LogicalOperator_gvnr;
  boolean rtb_LogicalOperator_inut;
  boolean rtb_RelationalOperator1_a4nw;
  boolean rtb_RelationalOperator1_abb3;
  boolean rtb_RelationalOperator1_ane1;
  boolean rtb_RelationalOperator1_bp1h;
  boolean rtb_RelationalOperator1_ie3s;
  boolean rtb_RelationalOperator1_jje1;
  boolean rtb_RelationalOperator1_kgxf;
  boolean rtb_RelationalOperator1_khcq;
  boolean rtb_RelationalOperator1_lt3z;
  boolean rtb_RelationalOperator1_nbm1;
  boolean rtb_RelationalOperator1_pgfr;
  boolean rtb_RelationalOperator_b3c5;
  boolean rtb_RelationalOperator_dqxp;
  boolean rtb_RelationalOperator_ea1p;
  boolean rtb_RelationalOperator_eiez;
  boolean rtb_RelationalOperator_gvkq;
  boolean rtb_RelationalOperator_h0it;
  boolean rtb_RelationalOperator_hcyg;
  boolean rtb_RelationalOperator_j4m1;
  boolean rtb_RelationalOperator_jtyy;
  boolean rtb_RelationalOperator_klm3;
  boolean rtb_RelationalOperator_oulp;
  boolean rtb_RelationalOperator_p3rt;
  boolean rtb_Selector1_ikyn;
  boolean rtb_Selector2_aoef;
  boolean rtb_Selector2_bj1k;
  boolean rtb_Selector2_bvc0;
  boolean rtb_Selector2_c5tw;
  boolean rtb_Selector2_d5ob;
  boolean rtb_Selector2_e1kw;
  boolean rtb_Selector2_f4jl;
  boolean rtb_Selector2_ghqr;
  boolean rtb_Selector2_gpod;
  boolean rtb_Selector2_h3x4;
  boolean rtb_Selector2_hi2t;
  boolean rtb_Selector2_ko2p;
  boolean rtb_Selector2_l3ro;
  boolean rtb_Selector2_lezv;
  boolean rtb_Selector2_mad0;
  boolean rtb_Selector2_mbkm;
  boolean rtb_Selector2_mqxc;
  boolean rtb_Selector2_mxk4;
  boolean rtb_Selector2_orvk;
  boolean rtb_Selector2_p3oh;
  boolean rtb_Selector2_p415;
  boolean rtb_Selector2_p5mv;
  boolean rtb_Selector2_pigy;
  boolean rtb_Selector4_eljz;
  boolean rtb_Selector6;
  boolean rtb_Selector7_idtg;
  boolean rtb_Switch1;
  boolean rtb_Switch1_avks;
  boolean rtb_Switch1_cxed;
  boolean rtb_Switch1_e2vj;
  boolean rtb_Switch1_p0m3;
  boolean rtb_Switch1_pesu;
  boolean rtb_Switch_lbqb;
  boolean rtb_bol_flgPhCurrSensFaltOcc;
  boolean rtb_stFaltDef_Perm;
  boolean rtb_stFaltDef_Perm_bryy;
  boolean rtb_stFaltDef_Tmpr;
  boolean rtb_stFaltDef_Tmpr_erdn;

  /* DataTypeConversion: '<S9>/Data Type Conversion2' incorporates:
   *  Constant: '<S9>/Constant4'
   *  DataTypeConversion: '<S94>/Extract Desired Bits'
   */
  for (i = 0; i < 30; i++) {
    ASW_OBD_B.DataTypeConversion2[i] = ((((uint8)(((uint32)Gu16_stCtlDFPMSt_C[(i)])
      >> 3)) & 1U) != 0U);
  }

  /* End of DataTypeConversion: '<S9>/Data Type Conversion2' */

  /* UnitDelay: '<S1>/Unit Delay' */
  rtb_stFaltDef_Tmpr_erdn = ASW_OBD_DW.UnitDelay_DSTATE.bol_flgPhiSensFaltFlg;
  rtb_stFaltDef_Perm_bryy = ASW_OBD_DW.UnitDelay_DSTATE.bol_flgPhCurrSensFaltFlg;

  /* Logic: '<S285>/Logical Operator1' incorporates:
   *  Logic: '<S285>/Logical Operator'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay generated from: '<S1>/Unit Delay1'
   */
  ASW_OBD_B.bitsForTID1.LogicalOperator1 =
    ((((!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgCtlBrdVltgLoLvl1Flg) &&
       (!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgCtlBrdVltgHiLvl1Flg)) &&
      (!ASW_OBD_DW.bitsForTID1.UnitDelay1_17_DSTATE)) &&
     (!ASW_OBD_DW.bitsForTID1.UnitDelay1_18_DSTATE));

  /* UnitDelay generated from: '<S1>/Unit Delay1' */
  rtb_bol_flgPhCurrSensFaltOcc = ASW_OBD_DW.bitsForTID1.UnitDelay1_23_DSTATE;

  /* Logic: '<S283>/Logical Operator' incorporates:
   *  Logic: '<S290>/Logical Operator'
   *  Logic: '<S290>/Logical Operator2'
   *  Logic: '<S290>/Logical Operator6'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_stFaltDef_Tmpr = !rtb_stFaltDef_Perm_bryy;

  /* Logic: '<S283>/Logical Operator3' incorporates:
   *  Logic: '<S283>/Logical Operator'
   *  Logic: '<S283>/Logical Operator1'
   *  Logic: '<S290>/Logical Operator'
   *  Logic: '<S290>/Logical Operator6'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_stFaltDef_Tmpr = (((ASW_OBD_B.bitsForTID1.LogicalOperator1) &&
    rtb_stFaltDef_Tmpr) && (!rtb_bol_flgPhCurrSensFaltOcc));
  ASW_OBD_B.bitsForTID1.LogicalOperator3 = rtb_stFaltDef_Tmpr;

  /* Logic: '<S289>/Logical Operator5' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ASW_OBD_B.bitsForTID1.LogicalOperator5 =
    !ASW_OBD_DW.UnitDelay_DSTATE.bol_flgSplyVltgLoLvl2Flg;

  /* Logic: '<S288>/Logical Operator1' incorporates:
   *  Logic: '<S287>/Logical Operator1'
   *  Logic: '<S288>/Logical Operator4'
   */
  rtb_stFaltDef_Perm = !ASW_OBD_B.bitsForTID1.LogicalOperator1;
  LogicalOperator8_tmp_tmp = !rtb_stFaltDef_Perm;

  /* Logic: '<S288>/Logical Operator6' incorporates:
   *  Logic: '<S288>/Logical Operator'
   *  Logic: '<S288>/Logical Operator1'
   *  Logic: '<S288>/Logical Operator3'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay generated from: '<S1>/Unit Delay1'
   */
  LogicalOperator8_tmp = ((LogicalOperator8_tmp_tmp &&
    (!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgPwrTubPCBTempSensFaltFlg)) &&
    (!ASW_OBD_DW.bitsForTID1.UnitDelay1_24_DSTATE));

  /* Logic: '<S288>/Logical Operator8' incorporates:
   *  Logic: '<S288>/Logical Operator6'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ASW_OBD_B.bitsForTID1.LogicalOperator8 =
    ((!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgPwrTubPCBTempHiLvl2Flg) &&
     LogicalOperator8_tmp);

  /* Logic: '<S288>/Logical Operator3' */
  ASW_OBD_B.bitsForTID1.LogicalOperator3_k1jc = LogicalOperator8_tmp;

  /* Logic: '<S288>/Logical Operator7' incorporates:
   *  Logic: '<S288>/Logical Operator2'
   *  Logic: '<S288>/Logical Operator5'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay generated from: '<S1>/Unit Delay1'
   */
  LogicalOperator8_tmp = ((LogicalOperator8_tmp_tmp &&
    (!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgMotoTempSensFaltFlg)) &&
    (!ASW_OBD_DW.bitsForTID1.UnitDelay1_25_DSTATE));

  /* Logic: '<S288>/Logical Operator9' incorporates:
   *  Logic: '<S288>/Logical Operator7'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ASW_OBD_B.bitsForTID1.LogicalOperator9 =
    ((!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgMotoTempHiLvl2Flg) &&
     LogicalOperator8_tmp);

  /* Logic: '<S288>/Logical Operator5' */
  ASW_OBD_B.bitsForTID1.LogicalOperator5_opu4 = LogicalOperator8_tmp;

  /* Logic: '<S290>/Logical Operator11' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ASW_OBD_B.bitsForTID1.LogicalOperator11 =
    !ASW_OBD_DW.UnitDelay_DSTATE.bol_flgBusOffFaltFlg;

  /* Logic: '<S290>/Logical Operator' incorporates:
   *  Logic: '<S287>/Logical Operator2'
   *  Logic: '<S290>/Logical Operator2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  LogicalOperator8_tmp = !rtb_stFaltDef_Tmpr_erdn;

  /* UnitDelay generated from: '<S1>/Unit Delay1' */
  LogicalOperator8_tmp_tmp = !ASW_OBD_DW.bitsForTID1.UnitDelay1_22_DSTATE;

  /* Logic: '<S290>/Logical Operator3' incorporates:
   *  Logic: '<S290>/Logical Operator'
   *  Logic: '<S290>/Logical Operator2'
   *  Logic: '<S290>/Logical Operator5'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay generated from: '<S1>/Unit Delay1'
   */
  LogicalOperator3_lgwh_tmp = ((rtb_stFaltDef_Tmpr && LogicalOperator8_tmp) &&
    LogicalOperator8_tmp_tmp);
  ASW_OBD_B.bitsForTID1.LogicalOperator3_lgwh = LogicalOperator3_lgwh_tmp;

  /* Logic: '<S290>/Logical Operator5' */
  ASW_OBD_B.bitsForTID1.LogicalOperator5_oi54 = LogicalOperator3_lgwh_tmp;

  /* Logic: '<S290>/Logical Operator8' incorporates:
   *  Logic: '<S290>/Logical Operator6'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay generated from: '<S1>/Unit Delay1'
   */
  ASW_OBD_B.bitsForTID1.LogicalOperator8_eron = ((rtb_stFaltDef_Tmpr &&
    (!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgSplyVltgHiLvl1Flg)) &&
    (!ASW_OBD_DW.bitsForTID1.UnitDelay1_5_DSTATE));

  /* Logic: '<S287>/Logical Operator' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay generated from: '<S1>/Unit Delay1'
   */
  rtb_LogicalOperator_dizb = ((((rtb_stFaltDef_Perm || rtb_stFaltDef_Perm_bryy) ||
    rtb_bol_flgPhCurrSensFaltOcc) || rtb_stFaltDef_Tmpr_erdn) ||
    (ASW_OBD_DW.bitsForTID1.UnitDelay1_22_DSTATE));

  /* Logic: '<S287>/Logical Operator3' incorporates:
   *  Logic: '<S287>/Logical Operator2'
   */
  rtb_stFaltDef_Tmpr = !rtb_LogicalOperator_dizb;
  ASW_OBD_B.bitsForTID1.LogicalOperator3_mlkr = rtb_stFaltDef_Tmpr;

  /* Logic: '<S287>/Logical Operator4' incorporates:
   *  Logic: '<S287>/Logical Operator2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  ASW_OBD_B.bitsForTID1.LogicalOperator4 = ((((rtb_stFaltDef_Tmpr &&
    LogicalOperator8_tmp) && LogicalOperator8_tmp_tmp) &&
    (!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgMotoStallPermFlg)) &&
    (!ASW_OBD_DW.UnitDelay_DSTATE.bol_flgMotoStallTmpFlg));

  /* Outputs for Iterator SubSystem: '<S279>/sss_FaltEnFlgConf' */
  ASW_OBD_sss_FaltEnFlgConf();

  /* End of Outputs for SubSystem: '<S279>/sss_FaltEnFlgConf' */

  /* Logic: '<S279>/Logical Operator' incorporates:
   *  Constant: '<S279>/Constant1'
   *  Constant: '<S280>/Constant'
   *  Inport: '<Root>/busOBD_SlwTaskIn'
   *  RelationalOperator: '<S280>/Compare'
   */
  rtb_LogicalOperator_gvnr = (((Gbol_flgFaltManEnFlg_C) &&
    (busOBD_SlwTaskIn.enm_stSysSt != SYSINIT)) &&
    (busOBD_SlwTaskIn.bol_flgFaltEnFlgUDS85));
  for (i = 0; i < 30; i++) {
    /* Switch: '<S279>/Switch' */
    if (rtb_LogicalOperator_gvnr) {
      rtb_Switch[i] = ASW_OBD_B.Assignment_al4c[i];
    } else {
      rtb_Switch[i] = false;
    }

    /* End of Switch: '<S279>/Switch' */

    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  Constant: '<S9>/Constant4'
     *  DataTypeConversion: '<S92>/Extract Desired Bits'
     */
    Gu16_stCtlDFPMSt_C_0 = Gu16_stCtlDFPMSt_C[(i)];
    rtb_DataTypeConversion[i] = (uint8)(((uint8)(((uint32)Gu16_stCtlDFPMSt_C_0) >>
      4)) & 15);

    /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
     *  Constant: '<S9>/Constant4'
     *  DataTypeConversion: '<S93>/Extract Desired Bits'
     */
    rtb_DataTypeConversion1[i] = ((((uint8)Gu16_stCtlDFPMSt_C_0) & 1U) != 0U);

    /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
     *  Constant: '<S9>/Constant4'
     *  DataTypeConversion: '<S95>/Extract Desired Bits'
     */
    ASW_OBD_B.DataTypeConversion3[i] = (uint8)(((uint8)(((uint32)
      Gu16_stCtlDFPMSt_C_0) >> 1)) & 3);
  }

  /* RelationalOperator: '<S100>/Equal' incorporates:
   *  Constant: '<S9>/Constant3'
   *  UnitDelay: '<S100>/Unit Delay'
   */
  rtb_Equal_c0gx = (Gu16_ctFaltDiaSlwSdlCnt_C ==
                    ASW_OBD_DW.UnitDelay_DSTATE_aj4e);

  /* Outputs for Enabled SubSystem: '<S1>/rss_BattPwrHiLvl1Dia' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtb_Equal_c0gx) {
    /* Saturate: '<S2>/Saturation2' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    if (busOBD_SlwTaskIn.s16_pwrSplyElecPwr > 16384) {
      rtb_Saturation2_nleq = 16384;
    } else if (busOBD_SlwTaskIn.s16_pwrSplyElecPwr < -16384) {
      rtb_Saturation2_nleq = -16384;
    } else {
      rtb_Saturation2_nleq = busOBD_SlwTaskIn.s16_pwrSplyElecPwr;
    }

    /* End of Saturate: '<S2>/Saturation2' */

    /* Selector: '<S2>/Selector2' incorporates:
     *  Constant: '<S2>/Constant4'
     */
    rtb_Selector2_ghqr = rtb_Switch[BATT_PWR_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S35>/ens_JudgDeb' incorporates:
     *  EnablePort: '<S36>/Enable'
     */
    if (rtb_Selector2_ghqr) {
      /* Abs: '<S39>/Abs' incorporates:
       *  Saturate: '<S2>/Saturation2'
       */
      if (rtb_Saturation2_nleq < 0) {
        Gu16_stCtlDFPMSt_C_0 = (uint16)(-rtb_Saturation2_nleq);
      } else {
        Gu16_stCtlDFPMSt_C_0 = (uint16)rtb_Saturation2_nleq;
      }

      /* Outputs for Atomic SubSystem: '<S36>/lib_Deb_11' */
      /* RelationalOperator: '<S39>/Relational Operator1' incorporates:
       *  Abs: '<S39>/Abs'
       *  Constant: '<S36>/Constant2'
       *  Constant: '<S36>/Constant3'
       *  Constant: '<S39>/Constant2'
       */
      ASW_OBD_lib_Deb_11((Gu16_stCtlDFPMSt_C_0 > Gu16_pwrBattPwrHiLvl1ConfTrs_C),
                         Gu16_ctBattPwrHiLvl1ConfCnt_C,
                         Gu16_ctBattPwrHiLvl1RcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_hlnt, &ASW_OBD_DW.lib_Deb_11);

      /* End of Outputs for SubSystem: '<S36>/lib_Deb_11' */
    }

    /* End of Outputs for SubSystem: '<S35>/ens_JudgDeb' */

    /* Outputs for Atomic SubSystem: '<S35>/lib_FaltDefd_21' */
    /* Selector: '<S2>/Selector1' incorporates:
     *  Constant: '<S2>/Constant4'
     *  Selector: '<S2>/Selector2'
     *  Selector: '<S2>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_hlnt, rtb_Selector2_ghqr,
      rtb_DataTypeConversion[BATT_PWR_HI_LVL1],
      rtb_DataTypeConversion1[BATT_PWR_HI_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_lhdo,
      &ASW_OBD_B.stFaltDef_Perm_iopf, &ASW_OBD_B.FaltCycAccCnt_if4y,
      Gu16_ctBattPwrHiLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_21);

    /* End of Outputs for SubSystem: '<S35>/lib_FaltDefd_21' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_BattPwrHiLvl1Dia' */

  /* RelationalOperator: '<S99>/Equal' incorporates:
   *  Constant: '<S9>/Constant2'
   *  UnitDelay: '<S99>/Unit Delay'
   */
  rtb_Equal_cipx = (Gu16_ctFaltDiaFstSdlCnt_C ==
                    ASW_OBD_DW.UnitDelay_DSTATE_e34g);

  /* Outputs for Enabled SubSystem: '<S1>/rss_ChipFaltDia' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_CRASHFaltDia' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_BusOffFaltDia' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtb_Equal_cipx) {
    /* Selector: '<S3>/Selector2' incorporates:
     *  Constant: '<S3>/Constant4'
     */
    rtb_Selector2_p3oh = rtb_Switch[BUSOFF_FALT];

    /* Outputs for Enabled SubSystem: '<S42>/ens_HysDeb' incorporates:
     *  EnablePort: '<S43>/Enable'
     */
    if (rtb_Selector2_p3oh) {
      /* Outputs for Atomic SubSystem: '<S43>/lib_Deb_4' */
      /* SignalConversion generated from: '<S43>/bol_flgBusOffFaltRaw' incorporates:
       *  Constant: '<S43>/Constant2'
       *  Constant: '<S43>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_lib_Deb_11(busOBD_SlwTaskIn.bol_flgBusOffFaltRaw,
                         Gu16_ctBusOffFaltConfCnt_C, Gu16_ctBusOffFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_euom, &ASW_OBD_DW.lib_Deb_4);

      /* End of Outputs for SubSystem: '<S43>/lib_Deb_4' */
    }

    /* End of Outputs for SubSystem: '<S42>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S42>/lib_FaltDefd_12' */
    /* Selector: '<S3>/Selector1' incorporates:
     *  Constant: '<S3>/Constant4'
     *  Selector: '<S3>/Selector2'
     *  Selector: '<S3>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_euom, rtb_Selector2_p3oh,
      rtb_DataTypeConversion[BUSOFF_FALT], rtb_DataTypeConversion1[BUSOFF_FALT],
      &ASW_OBD_B.stFaltDef_Tmpr_m0mb, &ASW_OBD_B.stFaltDef_Perm_nx2u,
      &ASW_OBD_B.FaltCycAccCnt_ozl3, Gu16_ctBusOffFaltConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_12);

    /* End of Outputs for SubSystem: '<S42>/lib_FaltDefd_12' */

    /* Selector: '<S4>/Selector2' incorporates:
     *  Constant: '<S4>/Constant4'
     */
    rtb_Selector2_bj1k = rtb_Switch[CRASH_FALT];

    /* Outputs for Enabled SubSystem: '<S48>/ens_HysDeb' incorporates:
     *  EnablePort: '<S49>/Enable'
     */
    if (rtb_Selector2_bj1k) {
      /* Outputs for Atomic SubSystem: '<S49>/lib_Deb_17' */
      /* SignalConversion generated from: '<S49>/bol_flgCrashFalt' incorporates:
       *  Constant: '<S49>/Constant2'
       *  Constant: '<S49>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_lib_Deb_11(busOBD_SlwTaskIn.bol_flgCrashFalt,
                         Gu16_ctCrashFaltConfCnt_C, Gu16_ctCrashFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_gufh, &ASW_OBD_DW.lib_Deb_17);

      /* End of Outputs for SubSystem: '<S49>/lib_Deb_17' */
    }

    /* End of Outputs for SubSystem: '<S48>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S48>/lib_FaltDefd_9' */
    /* Selector: '<S4>/Selector1' incorporates:
     *  Constant: '<S4>/Constant4'
     *  Selector: '<S4>/Selector2'
     *  Selector: '<S4>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_gufh, rtb_Selector2_bj1k,
      rtb_DataTypeConversion[CRASH_FALT], rtb_DataTypeConversion1[CRASH_FALT],
      &ASW_OBD_B.stFaltDef_Tmpr_nqix, &ASW_OBD_B.stFaltDef_Perm_bpps,
      &ASW_OBD_B.FaltCycAccCnt_okl0, Gu16_ctCrashFaltConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_9);

    /* End of Outputs for SubSystem: '<S48>/lib_FaltDefd_9' */

    /* Selector: '<S5>/Selector2' incorporates:
     *  Constant: '<S5>/Constant4'
     */
    rtb_Selector2_mqxc = rtb_Switch[CHIP_FALT];

    /* Outputs for Enabled SubSystem: '<S54>/ens_HysDeb' incorporates:
     *  EnablePort: '<S55>/Enable'
     */
    if (rtb_Selector2_mqxc) {
      /* Outputs for Atomic SubSystem: '<S55>/lib_Deb_1' */
      /* SignalConversion generated from: '<S55>/bol_flgCrashFalt' incorporates:
       *  Constant: '<S55>/Constant2'
       *  Constant: '<S55>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_lib_Deb_11(busOBD_SlwTaskIn.bol_flgChipFalt,
                         Gu16_ctChipFaltConfCnt_C, Gu16_ctChipFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_j4ya, &ASW_OBD_DW.lib_Deb_1);

      /* End of Outputs for SubSystem: '<S55>/lib_Deb_1' */
    }

    /* End of Outputs for SubSystem: '<S54>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S54>/lib_FaltDefd_9' */
    /* Selector: '<S5>/Selector1' incorporates:
     *  Constant: '<S5>/Constant4'
     *  Selector: '<S5>/Selector2'
     *  Selector: '<S5>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_j4ya, rtb_Selector2_mqxc,
      rtb_DataTypeConversion[CHIP_FALT], rtb_DataTypeConversion1[CHIP_FALT],
      &ASW_OBD_B.stFaltDef_Tmpr_cbrr, &ASW_OBD_B.stFaltDef_Perm_mvmh,
      &ASW_OBD_B.FaltCycAccCnt_be2m, Gu16_ctChipFaltConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_9_drq2);

    /* End of Outputs for SubSystem: '<S54>/lib_FaltDefd_9' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_BusOffFaltDia' */
  /* End of Outputs for SubSystem: '<S1>/rss_CRASHFaltDia' */
  /* End of Outputs for SubSystem: '<S1>/rss_ChipFaltDia' */

  /* RelationalOperator: '<S98>/Equal' incorporates:
   *  Constant: '<S9>/Constant7'
   *  UnitDelay: '<S98>/Unit Delay'
   */
  rtb_Equal_kjhq = (Gu16_ctFaltDiaComSdlCnt_C ==
                    ASW_OBD_DW.UnitDelay_DSTATE_c13u);

  /* Outputs for Enabled SubSystem: '<S1>/rss_ComFaltDia' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtb_Equal_kjhq) {
    /* Selector: '<S6>/Selector1' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    rtb_Selector1_eamb = rtb_DataTypeConversion[COM_FALT];

    /* Selector: '<S6>/Selector2' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Selector: '<S6>/Selector1'
     */
    rtb_Selector2_bvc0 = rtb_Switch[COM_FALT];

    /* Outputs for Enabled SubSystem: '<S61>/ens_HysDeb_GEELY' incorporates:
     *  EnablePort: '<S63>/Enable'
     */
    if (rtb_Selector2_bvc0) {
      /* Outputs for Atomic SubSystem: '<S63>/CANHeartLos' */
      CANHeartLosCheck();

      /* End of Outputs for SubSystem: '<S63>/CANHeartLos' */

      /* Outputs for Atomic SubSystem: '<S63>/lib_Deb_5' */
      /* Constant: '<S63>/Constant2' incorporates:
       *  Constant: '<S63>/Constant3'
       */
      ASW_OBD_lib_Deb_11(ASW_OBD_B.bitsForTID1.Equal_azvi,
                         Gu16_ctComLosFaltConfCnt_C, Gu16_ctComLosFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_eatq, &ASW_OBD_DW.lib_Deb_5);

      /* End of Outputs for SubSystem: '<S63>/lib_Deb_5' */

      /* RelationalOperator: '<S65>/Equal' incorporates:
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  UnitDelay: '<S65>/Unit Delay'
       */
      ASW_OBD_B.bitsForTID1.Equal = (ASW_OBD_DW.UnitDelay_DSTATE_keg4 !=
        busOBD_SlwTaskIn.bol_flgComLosFaltRaw);

      /* Outputs for Enabled SubSystem: '<S65>/COMLosDia' */
      CANSigLosCheck();

      /* End of Outputs for SubSystem: '<S65>/COMLosDia' */

      /* Outputs for Atomic SubSystem: '<S63>/lib_Deb_6' */
      /* Constant: '<S63>/Constant1' incorporates:
       *  Constant: '<S63>/Constant4'
       */
      ASW_OBD_lib_Deb_11(ASW_OBD_B.bitsForTID1.DataTypeConversion1,
                         Gu16_ctComRolCntFaltConfCnt_C,
                         Gu16_ctComRolCntFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_lgdu, &ASW_OBD_DW.lib_Deb_6);

      /* End of Outputs for SubSystem: '<S63>/lib_Deb_6' */

      /* Outputs for Atomic SubSystem: '<S63>/lib_Deb_7' */
      /* Constant: '<S63>/Constant6' incorporates:
       *  Constant: '<S63>/Constant7'
       */
      ASW_OBD_lib_Deb_11(ASW_OBD_B.bitsForTID1.DataTypeConversion,
                         Gu16_ctCRCFaltConfCnt_C, Gu16_ctCRCFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_ojfd, &ASW_OBD_DW.lib_Deb_7);

      /* End of Outputs for SubSystem: '<S63>/lib_Deb_7' */

      /* Logic: '<S63>/Logical Operator' */
      ASW_OBD_B.bitsForTID1.LogicalOperator_hyuk = (((ASW_OBD_B.lb_genOutp_eatq)
        || (ASW_OBD_B.lb_genOutp_lgdu)) || (ASW_OBD_B.lb_genOutp_ojfd));

      /* Update for UnitDelay: '<S65>/Unit Delay' incorporates:
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_DW.UnitDelay_DSTATE_keg4 = busOBD_SlwTaskIn.bol_flgComLosFaltRaw;
    }

    /* End of Outputs for SubSystem: '<S61>/ens_HysDeb_GEELY' */

    /* Outputs for Atomic SubSystem: '<S60>/lib_FaltDefd_18' */
    /* Chart: '<S62>/sfc_FaultDefiniteness' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Selector: '<S6>/Selector1'
     *  Selector: '<S6>/Selector7'
     */
    /* Gateway: FaultDefiniteness_0/sfc_FaultDefiniteness */
    /* During: FaultDefiniteness_0/sfc_FaultDefiniteness */
    if (ASW_OBD_DW.is_active_c2_swiWcj04KqK1cujXcW == 0U) {
      /* Entry: FaultDefiniteness_0/sfc_FaultDefiniteness */
      ASW_OBD_DW.is_active_c2_swiWcj04KqK1cujXcW = 1U;

      /* Entry Internal: FaultDefiniteness_0/sfc_FaultDefiniteness */
      /* Transition: '<S77>:222' */
      ASW_OBD_DW.is_c2_swiWcj04KqK1cujXcWFuKxE_l = IN_DisableDiagnosis_ixht;

      /* Entry 'DisableDiagnosis': '<S77>:221' */
      /* Clear Bit0 Bit1 */
      ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = false;
      ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = false;
      ASW_OBD_B.FaltCycAccCnt_nakw = 0U;
    } else if (ASW_OBD_DW.is_c2_swiWcj04KqK1cujXcWFuKxE_l ==
               IN_DisableDiagnosis_ixht) {
      ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = false;
      ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = false;

      /* During 'DisableDiagnosis': '<S77>:221' */
      /* Fault Need Enable */
      if (rtb_Selector2_bvc0) {
        /* Transition: '<S77>:223' */
        ASW_OBD_DW.is_c2_swiWcj04KqK1cujXcWFuKxE_l = IN_EnableDiagnosis_mjfq;

        /* Entry Internal 'EnableDiagnosis': '<S77>:220' */
        /* Transition: '<S77>:149' */
        ASW_OBD_DW.is_EnableDiagnosis = IN_Normal_iv3m;

        /* Entry 'Normal': '<S77>:225' */
        /* Clear Bit0 Bit1 */
        ASW_OBD_B.FaltCycAccCnt_nakw = 0U;
      }
    } else {
      /* During 'EnableDiagnosis': '<S77>:220' */
      switch (ASW_OBD_DW.is_EnableDiagnosis) {
       case IN_Confirmed_fog5:
        ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = false;
        ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = true;

        /* During 'Confirmed': '<S77>:165' */
        /* Need Recovery */
        if ((rtb_DataTypeConversion1[COM_FALT]) &&
            (!ASW_OBD_B.bitsForTID1.LogicalOperator_hyuk)) {
          /* Transition: '<S77>:219' */
          /* Transition: '<S77>:230' */
          ASW_OBD_DW.is_EnableDiagnosis = IN_Normal_iv3m;

          /* Entry 'Normal': '<S77>:225' */
          /* Clear Bit0 Bit1 */
          ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = false;
          ASW_OBD_B.FaltCycAccCnt_nakw = 0U;
        }
        break;

       case IN_Confirming_p012:
        ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = true;
        ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = true;

        /* During 'Confirming': '<S77>:93' */
        /* There is no Fault */
        if (!ASW_OBD_B.bitsForTID1.LogicalOperator_hyuk) {
          /* Transition: '<S77>:173' */
          ASW_OBD_DW.is_EnableDiagnosis = IN_Wait_ax3z;

          /* Entry 'Wait': '<S77>:98' */
          /* Set Bit0 Clear Bit1 */
          ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = false;
          ASW_OBD_DW.FaltWaitRecvCnt = 0U;
        }
        break;

       case IN_Normal_iv3m:
        ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = false;
        ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = false;

        /* During 'Normal': '<S77>:225' */
        /* There is Fault */
        if (ASW_OBD_B.bitsForTID1.LogicalOperator_hyuk) {
          /* Transition: '<S77>:182' */
          /* Direct Confirm */
          if (rtb_Selector1_eamb == 0) {
            /* Transition: '<S77>:185' */
            /* Transition: '<S77>:188' */
            ASW_OBD_DW.is_EnableDiagnosis = IN_Confirmed_fog5;

            /* Entry 'Confirmed': '<S77>:165' */
            /* Set Bit1 Clear Bit0 */
            ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = true;
            ASW_OBD_B.FaltCycAccCnt_nakw = 0U;
          } else {
            /* Transition: '<S77>:183' */
            ASW_OBD_DW.is_EnableDiagnosis = IN_Confirming_p012;

            /* Entry 'Confirming': '<S77>:93' */
            /* Set Bit0 Bit1 */
            ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = true;
            ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = true;
            i = ASW_OBD_B.FaltCycAccCnt_nakw + 1;
            if ((ASW_OBD_B.FaltCycAccCnt_nakw + 1) > 255) {
              i = 255;
            }

            ASW_OBD_B.FaltCycAccCnt_nakw = (uint8)i;
          }
        }
        break;

       default:
        ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = true;
        ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = false;

        /* During 'Wait': '<S77>:98' */
        /* There is Fault */
        if (ASW_OBD_B.bitsForTID1.LogicalOperator_hyuk) {
          /* Transition: '<S77>:166' */
          /* Fault is Confirmed */
          if (ASW_OBD_B.FaltCycAccCnt_nakw >= rtb_Selector1_eamb) {
            /* Transition: '<S77>:214' */
            /* Transition: '<S77>:232' */
            /* Exit 'Wait': '<S77>:98' */
            ASW_OBD_DW.FaltWaitRecvCnt = 0U;
            ASW_OBD_DW.is_EnableDiagnosis = IN_Confirmed_fog5;

            /* Entry 'Confirmed': '<S77>:165' */
            /* Set Bit1 Clear Bit0 */
            ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = false;
            ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = true;
            ASW_OBD_B.FaltCycAccCnt_nakw = 0U;
          } else {
            /* Transition: '<S77>:213' */
            /* Need Confirm */
            /* Exit 'Wait': '<S77>:98' */
            ASW_OBD_DW.FaltWaitRecvCnt = 0U;
            ASW_OBD_DW.is_EnableDiagnosis = IN_Confirming_p012;

            /* Entry 'Confirming': '<S77>:93' */
            /* Set Bit0 Bit1 */
            ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp = true;
            ASW_OBD_B.FaltCycAccCnt_nakw++;
          }

          /* Confirm to Recovery */
        } else if ((ASW_OBD_DW.FaltWaitRecvCnt > 100) && rtb_Selector2_bvc0) {
          /* Transition: '<S77>:226' */
          /* Transition: '<S77>:234' */
          /* Exit 'Wait': '<S77>:98' */
          ASW_OBD_DW.FaltWaitRecvCnt = 0U;
          ASW_OBD_DW.is_EnableDiagnosis = IN_Normal_iv3m;

          /* Entry 'Normal': '<S77>:225' */
          /* Clear Bit0 Bit1 */
          ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h = false;
          ASW_OBD_B.FaltCycAccCnt_nakw = 0U;
        } else {
          i = ASW_OBD_DW.FaltWaitRecvCnt + 1;
          if ((ASW_OBD_DW.FaltWaitRecvCnt + 1) > 65535) {
            i = 65535;
          }

          ASW_OBD_DW.FaltWaitRecvCnt = (uint16)i;
        }
        break;
      }
    }

    /* End of Chart: '<S62>/sfc_FaultDefiniteness' */
    /* End of Outputs for SubSystem: '<S60>/lib_FaltDefd_18' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_ComFaltDia' */

  /* Outputs for Enabled SubSystem: '<S1>/rss_SplyVltgHiLvl1Dia' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_SplyVltgLoLvl2Dia' incorporates:
   *  EnablePort: '<S29>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_SplyVltgLoLvl1Dia' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_HWOvrCurrDia' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_PhCurrHiLvl1Dia' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_CtlBrdVltgLoLvl1Dia' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_CtlBrdVltgHiLvl1Dia' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtb_Equal_cipx) {
    /* Selector: '<S7>/Selector2' incorporates:
     *  Constant: '<S7>/Constant8'
     */
    rtb_Selector2_lezv = rtb_Switch[CTL_BRD_VLTG_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S78>/ens_Deb' incorporates:
     *  EnablePort: '<S79>/Enable'
     */
    if (rtb_Selector2_lezv) {
      /* Saturate: '<S7>/Saturation1' incorporates:
       *  Constant: '<S79>/Constant16'
       *  Constant: '<S79>/Constant17'
       *  Constant: '<S79>/Constant18'
       *  Constant: '<S79>/Constant19'
       *  Constant: '<S79>/Constant2'
       *  Constant: '<S79>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      if (busOBD_SlwTaskIn.u16_uCtlBrdVltg <= 32767) {
        Gu16_stCtlDFPMSt_C_0 = busOBD_SlwTaskIn.u16_uCtlBrdVltg;
      } else {
        Gu16_stCtlDFPMSt_C_0 = 32767U;
      }

      /* Outputs for Atomic SubSystem: '<S79>/lib_HysDeb_1' */
      ASW_OBD_lib_HysDeb_1(Gu16_stCtlDFPMSt_C_0, Gu16_uCtlBrdVltgHiLvl1ConfTrs_C,
                           Gu16_uCtlBrdVltgHiLvl1RcvyTrs_C,
                           Gu16_ctCtlBrdVltgHiLvl1ConfCnt_C,
                           Gu16_ctCtlBrdVltgHiLvl1RcvyCnt_C, true, false,
                           &ASW_OBD_B.Switch1_l3mi,
                           &ASW_OBD_B.RelationalOperator1_l2l1,
                           &rtb_RelationalOperator_dqxp,
                           &ASW_OBD_DW.lib_HysDeb_1);

      /* End of Saturate: '<S7>/Saturation1' */
      /* End of Outputs for SubSystem: '<S79>/lib_HysDeb_1' */
    }

    /* End of Outputs for SubSystem: '<S78>/ens_Deb' */

    /* Outputs for Atomic SubSystem: '<S78>/lib_FaltDefd_1' */
    /* Selector: '<S7>/Selector9' incorporates:
     *  Constant: '<S7>/Constant8'
     *  Selector: '<S7>/Selector2'
     *  Selector: '<S7>/Selector21'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_l3mi, rtb_Selector2_lezv,
      rtb_DataTypeConversion[CTL_BRD_VLTG_HI_LVL1],
      rtb_DataTypeConversion1[CTL_BRD_VLTG_HI_LVL1],
      &ASW_OBD_B.stFaltDef_Tmpr_b1sa, &ASW_OBD_B.stFaltDef_Perm_ofvs,
      &ASW_OBD_B.FaltCycAccCnt_da1w, Gu16_ctCtlBrdVltgHiLvl1ConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_1);

    /* End of Outputs for SubSystem: '<S78>/lib_FaltDefd_1' */

    /* Selector: '<S8>/Selector2' incorporates:
     *  Constant: '<S8>/Constant8'
     */
    rtb_Selector2_d5ob = rtb_Switch[CTL_BRD_VLTG_LO_LVL1];

    /* Outputs for Enabled SubSystem: '<S85>/ens_Deb' incorporates:
     *  EnablePort: '<S86>/Enable'
     */
    if (rtb_Selector2_d5ob) {
      /* Saturate: '<S8>/Saturation1' incorporates:
       *  Constant: '<S86>/Constant16'
       *  Constant: '<S86>/Constant17'
       *  Constant: '<S86>/Constant18'
       *  Constant: '<S86>/Constant19'
       *  Constant: '<S86>/Constant2'
       *  Constant: '<S86>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      if (busOBD_SlwTaskIn.u16_uCtlBrdVltg <= 32767) {
        Gu16_stCtlDFPMSt_C_0 = busOBD_SlwTaskIn.u16_uCtlBrdVltg;
      } else {
        Gu16_stCtlDFPMSt_C_0 = 32767U;
      }

      /* Outputs for Atomic SubSystem: '<S86>/lib_HysDeb_0' */
      ASW_OBD_lib_HysDeb_1(Gu16_stCtlDFPMSt_C_0, Gu16_uCtlBrdVltgLoLvl1RcvyTrs_C,
                           Gu16_uCtlBrdVltgLoLvl1ConfTrs_C,
                           Gu16_ctCtlBrdVltgLoLvl1RcvyCnt_C,
                           Gu16_ctCtlBrdVltgLoLvl1ConfCnt_C, false, true,
                           &ASW_OBD_B.Switch1_aqbl,
                           &rtb_RelationalOperator1_nbm1,
                           &ASW_OBD_B.RelationalOperator,
                           &ASW_OBD_DW.lib_HysDeb_0);

      /* End of Saturate: '<S8>/Saturation1' */
      /* End of Outputs for SubSystem: '<S86>/lib_HysDeb_0' */
    }

    /* End of Outputs for SubSystem: '<S85>/ens_Deb' */

    /* Outputs for Atomic SubSystem: '<S85>/lib_FaltDefd_0' */
    /* Selector: '<S8>/Selector9' incorporates:
     *  Constant: '<S8>/Constant8'
     *  Selector: '<S8>/Selector2'
     *  Selector: '<S8>/Selector21'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_aqbl, rtb_Selector2_d5ob,
      rtb_DataTypeConversion[CTL_BRD_VLTG_LO_LVL1],
      rtb_DataTypeConversion1[CTL_BRD_VLTG_LO_LVL1],
      &ASW_OBD_B.stFaltDef_Tmpr_bk0g, &ASW_OBD_B.stFaltDef_Perm_nbju,
      &ASW_OBD_B.FaltCycAccCnt_kbad, Gu16_ctCtlBrdVltgLoLvl1ConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_0);

    /* End of Outputs for SubSystem: '<S85>/lib_FaltDefd_0' */

    /* Selector: '<S22>/Selector2' incorporates:
     *  Constant: '<S22>/Constant4'
     */
    rtb_Selector2_ko2p = rtb_Switch[PH_CURR_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S206>/ens_HysDeb' incorporates:
     *  EnablePort: '<S207>/Enable'
     */
    if (rtb_Selector2_ko2p) {
      /* Switch: '<S207>/Switch' incorporates:
       *  Constant: '<S207>/Constant1'
       *  Constant: '<S207>/Constant2'
       *  Constant: '<S207>/Constant3'
       *  Constant: '<S207>/Constant4'
       *  Constant: '<S207>/Constant9'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  RelationalOperator: '<S207>/Relational Operator'
       */
      if (busOBD_SlwTaskIn.u8_tPCBTempSubs <= Gu8_tColdStrtPCBTempConfTrs_C) {
        rtb_Switch_kftc_idx_0 = Gs16_iColdStrtPhCurrHiLvl1ConfTrs_C;
        rtb_Switch_kftc_idx_1 = Gs16_iColdStrtPhCurrHiLvl1RcvyTrs_C;
      } else {
        rtb_Switch_kftc_idx_0 = Gs16_iPhCurrHiLvl1ConfTrs_C;
        rtb_Switch_kftc_idx_1 = Gs16_iPhCurrHiLvl1RcvyTrs_C;
      }

      /* End of Switch: '<S207>/Switch' */

      /* Saturate: '<S22>/Saturation1' incorporates:
       *  Constant: '<S207>/Constant5'
       *  Constant: '<S207>/Constant6'
       *  Constant: '<S207>/Constant7'
       *  Constant: '<S207>/Constant8'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      if (busOBD_SlwTaskIn.s16_ampActPhCurrAmp > 14746) {
        minV = 14746;
      } else if (busOBD_SlwTaskIn.s16_ampActPhCurrAmp < 0) {
        minV = 0;
      } else {
        minV = busOBD_SlwTaskIn.s16_ampActPhCurrAmp;
      }

      /* Outputs for Atomic SubSystem: '<S207>/lib_HysDeb_2' */
      ASW_OBD_lib_HysDeb_14(minV, rtb_Switch_kftc_idx_0, rtb_Switch_kftc_idx_1,
                            Gu16_ctPhCurrHiLvl1ConfCnt_C,
                            Gu16_ctPhCurrHiLvl1RcvyCnt_C, true, false,
                            &ASW_OBD_B.Switch1_pxi3,
                            &rtb_RelationalOperator1_pgfr,
                            &rtb_RelationalOperator_b3c5,
                            &ASW_OBD_DW.lib_HysDeb_2);

      /* End of Saturate: '<S22>/Saturation1' */
      /* End of Outputs for SubSystem: '<S207>/lib_HysDeb_2' */
    }

    /* End of Outputs for SubSystem: '<S206>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S206>/lib_FaltDefd_2' */
    /* Selector: '<S22>/Selector' incorporates:
     *  Constant: '<S22>/Constant4'
     *  Selector: '<S22>/Selector2'
     *  Selector: '<S22>/Selector9'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_pxi3, rtb_Selector2_ko2p,
      rtb_DataTypeConversion[PH_CURR_HI_LVL1],
      rtb_DataTypeConversion1[PH_CURR_HI_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_glyd,
      &ASW_OBD_B.stFaltDef_Perm_lijp, &ASW_OBD_B.FaltCycAccCnt_psnz,
      Gu16_ctPhCurrHiLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_2);

    /* End of Outputs for SubSystem: '<S206>/lib_FaltDefd_2' */

    /* Selector: '<S14>/Selector6' incorporates:
     *  Constant: '<S14>/Constant8'
     */
    rtb_Selector6 = rtb_Switch[HW_OVER_CURR];

    /* Outputs for Enabled SubSystem: '<S149>/ens_Deb_0' incorporates:
     *  EnablePort: '<S150>/Enable'
     */
    if (rtb_Selector6) {
      /* Outputs for Atomic SubSystem: '<S150>/lib_Deb_0' */
      /* SignalConversion generated from: '<S150>/bol_flgHWOvrCurrFalt' incorporates:
       *  Constant: '<S150>/Constant1'
       *  Constant: '<S150>/Constant4'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_lib_Deb_11(busOBD_SlwTaskIn.bol_flgHWOvrCurrFalt,
                         Gu16_ctHWOvrCurrConfCnt_C, Gu16_ctHWOvrCurrRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_neqw, &ASW_OBD_DW.lib_Deb_0);

      /* End of Outputs for SubSystem: '<S150>/lib_Deb_0' */
    }

    /* End of Outputs for SubSystem: '<S149>/ens_Deb_0' */

    /* Outputs for Atomic SubSystem: '<S149>/lib_FaltDefd_3' */
    /* SignalConversion generated from: '<S14>/bol_flgHWOvrCurrTmp' incorporates:
     *  Chart: '<S151>/sfc_FaultDefiniteness'
     *  Constant: '<S14>/Constant8'
     *  Selector: '<S14>/Selector12'
     *  Selector: '<S14>/Selector6'
     *  Selector: '<S14>/Selector8'
     */
    ASW_OBD_sfc_FaultDefiniteness(ASW_OBD_B.lb_genOutp_neqw, rtb_Selector6,
      rtb_DataTypeConversion[HW_OVER_CURR], rtb_DataTypeConversion1[HW_OVER_CURR],
      &ASW_OBD_B.OutportBufferForbol_flgHWOvrCur, &ASW_OBD_B.stFaltDef_Perm_dzb0,
      &ASW_OBD_B.FaltCycAccCnt_gwiq, Gu16_ctHWOvrCurrConfCnt_C,
      &ASW_OBD_DW.sf_sfc_FaultDefiniteness_fvae);

    /* End of Outputs for SubSystem: '<S149>/lib_FaltDefd_3' */

    /* Selector: '<S28>/Selector2' incorporates:
     *  Constant: '<S28>/Constant8'
     */
    rtb_Selector2_e1kw = rtb_Switch[SPLY_VLTG_LO_LVL1];

    /* Outputs for Enabled SubSystem: '<S265>/ens_HysDeb' incorporates:
     *  EnablePort: '<S266>/Enable'
     */
    if (rtb_Selector2_e1kw) {
      /* Saturate: '<S28>/Saturation1' incorporates:
       *  Constant: '<S266>/Constant16'
       *  Constant: '<S266>/Constant17'
       *  Constant: '<S266>/Constant18'
       *  Constant: '<S266>/Constant19'
       *  Constant: '<S266>/Constant2'
       *  Constant: '<S266>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      if (busOBD_SlwTaskIn.u16_uSplyVltg <= 32767) {
        Gu16_stCtlDFPMSt_C_0 = busOBD_SlwTaskIn.u16_uSplyVltg;
      } else {
        Gu16_stCtlDFPMSt_C_0 = 32767U;
      }

      /* Outputs for Atomic SubSystem: '<S266>/lib_HysDeb_3' */
      ASW_OBD_lib_HysDeb_1(Gu16_stCtlDFPMSt_C_0, Gu16_uSplyVltgLoLvl1RcvyTrs_C,
                           Gu16_uSplyVltgLoLvl1ConfTrs_C,
                           Gu16_ctSplyVltgLoLvl1RcvyCnt_C,
                           Gu16_ctSplyVltgLoLvl1ConfCnt_C, false, true,
                           &ASW_OBD_B.Switch1_lspe,
                           &rtb_RelationalOperator1_lt3z,
                           &rtb_RelationalOperator_hcyg,
                           &ASW_OBD_DW.lib_HysDeb_3);

      /* End of Saturate: '<S28>/Saturation1' */
      /* End of Outputs for SubSystem: '<S266>/lib_HysDeb_3' */
    }

    /* End of Outputs for SubSystem: '<S265>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S265>/lib_FaltDefd_4' */
    /* Selector: '<S28>/Selector9' incorporates:
     *  Constant: '<S28>/Constant8'
     *  Selector: '<S28>/Selector2'
     *  Selector: '<S28>/Selector21'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_lspe, rtb_Selector2_e1kw,
      rtb_DataTypeConversion[SPLY_VLTG_LO_LVL1],
      rtb_DataTypeConversion1[SPLY_VLTG_LO_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_lgzj,
      &ASW_OBD_B.stFaltDef_Perm_ktdp, &ASW_OBD_B.FaltCycAccCnt_akrv,
      Gu16_ctSplyVltgLoLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_4);

    /* End of Outputs for SubSystem: '<S265>/lib_FaltDefd_4' */

    /* Selector: '<S29>/Selector4' incorporates:
     *  Constant: '<S29>/Constant15'
     */
    rtb_Selector4_eljz = rtb_Switch[SPLY_VLTG_LO_LVL2];

    /* Outputs for Enabled SubSystem: '<S272>/ens_HysDeb' incorporates:
     *  EnablePort: '<S273>/Enable'
     */
    if (rtb_Selector4_eljz) {
      /* Saturate: '<S29>/Saturation1' incorporates:
       *  Constant: '<S273>/Constant1'
       *  Constant: '<S273>/Constant4'
       *  Constant: '<S273>/Constant5'
       *  Constant: '<S273>/Constant6'
       *  Constant: '<S273>/Constant7'
       *  Constant: '<S273>/Constant8'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      if (busOBD_SlwTaskIn.u16_uSplyVltg <= 32767) {
        Gu16_stCtlDFPMSt_C_0 = busOBD_SlwTaskIn.u16_uSplyVltg;
      } else {
        Gu16_stCtlDFPMSt_C_0 = 32767U;
      }

      /* Outputs for Atomic SubSystem: '<S273>/lib_HysDeb_4' */
      ASW_OBD_lib_HysDeb_1(Gu16_stCtlDFPMSt_C_0, Gu16_uSplyVltgLoLvl2RcvyTrs_C,
                           Gu16_uSplyVltgLoLvl2ConfTrs_C,
                           Gu16_ctSplyVltgLoLvl2RcvyCnt_C,
                           Gu16_ctSplyVltgLoLvl2ConfCnt_C, false, true,
                           &ASW_OBD_B.Switch1_le4p,
                           &rtb_RelationalOperator1_bp1h,
                           &rtb_RelationalOperator_ea1p,
                           &ASW_OBD_DW.lib_HysDeb_4);

      /* End of Saturate: '<S29>/Saturation1' */
      /* End of Outputs for SubSystem: '<S273>/lib_HysDeb_4' */
    }

    /* End of Outputs for SubSystem: '<S272>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S272>/lib_FaltDefd_5' */
    /* Selector: '<S29>/Selector10' incorporates:
     *  Constant: '<S29>/Constant15'
     *  Selector: '<S29>/Selector15'
     *  Selector: '<S29>/Selector4'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_le4p, rtb_Selector4_eljz,
      rtb_DataTypeConversion[SPLY_VLTG_LO_LVL2],
      rtb_DataTypeConversion1[SPLY_VLTG_LO_LVL2], &ASW_OBD_B.stFaltDef_Tmpr_o3sb,
      &ASW_OBD_B.stFaltDef_Perm_efmb, &ASW_OBD_B.FaltCycAccCnt_e00n,
      Gu16_ctSplyVltgLoLvl2ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_5);

    /* End of Outputs for SubSystem: '<S272>/lib_FaltDefd_5' */

    /* Selector: '<S27>/Selector1' incorporates:
     *  Constant: '<S27>/Constant1'
     */
    rtb_Selector1_ikyn = rtb_Switch[SPLY_VLTG_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S258>/ens_HysDeb' incorporates:
     *  EnablePort: '<S259>/Enable'
     */
    if (rtb_Selector1_ikyn) {
      /* Saturate: '<S27>/Saturation1' incorporates:
       *  Constant: '<S259>/Constant16'
       *  Constant: '<S259>/Constant17'
       *  Constant: '<S259>/Constant18'
       *  Constant: '<S259>/Constant19'
       *  Constant: '<S259>/Constant2'
       *  Constant: '<S259>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      if (busOBD_SlwTaskIn.u16_uSplyVltg <= 32767) {
        Gu16_stCtlDFPMSt_C_0 = busOBD_SlwTaskIn.u16_uSplyVltg;
      } else {
        Gu16_stCtlDFPMSt_C_0 = 32767U;
      }

      /* Outputs for Atomic SubSystem: '<S259>/lib_HysDeb_5' */
      ASW_OBD_lib_HysDeb_1(Gu16_stCtlDFPMSt_C_0, Gu16_uSplyVltgHiLvl1ConfTrs_C,
                           Gu16_uSplyVltgHiLvl1RcvyTrs_C,
                           Gu16_ctSplyVltgHiLvl1ConfCnt_C,
                           Gu16_ctSplyVltgHiLvl1RcvyCnt_C, true, false,
                           &ASW_OBD_B.Switch1_j0vh,
                           &ASW_OBD_B.RelationalOperator1,
                           &rtb_RelationalOperator_klm3,
                           &ASW_OBD_DW.lib_HysDeb_5);

      /* End of Saturate: '<S27>/Saturation1' */
      /* End of Outputs for SubSystem: '<S259>/lib_HysDeb_5' */
    }

    /* End of Outputs for SubSystem: '<S258>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S258>/lib_FaltDefd_6' */
    /* Selector: '<S27>/Selector3' incorporates:
     *  Constant: '<S27>/Constant1'
     *  Selector: '<S27>/Selector1'
     *  Selector: '<S27>/Selector18'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_j0vh, rtb_Selector1_ikyn,
      rtb_DataTypeConversion[SPLY_VLTG_HI_LVL1],
      rtb_DataTypeConversion1[SPLY_VLTG_HI_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_ni5x,
      &ASW_OBD_B.stFaltDef_Perm_f4wg, &ASW_OBD_B.FaltCycAccCnt_eksn,
      Gu16_ctSplyVltgHiLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_6);

    /* End of Outputs for SubSystem: '<S258>/lib_FaltDefd_6' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_CtlBrdVltgHiLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_CtlBrdVltgLoLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_PhCurrHiLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_HWOvrCurrDia' */
  /* End of Outputs for SubSystem: '<S1>/rss_SplyVltgLoLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_SplyVltgLoLvl2Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_SplyVltgHiLvl1Dia' */

  /* Outputs for Enabled SubSystem: '<S1>/rss_MotoTempHiLvl2Dia' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_MotoTempHiLvl1Dia' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl2Dia' incorporates:
   *  EnablePort: '<S25>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl1Dia' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  if (rtb_Equal_c0gx) {
    /* Selector: '<S24>/Selector2' incorporates:
     *  Constant: '<S24>/Constant4'
     */
    rtb_Selector2_f4jl = rtb_Switch[PWR_TUB_PCB_TEMP_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S220>/ens_HysDeb' incorporates:
     *  EnablePort: '<S221>/Enable'
     */
    if (rtb_Selector2_f4jl) {
      /* Outputs for Atomic SubSystem: '<S221>/lib_HysDeb_9' */
      /* Inport: '<Root>/busOBD_SlwTaskIn' incorporates:
       *  Constant: '<S221>/Constant1'
       *  Constant: '<S221>/Constant16'
       *  Constant: '<S221>/Constant17'
       *  Constant: '<S221>/Constant18'
       *  Constant: '<S221>/Constant19'
       *  Constant: '<S221>/Constant2'
       *  Constant: '<S221>/Constant3'
       *  Constant: '<S221>/Constant4'
       *  Constant: '<S221>/Constant5'
       *  Constant: '<S221>/Constant6'
       *  Constant: '<S221>/Constant7'
       *  Constant: '<S221>/Constant8'
       */
      ASW_OBD_lib_HysDeb_12(busOBD_SlwTaskIn.u8_tPCBTempSubs,
                            Gu8_tPCBTempHiLvl1ConfTrs_C,
                            Gu8_tPCBTempHiLvl1RcvyTrs_C,
                            Gu16_ctPCBTempHiLvl1ConfCnt_C,
                            Gu16_ctPCBTempHiLvl1RcvyCnt_C, true, false,
                            &rtb_Switch1, &rtb_RelationalOperator1_kgxf,
                            &rtb_RelationalOperator_h0it,
                            &ASW_OBD_DW.lib_HysDeb_9);

      /* End of Outputs for SubSystem: '<S221>/lib_HysDeb_9' */

      /* Outputs for Atomic SubSystem: '<S221>/lib_HysDeb_8' */
      ASW_OBD_lib_HysDeb_12(busOBD_SlwTaskIn.u8_tPwrTubTemp,
                            Gu8_tPwrTubTempHiLvl1ConfTrs_C,
                            Gu8_tPwrTubTempHiLvl1RcvyTrs_C,
                            Gu16_ctPwrTubTempHiLvl1ConfCnt_C,
                            Gu16_ctPwrTubTempHiLvl1RcvyCnt_C, true, false,
                            &rtb_Switch1_pesu, &rtb_RelationalOperator1_abb3,
                            &rtb_RelationalOperator_p3rt,
                            &ASW_OBD_DW.lib_HysDeb_8);

      /* End of Outputs for SubSystem: '<S221>/lib_HysDeb_8' */

      /* Logic: '<S221>/Logical Operator2' */
      ASW_OBD_B.bitsForTID1.LogicalOperator2_eork = (rtb_Switch1_pesu ||
        rtb_Switch1);
    }

    /* End of Outputs for SubSystem: '<S220>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S220>/lib_FaltDefd_13' */
    /* Selector: '<S24>/Selector1' incorporates:
     *  Constant: '<S24>/Constant4'
     *  Selector: '<S24>/Selector2'
     *  Selector: '<S24>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.bitsForTID1.LogicalOperator2_eork,
      rtb_Selector2_f4jl, rtb_DataTypeConversion[PWR_TUB_PCB_TEMP_HI_LVL1],
      rtb_DataTypeConversion1[PWR_TUB_PCB_TEMP_HI_LVL1],
      &ASW_OBD_B.stFaltDef_Tmpr_mpvn, &ASW_OBD_B.stFaltDef_Perm_dthc,
      &ASW_OBD_B.FaltCycAccCnt_k5ca, Gu16_ctPwrTubTempHiLvl1ConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_13);

    /* End of Outputs for SubSystem: '<S220>/lib_FaltDefd_13' */

    /* Selector: '<S25>/Selector1' incorporates:
     *  Constant: '<S25>/Constant1'
     */
    rtb_Selector1_eapz = rtb_DataTypeConversion[PWR_TUB_PCB_TEMP_HI_LVL2];

    /* Selector: '<S25>/Selector2' incorporates:
     *  Constant: '<S25>/Constant1'
     *  Selector: '<S25>/Selector1'
     */
    rtb_Selector2_mad0 = rtb_Switch[PWR_TUB_PCB_TEMP_HI_LVL2];

    /* Selector: '<S25>/Selector7' incorporates:
     *  Constant: '<S25>/Constant1'
     *  Selector: '<S25>/Selector1'
     */
    rtb_Selector7_idtg = rtb_DataTypeConversion1[PWR_TUB_PCB_TEMP_HI_LVL2];

    /* Outputs for Enabled SubSystem: '<S230>/ens_HysDeb' incorporates:
     *  EnablePort: '<S231>/Enable'
     */
    if (rtb_Selector2_mad0) {
      /* Outputs for Atomic SubSystem: '<S231>/lib_HysDeb_10' */
      /* Inport: '<Root>/busOBD_SlwTaskIn' incorporates:
       *  Constant: '<S231>/Constant1'
       *  Constant: '<S231>/Constant16'
       *  Constant: '<S231>/Constant17'
       *  Constant: '<S231>/Constant18'
       *  Constant: '<S231>/Constant19'
       *  Constant: '<S231>/Constant2'
       *  Constant: '<S231>/Constant3'
       *  Constant: '<S231>/Constant4'
       *  Constant: '<S231>/Constant5'
       *  Constant: '<S231>/Constant6'
       *  Constant: '<S231>/Constant7'
       *  Constant: '<S231>/Constant8'
       */
      ASW_OBD_lib_HysDeb_12(busOBD_SlwTaskIn.u8_tPwrTubTemp,
                            Gu8_tPwrTubTempHiLvl2ConfTrs_C,
                            Gu8_tPwrTubTempHiLvl2RcvyTrs_C,
                            Gu16_ctPwrTubTempHiLvl2ConfCnt_C,
                            Gu16_ctPwrTubTempHiLvl2RcvyCnt_C, true, false,
                            &ASW_OBD_B.Switch1_mj3e,
                            &rtb_RelationalOperator1_ane1,
                            &rtb_RelationalOperator_eiez,
                            &ASW_OBD_DW.lib_HysDeb_10);

      /* End of Outputs for SubSystem: '<S231>/lib_HysDeb_10' */

      /* Outputs for Atomic SubSystem: '<S231>/lib_HysDeb_11' */
      ASW_OBD_lib_HysDeb_12(busOBD_SlwTaskIn.u8_tPCBTempSubs,
                            Gu8_tPCBTempHiLvl2ConfTrs_C,
                            Gu8_tPCBTempHiLvl2RcvyTrs_C,
                            Gu16_ctPCBTempHiLvl2ConfCnt_C,
                            Gu16_ctPCBTempHiLvl2RcvyCnt_C, true, false,
                            &ASW_OBD_B.Switch1_h5dr,
                            &rtb_RelationalOperator1_khcq,
                            &rtb_RelationalOperator_jtyy,
                            &ASW_OBD_DW.lib_HysDeb_11);

      /* End of Outputs for SubSystem: '<S231>/lib_HysDeb_11' */
    }

    /* End of Outputs for SubSystem: '<S230>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S230>/lib_FaltDefd_14' */
    ASW_OBD_lib_FaltDefd_14(ASW_OBD_B.Switch1_mj3e, rtb_Selector2_mad0,
      rtb_Selector1_eapz, rtb_Selector7_idtg, &rtb_stFaltDef_Tmpr_erdn,
      &rtb_stFaltDef_Perm_bryy, &ASW_OBD_B.FaltCycAccCnt_lwpi,
      Gu16_ctPwrTubTempHiLvl2ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_14);

    /* End of Outputs for SubSystem: '<S230>/lib_FaltDefd_14' */

    /* Outputs for Atomic SubSystem: '<S230>/lib_FaltDefd_15' */
    ASW_OBD_lib_FaltDefd_14(ASW_OBD_B.Switch1_h5dr, rtb_Selector2_mad0,
      rtb_Selector1_eapz, rtb_Selector7_idtg, &rtb_stFaltDef_Tmpr,
      &rtb_stFaltDef_Perm, &ASW_OBD_B.FaltCycAccCnt_mbzj,
      Gu16_ctPCBTempHiLvl2ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_15);

    /* End of Outputs for SubSystem: '<S230>/lib_FaltDefd_15' */

    /* Logic: '<S230>/Logical Operator1' */
    ASW_OBD_B.bitsForTID1.LogicalOperator1_cq5m = (rtb_stFaltDef_Perm_bryy ||
      rtb_stFaltDef_Perm);

    /* Logic: '<S230>/Logical Operator2' */
    ASW_OBD_B.bitsForTID1.LogicalOperator2_hzmq = (rtb_stFaltDef_Tmpr_erdn ||
      rtb_stFaltDef_Tmpr);

    /* Selector: '<S18>/Selector2' incorporates:
     *  Constant: '<S18>/Constant4'
     */
    rtb_Selector2_p415 = rtb_Switch[MOTO_TEMP_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S178>/ens_HysDeb' incorporates:
     *  EnablePort: '<S179>/Enable'
     */
    if (rtb_Selector2_p415) {
      /* Outputs for Atomic SubSystem: '<S179>/lib_HysDeb_12' */
      /* Inport: '<Root>/busOBD_SlwTaskIn' incorporates:
       *  Constant: '<S179>/Constant16'
       *  Constant: '<S179>/Constant17'
       *  Constant: '<S179>/Constant18'
       *  Constant: '<S179>/Constant19'
       *  Constant: '<S179>/Constant2'
       *  Constant: '<S179>/Constant3'
       */
      ASW_OBD_lib_HysDeb_12(busOBD_SlwTaskIn.u8_tMotoTemp,
                            Gu8_tMotoTempHiLvl1ConfTrs_C,
                            Gu8_tMotoTempHiLvl1RcvyTrs_C,
                            Gu16_ctMotoTempHiLvl1ConfCnt_C,
                            Gu16_ctMotoTempHiLvl1RcvyCnt_C, true, false,
                            &ASW_OBD_B.Switch1_grgo,
                            &rtb_RelationalOperator1_ie3s,
                            &rtb_RelationalOperator_j4m1,
                            &ASW_OBD_DW.lib_HysDeb_12);

      /* End of Outputs for SubSystem: '<S179>/lib_HysDeb_12' */
    }

    /* End of Outputs for SubSystem: '<S178>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S178>/lib_FaltDefd_16' */
    /* Selector: '<S18>/Selector1' incorporates:
     *  Constant: '<S18>/Constant4'
     *  Selector: '<S18>/Selector2'
     *  Selector: '<S18>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_grgo, rtb_Selector2_p415,
      rtb_DataTypeConversion[MOTO_TEMP_HI_LVL1],
      rtb_DataTypeConversion1[MOTO_TEMP_HI_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_pjcw,
      &ASW_OBD_B.stFaltDef_Perm_h1g3, &ASW_OBD_B.FaltCycAccCnt_fxmn,
      Gu16_ctMotoTempHiLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_16);

    /* End of Outputs for SubSystem: '<S178>/lib_FaltDefd_16' */

    /* Selector: '<S19>/Selector2' incorporates:
     *  Constant: '<S19>/Constant4'
     */
    rtb_Selector2_h3x4 = rtb_Switch[MOTO_TEMP_HI_LVL2];

    /* Outputs for Enabled SubSystem: '<S185>/ens_HysDeb' incorporates:
     *  EnablePort: '<S186>/Enable'
     */
    if (rtb_Selector2_h3x4) {
      /* Outputs for Atomic SubSystem: '<S186>/lib_HysDeb_13' */
      /* Inport: '<Root>/busOBD_SlwTaskIn' incorporates:
       *  Constant: '<S186>/Constant16'
       *  Constant: '<S186>/Constant17'
       *  Constant: '<S186>/Constant18'
       *  Constant: '<S186>/Constant19'
       *  Constant: '<S186>/Constant2'
       *  Constant: '<S186>/Constant3'
       */
      ASW_OBD_lib_HysDeb_12(busOBD_SlwTaskIn.u8_tMotoTemp,
                            Gu8_tMotoTempHiLvl2ConfTrs_C,
                            Gu8_tMotoTempHiLvl2RcvyTrs_C,
                            Gu16_ctMotoTempHiLvl2ConfCnt_C,
                            Gu16_ctMotoTempHiLvl2RcvyCnt_C, true, false,
                            &ASW_OBD_B.Switch1_j1ol,
                            &rtb_RelationalOperator1_jje1,
                            &rtb_RelationalOperator_oulp,
                            &ASW_OBD_DW.lib_HysDeb_13);

      /* End of Outputs for SubSystem: '<S186>/lib_HysDeb_13' */
    }

    /* End of Outputs for SubSystem: '<S185>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S185>/lib_FaltDefd_17' */
    /* Selector: '<S19>/Selector1' incorporates:
     *  Constant: '<S19>/Constant4'
     *  Selector: '<S19>/Selector2'
     *  Selector: '<S19>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_j1ol, rtb_Selector2_h3x4,
      rtb_DataTypeConversion[MOTO_TEMP_HI_LVL2],
      rtb_DataTypeConversion1[MOTO_TEMP_HI_LVL2], &ASW_OBD_B.stFaltDef_Tmpr_izjl,
      &ASW_OBD_B.stFaltDef_Perm_b5ga, &ASW_OBD_B.FaltCycAccCnt_mn3a,
      Gu16_ctMotoTempHiLvl2ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_17);

    /* End of Outputs for SubSystem: '<S185>/lib_FaltDefd_17' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_PwrTubPCBTempHiLvl2Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_MotoTempHiLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_MotoTempHiLvl2Dia' */

  /* Outputs for Enabled SubSystem: '<S1>/rss_NoLdDia' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S31>/rss_MotoStallDiaHybr' incorporates:
   *  EnablePort: '<S291>/Enable'
   */
  if (rtb_Equal_cipx) {
    /* Logic: '<S291>/Logical Operator' incorporates:
     *  Constant: '<S291>/Constant2'
     *  Constant: '<S291>/Constant4'
     *  Selector: '<S291>/Selector2'
     *  Selector: '<S291>/Selector3'
     */
    rtb_LogicalOperator_inut = ((rtb_Switch[MOTO_STALL_PERM]) &&
      (rtb_Switch[MOTO_STALL_TMP]));

    /* Saturate: '<S291>/Saturation1' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    if (busOBD_SlwTaskIn.s16_nRmpRefElecSpd >= -32767) {
      rtb_Saturation1_fxo0 = busOBD_SlwTaskIn.s16_nRmpRefElecSpd;
    } else {
      rtb_Saturation1_fxo0 = -32767;
    }

    /* End of Saturate: '<S291>/Saturation1' */

    /* Saturate: '<S291>/Saturation2' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    if (busOBD_SlwTaskIn.s16_nActElecSpd >= -32767) {
      rtb_Saturation2 = busOBD_SlwTaskIn.s16_nActElecSpd;
    } else {
      rtb_Saturation2 = -32767;
    }

    /* End of Saturate: '<S291>/Saturation2' */

    /* Outputs for Enabled SubSystem: '<S292>/ens_JudgDeb' incorporates:
     *  EnablePort: '<S293>/Enable'
     */
    if (rtb_LogicalOperator_inut) {
      /* Switch: '<S296>/Switch' incorporates:
       *  Abs: '<S296>/Abs3'
       *  Constant: '<S296>/Constant2'
       *  Constant: '<S296>/Constant3'
       *  Constant: '<S298>/Constant'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  RelationalOperator: '<S296>/Relational Operator1'
       *  RelationalOperator: '<S296>/Relational Operator3'
       *  RelationalOperator: '<S298>/Compare'
       *  Saturate: '<S291>/Saturation4'
       */
      if (busOBD_SlwTaskIn.enm_modeAgEvalMode != SENSORLESS) {
        /* Abs: '<S296>/Abs3' incorporates:
         *  Saturate: '<S291>/Saturation2'
         */
        if (rtb_Saturation2 < 0) {
          minV = (sint16)(-rtb_Saturation2);
        } else {
          minV = rtb_Saturation2;
        }

        rtb_Switch_lbqb = (minV < Gs16_nMotoStallMinRefElecSpd_C);
      } else {
        if (busOBD_SlwTaskIn.u16_psiEstPermMagFlx > 10922) {
          /* Saturate: '<S291>/Saturation4' */
          Gu16_stCtlDFPMSt_C_0 = 10922U;
        } else if (busOBD_SlwTaskIn.u16_psiEstPermMagFlx < 55) {
          /* Saturate: '<S291>/Saturation4' */
          Gu16_stCtlDFPMSt_C_0 = 55U;
        } else {
          /* Saturate: '<S291>/Saturation4' */
          Gu16_stCtlDFPMSt_C_0 = busOBD_SlwTaskIn.u16_psiEstPermMagFlx;
        }

        rtb_Switch_lbqb = (Gu16_stCtlDFPMSt_C_0 < Gu16_psiEstMinPermMagFlx_C);
      }

      /* End of Switch: '<S296>/Switch' */

      /* Abs: '<S296>/Abs' incorporates:
       *  Saturate: '<S291>/Saturation1'
       */
      if (rtb_Saturation1_fxo0 < 0) {
        minV = (sint16)(-rtb_Saturation1_fxo0);
      } else {
        minV = rtb_Saturation1_fxo0;
      }

      /* Outputs for Atomic SubSystem: '<S293>/lib_Deb_9' */
      /* Logic: '<S296>/Logical Operator' incorporates:
       *  Abs: '<S296>/Abs'
       *  Constant: '<S293>/Constant2'
       *  Constant: '<S293>/Constant3'
       *  RelationalOperator: '<S296>/Relational Operator'
       */
      ASW_OBD_lib_Deb_11(((minV > 0) && rtb_Switch_lbqb),
                         Gu16_ctMotoStallConfCnt_C, Gu16_ctMotoStallRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_hfik, &ASW_OBD_DW.lib_Deb_9);

      /* End of Outputs for SubSystem: '<S293>/lib_Deb_9' */
    }

    /* End of Outputs for SubSystem: '<S292>/ens_JudgDeb' */

    /* Outputs for Atomic SubSystem: '<S292>/lib_FaltDefd_19' */
    /* Chart: '<S294>/sfc_FaultDefiniteness' incorporates:
     *  Constant: '<S291>/Constant2'
     *  Constant: '<S291>/Constant4'
     *  Logic: '<S291>/Logical Operator1'
     *  Selector: '<S291>/Selector1'
     *  Selector: '<S291>/Selector2'
     *  Selector: '<S291>/Selector3'
     *  Selector: '<S291>/Selector4'
     *  Selector: '<S291>/Selector7'
     */
    ASW_OBD_sfc_FaultDefiniteness(ASW_OBD_B.lb_genOutp_hfik,
      rtb_LogicalOperator_inut, rtb_DataTypeConversion[MOTO_STALL_PERM],
      ((rtb_DataTypeConversion1[MOTO_STALL_PERM]) &&
       (rtb_DataTypeConversion1[MOTO_STALL_TMP])),
      &ASW_OBD_B.stFaltDef_Tmpr_gjm2, &ASW_OBD_B.stFaltDef_Perm_g4b1,
      &ASW_OBD_B.FaltCycAccCnt_advj, Gu16_ctMotoStallConfCnt_C,
      &ASW_OBD_DW.sf_sfc_FaultDefiniteness_et5q);

    /* End of Outputs for SubSystem: '<S292>/lib_FaltDefd_19' */

    /* Saturate: '<S21>/Saturation1' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    if (busOBD_SlwTaskIn.s16_nActElecSpd >= -32767) {
      rtb_Saturation1_h5iq = busOBD_SlwTaskIn.s16_nActElecSpd;
    } else {
      rtb_Saturation1_h5iq = -32767;
    }

    /* End of Saturate: '<S21>/Saturation1' */

    /* Selector: '<S21>/Selector2' incorporates:
     *  Constant: '<S21>/Constant4'
     */
    rtb_Selector2_aoef = rtb_Switch[NO_LD];

    /* Outputs for Enabled SubSystem: '<S199>/ens_JudgDeb' incorporates:
     *  EnablePort: '<S200>/Enable'
     */
    if (rtb_Selector2_aoef) {
      /* Saturate: '<S21>/Saturation2' incorporates:
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      if (busOBD_SlwTaskIn.s16_ampActPhCurrAmp > 14746) {
        minV = 14746;
      } else if (busOBD_SlwTaskIn.s16_ampActPhCurrAmp < 0) {
        minV = 0;
      } else {
        minV = busOBD_SlwTaskIn.s16_ampActPhCurrAmp;
      }

      /* Outputs for Atomic SubSystem: '<S200>/lib_Deb_10' */
      /* Logic: '<S203>/Logical Operator' incorporates:
       *  Constant: '<S200>/Constant2'
       *  Constant: '<S200>/Constant3'
       *  Constant: '<S203>/Constant2'
       *  Lookup_n-D: '<S203>/ElctTrqMap'
       *  RelationalOperator: '<S203>/Relational Operator1'
       *  RelationalOperator: '<S203>/Relational Operator2'
       *  Saturate: '<S21>/Saturation1'
       *  Saturate: '<S21>/Saturation2'
       */
      ASW_OBD_lib_Deb_11(((minV < look1_is16lu32n32ys16n_eAC3J1UD
                           (rtb_Saturation1_h5iq,
                            &Gs16_iNoLdPhCurr_CUR_nActElecSpd_X[0],
                            &Gs16_iNoLdPhCurr_CUR[0], 4U)) &&
                          (rtb_Saturation1_h5iq >= Gs16_nNoLdJudgActElecSpd_C)),
                         Gu16_ctNoLdConfCnt_C, Gu16_ctNoLdRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_hhu4, &ASW_OBD_DW.lib_Deb_10);

      /* End of Outputs for SubSystem: '<S200>/lib_Deb_10' */
    }

    /* End of Outputs for SubSystem: '<S199>/ens_JudgDeb' */

    /* Outputs for Atomic SubSystem: '<S199>/lib_FaltDefd_20' */
    /* Selector: '<S21>/Selector1' incorporates:
     *  Constant: '<S21>/Constant4'
     *  Selector: '<S21>/Selector2'
     *  Selector: '<S21>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_hhu4, rtb_Selector2_aoef,
      rtb_DataTypeConversion[NO_LD], rtb_DataTypeConversion1[NO_LD],
      &ASW_OBD_B.stFaltDef_Tmpr_cp2o, &ASW_OBD_B.stFaltDef_Perm_kt5c,
      &ASW_OBD_B.FaltCycAccCnt_fh1w, Gu16_ctNoLdConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_20);

    /* End of Outputs for SubSystem: '<S199>/lib_FaltDefd_20' */
  }

  /* End of Outputs for SubSystem: '<S31>/rss_MotoStallDiaHybr' */
  /* End of Outputs for SubSystem: '<S1>/rss_NoLdDia' */

  /* Outputs for Enabled SubSystem: '<S1>/rss_MotoSpdLoLvl1Dia' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_MotoSpdHiLvl1Dia' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (rtb_Equal_c0gx) {
    /* Saturate: '<S16>/Saturation1' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    if (busOBD_SlwTaskIn.s16_nActElecSpd >= -32767) {
      rtb_Saturation1_kizi = busOBD_SlwTaskIn.s16_nActElecSpd;
    } else {
      rtb_Saturation1_kizi = -32767;
    }

    /* End of Saturate: '<S16>/Saturation1' */

    /* Selector: '<S16>/Selector2' incorporates:
     *  Constant: '<S16>/Constant8'
     */
    rtb_Selector2_mxk4 = rtb_Switch[MOTO_SPD_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S161>/ens_Deb' incorporates:
     *  EnablePort: '<S162>/Enable'
     */
    if (rtb_Selector2_mxk4) {
      /* Abs: '<S162>/Abs' incorporates:
       *  Constant: '<S162>/Constant16'
       *  Constant: '<S162>/Constant17'
       *  Constant: '<S162>/Constant18'
       *  Constant: '<S162>/Constant19'
       *  Constant: '<S162>/Constant2'
       *  Constant: '<S162>/Constant3'
       *  Saturate: '<S16>/Saturation1'
       */
      if (rtb_Saturation1_kizi < 0) {
        minV = (sint16)(-rtb_Saturation1_kizi);
      } else {
        minV = rtb_Saturation1_kizi;
      }

      /* Outputs for Atomic SubSystem: '<S162>/lib_HysDeb_14' */
      ASW_OBD_lib_HysDeb_14(minV, Gu16_nMotoSpdHiLvl1ConfTrs_C,
                            Gu16_nMotoSpdHiLvl1RcvyTrs_C,
                            Gu16_ctMotoSpdHiLvl1ConfCnt_C,
                            Gu16_ctMotoSpdHiLvl1RcvyCnt_C, true, false,
                            &ASW_OBD_B.Switch1_asmr,
                            &rtb_RelationalOperator1_a4nw,
                            &rtb_RelationalOperator_gvkq,
                            &ASW_OBD_DW.lib_HysDeb_14);

      /* End of Abs: '<S162>/Abs' */
      /* End of Outputs for SubSystem: '<S162>/lib_HysDeb_14' */
    }

    /* End of Outputs for SubSystem: '<S161>/ens_Deb' */

    /* Outputs for Atomic SubSystem: '<S161>/lib_FaltDefd_22' */
    /* Selector: '<S16>/Selector9' incorporates:
     *  Constant: '<S16>/Constant8'
     *  Selector: '<S16>/Selector2'
     *  Selector: '<S16>/Selector21'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.Switch1_asmr, rtb_Selector2_mxk4,
      rtb_DataTypeConversion[MOTO_SPD_HI_LVL1],
      rtb_DataTypeConversion1[MOTO_SPD_HI_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_nmp1,
      &ASW_OBD_B.stFaltDef_Perm_naf3, &ASW_OBD_B.FaltCycAccCnt_beqh,
      Gu16_ctMotoSpdHiLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_22);

    /* End of Outputs for SubSystem: '<S161>/lib_FaltDefd_22' */

    /* Saturate: '<S17>/Saturation' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    if (busOBD_SlwTaskIn.s16_nRmpRefElecSpd >= -32767) {
      rtb_Saturation = busOBD_SlwTaskIn.s16_nRmpRefElecSpd;
    } else {
      rtb_Saturation = -32767;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* Saturate: '<S17>/Saturation1' incorporates:
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     */
    if (busOBD_SlwTaskIn.s16_nActElecSpd >= -32767) {
      rtb_Saturation1_kx2o = busOBD_SlwTaskIn.s16_nActElecSpd;
    } else {
      rtb_Saturation1_kx2o = -32767;
    }

    /* End of Saturate: '<S17>/Saturation1' */

    /* Selector: '<S17>/Selector2' incorporates:
     *  Constant: '<S17>/Constant4'
     */
    rtb_Selector2_gpod = rtb_Switch[MOTO_SPD_LO_LVL1];

    /* Outputs for Enabled SubSystem: '<S168>/ens_JudgDeb' incorporates:
     *  EnablePort: '<S169>/Enable'
     */
    if (rtb_Selector2_gpod) {
      /* Abs: '<S169>/Abs' incorporates:
       *  Saturate: '<S17>/Saturation'
       */
      if (rtb_Saturation < 0) {
        minV = (sint16)(-rtb_Saturation);
      } else {
        minV = rtb_Saturation;
      }

      /* Abs: '<S169>/Abs1' incorporates:
       *  Saturate: '<S17>/Saturation1'
       */
      if (rtb_Saturation1_kx2o < 0) {
        rtb_Switch_kftc_idx_0 = (sint16)(-rtb_Saturation1_kx2o);
      } else {
        rtb_Switch_kftc_idx_0 = rtb_Saturation1_kx2o;
      }

      /* Sum: '<S169>/Subtract' incorporates:
       *  Abs: '<S169>/Abs'
       *  Abs: '<S169>/Abs1'
       */
      rtb_Subtract = (sint16)((minV - rtb_Switch_kftc_idx_0) >> 1);

      /* Saturate: '<S169>/Saturation3' incorporates:
       *  Sum: '<S169>/Subtract'
       */
      i = (rtb_Subtract << 1);
      if (i >= 32767) {
        rtb_Saturation3 = MAX_int16_T;
      } else if (i <= -32767) {
        rtb_Saturation3 = -32767;
      } else {
        rtb_Saturation3 = (sint16)(rtb_Subtract << 1);
      }

      /* End of Saturate: '<S169>/Saturation3' */

      /* Outputs for Atomic SubSystem: '<S169>/lib_HysDeb_15' */
      /* Chart: '<S174>/sfc_Debounce1' incorporates:
       *  Constant: '<S169>/OBD_ctIGBTHiDebOK_C'
       *  Constant: '<S169>/Parameter1'
       *  RelationalOperator: '<S174>/Relational Operator'
       *  Saturate: '<S169>/Saturation3'
       */
      ASW_OBD_sfc_Debounce((rtb_Saturation3 < Gs16_nMinMotoSpdDvtRcvyTrs_C),
                           Gu16_ctMinMotoSpdDvtRcvyCnt_C,
                           &rtb_stFaltDef_Tmpr_erdn,
                           &ASW_OBD_DW.sf_sfc_Debounce1);

      /* Chart: '<S174>/sfc_Debounce' incorporates:
       *  Constant: '<S169>/OBD_ctIGBTHiDebDef_C'
       *  Constant: '<S169>/Parameter2'
       *  RelationalOperator: '<S174>/Relational Operator1'
       *  Saturate: '<S169>/Saturation3'
       */
      ASW_OBD_sfc_Debounce((rtb_Saturation3 > Gs16_nMaxMotoSpdDvtConfTrs_C),
                           Gu16_ctMaxMotoSpdDvtConfCnt_C,
                           &rtb_stFaltDef_Perm_bryy, &ASW_OBD_DW.sf_sfc_Debounce);

      /* Switch: '<S174>/Switch1' incorporates:
       *  Constant: '<S169>/Parameter5'
       *  Switch: '<S174>/Switch'
       *  UnitDelay: '<S174>/Unit Delay2'
       */
      if (rtb_stFaltDef_Perm_bryy) {
        rtb_Switch1_p0m3 = true;
      } else {
        rtb_Switch1_p0m3 = ((!rtb_stFaltDef_Tmpr_erdn) &&
                            (ASW_OBD_DW.bitsForTID1.UnitDelay2_DSTATE));
      }

      /* End of Switch: '<S174>/Switch1' */

      /* Update for UnitDelay: '<S174>/Unit Delay2' */
      ASW_OBD_DW.bitsForTID1.UnitDelay2_DSTATE = rtb_Switch1_p0m3;

      /* End of Outputs for SubSystem: '<S169>/lib_HysDeb_15' */

      /* Logic: '<S169>/OR2' incorporates:
       *  Constant: '<S171>/Constant'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  RelationalOperator: '<S171>/Compare'
       */
      ASW_OBD_B.bitsForTID1.OR2 = ((busOBD_SlwTaskIn.enm_stMotoSt == CLOSED_LOOP)
        && rtb_Switch1_p0m3);
    }

    /* End of Outputs for SubSystem: '<S168>/ens_JudgDeb' */

    /* Outputs for Atomic SubSystem: '<S168>/lib_FaltDefd_23' */
    /* Selector: '<S17>/Selector1' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Selector: '<S17>/Selector2'
     *  Selector: '<S17>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.bitsForTID1.OR2, rtb_Selector2_gpod,
      rtb_DataTypeConversion[MOTO_SPD_LO_LVL1],
      rtb_DataTypeConversion1[MOTO_SPD_LO_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_j3ha,
      &ASW_OBD_B.stFaltDef_Perm_ilgb, &ASW_OBD_B.FaltCycAccCnt_fd2e,
      Gu16_ctMaxMotoSpdDvtConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_23);

    /* End of Outputs for SubSystem: '<S168>/lib_FaltDefd_23' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_MotoSpdHiLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_MotoSpdLoLvl1Dia' */

  /* Outputs for Enabled SubSystem: '<S1>/rss_PhCurrSensFaltDia' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S32>/rss_PhiSensFaltDiaHybr' incorporates:
   *  EnablePort: '<S300>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_GDVltgHiLvl1Dia' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_GDVltgLoLvl1Dia' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtb_Equal_cipx) {
    /* Selector: '<S13>/Selector2' incorporates:
     *  Constant: '<S13>/Constant8'
     */
    rtb_Selector2_mbkm = rtb_Switch[GD_VLTG_LO_LVL1];

    /* Outputs for Enabled SubSystem: '<S143>/ens_Deb_GEELY' incorporates:
     *  EnablePort: '<S145>/Enable'
     */
    if (rtb_Selector2_mbkm) {
      /* Outputs for Atomic SubSystem: '<S145>/lib_Deb_15' */
      /* SignalConversion generated from: '<S145>/bol_flgGDVltgLoLvl1' incorporates:
       *  Constant: '<S145>/Constant1'
       *  Constant: '<S145>/Constant4'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_lib_Deb_11(busOBD_SlwTaskIn.bol_flgGDVltgLoLvl1,
                         Gu16_ctGDVltgLoLvl1ConfCnt_C,
                         Gu16_ctGDVltgLoLvl1RcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_j4vj, &ASW_OBD_DW.lib_Deb_15);

      /* End of Outputs for SubSystem: '<S145>/lib_Deb_15' */
    }

    /* End of Outputs for SubSystem: '<S143>/ens_Deb_GEELY' */

    /* Outputs for Atomic SubSystem: '<S142>/lib_FaltDefd_7' */
    /* Selector: '<S13>/Selector9' incorporates:
     *  Constant: '<S13>/Constant8'
     *  Selector: '<S13>/Selector2'
     *  Selector: '<S13>/Selector21'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_j4vj, rtb_Selector2_mbkm,
      rtb_DataTypeConversion[GD_VLTG_LO_LVL1],
      rtb_DataTypeConversion1[GD_VLTG_LO_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_hsig,
      &ASW_OBD_B.stFaltDef_Perm_g0ii, &ASW_OBD_B.FaltCycAccCnt_ei2t,
      Gu16_ctGDVltgLoLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_7);

    /* End of Outputs for SubSystem: '<S142>/lib_FaltDefd_7' */

    /* Selector: '<S12>/Selector2' incorporates:
     *  Constant: '<S12>/Constant8'
     */
    rtb_Selector2_hi2t = rtb_Switch[GD_VLTG_HI_LVL1];

    /* Outputs for Enabled SubSystem: '<S136>/ens_Deb_GEELY' incorporates:
     *  EnablePort: '<S138>/Enable'
     */
    if (rtb_Selector2_hi2t) {
      /* Outputs for Atomic SubSystem: '<S138>/lib_Deb_16' */
      /* SignalConversion generated from: '<S138>/bol_flgGDVltgHiLvl1' incorporates:
       *  Constant: '<S138>/Constant1'
       *  Constant: '<S138>/Constant4'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_lib_Deb_11(busOBD_SlwTaskIn.bol_flgGDVltgHiLvl1,
                         Gu16_ctGDVltgHiLvl1ConfCnt_C,
                         Gu16_ctGDVltgHiLvl1RcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_hynf, &ASW_OBD_DW.lib_Deb_16);

      /* End of Outputs for SubSystem: '<S138>/lib_Deb_16' */
    }

    /* End of Outputs for SubSystem: '<S136>/ens_Deb_GEELY' */

    /* Outputs for Atomic SubSystem: '<S135>/lib_FaltDefd_8' */
    /* Selector: '<S12>/Selector9' incorporates:
     *  Constant: '<S12>/Constant8'
     *  Selector: '<S12>/Selector2'
     *  Selector: '<S12>/Selector21'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_hynf, rtb_Selector2_hi2t,
      rtb_DataTypeConversion[GD_VLTG_HI_LVL1],
      rtb_DataTypeConversion1[GD_VLTG_HI_LVL1], &ASW_OBD_B.stFaltDef_Tmpr_im4y,
      &ASW_OBD_B.stFaltDef_Perm_dgcc, &ASW_OBD_B.FaltCycAccCnt_et1a,
      Gu16_ctGDVltgHiLvl1ConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_8);

    /* End of Outputs for SubSystem: '<S135>/lib_FaltDefd_8' */

    /* Selector: '<S300>/Selector2' incorporates:
     *  Constant: '<S300>/Constant4'
     */
    rtb_Selector2_pigy = rtb_Switch[PHI_SENS_FALT];

    /* Outputs for Enabled SubSystem: '<S301>/ens_HysDeb' incorporates:
     *  EnablePort: '<S303>/Enable'
     */
    if (rtb_Selector2_pigy) {
      /* SignalConversion generated from: '<S303>/bol_flgPhiSensFalt' incorporates:
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_B.bitsForTID1.bol_flgPhiSensFalt =
        busOBD_SlwTaskIn.bol_flgPhiSensFalt;

      /* Outputs for Atomic SubSystem: '<S303>/lib_Deb_2' */
      /* Constant: '<S303>/Constant2' incorporates:
       *  Constant: '<S303>/Constant3'
       */
      ASW_OBD_lib_Deb_11(ASW_OBD_B.bitsForTID1.bol_flgPhiSensFalt,
                         Gu16_ctPhiSensFaltConfCnt_C,
                         Gu16_ctPhiSensFaltRcvyCnt_C, &ASW_OBD_B.lb_genOutp,
                         &ASW_OBD_DW.lib_Deb_2);

      /* End of Outputs for SubSystem: '<S303>/lib_Deb_2' */
    }

    /* End of Outputs for SubSystem: '<S301>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S301>/lib_FaltDefd_10' */
    /* Selector: '<S300>/Selector1' incorporates:
     *  Constant: '<S300>/Constant4'
     *  Selector: '<S300>/Selector2'
     *  Selector: '<S300>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp, rtb_Selector2_pigy,
      rtb_DataTypeConversion[PHI_SENS_FALT],
      rtb_DataTypeConversion1[PHI_SENS_FALT], &ASW_OBD_B.stFaltDef_Tmpr,
      &ASW_OBD_B.stFaltDef_Perm, &ASW_OBD_B.FaltCycAccCnt,
      Gu16_ctPhiSensFaltConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_10);

    /* End of Outputs for SubSystem: '<S301>/lib_FaltDefd_10' */

    /* Logic: '<S301>/Logical Operator' incorporates:
     *  Constant: '<S302>/Constant'
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     *  RelationalOperator: '<S302>/Compare'
     */
    ASW_OBD_B.bitsForTID1.LogicalOperator = ((ASW_OBD_B.stFaltDef_Perm) &&
      (busOBD_SlwTaskIn.enm_modeAgEvalMode != SENSORLESS));

    /* Selector: '<S23>/Selector2' incorporates:
     *  Constant: '<S23>/Constant4'
     */
    rtb_Selector2_orvk = rtb_Switch[PH_CURR_SENS_FALT];

    /* Outputs for Enabled SubSystem: '<S213>/ens_JudgDeb' incorporates:
     *  EnablePort: '<S214>/Enable'
     */
    if (rtb_Selector2_orvk) {
      /* Logic: '<S217>/Logical Operator2' incorporates:
       *  Constant: '<S217>/Constant1'
       *  Constant: '<S217>/Constant3'
       *  Constant: '<S217>/Constant4'
       *  Constant: '<S217>/Constant5'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  Logic: '<S217>/Logical Operator'
       *  Logic: '<S217>/Logical Operator1'
       *  RelationalOperator: '<S217>/Relational Operator'
       *  RelationalOperator: '<S217>/Relational Operator2'
       *  RelationalOperator: '<S217>/Relational Operator3'
       *  RelationalOperator: '<S217>/Relational Operator4'
       */
      ASW_OBD_B.bitsForTID1.LogicalOperator2_fqo5 =
        (((busOBD_SlwTaskIn.u16_uADActPhCurr[0] >= Gu16_uADPhUCurrFaltHiLim_C) ||
          (busOBD_SlwTaskIn.u16_uADActPhCurr[0] <= Gu16_uADPhUCurrFaltLoLim_C)) ||
         ((busOBD_SlwTaskIn.u16_uADActPhCurr[1] >= Gu16_uADPhVCurrFaltHiLim_C) ||
          (busOBD_SlwTaskIn.u16_uADActPhCurr[1] <= Gu16_uADPhVCurrFaltLoLim_C)));

      /* Outputs for Atomic SubSystem: '<S214>/lib_Deb_3' */
      /* Constant: '<S214>/Constant2' incorporates:
       *  Constant: '<S214>/Constant3'
       */
      ASW_OBD_lib_Deb_11(ASW_OBD_B.bitsForTID1.LogicalOperator2_fqo5,
                         Gu16_ctPhCurrSensFaltConfCnt_C,
                         Gu16_ctPhCurrSensFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_gw2t, &ASW_OBD_DW.lib_Deb_3);

      /* End of Outputs for SubSystem: '<S214>/lib_Deb_3' */
    }

    /* End of Outputs for SubSystem: '<S213>/ens_JudgDeb' */

    /* Outputs for Atomic SubSystem: '<S213>/lib_FaltDefd_11' */
    /* Selector: '<S23>/Selector1' incorporates:
     *  Constant: '<S23>/Constant4'
     *  Selector: '<S23>/Selector2'
     *  Selector: '<S23>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_gw2t, rtb_Selector2_orvk,
      rtb_DataTypeConversion[PH_CURR_SENS_FALT],
      rtb_DataTypeConversion1[PH_CURR_SENS_FALT], &ASW_OBD_B.stFaltDef_Tmpr_ics0,
      &ASW_OBD_B.stFaltDef_Perm_omzh, &ASW_OBD_B.FaltCycAccCnt_buyv,
      Gu16_ctPhCurrSensFaltConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_11);

    /* End of Outputs for SubSystem: '<S213>/lib_FaltDefd_11' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_GDVltgLoLvl1Dia' */
  /* End of Outputs for SubSystem: '<S1>/rss_GDVltgHiLvl1Dia' */
  /* End of Outputs for SubSystem: '<S32>/rss_PhiSensFaltDiaHybr' */
  /* End of Outputs for SubSystem: '<S1>/rss_PhCurrSensFaltDia' */

  /* Outputs for Enabled SubSystem: '<S1>/rss_MotoTempSensFaltDia' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/rss_PwrTubPCBTempSensFaltDia' incorporates:
   *  EnablePort: '<S26>/Enable'
   */
  if (rtb_Equal_c0gx) {
    /* Selector: '<S26>/Selector2' incorporates:
     *  Constant: '<S26>/Constant4'
     */
    rtb_Selector2_c5tw = rtb_Switch[PWR_TUB_PCB_TEMP_SENS_FALT];

    /* Outputs for Enabled SubSystem: '<S242>/ens_HysDeb' incorporates:
     *  EnablePort: '<S243>/Enable'
     */
    if (rtb_Selector2_c5tw) {
      /* Saturate: '<S256>/Saturation' incorporates:
       *  Constant: '<S256>/Constant'
       */
      if (Gu8_tMaxNTCMCUTempDvt_C > 110) {
        maxV = 110U;
      } else if (Gu8_tMaxNTCMCUTempDvt_C < 40) {
        maxV = 40U;
      } else {
        maxV = Gu8_tMaxNTCMCUTempDvt_C;
      }

      /* Switch: '<S248>/Switch1' incorporates:
       *  Constant: '<S248>/Constant1'
       *  Constant: '<S248>/Constant4'
       *  Constant: '<S248>/Constant6'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  Logic: '<S248>/Logical Operator2'
       *  RelationalOperator: '<S248>/Relational Operator4'
       *  RelationalOperator: '<S248>/Relational Operator5'
       *  RelationalOperator: '<S248>/Relational Operator7'
       *  Saturate: '<S256>/Saturation'
       *  Sum: '<S248>/Add1'
       *  UnitDelay: '<S248>/Unit Delay'
       */
      if ((((uint8)((busOBD_SlwTaskIn.u8_tPwrTubTemp + maxV) - 40)) <
           busOBD_SlwTaskIn.u8_tMCUTemp) && (busOBD_SlwTaskIn.u8_tPwrTubTemp <=
           Gu8_tNTCTempSensOpnCir_C)) {
        rtb_Switch1_cxed = true;
      } else {
        rtb_Switch1_cxed = ((busOBD_SlwTaskIn.u8_tPwrTubTemp <=
                             Gu8_tNTCTempSensNoOpnCir_C) &&
                            (ASW_OBD_DW.bitsForTID1.UnitDelay_DSTATE_igiu));
      }

      /* End of Switch: '<S248>/Switch1' */

      /* Logic: '<S248>/Logical Operator3' incorporates:
       *  Constant: '<S248>/Constant5'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  RelationalOperator: '<S248>/Relational Operator6'
       */
      rtb_LogicalOperator3 = (rtb_Switch1_cxed ||
        (busOBD_SlwTaskIn.u16_uADPwrTubTemp <= Gu16_uADPwrTubTempFaltLoLim_C));

      /* Outputs for Atomic SubSystem: '<S243>/lib_Deb_12' */
      /* Constant: '<S243>/Constant9' incorporates:
       *  Constant: '<S243>/Constant10'
       */
      rtb_stFaltDef_Tmpr_erdn = ASW_OBD_lib_Deb_12(rtb_LogicalOperator3,
        Gu16_ctPwrTubTempFaltConfCnt_C, Gu16_ctPwrTubTempFaltRcvyCnt_C,
        &ASW_OBD_DW.lib_Deb_12);

      /* End of Outputs for SubSystem: '<S243>/lib_Deb_12' */

      /* Saturate: '<S253>/Saturation' incorporates:
       *  Constant: '<S253>/Constant'
       */
      if (Gu8_tMaxNTCMCUTempDvt_C > 110) {
        maxV = 110U;
      } else if (Gu8_tMaxNTCMCUTempDvt_C < 40) {
        maxV = 40U;
      } else {
        maxV = Gu8_tMaxNTCMCUTempDvt_C;
      }

      /* Switch: '<S247>/Switch1' incorporates:
       *  Constant: '<S247>/Constant1'
       *  Constant: '<S247>/Constant2'
       *  Constant: '<S247>/Constant4'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  Logic: '<S247>/Logical Operator2'
       *  RelationalOperator: '<S247>/Relational Operator1'
       *  RelationalOperator: '<S247>/Relational Operator2'
       *  RelationalOperator: '<S247>/Relational Operator4'
       *  Saturate: '<S253>/Saturation'
       *  Sum: '<S247>/Add'
       *  UnitDelay: '<S247>/Unit Delay'
       */
      if ((((uint8)((busOBD_SlwTaskIn.u8_tPCBTemp + maxV) - 40)) <
           busOBD_SlwTaskIn.u8_tMCUTemp) && (busOBD_SlwTaskIn.u8_tPCBTemp <=
           Gu8_tNTCTempSensOpnCir_C)) {
        rtb_Switch1_e2vj = true;
      } else {
        rtb_Switch1_e2vj = ((busOBD_SlwTaskIn.u8_tPCBTemp <=
                             Gu8_tNTCTempSensNoOpnCir_C) &&
                            (ASW_OBD_DW.bitsForTID1.UnitDelay_DSTATE_o2r0));
      }

      /* End of Switch: '<S247>/Switch1' */

      /* Logic: '<S247>/Logical Operator1' incorporates:
       *  Constant: '<S247>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  RelationalOperator: '<S247>/Relational Operator3'
       */
      rtb_LogicalOperator1_cf41 = (rtb_Switch1_e2vj ||
        (busOBD_SlwTaskIn.u16_uADPCBTemp <= Gu16_uADPCBTempFaltLoLim_C));

      /* Outputs for Atomic SubSystem: '<S243>/lib_Deb_13' */
      /* Constant: '<S243>/Constant12' incorporates:
       *  Constant: '<S243>/Constant11'
       */
      rtb_stFaltDef_Perm_bryy = ASW_OBD_lib_Deb_12(rtb_LogicalOperator1_cf41,
        Gu16_ctPCBTempFaltConfCnt_C, Gu16_ctPCBTempFaltRcvyCnt_C,
        &ASW_OBD_DW.lib_Deb_13);

      /* End of Outputs for SubSystem: '<S243>/lib_Deb_13' */

      /* Logic: '<S243>/Logical Operator2' */
      ASW_OBD_B.bitsForTID1.LogicalOperator2 = (rtb_stFaltDef_Tmpr_erdn ||
        rtb_stFaltDef_Perm_bryy);

      /* Logic: '<S243>/Logical Operator1' */
      ASW_OBD_B.bitsForTID1.LogicalOperator1_c3mb = (rtb_LogicalOperator3 ||
        rtb_LogicalOperator1_cf41);

      /* Update for UnitDelay: '<S248>/Unit Delay' */
      ASW_OBD_DW.bitsForTID1.UnitDelay_DSTATE_igiu = rtb_Switch1_cxed;

      /* Update for UnitDelay: '<S247>/Unit Delay' */
      ASW_OBD_DW.bitsForTID1.UnitDelay_DSTATE_o2r0 = rtb_Switch1_e2vj;
    }

    /* End of Outputs for SubSystem: '<S242>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S242>/lib_FaltDefd_24' */
    /* Selector: '<S26>/Selector1' incorporates:
     *  Constant: '<S26>/Constant4'
     *  Selector: '<S26>/Selector2'
     *  Selector: '<S26>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.bitsForTID1.LogicalOperator2,
      rtb_Selector2_c5tw, rtb_DataTypeConversion[PWR_TUB_PCB_TEMP_SENS_FALT],
      rtb_DataTypeConversion1[PWR_TUB_PCB_TEMP_SENS_FALT],
      &ASW_OBD_B.stFaltDef_Tmpr_keux, &ASW_OBD_B.stFaltDef_Perm_i2o3,
      &ASW_OBD_B.FaltCycAccCnt_kent, Gu16_ctPCBTempFaltConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_24);

    /* End of Outputs for SubSystem: '<S242>/lib_FaltDefd_24' */

    /* Selector: '<S20>/Selector2' incorporates:
     *  Constant: '<S20>/Constant4'
     */
    rtb_Selector2_l3ro = rtb_Switch[MOTO_TEMP_SENS_FALT];

    /* Outputs for Enabled SubSystem: '<S192>/ens_HysDeb' incorporates:
     *  EnablePort: '<S193>/Enable'
     */
    if (rtb_Selector2_l3ro) {
      /* Logic: '<S196>/Logical Operator' incorporates:
       *  Constant: '<S196>/Constant1'
       *  Constant: '<S196>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       *  RelationalOperator: '<S196>/Relational Operator'
       *  RelationalOperator: '<S196>/Relational Operator2'
       */
      ASW_OBD_B.bitsForTID1.LogicalOperator_kubn =
        ((busOBD_SlwTaskIn.u16_uADMotoTemp >= Gu16_uADMotoTempFaltHiLim_C) ||
         (busOBD_SlwTaskIn.u16_uADMotoTemp <= Gu16_uADMotoTempFaltLoLim_C));

      /* Outputs for Atomic SubSystem: '<S193>/lib_Deb_14' */
      /* Constant: '<S193>/Constant9' incorporates:
       *  Constant: '<S193>/Constant10'
       */
      ASW_OBD_lib_Deb_11(ASW_OBD_B.bitsForTID1.LogicalOperator_kubn,
                         Gu16_ctMotoTempFaltConfCnt_C,
                         Gu16_ctMotoTempFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_f0nq, &ASW_OBD_DW.lib_Deb_14);

      /* End of Outputs for SubSystem: '<S193>/lib_Deb_14' */
    }

    /* End of Outputs for SubSystem: '<S192>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S192>/lib_FaltDefd_25' */
    /* Selector: '<S20>/Selector1' incorporates:
     *  Constant: '<S20>/Constant4'
     *  Selector: '<S20>/Selector2'
     *  Selector: '<S20>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_f0nq, rtb_Selector2_l3ro,
      rtb_DataTypeConversion[MOTO_TEMP_SENS_FALT],
      rtb_DataTypeConversion1[MOTO_TEMP_SENS_FALT],
      &ASW_OBD_B.stFaltDef_Tmpr_dr1m, &ASW_OBD_B.stFaltDef_Perm_cm35,
      &ASW_OBD_B.FaltCycAccCnt_ibsm, Gu16_ctMotoTempFaltConfCnt_C,
      &ASW_OBD_DW.lib_FaltDefd_25);

    /* End of Outputs for SubSystem: '<S192>/lib_FaltDefd_25' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_PwrTubPCBTempSensFaltDia' */
  /* End of Outputs for SubSystem: '<S1>/rss_MotoTempSensFaltDia' */

  /* Outputs for Enabled SubSystem: '<S1>/rss_MosOpnCirFaltDia' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (rtb_Equal_cipx) {
    /* Selector: '<S15>/Selector2' incorporates:
     *  Constant: '<S15>/Constant4'
     */
    rtb_Selector2_p5mv = rtb_Switch[MOSOPNCIR_FALT];

    /* Outputs for Enabled SubSystem: '<S155>/ens_HysDeb' incorporates:
     *  EnablePort: '<S156>/Enable'
     */
    if (rtb_Selector2_p5mv) {
      /* Outputs for Atomic SubSystem: '<S156>/lib_Deb_17' */
      /* SignalConversion generated from: '<S156>/bol_flgMosOpnCirFalt' incorporates:
       *  Constant: '<S156>/Constant2'
       *  Constant: '<S156>/Constant3'
       *  Inport: '<Root>/busOBD_SlwTaskIn'
       */
      ASW_OBD_lib_Deb_11(busOBD_SlwTaskIn.bol_flgMosOpnCirFalt,
                         Gu16_ctMosOpnCirFaltConfCnt_C,
                         Gu16_ctMosOpnCirFaltRcvyCnt_C,
                         &ASW_OBD_B.lb_genOutp_lsbp, &ASW_OBD_DW.lib_Deb_17_erkz);

      /* End of Outputs for SubSystem: '<S156>/lib_Deb_17' */
    }

    /* End of Outputs for SubSystem: '<S155>/ens_HysDeb' */

    /* Outputs for Atomic SubSystem: '<S155>/lib_FaltDefd_9' */
    /* Selector: '<S15>/Selector1' incorporates:
     *  Constant: '<S15>/Constant4'
     *  Selector: '<S15>/Selector2'
     *  Selector: '<S15>/Selector7'
     */
    ASW_OBD_lib_FaltDefd_21(ASW_OBD_B.lb_genOutp_lsbp, rtb_Selector2_p5mv,
      rtb_DataTypeConversion[MOSOPNCIR_FALT],
      rtb_DataTypeConversion1[MOSOPNCIR_FALT], &ASW_OBD_B.stFaltDef_Tmpr_otno,
      &ASW_OBD_B.stFaltDef_Perm_gulm, &ASW_OBD_B.FaltCycAccCnt_jfr4,
      Gu16_ctMosOpnCirFaltConfCnt_C, &ASW_OBD_DW.lib_FaltDefd_9_hcdo);

    /* End of Outputs for SubSystem: '<S155>/lib_FaltDefd_9' */
  }

  /* End of Outputs for SubSystem: '<S1>/rss_MosOpnCirFaltDia' */

  /* BusCreator: '<S9>/Bus Creator1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  ASW_OBD_B.BusCreator1.bol_flgPhCurrHiLvl1Flg = ASW_OBD_B.stFaltDef_Perm_lijp;
  ASW_OBD_B.BusCreator1.bol_flgHWOvrCurrFlg = ASW_OBD_B.stFaltDef_Perm_dzb0;
  ASW_OBD_B.BusCreator1.bol_flgSplyVltgLoLvl1Flg = ASW_OBD_B.stFaltDef_Perm_ktdp;
  ASW_OBD_B.BusCreator1.bol_flgSplyVltgLoLvl2Flg = ASW_OBD_B.stFaltDef_Perm_efmb;
  ASW_OBD_B.BusCreator1.bol_flgSplyVltgHiLvl1Flg = ASW_OBD_B.stFaltDef_Perm_f4wg;
  ASW_OBD_B.BusCreator1.bol_flgPwrTubPCBTempHiLvl1Flg =
    ASW_OBD_B.stFaltDef_Perm_dthc;
  ASW_OBD_B.BusCreator1.bol_flgPwrTubPCBTempHiLvl2Flg =
    ASW_OBD_B.bitsForTID1.LogicalOperator1_cq5m;
  ASW_OBD_B.BusCreator1.bol_flgMotoTempHiLvl1Flg = ASW_OBD_B.stFaltDef_Perm_h1g3;
  ASW_OBD_B.BusCreator1.bol_flgMotoTempHiLvl2Flg = ASW_OBD_B.stFaltDef_Perm_b5ga;
  ASW_OBD_B.BusCreator1.bol_flgComFaltFlg =
    ASW_OBD_B.bitsForTID1.stFaltDef_Perm_l1lp;
  ASW_OBD_B.BusCreator1.bol_flgMotoStallPermFlg = ASW_OBD_B.stFaltDef_Perm_g4b1;
  ASW_OBD_B.BusCreator1.bol_flgMotoStallTmpFlg = ASW_OBD_B.stFaltDef_Tmpr_gjm2;
  ASW_OBD_B.BusCreator1.bol_flgNoLdFlg = ASW_OBD_B.stFaltDef_Perm_kt5c;
  ASW_OBD_B.BusCreator1.bol_flgBattPwrHiLvl1Flg = ASW_OBD_B.stFaltDef_Perm_iopf;
  ASW_OBD_B.BusCreator1.bol_flgMotoSpdHiLvl1Flg = ASW_OBD_B.stFaltDef_Perm_naf3;
  ASW_OBD_B.BusCreator1.bol_flgMotoSpdLoLvl1Flg = ASW_OBD_B.stFaltDef_Perm_ilgb;
  ASW_OBD_B.BusCreator1.bol_flgCtlBrdVltgLoLvl1Flg =
    ASW_OBD_B.stFaltDef_Perm_nbju;
  ASW_OBD_B.BusCreator1.bol_flgCtlBrdVltgHiLvl1Flg =
    ASW_OBD_B.stFaltDef_Perm_ofvs;
  ASW_OBD_B.BusCreator1.bol_flgGDVltgLoLvl1Flg = ASW_OBD_B.stFaltDef_Perm_g0ii;
  ASW_OBD_B.BusCreator1.bol_flgGDVltgHiLvl1Flg = ASW_OBD_B.stFaltDef_Perm_dgcc;
  ASW_OBD_B.BusCreator1.bol_flgChipFaltFlg = ASW_OBD_B.stFaltDef_Perm_mvmh;
  ASW_OBD_B.BusCreator1.bol_flgPhiSensFaltFlg =
    ASW_OBD_B.bitsForTID1.LogicalOperator;
  ASW_OBD_B.BusCreator1.bol_flgPhCurrSensFaltFlg = ASW_OBD_B.stFaltDef_Perm_omzh;
  ASW_OBD_B.BusCreator1.bol_flgPwrTubPCBTempSensFaltFlg =
    ASW_OBD_B.stFaltDef_Perm_i2o3;
  ASW_OBD_B.BusCreator1.bol_flgMotoTempSensFaltFlg =
    ASW_OBD_B.stFaltDef_Perm_cm35;
  ASW_OBD_B.BusCreator1.bol_flgBusOffFaltFlg = ASW_OBD_B.stFaltDef_Perm_nx2u;
  ASW_OBD_B.BusCreator1.bol_flgCrashFaltFlg = ASW_OBD_B.stFaltDef_Perm_bpps;
  ASW_OBD_B.BusCreator1.bol_flgMosOpnCirFaltFlg = ASW_OBD_B.stFaltDef_Perm_gulm;
  ASW_OBD_B.BusCreator1.bol_flgReserved4Flg = false;
  ASW_OBD_B.BusCreator1.bol_flgReserved5Flg = false;

  /* Outputs for Iterator SubSystem: '<S10>/sss_FaltLvlConf' */
  ASW_OBD_sss_FaltLvlConf();

  /* End of Outputs for SubSystem: '<S10>/sss_FaltLvlConf' */

  /* Outputs for Triggered SubSystem: '<S119>/sss_ComFaltMechSpdRespDefd_GEELY' incorporates:
   *  TriggerPort: '<S121>/Trigger'
   */
  if (rtb_Equal_c0gx && (ASW_OBD_PrevZCX.sss_ComFaltMechSpdRespDefd_GEEL !=
                         POS_ZCSIG)) {
    /* Switch: '<S122>/Switch1' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S121>/Constant8'
     *  Constant: '<S121>/Constant9'
     *  Inport: '<Root>/busOBD_SlwTaskIn'
     *  RelationalOperator: '<S122>/Relational Operator'
     *  RelationalOperator: '<S122>/Relational Operator1'
     *  UnitDelay: '<S122>/Unit Delay2'
     */
    if (busOBD_SlwTaskIn.u16_uSplyVltg > Gu16_uLimHmeSplyVltgConfTrs_C) {
      rtb_Switch1_avks = true;
    } else {
      rtb_Switch1_avks = ((busOBD_SlwTaskIn.u16_uSplyVltg >=
                           Gu16_uLimHmeSplyVltgRcvyTrs_C) &&
                          (ASW_OBD_DW.bitsForTID1.UnitDelay2_DSTATE_i4n0));
    }

    /* End of Switch: '<S122>/Switch1' */

    /* Switch: '<S121>/Switch3' incorporates:
     *  Constant: '<S121>/Constant6'
     *  Constant: '<S121>/Constant7'
     */
    if (rtb_Switch1_avks) {
      ASW_OBD_B.Switch3 = Gs16_nLmpHmeRefMechSpd_C;
    } else {
      ASW_OBD_B.Switch3 = 0;
    }

    /* End of Switch: '<S121>/Switch3' */

    /* Update for UnitDelay: '<S122>/Unit Delay2' */
    ASW_OBD_DW.bitsForTID1.UnitDelay2_DSTATE_i4n0 = rtb_Switch1_avks;
  }

  ASW_OBD_PrevZCX.sss_ComFaltMechSpdRespDefd_GEEL = rtb_Equal_c0gx;

  /* End of Outputs for SubSystem: '<S119>/sss_ComFaltMechSpdRespDefd_GEELY' */

  /* Switch: '<S123>/Switch1' incorporates:
   *  Constant: '<S123>/Constant17'
   *  Constant: '<S125>/Constant'
   *  RelationalOperator: '<S125>/Compare'
   */
  if (ASW_OBD_B.FaltCycAccCnt_advj != 0) {
    /* Switch: '<S123>/Switch' incorporates:
     *  Constant: '<S124>/Constant'
     *  Math: '<S123>/Mod'
     *  RelationalOperator: '<S124>/Compare'
     */
    if (((uint8)(ASW_OBD_B.FaltCycAccCnt_advj % 2)) != 0) {
      /* Switch: '<S123>/Switch1' incorporates:
       *  Constant: '<S123>/Constant1'
       */
      ASW_OBD_B.Switch1 = Gs16_nMotoTmpStallRefMechSpd_C;
    } else {
      /* Switch: '<S123>/Switch1' incorporates:
       *  Constant: '<S123>/Constant1'
       *  Gain: '<S123>/Gain'
       */
      ASW_OBD_B.Switch1 = (dt_Standardize_s16p15b0)
        (-Gs16_nMotoTmpStallRefMechSpd_C);
    }

    /* End of Switch: '<S123>/Switch' */
  } else {
    ASW_OBD_B.Switch1 = Gs16_nMaxRefMechSpd_C;
  }

  /* End of Switch: '<S123>/Switch1' */

  /* Outputs for Iterator SubSystem: '<S106>/sss_FaltLvl2Conf' */
  ASW_OBD_sss_FaltLvl2Conf();

  /* End of Outputs for SubSystem: '<S106>/sss_FaltLvl2Conf' */

  /* MinMax: '<S134>/Min' incorporates:
   *  Assignment: '<S133>/Assignment'
   */
  minV = ASW_OBD_B.Assignment[0];

  /* MinMax: '<S103>/Max' */
  maxV = ASW_OBD_B.Assignment_czft[0];

  /* MinMax: '<S134>/Min1' incorporates:
   *  Assignment: '<S133>/Assignment1'
   */
  rtb_Switch_kftc_idx_0 = ASW_OBD_B.Assignment1[0];
  for (i = 0; i < 29; i++) {
    /* MinMax: '<S134>/Min' incorporates:
     *  Assignment: '<S133>/Assignment'
     */
    rtb_Switch_kftc_idx_1 = ASW_OBD_B.Assignment[i + 1];
    if (minV <= rtb_Switch_kftc_idx_1) {
    } else {
      minV = rtb_Switch_kftc_idx_1;
    }

    /* MinMax: '<S103>/Max' */
    u1 = ASW_OBD_B.Assignment_czft[i + 1];
    if (maxV >= u1) {
    } else {
      maxV = u1;
    }

    /* MinMax: '<S134>/Min1' incorporates:
     *  Assignment: '<S133>/Assignment1'
     */
    rtb_Switch_kftc_idx_1 = ASW_OBD_B.Assignment1[i + 1];
    if (rtb_Switch_kftc_idx_0 <= rtb_Switch_kftc_idx_1) {
    } else {
      rtb_Switch_kftc_idx_0 = rtb_Switch_kftc_idx_1;
    }
  }

  /* SwitchCase: '<S104>/Switch Case' incorporates:
   *  MinMax: '<S103>/Max'
   */
  switch (maxV) {
   case 3:
    /* Outputs for IfAction SubSystem: '<S104>/sas_FaltLvl3' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    /* SignalConversion generated from: '<S109>/s16_nFaltRefMechSpdLvl3' incorporates:
     *  Constant: '<S109>/Constant'
     *  Merge: '<S104>/Merge'
     */
    busOBD_SlwTaskOut.s16_nFaltRefMechSpd = 0;

    /* SignalConversion generated from: '<S109>/s16_trqFaltRefTqLimLvl3' incorporates:
     *  Constant: '<S109>/Constant1'
     *  Merge: '<S104>/Merge1'
     */
    busOBD_SlwTaskOut.s16_trqFaltRefTqLim = 0;

    /* End of Outputs for SubSystem: '<S104>/sas_FaltLvl3' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S104>/sas_FaltLvl2' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    /* SignalConversion generated from: '<S108>/nFaltRefMechSpdSlcLevl2' incorporates:
     *  Merge: '<S104>/Merge'
     *  MinMax: '<S134>/Min'
     */
    busOBD_SlwTaskOut.s16_nFaltRefMechSpd = minV;

    /* SignalConversion generated from: '<S108>/tqFaltRefTrqLimSlcLevl2' incorporates:
     *  Merge: '<S104>/Merge1'
     *  MinMax: '<S134>/Min1'
     */
    busOBD_SlwTaskOut.s16_trqFaltRefTqLim = rtb_Switch_kftc_idx_0;

    /* End of Outputs for SubSystem: '<S104>/sas_FaltLvl2' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S104>/sas_FaltLvl1' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    /* SignalConversion generated from: '<S107>/s16_nFaltRefMechSpdLvl1' incorporates:
     *  Constant: '<S107>/Constant'
     *  Merge: '<S104>/Merge'
     */
    busOBD_SlwTaskOut.s16_nFaltRefMechSpd = Gs16_nMaxRefMechSpd_C;

    /* SignalConversion generated from: '<S107>/s16_trqFaltRefTqLimLvl1' incorporates:
     *  Constant: '<S107>/Constant1'
     *  Merge: '<S104>/Merge1'
     */
    busOBD_SlwTaskOut.s16_trqFaltRefTqLim = Gs16_trqTqUpLim_C;

    /* End of Outputs for SubSystem: '<S104>/sas_FaltLvl1' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S104>/sas_FaltLvlDfl' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    /* SignalConversion generated from: '<S110>/s16_nFaltRefMechSpdLvlDfl' incorporates:
     *  Constant: '<S110>/Constant'
     *  Merge: '<S104>/Merge'
     */
    busOBD_SlwTaskOut.s16_nFaltRefMechSpd = Gs16_nMaxRefMechSpd_C;

    /* SignalConversion generated from: '<S110>/s16_trqFaltRefTqLimLvlDfl' incorporates:
     *  Constant: '<S110>/Constant1'
     *  Merge: '<S104>/Merge1'
     */
    busOBD_SlwTaskOut.s16_trqFaltRefTqLim = Gs16_trqTqUpLim_C;

    /* End of Outputs for SubSystem: '<S104>/sas_FaltLvlDfl' */
    break;
  }

  /* End of SwitchCase: '<S104>/Switch Case' */

  /* BusCreator: '<S309>/Bus Creator1' incorporates:
   *  BusCreator: '<S9>/Bus Creator2'
   *  Constant: '<S9>/Constant8'
   *  MinMax: '<S103>/Max'
   */
  busOBD_SlwTaskOut.busOBD_FaltSt = ASW_OBD_B.BusCreator1;
  busOBD_SlwTaskOut.u8_stMaxFaltLvl = maxV;
  busOBD_SlwTaskOut.bol_flgPhiSensFaltRawFlg = ASW_OBD_B.stFaltDef_Perm;
  busOBD_SlwTaskOut.bol_flgComNodeLosFaltDeb = ASW_OBD_B.lb_genOutp_eatq;
  busOBD_SlwTaskOut.bol_flgComRolCntFaltDeb = ASW_OBD_B.lb_genOutp_lgdu;
  busOBD_SlwTaskOut.bol_flgCRCFaltDeb = ASW_OBD_B.lb_genOutp_ojfd;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPhCurrHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_glyd;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgHWOvrCurrTmp =
    ASW_OBD_B.OutportBufferForbol_flgHWOvrCur;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgSplyVltgLoLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_lgzj;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgSplyVltgLoLvl2Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_o3sb;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgSplyVltgHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_ni5x;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPwrTubPCBTempHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_mpvn;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPwrTubPCBTempHiLvl2Tmp =
    ASW_OBD_B.bitsForTID1.LogicalOperator2_hzmq;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoTempHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_pjcw;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoTempHiLvl2Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_izjl;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgComFaltTmp =
    ASW_OBD_B.bitsForTID1.stFaltDef_Tmpr_cu5h;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoStallPermTmp =
    ASW_OBD_B.stFaltDef_Tmpr_gjm2;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoStallTmpTmp =
    ASW_OBD_B.stFaltDef_Tmpr_gjm2;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgNoLdTmp =
    ASW_OBD_B.stFaltDef_Tmpr_cp2o;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgBattPwrHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_lhdo;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoSpdHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_nmp1;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoSpdLoLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_j3ha;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgCtlBrdVltgLoLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_bk0g;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgCtlBrdVltgHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_b1sa;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgGDVltgLoLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_hsig;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgGDVltgHiLvl1Tmp =
    ASW_OBD_B.stFaltDef_Tmpr_im4y;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgChipFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr_cbrr;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPhiSensFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPhCurrSensFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr_ics0;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgPwrTubPCBTempSensFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr_keux;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMotoTempSensFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr_dr1m;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgBusOffFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr_m0mb;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgCrashFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr_nqix;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgMosOpnCirFaltTmp =
    ASW_OBD_B.stFaltDef_Tmpr_otno;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgReserved4Tmp = false;
  busOBD_SlwTaskOut.busOBD_FaltStTmp.bol_flgReserved5Tmp = false;

  /* Switch: '<S98>/Switch' */
  if (rtb_Equal_kjhq) {
    /* Update for UnitDelay: '<S98>/Unit Delay' incorporates:
     *  Constant: '<S98>/Parameter1'
     */
    ASW_OBD_DW.UnitDelay_DSTATE_c13u = 1U;
  } else {
    /* Update for UnitDelay: '<S98>/Unit Delay' incorporates:
     *  Constant: '<S98>/Parameter2'
     *  Sum: '<S98>/Add1'
     */
    ASW_OBD_DW.UnitDelay_DSTATE_c13u++;
  }

  /* End of Switch: '<S98>/Switch' */

  /* Switch: '<S99>/Switch' */
  if (rtb_Equal_cipx) {
    /* Update for UnitDelay: '<S99>/Unit Delay' incorporates:
     *  Constant: '<S99>/Parameter1'
     */
    ASW_OBD_DW.UnitDelay_DSTATE_e34g = 1U;
  } else {
    /* Update for UnitDelay: '<S99>/Unit Delay' incorporates:
     *  Constant: '<S99>/Parameter2'
     *  Sum: '<S99>/Add1'
     */
    ASW_OBD_DW.UnitDelay_DSTATE_e34g++;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Switch: '<S100>/Switch' */
  if (rtb_Equal_c0gx) {
    /* Update for UnitDelay: '<S100>/Unit Delay' incorporates:
     *  Constant: '<S100>/Parameter1'
     */
    ASW_OBD_DW.UnitDelay_DSTATE_aj4e = 1U;
  } else {
    /* Update for UnitDelay: '<S100>/Unit Delay' incorporates:
     *  Constant: '<S100>/Parameter2'
     *  Sum: '<S100>/Add1'
     */
    ASW_OBD_DW.UnitDelay_DSTATE_aj4e++;
  }

  /* End of Switch: '<S100>/Switch' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  ASW_OBD_DW.UnitDelay_DSTATE = ASW_OBD_B.BusCreator1;

  /* Update for UnitDelay generated from: '<S1>/Unit Delay1' */
  ASW_OBD_DW.bitsForTID1.UnitDelay1_17_DSTATE = ASW_OBD_B.RelationalOperator;

  /* Update for UnitDelay generated from: '<S1>/Unit Delay1' */
  ASW_OBD_DW.bitsForTID1.UnitDelay1_18_DSTATE =
    ASW_OBD_B.RelationalOperator1_l2l1;

  /* Update for UnitDelay generated from: '<S1>/Unit Delay1' */
  ASW_OBD_DW.bitsForTID1.UnitDelay1_23_DSTATE =
    ASW_OBD_B.bitsForTID1.LogicalOperator2_fqo5;

  /* Update for UnitDelay generated from: '<S1>/Unit Delay1' */
  ASW_OBD_DW.bitsForTID1.UnitDelay1_24_DSTATE =
    ASW_OBD_B.bitsForTID1.LogicalOperator1_c3mb;

  /* Update for UnitDelay generated from: '<S1>/Unit Delay1' */
  ASW_OBD_DW.bitsForTID1.UnitDelay1_25_DSTATE =
    ASW_OBD_B.bitsForTID1.LogicalOperator_kubn;

  /* Update for UnitDelay generated from: '<S1>/Unit Delay1' */
  ASW_OBD_DW.bitsForTID1.UnitDelay1_22_DSTATE =
    ASW_OBD_B.bitsForTID1.bol_flgPhiSensFalt;

  /* Update for UnitDelay generated from: '<S1>/Unit Delay1' */
  ASW_OBD_DW.bitsForTID1.UnitDelay1_5_DSTATE = ASW_OBD_B.RelationalOperator1;
}

/* Model step function */
void ASW_OBD_step(void)
{
  if (ASW_OBD_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/OBD_SlwTask' */
    OBD_SlwTask();

    /* End of Outputs for SubSystem: '<Root>/OBD_SlwTask' */
  }

  rate_scheduler();
}

/* Model initialize function */
void ASW_OBD_Init(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ASW_OBD_M, 0,
                sizeof(RT_MODEL_ASW_OBD));

  /* block I/O */
  (void) memset(((void *) &ASW_OBD_B), 0,
                sizeof(B_ASW_OBD));

  /* exported global signals */
  busOBD_SlwTaskOut = ASW_OBD_rtZBUS_OBD_SLW_TASK_OUT;
  test9 = 0U;
  test10 = 0U;
  test6 = 0U;
  test2 = false;

  /* states (dwork) */
  (void) memset((void *)&ASW_OBD_DW, 0,
                sizeof(DW_ASW_OBD));

  /* external inputs */
  busOBD_SlwTaskIn = ASW_OBD_rtZBUS_OBD_SLW_TASK_IN;
  ASW_OBD_PrevZCX.sss_ComFaltMechSpdRespDefd_GEEL = POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/OBD_SlwTask' */
  OBD_SlwTask_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/OBD_SlwTask' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
