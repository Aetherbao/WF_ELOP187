/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "PWM_Clac.h"
#include "ADC_Meas.h"
#include "BDRV_BDRV.h"
/*******************************************************************************
**                          Private Type Declarations                         **
*******************************************************************************/


/** Enumeration for space vector sectors (see #PWM_EvaluateSector) */
typedef enum
{
  PWM_CALC_SECTOR_0 = 0, /**< Virtual sector placed in the origin, all dc off */
  PWM_CALC_SECTOR_1,     /**< 0-60 degree sector */
  PWM_CALC_SECTOR_2,     /**< 61-120 degree sector */
  PWM_CALC_SECTOR_3,     /**< 121-180 degree sector */
  PWM_CALC_SECTOR_4,     /**< 181-240 degree sector */
  PWM_CALC_SECTOR_5,     /**< 241-300 degree sector */
  PWM_CALC_SECTOR_6,     /**< 301-360 degree sector */
  PWM_CALC_SECTOR_7,     /**< Virtual sector placed in the origin, all dc on */
  PWM_CALC_NUM_SECT      /**< Number of sectors, also used as invalid sector */
} ENM_PWM_SECTOR;

/** Information about the active sector */
typedef struct
{
  ENM_PWM_SECTOR enmPWM_ActiveSector; /**< Sector occupied by the voltage vector */
  ENM_PWM_PHASES enmPWM_Dc_Min_Ph;     /**< Phase with the minimum duty cycle */
  ENM_PWM_PHASES enmPWM_Dc_Med_Ph;     /**< Phase with the medium duty cycle */
  ENM_PWM_PHASES enmPWM_Dc_Max_Ph;     /**< Phase with the maximum duty cycle */
} ST_PWM_SECTORINFO;
/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
/** Duty cycles size in bits. 100% DC = 2^15 */
#define PWM_CALC_DC_SIZE                        (15u)

/** \brief Minimum duty cycle value in ticks allowed for single shunt 
 *         measurement 
 * \todo   Tune the min duty cycle value (now it's 4us) */
#define PWM_CALC_MIN_DUTY_VAL_TICKS             (100u)

/** \brief Delay between PWM edge and ADC measurement trigger in ticks(2us)*/
#define PWM_SSM_MEASURE_DELAY_TICKS             (80U)

/** \brief Start the timer T13 */
#define PWM_START_SSMTIMER()                    (CCU6_T13_Start())

/** \brief Get first current measurement from ADC1 Ch0 (triggered by T13CM) */
#define PWM_SSM_FST_CURR                         Gu16_ADC_FstCSASample_IF          
//(ADC1_getCh0Result())

/** \brief Get second current measurement from ADC1 Ch1 (triggered by T13PM) */
#define PWM_SSM_SCND_CURR                        Gu16_ADC_ScndCSASample_IF  

/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
SRAM_GLOBAL_UINT16 Gu16_uPWM_CsaCalibResult_IF;
SRAM_GLOBAL_UINT8 Gu8_PWMSectorRaw;/* PWM sector raw value*/
SRAM_GLOBAL_UINT16 Gu16_uPWM_PhFstCurr_IF; //phase current monitor first point
SRAM_GLOBAL_UINT16 Gu16_uPWM_PhScndCurr_IF;//phase current monitor second point
/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/
/** \brief Array containing the compare values for the 3-phase PWM generation
 *         [U-phase DC, V-phase DC, W-phase DC] on rising edge
 */
static uint16 Su16_PwmCompValRise[PWM_CALC_NUM_OF_PHASES] = {0u};

/** \brief Array containing the compare values for the 3-phase PWM generation
 *         [U-phase DC, V-phase DC, W-phase DC] on falling edge
 */
static uint16 Su16_PwmCompValFall[PWM_CALC_NUM_OF_PHASES] = {0u};

/** \brief Struct containing information regarding the current hexagon sector */
 static ST_PWM_SECTORINFO SstPWM_SectorInfo = {0};

