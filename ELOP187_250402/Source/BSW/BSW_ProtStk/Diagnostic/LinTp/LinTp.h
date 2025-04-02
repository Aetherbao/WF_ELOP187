#ifndef LINTP_H_
#define LINTP_H_


/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "LinTp_types.h"


/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/
/* PDU (N_PCI + N_Data, not include N_AI) informations */
#define NT_PDU_BUFFER_SIZE   8      /* PDU buffer size define (for CAN, must full 8 bytes) */
#define NT_NAD_POS          0 /* Node address start position in PDU buffer */
#define NT_NPCI_POS          1 /* N_PCI start position in PDU buffer */
#define NT_NPCI_MASK         0xF0u  /* PDU type mask invert mask */
#define NT_NPCI_INV_MASK     0x0Fu

/* N_PCI macros */
#define NT_NPCI_SF           0x00u  /* PDU N_PCI Single Frame */
#define NT_NPCI_FF           0x10u  /* PDU N_PCI First Frame */
#define NT_NPCI_CF           0x20u  /* PDU N_PCI Consecutive Frame */


/* SF macros */
#define NT_SF_MAX_DL         (NT_PDU_BUFFER_SIZE - NT_NPCI_POS - 1)
/* FF macros */
#define NT_FF_MIN_DL         (8 - NT_NPCI_POS)
#define NT_FF_DT_START_POS   (NT_NPCI_POS + 2)
#define NT_FF_DT_LEN         (6 - NT_NPCI_POS)


/* CF macros */
#define NT_CF_DT_START_POS   (NT_NPCI_POS + 1)
#define NT_CF_MAX_DL         (NT_PDU_BUFFER_SIZE - NT_NPCI_POS - 1)






/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/
extern void ProtStk_LINTp_Init(void);
extern void LinTp_task_1ms(void);
extern void LinTp_Prepare1002Resp(void);

#endif

