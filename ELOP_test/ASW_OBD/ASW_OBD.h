/*
 * File: ASW_OBD.h
 *
 * Code generated for Simulink model 'ASW_OBD'.
 *
 * Model version                  : 6.265
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:35:33 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ASW_OBD_h_
#define RTW_HEADER_ASW_OBD_h_
#ifndef ASW_OBD_COMMON_INCLUDES_
#define ASW_OBD_COMMON_INCLUDES_
#include "../ASW_share/rtwtypes.h"
#endif                                 /* ASW_OBD_COMMON_INCLUDES_ */

//#include "ASW_OBD_types.h"
#include "../ASW_share/custom_type_definition.h"
#include "../ASW_share/motor_control_interface.h"
#include <string.h>
#include "../ASW_share/zero_crossing_types.h"

/* Block states (default storage) for system '<S38>/sfc_FaultDebounce' */
typedef struct {
  uint16 lb_cntDebCond;                /* '<S38>/sfc_FaultDebounce' */
  uint8 is_active_c7_lib_debounce;     /* '<S38>/sfc_FaultDebounce' */
  uint8 is_c7_lib_debounce;            /* '<S38>/sfc_FaultDebounce' */
} DW_sfc_FaultDebounce_ASW_OBD;

/* Block states (default storage) for system '<S36>/lib_Deb_11' */
typedef struct {
  DW_sfc_FaultDebounce_ASW_OBD sf_sfc_FaultDebounce;/* '<S38>/sfc_FaultDebounce' */
} DW_lib_Deb_11_ASW_OBD;

/* Block states (default storage) for system '<S37>/sfc_FaultDefiniteness' */
typedef struct {
  uint16 FaltWaitRecvCnt;              /* '<S37>/sfc_FaultDefiniteness' */
  uint8 is_active_c2_sv8YVlxvCwKOd9Te1t;/* '<S37>/sfc_FaultDefiniteness' */
  uint8 is_c2_sv8YVlxvCwKOd9Te1tJVaiH_l;/* '<S37>/sfc_FaultDefiniteness' */
  uint8 is_EnableDiagnosis;            /* '<S37>/sfc_FaultDefiniteness' */
} DW_sfc_FaultDefiniteness_ASW_OB;

/* Block states (default storage) for system '<S35>/lib_FaltDefd_21' */
typedef struct {
  DW_sfc_FaultDefiniteness_ASW_OB sf_sfc_FaultDefiniteness;/* '<S37>/sfc_FaultDefiniteness' */
} DW_lib_FaltDefd_21_ASW_OBD;

/* Block states (default storage) for system '<S81>/sfc_Debounce' */
typedef struct {
  uint16 lb_cntDebCond;                /* '<S81>/sfc_Debounce' */
  uint8 is_active_c7_vhit_control_libra;/* '<S81>/sfc_Debounce' */
  uint8 is_c7_vhit_control_library;    /* '<S81>/sfc_Debounce' */
} DW_sfc_Debounce_ASW_OBD;

/* Block states (default storage) for system '<S79>/lib_HysDeb_1' */
typedef struct {
  struct {
    uint_T UnitDelay2_DSTATE:1;        /* '<S81>/Unit Delay2' */
  } bitsForTID1;

  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce1;/* '<S81>/sfc_Debounce1' */
  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce;/* '<S81>/sfc_Debounce' */
} DW_lib_HysDeb_1_ASW_OBD;

/* Block states (default storage) for system '<S162>/lib_HysDeb_14' */
typedef struct {
  struct {
    uint_T UnitDelay2_DSTATE:1;        /* '<S164>/Unit Delay2' */
  } bitsForTID1;

  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce1;/* '<S164>/sfc_Debounce1' */
  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce;/* '<S164>/sfc_Debounce' */
} DW_lib_HysDeb_14_ASW_OBD;

/* Block states (default storage) for system '<S179>/lib_HysDeb_12' */
typedef struct {
  struct {
    uint_T UnitDelay2_DSTATE:1;        /* '<S181>/Unit Delay2' */
  } bitsForTID1;

  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce1;/* '<S181>/sfc_Debounce1' */
  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce;/* '<S181>/sfc_Debounce' */
} DW_lib_HysDeb_12_ASW_OBD;

/* Block states (default storage) for system '<S230>/lib_FaltDefd_14' */
typedef struct {
  DW_sfc_FaultDefiniteness_ASW_OB sf_sfc_FaultDefiniteness;/* '<S232>/sfc_FaultDefiniteness' */
} DW_lib_FaltDefd_14_ASW_OBD;

/* Block states (default storage) for system '<S243>/lib_Deb_12' */
typedef struct {
  DW_sfc_FaultDebounce_ASW_OBD sf_sfc_FaultDebounce;/* '<S245>/sfc_FaultDebounce' */
} DW_lib_Deb_12_ASW_OBD;

