#ifndef LINTP_CBK_H_
#define  LINTP_CBK_H_

#include "ComStack_Types.h"

extern void LinTp_LinIfRxIndication(const PduInfoType * ptr);
extern void LinTp_LinIfTriggerTransmit(PduInfoType * ptr);
extern void LinTp_LinIfTxConfirmation(void);




#endif

