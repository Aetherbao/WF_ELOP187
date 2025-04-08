#include "Std_Types.h"
#include "Platform_Types.h"
#include "Lin_GeneralTypes.h"
//#include "Lin_17_AscLin.h"
//#include "IfxAsclin_reg.h"
#include "LinIf_GotoSleepIndication.h"
#include "LinIf_GotoSleepConfirmation.h"
#include "LinSlave_MainFunction.h"

#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)  
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* ASC Register Start Address Mapping */
#ifndef LIN_HW_MODULE
#define LIN_HW_MODULE  (&(MODULE_ASCLIN0))
#endif

#define LIN_SLAVE_MAINFUNC_PERIOD	(100)
#define LIN_BUS_IDLE_TIMEOUT			(4500/LIN_SLAVE_MAINFUNC_PERIOD)


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
	uint32 TOutDuration;
	boolean bBusIdleDetected;
	boolean bBusSleepHasReorted;
}LinSlave_BusIdleCheck_t;;




/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static LinSlave_BusIdleCheck_t LinSlave_BusIdleCheck[1] = {
	{LIN_BUS_IDLE_TIMEOUT,	FALSE,	FALSE}
};




void LinSlave_GotoSleepIndication(uint16 Chan)
{
	if(!LinSlave_BusIdleCheck[Chan].bBusSleepHasReorted)
	{				
		LinSlave_BusIdleCheck[Chan].bBusSleepHasReorted = TRUE;
			
		LinIf_GotoSleepIndication(Chan);
	}
}





static void LinSlave_CheckBusIdle(uint8 Chan)
{
	uint8 ModuleNo;
	Ifx_ASCLIN*  HwModulePtr;
	uint8 ChannelConfigMap[1] = {1};

	/* Extract the hwmodule */
	ModuleNo =ChannelConfigMap[Chan];	
	HwModulePtr = &(LIN_HW_MODULE[ModuleNo]);

	if( (HwModulePtr->FLAGS.B.FED == 1) ||(HwModulePtr->FLAGS.B.RED == 1))
	{
		/* clearing edge flags*/
		HwModulePtr->FLAGSCLEAR.U = 0xF0;

		LinSlave_BusIdleCheck[Chan].bBusIdleDetected = FALSE;
		LinSlave_BusIdleCheck[Chan].bBusSleepHasReorted = FALSE;
		LinSlave_BusIdleCheck[Chan].TOutDuration = LIN_BUS_IDLE_TIMEOUT;
	}
	else
	{
		if(LinSlave_BusIdleCheck[Chan].TOutDuration > 0)
		{
			LinSlave_BusIdleCheck[Chan].TOutDuration -= 1;
		}
		else
		{
			LinSlave_BusIdleCheck[Chan].bBusIdleDetected = TRUE;

			LinSlave_GotoSleepIndication(Chan);			
		}
	}	
}



void LinSlave_MainFunction(void)
{
	uint8 Chan;
	uint8 MaxChannel;
	uint8 buffer[9];
	uint8 * ptr;

	MaxChannel = 1;
	ptr = buffer;
	/* Enable the ASCLIN hardware unit/s for all the Lin channels */
	for (Chan = 0U; Chan < MaxChannel; Chan++)
	{
		LinSlave_CheckBusIdle(Chan);
		
		if(LinSlave_BusIdleCheck[Chan].bBusSleepHasReorted)
		{
			if(Lin_17_AscLin_GetStatus(Chan,&(ptr)) == LIN_CH_SLEEP)
			{
				LinIf_GotoSleepConfirmation(Chan, TRUE);
			}
		}			
	}
}


#endif

