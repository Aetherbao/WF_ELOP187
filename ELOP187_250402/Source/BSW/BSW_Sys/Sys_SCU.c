/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Sys_SCU.h"
#include "ssc.h"
#include "scu.h"
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void Sys_SCU_SleepMode(void)
{
  // if(SleepMode_swtEnable_mp==1)
		 SCU_EnterSleepMode(); /*the device enters sleep mode */
}

 void Sys_SCU_ClrRxInt(void)
{
  SSC1_RX_Int_Clr();/* Clear Interrupt Flag */
}
