/*
 * motor_control_param.c
 *
 * Definition of constants related to motor control 
 *
 */
 
#include "motor_control_param.h"
#include "rtwtypes.h"
#include "Mem_mem.h"

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */

/* PhvltgGen*/
const boolean Gbol_flgDaxQaxCurrClpFlg_C = false;  //OK
const sint16 Gs16_facOpnLpClsLpAgRiseRate_C = 80;
const dt_Standardize_s16p15b0 Gs16_nPLLElecAgSpdUpLim_C = 26214;
const dt_Standardize_s16p15b0 Gs16_nSenlTrnsElecSpd_C = 1311;
const sint16 Gs16_tCtlVltgDelTi_C = 0;//-419;  //OK
const sint16 Gs16_tiSenlElecAgDel_C = 0;  //OK
const sint16 Gs16_tiPhVltgAgDel_C =-700;//-600;//0;  //OK
const uint16 Gu16_ctSenlTrnsElecAgConfCnt_C = 400U;
const uint16 Gu16_ctSenlTrnsElecAgRcvyCnt_C = 0U;
const uint16 Gu16_fEstAgDvtCompFrq_C = 11312U;   //OK
dt_CurrCtrlIntgGain_u16p5b0 Gu16_facDaxCurrCtlKi_C= 600;//12800U;   //OK
dt_CurrCtrlPropGain_u16p15b0 Gu16_facDaxCurrCtlKp_C = 2200;//1638U;  //OK
const uint16 Gu16_facFlxObsFltCoeff_C = 1311U;  //OK
const uint16 Gu16_facPLLCtlKi_C = 3000U;//3200U;
const uint16 Gu16_facPLLCtlKp_C = 400U;//320U;
dt_CurrCtrlIntgGain_u16p5b0 Gu16_facQaxCurrCtlKi_C = 600;//12800U;   //OK
dt_CurrCtrlPropGain_u16p15b0 Gu16_facQaxCurrCtlKp_C = 2200;//1638U;   //OK
const uint16 Gu16_facSpdFltCoeff_C = 13107U;   //OK
const dt_RadAng_u16r15b0 Gu16_phiMaxSenlTrnsElecAg_C = 8188U;
const dt_Temp_u8p0bn40 Gu8_facPLLCtlKp_MAP_tPCBTempSubs_X[4] = { 0U, 40U, 80U, 130U } ;
const dt_Standardize_s16p15b0 Gs16_facPLLCtlKp_MAP_nActElecSpd_Y[4] = { 1000U, 3276U, 10000U, 20000U } ;
//const uint16 Gu16_facPLLCtlKp_MAP[4][4] = {{320,320,320,320},{320,320,320,320},{320,320,320,320},{320,320,320,320}} ;
uint16 Gu16_facPLLCtlKp_MAP[4][4] = {{1200,1200,1200,1200},{1200,1200,1200,1200},{1200,1200,1200,1200},{1200,1200,1200,1200}} ;
//const uint16 Gu16_facPLLCtlKi_MAP[4][4] = {{3200,3200,3200,3200},{3200,3200,3200,3200},{3200,3200,3200,3200},{3200,3200,3200,3200}} ;	
uint16 Gu16_facPLLCtlKi_MAP[4][4] = {{3000,3000,3000,3000},{3000,3000,3000,3000},{3000,3000,3000,3000},{3000,3000,3000,3000}} ;	

/*OBD*/
const dt_Standardize_s16p15b0 Gs16_nNoLdJudgActElecSpd_C = 17927;//4280rpm;
const boolean Gbol_enFaltInfoManClr_C = false;
const boolean Gbol_enLmpHmeStop_C = false;
const boolean Gbol_flgFaltManEnFlg_C = true;
const dt_Standardize_s16p15b0 Gs16_iNoLdPhCurr_CUR[5] = { 768, 896, 896, 896,
  1024 } ;

const dt_Standardize_s16p15b0 Gs16_iNoLdPhCurr_CUR_nActElecSpd_X[5] = { 14656, 15912,
  16744, 18840, 20933 } ;

