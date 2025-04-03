#ifndef HSI_SW_H
#define HSI_SW_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "types.h"
#include "int.h"
#include "wdt1.h"
#include "DIAG_Handle.h"
#include "timer2x_defines.h"
#include "sfr_access.h"
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
 void HSI_SPI_SendWord(uint16 u16_DataWord);
 uint8 HSI_SPI_RxIntCheck(void);
 void HSI_DMA_TxRxSrcSelect_SSC1(void);
 void HSI_DMA_TxRxChannelEnable(void);
 void HSI_TIMER21_ReInit500us(void);
 void HSI_TIMER21_ReInit10us(void);
uint8 HSI_DIAG_Get_VSUV_State(void);
uint8 HSI_DIAG_Get_VSOV_State(void);
uint8 HSI_DIAG_Get_VCPLO1_State(void);
uint8 HSI_DIAG_Get_VSDLO_State(void);
uint8 HSI_DIAG_Get_VSDUP_State(void);
void HSI_RunbootCode(void);
void HSI_Init(void);
void HSI_DmaBasePtrConfig(void);
uint8 HSI_NVMPage_Write(uint32 u32_TargetAddress,uint8 * u8p_SourceAddressPtr);
void HSI_VREF_Fault_Check(void);
#endif