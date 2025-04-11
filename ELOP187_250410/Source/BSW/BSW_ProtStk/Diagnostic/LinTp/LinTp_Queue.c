#include "LinTp_Queue.h"
#include "LinTp_SchM.h"

/*buffers for reducing the last time in CAN Rx interrupt*/
#define  LinTp_PDURXBUFFER_SIZE      (10u)

typedef unsigned char       boolean;        /* for use with TRUE/FALSE        */

typedef struct
{                                      
	linPduRefType pFifoIn;
	linPduRefType pFifoOut;
	linPduRefType pFifoBase;
	linPduRefType pFifoEnd;
	uint8 FifoRoom;
	uint8 FifoSize;
}lintp_pduFifoType;



static linPduType LinTp_PduRxBuffer[LinTp_PDURXBUFFER_SIZE];
static  lintp_pduFifoType lintp_pduFifo;


void LinTp_PduFifoInit(void)
{
	LINTP_ENTER_CRITICAL();

	lintp_pduFifo.pFifoIn = &(LinTp_PduRxBuffer[0]);
	lintp_pduFifo.pFifoOut = &(LinTp_PduRxBuffer[0]);
	lintp_pduFifo.pFifoBase = &(LinTp_PduRxBuffer[0]);
	lintp_pduFifo.pFifoEnd = &(LinTp_PduRxBuffer[LinTp_PDURXBUFFER_SIZE-1]);
	lintp_pduFifo.FifoRoom = LinTp_PDURXBUFFER_SIZE;
	lintp_pduFifo.FifoSize = LinTp_PDURXBUFFER_SIZE;
	LINTP_EXIT_CRITICAL();
}




static boolean LinTp_bPduFifoEmpty(void)
{
	return (lintp_pduFifo.FifoRoom == lintp_pduFifo.FifoSize);
}




static boolean LinTp_bPduFifoFull(void)
{
	return (lintp_pduFifo.FifoRoom == 0);
}




Std_ReturnType  LinTp_PduFifoInc(linPduRefType  pIn)
{
	Std_ReturnType ret = E_NOT_OK;

	if(pIn == NULL_PTR)
	{
		;
	}
	else
	{
		LINTP_ENTER_CRITICAL();
		
		if(LinTp_bPduFifoFull())
		{
			LINTP_EXIT_CRITICAL();
		}
		else
		{
			{
				uint8 loop_i;
				lintp_pduFifo.pFifoIn->length = pIn->length;
				for(loop_i=0; loop_i<pIn->length; loop_i++)
				{
					lintp_pduFifo.pFifoIn->buffer[loop_i] = pIn->buffer[loop_i];
				}
			}

			if (lintp_pduFifo.pFifoIn == (lintp_pduFifo.pFifoEnd)) 
			{
				lintp_pduFifo.pFifoIn = lintp_pduFifo.pFifoBase;
			} 
			else 
			{
				lintp_pduFifo.pFifoIn ++;
			}

			lintp_pduFifo.FifoRoom--;		
			LINTP_EXIT_CRITICAL();
			ret = E_OK;
		}
		}
	return ret;
}




Std_ReturnType  LinTp_PduFifoGetOne(linPduRefType * pOut)
{
	Std_ReturnType ret = E_NOT_OK;

	if(pOut == NULL_PTR)
	{
		;
	}
	else
	{
		LINTP_ENTER_CRITICAL();

		if(LinTp_bPduFifoEmpty())
		{
			LINTP_EXIT_CRITICAL();
		}
		else
		{
			{
				/*uint8 loop_i;
				pOut->length = lintp_pduFifo.pFifoOut->length;
				for(loop_i=0; loop_i<pOut->length; loop_i++)
				{
					pOut->buffer[loop_i] = lintp_pduFifo.pFifoOut->buffer[loop_i];
				}
				*/
				*pOut = lintp_pduFifo.pFifoOut;
			}

			if (lintp_pduFifo.pFifoOut == (lintp_pduFifo.pFifoEnd)) 
			{
				lintp_pduFifo.pFifoOut = lintp_pduFifo.pFifoBase;
			} 
			else 
			{
				lintp_pduFifo.pFifoOut ++;
			}		

			lintp_pduFifo.FifoRoom++;		
			LINTP_EXIT_CRITICAL();
			ret = E_OK;
		}
	}

	return ret;
}


