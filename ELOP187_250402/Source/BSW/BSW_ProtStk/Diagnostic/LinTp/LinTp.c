/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "LinTp.h"
#include "Std_Types.h"
#include "LinTp_Types.h"
#include "LinTp_Queue.h"
#include "LinTp_Cfg.h"
#include "LinTp_Timer.h"
#include "LinTP_Import.h"
#include "LinTp_export.h"

#include "uds.h"
/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      local RAM-Variables
------------------------------------------------------------------------------*/
lintp_state_t 		lintp_state = NTS_IDLE; /* NT request, response flow status */
nt_bool_t 			lintp_functional_req = FALSE; 			
unsigned char   lintp_bmsnad_fault = FALSE;

static nt_byte_t        linTp_tx_cf_sn   = 0; /* transmit CF block SN */
static nt_byte_t 	linTp_rx_cf_sn = 0; /* Next receive CF_SN */



static uint8 LinTp_RequestBuffer[APP_RECEIVE_BUF_SIZE];
static uint8 LinTp_ResponseBuffer[APP_SEND_BUF_SIZE];


linDiagReq_Rx_t linDiagRxReq = {
	LinTp_RequestBuffer,
	APP_RECEIVE_BUF_SIZE,
	0,
	0,
	0,
	LinReq_NotReady
};

linDiagResp_Tx_t linDiagTxResp = {
	LinTp_ResponseBuffer,
	APP_SEND_BUF_SIZE,
	0,
	0,
	0,
	LinResp_NotReady
};


/*------------------------------------------------------------------------------
                      External declaration of global RAM-Variables
------------------------------------------------------------------------------*/




/*------------------------------------------------------------------------------
                      Implementation of global functions
------------------------------------------------------------------------------*/
/*
 * Function:LinTp_pdu_push
 * Param<nt_byte_t nt_pdu_buf[]>: the buffer need push to NT received buffer
 * Param<nt_byte_t start>: push start position of nt_pdu_buf (the input buffer)
 * Param<nt_byte_t length>: push length of nt_pdu_buf (the input buffer)
 * Return<static nt_bool_t>: push result
 * REQ IDs:
 * Discription:
 * Note: 
*/
static nt_bool_t LinTp_pdu_push(nt_byte_t nt_pdu_buf[], nt_byte_t start, nt_byte_t length)
{
    nt_bool_t rst = FALSE; /* pre-set push Fail */
    nt_byte_t index = 0; /* nt_pdu_buf push data index */

    /* input parameter valid, buffer enough and received data length push valid check */
    if (((start + length) <= linDiagRxReq.bufSize)
        && ((linDiagRxReq.rcvdPos + length) <= linDiagRxReq.bufSize)
        && (linDiagRxReq.remainDl >= length))
    {
        /* push data */
        for (index = 0; index < length; index++)
        {
             /* set data */
	    linDiagRxReq.data[linDiagRxReq.rcvdPos++] = nt_pdu_buf[start++];
	    /* received remain data length-- */
	    linDiagRxReq.remainDl--;
        }
        rst = TRUE;
    }
    return rst;
}


 void linTp_Reset(void)
{
	/* reset NT status */
	lintp_state   = NTS_IDLE;
	
	/* reset for transmit */
	linTp_tx_cf_sn   = 0;
	linTp_rx_cf_sn = 0;
	
	/* application layer initialize */
	linDiagRxReq.rcvdPos  = 0;
	linDiagRxReq.requestLen  = 0;
	linDiagRxReq.remainDl = 0;
	linDiagRxReq.reqStatus = LinReq_NotReady;
	
	linDiagTxResp.sendPos = 0;
	linDiagTxResp.responseLen  = 0;
	linDiagTxResp.pdServId = 0;
	linDiagTxResp.respStatus = LinResp_NotReady;

	LinTp_ResetTimer();
}