const dt_Standardize_s16p15b0 Gs16_iPhCurrHiLvl1ConfTrs_C = 8959;
const dt_Standardize_s16p15b0 Gs16_iPhCurrHiLvl1RcvyTrs_C = 8320;
const dt_Standardize_s16p15b0 Gs16_iColdStrtPhCurrHiLvl1ConfTrs_C = 10239;
const dt_Standardize_s16p15b0 Gs16_iColdStrtPhCurrHiLvl1RcvyTrs_C = 9600;
const dt_Standardize_s16p15b0 Gs16_nLmpHmeRefMechSpd_C = 2675;//(2500*107/100);
const dt_Standardize_s16p15b0 Gs16_nMaxMotoSpdDvtConfTrs_C = 1256;//1257;299rpm
const dt_Standardize_s16p15b0 Gs16_nMaxRefMechSpd_C = 5350;  //OK
const dt_Standardize_s16p15b0 Gs16_nMinMotoSpdDvtRcvyTrs_C = 1257;//419;300rpm
const dt_Standardize_s16p15b0 Gs16_nMotoStallMinRefElecSpd_C = 224;//53.5rpm
const dt_Standardize_s16p15b0 Gs16_nMotoTmpStallRefMechSpd_C = 5000;


const uint16 Gu16_ctFaltDiaComSdlCnt_C = 1U;
const uint16 Gu16_ctFaltDiaFstSdlCnt_C = 1U;
const uint16 Gu16_ctFaltDiaSlwSdlCnt_C = 10U;
const uint8 Gu8_ctInitDisblCnt_C = 150U;
const uint16 Gu16_ctLmpHmeDurCnt_C = 100U;
const uint16 Gu16_ctMaxMotoSpdDvtConfCnt_C = 400U;
const uint16 Gu16_ctMinMotoSpdDvtRcvyCnt_C = 100U;//400U;
const dt_Standardize_s16p15b0 Gu16_nMotoSpdHiLvl1ConfTrs_C = 5000;
const dt_Standardize_s16p15b0 Gu16_nMotoSpdHiLvl1RcvyTrs_C = 9216;
const dt_Standardize_u16p15b0 Gu16_psiEstMinPermMagFlx_C = 66U;
const dt_Standardize_u16p15b0 Gu16_pwrBattPwrHiLvl1ConfTrs_C = 9470U;
const uint16 Gu16_stCtlDFPMSt_C[30] = { 174U, 15U, 0U, 15U, 15U, 0U, 15U, 0U, 0U, 13U,
  110U, 12U, 11U, 0U, 0U, 11U, 0U, 0U, 15U, 15U, 14U, 15U, 0U, 11U, 0U, 0U, 14U, 14U, 0U,
  0U } ;  //OK

