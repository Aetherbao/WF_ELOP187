#ifndef LINIF_HEADERINDICATION_H_
#define LINIF_HEADERINDICATION_H_




//#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)  
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"



extern Std_ReturnType LinIf_HeaderIndication( NetworkHandleType Channel, Lin_PduType* PduPtr );
#endif

//#endif
