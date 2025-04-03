#ifndef ADC_H
#define ADC_H
#include "../ASW_share/rtwtypes.h"
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

extern SRAM_GLOBAL_UINT16 Gu16_uADCVSD_IF;   /*ADC2 VSD voltage uint:mv */
extern SRAM_GLOBAL_UINT16 Gu16_uADC_NTCTemp_IF;         /*ADC1 CH2 voltage measurement*/

extern SRAM_GLOBAL_INT16   Gu8_tMcuTemp_IF;
extern SRAM_GLOBAL_UINT16  Gu16_uADC2VCP;        /*ADC2 VCP voltage measurement*/
extern SRAM_GLOBAL_UINT16  Gu16_uADCVDH_IF;      /*ADC1 CH3 VDH  voltage ,it used as battery and motor bus measurement*/


extern uint32 addr_ADC2_FILT_OUT0;
extern uint16 ADC2_GetChResult(uint8 channel);
extern uint16 ADC2_VSD_Result_mV(void);
extern void ADC_VSD_VDH_Routine(void);
extern sint16 ADC2_Temp_Result_C(uint16 value);
extern int ADC1_Get(uint16 curr);
extern int data_addr_ADC2_FILT_OUT0(int data);
extern int get_ADC1_mV(double voltage_mV);
extern int get_ADC2_mV(double voltage_mV);
extern int get_ADC2_Temp(sint16 temperature);


#endif