const uint16 Gu16_uADMotoTempFaltHiLim_C = 4000U;
const uint16 Gu16_uADMotoTempFaltLoLim_C = 100U;
const uint16 Gu16_uADPCBTempFaltHiLim_C = 4000U;
const uint16 Gu16_uADPCBTempFaltLoLim_C = 500U;
const uint16 Gu16_uADPhUCurrFaltHiLim_C = 4000U;
const uint16 Gu16_uADPhUCurrFaltLoLim_C = 100U;
const uint16 Gu16_uADPhVCurrFaltHiLim_C = 4000U;
const uint16 Gu16_uADPhVCurrFaltLoLim_C = 100U;
const uint16 Gu16_uADPwrTubTempFaltHiLim_C = 4000U;
const uint16 Gu16_uADPwrTubTempFaltLoLim_C = 500U;
const dt_Standardize_u16p15b0 Gu16_uComDiaDisblHiLvlConfTrs_C = 8192U;
const dt_Standardize_u16p15b0 Gu16_uComDiaDisblHiLvlRcvyTrs_C = 7936U;
const dt_Standardize_u16p15b0 Gu16_uComDiaDisblLoLvlConfTrs_C = 4608U;
const dt_Standardize_u16p15b0 Gu16_uComDiaDisblLoLvlRcvyTrs_C = 4864U;
const dt_Standardize_u16p15b0 Gu16_uCtlBrdVltgHiLvl1ConfTrs_C = 5000U;
const dt_Standardize_u16p15b0 Gu16_uCtlBrdVltgHiLvl1RcvyTrs_C = 9216U;
const dt_Standardize_u16p15b0 Gu16_uCtlBrdVltgLoLvl1ConfTrs_C = 3840U;
const dt_Standardize_u16p15b0 Gu16_uCtlBrdVltgLoLvl1RcvyTrs_C = 4096U;
const dt_Standardize_u16p15b0 Gu16_uGDVltgHiLvl1ConfTrs_C = 5000U;
const dt_Standardize_u16p15b0 Gu16_uGDVltgHiLvl1RcvyTrs_C = 9216U;
const dt_Standardize_u16p15b0 Gu16_uGDVltgLoLvl1ConfTrs_C = 3840U;
const dt_Standardize_u16p15b0 Gu16_uGDVltgLoLvl1RcvyTrs_C = 4096U;
const dt_Standardize_u16p15b0 Gu16_uSplyVltgHiLvl1ConfTrs_C = 9471U;
const dt_Standardize_u16p15b0 Gu16_uSplyVltgHiLvl1RcvyTrs_C = 9217U;
const dt_Standardize_u16p15b0 Gu16_uSplyVltgLoLvl1ConfTrs_C = 3840U;
const dt_Standardize_u16p15b0 Gu16_uSplyVltgLoLvl1RcvyTrs_C = 4096U;
const dt_Standardize_u16p15b0 Gu16_uSplyVltgLoLvl2ConfTrs_C = 3841U;
const dt_Standardize_u16p15b0 Gu16_uSplyVltgLoLvl2RcvyTrs_C = 4095U;
const uint16 Gu16_ctBattPwrHiLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctBattPwrHiLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctBusOffFaltConfCnt_C = 3U;
const uint16 Gu16_ctBusOffFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctCRCFaltConfCnt_C = 5U;
const uint16 Gu16_ctCRCFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctChipFaltConfCnt_C = 0U;
const uint16 Gu16_ctChipFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctComDiaDisblHiLvlConfCnt_C = 0U;
const uint16 Gu16_ctComDiaDisblHiLvlRcvyCnt_C = 50U;
const uint16 Gu16_ctComDiaDisblLoLvlConfCnt_C = 0U;
const uint16 Gu16_ctComDiaDisblLoLvlRcvyCnt_C = 50U;
const uint16 Gu16_ctComFramLosFaltJudgCnt_C = 8U;
const uint16 Gu16_ctComLosFaltConfCnt_C = 200U;
const uint16 Gu16_ctComLosFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctComRolCntFaltConfCnt_C = 5U;
const uint16 Gu16_ctComRolCntFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctCtlBrdVltgHiLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctCtlBrdVltgHiLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctCtlBrdVltgLoLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctCtlBrdVltgLoLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctDataExcdLimFaltJudgCnt_C = 5U;
const uint16 Gu16_ctGDVltgHiLvl1ConfCnt_C = 50U;
const uint16 Gu16_ctGDVltgHiLvl1RcvyCnt_C = 0U;
const uint16 Gu16_ctGDVltgLoLvl1ConfCnt_C = 50U;
const uint16 Gu16_ctGDVltgLoLvl1RcvyCnt_C = 0U;
const uint16 Gu16_ctHWOvrCurrConfCnt_C = 0U;
const uint16 Gu16_ctHWOvrCurrRcvyCnt_C = 0U;
const uint16 Gu16_ctMesgLngthFaltConfCnt_C = 0U;
const uint16 Gu16_ctMesgLngthFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctMotoSpdHiLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctMotoSpdHiLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctMotoStallConfCnt_C = 400U;
const uint16 Gu16_ctMotoStallRcvyCnt_C = 200U;
const uint16 Gu16_ctMotoTempHiLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctMotoTempHiLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctMotoTempHiLvl2ConfCnt_C = 100U;
const uint16 Gu16_ctMotoTempHiLvl2RcvyCnt_C = 100U;
const uint16 Gu16_ctMotoTempFaltConfCnt_C = 100U;
const uint16 Gu16_ctMotoTempFaltRcvyCnt_C = 100U;
const uint16 Gu16_ctNoLdConfCnt_C = 3000U;
const uint16 Gu16_ctNoLdRcvyCnt_C = 3000U;
const uint16 Gu16_ctPCBTempHiLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctPCBTempHiLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctPCBTempHiLvl2ConfCnt_C = 10U;
const uint16 Gu16_ctPCBTempHiLvl2RcvyCnt_C = 10U;
const uint16 Gu16_ctPCBTempFaltConfCnt_C = 10U;
const uint16 Gu16_ctPCBTempFaltRcvyCnt_C = 10U;
const uint16 Gu16_ctPhCurrHiLvl1ConfCnt_C = 30U;
const uint16 Gu16_ctPhCurrHiLvl1RcvyCnt_C = 180U;
const uint16 Gu16_ctPhCurrSensFaltConfCnt_C = 100U;
const uint16 Gu16_ctPhCurrSensFaltRcvyCnt_C = 100U;
const uint16 Gu16_ctPhiSensFaltConfCnt_C = 0U;
const uint16 Gu16_ctPhiSensFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctPwrTubTempHiLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctPwrTubTempHiLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctPwrTubTempHiLvl2ConfCnt_C = 100U;
const uint16 Gu16_ctPwrTubTempHiLvl2RcvyCnt_C = 100U;
const uint16 Gu16_ctPwrTubTempFaltConfCnt_C = 100U;
const uint16 Gu16_ctPwrTubTempFaltRcvyCnt_C = 100U;
const uint16 Gu16_ctSplyVltgHiLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctSplyVltgHiLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctSplyVltgLoLvl1ConfCnt_C = 100U;
const uint16 Gu16_ctSplyVltgLoLvl1RcvyCnt_C = 100U;
const uint16 Gu16_ctSplyVltgLoLvl2ConfCnt_C = 100U;
const uint16 Gu16_ctSplyVltgLoLvl2RcvyCnt_C = 100U;
const dt_Temp_u8p0bn40 Gu8_tMotoTempHiLvl1ConfTrs_C = 180U;
const dt_Temp_u8p0bn40 Gu8_tMotoTempHiLvl1RcvyTrs_C = 178U;
const dt_Temp_u8p0bn40 Gu8_tMotoTempHiLvl2ConfTrs_C = 180U;
const dt_Temp_u8p0bn40 Gu8_tMotoTempHiLvl2RcvyTrs_C = 178U;
const dt_Temp_u8p0bn40 Gu8_tPCBTempHiLvl1ConfTrs_C = 180U;
const dt_Temp_u8p0bn40 Gu8_tPCBTempHiLvl1RcvyTrs_C = 175U;
const dt_Temp_u8p0bn40 Gu8_tPCBTempHiLvl2ConfTrs_C = 179U;
const dt_Temp_u8p0bn40 Gu8_tPCBTempHiLvl2RcvyTrs_C = 175U;
const dt_Temp_u8p0bn40 Gu8_tPwrTubTempHiLvl1ConfTrs_C = 180U;
const dt_Temp_u8p0bn40 Gu8_tPwrTubTempHiLvl1RcvyTrs_C = 178U;
const dt_Temp_u8p0bn40 Gu8_tPwrTubTempHiLvl2ConfTrs_C = 180U;
const dt_Temp_u8p0bn40 Gu8_tPwrTubTempHiLvl2RcvyTrs_C = 178U;
const dt_Temp_u8p0bn40 Gu8_tMaxNTCMCUTempDvt_C = 90U;
const dt_Standardize_u16p15b0 Gu16_uLimHmeSplyVltgConfTrs_C = 6656U;
const dt_Standardize_u16p15b0 Gu16_uLimHmeSplyVltgRcvyTrs_C = 6144U;
const dt_Temp_u8p0bn40 Gu8_tNTCTempSensOpnCir_C = 25U;
const dt_Temp_u8p0bn40 Gu8_tNTCTempSensNoOpnCir_C = 30U;
const uint16 Gu16_ctCrashFaltConfCnt_C = 5U;
const uint16 Gu16_ctCrashFaltRcvyCnt_C = 0U;
const uint16 Gu16_ctMosOpnCirFaltConfCnt_C = 5U;
const uint16 Gu16_ctMosOpnCirFaltRcvyCnt_C = 0U;
const dt_Temp_u8p0bn40 Gu8_tColdStrtPCBTempConfTrs_C = 50;
const uint8 Gu8_RollingMin_C = 0U;
const uint8 Gu8_RollingMax_C = 15U;



