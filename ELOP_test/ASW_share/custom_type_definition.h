/*
 * File: custom_type_definition.h
 *
 * Code generated for Simulink model 'ASW_OBD'.
 *
 * Model version                  : 6.304
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Mar 25 10:57:19 2025
 */

#ifndef RTW_HEADER_custom_type_definition_h_
#define RTW_HEADER_custom_type_definition_h_
#include "rtwtypes.h"

typedef uint8 ENM_AG_POS_EVAL_MODE;

/* enum ENM_AG_POS_EVAL_MODE */
#define SENSOR                         ((ENM_AG_POS_EVAL_MODE)0U) /* Default value */
#define HYBRID                         ((ENM_AG_POS_EVAL_MODE)1U)
#define SENSORLESS                     ((ENM_AG_POS_EVAL_MODE)2U)

typedef uint8 ENM_AG_SENS_CALIB_STATUS;

/* enum ENM_AG_SENS_CALIB_STATUS */
#define CALIBFAIL                      ((ENM_AG_SENS_CALIB_STATUS)0U) /* Default value */
#define SUCCESS                        ((ENM_AG_SENS_CALIB_STATUS)1U)
#define ALPHA_PHASE1                   ((ENM_AG_SENS_CALIB_STATUS)2U)
#define BETA_PHASE                     ((ENM_AG_SENS_CALIB_STATUS)3U)
#define WAIT_ALPHA1                    ((ENM_AG_SENS_CALIB_STATUS)4U)
#define WAIT_BETA                      ((ENM_AG_SENS_CALIB_STATUS)5U)
#define ALPHA_PHASE2                   ((ENM_AG_SENS_CALIB_STATUS)6U)
#define WAIT_ALPHA2                    ((ENM_AG_SENS_CALIB_STATUS)7U)

typedef uint8 ENM_MOTO_STATUS;

/* enum ENM_MOTO_STATUS */
#define OFF                            ((ENM_MOTO_STATUS)0U)     /* Default value */
#define OPEN_LOOP                      ((ENM_MOTO_STATUS)1U)
#define CLOSED_LOOP                    ((ENM_MOTO_STATUS)2U)

typedef uint8 ENM_PH_CURR_SMP_MODE;

/* enum ENM_PH_CURR_SMP_MODE */
#define SNGSHT_GRO                     ((ENM_PH_CURR_SMP_MODE)1U) /* Default value */
#define TWOSHT_PHA                     ((ENM_PH_CURR_SMP_MODE)2U)
#define THRSENS_PHA                    ((ENM_PH_CURR_SMP_MODE)3U)

typedef uint8 ENM_PWM_MODE;

/* enum ENM_PWM_MODE */
#define SPWM                           ((ENM_PWM_MODE)1U)        /* Default value */
#define S3APWM                         ((ENM_PWM_MODE)2U)
#define SVPWM                          ((ENM_PWM_MODE)3U)
#define DMINPWM                        ((ENM_PWM_MODE)4U)

typedef uint8 ENM_STRTUP_TRQ_STATUS;

/* enum ENM_STRTUP_TRQ_STATUS */
#define TRQ_CST                        ((ENM_STRTUP_TRQ_STATUS)0U) /* Default value */
#define TRQ_DECRE                      ((ENM_STRTUP_TRQ_STATUS)1U)

typedef uint8 ENM_SYS_STATUS;

/* enum ENM_SYS_STATUS */
#define STANDBY                        ((ENM_SYS_STATUS)0U)
#define RUN                            ((ENM_SYS_STATUS)1U)
#define POSTRUN                        ((ENM_SYS_STATUS)2U)
#define SYSINIT                        ((ENM_SYS_STATUS)3U)      /* Default value */
#define SYSFAIL                        ((ENM_SYS_STATUS)4U)
#define LIMPHOME                       ((ENM_SYS_STATUS)5U)
#define SYSSLEEP                       ((ENM_SYS_STATUS)6U)
#define SYSDERATING                    ((ENM_SYS_STATUS)7U)

