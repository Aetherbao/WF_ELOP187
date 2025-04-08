#include "ComIf_Task.h"
#include "Lintask.h"
#include "LinTp.h"
#include "uds.h"
#include "Linmain.h"
#include "ComIf_SA_HAL.h"


void ComIf_1msTask(void)
{
	 // mainTask_1ms();
  //  APP_Task1ms();
	  ProtStk_UDS_1msTask();
	  //LinTp_task_1ms();
		//uds_task();
	  ComDrv_1msTask();
	
	  Gu8_ComIf_StmUser_1msCnt++;
	
		//LinAppl_Run();//
	  
	  //LIN_LLD_Service();
	
}

void ComIf_500usTask(void)
{

  
   ComDrv_500usTask();


}







