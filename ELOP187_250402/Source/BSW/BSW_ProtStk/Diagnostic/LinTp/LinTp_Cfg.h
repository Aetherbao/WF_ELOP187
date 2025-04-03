#ifndef LINTP_CFG_H_
#define LINTP_CFG_H_

#include "ComIf_UdsDspCfg.h"
/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/
//#define 	BMS_NAD		(0x08)

//#define 	FUNC_AD		(0x7E)
//#define 	BOARD_AD		(0x7F)

//#define     LIN_TP_PADDING	(0xFF)


/* Params set based nt_task call period, set value is Ticks */
#define PARAM_NT_TASK_CYCLE	(1)
#define PARAM_NT_TM_Cr          	(1000/PARAM_NT_TASK_CYCLE)
#define PARAM_NT_TM_Bs          	(1000/PARAM_NT_TASK_CYCLE)
#define PARAM_NT_TM_Cs       	(0)
#define PARAM_NT_TM_As            (1000/PARAM_NT_TASK_CYCLE)










#endif

