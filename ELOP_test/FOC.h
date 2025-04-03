#ifndef MOTCTRL_WRAP_H
#define MOTCTRL_WRAP_H

#include "ASW_share/rtwtypes.h"

extern void Interface_FR_Task(void);
extern void Interface_500usTask(int count);
extern void Interface_10msTask(int count);

extern void Interface_DcycGen_FstTask_Trans(void);
extern void Interface_Set_DutyCycle(uint16 u16_dutyCyc[3]);
extern void Interface_Set_OutputEnable(uint8 u8_enable);
extern void Interface_SigIn_MedTask_Trans(void);
extern void Interface_PhVltgGen_MedTask_Trans();
extern void Interface_PhCurrGen_SlwTask_Trans(void);
extern void Interface_AST_SlwTask_Trans(void);
extern void Interface_OBD_SlwTask_Trans(void);
extern void Interface_SigIn_SlwTask_Trans(void);
extern void Interface_ApplCom_ASW_Trans(void);
extern void Interface_FrzUDSCom_ASW_Trans(void);
extern void Interface_AgCalib_Trans(void);


#endif //MOTCTRL_WRAP_H