/* Block signals (default storage) */
typedef struct {
  dt_Standardize_s16p15b0 Assignment[30];/* '<S133>/Assignment' */
  dt_Standardize_s16p15b0 Assignment1[30];/* '<S133>/Assignment1' */
  BUS_OBD_FALT_STS BusCreator1;        /* '<S9>/Bus Creator1' */
  uint8 DataTypeConversion3[30];       /* '<S9>/Data Type Conversion3' */
  uint8 Assignment_czft[30];           /* '<S102>/Assignment' */
  boolean DataTypeConversion2[30];     /* '<S9>/Data Type Conversion2' */
  boolean Assignment_al4c[30];         /* '<S281>/Assignment' */
  struct {
    uint_T LogicalOperator1:1;         /* '<S285>/Logical Operator1' */
    uint_T LogicalOperator3:1;         /* '<S283>/Logical Operator3' */
    uint_T LogicalOperator5:1;         /* '<S289>/Logical Operator5' */
    uint_T LogicalOperator8:1;         /* '<S288>/Logical Operator8' */
    uint_T LogicalOperator3_k1jc:1;    /* '<S288>/Logical Operator3' */
    uint_T LogicalOperator9:1;         /* '<S288>/Logical Operator9' */
    uint_T LogicalOperator5_opu4:1;    /* '<S288>/Logical Operator5' */
    uint_T LogicalOperator11:1;        /* '<S290>/Logical Operator11' */
    uint_T LogicalOperator3_lgwh:1;    /* '<S290>/Logical Operator3' */
    uint_T LogicalOperator5_oi54:1;    /* '<S290>/Logical Operator5' */
    uint_T LogicalOperator8_eron:1;    /* '<S290>/Logical Operator8' */
    uint_T LogicalOperator3_mlkr:1;    /* '<S287>/Logical Operator3' */
    uint_T LogicalOperator4:1;         /* '<S287>/Logical Operator4' */
    uint_T LogicalOperator:1;          /* '<S301>/Logical Operator' */
    uint_T bol_flgPhiSensFalt:1;       /* '<S303>/bol_flgPhiSensFalt' */
    uint_T LogicalOperator2:1;         /* '<S243>/Logical Operator2' */
    uint_T LogicalOperator1_c3mb:1;    /* '<S243>/Logical Operator1' */
    uint_T LogicalOperator1_cq5m:1;    /* '<S230>/Logical Operator1' */
    uint_T LogicalOperator2_hzmq:1;    /* '<S230>/Logical Operator2' */
    uint_T LogicalOperator2_eork:1;    /* '<S221>/Logical Operator2' */
    uint_T LogicalOperator2_fqo5:1;    /* '<S217>/Logical Operator2' */
    uint_T LogicalOperator_kubn:1;     /* '<S196>/Logical Operator' */
    uint_T OR2:1;                      /* '<S169>/OR2' */
    uint_T stFaltDef_Tmpr_cu5h:1;      /* '<S62>/sfc_FaultDefiniteness' */
    uint_T stFaltDef_Perm_l1lp:1;      /* '<S62>/sfc_FaultDefiniteness' */
    uint_T Equal:1;                    /* '<S65>/Equal' */
    uint_T LogicalOperator_hyuk:1;     /* '<S63>/Logical Operator' */
    uint_T DataTypeConversion1:1;      /* '<S71>/Data Type Conversion1' */
    uint_T DataTypeConversion:1;       /* '<S71>/Data Type Conversion' */
    uint_T Equal_azvi:1;               /* '<S69>/Equal' */
  } bitsForTID1;

  dt_Standardize_s16p15b0 Switch1;     /* '<S123>/Switch1' */
  dt_Standardize_s16p15b0 Switch3;     /* '<S121>/Switch3' */
  uint8 FaltCycAccCnt;                 /* '<S304>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_advj;            /* '<S294>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_e00n;            /* '<S274>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_akrv;            /* '<S267>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_eksn;            /* '<S260>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_kent;            /* '<S244>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_mbzj;            /* '<S233>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_lwpi;            /* '<S232>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_k5ca;            /* '<S222>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_buyv;            /* '<S215>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_psnz;            /* '<S208>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_fh1w;            /* '<S201>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_ibsm;            /* '<S194>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_mn3a;            /* '<S187>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_fxmn;            /* '<S180>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_fd2e;            /* '<S170>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_beqh;            /* '<S163>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_jfr4;            /* '<S157>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_gwiq;            /* '<S151>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_ei2t;            /* '<S144>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_et1a;            /* '<S137>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_kbad;            /* '<S87>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_da1w;            /* '<S80>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_nakw;            /* '<S62>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_be2m;            /* '<S56>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_okl0;            /* '<S50>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_ozl3;            /* '<S44>/sfc_FaultDefiniteness' */
  uint8 FaltCycAccCnt_if4y;            /* '<S37>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Tmpr;              /* '<S304>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm;              /* '<S304>/sfc_FaultDefiniteness' */
  boolean lb_genOutp;                  /* '<S305>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_gjm2;         /* '<S294>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_g4b1;         /* '<S294>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_hfik;             /* '<S295>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_o3sb;         /* '<S274>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_efmb;         /* '<S274>/sfc_FaultDefiniteness' */
  boolean Switch1_le4p;                /* '<S275>/Switch1' */
  boolean stFaltDef_Tmpr_lgzj;         /* '<S267>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_ktdp;         /* '<S267>/sfc_FaultDefiniteness' */
  boolean Switch1_lspe;                /* '<S268>/Switch1' */
  boolean stFaltDef_Tmpr_ni5x;         /* '<S260>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_f4wg;         /* '<S260>/sfc_FaultDefiniteness' */
  boolean RelationalOperator1;         /* '<S261>/Relational Operator1' */
  boolean Switch1_j0vh;                /* '<S261>/Switch1' */
  boolean stFaltDef_Tmpr_keux;         /* '<S244>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_i2o3;         /* '<S244>/sfc_FaultDefiniteness' */
  boolean Switch1_h5dr;                /* '<S235>/Switch1' */
  boolean Switch1_mj3e;                /* '<S234>/Switch1' */
  boolean stFaltDef_Tmpr_mpvn;         /* '<S222>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_dthc;         /* '<S222>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Tmpr_ics0;         /* '<S215>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_omzh;         /* '<S215>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_gw2t;             /* '<S216>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_glyd;         /* '<S208>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_lijp;         /* '<S208>/sfc_FaultDefiniteness' */
  boolean Switch1_pxi3;                /* '<S209>/Switch1' */
  boolean stFaltDef_Tmpr_cp2o;         /* '<S201>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_kt5c;         /* '<S201>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_hhu4;             /* '<S202>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_dr1m;         /* '<S194>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_cm35;         /* '<S194>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_f0nq;             /* '<S195>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_izjl;         /* '<S187>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_b5ga;         /* '<S187>/sfc_FaultDefiniteness' */
  boolean Switch1_j1ol;                /* '<S188>/Switch1' */
  boolean stFaltDef_Tmpr_pjcw;         /* '<S180>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_h1g3;         /* '<S180>/sfc_FaultDefiniteness' */
  boolean Switch1_grgo;                /* '<S181>/Switch1' */
  boolean stFaltDef_Tmpr_j3ha;         /* '<S170>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_ilgb;         /* '<S170>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Tmpr_nmp1;         /* '<S163>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_naf3;         /* '<S163>/sfc_FaultDefiniteness' */
  boolean Switch1_asmr;                /* '<S164>/Switch1' */
  boolean stFaltDef_Tmpr_otno;         /* '<S157>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_gulm;         /* '<S157>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_lsbp;             /* '<S158>/sfc_FaultDebounce' */
  boolean OutportBufferForbol_flgHWOvrCur;
  boolean stFaltDef_Perm_dzb0;         /* '<S151>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_neqw;             /* '<S152>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_hsig;         /* '<S144>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_g0ii;         /* '<S144>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_j4vj;             /* '<S146>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_im4y;         /* '<S137>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_dgcc;         /* '<S137>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_hynf;             /* '<S139>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_bk0g;         /* '<S87>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_nbju;         /* '<S87>/sfc_FaultDefiniteness' */
  boolean RelationalOperator;          /* '<S88>/Relational Operator' */
  boolean Switch1_aqbl;                /* '<S88>/Switch1' */
  boolean stFaltDef_Tmpr_b1sa;         /* '<S80>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_ofvs;         /* '<S80>/sfc_FaultDefiniteness' */
  boolean RelationalOperator1_l2l1;    /* '<S81>/Relational Operator1' */
  boolean Switch1_l3mi;                /* '<S81>/Switch1' */
  boolean lb_genOutp_ojfd;             /* '<S68>/sfc_FaultDebounce' */
  boolean lb_genOutp_lgdu;             /* '<S67>/sfc_FaultDebounce' */
  boolean lb_genOutp_eatq;             /* '<S66>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_cbrr;         /* '<S56>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_mvmh;         /* '<S56>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_j4ya;             /* '<S57>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_nqix;         /* '<S50>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_bpps;         /* '<S50>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_gufh;             /* '<S51>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_m0mb;         /* '<S44>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_nx2u;         /* '<S44>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_euom;             /* '<S45>/sfc_FaultDebounce' */
  boolean stFaltDef_Tmpr_lhdo;         /* '<S37>/sfc_FaultDefiniteness' */
  boolean stFaltDef_Perm_iopf;         /* '<S37>/sfc_FaultDefiniteness' */
  boolean lb_genOutp_hlnt;             /* '<S38>/sfc_FaultDebounce' */
} B_ASW_OBD;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  BUS_OBD_FALT_STS UnitDelay_DSTATE;   /* '<S1>/Unit Delay' */
  struct {
    uint_T UnitDelay1_17_DSTATE:1;     /* '<S1>/Unit Delay1' */
    uint_T UnitDelay1_18_DSTATE:1;     /* '<S1>/Unit Delay1' */
    uint_T UnitDelay1_23_DSTATE:1;     /* '<S1>/Unit Delay1' */
    uint_T UnitDelay1_24_DSTATE:1;     /* '<S1>/Unit Delay1' */
    uint_T UnitDelay1_25_DSTATE:1;     /* '<S1>/Unit Delay1' */
    uint_T UnitDelay1_22_DSTATE:1;     /* '<S1>/Unit Delay1' */
    uint_T UnitDelay1_5_DSTATE:1;      /* '<S1>/Unit Delay1' */
    uint_T UnitDelay_DSTATE_igiu:1;    /* '<S248>/Unit Delay' */
    uint_T UnitDelay_DSTATE_o2r0:1;    /* '<S247>/Unit Delay' */
    uint_T UnitDelay2_DSTATE:1;        /* '<S174>/Unit Delay2' */
    uint_T UnitDelay2_DSTATE_i4n0:1;   /* '<S122>/Unit Delay2' */
  } bitsForTID1;

  uint16 UnitDelay_DSTATE_aj4e;        /* '<S100>/Unit Delay' */
  uint16 UnitDelay_DSTATE_e34g;        /* '<S99>/Unit Delay' */
  uint16 UnitDelay_DSTATE_c13u;        /* '<S98>/Unit Delay' */
  uint16 FaltWaitRecvCnt;              /* '<S62>/sfc_FaultDefiniteness' */
  uint8 UnitDelay_DSTATE_keg4;         /* '<S65>/Unit Delay' */
  uint8 UnitDelay_DSTATE_npzl;         /* '<S73>/Unit Delay' */
  uint8 UnitDelay_DSTATE_bxev;         /* '<S69>/Unit Delay' */
  uint8 is_active_c2_swiWcj04KqK1cujXcW;/* '<S62>/sfc_FaultDefiniteness' */
  uint8 is_c2_swiWcj04KqK1cujXcWFuKxE_l;/* '<S62>/sfc_FaultDefiniteness' */
  uint8 is_EnableDiagnosis;            /* '<S62>/sfc_FaultDefiniteness' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_10;/* '<S301>/lib_FaltDefd_10' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_2;     /* '<S303>/lib_Deb_2' */
  DW_sfc_FaultDefiniteness_ASW_OB sf_sfc_FaultDefiniteness_et5q;/* '<S294>/sfc_FaultDefiniteness' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_9;     /* '<S293>/lib_Deb_9' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_5;/* '<S272>/lib_FaltDefd_5' */
  DW_lib_HysDeb_1_ASW_OBD lib_HysDeb_4;/* '<S273>/lib_HysDeb_4' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_4;/* '<S265>/lib_FaltDefd_4' */
  DW_lib_HysDeb_1_ASW_OBD lib_HysDeb_3;/* '<S266>/lib_HysDeb_3' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_6;/* '<S258>/lib_FaltDefd_6' */
  DW_lib_HysDeb_1_ASW_OBD lib_HysDeb_5;/* '<S259>/lib_HysDeb_5' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_24;/* '<S242>/lib_FaltDefd_24' */
  DW_lib_Deb_12_ASW_OBD lib_Deb_13;    /* '<S243>/lib_Deb_13' */
  DW_lib_Deb_12_ASW_OBD lib_Deb_12;    /* '<S243>/lib_Deb_12' */
  DW_lib_FaltDefd_14_ASW_OBD lib_FaltDefd_15;/* '<S230>/lib_FaltDefd_15' */
  DW_lib_FaltDefd_14_ASW_OBD lib_FaltDefd_14;/* '<S230>/lib_FaltDefd_14' */
  DW_lib_HysDeb_12_ASW_OBD lib_HysDeb_11;/* '<S231>/lib_HysDeb_11' */
  DW_lib_HysDeb_12_ASW_OBD lib_HysDeb_10;/* '<S231>/lib_HysDeb_10' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_13;/* '<S220>/lib_FaltDefd_13' */
  DW_lib_HysDeb_12_ASW_OBD lib_HysDeb_9;/* '<S221>/lib_HysDeb_9' */
  DW_lib_HysDeb_12_ASW_OBD lib_HysDeb_8;/* '<S221>/lib_HysDeb_8' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_11;/* '<S213>/lib_FaltDefd_11' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_3;     /* '<S214>/lib_Deb_3' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_2;/* '<S206>/lib_FaltDefd_2' */
  DW_lib_HysDeb_14_ASW_OBD lib_HysDeb_2;/* '<S207>/lib_HysDeb_2' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_20;/* '<S199>/lib_FaltDefd_20' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_10;    /* '<S200>/lib_Deb_10' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_25;/* '<S192>/lib_FaltDefd_25' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_14;    /* '<S193>/lib_Deb_14' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_17;/* '<S185>/lib_FaltDefd_17' */
  DW_lib_HysDeb_12_ASW_OBD lib_HysDeb_13;/* '<S186>/lib_HysDeb_13' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_16;/* '<S178>/lib_FaltDefd_16' */
  DW_lib_HysDeb_12_ASW_OBD lib_HysDeb_12;/* '<S179>/lib_HysDeb_12' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_23;/* '<S168>/lib_FaltDefd_23' */
  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce1;/* '<S174>/sfc_Debounce1' */
  DW_sfc_Debounce_ASW_OBD sf_sfc_Debounce;/* '<S174>/sfc_Debounce' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_22;/* '<S161>/lib_FaltDefd_22' */
  DW_lib_HysDeb_14_ASW_OBD lib_HysDeb_14;/* '<S162>/lib_HysDeb_14' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_9_hcdo;/* '<S155>/lib_FaltDefd_9' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_17_erkz;/* '<S156>/lib_Deb_17' */
  DW_sfc_FaultDefiniteness_ASW_OB sf_sfc_FaultDefiniteness_fvae;/* '<S151>/sfc_FaultDefiniteness' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_0;     /* '<S150>/lib_Deb_0' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_7;/* '<S142>/lib_FaltDefd_7' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_15;    /* '<S145>/lib_Deb_15' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_8;/* '<S135>/lib_FaltDefd_8' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_16;    /* '<S138>/lib_Deb_16' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_0;/* '<S85>/lib_FaltDefd_0' */
  DW_lib_HysDeb_1_ASW_OBD lib_HysDeb_0;/* '<S86>/lib_HysDeb_0' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_1;/* '<S78>/lib_FaltDefd_1' */
  DW_lib_HysDeb_1_ASW_OBD lib_HysDeb_1;/* '<S79>/lib_HysDeb_1' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_7;     /* '<S63>/lib_Deb_7' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_6;     /* '<S63>/lib_Deb_6' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_5;     /* '<S63>/lib_Deb_5' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_9_drq2;/* '<S54>/lib_FaltDefd_9' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_1;     /* '<S55>/lib_Deb_1' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_9;/* '<S48>/lib_FaltDefd_9' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_17;    /* '<S49>/lib_Deb_17' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_12;/* '<S42>/lib_FaltDefd_12' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_4;     /* '<S43>/lib_Deb_4' */
  DW_lib_FaltDefd_21_ASW_OBD lib_FaltDefd_21;/* '<S35>/lib_FaltDefd_21' */
  DW_lib_Deb_11_ASW_OBD lib_Deb_11;    /* '<S36>/lib_Deb_11' */
} DW_ASW_OBD;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState sss_ComFaltMechSpdRespDefd_GEEL;
                                 /* '<S119>/sss_ComFaltMechSpdRespDefd_GEELY' */
} PrevZCX_ASW_OBD;

