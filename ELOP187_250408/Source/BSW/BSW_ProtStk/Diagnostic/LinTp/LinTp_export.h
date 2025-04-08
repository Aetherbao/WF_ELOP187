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

/* ---- Source switch on ------------------------------------------------------*/
#ifndef LINTP_EXPORT_H_
#define LINTP_EXPORT_H_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "LinTp_types.h"


/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      External declaration of global RAM-Variables
------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------
                      External declaration of global ROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                    External declaration of global EEPROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/

extern nt_word_t nt_req_len(void);

extern nt_byte_t nt_req_pop_dt(nt_byte_t def_val);

extern void nt_req_pos_reset(void);

extern void nt_req_pos_set(nt_word_t pos);

extern nt_word_t nt_get_req_pos(void);

extern nt_word_t nt_req_remain_len(void);


extern nt_bool_t nt_req_is_functional_check(void);

extern void nt_unlock(void);


extern nt_bool_t nt_is_locked(void);



extern nt_bool_t nt_is_RequestCompleted(void);


extern void nt_rsp_reset(void);


extern nt_bool_t nt_rsp_push_dt(nt_byte_t val);

extern nt_bool_t nt_rsp_push_buf(nt_byte_t buf[], nt_word_t len);

extern nt_byte_t nt_rsp_get_data(nt_word_t rsp_pos);

extern nt_bool_t nt_rsp_set(nt_byte_t buf[], nt_word_t len);

extern nt_word_t nt_rsp_len(void);

extern nt_word_t nt_rsp_remain_len(void);

extern void nt_rsp_start(void);

extern void uds_rsp_pending(nt_byte_t serv_id);

extern nt_bool_t uds_rsp_is_pending(void);

#endif

