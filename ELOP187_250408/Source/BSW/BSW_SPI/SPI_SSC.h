#ifndef SPI_SSC_H
#define SPI_SSC_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "tle987x.h"
#include "Mem_Mem.h"
#include "Sys_DMA.h"
#include "ssc.h"
/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
extern SRAM_GLOBAL_UINT16 Gu16_SPI_TxBuffer[SYS_DMA_CFG_DATABYTE]; /*SPI send data array*/
extern SRAM_GLOBAL_UINT16 Gu16_SPI_RxBuffer[SYS_DMA_CFG_DATABYTE]; /*SPI receive data array*/
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void SPI_Update_TxBuffer (const uint16 Cu16_TxData0, const uint16 Cu16_TxData1,const uint16 Cu16_TxData2);
void SPI_SyncTransmit(const uint8 Cu8_Access);
void SPI_DtTxHandle(uint8 u8_Access);
void SPI_DataTransferDMA(void);
void SPI_DataTransferStart(void);
#endif
