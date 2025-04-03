/*
 * File: div_nde_s32_floor.c
 *
 * Code generated for Simulink model 'ASW_AST'.
 *
 * Model version                  : 6.225
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:33:06 2025
 */

#include "div_nde_s32_floor.h"
#include "rtwtypes.h"

sint32 div_nde_s32_floor(sint32 numerator, sint32 denominator)
{
  return ((((numerator < 0) != (denominator < 0)) && ((numerator % denominator)
            != 0)) ? -1 : 0) + (numerator / denominator);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
