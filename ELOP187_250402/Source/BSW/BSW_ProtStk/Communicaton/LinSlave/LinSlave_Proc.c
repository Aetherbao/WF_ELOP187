#include "Std_Types.h"
#include "Platform_Types.h"
#include "Lin_GeneralTypes.h"
#include "LinSlave_Proc.h"
#include "LinIf_RxIndication.h"
#include "LinIf_HeaderIndication.h"
#include "LinIf_TxConfirmation.h"
#include "LinIf_WakeupConfirmation.h"
//#include "IfxAsclin_reg.h"


#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* ASC Register Start Address Mapping */
#ifndef LIN_HW_MODULE
#define LIN_HW_MODULE  (&(MODULE_ASCLIN0))
#endif


/*******************************************************************************
**                      External Functions Declaration                             **
*******************************************************************************/
extern void LinSlave_GotoSleepIndication(uint16 Chan);



/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static uint8 Lin_RspBuffer[9];


void LinSlave_PrepareHeaderReception(uint8 HwUnit)
{
    Ifx_ASCLIN*  HwModulePtr;
	/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
	efficiently access the SFRs of multiple ASCLIN kernels.*/
	HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
	 /*configure the watchdog timer*/
	HwModulePtr->DATCON.B.RESPONSE = 255;
	 /* flushing Rx FIFO*/
	HwModulePtr ->RXFIFOCON.B.FLUSH = 1;
	 /* enabling Rx FIFO for receiving*/
	HwModulePtr->RXFIFOCON.B.ENI = 1;	 
	/* clearing all flags*/
	HwModulePtr->FLAGSCLEAR.U = 0xFFFFFF0F;
	/*enable the RX Header interrupt event*/
	HwModulePtr->FLAGSENABLE.B.RHE = 1;
	/*enable the EX interrupt events*/
	HwModulePtr->FLAGSENABLE.B.HTE = 1;
	HwModulePtr->FLAGSENABLE.B.CEE = 1;
	HwModulePtr->FLAGSENABLE.B.FEE = 1;
	HwModulePtr->FLAGSENABLE.B.ABE = 1;
	HwModulePtr->FLAGSENABLE.B.LPE = 1;
}


static void LinSlave_RcvdResponseProc(uint8 HwUnit)
{
	Lin_PduType  LinPdu;
	Ifx_ASCLIN*  HwModulePtr;
	
	HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
	
	LinPdu.SduPtr =  Lin_RspBuffer;

	/*read out the data from RXFIFO*/
	{
		uint8 tmpCnt = 0;
		while(tmpCnt < 9)
		{
			Lin_RspBuffer[tmpCnt] = (uint8)(HwModulePtr->RXDATA.U);
			tmpCnt += 1;
		}

		/*clear the uder flow flag if data length < 8*/
		HwModulePtr->FLAGSCLEAR.B.RFUC = 1;

		/* flushing Rx FIFO*/			
		HwModulePtr->RXFIFOCON.B.FLUSH = 1;			
	}

	if(  (Lin_RspBuffer[0] == 0x3c) && (Lin_RspBuffer[1] == 0x00))
	{
		/* clearing edge flags*/
		HwModulePtr->FLAGSCLEAR.U = 0xF0;
		LinSlave_GotoSleepIndication(0);
	}
	else
	{	
		LinIf_RxIndication(0, Lin_RspBuffer);
	}
}






