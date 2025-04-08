/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Sys_Timer2x.h"
#include "Task_Task.h"
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
// void ESM_interrupt(void)
// {
// }

// void Timer2_1ms_interrupt(void)
// {
// 	Task_Timer_ISR();
// }

void Timer21_interrupt(void)//back or err handle
{
	Task_Timer_ISR();
	
	TIMER21_Stop();
}
