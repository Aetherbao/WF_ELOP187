#include "LinIf_Cfg.h"
#include "LinIf_RxIndication.h"
#include "LinTp_Cbk.h"



//#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)  
void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr)
{
	uint8 FrameIndex_u8;

	for (FrameIndex_u8=0; FrameIndex_u8<2; FrameIndex_u8++)
	{
		if(LinIf_FrmCfg_acs[FrameIndex_u8].Pid_u8 == Lin_SduPtr[0])
		{
			break;
		}
	}

	if( 	(FrameIndex_u8 < 2)
	    &&(LinIf_FrmCfg_acs[FrameIndex_u8].LinIfPduDirection_u8 == LINIF_RX))
	{
		PduInfoType pdu_Info_Rx;

		pdu_Info_Rx.SduDataPtr = &(Lin_SduPtr[1]);
		pdu_Info_Rx.SduLength = LinIf_FrmCfg_acs[FrameIndex_u8].LengthOrNoSpoET_u8;	
		
		LinTp_LinIfRxIndication(&pdu_Info_Rx);
	}
}

//#endif/*#if defined(LIN_SLAVER_MODIFY) && (LIN_SLAVER_MODIFY != STD_OFF)*/

