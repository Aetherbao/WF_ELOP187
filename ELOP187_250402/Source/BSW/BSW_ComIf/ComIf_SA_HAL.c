#include "ComIf_SA_HAL.h"
#include <stdlib.h>
#include "utils.h"
#include "uds_cfg.h"
#include "stdint.h"

//#include "bootrom.h"

//#include "ComIf_UdsDspCfg.h"
//#include "Rte_Dcm_Type.h"
//#include "Dcm_Types.h"



//#if defined(DCM_SERVICE_27_SUB11)|| defined(DCM_SERVICE_27_SUB12)
//static unsigned char ISOUDS_SEED[SECURITY_SEED_SIZE_LEAVEL9];	
//static unsigned char SeedVal[SECURITY_SEED_SIZE_LEAVEL9];
//#endif

/////* Counter */
////static uint32_t Counter;



 //unsigned char Su8_uDcmSeed[3]={0};
 //unsigned char Su8_uDcmKey[3]={0};
 
const uint64_t Cu64_ComIf_FMASKTEMP = 0xFFFFFFFFFF;  //F1 F2 F3 F4 F5 0x41AA42BB43     (wSeed S1 S2 S3)   //0x1A2B3C4D5E
const uint32_t Cu32_ComIf_initialvalueATEMP = 0xc541A9; 

const uint8_t  Cu8_ComIf_seedLen =3;
uds_dWord_t    Gu32_ComIf_saSeed = 0;

uint32_t  Gu8_ComIf_StmUser_1msCnt =0;
///******************************** Function definitions ********************************************/


uint32_t ComIf_sys_random(bool seedInit)
{
	static uint32_t randomSeed = 0ul;
	uint32_t curCnt = Gu8_ComIf_StmUser_1msCnt;
	if (TRUE == seedInit)
	{
		randomSeed = curCnt;
		if (0ul == randomSeed)
		{
			randomSeed = 0x1A8D614Cul;
		}
	}
	else
	{
		if ((0 == randomSeed)
			&& (0 == curCnt))
		{
			randomSeed = 0x1A8D614Cul;
		}
	}
	randomSeed = (randomSeed * 1971) + 1360 + (curCnt & 0x0A00000Ful);
	return randomSeed;
	//return 0;
}



uint32_t ComIf_set_bit(uint32_t byte, uint8_t position, uint8_t value) {
   
    uint32_t mask = 1 << position;
 
    if (value == 0) {
        byte &= ~mask;  //
    } else {
        byte |= mask;   // 
    }
 
    return byte;
}




uint32_t ComIf_canculate_security_access_jili(uint32_t wSeed,uint64_t FMASK,uint32_t initialvalueA)
{

	uint64_t challengebits ;
	uint32_t positionB;
	uint32_t Btemp;
	uint32_t positionC;
	uint32_t Rkey;
	
	
  challengebits = ((FMASK&0xFF)<<56) | (((FMASK>>8)&0xFF)<<48)| (((FMASK>>16)&0xFF)<<40)| (((FMASK>>24)&0xFF)<<32)| (((FMASK>>32)&0xFF)<<24);
	challengebits = challengebits | ((wSeed&0xFF)<<16) | (((wSeed>>8)&0xFF)<<8) | ((wSeed>>16)&0xFF);
	for(uint8_t i=0;i<64;i++)
	{
			positionB = ((((challengebits>>i)& 0x0000000000000001)^ (initialvalueA &0x01))<<23) |  (initialvalueA>>1);
		   
		  Btemp = ((positionB >>23)& 0x01)^ ((positionB >>20)&0x01 );
		  
		  positionC = ComIf_set_bit(positionB,20,Btemp);
		
		  Btemp = ((positionB >>23)& 0x01)^ ((positionB >>15)&0x01 );
		  
		  positionC = ComIf_set_bit(positionC,15,Btemp);
		  
		  
		  Btemp = ((positionB >>23)& 0x01)^ ((positionB >>12)&0x01 );
		  
		  positionC = ComIf_set_bit(positionC,12,Btemp);
		
		  Btemp = ((positionB >>23)& 0x01)^ ((positionB >>5)&0x01 );
		  
		  positionC = ComIf_set_bit(positionC,5,Btemp);
		
		  Btemp = ((positionB >>23)& 0x01)^ ((positionB >>3)&0x01 );
		  
		  positionC = ComIf_set_bit(positionC,3,Btemp);
		 
		  initialvalueA = positionC;
	}
	
	Rkey =  (((positionC >> 4)& 0xFF)<<16) | (((positionC >> 12)& 0x0F)<<12) | (((positionC >> 20)& 0x0F)<<8);
	Rkey =  Rkey | (((positionC >> 0)& 0x0F)<<4) | (((positionC >> 16)& 0x0F)<<0);
	
	return( Rkey );
}





