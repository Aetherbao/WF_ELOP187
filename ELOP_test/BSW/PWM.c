#include "../ASW_share/rtwtypes.h"
#include <stdio.h>

typedef enum
{
  PWM_CALC_PHASE_U = 0,     /**< Phase U is placed at 0 deg */
  PWM_CALC_PHASE_V,         /**< Phase V is placed at 120 deg */
  PWM_CALC_PHASE_W,         /**< Phase W is placed at 240 deg */
  PWM_CALC_NUM_OF_PHASES
} ENM_PWM_PHASES;
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
typedef struct
{
  ENM_PWM_SECTOR enmPWM_ActiveSector; /**< Sector occupied by the voltage vector */
  ENM_PWM_PHASES enmPWM_Dc_Min_Ph;     /**< Phase with the minimum duty cycle */
  ENM_PWM_PHASES enmPWM_Dc_Med_Ph;     /**< Phase with the medium duty cycle */
  ENM_PWM_PHASES enmPWM_Dc_Max_Ph;     /**< Phase with the maximum duty cycle */
} ST_PWM_SECTORINFO;
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

#define PWM_CALC_MIN_DUTY_VAL_TICKS             (100u)
#define PWM_CALC_DC_SIZE                        (15u)

static ST_PWM_SECTORINFO SstPWM_SectorInfo = {0};
static uint16 Su16_PwmCompValRise[PWM_CALC_NUM_OF_PHASES] = {0u};
static uint16 Su16_PwmCompValFall[PWM_CALC_NUM_OF_PHASES] = {0u};
uint8 Gu8_PWMSectorRaw;
void PWM_EvaluateSector( const uint16 Cu16_Duty[PWM_CALC_NUM_OF_PHASES] )
{
  /* Condition used for evaluating the sector */
  uint8 u8_FstPhInfo = (Cu16_Duty[PWM_CALC_PHASE_U] > Cu16_Duty[PWM_CALC_PHASE_V]);
  uint8 u8_ScndPhInfo = (Cu16_Duty[PWM_CALC_PHASE_V] > Cu16_Duty[PWM_CALC_PHASE_W]);
  uint8 u8_ThrdPhInfo = (Cu16_Duty[PWM_CALC_PHASE_W] > Cu16_Duty[PWM_CALC_PHASE_U]);

  SstPWM_SectorInfo = SCstPWM_SectorInfo_EvalTab[((u8_FstPhInfo << 2) | (u8_ThrdPhInfo << 1) | u8_ScndPhInfo)];
	Gu8_PWMSectorRaw=(uint8)(SstPWM_SectorInfo.enmPWM_ActiveSector);
  FILE *log_file = fopen("log.txt", "a");
  if (!log_file) {
    perror("Failed to open log file");
  }
  fprintf(log_file,"Gu8_PWMSectorRaw=%d\n",Gu8_PWMSectorRaw);
  fclose(log_file);
}
void PWM_Set_ShiftCompVals(
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
  FILE *log_file = fopen(LOG_FILE, "a");
  if (!log_file) {
    perror("Failed to open log file");
  }
  fprintf(log_file,"Su16_PwmCompValRise[3]={%d,%d,%d}\n",Su16_PwmCompValRise[PWM_CALC_PHASE_U],Su16_PwmCompValRise[PWM_CALC_PHASE_V],Su16_PwmCompValRise[PWM_CALC_PHASE_W]);
  fprintf(log_file,"Su16_PwmCompValFall[3]={%d,%d,%d}\n",Su16_PwmCompValFall[PWM_CALC_PHASE_U],Su16_PwmCompValFall[PWM_CALC_PHASE_V],Su16_PwmCompValFall[PWM_CALC_PHASE_W]);
  fclose(log_file);
}
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