/*
* Copyright (c) File 2016-08-11,SHENZHEN HANGSHENG NEW ENERGY Co.,Ltd.
* All Rights Reserved.
* Dept.: Software Department
* File:p
* Description: 
* REQ IDs: 
* History:
* 2017-12-25
*/


/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "LinTp_export.h"
#include "LinTp_SchM.h"


/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------
                      External declaration of global RAM-Variables
------------------------------------------------------------------------------*/
extern lintp_state_t 		lintp_state;
extern nt_bool_t 		lintp_functional_req;
extern linDiagReq_Rx_t  linDiagRxReq;
extern linDiagResp_Tx_t linDiagTxResp;


/*------------------------------------------------------------------------------
                      External declaration of global ROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                    External declaration of global EEPROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/
extern void linTp_Reset(void);

/*
 * Function:nt_req_len
 * Param<void>:
 * Return<nt_word_t>: The total received request length.
 * REQ IDs:
 * Discription:
 * Note: 
*/
nt_word_t nt_req_len(void)
{
    return linDiagRxReq.requestLen; /* return received data length */
}


/*
 * Function:nt_req_read
 * Param<nt_byte_t def_val>: Default value when no more data
 * Return<nt_byte_t>: The current pop data of received buffer. if no more data, will return def_val
 * REQ IDs:
 * Discription:
 * Note: 
*/
nt_byte_t nt_req_pop_dt(nt_byte_t def_val)
{
    nt_byte_t data = def_val; /* preset return value to default value */

    if (NTS_APPL_LOCKED == lintp_state) /* <-- Jason 20160602, add conditon. Forbide read data when received request by NT layer */
    {
        /* check receive buffer */
        if (linDiagRxReq.rcvdPos < linDiagRxReq.requestLen)
        {
            /* have data can be pop */
            data = linDiagRxReq.data[linDiagRxReq.rcvdPos++]; /* set return value */            
        }
    }
    
    return data;
}

/*
 * Function:nt_req_pos_reset
 * Param<void>:
 * Return<void>:
 * REQ IDs:
 * Discription: reset request pop data position for read received data from position 0
 * Note: This function only actived when receive buffer was be locked by upper layer
*/
void nt_req_pos_reset(void)
{
    /* check NT state */
    if (NTS_APPL_LOCKED == lintp_state)
    {
        /* NT in application locked buffer status */
        linDiagRxReq.rcvdPos = 0; /* reset pop position */
    }
}

/*
 * Function:nt_req_pos_set
 * Param<nt_word_t pos>: The pop point position for read received data
 * Return<void>:
 * REQ IDs:
 * Discription: set request pop data position for read received data
 * Note: This function only actived when receive buffer was be locked by upper layer
*/
void nt_req_pos_set(nt_word_t pos)
{
    /* check NT state */
    if (NTS_APPL_LOCKED == lintp_state)
    {
        /* NT in application locked buffer status */
        linDiagRxReq.rcvdPos = pos; /* set pop position */
    }
}

/*
 * Function:nt_get_req_pos
 * Param<void>:
 * Return<nt_word_t>: current receive position
 * REQ IDs:
 * Discription: get current receive buffer point position
 * Note: 
*/
nt_word_t nt_get_req_pos(void)
{
    return linDiagRxReq.rcvdPos;
}

/*
 * Function:nt_req_remain_len
 * Param<void>:
 * Return<nt_word_t>: request data (received buffer) remain pop data length
 * REQ IDs:
 * Discription:
 * Note: 
*/
nt_word_t nt_req_remain_len(void)
{
    nt_word_t remain_len = 0;

    /* check remain length */
    if (linDiagRxReq.requestLen > linDiagRxReq.rcvdPos)
    {
        /* received Dl above current pop position */
        remain_len = (nt_word_t)(linDiagRxReq.requestLen - linDiagRxReq.rcvdPos); /* get remain pop length */
    }
    
    return remain_len;
}

nt_bool_t nt_req_is_functional_check(void)
{
	return lintp_functional_req;
}

