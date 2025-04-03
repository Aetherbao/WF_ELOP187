#ifndef ISOUDS_WRDABYID_HAL_H
#define ISOUDS_WRDABYID_HAL_H
#include "Std_Types.h"

//#include <stdint.h>
//#include "Rte_Dcm_Type.h"
extern uint8_t Gu8_ComIf_UDSWriteFlg;
//extern uint16_t Gu16_ComIf_WakeupSignalTimes;
//extern uint16_t Gu16_ComIf_SleepSignalTimes;
//extern uint16_t Gu16_ComIf_LimphomeSpeedSignal;

extern void ComIf_Get_WriteFunc_04(const unsigned char * Data, unsigned char *u8_ErrorCode);
extern void ComIf_Get_WriteFunc_03(const unsigned char * Data, unsigned char *u8_ErrorCode);
extern void ComIf_Get_WriteFunc_02(const unsigned char * Data, unsigned char *u8_ErrorCode);

//extern void ComIf_Get_WriteFunc_14 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_15 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_16 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_31 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_32 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_36 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_37 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_39 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_40 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_41 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);
//extern void ComIf_Get_WriteFunc_43 (const unsigned char * Data, Dcm_NegativeResponseCodeType *u8_ErrorCode);


#endif  /* _ISOUDS_WRDABYID_HAL_H_ */