/*PhCurrGen*/
const sint16 Gs16_facStrtUpTqRiseRate_C = 20;
dt_Standardize_s16p15b0 Gs16_nMinSenlRefElecSpd_C = 1680;//1680;/* 210 */
dt_Standardize_s16p15b0 Gs16_nMinStrtUpElecSpd_C = 1256;/* 157.07963267948966 */
const dt_Standardize_s16p15b0 Gs16_nOpnLpConvActElecSpd_C = 2096;
const dt_Standardize_s16p15b0 Gs16_nShOffActElecSpd_C = 1048; //OK
const dt_Standardize_s16p15b0 Gs16_nStrtUpProcTolcElecSpd_C = 832;
const dt_Standardize_s16p15b0 Gs16_trqInitCondTq_C = 0;/* 0.1 */  //OK
dt_Standardize_s16p15b0 Gs16_trqMaxStrtUpTq_C = 2500;//6554;
dt_SpdCtrlIntgGain_u16p9b0 Gu16_facSpdCtlKi_C= 7000;//1000;//4096U;/* 0.00390625*/  //OK
dt_SpdCtrlPropGain_u16p12b0 Gu16_facSpdCtlKp_C= 16000;//600;//6144U;   //OK
const dt_RadAng_u16r15b0 Gu16_phiMinOpnLpClsLpAgDvt_C = 3129;//3129;
const dt_Standardize_s16p15b0 Gs16_trqMinStrtUpRefTq_C = 800;//655,1200
const sint16 Gs16_facStrtUpTrqDecRiseRate_C = 100;//256;
const sint16 Gs16_facStrtUpTrqDecFallRate_C = -100;//-256;