static void LinTp_RxMsgProc(void)
{
	Std_ReturnType result;
	linPduType * pLinPdu;	
	
	result = LinTp_PduFifoGetOne(&pLinPdu);
	
	if(result == E_NOT_OK){return;}
	
	//if(pLinPdu->buffer[NT_NAD_POS] == FUNC_AD){lintp_functional_req = TRUE;}	
	if((pLinPdu->buffer[NT_NAD_POS] == FUNC_AD)|| (pLinPdu->buffer[NT_NAD_POS] == BOARD_AD)){lintp_functional_req = TRUE;}	
	else if(pLinPdu->buffer[NT_NAD_POS] == BMS_NAD){lintp_functional_req = FALSE;}
	else
    {
		    lintp_bmsnad_fault = TRUE;
				return;
		
		}

	if(pLinPdu->length != NT_PDU_BUFFER_SIZE){return;}
	
	{
		nt_byte_t pciType = 0xFFu;
		nt_byte_t fc_fs = 0xFFu;
		nt_byte_t dt_len = 0;
		
		/* get N_PCI type */
		pciType = (nt_byte_t)(pLinPdu->buffer[NT_NPCI_POS] & NT_NPCI_MASK);

		if((lintp_functional_req) && (pciType != NT_NPCI_SF)){return;}

		switch (pciType)
		{
			case NT_NPCI_SF:
			{
				/* single frame */
				/* Half-duplex: Segmented transmit in progress check */
				if(	(lintp_functional_req) &&
					(NTS_WAIT_CF == lintp_state  || NTS_RX_FF == lintp_state))
				{
					/*do nothing*/
				}
				/* during in transmit process */
				else if(lintp_state >= NTS_APPL_LOCKED)
				{
					/*Abort sending*/
					linTp_Reset();
				}
				else 
				{}
				{
					/* get SF data length */
					dt_len = (nt_byte_t)(pLinPdu->buffer[NT_NPCI_POS] & NT_NPCI_INV_MASK);
					/* data length valid check (data length invalid will ignore the received N_PDU) */
					if (dt_len > 0 && dt_len <= NT_SF_MAX_DL)
					{
						/* reset timer */
						LinTp_ResetTimer();
						/* set NT status to NTS_RX_SF */
						lintp_state = NTS_RX_SF;
						/* store received data length */
						linDiagRxReq.requestLen = (nt_word_t)dt_len;
						linDiagRxReq.remainDl = (nt_word_t)dt_len;
						/* set remain receive data length to 0 */
						//linDiagRxReq.remainDl = linDiagRxReq.requestLen;
						/* reset receive buffer */
						//linDiagRxReq.rcvdPos = 0;
						/* push data */
						if (TRUE == LinTp_pdu_push(pLinPdu->buffer, (NT_NPCI_POS+1), dt_len))
						{						
							linDiagRxReq.rcvdPos  = 0;
							linDiagRxReq.remainDl = 0;
							linDiagRxReq.reqStatus = LinReq_Ready;	

							/* change status to application layer locked state */
							lintp_state = NTS_APPL_LOCKED;
						}
						else
						{
							linTp_Reset();
						}
					}
				}
			}break;

			case NT_NPCI_FF:
			{
				/* during in transmit process */
				if(lintp_state >= NTS_APPL_LOCKED)
				{
					/*Abort sending*/
					linTp_Reset();
				}
				else
				{}
				{
					/* get frame length (12 bit length) */
					linDiagRxReq.requestLen = (nt_word_t)(pLinPdu->buffer[NT_NPCI_POS] & NT_NPCI_INV_MASK);
					linDiagRxReq.requestLen <<= 8;
					linDiagRxReq.requestLen += pLinPdu->buffer[NT_NPCI_POS + 1];
					/* set remain length to need received length */
					linDiagRxReq.remainDl = linDiagRxReq.requestLen;
					
					/* FF length valid check */				
					if ((linDiagRxReq.requestLen < NT_FF_MIN_DL) || (linDiagRxReq.requestLen > APP_RECEIVE_BUF_SIZE)){return;}				
					
					/* reset Timer */
					LinTp_ResetTimer();
					/* set NT status */
					lintp_state = NTS_RX_FF;
					/* reset receive buffer */
					linDiagRxReq.rcvdPos = 0;
					/* set next receive CF SN */
					linTp_rx_cf_sn = 1;
					/* push data (will auto dec remain length) */
					if (TRUE == LinTp_pdu_push(pLinPdu->buffer, (nt_byte_t)NT_FF_DT_START_POS, (nt_byte_t)NT_FF_DT_LEN))
					{
						/* set NT status */
						lintp_state = NTS_WAIT_CF;
						/* set Cr Timeout */
						LinTp_SetTimer(NT_TM_Cr);
					}
					else
					{
						/* Push fail, reset NT */
						linTp_Reset();
					}				
				}
			}break;
			 
			case NT_NPCI_CF:
			{
			    /* consecutive frame */
			    /* NT status match check, if not in wait CF status, ignore received N_PDU */
			    if(NTS_WAIT_CF == lintp_state)
			    {
				LinTp_CancelTimer(NT_TM_Cr);
				if ((pLinPdu->buffer[NT_NPCI_POS] & NT_NPCI_INV_MASK) == linTp_rx_cf_sn)
				{
					/* SN ++ */
					linTp_rx_cf_sn++;
					linTp_rx_cf_sn &= 0x0Fu; /* SN is 4 bit length */
					/* remain length check (if below or equal NT_CF_MAX_DL, is last CF block) */
					if (linDiagRxReq.remainDl > NT_CF_MAX_DL)
					{
						/* Not last block */
						/* push data */
						if (TRUE == LinTp_pdu_push(pLinPdu->buffer, (nt_byte_t)NT_CF_DT_START_POS, (nt_byte_t)NT_CF_MAX_DL))
						{
							/* push success, set Next receive CF timer */
							LinTp_SetTimer(NT_TM_Cr);
						}
						else
						{
							/* push fail, reset NT */
							linTp_Reset();
						}
					}
					else
					{
						/* Last block */
						/* push data */
						if (TRUE == LinTp_pdu_push(pLinPdu->buffer, (nt_byte_t)NT_CF_DT_START_POS, (nt_byte_t)linDiagRxReq.remainDl))
						{
							/* push success */
							/* reset Timer (Stop all NT timer) */
							LinTp_ResetTimer();							

							linDiagRxReq.rcvdPos  = 0;
							linDiagRxReq.remainDl = 0;
							linDiagRxReq.reqStatus = LinReq_Ready;	

							/* change status to application layer locked state */
							lintp_state = NTS_APPL_LOCKED;
						}
						else
						{
							/* push fail, reset NT */
							linTp_Reset();
						}
					}
				}
				else
				{
					/* reset NT */
					linTp_Reset();
					/* Hear can make a callback to the adjacent upper layer */
				}
			}
		    }break;
			
		default:
		{}break;
	    }		
	}
}




