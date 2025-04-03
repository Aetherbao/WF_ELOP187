#ifndef MEM_MEM_H
#define MEM_MEM_H
/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "tle987x.h"


#include "tle987x.h"
#include "types.h"
#include "bootrom.h"

typedef enum 
{ 
  MEM_CHARACT = 0u,
  MEM_RWPRODUCTINFO,
  MEM_NUM_SECTOR
}ENM_MEM_SECTOR;

// #define MEM_DATATYPE_EE              (0x01)//data1_size:2byte data1_size:2byte  sum:4byte
// #define MEM_DATATYPE_PRODUCT         (0x02)//data1_size:12byte data1_size:10byte data1_size:4byte  sum:26byte


/*charact data Sector*/
/*size*/
#define MEM_CHARACT_SIZE                (0x40)
/*flash*/
#define MEM_CHARACT_NVM_START           (0x1101F800)  /* Start Address of the flash  */
/*ram*/
#define MEM_CHARACT_RAM_START           (0x18001700)  /* Start Address of the RAM   */

/*RW_PRODUCT_INFODATA Sector*/
/*size*/
#define MEM_RWPRODUCT_SIZE              (0x40)
/*flash*/
#define MEM_RWPRODUCT_NVM_START         (0x1101F880)  /* Start Address of the flash  */
/*ram*/
#define MEM_RWPRODUCT_RAM_START         (0x18001740)  /* Start Address of the RAM   */


/*Product data Sector*/
/*size*/
// #define PRODUCT_SIZE             (0x80)
/*flash*/
// #define MEM_SWUNIT_NVM           (0x1101DED8)//no use
/*ram*/
// #define MEM_PRODUCT_RAM_Start    (0x18001780) 


/*********************************************************************
RAM AREA
 ******************************************************************/


// #define  SRAM_GLOBALDATA           __attribute__ ((section(".RAM_GLOBAL")))       
#define  SRAM_DMADATA               __attribute__ ((section(".RAM_DMA")))         
// #define  SRAM_CaliDATA             __attribute__ ((section(".RAM_Cali")))     
#define  SRAM_CHARACT               __attribute__ ((section(".RAM_CHARACT"))) 
// #define  SRAM_RW_PRODUCT_INFODATA   __attribute__ ((section(".RAM_RW_ProductInfo")))

#define  SRAM_RW_PRODUCT_INFODATA_HWV       __attribute__ ((section(".RAM_RW_ProductInfo_HWV")))
#define  SRAM_RW_PRODUCT_INFODATA_SERNUM    __attribute__ ((section(".RAM_RW_ProductInfo_SerNum")))
#define  SRAM_RW_PRODUCT_INFODATA_ECUTIME   __attribute__ ((section(".RAM_RW_ProductInfo_ECUTime")))

#define  SRAM_PRODUCT_INFODATA      __attribute__ ((section(".RAM_ProductInfo")))
//SRAM_PRODUCT_INFODATA 这些数据需要确认 只是看到进行了定义和初值 并没有进行NVM的操作


#define  SRAM_GLOBAL              
#define  SRAM_GLOBAL_UINT8         uint8
// #define  SRAM_GLOBAL_INT8          sint8
#define  SRAM_GLOBAL_UINT16        uint16
#define  SRAM_GLOBAL_INT16         sint16
// #define  SRAM_GLOBAL_UINT32        uint32
// #define  SRAM_GLOBAL_INT32         sint32
// #define  SRAM_GLOBAL_FLOAT32       float32

// #define  SRAM_STATIC_UINT8         static uint8
// #define  SRAM_STATIC_INT8          static sint8
// #define  SRAM_STATIC_UINT16        static uint16
// #define  SRAM_STATIC_INT16         static sint16
// #define  SRAM_STATIC_UINT32        static uint32
// #define  SRAM_STATIC_INT32         static sint32
// #define  SRAM_STATIC_FLOAT32       static float32


