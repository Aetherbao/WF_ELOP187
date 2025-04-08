/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "DIO_Dio.h"

void DIO_Set_PinState(uint32 u32_Port, uint32 u32_State)
{
    switch (u32_Port)
    {
    case DIO_P0_1:
        PORT_ChangePin(DIO_P0_1, u32_State);
        break;
    default:
        break;
    }
}

void DIO_Set_PinDir(uint32 u32_Port, uint32 u32_Dir)
{
    switch (u32_Port)
    {
    case DIO_P0_2:
        PORT_ChangePin(DIO_P0_2, u32_Dir);
        break;
    default:
        break;
    }
}
