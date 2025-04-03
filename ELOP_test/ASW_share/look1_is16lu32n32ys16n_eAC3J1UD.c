/*
 * File: look1_is16lu32n32ys16n_eAC3J1UD.c
 *
 * Code generated for Simulink model 'ASW_OBD'.
 *
 * Model version                  : 6.265
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:35:33 2025
 */

#include "look1_is16lu32n32ys16n_eAC3J1UD.h"
#include "div_nzp_repeat_u32.c"
#include "mul_ssu32_loSR.h"
#include "rtwtypes.h"

sint16 look1_is16lu32n32ys16n_eAC3J1UD(sint16 u0, const sint16 bp0[], const
  sint16 table[], uint32 maxIndex)
{
  sint32 finalAccum;
  uint32 frac;
  uint32 iLeft;
  uint32 iRght;
  sint16 bpLeftVar;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16lu32n32ys16n15Ds32Is32n30_binlcass
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
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
    frac = div_nzp_repeat_u32(((uint32)((uint16)(u0 - bpLeftVar))) << 16,
      (uint16)(bp0[iLeft + 1U] - bpLeftVar), 16U);
  } else {
    iLeft = maxIndex;
    frac = 0U;
  }

  /* Column-major Interpolation 1-D
     Canonical function name: intrp1d_s16p15s32s32u32u32n32la_s
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (iLeft == maxIndex) {
    finalAccum = (table[iLeft] << 15);
  } else {
    bpLeftVar = table[iLeft];
    finalAccum = mul_ssu32_loSR(table[iLeft + 1U] - bpLeftVar, frac, 17U) +
      (bpLeftVar << 15);
  }

  finalAccum >>= 15;
  if (finalAccum > 32767) {
    finalAccum = 32767;
  } else if (finalAccum < -32768) {
    finalAccum = -32768;
  }

  return (sint16)finalAccum;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
