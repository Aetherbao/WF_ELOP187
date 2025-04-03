/*
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/

/*******************************************************************************
**                             Author(s) Identity                             **
********************************************************************************
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** BG           Blandine Guillot                                              **
*******************************************************************************/

/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V1.0.0: 2014-05-20, DM:   Initial version                                  **
** V1.0.1: 2020-07-21, BG:   EP-439: Formatted .h/.c files                    **
*******************************************************************************/

#include "linmain.h"
#include "utils.h"
/*******************************************************************************
**                        Global Variable Declarations                        **
*******************************************************************************/
/* Global variables */
volatile unsigned char timer_250us, timer_1ms;
volatile uint16 timer_1s;
unsigned int BusIdleTimeOutCounter, tmpStatus;

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void ComDrv_LLD_Init(void)
{
  /* LIN driver init */
  l_sys_init();
}

void LIN_LLD_Service(void)
{
	
	
	
//  if (timer_250us)
//  {
//    timer_250us = 0u;
//    /* Cyclic communication task has to be called once every byte */
//    l_cyclic_com_task();    //zhq
//  }

  /* 1ms cyclic task */
 // if (timer_1ms >= 4u)
  {
    //timer_1ms = 0u;
    BusIdleTimeOutCounter++;
    /* Get the status of the LIN driver from status word, see LIN specification for more detailed information */
    tmpStatus = l_ifc_read_status();

    /* If one of the status flags is set, there was something on the bus */
    /* Reset the counter and wake up */
    if (tmpStatus & 0x00FFu)
    {
      BusIdleTimeOutCounter = 0u;
    }

    /* After 4 seconds of no communication or other disturbance, go to sleep */
    if (BusIdleTimeOutCounter >= 4000u)
    {
      BusIdleTimeOutCounter = 4000u; /* To prevent overflow */
    }

    /* Cyclic task of driver (timeout and diagnostic control) */
    ld_task();
	
		
		
		
  }
}

l_irqmask l_sys_irq_disable (void)
{
	
		__set_PRIMASK (1);//DisableAllInterrupts
  return 0u;
}

void l_sys_irq_restore (l_irqmask mask)
{
	__set_PRIMASK (0);//EnableAllInterrupts
  return;
}

void LIN_Enable_Transceiver(void)
{
}

void LIN_Disable_Transceiver(void)
{
}

void LIN_Task_250us(void)
{
  timer_250us++;
  timer_1ms++;
  timer_1s++;
}

void LIN_COM_Handler(void)
{
#ifdef AUTOBAUD_ENABLED

  if (TIMER2->T2CON.bit.EXF2 == 1u)
  {
    l_ifc_t2();
    TIMER2->T2ICLR.bit.EXF2CLR = 1u;
  }

#endif /* end #ifdef AUTOBAUD_ENABLED */

  if ((UART1->SCON.reg & 0x01u) == 1u)
  {
		//SleepMode_tiCount_mp=0;
    l_ifc_rx();
    UART1->SCONCLR.bit.RICLR = 1u;
  }
}
