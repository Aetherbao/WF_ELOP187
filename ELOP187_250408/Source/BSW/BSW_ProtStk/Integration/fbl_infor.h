/*
* Copyright (c) 2016,SHENZHEN HANGSHENG ELECTRONICS Co.,Ltd.
* All Rights Reserved.
* Dept.:Software Department
* File:fbl_infor.h
* Description: match flash driver protocol version 2.0
* History:
* 2016-5-13, 1007040, original
*/

#ifndef __FBL_INFOR_H__
#define __FBL_INFOR_H__

#include "typedefs.h"

/*user code start address*/
#define USER_CODE_START_ADDRESS 0x80000070

/* CPU properties config */
#define CPU_ADDR_WIDTH 1 /* Bytes, * 8 bits. Only used 1, 2 */
/* Application releated config */

/* Do not change those code below this line (is force define in FBL protocol) */
/* Define for flash bootlader identify */
#define prodoctCodeDLC     8   /* Product code length define used data length (Bytes) */
#define cpuTopology_Master 'M'  /* Master, CPU Topology in product */
#define cpuTopology_Slave  'S'  /* Slave  */
#define softwareType_FBL   'B'  /* Bootloader Flag */
#define softwareType_APP   'A'  /* Applcation Flag */
#define fblVersionDLC      4   /* Flash bootloader version define used data length (Bytes) */
/* Define for flash bootloader fingerprint */
#define progAccessCheckDLC 8  /* program access check flag data length (Bytes) */
#define flashDriverID_selfLoad 0x00 /* not need download flash driver when program */
#define  flashDriverID_downLoad 0x01

/*Number of sw uint in Application sw*/
#define nbOfSoftwareUnits_APP	0x01

/* exEEPROM virtual address convert */
#define exEEPROM_basicVirAddress          (0xE0000000ul)
#define exEEPROM_getVirtualAddr(phyAddr)  ((phyAddr) + 0xE0000000ul)
#define exEEPROM_getPhysicalAddr(varAddr) ((varAddr) & 0x0FFFFFFFul)
/* import form sections.ld linker file */
extern const uint32_t _DFLASH_START_ADDR;
extern const uint32_t _DFLASH_SIZE;
extern const uint32_t _FBL_PFLASH_START_ADDR;
extern const uint32_t _FBL_PFLASH_SIZE;
extern const uint32_t _APP_PFLASH_START_ADDR;
extern const uint32_t _APP_PFLASH_SIZE;
extern const uint32_t _APP_PFLASH_BLOCKSIZE;

/* Boot software ID */
typedef struct
{
    uint8_t productCode[prodoctCodeDLC]; /* Product Code */
    uint8_t cpuTopology;                 /* CPU topology (Master CPU, Slave/Safety CPU, or CPU number on one board) */
    uint8_t swType;
    uint8_t swVersion[fblVersionDLC];    /* FBL software version */
} fblID_t;

/* Boot Fingerprint */
//typedef struct
//{
//    uint8_t progAccessCheckData[progAccessCheckDLC]; /* update check flag, check when appliction fingerprint write */
//    uint8_t fblProVer; /* flash bootloader protocol version number */
//    uint8_t flashDriverID;  /* flash driver version download request, set 0x00 for not need download flash driver */
//    uint8_t addrWidth;    /* CPU data address width, indicate the CPU each address maped how many bytes. width(bytes) = 0x01 << dtAddrWidth */
//    uint8_t rsvd_0;         /* reserved, stay on 0xFFFF */
//    uint32_t startAddr;     /* Flash bootloader address */
//    uint32_t addrLength;    /* Flash bootloader address length */
//    uint32_t appStartAddr;  /* Application area start address */
//    uint32_t appAddrLength; /* Application area address length */
//    uint32_t appAlineSize;  /* Application area address aline size when program */
//    uint32_t appDependencyFlgAddr; 
//    uint32_t appValidNumber;
//    uint32_t rsvd_1;
//uint32_t rsvd_2;
//} fblFingerprint_t; /* Flash bootloader fingerprint total size 56 */


/* Boot used in-EEPROM datas */
typedef struct
{
	uint32_t appSwUnitIndex;
	uint8_t   CntArea;
	uint8_t   Area;
	uint32_t startAddr;
	uint32_t length;
	uint32_t validFlgAddr;
	uint32_t validMagicNum;
}appSwUnitInfo_t;



/* Boot used in-EEPROM datas */
typedef struct
{
	uint8_t VehicleIdentificationNumber[17];
	uint8_t reserve1[3];
	uint8_t TesterSerialNumber[16];
	uint8_t progarmmingDate[3];
	uint8_t TestUsageId;
	uint32_t saInvalidAccessCnt;
	uint32_t RequestDownloadAddr;
	uint32_t programAttemptCounter;
	uint32_t crc;       /* CRC16 value */
}fblNvmDts_t;


extern const appSwUnitInfo_t appSwUnitInfo[nbOfSoftwareUnits_APP];
extern const fblID_t fblID;
//extern const fblFingerprint_t fblFingerprint;
extern fblNvmDts_t fblNvmDts_ram1;
extern fblNvmDts_t fblNvmDts_ram2;



/* Export: function */
extern void fblNvm_load(void);
extern bool fblNvm_save1(void);
extern bool fblNvm_save2(void);

/*--------EOF--------*/
#endif
