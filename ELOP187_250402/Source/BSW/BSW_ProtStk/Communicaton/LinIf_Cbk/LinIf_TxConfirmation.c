#include "LinIf_Cfg.h"
#include "LinIf_TxConfirmation.h"
#include "LinTp_Cbk.h"


//#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)
void LinIf_TxConfirmation( NetworkHandleType Channel)
{
	LinTp_LinIfTxConfirmation();
}


//#endif


