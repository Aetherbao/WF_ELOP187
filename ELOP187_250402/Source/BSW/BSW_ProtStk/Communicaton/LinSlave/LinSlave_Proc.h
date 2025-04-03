#ifndef LINSLAVE_PROC_H
#define LINSLAVE_PROC_H



#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)  

#include "Platform_Types.h"

extern void LinSlave_PrepareHeaderReception(uint8 HwUnit);
extern void LinSlave_IsrErrorHandler(uint8 HwUnit);
extern void LinSlave_IsrTransmitHandler(uint8  HwUnit);
extern void LinSlave_IsrReceiveHandler(uint8  HwUnit);

#endif

#endif
