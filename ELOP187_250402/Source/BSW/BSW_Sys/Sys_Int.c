/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Sys_Timer2x.h"
#include "Sys_Int.h"
#include "int.h"
#include "cmsis_misra.h"

// SRAM_GLOBAL_UINT8 Gu8_DIAG_PLLLossLock;  /*PLL Loss of lock error status */
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/**************************************************************************************************
 brief         IntMon_PllLossOfLock_IRQHandler
 details       Interupt routine for Pll loss of lock (clock runtime error)
 
 param[in]     None

 return        None

 ****************************************************************************************************/
void IntMon_PllLossOfLock_IRQHandler(void)
{
	// Gu8_DIAG_PLLLossLock=1;
	NMI_PLL_Int_Clr();
	while(1);
}

void Sys_IntDisIrq(void)
{
    (void)CMSIS_Irq_Dis();
}

void Sys_IntEnIrq(void)
{
    (void)CMSIS_Irq_En();
}
