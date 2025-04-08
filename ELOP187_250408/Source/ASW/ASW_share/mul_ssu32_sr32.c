/*
 * File: mul_ssu32_sr32.c
 *
 * Code generated for Simulink model 'rmd_SlowRateTask_100Hz'.
 *
 * Model version                  : 5.104
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Sep 27 16:30:01 2023
 */

#include "mul_ssu32_sr32.h"
#include "mul_wide_su32.h"
#include "rtwtypes.h"

sint32 mul_ssu32_sr32(sint32 a, uint32 b)
{
  uint32 u32_chi;
  uint32 u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  return (sint32)u32_chi;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
