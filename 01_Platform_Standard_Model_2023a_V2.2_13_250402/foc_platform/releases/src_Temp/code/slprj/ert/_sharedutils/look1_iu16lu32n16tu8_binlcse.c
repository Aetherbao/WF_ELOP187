/*
 * File: look1_iu16lu32n16tu8_binlcse.c
 *
 * Code generated for Simulink model 'ASW_SigIn'.
 *
 * Model version                  : 6.146
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Apr  2 08:54:23 2025
 */

#include "look1_iu16lu32n16tu8_binlcse.h"
#include "rtwtypes.h"

uint8 look1_iu16lu32n16tu8_binlcse(uint16 u0, const uint16 bp0[], const
  uint8 table[], uint32 maxIndex)
{
  uint32 frac;
  uint32 iLeft;
  uint32 iRght;
  uint16 bpLeftVar;
  uint8 y;
  uint8 yL_0d0;
  uint8 yR_0d0;

  /* Column-major Lookup 1-D
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
  yR_0d0 = table[iLeft + 1U];
  yL_0d0 = table[iLeft];
  if (yR_0d0 >= yL_0d0) {
    y = (uint8)(((uint32)((uint8)((((uint8)(((uint32)yR_0d0) - yL_0d0))
      * frac) >> 16))) + yL_0d0);
  } else {
    y = (uint8)(((uint32)yL_0d0) - ((uint8)((((uint8)(((uint32)yL_0d0)
      - yR_0d0)) * frac) >> 16)));
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