uint8 flagdada=0;
uint8 flagrespStatus =0;
void LinTp_TxMsgProc(uint8 * pBuff)
{
//	flagdada++;
//	if(flagdada == 3)
//	{
//	  flagdada =0;
//		
//	flagrespStatus =	linDiagTxResp.respStatus ;
//	
//	}
	
	if(linDiagTxResp.respStatus != LinResp_Ready)
 	{
		uds_rspPending();
		
		pBuff[NT_NAD_POS] = BMS_NAD;
		pBuff[NT_NPCI_POS] = 0x03;
		pBuff[2] = 0x7F;
		pBuff[3] = linDiagTxResp.pdServId;
		pBuff[4] = 0x78;
		pBuff[5] = LIN_TP_PADDING;
		pBuff[6] = LIN_TP_PADDING;
		pBuff[7] = LIN_TP_PADDING;
	}
	else
	{
		nt_byte_t pdu_index;

		if(lintp_state == NTS_APPL_LOCKED)
		{
			/* start send */
			if (linDiagTxResp.responseLen <= NT_SF_MAX_DL)
			{
				/* single frame transmit */
				lintp_state = NTS_SEND_SF;			
				/* set Datas */
				for (pdu_index = 0; pdu_index < NT_PDU_BUFFER_SIZE; pdu_index++)
				{
					if(pdu_index == NT_NAD_POS)
					{
						pBuff[pdu_index] = BMS_NAD;
					}
					else if(pdu_index == NT_NPCI_POS)
					{
						pBuff[pdu_index] = (nt_byte_t)(NT_NPCI_SF | (linDiagTxResp.responseLen & 0x0Fu));
					}
					else
					{
						if(linDiagTxResp.sendPos < linDiagTxResp.responseLen)
						{
							pBuff[pdu_index] = linDiagTxResp.data[linDiagTxResp.sendPos++];
						}
						else
						{
							pBuff[pdu_index] = LIN_TP_PADDING;
						}
					}
				}
			}
			else
			{
				/* multi-frame transmit by consecutive segment frame */
				/* first frame transmit */
				lintp_state = NTS_SEND_FF;
				/* set start block SN (FF for block 0) */
				linTp_tx_cf_sn   = 0;
				
				/* set Datas */
				for (pdu_index = 0; pdu_index < NT_PDU_BUFFER_SIZE; pdu_index++)
				{
					if(pdu_index == NT_NAD_POS)
					{
						pBuff[pdu_index] = BMS_NAD;
					}
					else if(pdu_index == NT_NPCI_POS)
					{
						pBuff[pdu_index++] = (nt_byte_t)(NT_NPCI_FF | ((linDiagTxResp.responseLen >> 8) & 0x0Fu));
						pBuff[pdu_index] = (nt_byte_t)(linDiagTxResp.responseLen & 0x00FFu);
					}
					else
					{
						if(linDiagTxResp.sendPos < linDiagTxResp.responseLen)
						{
							pBuff[pdu_index] = linDiagTxResp.data[linDiagTxResp.sendPos++];
						}
						else
						{
							pBuff[pdu_index] = LIN_TP_PADDING;
						}
					}
				}
			}			
		}

		else if(lintp_state == NTS_SEND_CF)
		{
			lintp_state = NTS_SEND_CF;

			/* SN ++ */
			linTp_tx_cf_sn++;
			linTp_tx_cf_sn &= 0x0F; /* SN is 4 bit length */

			/* set Datas */
			for (pdu_index = 0; pdu_index < NT_PDU_BUFFER_SIZE; pdu_index++)
			{
				if(pdu_index == NT_NAD_POS)
				{
					pBuff[pdu_index] = BMS_NAD;
				}
				else if(pdu_index == NT_NPCI_POS)
				{
					pBuff[pdu_index] = (nt_byte_t)(NT_NPCI_CF | (linTp_tx_cf_sn & 0x0Fu));
				}
				else
				{
					if(linDiagTxResp.sendPos < linDiagTxResp.responseLen)
					{
						pBuff[pdu_index] = linDiagTxResp.data[linDiagTxResp.sendPos++];
					}
					else
					{
						pBuff[pdu_index] = LIN_TP_PADDING;
					}
				}
			}
		}
		else
		{
			/*shall never be reached!!!*/
		}
	}

	LinTp_SetTimer(NT_TM_As);
}