/*DcycGen*/
const ENM_PWM_MODE Genm_modePWMMode_C = S3APWM;  //OK
const dt_OmodFact_u16p15b0 Gu16_facOvrModulFac_C = 32768U; //OK

/*AST*/
ENM_AG_POS_EVAL_MODE Genm_modeAgEvallMode_C= SENSOR;
const sint16 Gs16_facAlgnTqFallRate_C = -1190; //OK
const sint16 Gs16_facAlgnTqRiseRate_C = 1190;  //OK
const dt_RefSpdSlewRate_s16p12b0 Gs16_facRefSpdFallSlwRate_C = -4000;//  OK -8192;/* -2.44 */
const dt_RefSpdSlewRate_s16p12b0 Gs16_facRefSpdOLFallSlwRate_C = -410;/* 2.44 */
const dt_RefSpdSlewRate_s16p12b0 Gs16_facRefSpdOLRiseSlwRate_C = 410;/* 2.44 */
const dt_RefSpdSlewRate_s16p12b0 Gs16_facRefSpdRisSlwRate_C = 8000;//12000;//   OK 8192;/* 2.44 */
const dt_Standardize_s16p15b0 Gs16_iPhCurrLim_CUR[6] = { 9344, 9344, 8064, 8064,
  7296, 1408 } ;

const dt_Temp_u8p0bn40 Gs16_iPhCurrLim_CUR_tPCBTemp_X[6] = { 0U, 49U, 50U, 150U,
  172U, 196U } ;

const dt_Standardize_s16p15b0 Gs16_iSplyCurrTempLim_CUR[6] = { 3277, 3277, 3277,
  3277, 3277, 3277 } ;

const dt_Temp_u8p0bn40 Gs16_iSplyCurrTempLim_CUR_tPCBTemp_X[6] = { 0U, 40U, 80U,
  120U, 145U, 160U } ;

const dt_Standardize_s16p15b0 Gs16_iSplyCurrVltgLim_CUR[7] = { 2304, 2304, 2176, 2048, 1792,
  1664, 1408 } ;

const dt_Standardize_u16p15b0 Gs16_iSplyCurrVltgLim_CUR_uSplyVltg_X[7] = { 4608U,
  5120U, 6144U, 6656U,7168U, 8192U, 9472U } ;

const dt_Standardize_s16p15b0 Gs16_nAlgnRefElecSpd_C = 50;/* 6.2831853071795862 */


dt_Standardize_s16p15b0 Gs16_nMaxStrtUpRefElecSpd_C = 1680;/* 210 */
const dt_Standardize_s16p15b0 Gs16_nMinRefMechSpd_C = 267; //OK


