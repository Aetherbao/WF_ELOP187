#ifndef LINTP_QUEUE_H_
#define LINTP_QUEUE_H_


#include "Std_Types.h"
#include "LinTp_types.h"

extern void LinTp_PduFifoInit(void);
extern Std_ReturnType  LinTp_PduFifoInc(linPduRefType pIn);
extern Std_ReturnType  LinTp_PduFifoGetOne(linPduRefType * pOut);


#endif


