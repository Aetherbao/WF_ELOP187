/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Mem_Mem.h"
#include "PosSCD_PosSensor.h"
#include "SPI_SSC.h"

#include "MID_Interface.h"

#include "HSI_SW.h"
#include "Sys_Int.h"

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void Mem_RAMInit(void)
{
  uint8 *u8p_SrcData = (uint8 *)MEM_CHARACT_NVM_START;
  uint8 *u8p_DstData = (uint8 *)MEM_CHARACT_RAM_START;
  uint8 u8_Index=0;

  for (u8_Index=0; u8_Index < MEM_CHARACT_SIZE; u8_Index++)
  {
    u8p_DstData[u8_Index] = u8p_SrcData[u8_Index];
  }
  
  u8p_SrcData = (uint8 *)MEM_RWPRODUCT_NVM_START;
  u8p_DstData = (uint8 *)MEM_RWPRODUCT_RAM_START;
  u8_Index=0;

  for (u8_Index=0; u8_Index < MEM_RWPRODUCT_SIZE; u8_Index++)
  {
    u8p_DstData[u8_Index] = u8p_SrcData[u8_Index];
  }

  Gu16_SPI_TxBuffer[0] = PSCD_CFG_TXDATA1;
  Gu16_SPI_TxBuffer[1] = PSCD_CFG_TXDATA;
  Gu16_SPI_TxBuffer[2] = PSCD_CFG_TXDATA;
	
  Gu16_SPI_RxBuffer[0] = PSCD_CFG_RXDATA;
  Gu16_SPI_RxBuffer[1] = PSCD_CFG_RXDATA;
  Gu16_SPI_RxBuffer[2] = PSCD_CFG_RXDATA;

}

// void Mem_EreaseEeprom(void)//erase product and eeprom
// {
// 	uint8  u8_Index;
// 	uint32 u32_Addr_Tmp;
// 	u8_Index = 0u;
  
//  /* Erase EEPROM */
// 	// for(u8_Index=0;u8_Index<(EEPROM_SIZE/0x80);u8_Index++)
// 	// {
//     u32_Addr_Tmp=MEM_CHARACT_NVM_START+(u8_Index*0x80);
//    (void)USER_ERASEPG((uint32*)u32_Addr_Tmp,0);
// 	// }
// }

void Mem_DataRAM2NVM(ENM_MEM_SECTOR enmMem_Sector)
{
	uint8  u8_NVM_Err;

	u8_NVM_Err=0;//0 :no error

  switch (enmMem_Sector)
  {
  case MEM_CHARACT:
      (void)USER_ERASEPG((uint32*)MEM_CHARACT_NVM_START,0);
      Sys_IntDisIrq();
      u8_NVM_Err = HSI_NVMPage_Write(MEM_CHARACT_NVM_START, (uint8 *)MEM_CHARACT_RAM_START);
      Sys_IntEnIrq();
    break;
  
  case MEM_RWPRODUCTINFO:
      (void)USER_ERASEPG((uint32*)MEM_RWPRODUCT_NVM_START,0);
      Sys_IntDisIrq();
      u8_NVM_Err = HSI_NVMPage_Write(MEM_RWPRODUCT_NVM_START, (uint8 *)MEM_RWPRODUCT_RAM_START);
      Sys_IntEnIrq();
    break;
  
  default:
    break;
  }
}



