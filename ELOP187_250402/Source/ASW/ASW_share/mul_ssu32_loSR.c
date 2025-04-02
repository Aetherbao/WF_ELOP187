/*
 * File: mul_ssu32_loSR.c
 *
 * Code generated for Simulink model 'ASW_AST'.
 *
 * Model version                  : 6.236
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Apr  1 14:26:19 2025
 */

#include "mul_ssu32_loSR.h"
#include "mul_wide_su32.h"
#include "rtwtypes.h"

sint32 mul_ssu32_loSR(sint32 a, uint32 b, uint32 aShift)
{
  uint32 u32_chi;
  uint32 u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = (u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift)) | (u32_clo >> aShift);
  return (sint32)u32_clo;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
