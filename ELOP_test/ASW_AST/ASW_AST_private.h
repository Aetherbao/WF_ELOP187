/*
 * File: ASW_AST_private.h
 *
 * Code generated for Simulink model 'ASW_AST'.
 *
 * Model version                  : 6.225
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:33:06 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ASW_AST_private_h_
#define RTW_HEADER_ASW_AST_private_h_
#include "../ASW_share/rtwtypes.h"
#include "../ASW_share/custom_type_definition.h"
#include "ASW_AST.h"

/* Includes for objects with custom storage classes */
#include "../ASW_par/motor_control_param.h"
#include "../ASW_par/motor_param.h"
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

extern const uint32 rtCP_pooled_JyOGC55IyIsD[2];
extern const uint16 rtCP_pooled_rp0I2sPNEO4V[512];
extern const uint16 rtCP_pooled_GGuKQ5avRdmD[512];

#define rtCP_Gu16_etaCtlBrd_MAP_maxInde rtCP_pooled_JyOGC55IyIsD /* Computed Parameter: rtCP_Gu16_etaCtlBrd_MAP_maxInde
                                                                  * Referenced by: '<S5>/Gu16_etaCtlBrd_MAP'
                                                                  */
#define rtCP_Constant3_Value           rtCP_pooled_rp0I2sPNEO4V  /* Computed Parameter: rtCP_Constant3_Value
                                                                  * Referenced by: '<S17>/Constant3'
                                                                  */
#define rtCP_Constant3_Value_jnyd      rtCP_pooled_GGuKQ5avRdmD  /* Computed Parameter: rtCP_Constant3_Value_jnyd
                                                                  * Referenced by: '<S58>/Constant3'
                                                                  */

extern void ASW_AST_Chart_Init(boolean *rty_lb_noRatLimReq, boolean
  *rty_lb_incrRatLimReq, boolean *rty_lb_decrRatLimReq);
extern void ASW_AST_Chart(boolean rtu_lb_incrRatLimOn, boolean
  rtu_lb_decrRatLimOn, boolean *rty_lb_noRatLimReq, boolean
  *rty_lb_incrRatLimReq, boolean *rty_lb_decrRatLimReq);
extern void AST_SlwTask_Init(void);
extern void AST_SlwTask(void);

#endif                                 /* RTW_HEADER_ASW_AST_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