/*
 * Function:nt_unlock
 * Param<void>:
 * Return<void>:
 * REQ IDs:
 * Discription: for upper layer unlock the NT receive buffer
 * Note: 
*/
void nt_unlock(void)
{
    /* NT state check */
    if (NTS_APPL_LOCKED == lintp_state)
    {
        /* in application locked state */
        linTp_Reset(); /* reset NT */
    }
}

/*
 * Function:nt_is_locked
 * Param<void>:
 * Return<nt_bool_t>: NT unlock state. TRUE for is locked, FALSE for is unlock
 * Discription:
 * Note: 
*/
nt_bool_t nt_is_locked(void)
{
    return (nt_bool_t)(NTS_APPL_LOCKED == lintp_state);
}




nt_bool_t nt_is_RequestCompleted(void)
{	
	LINTP_ENTER_CRITICAL();
	
	if(linDiagRxReq.reqStatus == LinReq_Ready)
	{
		linDiagRxReq.reqStatus = LinReq_NotReady;
		LINTP_EXIT_CRITICAL();
		return TRUE;
	}
	LINTP_EXIT_CRITICAL();
	return FALSE;	
}






#if 0
void  nt_CopyTxData(uint8  buf[], uint16 len)
{
	uint16 loop_i;
	
	if(nt_is_locked())
	{
		LINTP_ENTER_CRITICAL();
		for(loop_i=0; loop_i<len; loop_i++)
		{
			linDiagTxResp.data[loop_i] = buf[loop_i];
		}

		linDiagTxResp.responseLen = len;
		linDiagTxResp.respStatus = LinResp_Ready;

		lintp_state = NTS_RSP_READY;
		LINTP_EXIT_CRITICAL();
	}
}
#endif


/*
 * Function:nt_rsp_reset
 * Param<void>:
 * Return<void>:
 * REQ IDs:
 * Discription: reset send buffer (clear all push datas)
 * Note: 
*/
void nt_rsp_reset(void)
{
    LINTP_ENTER_CRITICAL();
	linDiagTxResp.respStatus = LinResp_NotReady;
	linDiagTxResp.responseLen = 0;
	linDiagTxResp.sendPos = 0;	
	LINTP_EXIT_CRITICAL();
}


/*
 * Function:nt_rsp_push_dt
 * Param<nt_byte_t val>: the data value (byte) need push to response (send) buffer
 * Return<nt_bool_t>: push result, TRUE: push success, FALSE: push fail, the buffer is full
 * REQ IDs:
 * Discription:
 * Note: This function will auto clear all push data if push fail (buffer full)
*/
nt_bool_t nt_rsp_push_dt(nt_byte_t val)
{
    nt_bool_t rst = FALSE; /* pre-set push result to FALSE */

    /* buffer full check */
    if (linDiagTxResp.sendPos < linDiagTxResp.bufSize)
    {
        /* not full, can push at least 1 byte */
        linDiagTxResp.data[linDiagTxResp.sendPos] = val; /* set value */
        linDiagTxResp.sendPos++; /* push position inc 1 */
        rst = TRUE; /* set push result to TRUE */
    }

    return rst; /* return push result */
}

/*
 * Function:nt_rsp_push_buf
 * Param<nt_byte_t buf[]>: the buffer need push to response (send) buffer
 * Param<nt_word_t len>: push data length
 * Return<nt_bool_t>: push result, TRUE: push success, FALSE: push fail, the send buffer can not push so many datas
 * REQ IDs:
 * Discription:
 * Note: This function will auto clear all push data if push fail (buffer not enough)
*/
nt_bool_t nt_rsp_push_buf(nt_byte_t buf[], nt_word_t len)
{
    nt_word_t index; /* push data buffer index */
    nt_bool_t rst = FALSE; /* push result, pre-set push fail (FALSE) */

    /* buffer remain size enough check */
    if ((linDiagTxResp.bufSize - linDiagTxResp.sendPos) > len)
    {
        /* buffer enough, push data to buffer */
        for (index = 0; index < len; index++)
        {
            linDiagTxResp.data[linDiagTxResp.sendPos] = buf[index];
            linDiagTxResp.sendPos++;
        }
        /* push success */
        rst = TRUE;
    }
    
    return rst;
}

