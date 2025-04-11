#ifndef LINIF_GOTOSLEEPINDICATION_H_
#define LINIF_GOTOSLEEPINDICATION_H_



#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)  


#include "ComStack_Types.h"

extern void LinIf_GotoSleepIndication( NetworkHandleType Channel);

#endif

#endif