const dt_Standardize_s16p15b0 Gs16_nUDS2FRefMechSpd_C = 2500;
const dt_Standardize_s16p15b0 Gs16_trqRefTqAlgnVal_C = 10000;//2000;  //OK
const dt_Standardize_s16p15b0 Gs16_trqTqUpLim_C = 22118;//16384;   //OK
const dt_Standardize_s16p15b0 Gs16_trqTmpStallTqUpLim_C = 8847;//16384;   //OK
const uint16 Gu16_ctAlgnAlPhStCnt_C = 200U; //OK
const uint16 Gu16_ctAlgnBePhStCnt_C = 200U;  //OK
const uint16 Gu16_ctAlgnStEndCnt_C = 100U;
const uint16 Gu16_ctAlgnTmpFailStCnt_C = 200U;
const uint16 Gu16_ctAlgnWaitAlStCnt_C = 50U;  //OK
const uint16 Gu16_ctAlgnWaitBeStCnt_C = 50U;  //OK
const uint16 Gu16_ctSysStInitWaitCnt_C = 10U;
const uint16 Gu16_facDrtnVltgFltCoeff_C = 13107U;
const dt_RadAng_u16r15b0 Gu16_phiAlgnAlPhElecAg_C = 49152U;  //OK
const dt_RadAng_u16r15b0 Gu16_phiAlgnBePhElecAg_C = 0U;  //OK
const dt_RadAng_u16r15b0 Gu16_phiMinAlgnElecAngDvt_C = 3641U;  //OK
const dt_RadAng_u16r15b0 Gu16_phiTheoBePhElecAg_C = 16384U;
const dt_DutyCycl_u16p15b0 Gu16_rMaxVltgAmpRat_C = 28000;//32768U;
const dt_Standardize_s16p15b0 Gu16_etaCtlBrd_MAP_ampActPhCurrAmp_X[6] = {1280,2560,3840,5120,6400,7680};
const dt_Standardize_s16p15b0 Gu16_etaCtlBrd_MAP_nActElecSpd_Y[6] = {2094,4188,8377,12565,16754,18848};
const dt_Standardize_u16p15b0 Gu16_etaCtlBrd_MAP[6][6] ={{48000,49000,47000,44000,44000,44000},{38000,40000,40000,42000,42000,42000},{35129,35129,41129,37129,37129,41000},{36000,36000,37000,37000,38000,37000 },{35000,35000,36000,36000,37000,37000},{36000,36000,37000,37000,38000,38000}};  
const uint16 Gu16_facComSpdFltCoeff_C = 39322U;//13107U;
	

/*SigIn*/
const ENM_PH_CURR_SMP_MODE Genm_modePhCurrSmpMode_C = SNGSHT_GRO;   //OK
const dt_VltgRat_u16p22b0 Gu16_rCtlBrdVltgADCRat_C = 4194U;
const dt_VltgRat_u16p22b0 Gu16_rGDVltgADCRat_C = 4194U;
const dt_MotRstn_u16p20b0 Gu16_rPhCurrADCRat_C = 52428U;/* 0.0001953125 */  //OK
const dt_VltgRat_u16p22b0 Gu16_rSplyVltgADCRat_C = 4194U;
const uint16 Gu16_tMotoTemp_CUR_ADMotoTempADC_X[5] = { 0U, 500U, 1000U, 1500U,
  2000U } ;

const uint16 Gu16_tPCBTemp_CUR_ADPCBTempADC_X[38] = {1276,1379,1490,1608,1734,1867,2007,2154,2307,2465,2627,2792,2959,3125,3289,3449,3605,3755,3896,4029,4153,4266,4369,4462,4544,4617,4680,4735,4782,4822,4856,4884,4907,4926,4942,4954,4964,4972};

const uint16 Gu16_tPwrTubTemp_CUR_ADPwrTubTempADC_X[5] = { 0U, 500U, 1000U,
  1500U, 2000U } ;

const dt_Temp_u8p0bn40 Gu8_tMotoTemp_CUR[5] = { 0U, 40U, 80U, 120U, 160U } ;

const dt_Temp_u8p0bn40 Gu8_tPCBTemp_CUR[38] = {185,180,175,170,165,160,155,150,145,140,135,130,125,120,115,110,105,100,95,90,85,80,75,70,65,60,55,50,45,40,35,30,25,20,15,10,5,0};

const dt_Temp_u8p0bn40 Gu8_tPwrTubTemp_CUR[5] = { 40U, 60U, 80U, 120U, 160U } ;