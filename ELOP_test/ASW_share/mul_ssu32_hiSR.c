/*
 * File: mul_ssu32_hiSR.c
 *
 * Code generated for Simulink model 'ASW_AST'.
 *
 * Model version                  : 6.225
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:33:06 2025
 */

#include "mul_ssu32_hiSR.h"
#include "mul_wide_su32.h"
#include "rtwtypes.h"

sint32 mul_ssu32_hiSR(sint32 a, uint32 b, uint32 aShift)
{
  uint32 u32_chi;
  uint32 u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  return ((sint32)u32_chi) >> aShift;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
