#ifndef LINIF_GOTOSLEEPCONFIRMATION_H_
#define LINIF_GOTOSLEEPCONFIRMATION_H_



#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)  

#include "ComStack_Types.h"
#include "Platform_Types.h"



extern void LinIf_GotoSleepConfirmation( NetworkHandleType Channel, boolean success);

#endif

#endif