/** \brief    Array used as look-up table to evaluate in a fastPWM_Set_ClacPwmValser 
 *            mode the current voltage sector keeping track of the phase holding 
 *            the maximum, medium and minimum duty cycles
 *  \details  The table is customized on #PWM_EvaluateSector and its inner 
 *            condition "a", "b" and "c", defined as follows:
 *            - a: True if duty on phase U is greater than duty on phase V
 *            - b: True if duty on phase V is greater than duty on phase W
 *            - c: True if duty on phase W is greater than duty on phase U
 * 
 *            Combining the results of the previous three conditions, the 
 *            current sector can be evaluated with the formula: \n
 *            (a << 2 | c << 1 | b)
 * 
 *            Example: \n 
 *            Voltage vector is in Sector_1: a = TRUE, b = TRUE, c = FALSE
 * 
 *            SCstPWM_SectorInfo_EvalTab[(a << 2 | c << 1 | b)] = PWM_CALC_SECTOR_1.
 * 
 *            #PWM_CALC_NUM_SECT means the condition is not valid
 * \todo      Check the condition in which duty cycles are equal
 */
static const ST_PWM_SECTORINFO SCstPWM_SectorInfo_EvalTab [PWM_CALC_NUM_SECT] = 
{
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_0,
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_U,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_V,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_W
  },
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_2,
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_W,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_U,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_V
  },
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_4,
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_U,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_V,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_W
  },
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_3,
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_U,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_W,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_V
  },
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_6,
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_V,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_W,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_U
  },
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_1,
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_W,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_V,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_U
  },
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_5,
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_V,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_U,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_W
  },
  { .enmPWM_ActiveSector = PWM_CALC_SECTOR_7, // Never selectable 
    .enmPWM_Dc_Min_Ph = PWM_CALC_PHASE_U,
    .enmPWM_Dc_Med_Ph = PWM_CALC_PHASE_V,
    .enmPWM_Dc_Max_Ph = PWM_CALC_PHASE_W
  },
};

// SRAM_GLOBAL_UINT8 BSW_stMotorRun_mp;      /*Motor run status 1:run  0:stop */
// SRAM_GLOBAL_UINT8 APP_stMotorRun_mp;      /*Motor run status 1:run  0:stop */
/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

 /**************************************************************************//**
 * \fn      PWM_EvaluateSector(const uint16 Cu16_Duty[PWM_CALC_NUM_OF_PHASES])
 * \details  The function compares the value of the duty cycles read as input 
 *           and establishes the hexagon sector according to their values.  
 *           Taking a Cartesian coordinate system as reference, sector 1 is 
 *           defined by the first 60°, moving in counter-clockwise rotation  
 *           starting from the positive x axis
 * \image    html Hexagon.png 
 * \param[in] Cu16_Duty Duty Cycles provided by Control algorithm
 * \see   SstPWM_SectorInfo Current sector occupied by the voltage vector,
 *           with info on the phase piloted with the maximum, medium and minimum
 *           duty cycle, according to #SCstPWM_SectorInfo_EvalTab
 * ****************************************************************************/
