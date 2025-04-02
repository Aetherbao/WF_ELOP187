#include "ComIf_Init.h"
#include "linmain.h"
#include "uds.h"
#include "LinTp.h"

void ComIf_Init(void)
{
	
	ComDrv_LLD_Init();/*LIN protocal init data transmit methold :interrupt */

	ProtStk_UDS_Init();
	//uds_init(); 
	ProtStk_LINTp_Init();



}