void LinTp_TxConfirmation(void)
{	
	LinTp_CancelTimer(NT_TM_As);
	
	switch(lintp_state)
	{
		case NTS_SEND_SF:
		{
			linTp_Reset();
		}break;

		case NTS_SEND_FF:
		{
			lintp_state = NTS_SEND_CF;
			LinTp_SetTimer(NT_TM_Bs);
		}break;

		case NTS_SEND_CF:
		{
			LinTp_CancelTimer(NT_TM_Bs);
			if(linDiagTxResp.sendPos >= linDiagTxResp.responseLen)
			{
				linTp_Reset();
			}
			else
			{
				LinTp_SetTimer(NT_TM_Bs);
			}
		}break;

		default:
		{
		}break;
	}
}


void LinTp_timeout_cb(void)
{	
	linTp_Reset();
}



void ProtStk_LINTp_Init(void)
{
	linTp_Reset();
	LinTp_PduFifoInit();	
}



void LinTp_task_1ms(void)
{
	LinTp_RxMsgProc();
	LinTp_ProcessTimers();
}



/*this function shall only be called for answering 1002 after jumped from APP*/
void LinTp_Prepare1002Resp(void)
{
	linDiagTxResp.data[0] = 0x50;
	linDiagTxResp.data[1] = 0x02;
	linDiagTxResp.data[2] = 0x00;
	linDiagTxResp.data[3] = 0x32;
	linDiagTxResp.data[4] = 0x01;
	linDiagTxResp.data[5] = 0xf4;  //0xf4

	linDiagTxResp.responseLen = 6;
	linDiagTxResp.sendPos = 0;
	linDiagTxResp.pdServId = 0x10;
	linDiagTxResp.respStatus = LinResp_Ready;
	lintp_state = NTS_APPL_LOCKED;
}




