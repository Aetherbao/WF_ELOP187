/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "tle987x.h"
#include "HSI_SW.h"
#include "tle_device.h"
#include "Sys_DMA.h"
#include "bootrom.h"
#include "ADC_Meas.h"
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
void HSI_SPI_SendWord(uint16 u16_DataWord)
{
  Field_Wrt16(&SSC1->TB.reg, (uint16)SSC1_TB_TB_VALUE_Pos, (uint16)SSC1_TB_TB_VALUE_Msk, u16_DataWord);
}

uint8 HSI_SPI_RxIntCheck(void)
{
  uint8 u8_Ret=0u;
  if ((uint8)1 == (uint8)SCU->IRCON1.bit.RIR)
  {
    u8_Ret=1u;
  }
  else
  {
    u8_Ret=0u;
  }
  return(u8_Ret);
}

void HSI_DMA_TxRxSrcSelect_SSC1(void)
{
	SCU->DMASRCSEL.bit.SSCRXSRCSEL=0;
	SCU->DMASRCSEL.bit.SSCTXSRCSEL=0;
}

void HSI_DMA_TxRxChannelEnable(void)
{
  DMA->CHNL_ENABLE_SET.reg = (0x000CU);
}


void HSI_TIMER21_ReInit500us(void)
{

  TIMER21->RC2H.reg = (uint8) 0xF9u;
  TIMER21->RC2L.reg = (uint8) 0x7Du;
  TIMER21->T2H.reg = (uint8) TIMER21_T2H;
  TIMER21->T2L.reg = (uint8) TIMER21_T2L;
  TIMER21->T2MOD.reg = (uint8) TIMER21_T2MOD;
  TIMER21->T2CON.reg = (uint8) TIMER21_T2CON;
  TIMER21->T2CON1.reg = (uint8) TIMER21_T2CON1;
}

void HSI_TIMER21_ReInit10us(void)
{
  TIMER21->RC2H.reg = (uint8) TIMER21_RC2H;
  TIMER21->RC2L.reg = (uint8) TIMER21_RC2L;
  TIMER21->T2H.reg = (uint8) TIMER21_T2H;
  TIMER21->T2L.reg = (uint8) TIMER21_T2L;
  TIMER21->T2MOD.reg = (uint8) TIMER21_T2MOD;
  TIMER21->T2CON.reg = (uint8) TIMER21_T2CON;
  TIMER21->T2CON1.reg = (uint8) TIMER21_T2CON1;
}

void IntMon_SupplyPrewarning_IRQHandler(void)
{

    /* Check VDDC and VDDP overvoltage  */
    if(SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD1V5_OV_IS == 1)
    {
      Gu8_DIAG_VDD_1V5OV=1;
    }
	
    if(SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD5V_OV_IS == 1)
    {
      Gu8_DIAG_VDD_5VOV=1;
    }

    /* Check VDDC and VDDP Overload   */
    if(PMU->PMU_SUPPLY_STS.bit.PMU_1V5_OVERLOAD == 1)
    {
      // Gu8_DIAG_PMU_1V5OverLoad=1;
      while(1);
    }
			
    if(PMU->PMU_SUPPLY_STS.bit.PMU_5V_OVERLOAD == 1)
    {
      // Gu8_DIAG_PMU_5VOverLoad=1;
      while(1);
    }

    /* Clear all status IRQ status flags */
    SCUPM->SYS_SUPPLY_IRQ_CLR.reg |= (uint32) 0xFFFFFFFF;
}

void HSI_RunbootCode(void)
{
  uint32 JumpAddress;
  uint32 APPLICATION_ADDRESS;

	APPLICATION_ADDRESS = 0x0;      
	INT_Disable_Global_Int();
	(void)WDT1_Service();
	WDT1_SOW_Service(3);

	CPU->VTOR.reg = APPLICATION_ADDRESS;
  
	JumpAddress = *(__IO uint32*) (APPLICATION_ADDRESS+4);
	__set_MSP(*(__IO uint32*) APPLICATION_ADDRESS);
	((void(*)(void))JumpAddress)();
}


uint8 HSI_DIAG_Get_VSUV_State(void)
{
  uint8 u8_RetState=0;
  u8_RetState = u8_Field_Rd32(&SCUPM->SYS_SUPPLY_IRQ_STS.reg, 
                              SCUPM_SYS_SUPPLY_IRQ_STS_VS_UV_IS_Pos, 
                              SCUPM_SYS_SUPPLY_IRQ_STS_VS_UV_IS_Msk);

  return(u8_RetState);
}

uint8 HSI_DIAG_Get_VSOV_State(void)
{
  uint8 u8_RetState=0;
  u8_RetState = u8_Field_Rd32(&SCUPM->SYS_SUPPLY_IRQ_STS.reg, 
                              SCUPM_SYS_SUPPLY_IRQ_STS_VS_OV_IS_Pos, 
                              SCUPM_SYS_SUPPLY_IRQ_STS_VS_OV_IS_Msk);

  return(u8_RetState);
}

