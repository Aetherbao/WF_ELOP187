/***************************************************************************//**
 * \file       MotCtrl_wrap.h
 * \brief      Motor Control wrapper header file
 * \author     EAD1 SW Team - Domenico Di Stasi
 * \date       07/12/2022
 *
 * \par        Copyright (c) 2022, VHIT S.p.A. All rights reserved
 ******************************************************************************/
 
#ifndef MOTCTRL_WRAP_H
#define MOTCTRL_WRAP_H

// Includes
#include "types.h"

/***************************************************************************//**
 * \fn       Interface_StartupTask
 * \details  Call this function in a startup task to initialize inner variables.
 *           Caller for all the initialization function of Motor control library
 * ****************************************************************************/
void Interface_StartupTask(void);

/***************************************************************************//**
 * \fn       MotCtrl_startMotor
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void MotCtrl_startMotor(void);

/***************************************************************************//**
 * \fn       MotCtrl_stoptMotor
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
//void MotCtrl_stopMotor(void);

/***************************************************************************//**
 * \fn       Interface_FR_Task
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void Interface_FR_Task(void);

/***************************************************************************//**
 * \fn       Interface_500usTask
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void Interface_500usTask(void);

/***************************************************************************//**
 * \fn       Interface_1msTask
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void Interface_1msTask(void);

/***************************************************************************//**
 * \fn       Interface_5msTask
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void Interface_5msTask(void);

/***************************************************************************//**
 * \fn       Interface_10msTask
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void Interface_10msTask(void);

/***************************************************************************//**
 * \fn       Interface_100msTask
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void Interface_100msTask(void);

/***************************************************************************//**
 * \fn       Interface_Set_DutyCycle
 * \details  TODO
 * \todo     describe
 * ****************************************************************************/
void Interface_Set_DutyCycle(uint16 dutyCycles_u16[3]);

//bool MotCtrl_get_actualSatus(void);
void Interface_AgCalib_Trans(void);
void Interface_Mem_Trans(void);
void Interface_DcycGen_FstTask_Trans(void);
void Interface_SigIn_MedTask_Trans(void);
void Interface_PhVltgGen_MedTask_Trans(void);
void Interface_PhCurrGen_SlwTask_Trans(void);
void Interface_OBD_SlwTask_Trans(void);
void Interface_SigIn_SlwTask_Trans(void);
void Interface_ApplCom_ASW_Trans(void);
void Interface_FrzUDSCom_ASW_Trans(void);
void Interface_AST_SlwTask_Trans(void);
void Interface_SleepReq(void);
extern sint16 Gs16_Interface_ActSpd;
extern sint16 Gs16_ComIf_ActSpdBOOTChk;
extern uint8 Gu8_flgShOffflg;
//bool MotCtrl_get_calibDone(void);
//bool MotCtrl_get_DeratingActive_b(void);
//bool MotCtl_get_MotorBlockedPerm_b(void);
//sint16 MotCtrl_get_actualSpeed(void);
//sint16 MotCtrl_get_lineCurr_s16(void);
//sint16 MotCtrl_get_supplyCurr_s16(void);
//uint8 MotCtl_get_actualStaus(void);
//uint8 MotCtl_get_TempECU_u8(void);
//bool MotCtl_get_OverVoltFlag_b(void);
//bool MotCtl_get_UnderVoltFlag_b(void);
//bool MotCtl_get_OverTempFlag_b(void);
//bool MotCtl_get_OverLineCurrentFlag_b(void);

#endif //MOTCTRL_WRAP_H
