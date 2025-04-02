/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "SPI_SSC.h"
#include "DIO_Dio.h"
#include "HSI_SW.h"

#include "Sys_SCU.h"
#include "PosSCD_PosSensor.h"

typedef enum
{
    SPI_SEQ_OK, 
    SPI_SEQ_PENDING
} ENM_SPI_SEQRESULT_TYPE;


/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
SRAM_GLOBAL_UINT16 Gu16_SPI_TxBuffer[SYS_DMA_CFG_DATABYTE]; /*SPI send data array*/
SRAM_GLOBAL_UINT16 Gu16_SPI_RxBuffer[SYS_DMA_CFG_DATABYTE]; /*SPI receive data array*/

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/
static SRAM_GLOBAL_UINT8 Su8_RxBufIdx;        /*SPI receive data count*/

static SRAM_GLOBAL ENM_SPI_SEQRESULT_TYPE SenmSPI_SeqState; /*SPI send data status*/
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
/*----------------------------------------------------------------------------
! This function transmits and receive data on SPI bus   
!	
! pre
! rbSpi_PrvSrcBufPtrs_pu16 should have data
!
! post 
! Updates the rbSpi_PrvTarBufPtrs_u16 with receive data and updates
! current status of communication 
!
! return: void
----------------------------------------------------------------------------*/
void SPI_SyncTransmit(const uint8 Cu8_Access)//use for init
{
    // SSC1_AsyncTransmit(0);   /*Assign TB buffer with data and set the status ��SSC1_PrvSeqSts_aen[SSC1_Sequence_u8] = SPI_SEQ_PENDING;*/

    HSI_SPI_SendWord(Gu16_SPI_TxBuffer[0]);
    Su8_RxBufIdx = 0;
    SenmSPI_SeqState = SPI_SEQ_PENDING;

    while (SenmSPI_SeqState != SPI_SEQ_OK)
    {
        SPI_DtTxHandle(Cu8_Access);    /*SenmSPI_SeqState[RB_SPI_SEQUENCE0] = SPI_SEQ_OK;*/
    }
}

//use
void SPI_Update_TxBuffer(const uint16 Cu16_TxData0, const uint16 Cu16_TxData1,const uint16 Cu16_TxData2)//for init
{
    Gu16_SPI_TxBuffer[0] = Cu16_TxData0;
    Gu16_SPI_TxBuffer[1] = Cu16_TxData1;
    Gu16_SPI_TxBuffer[2] = Cu16_TxData2;
}

//use
void SPI_DtTxHandle(uint8 u8_Access)//for init
{
    uint8 u8_RxInt=HSI_SPI_RxIntCheck();
    if(1u == u8_RxInt)
    {
        if (Su8_RxBufIdx < 2u)
        {
            /* Read the next byte from receive register, fill it to receive buffer */
            Gu16_SPI_RxBuffer[Su8_RxBufIdx++] = SSC1_ReadWord();//SSC1_PrvTarBufPtrs_pu16

            Sys_SCU_ClrRxInt(); /* Clear Interrupt Flag */

            if((u8_Access == PSCD_READACCESS) && (1u == Su8_RxBufIdx))
            {
                /*Port_SetPinDirection(RB_RPS_CFG_MTSRPORT, PORT_PIN_IN); */
                DIO_Set_PinDir(DIO_P0_2,DIO_PIN_IN);
            }
            else
            {
                ;
            }

            /* Send the next byte of the transmit buffer */
            HSI_SPI_SendWord(Gu16_SPI_TxBuffer[Su8_RxBufIdx]);//  SSC1_PrvSrcBufPtrs_pu16
            /* Increment buffer index */
        }
        else
        {
            /* Read last byte from the receive buffer */
            Gu16_SPI_RxBuffer[Su8_RxBufIdx++] = SSC1_ReadWord();//SSC1_PrvTarBufPtrs_pu16
            Sys_SCU_ClrRxInt(); /* Clear Interrupt Flag */
            SenmSPI_SeqState = SPI_SEQ_OK;
        }
    }
    else
    {
        ;
    }
}

/*----------------------------------------------------------------------------
//! This function continues DMA transfer by re-initializing
//! the RX and TX channels for DMA when N_Minus_1 transfers have
//! been completed.
//!
//!
//! pre
//! N_Minus_1 of DMA channel should be 0, and DMA stops tranfer.
//! 
//! post
//! DMA starts memory to peripheral transfer once N_Minus_1 is initialised
//! other than 0.��TASK(SchM_Task_500us)����,SPI���ݷ���2/2
//! ���жϱ�־λ�������ռĴ�������MTSR���Ÿ�Ϊ���룬���³�ʼ��DMA�շ�Դ��ַ�����ֽ������ڵȣ�ʹ��ͨ����ʹ��DMA
//! return: NA  usethis  
----------------------------------------------------------------------------*/
void SPI_DataTransferDMA(void)//use
{
    uint8 u8_RxInt=HSI_SPI_RxIntCheck();
    if(1u != u8_RxInt)
    {
        // return(0);/*FALSE=0*/
        ;
    }
    else
    {
        Sys_SCU_ClrRxInt();                              /* Clear Interrupt Flag                             */
        Gu16_SPI_RxBuffer[0] = SSC1_ReadWord();        /* Load Rps Rx buffer 1st location with SSC Rx data */
        /*Port_SetPinDirection(RB_RPS_CFG_MTSRPORT, PORT_PIN_IN);    Set MTSR Port pin as input���������Խ������ŵ�Ӱ�� */      
        DIO_Set_PinDir(DIO_P0_2,DIO_PIN_IN);
        Sys_DMAResetChannel();
        // return(1);
    }
}

/*----------------------------------------------------------------------------
//! This function continues DMA transfer by re-initializing
//! the RX and TX channels for DMA when N_Minus_1 transfers have
//! been completed.
//!
//!
//! pre
//! N_Minus_1 of DMA channel should be 0, and DMA stops tranfer.
//! 
//! post
//! DMA starts memory to peripheral transfer once N_Minus_1 is initialised
//! other than 0.��TASK(SchM_Task_500us)����  SPI���ݷ���1/2
//! Ƭѡ����MTSR���Ÿ�Ϊ��������жϱ�־λ�������ͼĴ���װ������,�����������齻��DMA������
//! return: NA
//----------------------------------------------------------------------------*/
void SPI_DataTransferStart(void)//use
{
    /*Dio_WriteChannel(RB_RPS_CFG_SLAVESELECTPIN,RB_RPS_CSASSERT);    Assert the CS pin and start the communication */
    DIO_Set_PinState(DIO_P0_1,DIO_PIN_LOW);
	  /*Port_SetPinDirection(RB_RPS_CFG_MTSRPORT, PORT_PIN_OUT);         re-configuring MTSR pin as output for next cycle of getting angle data */ 
    // PORT->P0_DIR.bit.P2 = 1;
    DIO_Set_PinDir(DIO_P0_2,DIO_PIN_OUT);
	Sys_SCU_ClrRxInt();                                    /* Clear Interrupt Flag                             */          
    /* Load SSC Tx buffer with Rps Tx buffer 1st data   Gu16_SPI_TxBuffer[0] is PSCD_CFG_TXDATA1 for angle command*/
    HSI_SPI_SendWord(Gu16_SPI_TxBuffer[0]);
}


/*******************************************************************************
**                         Private Function Definitions                        **
*******************************************************************************/


