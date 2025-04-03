/*
 * File: ASW_DcycGen_private.h
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

#ifndef RTW_HEADER_ASW_DcycGen_private_h_
#define RTW_HEADER_ASW_DcycGen_private_h_
#include "../ASW_share/multiword_types.h"
#include "../ASW_share/rtwtypes.h"
// #include "ASW_DcycGen_types.h"
#include "ASW_DcycGen.h"

/* Includes for objects with custom storage classes */
#include "../ASW_par/motor_control_param.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if (UCHAR_MAX != (0xFFU)) || (SCHAR_MAX != (0x7F))
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if (USHRT_MAX != (0xFFFFU)) || (SHRT_MAX != (0x7FFF))
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if (UINT_MAX != (0xFFFFFFFFU)) || (INT_MAX != (0x7FFFFFFF))
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if (ULONG_MAX != (0xFFFFFFFFU)) || (LONG_MAX != (0x7FFFFFFF))
//#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern const sint16 rtCP_pooled_4kPhDAGJJnkK[1024];
extern const sint16 rtCP_pooled_xVWSvxiEcNqv[1024];
extern const sint16 rtCP_pooled_91ugntIedRb3[1024];
extern const sint16 rtCP_pooled_RYEJYHmWHols[1024];

#define rtCP_Constant2_Value                                                   \
  rtCP_pooled_4kPhDAGJJnkK /* Computed Parameter: rtCP_Constant2_Value         \
                            * Referenced by: '<S71>/Constant2'                 \
                            */
#define rtCP_Constant3_Value                                                   \
  rtCP_pooled_4kPhDAGJJnkK /* Computed Parameter: rtCP_Constant3_Value         \
                            * Referenced by: '<S71>/Constant3'                 \
                            */
#define rtCP_Constant4_Value                                                   \
  rtCP_pooled_4kPhDAGJJnkK /* Computed Parameter: rtCP_Constant4_Value         \
                            * Referenced by: '<S71>/Constant4'                 \
                            */
#define rtCP_Constant2_Value_o0nc                                              \
  rtCP_pooled_xVWSvxiEcNqv /* Computed Parameter: rtCP_Constant2_Value_o0nc    \
                            * Referenced by: '<S57>/Constant2'                 \
                            */
#define rtCP_Constant3_Value_plsi                                              \
  rtCP_pooled_xVWSvxiEcNqv /* Computed Parameter: rtCP_Constant3_Value_plsi    \
                            * Referenced by: '<S57>/Constant3'                 \
                            */
#define rtCP_Constant4_Value_dztf                                              \
  rtCP_pooled_xVWSvxiEcNqv /* Computed Parameter: rtCP_Constant4_Value_dztf    \
                            * Referenced by: '<S57>/Constant4'                 \
                            */
#define rtCP_Constant2_Value_oxew                                              \
  rtCP_pooled_91ugntIedRb3 /* Computed Parameter: rtCP_Constant2_Value_oxew    \
                            * Referenced by: '<S43>/Constant2'                 \
                            */
#define rtCP_Constant3_Value_dctq                                              \
  rtCP_pooled_91ugntIedRb3 /* Computed Parameter: rtCP_Constant3_Value_dctq    \
                            * Referenced by: '<S43>/Constant3'                 \
                            */
#define rtCP_Constant4_Value_hsqu                                              \
  rtCP_pooled_91ugntIedRb3 /* Computed Parameter: rtCP_Constant4_Value_hsqu    \
                            * Referenced by: '<S43>/Constant4'                 \
                            */
#define rtCP_Constant2_Value_jykr                                              \
  rtCP_pooled_RYEJYHmWHols /* Computed Parameter: rtCP_Constant2_Value_jykr    \
                            * Referenced by: '<S29>/Constant2'                 \
                            */
#define rtCP_Constant3_Value_j2aj                                              \
  rtCP_pooled_RYEJYHmWHols /* Computed Parameter: rtCP_Constant3_Value_j2aj    \
                            * Referenced by: '<S29>/Constant3'                 \
                            */
#define rtCP_Constant4_Value_e3ib                                              \
  rtCP_pooled_RYEJYHmWHols /* Computed Parameter: rtCP_Constant4_Value_e3ib    \
                            * Referenced by: '<S29>/Constant4'                 \
                            */
#define rtCP_Constant2_Value_fxfk                                              \
  rtCP_pooled_xVWSvxiEcNqv /* Computed Parameter: rtCP_Constant2_Value_fxfk    \
                            * Referenced by: '<S15>/Constant2'                 \
                            */
#define rtCP_Constant3_Value_pkbs                                              \
  rtCP_pooled_xVWSvxiEcNqv /* Computed Parameter: rtCP_Constant3_Value_pkbs    \
                            * Referenced by: '<S15>/Constant3'                 \
                            */
#define rtCP_Constant4_Value_imww                                              \
  rtCP_pooled_xVWSvxiEcNqv /* Computed Parameter: rtCP_Constant4_Value_imww    \
                            * Referenced by: '<S15>/Constant4'                 \
                            */

extern void DcycGen_FstTask(void);

#endif /* RTW_HEADER_ASW_DcycGen_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