/* Real-time Model Data Structure */
struct tag_RTM_ASW_OBD {
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
extern B_ASW_OBD ASW_OBD_B;

/* Block states (default storage) */
extern DW_ASW_OBD ASW_OBD_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_ASW_OBD ASW_OBD_PrevZCX;

/* External data declarations for dependent source files */
extern const BUS_OBD_SLW_TASK_IN ASW_OBD_rtZBUS_OBD_SLW_TASK_IN;/* BUS_OBD_SLW_TASK_IN ground */
extern const BUS_OBD_SLW_TASK_OUT ASW_OBD_rtZBUS_OBD_SLW_TASK_OUT;/* BUS_OBD_SLW_TASK_OUT ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BUS_OBD_SLW_TASK_IN busOBD_SlwTaskIn;/* '<Root>/busOBD_SlwTaskIn' */
extern BUS_OBD_SLW_TASK_OUT busOBD_SlwTaskOut;/* '<S309>/Bus Creator1' */
extern uint8 test9;                    /* '<S73>/Signal Copy1' */
extern uint8 test10;                   /* '<S73>/Add' */
extern uint8 test6;                    /* '<S73>/Data Type Conversion2' */
extern boolean test2;                  /* '<S72>/Data Type Conversion' */

/* Model entry point functions */
extern void ASW_OBD_Init(void);
extern void ASW_OBD_step(void);

/* Real-time Model object */
extern RT_MODEL_ASW_OBD *const ASW_OBD_M;

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
 * '<Root>' : 'ASW_OBD'
 * '<S1>'   : 'ASW_OBD/OBD_SlwTask'
 * '<S2>'   : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia'
 * '<S3>'   : 'ASW_OBD/OBD_SlwTask/rss_BusOffFaltDia'
 * '<S4>'   : 'ASW_OBD/OBD_SlwTask/rss_CRASHFaltDia'
 * '<S5>'   : 'ASW_OBD/OBD_SlwTask/rss_ChipFaltDia'
 * '<S6>'   : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia'
 * '<S7>'   : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia'
 * '<S8>'   : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia'
 * '<S9>'   : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng'
 * '<S10>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltLevlCmpt'
 * '<S11>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltResp'
 * '<S12>'  : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia'
 * '<S13>'  : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia'
 * '<S14>'  : 'ASW_OBD/OBD_SlwTask/rss_HWOvrCurrDia'
 * '<S15>'  : 'ASW_OBD/OBD_SlwTask/rss_MosOpnCirFaltDia'
 * '<S16>'  : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia'
 * '<S17>'  : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia'
 * '<S18>'  : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia'
 * '<S19>'  : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia'
 * '<S20>'  : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia'
 * '<S21>'  : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia'
 * '<S22>'  : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia'
 * '<S23>'  : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia'
 * '<S24>'  : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia'
 * '<S25>'  : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia'
 * '<S26>'  : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia'
 * '<S27>'  : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia'
 * '<S28>'  : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia'
 * '<S29>'  : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia'
 * '<S30>'  : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf'
 * '<S31>'  : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia'
 * '<S32>'  : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia'
 * '<S33>'  : 'ASW_OBD/OBD_SlwTask/vrs_SlwTaskIn'
 * '<S34>'  : 'ASW_OBD/OBD_SlwTask/vrs_SlwTaskOut'
 * '<S35>'  : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia/sss_BattPwrHiLvl1'
 * '<S36>'  : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia/sss_BattPwrHiLvl1/ens_JudgDeb'
 * '<S37>'  : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia/sss_BattPwrHiLvl1/lib_FaltDefd_21'
 * '<S38>'  : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia/sss_BattPwrHiLvl1/ens_JudgDeb/lib_Deb_11'
 * '<S39>'  : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia/sss_BattPwrHiLvl1/ens_JudgDeb/sss_BattPwrHiLvl1PreJudg'
 * '<S40>'  : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia/sss_BattPwrHiLvl1/ens_JudgDeb/lib_Deb_11/sfc_FaultDebounce'
 * '<S41>'  : 'ASW_OBD/OBD_SlwTask/rss_BattPwrHiLvl1Dia/sss_BattPwrHiLvl1/lib_FaltDefd_21/sfc_FaultDefiniteness'
 * '<S42>'  : 'ASW_OBD/OBD_SlwTask/rss_BusOffFaltDia/sss_BusOffFalt'
 * '<S43>'  : 'ASW_OBD/OBD_SlwTask/rss_BusOffFaltDia/sss_BusOffFalt/ens_HysDeb'
 * '<S44>'  : 'ASW_OBD/OBD_SlwTask/rss_BusOffFaltDia/sss_BusOffFalt/lib_FaltDefd_12'
 * '<S45>'  : 'ASW_OBD/OBD_SlwTask/rss_BusOffFaltDia/sss_BusOffFalt/ens_HysDeb/lib_Deb_4'
 * '<S46>'  : 'ASW_OBD/OBD_SlwTask/rss_BusOffFaltDia/sss_BusOffFalt/ens_HysDeb/lib_Deb_4/sfc_FaultDebounce'
 * '<S47>'  : 'ASW_OBD/OBD_SlwTask/rss_BusOffFaltDia/sss_BusOffFalt/lib_FaltDefd_12/sfc_FaultDefiniteness'
 * '<S48>'  : 'ASW_OBD/OBD_SlwTask/rss_CRASHFaltDia/sss_CrashFalt'
 * '<S49>'  : 'ASW_OBD/OBD_SlwTask/rss_CRASHFaltDia/sss_CrashFalt/ens_HysDeb'
 * '<S50>'  : 'ASW_OBD/OBD_SlwTask/rss_CRASHFaltDia/sss_CrashFalt/lib_FaltDefd_9'
 * '<S51>'  : 'ASW_OBD/OBD_SlwTask/rss_CRASHFaltDia/sss_CrashFalt/ens_HysDeb/lib_Deb_17'
 * '<S52>'  : 'ASW_OBD/OBD_SlwTask/rss_CRASHFaltDia/sss_CrashFalt/ens_HysDeb/lib_Deb_17/sfc_FaultDebounce'
 * '<S53>'  : 'ASW_OBD/OBD_SlwTask/rss_CRASHFaltDia/sss_CrashFalt/lib_FaltDefd_9/sfc_FaultDefiniteness'
 * '<S54>'  : 'ASW_OBD/OBD_SlwTask/rss_ChipFaltDia/sss_ChipFalt'
 * '<S55>'  : 'ASW_OBD/OBD_SlwTask/rss_ChipFaltDia/sss_ChipFalt/ens_HysDeb'
 * '<S56>'  : 'ASW_OBD/OBD_SlwTask/rss_ChipFaltDia/sss_ChipFalt/lib_FaltDefd_9'
 * '<S57>'  : 'ASW_OBD/OBD_SlwTask/rss_ChipFaltDia/sss_ChipFalt/ens_HysDeb/lib_Deb_1'
 * '<S58>'  : 'ASW_OBD/OBD_SlwTask/rss_ChipFaltDia/sss_ChipFalt/ens_HysDeb/lib_Deb_1/sfc_FaultDebounce'
 * '<S59>'  : 'ASW_OBD/OBD_SlwTask/rss_ChipFaltDia/sss_ChipFalt/lib_FaltDefd_9/sfc_FaultDefiniteness'
 * '<S60>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt'
 * '<S61>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb'
 * '<S62>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/lib_FaltDefd_18'
 * '<S63>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY'
 * '<S64>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/CANHeartLos'
 * '<S65>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/ComLosFaltDet'
 * '<S66>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/lib_Deb_5'
 * '<S67>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/lib_Deb_6'
 * '<S68>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/lib_Deb_7'
 * '<S69>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/CANHeartLos/CANHeartLos'
 * '<S70>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/ComLosFaltDet/COMLosDia'
 * '<S71>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/ComLosFaltDet/COMLosDia/COMLosDeb'
 * '<S72>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/ComLosFaltDet/COMLosDia/COMLosDeb/CRCErrDef'
 * '<S73>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/ComLosFaltDet/COMLosDia/COMLosDeb/RollCntErrDef'
 * '<S74>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/lib_Deb_5/sfc_FaultDebounce'
 * '<S75>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/lib_Deb_6/sfc_FaultDebounce'
 * '<S76>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/ens_HysDeb/ens_HysDeb_GEELY/lib_Deb_7/sfc_FaultDebounce'
 * '<S77>'  : 'ASW_OBD/OBD_SlwTask/rss_ComFaltDia/sss_ComFalt/lib_FaltDefd_18/sfc_FaultDefiniteness'
 * '<S78>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia/sss_CtlBrdVltgHiLvl1'
 * '<S79>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia/sss_CtlBrdVltgHiLvl1/ens_Deb'
 * '<S80>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia/sss_CtlBrdVltgHiLvl1/lib_FaltDefd_1'
 * '<S81>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia/sss_CtlBrdVltgHiLvl1/ens_Deb/lib_HysDeb_1'
 * '<S82>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia/sss_CtlBrdVltgHiLvl1/ens_Deb/lib_HysDeb_1/sfc_Debounce'
 * '<S83>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia/sss_CtlBrdVltgHiLvl1/ens_Deb/lib_HysDeb_1/sfc_Debounce1'
 * '<S84>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgHiLvl1Dia/sss_CtlBrdVltgHiLvl1/lib_FaltDefd_1/sfc_FaultDefiniteness'
 * '<S85>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia/sss_CtlBrdVltgLoLvl1'
 * '<S86>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia/sss_CtlBrdVltgLoLvl1/ens_Deb'
 * '<S87>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia/sss_CtlBrdVltgLoLvl1/lib_FaltDefd_0'
 * '<S88>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia/sss_CtlBrdVltgLoLvl1/ens_Deb/lib_HysDeb_0'
 * '<S89>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia/sss_CtlBrdVltgLoLvl1/ens_Deb/lib_HysDeb_0/sfc_Debounce'
 * '<S90>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia/sss_CtlBrdVltgLoLvl1/ens_Deb/lib_HysDeb_0/sfc_Debounce1'
 * '<S91>'  : 'ASW_OBD/OBD_SlwTask/rss_CtlBrdVltgLoLvl1Dia/sss_CtlBrdVltgLoLvl1/lib_FaltDefd_0/sfc_FaultDefiniteness'
 * '<S92>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/Extract Bits'
 * '<S93>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/Extract Bits1'
 * '<S94>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/Extract Bits2'
 * '<S95>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/Extract Bits3'
 * '<S96>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/sss_FaltDiaSdlEn'
 * '<S97>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/vrs_DSMSaveInfo'
 * '<S98>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/sss_FaltDiaSdlEn/sss_ComSdlCnt'
 * '<S99>'  : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/sss_FaltDiaSdlEn/sss_FstSdlCnt'
 * '<S100>' : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/sss_FaltDiaSdlEn/sss_SlwSdlCnt'
 * '<S101>' : 'ASW_OBD/OBD_SlwTask/rss_FaltInfoMng/vrs_DSMSaveInfo/sss_DSMSaveInfoNoNeed'
 * '<S102>' : 'ASW_OBD/OBD_SlwTask/rss_FaltLevlCmpt/sss_FaltLvlConf'
 * '<S103>' : 'ASW_OBD/OBD_SlwTask/rss_FaltLevlCmpt/sss_MaxFaltLvlSel'
 * '<S104>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespConf'
 * '<S105>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd'
 * '<S106>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespSel'
 * '<S107>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespConf/sas_FaltLvl1'
 * '<S108>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespConf/sas_FaltLvl2'
 * '<S109>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespConf/sas_FaltLvl3'
 * '<S110>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespConf/sas_FaltLvlDfl'
 * '<S111>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd'
 * '<S112>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd'
 * '<S113>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_CurrRlv'
 * '<S114>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else'
 * '<S115>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_SensRlv'
 * '<S116>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_SpdRlv'
 * '<S117>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_TempRlv'
 * '<S118>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_VltgRlv'
 * '<S119>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else/sss_ComFaltMechSpdRespDefd'
 * '<S120>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else/sss_MotoStallFaltMechSpdRespDefd'
 * '<S121>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else/sss_ComFaltMechSpdRespDefd/sss_ComFaltMechSpdRespDefd_GEELY'
 * '<S122>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else/sss_ComFaltMechSpdRespDefd/sss_ComFaltMechSpdRespDefd_GEELY/lib_hysteresis_0'
 * '<S123>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else/sss_MotoStallFaltMechSpdRespDefd/sss_MotoStallTmpSpd'
 * '<S124>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else/sss_MotoStallFaltMechSpdRespDefd/sss_MotoStallTmpSpd/Compare To Constant'
 * '<S125>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltMechSpdRespDefd/sss_Else/sss_MotoStallFaltMechSpdRespDefd/sss_MotoStallTmpSpd/Compare To Constant1'
 * '<S126>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd/sss_CurrRlv'
 * '<S127>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd/sss_Else'
 * '<S128>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd/sss_SensRlv'
 * '<S129>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd/sss_SpdRlv'
 * '<S130>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd/sss_TempRlv'
 * '<S131>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd/sss_VltgRlv'
 * '<S132>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespDefd/sss_FaltTqLimRespDefd/sss_Else/sss_trqMotoStallTmpTqLim'
 * '<S133>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespSel/sss_FaltLvl2Conf'
 * '<S134>' : 'ASW_OBD/OBD_SlwTask/rss_FaltResp/sss_FaltRespSel/sss_MinFaltRespSel'
 * '<S135>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia/sss_GDVltgHiLvl1'
 * '<S136>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia/sss_GDVltgHiLvl1/ens_Deb'
 * '<S137>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia/sss_GDVltgHiLvl1/lib_FaltDefd_8'
 * '<S138>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia/sss_GDVltgHiLvl1/ens_Deb/ens_Deb_GEELY'
 * '<S139>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia/sss_GDVltgHiLvl1/ens_Deb/ens_Deb_GEELY/lib_Deb_16'
 * '<S140>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia/sss_GDVltgHiLvl1/ens_Deb/ens_Deb_GEELY/lib_Deb_16/sfc_FaultDebounce'
 * '<S141>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgHiLvl1Dia/sss_GDVltgHiLvl1/lib_FaltDefd_8/sfc_FaultDefiniteness'
 * '<S142>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia/sss_GDVltgLoLvl1'
 * '<S143>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia/sss_GDVltgLoLvl1/ens_Deb'
 * '<S144>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia/sss_GDVltgLoLvl1/lib_FaltDefd_7'
 * '<S145>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia/sss_GDVltgLoLvl1/ens_Deb/ens_Deb_GEELY'
 * '<S146>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia/sss_GDVltgLoLvl1/ens_Deb/ens_Deb_GEELY/lib_Deb_15'
 * '<S147>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia/sss_GDVltgLoLvl1/ens_Deb/ens_Deb_GEELY/lib_Deb_15/sfc_FaultDebounce'
 * '<S148>' : 'ASW_OBD/OBD_SlwTask/rss_GDVltgLoLvl1Dia/sss_GDVltgLoLvl1/lib_FaltDefd_7/sfc_FaultDefiniteness'
 * '<S149>' : 'ASW_OBD/OBD_SlwTask/rss_HWOvrCurrDia/sss_HWOvrCurr'
 * '<S150>' : 'ASW_OBD/OBD_SlwTask/rss_HWOvrCurrDia/sss_HWOvrCurr/ens_Deb_0'
 * '<S151>' : 'ASW_OBD/OBD_SlwTask/rss_HWOvrCurrDia/sss_HWOvrCurr/lib_FaltDefd_3'
 * '<S152>' : 'ASW_OBD/OBD_SlwTask/rss_HWOvrCurrDia/sss_HWOvrCurr/ens_Deb_0/lib_Deb_0'
 * '<S153>' : 'ASW_OBD/OBD_SlwTask/rss_HWOvrCurrDia/sss_HWOvrCurr/ens_Deb_0/lib_Deb_0/sfc_FaultDebounce'
 * '<S154>' : 'ASW_OBD/OBD_SlwTask/rss_HWOvrCurrDia/sss_HWOvrCurr/lib_FaltDefd_3/sfc_FaultDefiniteness'
 * '<S155>' : 'ASW_OBD/OBD_SlwTask/rss_MosOpnCirFaltDia/sss_MosOpnCirFalt'
 * '<S156>' : 'ASW_OBD/OBD_SlwTask/rss_MosOpnCirFaltDia/sss_MosOpnCirFalt/ens_HysDeb'
 * '<S157>' : 'ASW_OBD/OBD_SlwTask/rss_MosOpnCirFaltDia/sss_MosOpnCirFalt/lib_FaltDefd_9'
 * '<S158>' : 'ASW_OBD/OBD_SlwTask/rss_MosOpnCirFaltDia/sss_MosOpnCirFalt/ens_HysDeb/lib_Deb_17'
 * '<S159>' : 'ASW_OBD/OBD_SlwTask/rss_MosOpnCirFaltDia/sss_MosOpnCirFalt/ens_HysDeb/lib_Deb_17/sfc_FaultDebounce'
 * '<S160>' : 'ASW_OBD/OBD_SlwTask/rss_MosOpnCirFaltDia/sss_MosOpnCirFalt/lib_FaltDefd_9/sfc_FaultDefiniteness'
 * '<S161>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia/sss_MotoSpdHiLvl1'
 * '<S162>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia/sss_MotoSpdHiLvl1/ens_Deb'
 * '<S163>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia/sss_MotoSpdHiLvl1/lib_FaltDefd_22'
 * '<S164>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia/sss_MotoSpdHiLvl1/ens_Deb/lib_HysDeb_14'
 * '<S165>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia/sss_MotoSpdHiLvl1/ens_Deb/lib_HysDeb_14/sfc_Debounce'
 * '<S166>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia/sss_MotoSpdHiLvl1/ens_Deb/lib_HysDeb_14/sfc_Debounce1'
 * '<S167>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdHiLvl1Dia/sss_MotoSpdHiLvl1/lib_FaltDefd_22/sfc_FaultDefiniteness'
 * '<S168>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1'
 * '<S169>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/ens_JudgDeb'
 * '<S170>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/lib_FaltDefd_23'
 * '<S171>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/ens_JudgDeb/Compare To Constant1'
 * '<S172>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/ens_JudgDeb/Compare To Constant3'
 * '<S173>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/ens_JudgDeb/lib_Cnvr_0'
 * '<S174>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/ens_JudgDeb/lib_HysDeb_15'
 * '<S175>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/ens_JudgDeb/lib_HysDeb_15/sfc_Debounce'
 * '<S176>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/ens_JudgDeb/lib_HysDeb_15/sfc_Debounce1'
 * '<S177>' : 'ASW_OBD/OBD_SlwTask/rss_MotoSpdLoLvl1Dia/sss_MotoSpdLoLvl1/lib_FaltDefd_23/sfc_FaultDefiniteness'
 * '<S178>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia/sss_MotoTempHiLvl1'
 * '<S179>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia/sss_MotoTempHiLvl1/ens_HysDeb'
 * '<S180>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia/sss_MotoTempHiLvl1/lib_FaltDefd_16'
 * '<S181>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia/sss_MotoTempHiLvl1/ens_HysDeb/lib_HysDeb_12'
 * '<S182>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia/sss_MotoTempHiLvl1/ens_HysDeb/lib_HysDeb_12/sfc_Debounce'
 * '<S183>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia/sss_MotoTempHiLvl1/ens_HysDeb/lib_HysDeb_12/sfc_Debounce1'
 * '<S184>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl1Dia/sss_MotoTempHiLvl1/lib_FaltDefd_16/sfc_FaultDefiniteness'
 * '<S185>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia/sss_MotoTempHiLvl2'
 * '<S186>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia/sss_MotoTempHiLvl2/ens_HysDeb'
 * '<S187>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia/sss_MotoTempHiLvl2/lib_FaltDefd_17'
 * '<S188>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia/sss_MotoTempHiLvl2/ens_HysDeb/lib_HysDeb_13'
 * '<S189>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia/sss_MotoTempHiLvl2/ens_HysDeb/lib_HysDeb_13/sfc_Debounce'
 * '<S190>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia/sss_MotoTempHiLvl2/ens_HysDeb/lib_HysDeb_13/sfc_Debounce1'
 * '<S191>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempHiLvl2Dia/sss_MotoTempHiLvl2/lib_FaltDefd_17/sfc_FaultDefiniteness'
 * '<S192>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia/sss_MotoTempSensFalt'
 * '<S193>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia/sss_MotoTempSensFalt/ens_HysDeb'
 * '<S194>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia/sss_MotoTempSensFalt/lib_FaltDefd_25'
 * '<S195>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia/sss_MotoTempSensFalt/ens_HysDeb/lib_Deb_14'
 * '<S196>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia/sss_MotoTempSensFalt/ens_HysDeb/sss_MotoTempSensPreJudg'
 * '<S197>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia/sss_MotoTempSensFalt/ens_HysDeb/lib_Deb_14/sfc_FaultDebounce'
 * '<S198>' : 'ASW_OBD/OBD_SlwTask/rss_MotoTempSensFaltDia/sss_MotoTempSensFalt/lib_FaltDefd_25/sfc_FaultDefiniteness'
 * '<S199>' : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia/sss_NoLd'
 * '<S200>' : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia/sss_NoLd/ens_JudgDeb'
 * '<S201>' : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia/sss_NoLd/lib_FaltDefd_20'
 * '<S202>' : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia/sss_NoLd/ens_JudgDeb/lib_Deb_10'
 * '<S203>' : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia/sss_NoLd/ens_JudgDeb/sss_NoLdPreJudg'
 * '<S204>' : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia/sss_NoLd/ens_JudgDeb/lib_Deb_10/sfc_FaultDebounce'
 * '<S205>' : 'ASW_OBD/OBD_SlwTask/rss_NoLdDia/sss_NoLd/lib_FaltDefd_20/sfc_FaultDefiniteness'
 * '<S206>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia/sss_PhCurrHiLvl1'
 * '<S207>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia/sss_PhCurrHiLvl1/ens_HysDeb'
 * '<S208>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia/sss_PhCurrHiLvl1/lib_FaltDefd_2'
 * '<S209>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia/sss_PhCurrHiLvl1/ens_HysDeb/lib_HysDeb_2'
 * '<S210>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia/sss_PhCurrHiLvl1/ens_HysDeb/lib_HysDeb_2/sfc_Debounce'
 * '<S211>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia/sss_PhCurrHiLvl1/ens_HysDeb/lib_HysDeb_2/sfc_Debounce1'
 * '<S212>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrHiLvl1Dia/sss_PhCurrHiLvl1/lib_FaltDefd_2/sfc_FaultDefiniteness'
 * '<S213>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia/sss_PhCurrSensFalt'
 * '<S214>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia/sss_PhCurrSensFalt/ens_JudgDeb'
 * '<S215>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia/sss_PhCurrSensFalt/lib_FaltDefd_11'
 * '<S216>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia/sss_PhCurrSensFalt/ens_JudgDeb/lib_Deb_3'
 * '<S217>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia/sss_PhCurrSensFalt/ens_JudgDeb/sss_PhCurrSensPreJudg'
 * '<S218>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia/sss_PhCurrSensFalt/ens_JudgDeb/lib_Deb_3/sfc_FaultDebounce'
 * '<S219>' : 'ASW_OBD/OBD_SlwTask/rss_PhCurrSensFaltDia/sss_PhCurrSensFalt/lib_FaltDefd_11/sfc_FaultDefiniteness'
 * '<S220>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1'
 * '<S221>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/ens_HysDeb'
 * '<S222>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/lib_FaltDefd_13'
 * '<S223>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/ens_HysDeb/lib_HysDeb_8'
 * '<S224>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/ens_HysDeb/lib_HysDeb_9'
 * '<S225>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/ens_HysDeb/lib_HysDeb_8/sfc_Debounce'
 * '<S226>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/ens_HysDeb/lib_HysDeb_8/sfc_Debounce1'
 * '<S227>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/ens_HysDeb/lib_HysDeb_9/sfc_Debounce'
 * '<S228>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/ens_HysDeb/lib_HysDeb_9/sfc_Debounce1'
 * '<S229>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl1Dia/sss_PwrTubPCBTempHiLvl1/lib_FaltDefd_13/sfc_FaultDefiniteness'
 * '<S230>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2'
 * '<S231>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/ens_HysDeb'
 * '<S232>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/lib_FaltDefd_14'
 * '<S233>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/lib_FaltDefd_15'
 * '<S234>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/ens_HysDeb/lib_HysDeb_10'
 * '<S235>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/ens_HysDeb/lib_HysDeb_11'
 * '<S236>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/ens_HysDeb/lib_HysDeb_10/sfc_Debounce'
 * '<S237>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/ens_HysDeb/lib_HysDeb_10/sfc_Debounce1'
 * '<S238>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/ens_HysDeb/lib_HysDeb_11/sfc_Debounce'
 * '<S239>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/ens_HysDeb/lib_HysDeb_11/sfc_Debounce1'
 * '<S240>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/lib_FaltDefd_14/sfc_FaultDefiniteness'
 * '<S241>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempHiLvl2Dia/sss_PwrTubPCBTempHiLvl2/lib_FaltDefd_15/sfc_FaultDefiniteness'
 * '<S242>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt'
 * '<S243>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb'
 * '<S244>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/lib_FaltDefd_24'
 * '<S245>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/lib_Deb_12'
 * '<S246>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/lib_Deb_13'
 * '<S247>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PCBTempSensPreJudg'
 * '<S248>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PwrTubTempSensPreJudg'
 * '<S249>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/lib_Deb_12/sfc_FaultDebounce'
 * '<S250>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/lib_Deb_13/sfc_FaultDebounce'
 * '<S251>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PCBTempSensPreJudg/lib_CfgPar_0'
 * '<S252>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PCBTempSensPreJudg/lib_CfgPar_0/vss_SaturationActivation'
 * '<S253>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PCBTempSensPreJudg/lib_CfgPar_0/vss_SaturationActivation/vss_SaturationRequired'
 * '<S254>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PwrTubTempSensPreJudg/lib_CfgPar_1'
 * '<S255>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PwrTubTempSensPreJudg/lib_CfgPar_1/vss_SaturationActivation'
 * '<S256>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/ens_HysDeb/sss_PwrTubTempSensPreJudg/lib_CfgPar_1/vss_SaturationActivation/vss_SaturationRequired'
 * '<S257>' : 'ASW_OBD/OBD_SlwTask/rss_PwrTubPCBTempSensFaltDia/sss_PwrTubPCBTempSensFalt/lib_FaltDefd_24/sfc_FaultDefiniteness'
 * '<S258>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia/sss_SplyVltgHiLvl1'
 * '<S259>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia/sss_SplyVltgHiLvl1/ens_HysDeb'
 * '<S260>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia/sss_SplyVltgHiLvl1/lib_FaltDefd_6'
 * '<S261>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia/sss_SplyVltgHiLvl1/ens_HysDeb/lib_HysDeb_5'
 * '<S262>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia/sss_SplyVltgHiLvl1/ens_HysDeb/lib_HysDeb_5/sfc_Debounce'
 * '<S263>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia/sss_SplyVltgHiLvl1/ens_HysDeb/lib_HysDeb_5/sfc_Debounce1'
 * '<S264>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgHiLvl1Dia/sss_SplyVltgHiLvl1/lib_FaltDefd_6/sfc_FaultDefiniteness'
 * '<S265>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia/sss_SplyVltgLoLvl1'
 * '<S266>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia/sss_SplyVltgLoLvl1/ens_HysDeb'
 * '<S267>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia/sss_SplyVltgLoLvl1/lib_FaltDefd_4'
 * '<S268>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia/sss_SplyVltgLoLvl1/ens_HysDeb/lib_HysDeb_3'
 * '<S269>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia/sss_SplyVltgLoLvl1/ens_HysDeb/lib_HysDeb_3/sfc_Debounce'
 * '<S270>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia/sss_SplyVltgLoLvl1/ens_HysDeb/lib_HysDeb_3/sfc_Debounce1'
 * '<S271>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl1Dia/sss_SplyVltgLoLvl1/lib_FaltDefd_4/sfc_FaultDefiniteness'
 * '<S272>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia/sss_SplyVltgLoLvl2'
 * '<S273>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia/sss_SplyVltgLoLvl2/ens_HysDeb'
 * '<S274>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia/sss_SplyVltgLoLvl2/lib_FaltDefd_5'
 * '<S275>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia/sss_SplyVltgLoLvl2/ens_HysDeb/lib_HysDeb_4'
 * '<S276>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia/sss_SplyVltgLoLvl2/ens_HysDeb/lib_HysDeb_4/sfc_Debounce'
 * '<S277>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia/sss_SplyVltgLoLvl2/ens_HysDeb/lib_HysDeb_4/sfc_Debounce1'
 * '<S278>' : 'ASW_OBD/OBD_SlwTask/rss_SplyVltgLoLvl2Dia/sss_SplyVltgLoLvl2/lib_FaltDefd_5/sfc_FaultDefiniteness'
 * '<S279>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl'
 * '<S280>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/Compare To Constant3'
 * '<S281>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltEnFlgConf'
 * '<S282>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg'
 * '<S283>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_CurrRlv'
 * '<S284>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_Else'
 * '<S285>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_HiPrioLvlConf'
 * '<S286>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_SensRlv'
 * '<S287>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_SpdRlv'
 * '<S288>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_TempRlv'
 * '<S289>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_VltgRlv'
 * '<S290>' : 'ASW_OBD/OBD_SlwTask/vrs_FaltEnFlgConf/rss_FaltEnFlgConfSenl/sss_FaltPrioJudg/sss_Else/sss_Else_GEELY'
 * '<S291>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr'
 * '<S292>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall'
 * '<S293>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall/ens_JudgDeb'
 * '<S294>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall/lib_FaltDefd_19'
 * '<S295>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall/ens_JudgDeb/lib_Deb_9'
 * '<S296>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall/ens_JudgDeb/sss_MotoStallPreJudg'
 * '<S297>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall/ens_JudgDeb/lib_Deb_9/sfc_FaultDebounce'
 * '<S298>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall/ens_JudgDeb/sss_MotoStallPreJudg/Compare To Constant'
 * '<S299>' : 'ASW_OBD/OBD_SlwTask/vrs_MotoStallDia/rss_MotoStallDiaHybr/sss_MotoStall/lib_FaltDefd_19/sfc_FaultDefiniteness'
 * '<S300>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr'
 * '<S301>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr/sss_PhiSensFalt'
 * '<S302>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr/sss_PhiSensFalt/Compare To Constant'
 * '<S303>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr/sss_PhiSensFalt/ens_HysDeb'
 * '<S304>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr/sss_PhiSensFalt/lib_FaltDefd_10'
 * '<S305>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr/sss_PhiSensFalt/ens_HysDeb/lib_Deb_2'
 * '<S306>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr/sss_PhiSensFalt/ens_HysDeb/lib_Deb_2/sfc_FaultDebounce'
 * '<S307>' : 'ASW_OBD/OBD_SlwTask/vrs_PhiSensFaltDia/rss_PhiSensFaltDiaHybr/sss_PhiSensFalt/lib_FaltDefd_10/sfc_FaultDefiniteness'
 * '<S308>' : 'ASW_OBD/OBD_SlwTask/vrs_SlwTaskIn/sss_SlwTaskInHybr'
 * '<S309>' : 'ASW_OBD/OBD_SlwTask/vrs_SlwTaskOut/sss_SlwTaskOutHybr'
 */
#endif                                 /* RTW_HEADER_ASW_OBD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
