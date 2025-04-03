/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */
#include "LinIf_Cfg.h"
#include "LinIf_HeaderIndication.h"
#include "LinTp_Cbk.h"



//#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)  
Std_ReturnType LinIf_HeaderIndication( NetworkHandleType Channel, Lin_PduType* PduPtr )
{
	Std_ReturnType ret = E_OK;

	uint8 FrameIndex_u8;

	for (FrameIndex_u8=0; FrameIndex_u8<2; FrameIndex_u8++)
	{
		if(LinIf_FrmCfg_acs[FrameIndex_u8].Pid_u8 == PduPtr->Pid)
		{				
			break;
		}
	}
	

	if(FrameIndex_u8 >= 2)
	{
		PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
	}
	else
	{
		PduPtr->Cs = LinIf_FrmCfg_acs[FrameIndex_u8].LinIfChecksumType_u8;
		PduPtr->Dl = LinIf_FrmCfg_acs[FrameIndex_u8].LengthOrNoSpoET_u8;
		
		if(LinIf_FrmCfg_acs[FrameIndex_u8].LinIfPduDirection_u8 == LINIF_RX)
		{
			PduPtr->Drc = LIN_FRAMERESPONSE_RX;
		}
		else
		{
			PduInfoType pdu_Info_Tx;

			PduPtr->Drc = LIN_FRAMERESPONSE_TX;

			pdu_Info_Tx.SduDataPtr = PduPtr->SduPtr;
			pdu_Info_Tx.SduLength = PduPtr->Dl;	

			LinTp_LinIfTriggerTransmit(&pdu_Info_Tx);
		}
	}
	
	return E_OK;
}

//#endif