static inline void PWM_EvaluateSector(const uint16 
                                                Cu16_Duty[PWM_CALC_NUM_OF_PHASES]);
                                                
 /**************************************************************************//**
 * \fn      PWM_Set_ShiftCompVals(const ST_PWM_SECTORINFO* CstPWM_CurrSectorInfo, 
 *                             const uint16 Cu16_OrCompVals[PWM_CALC_NUM_OF_PHASES],
 *                             const uint16 Cu16_Period,
 *                             uint16 u16p_CompValRise[PWM_CALC_NUM_OF_PHASES], 
 *                             uint16 u16p_CompValFall[PWM_CALC_NUM_OF_PHASES]);
 * \details  The function compares the minimum and maximum duty cycles with the 
 *           medium one. If their difference is lower than the minimum time 
 *           defined in timer ticks by #PWM_CALC_MIN_DUTY_VAL_TICKS, to 
 *           allow the single shunt measurement, it shifts the maximum duty to 
 *           the left, while the minimum to the right, modifying the compare 
 *           values for the rising and falling edges. In case of the duty cycles
 *           are too small (hexagon star area), the function put the maximum and 
 *           the minimum duty compare values respectively to 
 *           2*##PWM_CALC_MIN_DUTY_VAL_TICKS and #PWM_CALC_MIN_DUTY_VAL_TICKS.
 *           In case of null amplitude of the voltage phasor, the original 
 *           compare values are redirected in output, without any computation
 * \param[in] CstPWM_CurrSectorInfo Current sector occupied by the voltage vector, with  
 *           info on the phase piloted with the maximum, medium and minimum duty
 *           cycle, according to #SCstPWM_SectorInfo_EvalTab
 * \param[in] Cu16_OrCompVals Original compare values
 * \param[in] Cu16_Period PWM period
 * \param[out] u16p_CompValRise Compensated (if needed) compare values for the PWM 
 *             rising edge 
 * \param[out] u16p_CompValFall Compensated (if needed) compare values for the PWM 
 *             falling edge
 * ##\image    html Diagrams/PWM_Set_ShiftCompVals.png 
 * \todo     - Check the possibility of shifting values will result of a period 
 *             over/underflow
 *           - The function shall work with all modulations. Verify this 
 *             requirement
 * ****************************************************************************/
static inline void PWM_Set_ShiftCompVals(
                               const uint16 Cu16_OrCompVals[PWM_CALC_NUM_OF_PHASES],
                               const uint16 Cu16_Period);
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
/**
 * \fn       PWM_CalcStart
 * \brief    Initialization of the MotPwm module
 */
void PWM_CalcStart(void)
{
  // Configure the bridge driver
  // BDRV_ConfigBridgePWM();

  // Start timer for PWM generation
  PWM_LaunchPWM();

  // Clear the Bridge status
  BDRV_Clr_OC_STS();
  // Gu8_PWM_MotorRunStatus=1;
}

/**
 * \fn     PWM_Set_ClacPwmVals(const uint16 Cu16_Duty[PWM_CALC_NUM_OF_PHASES], const uint16 Cu16_Period)
 * \brief  Calculate the compare values for the PWM generation based on the 
 *         period and duty cycles provided
 */
void PWM_Set_ClacPwmVals(const uint16 Cu16_Duty[PWM_CALC_NUM_OF_PHASES], const uint16 Cu16_Period)
{
  // Array to convert duty cycles in compare values for the timer
  uint16 u16_OrigCompVals[PWM_CALC_NUM_OF_PHASES] = {0u};

  // Evaluate the sector and phase with min, med and max duty
  PWM_EvaluateSector(&Cu16_Duty[0]);

   /* Compare value is the timer value at which the PWM signal shall commute
      Low compare value means high % duty cycle */
  u16_OrigCompVals[PWM_CALC_PHASE_U] = ( Cu16_Period - (uint16)( 
    (((uint32)Cu16_Duty[PWM_CALC_PHASE_U]) * Cu16_Period) >> PWM_CALC_DC_SIZE ) );

  u16_OrigCompVals[PWM_CALC_PHASE_V] = ( Cu16_Period - (uint16)( 
    (((uint32)Cu16_Duty[PWM_CALC_PHASE_V]) * Cu16_Period) >> PWM_CALC_DC_SIZE ) );
    
  u16_OrigCompVals[PWM_CALC_PHASE_W] = ( Cu16_Period - (uint16)( 
    (((uint32)Cu16_Duty[PWM_CALC_PHASE_W]) * Cu16_Period) >> PWM_CALC_DC_SIZE ) );
  
  // Apply shift compensation if needed
  PWM_Set_ShiftCompVals(&u16_OrigCompVals[0], Cu16_Period);
  
  // Write PWM Shadow registers

}


