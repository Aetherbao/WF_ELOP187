/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "SPI_SSC.h"
#include "PosSCD_PosSensor.h"
#include "DIO_Dio.h"
#include "Sys_DMA.h"
#include "wdt1.h"

/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
SRAM_GLOBAL_UINT16 Gu16_PSCD_AngleData_IF;  /* angle data */
SRAM_GLOBAL_UINT16 Gu16_PSCD_SafetyWord_IF; /* fault information*/

// #define RPS_SAFETY_TOUT               10   /* 100mS */
/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/
static void PosSCD_Cmd_Handle(const uint16 Cu16_TxData0, 
                              const uint16 Cu16_TxData1,
                              const uint16 Cu16_TxData2, 
                              const uint8 Cu8_Access);
static void PosSCD_SCDInitConfig(void);
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/*brief : TLE5012B SSC and DMA init
  note  : 
*/
void PosSCD_Init(void)
{
  PosSCD_SCDInitConfig();//not use DMA function this place
  Sys_DMAInit();
}


void PosSCD_Data_Read(void)//500us
{
  SPI_DataTransferStart();
  Delay_us(1);
  SPI_DataTransferDMA();
  Delay_us(3);
  // SchM_AgMech_u16_mp = rbRps_GetData_u16();

  DIO_Set_PinState(DIO_P0_1, DIO_PIN_HIGH);
  Gu16_PSCD_AngleData_IF =  (Gu16_SPI_RxBuffer[SYS_DMA_CFG_DATABYTE-2U] & PSCD_ANGLEMASK); /*get the 0-14 bit angle from the 16 bit buffer */
  Gu16_PSCD_SafetyWord_IF = (Gu16_SPI_RxBuffer[SYS_DMA_CFG_DATABYTE-1U] & PSCD_SAFETY_MASK);

}

/*******************************************************************************
**                         Private Function Definitions                        **
*******************************************************************************/

//use
static void PosSCD_Cmd_Handle(const uint16 Cu16_TxData0, 
                              const uint16 Cu16_TxData1,
                              const uint16 Cu16_TxData2, 
                              const uint8 Cu8_Access)//for init
{   
    SPI_Update_TxBuffer(Cu16_TxData0, Cu16_TxData1, Cu16_TxData2);   //update the RAM tx buffer with data to be sent */
    
	  /*Dio_WriteChannel(RB_RPS_CFG_SLAVESELECTPIN, RB_RPS_CSASSERT);                    //start the communication*/
    DIO_Set_PinState(DIO_P0_1,DIO_PIN_LOW);
	  SPI_SyncTransmit(Cu8_Access);                                    //Calling SPI driver for getting/tranmitting data from/to respective buffer
    /*rbRps_Stop_void ();                                                             //stop the communication*/
    DIO_Set_PinState(DIO_P0_1,DIO_PIN_HIGH);
	  /*Port_SetPinDirection(RB_RPS_CFG_MTSRPORT, PORT_PIN_OUT);                        //Change the MTSR direction to output for TLE5012b*/
    DIO_Set_PinDir(DIO_P0_2,DIO_PIN_OUT);
}

static void PosSCD_SCDInitConfig(void)//use for init
{
    /* Configure the Interface Mod1 register of TLE5012b*/
    /*Configuring for S_NR bit*/
    PosSCD_Cmd_Handle (PSCD_CFG_SNRREAD,PSCD_CFG_TXDATA, PSCD_CFG_TXDATA, PSCD_READACCESS);
    PosSCD_Cmd_Handle (PSCD_CFG_SNRWRITE,PSCD_CFG_SNRDATA, PSCD_CFG_TXDATA, PSCD_WRITEACCESS);

    SPI_Update_TxBuffer (PSCD_CFG_TXDATA1, PSCD_CFG_TXDATA, PSCD_CFG_TXDATA);
}

