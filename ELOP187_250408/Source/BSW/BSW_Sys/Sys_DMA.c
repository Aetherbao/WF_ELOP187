/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "Sys_DMA.h"
#include "HSI_SW.h"
#include "SPI_SSC.h"

#define SYS_DMA_CFG_TLE9879xDMAREQ   (13u)
/*Hardware DMA request channel*/
#define SYS_DMA_TX_CHANNEL            (2u)
#define SYS_DMA_RX_CHANNEL            (3u)

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/
static SRAM_DMA TDMA_Entry SstSys_DMA_Handle[SYS_DMA_CFG_TLE9879xDMAREQ];//16*13=208byte
/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void Sys_DMAInit(void)//use
{
	uint8 u8_Channel;

	HSI_DMA_TxRxSrcSelect_SSC1();
	
	SstSys_DMA_Handle[SYS_DMA_TX_CHANNEL].Dst_End_Ptr = (uint32)&DMA_CH2_DST;/*Ŀ��˵�ַΪ���ͼĴ���*/
	SstSys_DMA_Handle[SYS_DMA_RX_CHANNEL].Src_End_Ptr = (uint32)&DMA_CH3_SRC;/*Դ�˵�ַΪ���ռĴ���*/
		
	
	/* DMA for TX Channel */	
	SstSys_DMA_Handle[SYS_DMA_TX_CHANNEL].Src_End_Ptr = (uint32)&Gu16_SPI_TxBuffer[SYS_DMA_CFG_DATABYTE - 1U];   /* Source data end pointer        */
	SstSys_DMA_Handle[SYS_DMA_TX_CHANNEL].Control.bit.Src_Inc = (1U);                                     /* address increment halfword     */
	SstSys_DMA_Handle[SYS_DMA_TX_CHANNEL].Control.bit.Dst_Inc = (3U);                                 /* Dont increment the destination */
			
	/* DMA for RX Channel */	
	SstSys_DMA_Handle[SYS_DMA_RX_CHANNEL].Dst_End_Ptr = (uint32)&Gu16_SPI_RxBuffer[SYS_DMA_CFG_DATABYTE - 1U]; /* Destination Data End Pointer   */
	SstSys_DMA_Handle[SYS_DMA_RX_CHANNEL].Control.bit.Src_Inc = (3U);												     /* Dont increment the source      */
	SstSys_DMA_Handle[SYS_DMA_RX_CHANNEL].Control.bit.Dst_Inc = (1U);														     /* address increment halfword     */
	
	for(u8_Channel = SYS_DMA_TX_CHANNEL; u8_Channel < (SYS_DMA_RX_CHANNEL + 1U); u8_Channel++)
	{
    	SstSys_DMA_Handle[u8_Channel].Control.bit.N_Minus_1 = (u8_Channel-(uint8)1U);       /* number of DMA transfer         */
		SstSys_DMA_Handle[u8_Channel].Control.bit.Cycle_Ctrl = (1U);												     /* Basic                          */
		SstSys_DMA_Handle[u8_Channel].Control.bit.Next_UseBurst = (0U);	                 /*DMA UserBurst*/		  		     /* Channel useburst               */ 
		SstSys_DMA_Handle[u8_Channel].Control.bit.R_Power = (0U);                        /*DMA R_Power Arbitrates*/                         		     /* Arbitrates after each DMA Trans CONFIRM                  */
		SstSys_DMA_Handle[u8_Channel].Control.bit.Src_Prot_Ctrl = (7U);              		       /* HPROT for controller = privileged, bufferable, cacheable */
		SstSys_DMA_Handle[u8_Channel].Control.bit.Dst_Prot_Ctrl = (7U);             		       /* HPROT for controller = privileged, bufferable, cacheable */
		SstSys_DMA_Handle[u8_Channel].Control.bit.Src_Size = (1U);                         	       /* size of source data = 16bit                              */
		SstSys_DMA_Handle[u8_Channel].Control.bit.Dst_Size = (1U);														     /* size of destination 16 bits                              */
	}
	HSI_DmaBasePtrConfig();
}

void Sys_DMAResetChannel(void)//use
{
	
	/* Re-initialize the TX and RX SSC Channels of DMA */
	/* This code is time critical, so we removed the cycle "for" */
	SstSys_DMA_Handle[SYS_DMA_TX_CHANNEL].Src_End_Ptr = (uint32)&Gu16_SPI_TxBuffer[SYS_DMA_CFG_DATABYTE - 1U];   /* Source data end pointer        */
	SstSys_DMA_Handle[SYS_DMA_RX_CHANNEL].Dst_End_Ptr = (uint32)&Gu16_SPI_RxBuffer[SYS_DMA_CFG_DATABYTE - 1U]; /* Destination Data End Pointer   */

	SstSys_DMA_Handle[SYS_DMA_TX_CHANNEL].Control.bit.N_Minus_1 = (SYS_DMA_TX_CHANNEL-(uint8_t)1U); 
	SstSys_DMA_Handle[SYS_DMA_TX_CHANNEL].Control.bit.Cycle_Ctrl = (1U);

	SstSys_DMA_Handle[SYS_DMA_RX_CHANNEL].Control.bit.N_Minus_1 = (SYS_DMA_RX_CHANNEL-(uint8_t)1U); 
	SstSys_DMA_Handle[SYS_DMA_RX_CHANNEL].Control.bit.Cycle_Ctrl = (1U);
//	DMA_Reset_Channel(SYS_DMA_TX_CHANNEL,SYS_DMA_TX_CHANNEL);
//	DMA_Reset_Channel(SYS_DMA_RX_CHANNEL,SYS_DMA_RX_CHANNEL);

	// DMA->CFG.bit.MASTER_ENABLE = 1;   /* DMA enable master  */
	HSI_DMA_TxRxChannelEnable();
	DMA_Master_En(); /* DMA enable master  */
}