uint8 HSI_DIAG_Get_VCPLO1_State(void)
{
  uint8 u8_RetState=0;
  u8_RetState = u1_Field_Rd32(&SCUPM->BDRV_IS.reg, 
                              SCUPM_BDRV_IS_VCP_LOWTH1_IS_Pos, 
                              SCUPM_BDRV_IS_VCP_LOWTH1_IS_Msk);
  return(u8_RetState);
}

uint8 HSI_DIAG_Get_VSDLO_State(void)
{
  uint8 u8_RetState=0;
  u8_RetState = u1_Field_Rd32(&SCUPM->BDRV_IS.reg, 
                              SCUPM_BDRV_IS_VSD_LOWTH_IS_Pos, 
                              SCUPM_BDRV_IS_VSD_LOWTH_IS_Msk);
  return(u8_RetState);
}

uint8 HSI_DIAG_Get_VSDUP_State(void)
{
  uint8 u8_RetState=0;
  u8_RetState = u1_Field_Rd32(&SCUPM->BDRV_IS.reg, 
                              SCUPM_BDRV_IS_VSD_UPTH_IS_Pos, 
                              SCUPM_BDRV_IS_VSD_UPTH_IS_Msk);
  return(u8_RetState);
}

void HSI_Init(void)
{
#ifdef RTE_DEVICE_SDK_SCU
  SCU_Init();
#endif
#ifdef RTE_DEVICE_SDK_PMU
  PMU_Init();
#endif
#ifdef RTE_DEVICE_SDK_ADC1
  ADC1_Init();
#endif
#ifdef RTE_DEVICE_SDK_ADC2
  ADC2_Init();
#endif
/*System Interrupt Status Clear*/
SCUPM->SYS_ISCLR.reg = (uint32)0xFFFFFFFF;
/*System Supply Interrupt Status Clear*/
SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)0xFFFFFFFF;	
ADC_BattStable_Protection();	

// #ifdef RTE_DEVICE_SDK_ADC34
//   SDADC_Init();
// #endif
// #ifdef RTE_DEVICE_SDK_BDRV
//   BDRV_Init();
// #endif
// /* Clear existing BDRV interrupt status */
//   SCUPM->BDRV_ISCLR.reg = (uint32)0xFFFFFFFF;		
#ifdef RTE_DEVICE_SDK_CCU6
  CCU6_Init();
#endif
#ifdef RTE_DEVICE_SDK_CSA
  CSA_Init();
#endif
#ifdef RTE_DEVICE_SDK_GPT12E
  GPT12E_Init();
#endif
#ifdef RTE_DEVICE_SDK_LIN
  LIN_Init();
#endif
#ifdef RTE_DEVICE_SDK_MON
  MON_Init();
#endif
#ifdef RTE_DEVICE_SDK_SSC
  SSC1_Init();
  // SSC2_Init();
#endif
#ifdef RTE_DEVICE_SDK_TIMER2X
  TIMER2_Init();
  TIMER21_Init();
#endif
#ifdef RTE_DEVICE_SDK_TIMER3
  TIMER3_Init();
#endif
#ifdef RTE_DEVICE_SDK_UART
  UART1_Init();
  UART2_Init();
#endif
#ifdef RTE_DEVICE_SDK_DMA
  DMA_Init();
#endif
#ifdef RTE_DEVICE_SDK_PORT
  PORT_Init();
#endif
#ifdef RTE_DEVICE_SDK_INT
  INT_Init();
#endif
}

void HSI_DmaBasePtrConfig(void)
{
  DMA->CTRL_BASE_PTR.reg = SYS_DMA_CFG_STARTADDRESS;
}

/**
 * u8_Ret 0-success 1-fail
*/
uint8 HSI_NVMPage_Write(uint32 u32_TargetAddress,uint8 * u8p_SourceAddressPtr)
{
  uint8 u8_Ret=0xFF;

  u8_Ret = ProgramPage(u32_TargetAddress, (uint8 *)u8p_SourceAddressPtr, 0, 0, 0);//

  if ((uint8)0 != u8_Ret)
  {
    u8_Ret = 1u;
  }
  else
  {
    ;
  }
  
  return(u8_Ret);
}

void HSI_VREF_Fault_Check(void)
{
	if (SCUPM->SYS_IS.bit.VREF5V_UPTH_IS == 1u)
	{
	  	SCUPM->SYS_ISCLR.bit.VREF5V_UPTH_ICLR = 1u;
			while(1);
	}

	if (SCUPM->SYS_IS.bit.VREF5V_LOWTH_IS == 1u)
	{
		  SCUPM->SYS_ISCLR.bit.VREF5V_LOWTH_ICLR = 1u;
			while(1);
	}
	
	if (SCUPM->SYS_IS.bit.VREF5V_OVL_IS == 1u)
	{
		  SCUPM->SYS_ISCLR.bit.VREF5V_OVL_ICLR = 1u;
			while(1);
	}

}