/*
 * Function: nt_rsp_get_data
 * Param<nt_word_t rsp_pos>: The data position of send buffer for read
 * Return<nt_byte_t>: The data of send buffer by rsp_pos point.
 * Discription: 
 * Note: If out of buffer or push data range, return zero
*/
nt_byte_t nt_rsp_get_data(nt_word_t rsp_pos)
{
    if ((linDiagTxResp.bufSize > rsp_pos) && (rsp_pos < linDiagTxResp.sendPos))
    {
        return linDiagTxResp.data[rsp_pos];
    }
    else
    {
        return (nt_byte_t)(0u);
    }
}


/*
 * Function:nt_rsp_set
 * Param<nt_byte_t buf[]>: buffer need set to response (send) buffer.
 * Param<nt_word_t len>: buffer length
 * Return<nt_bool_t>: push result, TRUE: push success, FALSE: push fail, the set buffer length above send buffer length
 * REQ IDs:
 * Discription: Push a buffer to response(send) buffer from position 0
 * Note: This function will auto clear all push data if push fail (buffer not enough)
*/
nt_bool_t nt_rsp_set(nt_byte_t buf[], nt_word_t len)
{
    nt_bool_t rst = FALSE; /* push result, pre-set push fail (FALSE) */

    /* set buffer length not zero check and send buffer enough check */
    if (len > 0 && linDiagTxResp.bufSize >= len)
    {
        /* set buffer to send buffer */
        for (linDiagTxResp.sendPos = 0; linDiagTxResp.sendPos < len; linDiagTxResp.sendPos++)
        {
            linDiagTxResp.data[linDiagTxResp.sendPos] = buf[linDiagTxResp.sendPos];
        }
        /* set success */
        rst = TRUE;
    }
    else
    {
        /* buffer not enough to push so many datas, clear all push data (take as an error) */
        linDiagTxResp.sendPos = 0; /* set posh position to 0 for clear all data */
    }
    
    return rst;
}

/*
 * Function:nt_rsp_len
 * Param<void>:
 * Return<nt_word_t>: current push buffer length to response (send) buffer
 * REQ IDs:
 * Discription: Get the current response buffer length
 * Note: It is current push position also
*/
nt_word_t nt_rsp_len(void)
{
    return linDiagTxResp.sendPos;
}

/*
 * Function:nt_rsp_remain_len
 * Param<void>:
 * Return<nt_word_t>: send buffer remain length for push
 * REQ IDs:
 * Discription:
 * Note: 
*/
nt_word_t nt_rsp_remain_len(void)
{
    return (nt_word_t)((nt_word_t)linDiagTxResp.bufSize - linDiagTxResp.sendPos);
}



/*
 * Function:nt_rsp_start
 * Param<void>:
 * Return<void>:
 * REQ IDs:
 * Discription: start send response
 * Note: 
*/
void nt_rsp_start(void)
{
	LINTP_ENTER_CRITICAL();	
	linDiagTxResp.responseLen = linDiagTxResp.sendPos;
	linDiagTxResp.sendPos = 0;	
	linDiagTxResp.respStatus = LinResp_Ready;
	LINTP_EXIT_CRITICAL();
}

/*
 * Function:uds_rsp_pending
 * Param<nt_byte_t serv_id>: service ID of notice response pending message
 * Return<void>:
 * REQ IDs:
 * Discription: UDS notice response sending
 * Note: This function only send UDS respnose pending negtive code when NT in application locked buffer state
*/
void uds_rsp_pending(nt_byte_t serv_id)
{
	LINTP_ENTER_CRITICAL();	
	linDiagTxResp.pdServId = serv_id;
	LINTP_EXIT_CRITICAL();
}

nt_bool_t uds_rsp_is_pending(void)
{
    return (linDiagTxResp.respStatus == LinResp_Ready);
}