static void LinSlave_RcvdHeaderProc(uint8 HwUnit)
{
	Lin_PduType  LinPdu;
	Ifx_ASCLIN*  HwModulePtr;
	
	HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
	
	LinPdu.SduPtr =  Lin_RspBuffer;

	LinPdu.Pid = (uint8)(HwModulePtr->RXDATAD.U);
		
	LinIf_HeaderIndication(0, &LinPdu);

	if(LinPdu.Drc == LIN_FRAMERESPONSE_IGNORE)
	{
		/* disable Rx FIFO */
		HwModulePtr->RXFIFOCON.B.ENI =  0;
		/* set header only mode*/
		HwModulePtr->DATCON.B.HO = 1;			
		/* clear all flags */
		HwModulePtr->FLAGSCLEAR.U = 0xFFFFFF0F;	
		/* flushing Rx FIFO*/
		HwModulePtr->RXFIFOCON.B.FLUSH = 1;			
	}
	else if(LinPdu.Drc == LIN_FRAMERESPONSE_RX)
	{
		/* set number of bytes to be received*/
		HwModulePtr->DATCON.B.DATLEN = LinPdu.Dl-1;
		/*configure the watchdog timer*/
		HwModulePtr->DATCON.B.RESPONSE = 255;
		/*configure the checksum mode*/
		HwModulePtr->DATCON.B.CSM = LinPdu.Cs;				
		/* enable Rx FIFO */
		HwModulePtr->RXFIFOCON.B.ENI =  1;
		/* disable Tx FIFO for transmitting */
		HwModulePtr->TXFIFOCON.B.ENO = 0;
		/*clear the event flags */
		HwModulePtr->FLAGSCLEAR.B.RRC = 1;
		HwModulePtr->FLAGSCLEAR.B.RFOC = 1;
		HwModulePtr->FLAGSCLEAR.B.RFUC = 1;
		HwModulePtr->FLAGSCLEAR.B.FEC = 1;
		HwModulePtr->FLAGSCLEAR.B.LCC = 1;
		HwModulePtr->FLAGSCLEAR.B.RTC = 1;
		HwModulePtr->FLAGSCLEAR.B.FEDC = 1;
		HwModulePtr->FLAGSCLEAR.B.REDC = 1;
		HwModulePtr->FLAGSCLEAR.B.BDC = 1;
			
		/*enable the RX interrupt event*/
		HwModulePtr->FLAGSENABLE.B.RRE = 1;
		/*enable the EX interrupt events*/
		HwModulePtr->FLAGSENABLE.B.RFOE = 1;
		HwModulePtr->FLAGSENABLE.B.RFUE = 1;
		HwModulePtr->FLAGSENABLE.B.FEE = 1;
		HwModulePtr->FLAGSENABLE.B.LCE = 1;
		HwModulePtr->FLAGSENABLE.B.RTE = 1;
	}
	else
	{
		HwModulePtr->DATCON.B.DATLEN = LinPdu.Dl-1;
		/*configure the watchdog timer*/
		HwModulePtr->DATCON.B.RESPONSE = 255;
		/*configure the checksum mode*/
		HwModulePtr->DATCON.B.CSM = LinPdu.Cs;

		/* enable Rx FIFO */
		//HwModulePtr->RXFIFOCON.B.ENI =  1;
		
		/* enable Tx FIFO for transmitting */
		HwModulePtr->TXFIFOCON.B.ENO = 1;
		
		/*clear the event flags : TRC, TFOC/UC, CEC, RTC, BDC*/
		HwModulePtr->FLAGSCLEAR.B.TRC = 1;
		HwModulePtr->FLAGSCLEAR.B.TFOC = 1;
		//HwModulePtr->FLAGSCLEAR.B.TFUC = 1;
		HwModulePtr->FLAGSCLEAR.B.CEC = 1;
		HwModulePtr->FLAGSCLEAR.B.RTC = 1;
		HwModulePtr->FLAGSCLEAR.B.BDC = 1;
		
		/*enable the TX interrupt event*/
		HwModulePtr->FLAGSENABLE.B.TRE = 1;
		/*enable the EX interrupt events*/
		HwModulePtr->FLAGSENABLE.B.TFOE = 1;
		HwModulePtr->FLAGSENABLE.B.CEE = 1;
		HwModulePtr->FLAGSENABLE.B.RTE = 1;
		//HwModulePtr->FLAGSENABLE.B.BDE = 1;
		/* fill the transmitted data */
		{
			uint8 tmpCnt = 0;

			HwModulePtr->TXFIFOCON.B.FLUSH = 1;
			while(tmpCnt < LinPdu.Dl)
			{
				HwModulePtr->TXDATA.U = LinPdu.SduPtr[tmpCnt];
				tmpCnt += 1;
			}					
		}
		/* set TRRQS flag */
		HwModulePtr->FLAGSSET.B.TRRQS = 1;	
	}
}


/*******************************************************************************
** Syntax :          void LinSlave_IsrErrorHandler( uint8  HwUnit)              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Non-reentrant for same HwUnit                            **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever there is an data        **
**                   transmission or reception error
**                   or a wakeup interrupt in ASCLIN                          **
*******************************************************************************/
void LinSlave_IsrErrorHandler(uint8 HwUnit)
{
	LinSlave_PrepareHeaderReception(HwUnit);
}



/*******************************************************************************
** Syntax :          void LinSlave_IsrTransmitHandler( uint8  HwUnit)           **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever the response data       **
**                   is successfully transmitted by the ASCLIN w/o any errors **
**                                                                            **
*******************************************************************************/
void LinSlave_IsrTransmitHandler(uint8  HwUnit)
{
	Ifx_ASCLIN*  HwModulePtr;
	HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
	
	if(HwModulePtr->FLAGS.B.TR == 1)
	{
		//Lin_RspBuffer[0] = (uint8)(HwModulePtr->RXDATAD.U);
				
		/* flushing Rx FIFO*/
		//HwModulePtr ->RXFIFOCON.B.FLUSH = 1;
		/* flushing Tx FIFO*/
		HwModulePtr ->TXFIFOCON.B.FLUSH = 1;

		LinIf_TxConfirmation(0);

		LinSlave_PrepareHeaderReception(HwUnit);
	}
}


/*******************************************************************************
** Syntax :          void LinSlave_IsrReceiveHandler( uint8  HwUnit)            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever the Slave response data **
**                   is completely received by the ASCLIN w/o any errors      **
**                                                                            **
*******************************************************************************/
void LinSlave_IsrReceiveHandler(uint8  HwUnit)
{
	Ifx_ASCLIN*  HwModulePtr;	
	HwModulePtr = &(LIN_HW_MODULE[HwUnit]);

	/*received a header*/
	if(HwModulePtr->FLAGS.B.RH == 1)
	{
		/*clear the receive header flag*/
		HwModulePtr->FLAGSCLEAR.B.RHC = 1;

		LinIf_WakeupConfirmation();
		LinSlave_RcvdHeaderProc(HwUnit);
	}

	/*received a response*/
	else if(HwModulePtr->FLAGS.B.RR == 1) 
	{
		/*clear the receive response flag*/
		HwModulePtr->FLAGSCLEAR.B.RRC = 1;
		
		LinSlave_RcvdResponseProc(HwUnit);
		/*prepare next Header Reception*/
		LinSlave_PrepareHeaderReception(HwUnit);
	}
	
	else
	{
		/* clear all flags */
		HwModulePtr->FLAGSCLEAR.U = 0xFFFFFF0F;
	}
}

#endif

