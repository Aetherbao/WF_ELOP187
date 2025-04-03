/*
 * File: ASW_DcycGen.c
 *
 * Code generated for Simulink model 'ASW_DcycGen'.
 *
 * Model version                  : 6.161
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Mar 25 10:38:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ASW_DcycGen.h"
#include "ASW_DcycGen_private.h"
#include "../ASW_share/motor_control_interface.h"
#include "../ASW_share/rtwtypes.h"
#include "../ASW_share/custom_type_definition.h"
#include "../ASW_par/motor_control_param.h"
#include <string.h>

const BUS_DCYCGEN_FST_TASK_OUT ASW_DcycGen_rtZBUS_DCYCGEN_FST_TASK_OUT = {
  {
    0U, 0U, 0U }
  ,                                    /* u16_dcycPhDyc */
  0U,                                  /* u16_ampMaxNrmVltgAmp */
  0U                                   /* u16_phiModulActElecAg */
};                                     /* BUS_DCYCGEN_FST_TASK_OUT ground */

/* Exported block signals */
BUS_DCYCGEN_FST_TASK_IN busDcycGen_FstTaskIn;/* '<Root>/busDcycGen_FstTaskIn' */
BUS_DCYCGEN_FST_TASK_OUT busDcycGen_FstTaskOut;/* '<S82>/Bus Creator1' */

/* Block states (default storage) */
DW_ASW_DcycGen ASW_DcycGen_DW;
const BUS_DCYCGEN_FST_TASK_IN ASW_DcycGen_rtZBUS_DCYCGEN_FST_ = { 0U,/* u16_ampDycAmp */
  0U,                                  /* u16_phiActElecAg */
  0U,                                  /* u16_phiDaxQaxVltgAg */
  0U,                                  /* enm_stMotoSt */
  0,                                   /* s16_nPredActElecSpd */
  false                                /* bol_enPosSCDCalibEnFlg */
};