typedef uint8 ENM_TYPE_FALT;

/* enum ENM_TYPE_FALT */
#define PH_CURR_HI_LVL1                ((ENM_TYPE_FALT)0U)       /* Default value */
#define HW_OVER_CURR                   ((ENM_TYPE_FALT)1U)
#define SPLY_VLTG_LO_LVL1              ((ENM_TYPE_FALT)2U)
#define SPLY_VLTG_LO_LVL2              ((ENM_TYPE_FALT)3U)
#define SPLY_VLTG_HI_LVL1              ((ENM_TYPE_FALT)4U)
#define PWR_TUB_PCB_TEMP_HI_LVL1       ((ENM_TYPE_FALT)5U)
#define PWR_TUB_PCB_TEMP_HI_LVL2       ((ENM_TYPE_FALT)6U)
#define MOTO_TEMP_HI_LVL1              ((ENM_TYPE_FALT)7U)
#define MOTO_TEMP_HI_LVL2              ((ENM_TYPE_FALT)8U)
#define COM_FALT                       ((ENM_TYPE_FALT)9U)
#define MOTO_STALL_PERM                ((ENM_TYPE_FALT)10U)
#define MOTO_STALL_TMP                 ((ENM_TYPE_FALT)11U)
#define NO_LD                          ((ENM_TYPE_FALT)12U)
#define BATT_PWR_HI_LVL1               ((ENM_TYPE_FALT)13U)
#define MOTO_SPD_HI_LVL1               ((ENM_TYPE_FALT)14U)
#define MOTO_SPD_LO_LVL1               ((ENM_TYPE_FALT)15U)
#define CTL_BRD_VLTG_LO_LVL1           ((ENM_TYPE_FALT)16U)
#define CTL_BRD_VLTG_HI_LVL1           ((ENM_TYPE_FALT)17U)
#define GD_VLTG_LO_LVL1                ((ENM_TYPE_FALT)18U)
#define GD_VLTG_HI_LVL1                ((ENM_TYPE_FALT)19U)
#define CHIP_FALT                      ((ENM_TYPE_FALT)20U)
#define PHI_SENS_FALT                  ((ENM_TYPE_FALT)21U)
#define PH_CURR_SENS_FALT              ((ENM_TYPE_FALT)22U)
#define PWR_TUB_PCB_TEMP_SENS_FALT     ((ENM_TYPE_FALT)23U)
#define MOTO_TEMP_SENS_FALT            ((ENM_TYPE_FALT)24U)
#define BUSOFF_FALT                    ((ENM_TYPE_FALT)25U)
#define CRASH_FALT                     ((ENM_TYPE_FALT)26U)
#define MOSOPNCIR_FALT                 ((ENM_TYPE_FALT)27U)
#define FAULT_RESERVED4                ((ENM_TYPE_FALT)28U)
#define FAULT_RESERVED5                ((ENM_TYPE_FALT)29U)

typedef uint16 dt_CurrCtrlIntgGain_u16p5b0;
typedef uint16 dt_CurrCtrlPropGain_u16p15b0;
typedef uint16 dt_DutyCycl_u16p15b0;
typedef uint16 dt_MotRstn_u16p20b0;
typedef uint16 dt_OmodFact_u16p15b0;
typedef sint16 dt_RadAngErr_s16r13b0;
typedef sint16 dt_RadAng_s16r15b0;
typedef uint16 dt_RadAng_u16r15b0;
typedef sint16 dt_RefSpdSlewRate_s16p12b0;
typedef uint16 dt_SpdCtrlIntgGain_u16p9b0;
typedef uint16 dt_SpdCtrlPropGain_u16p12b0;
typedef sint16 dt_Standardize_s16p15b0;
typedef uint16 dt_Standardize_u16p15b0;
typedef uint8 dt_Temp_u8p0bn40;
typedef uint16 dt_VltgRat_u16p22b0;

#endif                                /* RTW_HEADER_custom_type_definition_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