// void PWM_MotorStateChange_Handle(void)//100ms but this function wont be run 
// {
// 	if((APP_stMotorRun_mp==0)&&(BSW_stMotorRun_mp==1))//for BSW, from run to stop
// 	{
// 	  BSW_stMotorRun_mp=0u;
// 		PWM_3PhStop();
// 	}
// 	else if((APP_stMotorRun_mp==1)&&(BSW_stMotorRun_mp==0))//for BSW, from stop to run
// 	{
// 	  BSW_stMotorRun_mp=1u;
// 		PWM_3PhStart();
// 	}
//   else
//   {
//       ;
//   }
// }

/**
 * \brief    Set the compare values for the PWM generation
 * \todo     Shall set the period as well for spread spectrum support
 */
void PWM_Set_CompareRiseValues(void)
{
  PWM_Set_T12ChannelVal(Su16_PwmCompValRise[PWM_CALC_PHASE_U],
                        Su16_PwmCompValRise[PWM_CALC_PHASE_V],
                        Su16_PwmCompValRise[PWM_CALC_PHASE_W]);
}

/**
 * \brief    Set the compare values for the PWM generation
 * \todo     Shall set the period as well for spread spectrum support
 */

void PWM_Set_CompareFallValues(void)
{
    PWM_Set_T12ChannelVal(Su16_PwmCompValFall[PWM_CALC_PHASE_U],
                          Su16_PwmCompValFall[PWM_CALC_PHASE_V],
                          Su16_PwmCompValFall[PWM_CALC_PHASE_W]);
}

void PWM_SSM_Init(void)
{  
  uint16 u16_ADCOffSet;
  #if 1
    u16_ADCOffSet = CSA_Offset_Get();//金帅只是没注意到这个 可以试试看
    u16_ADCOffSet >>= 2u;//12-bit value, with left aligned 10-bit result
  #endif

  #if 0
  uint16 u16_CSAAD_Tmp;
	u16_CSAAD_Tmp=0u;
	ADC1_Software_Mode_Sel();  /* enables ADC1 and switches to Software Mode*/
  ADC1_SW_Ch_Sel( ADC1_CSA); /*select ADC1_CSA channel*/
  ADC1_SOC_Set();            /*starts an ADC1 conversion*/

  while ( ADC1_EOC_Sts() != 1u )	/*wait conversion finish*/
  {
    ;
  }

  if (ADC1_GetChResult(&u16_CSAAD_Tmp, ADC1_CSA) == true)
  {
    u16_ADCOffSet=u16_CSAAD_Tmp;
  }
  else
  {
    ADC1_SOC_Set();            /*starts an ADC1 conversion*/
    while ( ADC1_EOC_Sts() != 1u )	/*wait conversion finish*/
    {
      ;
    }

    if (ADC1_GetChResult(&u16_CSAAD_Tmp, ADC1_CSA) == true)
    {
      u16_ADCOffSet=u16_CSAAD_Tmp;
    }
    else
    {
			while(1)
      {
        ;
      }
		}
	}
  
  ADC1_Sequencer_Mode_Sel();   /*ADC1 selects the Sequencer Mode*/
  #endif
  
	Gu16_uPWM_CsaCalibResult_IF=u16_ADCOffSet*ADC1_VREF_5000MV/ADC1_RESOLUTION;
  /* Start T13 timer */
  PWM_START_SSMTIMER();
  CCU6_StartTmr_T12();/*Start CCU6 Timer T12*/
}

/**
 * \fn       PWM_Set_SampleTimer
 * \brief    Set the timer values for the two current measurement.
 */