/* Output and update for atomic system: '<Root>/DcycGen_FstTask' */
void DcycGen_FstTask(void)
{
  dt_RadAng_u16r15b0 tmp_0;
  dt_Standardize_s16p15b0 tmp;
  sint16 rtb_Switch1;
  uint16 rtb_Add1;
  uint16 rtb_Add1_agvg;
  uint16 rtb_Add1_cvlw;
  uint16 rtb_Add1_hqrl;
  uint16 rtb_Add1_l2i3;
  uint16 rtb_Saturation_0;
  uint16 rtb_Sum;
  boolean rtb_LogicalOperator;
  boolean tmp_1;

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/busDcycGen_FstTaskIn'
   */
  if (busDcycGen_FstTaskIn.u16_ampDycAmp <= 32768) {
    rtb_Saturation_0 = busDcycGen_FstTaskIn.u16_ampDycAmp;
  } else {
    rtb_Saturation_0 = 32768U;
  }

  /* Logic: '<S83>/Logical Operator' incorporates:
   *  Constant: '<S84>/Constant'
   *  Inport: '<Root>/busDcycGen_FstTaskIn'
   *  RelationalOperator: '<S84>/Compare'
   */
  rtb_LogicalOperator = ((busDcycGen_FstTaskIn.enm_stMotoSt != CLOSED_LOOP) ||
    (busDcycGen_FstTaskIn.bol_enPosSCDCalibEnFlg));

  /* Switch: '<S89>/Switch1' incorporates:
   *  Constant: '<S89>/Constant'
   *  Gain: '<S83>/Gain'
   *  Logic: '<S89>/NOT'
   *  Product: '<S89>/Product1'
   *  Saturate: '<S83>/Saturation'
   */
  if (!rtb_LogicalOperator) {
    /* Saturate: '<S83>/Saturation' incorporates:
     *  Inport: '<Root>/busDcycGen_FstTaskIn'
     */
    if (busDcycGen_FstTaskIn.s16_nPredActElecSpd >= -32767) {
      tmp = busDcycGen_FstTaskIn.s16_nPredActElecSpd;
    } else {
      tmp = -32767;
    }

    rtb_Switch1 = (sint16)(((tmp >> 1) * 16777) >> 14);
  } else {
    rtb_Switch1 = 0;
  }

  /* End of Switch: '<S89>/Switch1' */

  /* Switch: '<S94>/Switch1' incorporates:
   *  Constant: '<S94>/Constant1'
   *  UnitDelay: '<S94>/Unit Delay1'
   */
  if (ASW_DcycGen_DW.bitsForTID0.UnitDelay1_DSTATE) {
    tmp_1 = rtb_LogicalOperator;
  } else {
    tmp_1 = true;
  }

  /* Switch: '<S94>/Switch' incorporates:
   *  Inport: '<Root>/busDcycGen_FstTaskIn'
   *  Switch: '<S94>/Switch1'
   *  UnitDelay: '<S94>/Unit Delay'
   */
  if (tmp_1) {
    tmp_0 = busDcycGen_FstTaskIn.u16_phiActElecAg;
  } else {
    tmp_0 = ASW_DcycGen_DW.UnitDelay_DSTATE;
  }

  /* Sum: '<S89>/Sum' incorporates:
   *  Switch: '<S89>/Switch1'
   *  Switch: '<S94>/Switch'
   */
  rtb_Sum = (uint16)((((rtb_Switch1 * 20861) >> 2) + (tmp_0 << 14)) >> 14);

  /* SwitchCase: '<S2>/Switch Case' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  switch (Genm_modePWMMode_C) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/sas_SinuPWM' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Sum: '<S67>/Add1' incorporates:
     *  Constant: '<S67>/Constant'
     *  Inport: '<Root>/busDcycGen_FstTaskIn'
     *  Sum: '<S67>/Add'
     *  Sum: '<S89>/Sum'
     *  Switch: '<S89>/Switch'
     */
    rtb_Add1_agvg = (uint16)(((uint32)rtb_Sum) + ((uint16)
      (busDcycGen_FstTaskIn.u16_phiDaxQaxVltgAg - 16384)));

    /* SignalConversion generated from: '<S10>/u16_dcycPhDycCs1' incorporates:
     *  Constant: '<S71>/Constant'
     *  Constant: '<S71>/Constant1'
     *  Constant: '<S71>/Constant2'
     *  Constant: '<S71>/Constant3'
     *  Constant: '<S71>/Constant4'
     *  Constant: '<S71>/Constant5'
     *  Constant: '<S78>/Constant'
     *  Gain: '<S71>/Gain'
     *  Merge: '<S2>/Merge'
     *  Product: '<S71>/Divide'
     *  Product: '<S71>/Product'
     *  Saturate: '<S2>/Saturation'
     *  Selector: '<S71>/Selector'
     *  Selector: '<S71>/Selector1'
     *  Selector: '<S71>/Selector2'
     *  Sum: '<S67>/Add1'
     *  Sum: '<S71>/Add'
     *  Sum: '<S71>/Add3'
     *  Sum: '<S78>/Add'
     */
    busDcycGen_FstTaskOut.u16_dcycPhDyc[0] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant2_Value[(uint16)((1023U * ((((uint32)
                rtb_Add1_agvg) << 15) / 65535U)) >> 15)]) >> 15) << 1) + 32768) >>
       1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[1] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant3_Value[(uint16)((1023U * ((((uint32)
                ((uint16)(rtb_Add1_agvg - 21845))) << 15) / 65535U)) >> 15)]) >>
          15) << 1) + 32768) >> 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[2] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant4_Value[(uint16)((1023U * ((((uint32)
                ((uint16)(rtb_Add1_agvg - 43691))) << 15) / 65535U)) >> 15)]) >>
          15) << 1) + 32768) >> 1);

    /* SignalConversion generated from: '<S10>/u16_ampMaxNrmVltgAmpCs1' incorporates:
     *  Constant: '<S67>/Constant3'
     *  Merge: '<S2>/Merge1'
     *  Product: '<S67>/Product1'
     */
    busDcycGen_FstTaskOut.u16_ampMaxNrmVltgAmp = (dt_DutyCycl_u16p15b0)(((uint32)
      Gu16_facOvrModulFac_C) >> 1);

    /* End of Outputs for SubSystem: '<S2>/sas_SinuPWM' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/sas_SinuAddThrdHarmPWM' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Sum: '<S53>/Add1' incorporates:
     *  Constant: '<S53>/Constant'
     *  Inport: '<Root>/busDcycGen_FstTaskIn'
     *  Sum: '<S53>/Add'
     *  Sum: '<S89>/Sum'
     *  Switch: '<S89>/Switch'
     */
    rtb_Add1_cvlw = (uint16)(((uint32)rtb_Sum) + ((uint16)
      (busDcycGen_FstTaskIn.u16_phiDaxQaxVltgAg - 16384)));

    /* SignalConversion generated from: '<S9>/u16_dcycPhDycCs2' incorporates:
     *  Constant: '<S57>/Constant'
     *  Constant: '<S57>/Constant1'
     *  Constant: '<S57>/Constant2'
     *  Constant: '<S57>/Constant3'
     *  Constant: '<S57>/Constant4'
     *  Constant: '<S57>/Constant5'
     *  Constant: '<S64>/Constant'
     *  Gain: '<S57>/Gain'
     *  Merge: '<S2>/Merge'
     *  Product: '<S57>/Divide'
     *  Product: '<S57>/Product'
     *  Saturate: '<S2>/Saturation'
     *  Selector: '<S57>/Selector'
     *  Selector: '<S57>/Selector1'
     *  Selector: '<S57>/Selector2'
     *  Sum: '<S53>/Add1'
     *  Sum: '<S57>/Add'
     *  Sum: '<S57>/Add3'
     *  Sum: '<S64>/Add'
     */
    busDcycGen_FstTaskOut.u16_dcycPhDyc[0] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant2_Value_o0nc[(uint16)((1023U *
             ((((uint32)rtb_Add1_cvlw) << 15) / 65535U)) >> 15)]) >> 15) << 1) +
        32768) >> 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[1] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant3_Value_plsi[(uint16)((1023U *
             ((((uint32)((uint16)(rtb_Add1_cvlw - 21845))) << 15) / 65535U)) >>
            15)]) >> 15) << 1) + 32768) >> 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[2] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant4_Value_dztf[(uint16)((1023U *
             ((((uint32)((uint16)(rtb_Add1_cvlw - 43691))) << 15) / 65535U)) >>
            15)]) >> 15) << 1) + 32768) >> 1);

    /* SignalConversion generated from: '<S9>/u16_ampMaxNrmVltgAmpCs2' incorporates:
     *  Constant: '<S53>/Constant1'
     *  Constant: '<S53>/Constant3'
     *  Merge: '<S2>/Merge1'
     *  Product: '<S53>/Product1'
     */
    busDcycGen_FstTaskOut.u16_ampMaxNrmVltgAmp = (dt_DutyCycl_u16p15b0)((18919U *
      Gu16_facOvrModulFac_C) >> 15);

    /* End of Outputs for SubSystem: '<S2>/sas_SinuAddThrdHarmPWM' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/sas_SVPWM' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S39>/Add1' incorporates:
     *  Constant: '<S39>/Constant'
     *  Inport: '<Root>/busDcycGen_FstTaskIn'
     *  Sum: '<S39>/Add'
     *  Sum: '<S89>/Sum'
     *  Switch: '<S89>/Switch'
     */
    rtb_Add1_l2i3 = (uint16)(((uint32)rtb_Sum) + ((uint16)
      (busDcycGen_FstTaskIn.u16_phiDaxQaxVltgAg - 16384)));

    /* SignalConversion generated from: '<S8>/u16_dcycPhDycCs3' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S43>/Constant3'
     *  Constant: '<S43>/Constant4'
     *  Constant: '<S43>/Constant5'
     *  Constant: '<S50>/Constant'
     *  Gain: '<S43>/Gain'
     *  Merge: '<S2>/Merge'
     *  Product: '<S43>/Divide'
     *  Product: '<S43>/Product'
     *  Saturate: '<S2>/Saturation'
     *  Selector: '<S43>/Selector'
     *  Selector: '<S43>/Selector1'
     *  Selector: '<S43>/Selector2'
     *  Sum: '<S39>/Add1'
     *  Sum: '<S43>/Add'
     *  Sum: '<S43>/Add3'
     *  Sum: '<S50>/Add'
     */
    busDcycGen_FstTaskOut.u16_dcycPhDyc[0] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant2_Value_oxew[(uint16)((1023U *
             ((((uint32)rtb_Add1_l2i3) << 15) / 65535U)) >> 15)]) >> 15) << 1) +
        32768) >> 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[1] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant3_Value_dctq[(uint16)((1023U *
             ((((uint32)((uint16)(rtb_Add1_l2i3 - 21845))) << 15) / 65535U)) >>
            15)]) >> 15) << 1) + 32768) >> 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[2] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant4_Value_hsqu[(uint16)((1023U *
             ((((uint32)((uint16)(rtb_Add1_l2i3 - 43691))) << 15) / 65535U)) >>
            15)]) >> 15) << 1) + 32768) >> 1);

    /* SignalConversion generated from: '<S8>/u16_ampMaxNrmVltgAmpCs3' incorporates:
     *  Constant: '<S39>/Constant1'
     *  Constant: '<S39>/Constant3'
     *  Merge: '<S2>/Merge1'
     *  Product: '<S39>/Product1'
     */
    busDcycGen_FstTaskOut.u16_ampMaxNrmVltgAmp = (dt_DutyCycl_u16p15b0)((18919U *
      Gu16_facOvrModulFac_C) >> 15);

    /* End of Outputs for SubSystem: '<S2>/sas_SVPWM' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S2>/sas_DisnMinPWM' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Sum: '<S25>/Add1' incorporates:
     *  Constant: '<S25>/Constant'
     *  Inport: '<Root>/busDcycGen_FstTaskIn'
     *  Sum: '<S25>/Add'
     *  Sum: '<S89>/Sum'
     *  Switch: '<S89>/Switch'
     */
    rtb_Add1_hqrl = (uint16)(((uint32)rtb_Sum) + ((uint16)
      (busDcycGen_FstTaskIn.u16_phiDaxQaxVltgAg - 16384)));

    /* SignalConversion generated from: '<S7>/u16_dcycPhDycCs4' incorporates:
     *  Constant: '<S29>/Constant'
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S29>/Constant2'
     *  Constant: '<S29>/Constant3'
     *  Constant: '<S29>/Constant4'
     *  Constant: '<S29>/Constant5'
     *  Gain: '<S29>/Gain'
     *  Merge: '<S2>/Merge'
     *  Product: '<S29>/Divide'
     *  Product: '<S29>/Product'
     *  Saturate: '<S2>/Saturation'
     *  Selector: '<S29>/Selector'
     *  Selector: '<S29>/Selector1'
     *  Selector: '<S29>/Selector2'
     *  Sum: '<S25>/Add1'
     *  Sum: '<S29>/Add'
     *  Sum: '<S29>/Add3'
     *  Sum: '<S36>/Add'
     */
    busDcycGen_FstTaskOut.u16_dcycPhDyc[0] = (uint16)(((uint16)
      ((rtb_Saturation_0 * rtCP_Constant2_Value_jykr[(uint16)((1023U *
      ((((uint32)rtb_Add1_hqrl) << 15) / 65535U)) >> 15)]) >> 15)) << 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[1] = (uint16)(((uint16)
      ((rtb_Saturation_0 * rtCP_Constant3_Value_j2aj[(uint16)((1023U *
      ((((uint32)((uint16)(rtb_Add1_hqrl - 21845))) << 15) / 65535U)) >> 15)]) >>
       15)) << 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[2] = (uint16)(((uint16)
      ((rtb_Saturation_0 * rtCP_Constant4_Value_e3ib[(uint16)((1023U *
      ((((uint32)((uint16)(rtb_Add1_hqrl - 43691))) << 15) / 65535U)) >> 15)]) >>
       15)) << 1);

    /* SignalConversion generated from: '<S7>/u16_ampMaxNrmVltgAmpCs4' incorporates:
     *  Constant: '<S25>/Constant1'
     *  Constant: '<S25>/Constant3'
     *  Merge: '<S2>/Merge1'
     *  Product: '<S25>/Product1'
     */
    busDcycGen_FstTaskOut.u16_ampMaxNrmVltgAmp = (dt_DutyCycl_u16p15b0)((18919U *
      Gu16_facOvrModulFac_C) >> 15);

    /* End of Outputs for SubSystem: '<S2>/sas_DisnMinPWM' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/sas_Dfl' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Sum: '<S11>/Add1' incorporates:
     *  Constant: '<S11>/Constant'
     *  Inport: '<Root>/busDcycGen_FstTaskIn'
     *  Sum: '<S11>/Add'
     *  Sum: '<S89>/Sum'
     *  Switch: '<S89>/Switch'
     */
    rtb_Add1 = (uint16)(((uint32)rtb_Sum) + ((uint16)
      (busDcycGen_FstTaskIn.u16_phiDaxQaxVltgAg - 16384)));

    /* SignalConversion generated from: '<S6>/u16_dcycPhDycCsDfl' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S15>/Constant2'
     *  Constant: '<S15>/Constant3'
     *  Constant: '<S15>/Constant4'
     *  Constant: '<S15>/Constant5'
     *  Constant: '<S22>/Constant'
     *  Gain: '<S15>/Gain'
     *  Merge: '<S2>/Merge'
     *  Product: '<S15>/Divide'
     *  Product: '<S15>/Product'
     *  Saturate: '<S2>/Saturation'
     *  Selector: '<S15>/Selector'
     *  Selector: '<S15>/Selector1'
     *  Selector: '<S15>/Selector2'
     *  Sum: '<S11>/Add1'
     *  Sum: '<S15>/Add'
     *  Sum: '<S15>/Add3'
     *  Sum: '<S22>/Add'
     */
    busDcycGen_FstTaskOut.u16_dcycPhDyc[0] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant2_Value_fxfk[(uint16)((1023U *
             ((((uint32)rtb_Add1) << 15) / 65535U)) >> 15)]) >> 15) << 1) +
        32768) >> 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[1] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant3_Value_pkbs[(uint16)((1023U *
             ((((uint32)((uint16)(rtb_Add1 - 21845))) << 15) / 65535U)) >> 15)])
          >> 15) << 1) + 32768) >> 1);
    busDcycGen_FstTaskOut.u16_dcycPhDyc[2] = (dt_DutyCycl_u16p15b0)
      (((((rtb_Saturation_0 * rtCP_Constant4_Value_imww[(uint16)((1023U *
             ((((uint32)((uint16)(rtb_Add1 - 43691))) << 15) / 65535U)) >> 15)])
          >> 15) << 1) + 32768) >> 1);

    /* SignalConversion generated from: '<S6>/u16_ampMaxNrmVltgAmpCsDfl' incorporates:
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Constant3'
     *  Merge: '<S2>/Merge1'
     *  Product: '<S11>/Product1'
     */
    busDcycGen_FstTaskOut.u16_ampMaxNrmVltgAmp = (dt_DutyCycl_u16p15b0)((18919U *
      Gu16_facOvrModulFac_C) >> 15);

    /* End of Outputs for SubSystem: '<S2>/sas_Dfl' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* BusCreator: '<S82>/Bus Creator1' incorporates:
   *  Sum: '<S89>/Sum'
   *  Switch: '<S89>/Switch'
   */
  busDcycGen_FstTaskOut.u16_phiModulActElecAg = rtb_Sum;

  /* Update for UnitDelay: '<S94>/Unit Delay1' incorporates:
   *  Constant: '<S94>/Constant'
   */
  ASW_DcycGen_DW.bitsForTID0.UnitDelay1_DSTATE = true;

  /* Update for UnitDelay: '<S94>/Unit Delay' incorporates:
   *  Sum: '<S89>/Sum'
   *  Switch: '<S89>/Switch'
   */
  ASW_DcycGen_DW.UnitDelay_DSTATE = rtb_Sum;
}


/*
 * File trailer for generated code.
 *
 * [EOF]
 */
