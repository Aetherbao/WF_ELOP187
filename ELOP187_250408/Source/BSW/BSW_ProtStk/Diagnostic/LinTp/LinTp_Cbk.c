#include "LinTp_Cbk.h"
#include "Std_Types.h"
#include "LinTp_types.h"


/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/
extern Std_ReturnType  LinTp_PduFifoInc(linPduRefType  pIn);
extern void LinTp_TxMsgProc(uint8 * pBuff);
extern void LinTp_TxConfirmation(void);




void LinTp_LinIfRxIndication(const PduInfoType * ptr)
{
	uint8 loop_i;
	linPduType linPdu;

	linPdu.length = (unsigned char)(ptr->SduLength);
	
	for(loop_i=0; loop_i<linPdu.length; loop_i++)
	{
		linPdu.buffer[loop_i] = ptr->SduDataPtr[loop_i];
	}
	
	LinTp_PduFifoInc(&linPdu);
}



void LinTp_LinIfTriggerTransmit(PduInfoType * ptr)
{
	LinTp_TxMsgProc(ptr->SduDataPtr);
}



void LinTp_LinIfTxConfirmation(void)
{
	LinTp_TxConfirmation();
}

