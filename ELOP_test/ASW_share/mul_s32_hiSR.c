/*
 * File: mul_s32_hiSR.c
 *
 * Code generated for Simulink model 'ASW_PhVltgGen'.
 *
 * Model version                  : 6.190
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Dec  8 14:57:48 2024
 */

#include "mul_s32_hiSR.h"
#include "mul_wide_s32.h"
#include "rtwtypes.h"

sint32 mul_s32_hiSR(sint32 a, sint32 b, uint32 aShift)
{
  uint32 u32_chi;
  uint32 u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return ((sint32)u32_chi) >> aShift;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
