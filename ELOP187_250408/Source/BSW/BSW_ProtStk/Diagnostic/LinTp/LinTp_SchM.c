#include "LinTp_SchM.h"
//#include "Mcal_Compiler.h"
//#include "cmsis_misra.h"
#include "lin_driver_api.h"


unsigned char linirqState =0;

void LINTP_ENTER_CRITICAL(void)
{
  //DISABLE();
	//	__set_PRIMASK (1);//DisableAllInterrupts
	
	 linirqState = l_sys_irq_disable ();
}


void LINTP_EXIT_CRITICAL(void)
{
 // ENABLE();
	
	//	__set_PRIMASK (0);//EnableAllInterrupts
	
	l_sys_irq_restore (0);
}