void PWM_Set_SampleTimer(void)
{
  uint16 u16_FstMeasCompVal;
  uint16 u16_ScndMeasCompVal;
	uint16 u16_ConfigVal_Tmp;

  /* Timing for current measurement is based on the rising edge of the maximum 
     and medium duty cycles */
  u16_FstMeasCompVal = Su16_PwmCompValRise[SstPWM_SectorInfo.enmPWM_Dc_Max_Ph];
  u16_ScndMeasCompVal = Su16_PwmCompValRise[SstPWM_SectorInfo.enmPWM_Dc_Med_Ph];

	if(PWM_OM_FST == Gu8_PWM_GenerateWaveStatus)
	{
		u16_ConfigVal_Tmp=u16_FstMeasCompVal + (uint16)PWM_SSM_MEASURE_DELAY_TICKS;
    PWM_Set_T13PeriodVal(u16_ConfigVal_Tmp);

	}else if(PWM_OM_SCND == Gu8_PWM_GenerateWaveStatus)
  {
		u16_ConfigVal_Tmp=u16_ScndMeasCompVal + (uint16)PWM_SSM_MEASURE_DELAY_TICKS;
    PWM_Set_T13PeriodVal(u16_ConfigVal_Tmp);
	}
  else
  {
    ;
  }
}

/**
 * \fn     PWM_SSM_ReconstructCurr(void)
 * \brief  Reconstruct the phase currents and store them in the global vector
 *         #Ssmm_phCurrVec
 */
void PWM_SSM_ReconstructCurr(void)
{
  // Get conversion results
  Gu16_uPWM_PhFstCurr_IF =  (( (uint32)(PWM_SSM_FST_CURR)  * ADC1_VREF_5000MV ) / ADC1_RESOLUTION ) ;
  Gu16_uPWM_PhScndCurr_IF =  (( (uint32)(PWM_SSM_SCND_CURR)  * ADC1_VREF_5000MV ) / ADC1_RESOLUTION) ;
}

/*******************************************************************************
**                         Private Function Definitions                        **
*******************************************************************************/

/**
 *    Evaluate in which hexagon sector is currently placed the voltage
 *          vector
 */
static inline void PWM_EvaluateSector( const uint16 Cu16_Duty[PWM_CALC_NUM_OF_PHASES] )
{
  /* Condition used for evaluating the sector */
  uint8 u8_FstPhInfo = (Cu16_Duty[PWM_CALC_PHASE_U] > Cu16_Duty[PWM_CALC_PHASE_V]);
  uint8 u8_ScndPhInfo = (Cu16_Duty[PWM_CALC_PHASE_V] > Cu16_Duty[PWM_CALC_PHASE_W]);
  uint8 u8_ThrdPhInfo = (Cu16_Duty[PWM_CALC_PHASE_W] > Cu16_Duty[PWM_CALC_PHASE_U]);

  SstPWM_SectorInfo = SCstPWM_SectorInfo_EvalTab[((u8_FstPhInfo << 2) | (u8_ThrdPhInfo << 1) | u8_ScndPhInfo)];
	Gu8_PWMSectorRaw=(uint8)(SstPWM_SectorInfo.enmPWM_ActiveSector);
}

/**
 * \brief   Apply the PWM shift to allow single shunt measurement in all the 
 *          conditions
 */

