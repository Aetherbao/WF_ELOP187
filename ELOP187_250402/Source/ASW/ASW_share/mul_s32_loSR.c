/*
 * File: mul_s32_loSR.c
 *
 * Code generated for Simulink model 'ASW_PhVltgGen'.
 *
 * Model version                  : 6.209
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Feb 26 15:02:31 2025
 */

#include "mul_s32_loSR.h"
#include "mul_wide_s32.h"
#include "rtwtypes.h"

sint32 mul_s32_loSR(sint32 a, sint32 b, uint32 aShift)
{
  uint32 u32_chi;
  uint32 u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = (u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift)) | (u32_clo >> aShift);
  return (sint32)u32_clo;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
