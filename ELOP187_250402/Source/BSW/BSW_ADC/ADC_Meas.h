#ifndef ADC_MEAS_H
#define ADC_MEAS_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Mem_Mem.h"
#include "adc1.h"
/*******************************************************************************
**                         Global Macro Declarations                         **
*******************************************************************************/
// /*ADC1 channel 2 is used to collect board temperature voltage and AD*/
// #define ADC1_TempBoradChannel_number  1
// /*ADC1 channel 4 is used to battery voltage and AD*/
#define ADC1_TEMPOIL_NTC_CHAN         (2u)
#define ADC1_VREF_5000MV              (5000u)//ADC1_VREF_5000mV
#define ADC1_RESOLUTION               (1023u)//10 bit


/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
// SRAM_GLOBAL_UINT16                     Gu16_uMONVol;        /*ADC2 MON voltage uint:mv */
extern SRAM_GLOBAL_UINT16 Gu16_uADCVSD_IF;   /*ADC2 VSD voltage uint:mv */
extern SRAM_GLOBAL_UINT16 Gu16_uADC_NTCTemp_IF;         /*ADC1 CH2 voltage measurement*/

extern SRAM_GLOBAL_INT16   Gu8_tMcuTemp_IF;
extern SRAM_GLOBAL_UINT16  Gu16_uADC2VCP;        /*ADC2 VCP voltage measurement*/
extern SRAM_GLOBAL_UINT16  Gu16_uADCVDH_IF;      /*ADC1 CH3 VDH  voltage ,it used as battery and motor bus measurement*/

/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void ADC1_ChannelADVoltage(uint8 ADC1_Channel_tmp);
void ADC_VCP_Routine(void);
// void ADC_MON_Routine(void);
void ADC_MCUTemp_Routine(void);
void ADC_BattStable_Protection(void);
void ADC_TempOil_Routine(void);
// uint8 ADC_Get_ChResult(uint16 *u16p_DigValueMv, uint8 u8_Channel);
void ADC_VSD_VDH_Routine();
#endif
