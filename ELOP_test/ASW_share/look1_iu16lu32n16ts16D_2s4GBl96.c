/*
 * File: look1_iu16lu32n16ts16D_2s4GBl96.c
 *
 * Code generated for Simulink model 'ASW_AST'.
 *
 * Model version                  : 6.225
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:33:06 2025
 */

#include "look1_iu16lu32n16ts16D_2s4GBl96.h"
#include "rtwtypes.h"

sint16 look1_iu16lu32n16ts16D_2s4GBl96(uint16 u0, const uint16 bp0[], const
  sint16 table[], uint32 maxIndex)
{
  uint32 frac;
  uint32 iLeft;
  uint32 iRght;
  sint16 yL_0d0;
  uint16 bpLeftVar;

  /* Column-major Lookup 1-D
     Canonical function name: look1_iu16lu32n16ts16Ds32_binlcs
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = (maxIndex >> 1U);
    iLeft = 0U;
    iRght = maxIndex;
    while ((iRght - iLeft) > 1U) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = ((iRght + iLeft) >> 1U);
    }

    bpLeftVar = bp0[iLeft];
    frac = (((uint32)((uint16)(((uint32)u0) - bpLeftVar))) << 16) /
      ((uint16)(((uint32)bp0[iLeft + 1U]) - bpLeftVar));
  } else {
    iLeft = maxIndex - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (sint16)(((sint16)(((table[iLeft + 1U] - yL_0d0) * ((sint32)frac)) >>
    16)) + yL_0d0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