#define  SRAM_DMA             SRAM_DMADATA volatile 
// #define  SRAM_DMA_UINT8       SRAM_DMADATA volatile uint8
// #define  SRAM_DMA_INT8        SRAM_DMADATA volatile sint8
// #define  SRAM_DMA_UINT16      SRAM_DMADATA volatile uint16
// #define  SRAM_DMA_INT16       SRAM_DMADATA volatile sint16
// #define  SRAM_DMA_UINT32      SRAM_DMADATA volatile uint32
// #define  SRAM_DMA_INT32       SRAM_DMADATA volatile sint32
// #define  SRAM_DMA_FLOAT32     SRAM_DMADATA volatile float32

// #define  SRAM_Cali                 SRAM_CaliDATA volatile 
// #define  SRAM_CaliDATA_UINT8       SRAM_CaliDATA volatile uint8
// #define  SRAM_CaliDATA_INT8        SRAM_CaliDATA volatile sint8
// #define  SRAM_CaliDATA_UINT16      SRAM_CaliDATA volatile uint16
// #define  SRAM_CaliDATA_INT16       SRAM_CaliDATA volatile sint16
// #define  SRAM_CaliDATA_UINT32      SRAM_CaliDATA volatile uint32
// #define  SRAM_CaliDATA_INT32       SRAM_CaliDATA volatile sint32
// #define  SRAM_CaliDATA_FLOAT32     SRAM_CaliDATA volatile float32

// #define  SRAM_EEPROM             SRAM_CHARACT volatile 
// #define  SRAM_EEPROM_UINT8       SRAM_CHARACT volatile uint8
// #define  SRAM_EEPROM_INT8        SRAM_CHARACT volatile sint8
#define  SRAM_CHARACT_UINT16      SRAM_CHARACT volatile uint16
// #define  SRAM_EEPROM_INT16       SRAM_CHARACT volatile sint16
// #define  SRAM_EEPROM_UINT32      SRAM_CHARACT volatile uint32
// #define  SRAM_EEPROM_INT32       SRAM_CHARACT volatile sint32
// #define  SRAM_EEPROM_FLOAT32     SRAM_CHARACT volatile float32

// #define  SRAM_RW_PRODUCT_INFODATA_UINT8   SRAM_RW_PRODUCT_INFODATA volatile uint8

#define  SRAM_RW_PRODUCT_INFODATA_HWV_UINT8      SRAM_RW_PRODUCT_INFODATA_HWV volatile uint8
#define  SRAM_RW_PRODUCT_INFODATA_SERNUM_UINT8   SRAM_RW_PRODUCT_INFODATA_SERNUM volatile uint8
#define  SRAM_RW_PRODUCT_INFODATA_ECUTIME_UINT8  SRAM_RW_PRODUCT_INFODATA_ECUTIME volatile uint8
// #define  SRAM_PRODUCTINFO             SRAM_PRODUCT_INFODATA volatile 
#define  SRAM_PRODUCTINFO_UINT8       SRAM_PRODUCT_INFODATA volatile uint8
// #define  SRAM_PRODUCTINFO_INT8        SRAM_PRODUCT_INFODATA volatile sint8
// #define  SRAM_PRODUCTINFO_UINT16      SRAM_PRODUCT_INFODATA volatile uint16
// #define  SRAM_ProductInfo_INT16       SRAM_PRODUCT_INFODATA volatile sint16
// #define  SRAM_ProductInfo_UINT32      SRAM_PRODUCT_INFODATA volatile uint32
// #define  SRAM_ProductInfo_INT32       SRAM_PRODUCT_INFODATA volatile sint32
// #define  SRAM_ProductInfo_FLOAT32     SRAM_PRODUCT_INFODATA volatile float32
/*******************************************************************************
**                         Global Function Declarations                        **
*******************************************************************************/
// uint8 Mem_EreaeNVM(uint32 u32_TargetAddress,uint32 u32_Length);
void Mem_RAMInit(void);
void Mem_DataRAM2NVM(ENM_MEM_SECTOR enmMem_Sector);
 void Mem_EreaseEeprom(void);
#endif
