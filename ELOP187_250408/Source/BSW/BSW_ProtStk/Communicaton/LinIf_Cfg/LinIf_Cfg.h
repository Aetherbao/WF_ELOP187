#ifndef LINIF_CFG_H_
#define LINIF_CFG_H_



#include "Std_Types.h"
#include "Lin_GeneralTypes.h"
#include "Platform_Types.h"


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
#define LINIF_RX  		(0)
#define LINIF_TX  		(1)

typedef struct
{
	uint8                             	Pid_u8 ;                                         	 	/* PID of frame*/
	Lin_FrameCsModelType 	LinIfChecksumType_u8;                         /*Checksum type*/
	uint8                             	LengthOrNoSpoET_u8 ;                          /* Length*/
	uint8                             	LinIfPduDirection_u8 ;                          	/* Direction of PDU*/

} LinIf_FrameCfg_t;



extern  const LinIf_FrameCfg_t LinIf_FrmCfg_acs[2];



#endif
