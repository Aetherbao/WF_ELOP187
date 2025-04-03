/*
 * File: mul_s32_loSR.c
 *
 * Code generated for Simulink model 'ASW_PhVltgGen'.
 *
 * Model version                  : 6.197
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 14 13:34:34 2025
 */

#include "mul_s32_loSR.h"
//#include "mul_wide_s32.h"
#include "rtwtypes.h"

void mul_wide_s32(sint32 in0, sint32 in1, uint32 *ptrOutBitsHi, uint32
                  *ptrOutBitsLo)
{
  uint32 absIn0;
  uint32 absIn1;
  uint32 in0Hi;
  uint32 in0Lo;
  uint32 in1Hi;
  uint32 productHiLo;
  uint32 productLoHi;
  absIn0 = (in0 < 0) ? ((~((uint32)in0)) + 1U) : ((uint32)in0);
  absIn1 = (in1 < 0) ? ((~((uint32)in1)) + 1U) : ((uint32)in1);
  in0Hi = (absIn0 >> 16U);
  in0Lo = absIn0 & 65535U;
  in1Hi = (absIn1 >> 16U);
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ (productHiLo << /*MW:OvBitwiseOk*/ 16U);
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + (in0Hi * in1Hi)) +
    absIn1;
  if ((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}
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
