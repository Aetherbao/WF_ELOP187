/*
 * File: div_nzp_repeat_u32.c
 *
 * Code generated for Simulink model 'ASW_OBD'.
 *
 * Model version                  : 6.265
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:35:33 2025
 */

#include "div_nzp_repeat_u32.h"
#include "rtwtypes.h"

uint32 div_nzp_repeat_u32(uint32 numerator, uint32 denominator, uint32
  nRepeatSub)
{
  uint32 iRepeatSub;
  uint32 localNumerator;
  uint32 quotient;
  boolean numeratorExtraBit;
  quotient = numerator / denominator;
  localNumerator = numerator % denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (localNumerator >= 2147483648U);
    localNumerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (localNumerator >= denominator)) {
      quotient++;
      localNumerator -= denominator;
    }
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
