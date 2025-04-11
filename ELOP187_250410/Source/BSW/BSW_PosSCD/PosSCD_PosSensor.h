#ifndef POSSCD_POSSENSOR_H
#define POSSCD_POSSENSOR_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#define PSCD_WRITEACCESS			  (1u)
#define PSCD_READACCESS				  (0u)

#define PSCD_CFG_TXDATA1			  ((uint16)0x8021)
#define PSCD_CFG_TXDATA               ((uint16)0xFFFF)
#define PSCD_CFG_RXDATA               ((uint16)0xFFFF)

#define PSCD_CFG_SNRREAD			  ((uint16)0x8001)
#define PSCD_CFG_SNRWRITE			  ((uint16)0x0001)

#define PSCD_CFG_SNR_VALUE            ((uint16)0x0001)
#define PSCD_CFG_SNR_POS              ((uint16)13)
#define PSCD_CFG_SNR_MASK             ((uint16)0x6000)
#define PSCD_CFG_SNRDATA			  ((PSCD_CFG_SNR_VALUE<<PSCD_CFG_SNR_POS)&PSCD_CFG_SNR_MASK)//((uint16)0x2000)//S_NR:01


#define PSCD_ANGLEMASK				  ((uint16)0x7FFF)

/**value of these bit are 1 means OK 
 * bit15 0-Reset occurred 1-No reset  birf:Indication of chip reset or watchdog overflow
 * bit14 0-Error occurred 1-No error  birf:System error
 * bit13 0-Error occurred 1-No error  birf:Interface access error (access to wrong address; wrong lock)
 * bit13 0-Angle value invalid 1-Angle value valid  birf:Invalid angle value 
*/
#define PSCD_SAFETY_ERR               ((uint16)0xF000)
/*The sensor number bit is pulled low and the other bits are high*/
#define PSCD_SAFETY_RESP              ((uint16)0x0D00)//1101 PSCD_CFG_SNR_VALUE is 0x01, so bit1 is 0
// #define PSCD_SAFETY_CRC_MASK          ((uint16)0x00FF)
#define PSCD_SAFETY_MASK              ((uint16)0xFF00)

#define PSCD_COM_SUCCESS_MASK         (PSCD_SAFETY_MASK)
#define PSCD_COM_SUCCESS_VAULE        (PSCD_SAFETY_ERR|PSCD_SAFETY_RESP)
// #define PSCD_COM_FAULT_VAULE          ((uint16)0xFFFF)   
/*******************************************************************************
**                        Global Variable Definitions                        **
*******************************************************************************/
extern SRAM_GLOBAL_UINT16 Gu16_PSCD_AngleData_IF;  /* angle data */
extern SRAM_GLOBAL_UINT16 Gu16_PSCD_SafetyWord_IF; /* fault information*/
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
void PosSCD_Init(void);
void PosSCD_Data_Read(void);

#endif
