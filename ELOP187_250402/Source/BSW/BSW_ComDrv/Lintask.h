


#ifndef  LINTASK_H
#define LINTASK_H


#include "tle987x.h"

extern uint16 CountMessageNotReceived;
extern uint8 Flag_LinMessageNotReceived;
extern uint8 Flag_LinSlave_GotoSleepMid;

extern uint8 Flag_Count_LinSleep;


extern void ProtStk_UDS_1msTask(void);
extern void ComDrv_1msTask(void);
void LinAppl_Run(void);


sint16 CanApp_get_RefSpeed(void);

uint8 CanApp_get_RefSysStaFlag(void);





typedef  enum { LIN_STS_RQS_STOP =0,\
                LIN_STS_RQS_NORMAL,\
                LIN_STS_RQS_POSTRUN,\
                LIN_STS_DIAG,\
                LIN_STS_ERROR,\
                LIN_STS_RQS_LIMPHOME,\
                LIN_STS_SLEEP  } LIN_STS;



#endif