//#if defined(DCM_SERVICE_27_SUB01)|| defined(DCM_SERVICE_27_SUB02)
//27 01
Std_ReturnType ComIf_UnlockedL1_GetSeed(unsigned char *u8_Seed, Dcm_NegativeResponseCodeType *u8_ErrorCode)
{
	Std_ReturnType retValue = 0;
	
	unsigned char seedDt_i = 0; /* seed data index */
   
	for (; seedDt_i < Cu8_ComIf_seedLen; seedDt_i++) 
	{
	
	   u8_Seed[seedDt_i] = (uint8_t)(ComIf_sys_random(FALSE) & 0xFFul);
	}
	
	for(unsigned char byte_i = 0; byte_i < Cu8_ComIf_seedLen; byte_i ++)
	{
				Gu32_ComIf_saSeed = Gu32_ComIf_saSeed << 8;
				Gu32_ComIf_saSeed = Gu32_ComIf_saSeed + (uds_dWord_t)(u8_Seed[byte_i]);
				
	}                  
	
//    *u8_Seed =     Su8_uDcmSeed[0];
//    *(u8_Seed+1) = Su8_uDcmSeed[1];
//    *(u8_Seed+2) = Su8_uDcmSeed[2];
//	  *(u8_Seed+2) = Su8_uDcmSeed[3];
    
    return retValue;
}


//27 02
Std_ReturnType ComIf_UnlockedL1_CompareKey(unsigned char *u8_Key, Dcm_NegativeResponseCodeType *u8_ErrorCode)
{
	Std_ReturnType retValue = 0;
	
	uds_dWord_t saKey = 0;
	unsigned char seedDt_i = 0;
	

	 saKey   = ComIf_canculate_security_access_jili(Gu32_ComIf_saSeed,Cu64_ComIf_FMASKTEMP,Cu32_ComIf_initialvalueATEMP);
			
		*u8_Key =     saKey & 0xFF;
		*(u8_Key+1) = (saKey >>8) & 0xFF;
		*(u8_Key+2) = (saKey >>16) & 0xFF;
			
				
	
	/*  -------------------------------------- Data Read -----------------------------------------  */

    /*if ( ( u8_Key[ 0 ] != Su8_uDcmKey[ 0 ] ) || ( u8_Key[ 1 ] != Su8_uDcmKey[ 1 ] )||( u8_Key[ 2 ] != Su8_uDcmKey[ 2 ] )||(u8_Key[ 3 ] != Su8_uDcmKey[ 3 ]))
    {
       // *u8_ErrorCode = DCM_E_INVALIDKEY;    
      //  retValue = DCM_E_COMPARE_KEY_FAILED;
    }
    else
    {
        
    }*/
    return retValue;
}


//#endif





//#if defined(DCM_SERVICE_27_SUB11)|| defined(DCM_SERVICE_27_SUB12)
////0x27 11
////FUNC(Std_ReturnType, DCM_APPL_CODE) DcmGetSeedDSP_Fbl_ProgM_GetSeedCallback(VAR(Dcm_SecLevelType,AUTOMATIC) SecLevel_u8,                                /* PRQA S 3206, 1503 */ /* This function does not use this parameter */
////                                                                            VAR(unsigned long,AUTOMATIC) Seedlen_u32,                                          /* PRQA S 3206 */                  
////                                                                            VAR(unsigned long,AUTOMATIC) AccDataRecsize_u32,                                   /* PRQA S 3206 */
////                                                                            P2VAR(unsigned char,AUTOMATIC,DCM_INTERN_DATA) SecurityAccessDataRecord,            /* PRQA S 3206 */
////                                                                            P2VAR(unsigned char,AUTOMATIC,DCM_INTERN_DATA) Seed,                                /* PRQA S 3206 */
////                                                                            VAR(Dcm_OpStatusType,AUTOMATIC) OpStatus,                                   /* PRQA S 3206 */ /* This function does not use this parameter */
////                                                                            P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
//FUNC(Std_ReturnType, RTE_CODE) DcmGetSeedDSP_Fbl_ProgM_GetSeedCallback(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
//                                           P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Seed,
//                                           P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
//{
//    
//    Std_ReturnType retValue = E_OK;
//    
//    *Seed = Su8_uDcmSeed[0];
//    *(Seed+1) = Su8_uDcmSeed[1];
//    *(Seed+2) = Su8_uDcmSeed[2];
//    
//    return retValue;
//}

////0x27 12
////FUNC(Std_ReturnType, DCM_APPL_CODE) DcmCompareKeyDSP_Fbl_ProgM_CompareKeyCallback( VAR(unsigned long,AUTOMATIC) KeyLen_32,                 /* PRQA S 3206, 1503 */
////                                                                                    const unsigned char * Key,                              /* PRQA S 3206, 3673 */ /* The object addressed by the pointer parameter 'Key' is not modified and so the pointer could be of type 'pointer to const'*/
////                                                                                    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,      /* PRQA S 3206 */ /* This function does not use this parameter */
////                                                                                    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,
////                                                                                    DCM_INTERN_DATA) ErrorCode)


//FUNC(Std_ReturnType, RTE_CODE) DcmCompareKeyDSP_Fbl_ProgM_CompareKeyCallback(P2CONST(unsigned char, AUTOMATIC, RTE_APPL_DATA) Key,
//                                              VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
//                                               P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)                                                                                    
//{

//	Std_ReturnType retValue = E_OK;
//	/*  -------------------------------------- Data Read -----------------------------------------  */

//    if ( ( Key[ 0 ] != Su8_uDcmKey[ 0 ] ) || ( Key[ 1 ] != Su8_uDcmKey[ 1 ] )||( Key[ 2 ] != Su8_uDcmKey[ 2 ] ))
//    {
//        *ErrorCode = DCM_E_INVALIDKEY;    /*增加负响应码0x35*/
//        retValue = E_NOT_OK;
//    }
//    else
//    {
//        
//    }
//    return retValue;
//}
//#endif









