#include "../ASW_share/rtwtypes.h"
#include <stdio.h>
#define  SRAM_GLOBAL              
#define  SRAM_GLOBAL_UINT8         uint8
// #define  SRAM_GLOBAL_INT8          sint8
#define  SRAM_GLOBAL_UINT16        uint16
#define  SRAM_GLOBAL_INT16         sint16

/**\brief ADC2 channel selection macro, channel 0 - VBAT */
#define ADC2_VBAT       (0)
/**\brief ADC2 channel selection macro, channel 1 - VS */
#define ADC2_VS         (1)
/**\brief ADC2 channel selection macro, channel 2 - VSD */
#define ADC2_VSD        (2)
/**\brief ADC2 channel selection macro, channel 3 - VCP */
#define ADC2_VCP        (3)
/**\brief ADC2 channel selection macro, channel 4 - MON */
#define ADC2_MON        (4)
/**\brief ADC2 channel selection macro, channel 5 - VDDP */
#define ADC2_VDDP       (5)
/**\brief ADC2 channel selection macro, channel 6 - VAREF */
#define ADC2_VAREF      (6)
/**\brief ADC2 channel selection macro, channel 7 - VBG */
#define ADC2_VBG        (7)
/**\brief ADC2 channel selection macro, channel 8 - VDDC */
#define ADC2_VDDC       (8)
/**\brief ADC2 channel selection macro, channel 9 - TEMP */
#define ADC2_TEMP       (9)
/**\brief ADC2 \f$ V_{BG}\f$ in Volts */
#define ADC2_VREF (1.211F)
/**\brief ADC2 \f$ V_{BG}\f$ (1.211 V) in millivolts */
#define ADC2_VREF_mV (1211)
/**\brief ADC2 Filtered output register maximum value */
#define ADC2_FILTOUT_MAX (1023u)

#define VSD_ATTEN_CONV_NOMIN    (1000u)
#define VSD_ATTEN_CONV_DENOM    (39u)

#define ADC1_TEMPOIL_NTC_CHAN         (2u)
#define ADC1_VREF_5000MV              (5000u)//ADC1_VREF_5000mV
#define ADC1_RESOLUTION               (1023u)//10 bit

#define VDDC_ATTEN_CONV_NOMIN   (4u)
#define VDDC_ATTEN_CONV_DENOM   (3u)

/**\brief Offset of V_Temp (mV) corresponding to 0 &deg;C reference */
#define V_TEMP_REF_OFFSET_mV    (666u)

/**\brief Scaling factor for V_Temp (mV) */
#define V_TEMP_SCALE_FACT   (100u)

/**\brief Conversion coefficient from V_Temp (mV) to Temperature (&deg;C)
   multiplied by V_TEMP_SCALE_FACT */
#define CONV_COEFF_mV_TO_degC    (231u)

SRAM_GLOBAL_UINT16 Gu16_uADCVSD_IF;   /*ADC2 VSD voltage uint:mv */
SRAM_GLOBAL_UINT16 Gu16_uADC_NTCTemp_IF;         /*ADC1 CH2 voltage measurement*/

SRAM_GLOBAL_INT16   Gu8_tMcuTemp_IF;
SRAM_GLOBAL_UINT16  Gu16_uADC2VCP;        /*ADC2 VCP voltage measurement*/
SRAM_GLOBAL_UINT16  Gu16_uADCVDH_IF;      /*ADC1 CH3 VDH  voltage ,it used as battery and motor bus measurement*/


uint32 addr_ADC2_FILT_OUT0;

uint16 ADC2_GetChResult(uint8 channel)
{
  uint32 pBaseAddr;
  uint16 Var;
  uint32 addr;
  uint16 idx;

  if ((uint8)9 >= channel)
  {
    /* violation: intended cast from pointer to unsigned int [MISRA Rule 45]*/
    addr = addr_ADC2_FILT_OUT0;
    /* calculate address offset corresponding to the input channel number */
    idx = (uint16)((uint16)channel << 2u);
    addr += idx;
    /* violation: intended cast from unsigned int to pointer [MISRA Rule 45]*/
    pBaseAddr = addr;
    /* read the 10 LSbit of the ADC FILT_OUTx register */
    Var = (uint16)((pBaseAddr) & (uint32)0x000003FF);
  }
  else
  {
    Var = 0;
  }

  return (Var);
} /* End of ADC2_GetChResult */

uint16 ADC2_VSD_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_VSD);
  /* Conversion for VSD attenuator (attenuator 0.039 = 39/1000) */
  value = (uint16)(((value * (uint32)((uint16)ADC2_VREF_mV * (uint16)VSD_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VSD_ATTEN_CONV_DENOM);
  return (value);
}

void ADC_VSD_VDH_Routine(void)
{
  Gu16_uADCVSD_IF = ADC2_VSD_Result_mV();
  Gu16_uADCVDH_IF = Gu16_uADCVSD_IF;
}

sint16 ADC2_Temp_Result_C(uint16 value)
{
  uint16 V_Temp_mV;
  sint16 Temperature;
  /* Conversion for Temperature in deg C:
  Step 1: Calculate V_Temp(T)(mV): */
  V_Temp_mV = (uint16)(((uint32)value * (uint32)ADC2_VREF_mV) / (uint16)1023);
  /* Step 2: Conversion from V_Temp(T)(mV) to Temperature in deg C  */
  Temperature = (sint16)((((sint16)V_Temp_mV - (sint16)V_TEMP_REF_OFFSET_mV) * (sint16)V_TEMP_SCALE_FACT) / (sint16)CONV_COEFF_mV_TO_degC);
  /* return the calculated Temperature in deg C */
  return (Temperature);
}

int ADC1_Get(uint16 curr)
{
  return((( (uint32)(curr)  * ADC1_VREF_5000MV ) / ADC1_RESOLUTION ) );
}

int data_addr_ADC2_FILT_OUT0(int data)
{
    addr_ADC2_FILT_OUT0=data;
    ADC_VSD_VDH_Routine();
    //printf("Gu16_uADCVDH_IF=%d\n",Gu16_uADCVDH_IF);
    return (Gu16_uADCVDH_IF);
}

int get_ADC1_mV(double voltage_mV)
{ 
  uint16 adc_value = (voltage_mV * ADC1_RESOLUTION) / ADC1_VREF_5000MV;

    // 确保结果在10位ADC的范围内（0到1023）
    if (adc_value > ADC1_RESOLUTION) {
        adc_value = ADC1_RESOLUTION;
    }
    return (uint16)adc_value;
}

int get_ADC2_mV(double voltage_mV)
{
  uint16 adc_value = (voltage_mV * ADC2_FILTOUT_MAX * VSD_ATTEN_CONV_DENOM) /
                         (ADC2_VREF_mV * VSD_ATTEN_CONV_NOMIN);

    // 确保结果在ADC的范围内（0到1023）
    if (adc_value > ADC2_FILTOUT_MAX) {
        adc_value = ADC2_FILTOUT_MAX;
    }
    return (uint16)adc_value;
}

int get_ADC2_Temp(sint16 temperature)
{
  uint16 V_Temp_mV =
      ((sint32)temperature * CONV_COEFF_mV_TO_degC) / V_TEMP_SCALE_FACT +
      V_TEMP_REF_OFFSET_mV;
  uint16 adc_value = (uint16)((V_Temp_mV * 1023) / ADC2_VREF_mV);

  // 确保结果在10位ADC的范围内（0到1023）
  if (adc_value > 1023) {
    adc_value = 1023;
  }

  return adc_value;
}