static inline void PWM_Set_ShiftCompVals(
                               const uint16 Cu16_OrCompVals[PWM_CALC_NUM_OF_PHASES],
                               const uint16 Cu16_Period)
{
  // Delta between compare values for maximum and medium duty cycle
  uint16 u16_MaxMedDelta = 0u;
  // Delta between compare values for medium and minimum duty cycle
  uint16 u16_MinMedDelta = 0u;
  // Minimum compare value for the current measurement
  const uint16 Cu16_CompValLimit = (Cu16_Period - PWM_CALC_MIN_DUTY_VAL_TICKS);
  // Compensated compare values
  uint16 u16_CompensCompVal[PWM_CALC_NUM_OF_PHASES] = {0u};
  // Information about the current sector
  const ST_PWM_SECTORINFO CstPWM_CurrSectorInfo = SstPWM_SectorInfo;
  // Compare values for duty rising edge
  uint16 *u16p_CompValRise = &Su16_PwmCompValRise[0];
  // Compare values for duty falling edge
  uint16 *u16p_CompValFall = &Su16_PwmCompValFall[0];
  
  // Check if we are applying a voltage phasor != 0
  if ( (CstPWM_CurrSectorInfo.enmPWM_ActiveSector > PWM_CALC_SECTOR_0) && 
                                    (CstPWM_CurrSectorInfo.enmPWM_ActiveSector < PWM_CALC_SECTOR_7) )
  {
    // Check if we are in the hexagon Star Area
    if(Cu16_OrCompVals[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] > Cu16_CompValLimit)
    {
      u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] = ( Cu16_Period - 
                                              (2 * PWM_CALC_MIN_DUTY_VAL_TICKS) );
      u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph] = Cu16_CompValLimit;
    }
    else if (Cu16_OrCompVals[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph] > Cu16_CompValLimit)
    {
      // Only the medium DC is too small
      u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] = Cu16_OrCompVals[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph];
      u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph] = Cu16_CompValLimit;
    }
    else
    {
      // We are outside star area, no limitation
      u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] = Cu16_OrCompVals[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph];
      u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph] = Cu16_OrCompVals[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph];
    }
  
    // Smaller DC is never limited
    u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph] = Cu16_OrCompVals[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph];
      
    // Evaluate the distance between PWM edges on the 3 phases
    u16_MaxMedDelta = (u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph] - 
                                    u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph]);
    u16_MinMedDelta = (u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph] - 
                                    u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph]);
    
    // Write the medium compare value, never shifted
    u16p_CompValRise[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph] = u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph];
    u16p_CompValFall[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph] = u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Med_Ph];
  
    // Maximum 
    if (u16_MaxMedDelta < PWM_CALC_MIN_DUTY_VAL_TICKS)
    {
      // Reduce the compare value for rising edge --> Left shift PWM edge
      u16p_CompValRise[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] = (u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph]
                                 - (PWM_CALC_MIN_DUTY_VAL_TICKS - u16_MaxMedDelta));
      // Increase the compare value for falling edge --> Left shift PWM edge
      u16p_CompValFall[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] = (u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] 
                                 + (PWM_CALC_MIN_DUTY_VAL_TICKS - u16_MaxMedDelta));
    }
    else
    {
      // Keep the original values
      u16p_CompValRise[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] = u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph];
      u16p_CompValFall[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph] = u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Max_Ph];
    }
  
    // Minimum 
    if (u16_MinMedDelta < PWM_CALC_MIN_DUTY_VAL_TICKS)
    {
      // Increase the compare value for rise edge --> Right shift PWM edge
      u16p_CompValRise[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph] = (u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph]
                                 + (PWM_CALC_MIN_DUTY_VAL_TICKS - u16_MinMedDelta));
      // Reduce the compare value for falling edge --> Right shift PWM edge
      u16p_CompValFall[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph] = (u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph]
                                 - (PWM_CALC_MIN_DUTY_VAL_TICKS - u16_MinMedDelta));
    }
    else
    {
      // Keep the original values
      u16p_CompValRise[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph] = u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph];
      u16p_CompValFall[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph] = u16_CompensCompVal[CstPWM_CurrSectorInfo.enmPWM_Dc_Min_Ph];
    }
  } 
  else // Otherwise forward the original values
  {
    u16p_CompValRise[PWM_CALC_PHASE_U] = Cu16_OrCompVals[PWM_CALC_PHASE_U];
    u16p_CompValRise[PWM_CALC_PHASE_V] = Cu16_OrCompVals[PWM_CALC_PHASE_V];
    u16p_CompValRise[PWM_CALC_PHASE_W] = Cu16_OrCompVals[PWM_CALC_PHASE_W];
    u16p_CompValFall[PWM_CALC_PHASE_U] = Cu16_OrCompVals[PWM_CALC_PHASE_U];
    u16p_CompValFall[PWM_CALC_PHASE_V] = Cu16_OrCompVals[PWM_CALC_PHASE_V];
    u16p_CompValFall[PWM_CALC_PHASE_W] = Cu16_OrCompVals[PWM_CALC_PHASE_W];
  }
}
