#include "LinTp_Timer.h"
#include "LinTp_Cfg.h"

/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/
#define LinTp_TIMER_NOT_RUNNING		(0)

/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/
typedef unsigned short linTpTimer_t;


/*------------------------------------------------------------------------------
                      local RAM-Variables
------------------------------------------------------------------------------*/
static linTpTimer_t linTpTimer_As;
static linTpTimer_t linTpTimer_Bs;
static linTpTimer_t linTpTimer_Cs;
static linTpTimer_t linTpTimer_Cr;


void LinTp_SetTimer(lintp_tmr_t eTimer)
{
    switch (eTimer)
    {
	case NT_TM_As:
		linTpTimer_As = PARAM_NT_TM_As;
		break;

	case NT_TM_Bs:
		linTpTimer_Bs = PARAM_NT_TM_Bs;
		break;

	case NT_TM_Cs:
		linTpTimer_Cs = PARAM_NT_TM_Cs;
		break;

	case NT_TM_Cr:
		linTpTimer_Cr = PARAM_NT_TM_Cr;
		break;
		
        /* this case must not occur */
        default:
            break;
    }
}



void LinTp_CancelTimer(lintp_tmr_t eTimer)
{
    switch (eTimer)
    {
	case NT_TM_As:
		linTpTimer_As = LinTp_TIMER_NOT_RUNNING;
		break;

	case NT_TM_Bs:
		linTpTimer_Bs = LinTp_TIMER_NOT_RUNNING;
		break;

	case NT_TM_Cs:
		linTpTimer_Cs = LinTp_TIMER_NOT_RUNNING;
		break;

	case NT_TM_Cr:
		linTpTimer_Cr = LinTp_TIMER_NOT_RUNNING;
		break;
		
        /* this case must not occur */
        default:
            break;
    }
}



void LinTp_ResetTimer(void)
{
	linTpTimer_As = LinTp_TIMER_NOT_RUNNING;
	linTpTimer_Bs = LinTp_TIMER_NOT_RUNNING;
	linTpTimer_Cs = LinTp_TIMER_NOT_RUNNING;
	linTpTimer_Cr = LinTp_TIMER_NOT_RUNNING;
}


extern void LinTp_timeout_cb(void);
void LinTp_ProcessTimers(void)
{
	if(linTpTimer_As > 0U)
	{
		if(linTpTimer_As == 1U)
		{
			linTpTimer_As = 0U;
			LinTp_timeout_cb();
		}
		else
		{
			linTpTimer_As--;
		}
	}

	if(linTpTimer_Bs > 0U)
	{
		if(linTpTimer_Bs == 1U)
		{
			linTpTimer_Bs = 0U;
			LinTp_timeout_cb();
		}
		else
		{
			linTpTimer_Bs--;
		}
	}

	if(linTpTimer_Cs > 0U)
	{
		if(linTpTimer_Cs == 1U)
		{
			linTpTimer_Cs = 0U;
			LinTp_timeout_cb();
		}
		else
		{
			linTpTimer_Cs--;
		}
	}

	if(linTpTimer_Cr > 0U)
	{
		if(linTpTimer_Cr == 1U)
		{
			linTpTimer_Cr = 0U;
			LinTp_timeout_cb();
		}
		else
		{
			linTpTimer_Cr--;
		}
	}

}



