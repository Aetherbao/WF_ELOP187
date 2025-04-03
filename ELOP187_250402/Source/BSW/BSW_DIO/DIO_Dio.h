#ifndef DIO_DIO_H
#define DIO_DIO_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "port.h"
/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
#define DIO_P0_1  ((uint32)0x01)
#define DIO_P0_2  ((uint32)0x02)
#define DIO_PIN_HIGH    (PORT_ACTION_SET)
#define DIO_PIN_LOW     (PORT_ACTION_CLEAR)
#define DIO_PIN_OUT     (PORT_ACTION_OUTPUT)
#define DIO_PIN_IN      (PORT_ACTION_INPUT)
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void DIO_Set_PinState(uint32 u32_Port, uint32 u32_State);
void DIO_Set_PinDir(uint32 u32_Port, uint32 u32_Dir);

#endif
