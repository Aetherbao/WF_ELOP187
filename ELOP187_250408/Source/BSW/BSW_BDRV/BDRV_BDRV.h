#ifndef BDRV_BDRV_H
#define BDRV_BDRV_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "port.h"
#include "Mem_Mem.h"
/*******************************************************************************
**                         Global Macro Declarations                         **
*******************************************************************************/
typedef enum
{
  BDRV_INIT_IDLE = 0, 
  BDRV_INIT_STEP1, 
  BDRV_INIT_DONE, 
} ENM_BDRV_INITSTATE;

#define BDRV_OUTPUT_OPEN				  ((uint8)1)
#define BDRV_OUTPUT_CLOSE				  ((uint8)0)

extern ENM_BDRV_INITSTATE GenmBDRV_InitState;
extern SRAM_GLOBAL_UINT8 Gu8_PWM_MotorRunStatus;      /*PWM work  status 1:run  0:stop */

/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void BDRV_ConfigBridgePWM(void);
void BDRV_ConfigBridgeOff(void);
void BDRV_Clr_OC_STS(void);
void BDRV_Init_Check(void);
void BDRV_StateSwitch(void);
#endif