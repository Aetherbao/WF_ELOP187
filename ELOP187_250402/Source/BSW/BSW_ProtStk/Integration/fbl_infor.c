/*
* Copyright (c) 2016,SHENZHEN HANGSHENG ELECTRONICS Co.,Ltd.
* All Rights Reserved.
* Dept.: Software Dept.
* File:fbl_infor.c
* Description:
* History:
* 2016-5-13, 1007040, original
*/

#include "fbl_infor.h"
#include "utils.h"
//#include "Flash_IF.h"
#include "uds_user.h"

/* ------------------ Flash bootloader information define --------------------------- */



//const fblFingerprint_t  fblFingerprint __at(USER_CODE_START_ADDRESS - 0x30) =
//{
//    /* Program access check flag: 8 Bytes */ {0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01},
//    /* Bootloader Protocol ver:   1 Bytes */ 0x20, /* Version 2.0 */
//    /* Flash driver ID:           1 Bytes */ flashDriverID_downLoad,
//    /* CPU address bus width      1 Bytes */ CPU_ADDR_WIDTH,
//    /* Reserved, stay on 0xFF     1 Bytes */ 0xFFu,
//    /* FBL start address:         4 Bytes */ 0x80000000ul,
//    /* FBL address length:        4 Bytes */ 0x00020000ul,
//    /* APP start address:         4 Bytes */ 0x80020000ul,
//    /* APP address length:        4 Bytes */ 0x001E0000ul,
//    /* APP program aline size:    4 Bytes */ 0x00000100ul,   
//    /* appDependencyFlgAddr:     4 Bytes */ 0x8001C000ul,
//     /*appValidNumber:              4 Bytes */ 0x20211014ul,
//     /*rsvd_1:                       4 Bytes*/0xFFFFFFFFul,
//     /*rsvd_2:                       4 Bytes*/0xFFFFFFFFul
//};



const appSwUnitInfo_t appSwUnitInfo[nbOfSoftwareUnits_APP] = 
{
	{
		/* appSwUnitIndex;	*/	0x00000001,
		/*   CntArea;		*/	0x01,      //no use
		/*   Area;			*/	0x01,      //no use
		/* startAddr;		*/	0x1100A000ul,   //0x80020000ul
		/* length;			*/	0x00014000ul,   //0x001E0000ul
		/* validFlgAddr;	*/ 0x1101DED8,    // 0x8001C010ul
		/* validMagicNum;	*/	0x20211014ul
	}
};




//const fblID_t  fblID __at(USER_CODE_START_ADDRESS - 0x50) =
//{
//    /* Product Code: 8 Bytes */ {'A', 'B', 'F', '0', '8', 'B', 'M', 'S'},
//    /* CPU Topology: 1 Bytes */ cpuTopology_Master,
//    /* softwareType: 1 Bytes */ softwareType_FBL,
//    /* software ver: 4 Bytes */ {'1', '.', '0', '0'},
//};




/* ------------------ End Flash bootloader information define ----------------------- */


fblNvmDts_t fblNvmDts_ram1; /* [un-init in def] a temp map with in-EEPROM area, load form in-EEPROM when boot start */
fblNvmDts_t fblNvmDts_ram2; /* [un-init in def] a temp map with in-EEPROM area, load form in-EEPROM when boot start */


#pragma section all dflash_BootData
volatile const fblNvmDts_t  fblNvmDts_iee={0};
#pragma section all restore




void fblNvm_load(void)
{
	uint16_t fblNvmDts_iee_Size = sizeof(fblNvmDts_t);

    /* CRC16 check */
    if (fblNvmDts_iee.crc == crc32((uint8_t *)(&fblNvmDts_iee), (uint32_t)(fblNvmDts_iee_Size - 4)))
    {
        /* Check pass, load nvm data */
        memoryCopy((uint8_t *)(&fblNvmDts_iee), (uint8_t *)(&fblNvmDts_ram1), (uint16_t)(fblNvmDts_iee_Size));
	memoryCopy((uint8_t *)(&fblNvmDts_iee), (uint8_t *)(&fblNvmDts_ram2), (uint16_t)(fblNvmDts_iee_Size));
    }
    /* End access NVM(in-EEPROM block 0) */
}

/*
 * Function:fblNvm_save
 * Param<void>:
 * Return<bool>: TRUE: save success, FLASE: save fail
 * Discription:  save fblNvmDts_ram to D-Flash fblNvmUsedDFlashBlockIndex block, start address is block start address
 * Note: 
*/
bool fblNvm_save1(void)
{
    bool saveRst = FALSE;
    
//    if (flash_eraseSectorByStartAddr((uint32_t)(&fblNvmDts_iee)) > 0)
//    {
//        fblNvmDts_ram1.crc = crc32((uint8_t *)(&fblNvmDts_ram1), (uint32_t)(sizeof(fblNvmDts_ram1) - 4));
//        if (TRUE == flash_program((uint32_t)(&fblNvmDts_iee), (uint8_t *)(&fblNvmDts_ram1), sizeof(fblNvmDts_ram1)))
//        {
//            saveRst = TRUE;
//        }
//    }
    return saveRst;
}



bool fblNvm_save2(void)
{
    bool saveRst = FALSE;
    
//    if (flash_eraseSectorByStartAddr((uint32_t)(&fblNvmDts_iee)) > 0)
//    {
//        fblNvmDts_ram2.crc = crc32((uint8_t *)(&fblNvmDts_ram2), (uint32_t)(sizeof(fblNvmDts_ram2) - 4));
//        if (TRUE == flash_program((uint32_t)(&fblNvmDts_iee), (uint8_t *)(&fblNvmDts_ram2), sizeof(fblNvmDts_ram2)))
//        {
//            saveRst = TRUE;
//        }
//    }
    return saveRst;
}




