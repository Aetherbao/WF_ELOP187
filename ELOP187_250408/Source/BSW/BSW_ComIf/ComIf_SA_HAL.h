#ifndef ISOUDS_SA_HAL_H
#define ISOUDS_SA_HAL_H

//#include "Platform_Types.h"
//#include "Rte_Type.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/
//#define TopofStack	  			0x18007C00
//#define EndofStack 					0x18007E00

#define Dcm_NegativeResponseCodeType unsigned char
#define Std_ReturnType unsigned char

Std_ReturnType ComIf_UnlockedL1_GetSeed(unsigned char *u8_Seed, Dcm_NegativeResponseCodeType *u8_ErrorCode);
Std_ReturnType ComIf_UnlockedL1_CompareKey(unsigned char *u8_Key, Dcm_NegativeResponseCodeType *u8_ErrorCode);

extern unsigned int Gu8_ComIf_StmUser_1msCnt;


//extern unsigned char Su8_uDcmSeed[3];
//extern unsigned char Su8_uDcmKey[3];


#endif  /* ISOUDS_SA_HAL_H */
