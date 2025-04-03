/*
 * File: ASW_OBD_private.h
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

#ifndef RTW_HEADER_ASW_OBD_private_h_
#define RTW_HEADER_ASW_OBD_private_h_
#include "../ASW_share/rtwtypes.h"
#include "../ASW_share/multiword_types.h"
#include "../ASW_share/zero_crossing_types.h"
#include "ASW_OBD.h"
#include "../ASW_share/custom_type_definition.h"
//#include "ASW_OBD_types.h"

/* Includes for objects with custom storage classes */
#include "../ASW_par/motor_control_param.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
//#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern void ASW_OBD_sfc_FaultDebounce_Init(boolean *rty_lb_genOutp,
  DW_sfc_FaultDebounce_ASW_OBD *localDW);
extern void ASW_OBD_sfc_FaultDebounce(boolean rtu_lb_bolInp, uint16
  rtu_lb_cntDebConf, uint16 rtu_lb_cntDebRcvy, boolean *rty_lb_genOutp,
  DW_sfc_FaultDebounce_ASW_OBD *localDW);
extern void ASW_OBD_lib_Deb_11_Init(boolean *rty_lb_genOutp,
  DW_lib_Deb_11_ASW_OBD *localDW);
extern void ASW_OBD_lib_Deb_11(boolean rtu_lb_bolInp, uint16 rtu_lb_cntDebConf,
  uint16 rtu_lb_cntDebRcvy, boolean *rty_lb_genOutp, DW_lib_Deb_11_ASW_OBD
  *localDW);
extern void ASW__sfc_FaultDefiniteness_Init(boolean *rty_stFaltDef_Tmpr, boolean
  *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt, DW_sfc_FaultDefiniteness_ASW_OB
  *localDW);
extern void ASW_OBD_sfc_FaultDefiniteness(boolean rtu_stFaltDeb, boolean
  rtu_bolFaltEnFlg, uint8 rtu_stFaltCycDiaCnt, boolean rtu_bolFaltRecEnFlag,
  boolean *rty_stFaltDef_Tmpr, boolean *rty_stFaltDef_Perm, uint8
  *rty_FaltCycAccCnt, uint16 rtp_lb_FaltWaitRecvCnt,
  DW_sfc_FaultDefiniteness_ASW_OB *localDW);
extern void ASW_OBD_lib_FaltDefd_21_Init(boolean *rty_stFaltDef_Tmpr, boolean
  *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt, DW_lib_FaltDefd_21_ASW_OBD
  *localDW);
extern void ASW_OBD_lib_FaltDefd_21(boolean rtu_stFaltDeb, boolean
  rtu_bolFaltEnFlg, uint8 rtu_stFaltCycDiaCnt, boolean rtu_bolFaltRecEnFlag,
  boolean *rty_stFaltDef_Tmpr, boolean *rty_stFaltDef_Perm, uint8
  *rty_FaltCycAccCnt, uint16 rtp_lb_FaltWaitRecvCnt, DW_lib_FaltDefd_21_ASW_OBD *
  localDW);
extern void ASW_OBD_sfc_Debounce_Init(boolean *rty_lb_genOutp,
  DW_sfc_Debounce_ASW_OBD *localDW);
extern void ASW_OBD_sfc_Debounce(boolean rtu_lb_bolInp, uint16 rtu_lb_cntDebConf,
  boolean *rty_lb_genOutp, DW_sfc_Debounce_ASW_OBD *localDW);
extern void ASW_OBD_lib_HysDeb_1_Init(boolean rtp_lb_parInitOutp,
  DW_lib_HysDeb_1_ASW_OBD *localDW);
extern void ASW_OBD_lib_HysDeb_1(dt_Standardize_u16p15b0 rtu_lb_genInp,
  dt_Standardize_u16p15b0 rtu_lb_genUpLim, dt_Standardize_u16p15b0
  rtu_lb_genLowLim, uint16 rtu_lb_cntSetConf, uint16 rtu_lb_cntRsetConf, boolean
  rtu_lb_bolSet, boolean rtu_lb_bolRset, boolean *rty_lb_bolDebOutp, boolean
  *rty_lb_bolHiOccOutp, boolean *rty_lb_bolLoOccOutp, DW_lib_HysDeb_1_ASW_OBD
  *localDW);
extern void ASW_OBD_lib_HysDeb_14_Init(boolean rtp_lb_parInitOutp,
  DW_lib_HysDeb_14_ASW_OBD *localDW);
extern void ASW_OBD_lib_HysDeb_14(dt_Standardize_s16p15b0 rtu_lb_genInp,
  dt_Standardize_s16p15b0 rtu_lb_genUpLim, dt_Standardize_s16p15b0
  rtu_lb_genLowLim, uint16 rtu_lb_cntSetConf, uint16 rtu_lb_cntRsetConf, boolean
  rtu_lb_bolSet, boolean rtu_lb_bolRset, boolean *rty_lb_bolDebOutp, boolean
  *rty_lb_bolHiOccOutp, boolean *rty_lb_bolLoOccOutp, DW_lib_HysDeb_14_ASW_OBD
  *localDW);
extern void ASW_OBD_lib_HysDeb_12_Init(boolean rtp_lb_parInitOutp,
  DW_lib_HysDeb_12_ASW_OBD *localDW);
extern void ASW_OBD_lib_HysDeb_12(dt_Temp_u8p0bn40 rtu_lb_genInp,
  dt_Temp_u8p0bn40 rtu_lb_genUpLim, dt_Temp_u8p0bn40 rtu_lb_genLowLim, uint16
  rtu_lb_cntSetConf, uint16 rtu_lb_cntRsetConf, boolean rtu_lb_bolSet, boolean
  rtu_lb_bolRset, boolean *rty_lb_bolDebOutp, boolean *rty_lb_bolHiOccOutp,
  boolean *rty_lb_bolLoOccOutp, DW_lib_HysDeb_12_ASW_OBD *localDW);
extern void ASW_OBD_lib_FaltDefd_14_Init(boolean *rty_stFaltDef_Tmpr, boolean
  *rty_stFaltDef_Perm, uint8 *rty_FaltCycAccCnt, DW_lib_FaltDefd_14_ASW_OBD
  *localDW);
extern void ASW_OBD_lib_FaltDefd_14(boolean rtu_stFaltDeb, boolean
  rtu_bolFaltEnFlg, uint8 rtu_stFaltCycDiaCnt, boolean rtu_bolFaltRecEnFlag,
  boolean *rty_stFaltDef_Tmpr, boolean *rty_stFaltDef_Perm, uint8
  *rty_FaltCycAccCnt, uint16 rtp_lb_FaltWaitRecvCnt, DW_lib_FaltDefd_14_ASW_OBD *
  localDW);
extern void ASW_OBD_lib_Deb_12_Init(boolean *rty_lb_genOutp,
  DW_lib_Deb_12_ASW_OBD *localDW);
extern boolean ASW_OBD_lib_Deb_12(boolean rtu_lb_bolInp, uint16
  rtu_lb_cntDebConf, uint16 rtu_lb_cntDebRcvy, DW_lib_Deb_12_ASW_OBD *localDW);
extern void CANHeartLosCheck(void);
extern void CANSigLosCheck(void);
extern void ASW_OBD_sss_FaltLvlConf(void);
extern void ASW_OBD_sss_FaltLvl2Conf(void);
extern void ASW_OBD_sss_FaltEnFlgConf(void);
extern void OBD_SlwTask_Init(void);
extern void OBD_SlwTask(void);

#endif                                 /* RTW_HEADER_ASW_OBD_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
