/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "ADC_Meas.h"
#include "wdt1.h"
#include "adc2.h"

/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
// SRAM_GLOBAL_UINT16                     Gu16_uMONVol;        /*ADC2 MON voltage uint:mv */
SRAM_GLOBAL_UINT16 Gu16_uADCVSD_IF;   /*ADC2 VSD voltage uint:mv */
SRAM_GLOBAL_UINT16 Gu16_uADC_NTCTemp_IF;         /*ADC1 CH2 voltage measurement*/

SRAM_GLOBAL_INT16   Gu8_tMcuTemp_IF;
SRAM_GLOBAL_UINT16  Gu16_uADC2VCP;        /*ADC2 VCP voltage measurement*/
SRAM_GLOBAL_UINT16  Gu16_uADCVDH_IF;      /*ADC1 CH3 VDH  voltage ,it used as battery and motor bus measurement*/

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
#define VSD_STABLE_VAL                6000u

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

// uint8 ADC_Get_ChResult(uint16 *u16p_uDigValueMv, uint8 u8_Channel)
// {
//     uint8 u8_RetState;
//     u8_RetState = (uint8)ADC1_GetChResult(u16p_uDigValueMv,u8_Channel);
//     return(u8_RetState);
// }

void ADC_VSD_VDH_Routine(void)
{
  Gu16_uADCVSD_IF = ADC2_VSD_Result_mV();
  Gu16_uADCVDH_IF = Gu16_uADCVSD_IF;
}

void ADC_TempOil_Routine(void)
{
  uint16 u16_ADC_ChResult_Tmp;
  if (ADC1_GetChResult(&u16_ADC_ChResult_Tmp, ADC1_TEMPOIL_NTC_CHAN) == true)
  {
    /* ADC1 Voltage(mV) = (10bit_value * VREF_5000(mV)) / MAX_10BIT_VALUE */
    Gu16_uADC_NTCTemp_IF = (uint16)((u16_ADC_ChResult_Tmp * (uint16)ADC1_VREF_5000MV) / ADC1_RESOLUTION);	
  }
  else
  {
    ;
  }
}

void ADC_VCP_Routine(void)
{
  Gu16_uADC2VCP=ADC2_VCP_Result_mV();    /* VCP :IIR 0.5 weight 0f current sample*/
}

// void ADC_MON_Routine(void)
// {
//   Gu16_uMONVol=ADC2_MON_Result_mV();
// }

void ADC_MCUTemp_Routine(void)
{
  sint16 s16_tMcuTemp_Tmp;
  s16_tMcuTemp_Tmp = ADC2_Temp_Result_C();
    if(s16_tMcuTemp_Tmp<(-40))
    {
        s16_tMcuTemp_Tmp=  -40;
    }
    Gu8_tMcuTemp_IF = (uint8)(s16_tMcuTemp_Tmp+40);
}

void ADC_BattStable_Protection(void)
{
	uint8 u8_BattStableCnt;
	uint16 u16_BattStableCnt;
	uint16 u16_uVSDResult;
  
	u8_BattStableCnt=0u;
	u16_BattStableCnt=0u;

	while((u8_BattStableCnt==0u)&&(u16_BattStableCnt<1000u))
	{
		u16_uVSDResult=ADC2_VSD_Result_mV();

		if(u16_uVSDResult < VSD_STABLE_VAL)
		{
			(void)WDT1_Service();/*check and service the WDT1*/
//			Delay_us(1000);
			u8_BattStableCnt=0;
		}
		else
		{
			u8_BattStableCnt=1;
		}
		
		u16_BattStableCnt++;
	}

	if(u16_BattStableCnt>=1000u)
	{
		while(1);
	}
	else
	{
		;
	}
}

// void  ADC1_ChannelADVoltage(uint8 ADC1_Channel_tmp)
// {
//   uint16 u16_ADC_ChResult_Tmp;
//   if (ADC1_GetChResult(&u16_ADC_ChResult_Tmp, ADC1_Channel_tmp) == true)
//   {
//     switch(ADC1_Channel_tmp)
//     {
//       case ADC1_TempBoradChannel_number:
//         ADC1_TempBoardAD_mp=u16_ADC_ChResult_Tmp;
//         /* ADC1 Voltage(mV) = (10bit_value * VREF_5000(mV)) / MAX_10BIT_VALUE */
//         ADC1_uTempBoardVolt_mp = (uint16)((ADC1_TempBoardAD_mp * (uint16)ADC1_VREF_5000MV) / (uint16)1023u);				 
// 	  break;
		 
			 
// 	  case ADC1_TEMPOIL_NTC_CHAN:
//         ADC1_TempOilAD_mp=u16_ADC_ChResult_Tmp;
//         /* ADC1 Voltage(mV) = (10bit_value * VREF_5000(mV)) / MAX_10BIT_VALUE */
//         ADC1_uTempOilVolt_mp = (uint16)((ADC1_TempOilAD_mp * (uint16)ADC1_VREF_5000MV) / (uint16)1023);		 
//         Gu16_uADC_NTCTemp_IF=ADC1_uTempOilVolt_mp;
//       break;
// 		  default:
// 		  break;
// 		}	
//    }
//    else
//    {
//     ;
//    }
// }