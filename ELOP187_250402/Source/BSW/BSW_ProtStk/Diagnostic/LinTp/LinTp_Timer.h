#ifndef LINTP_TIMER_H_
#define LINTP_TIMER_H_


/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/
typedef enum
{
    NT_TM_IDLE = 0, /* No timeout tick running */
    /* As sender transmit frame timeout timer, used only when need send success indication */
    NT_TM_As,   /* Timeout for the msg confirmation while sending msg */
    NT_TM_Bs,   /* Timeout for wait Lin master send the frame header while transmit response */
    NT_TM_Cs,  /* Time delay for send next CF while transmit response for sender */
    NT_TM_Cr  /* Timeout for wait segmented CF (Consecutive frame) while receive request for receiver */
}lintp_tmr_t;




extern void LinTp_SetTimer(lintp_tmr_t eTimer);
extern void LinTp_CancelTimer(lintp_tmr_t eTimer);
extern void LinTp_ResetTimer(void);
extern void LinTp_ProcessTimers(void);






#endif

