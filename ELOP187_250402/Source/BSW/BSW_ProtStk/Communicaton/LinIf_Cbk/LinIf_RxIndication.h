#ifndef LINIF_RXINDICATION_H_
#define LINIF_RXINDICATION_H_




//#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF) 

#include "ComStack_Types.h"


extern void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr);
#endif


//#endif
