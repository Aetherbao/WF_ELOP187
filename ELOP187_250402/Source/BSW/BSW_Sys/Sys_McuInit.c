/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Sys_McuInit.h"
#include "tle_device.h"
#include "PWM_Pwm.h"
#include "Mem_Mem.h"
#include "PosSCD_PosSensor.h"
#include "linmain.h"
#include "uds.h"
#include "LinTp.h"
#include "Task_Task.h"
#include "PWM_Clac.h"
#include "HSI_SW.h"
#include "ComIf_Init.h"
#include "core_cm3.h"
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void Sys_McuInit(void)
{
  /* Initialization of hardware modules based on Config Wizard configuration */
	HSI_Init();

  /*set CCU6 T13 compare value is 1 */
	PWM_Set_T13CompareVal();
	
	Mem_RAMInit();/*BSW global variable init*/
	PosSCD_Init();/*TLE5012B SSC and DMA init*/
	
	ComIf_Init();


	// Start up hook
	// Task_StartupTask();
	PWM_SSM_Init();
}

void Sys_McuSystemReset(void)
{
	__NVIC_SystemReset();
}
