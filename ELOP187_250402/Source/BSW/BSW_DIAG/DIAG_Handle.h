#ifndef DIAG_HANDLE_H
#define DIAG_HANDLE_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Mem_Mem.h"
/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS1_DSMonitor;   /*HS1 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS2_DSMonitor;   /*HS2 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_HS3_DSMonitor;   /*HS3 DSMonitor error status */

// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS1_DSMonitor;   /*LS1 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS2_DSMonitor;   /*LS2 DSMonitor error status */
// static SRAM_GLOBAL_UINT8 Su8_DIAG_LS3_DSMonitor;   /*LS3 DSMonitor error status */


extern SRAM_GLOBAL_UINT8 Gu8_DIAG_VDD_1V5OV;      /*VDD 1.5V under voltage error status */
extern SRAM_GLOBAL_UINT8 Gu8_DIAG_VDD_5VOV;       /*VDD   5V under voltage error status */
extern SRAM_GLOBAL_UINT8 Gu8_DIAG_PMU_1V5OverLoad;/*PMU 1.5V over load error status */
extern SRAM_GLOBAL_UINT8 Gu8_DIAG_PMU_5VOverLoad; /*PMU   5V over load error status */

extern SRAM_GLOBAL_UINT16 Gu16_BSWToAPPFault_IF;/*BSW fault status*/
extern SRAM_GLOBAL_UINT8  Gu8_DIAG_HSLS_OCWarning;
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void DIAG_SysSupply_Err(void);
void DIAG_VCPAndVDHDiff_Handle(void);
void DIAG_BasicToAPPfault_Monitor(void);
void DIAG_VCPFault_Handle(void);
void DIAG_HSLSFault_Handle(void);
void DIAG_Fault_Monitor(void);
void DIAG_HSLS_OC_Timer_Handle_ISR(void);
void DIAG_PosSCD_Com(void);
void DIAG_VSDFault_Handle(void);
void DIAG_3PhaseOpenLoadFault_Handle(void);
void DIAG_VDDFault_Handle(void);
#endif