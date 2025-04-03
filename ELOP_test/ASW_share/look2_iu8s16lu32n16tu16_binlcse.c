/*
 * File: look2_iu8s16lu32n16tu16_binlcse.c
 *
 * Code generated for Simulink model 'ASW_PhVltgGen'.
 *
 * Model version                  : 6.211
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Mar 24 20:09:29 2025
 */

#include "look2_iu8s16lu32n16tu16_binlcse.h"
#include "rtwtypes.h"

uint16 look2_iu8s16lu32n16tu16_binlcse(uint8 u0, sint16 u1, const uint8
  bp0[], const sint16 bp1[], const uint16 table[], const uint32 maxIndex[],
  uint32 stride)
{
  uint32 bpIndices[2];
  uint32 fractions[2];
  uint32 bpIdx;
  uint32 frac;
  uint32 iLeft;
  sint16 bpLeftVar_0;
  uint16 y;
  uint16 yL_0d0;
  uint16 yL_1d;
  uint16 yR_0d0;
  uint8 bpLeftVar;

  /* Column-major Lookup 2-D
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
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = (maxIndex[0U] >> 1U);
    iLeft = 0U;
    frac = maxIndex[0U];
    while ((frac - iLeft) > 1U) {
      if (u0 < bp0[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((frac + iLeft) >> 1U);
    }

    bpLeftVar = bp0[iLeft];
    frac = (((uint32)((uint8)(((uint32)u0) - bpLeftVar))) << 16) /
      ((uint8)(((uint32)bp0[iLeft + 1U]) - bpLeftVar));
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 65536U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = (maxIndex[1U] >> 1U);
    iLeft = 0U;
    frac = maxIndex[1U];
    while ((frac - iLeft) > 1U) {
      if (u1 < bp1[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((frac + iLeft) >> 1U);
    }

    bpLeftVar_0 = bp1[iLeft];
    frac = (((uint32)((uint16)(u1 - bpLeftVar_0))) << 16) / ((uint16)
      (bp1[iLeft + 1U] - bpLeftVar_0));
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpIdx = (iLeft * stride) + bpIndices[0U];
  yR_0d0 = table[bpIdx + 1U];
  yL_0d0 = table[bpIdx];
  if (yR_0d0 >= yL_0d0) {
    yL_1d = (uint16)(((uint32)((uint16)((((uint16)(((uint32)yR_0d0) -
      yL_0d0)) * fractions[0U]) >> 16))) + yL_0d0);
  } else {
    yL_1d = (uint16)(((uint32)yL_0d0) - ((uint16)((((uint16)(((uint32)
      yL_0d0) - yR_0d0)) * fractions[0U]) >> 16)));
  }

  bpIdx += stride;
  yR_0d0 = table[bpIdx + 1U];
  yL_0d0 = table[bpIdx];
  if (yR_0d0 >= yL_0d0) {
    yR_0d0 = (uint16)(((uint32)((uint16)((((uint16)(((uint32)yR_0d0) -
      yL_0d0)) * fractions[0U]) >> 16))) + yL_0d0);
  } else {
    yR_0d0 = (uint16)(((uint32)yL_0d0) - ((uint16)((((uint16)(((uint32)
      yL_0d0) - yR_0d0)) * fractions[0U]) >> 16)));
  }

  if (yR_0d0 >= yL_1d) {
    y = (uint16)(((uint32)((uint16)((((uint16)(((uint32)yR_0d0) -
      yL_1d)) * frac) >> 16))) + yL_1d);
  } else {
    y = (uint16)(((uint32)yL_1d) - ((uint16)((((uint16)(((uint32)yL_1d)
      - yR_0d0)) * frac) >> 16)));
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
