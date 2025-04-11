#ifndef SYS_DMA_H
#define SYS_DMA_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Mem_Mem.h"
#include "dma.h"
#define SYS_DMA_CFG_DATABYTE                         (3U)

#define SYS_DMA_CFG_STARTADDRESS     (0x18001600)
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void Sys_DMAInit(void);//use
void Sys_DMAResetChannel(void);//use
#endif
