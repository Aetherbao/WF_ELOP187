/*
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/

/*******************************************************************************
**                                                                            **
**                _  _               ___             _                        **
**               (_)| |__   _ __    / _ \ _ __ ___  | |__    /\  /\           **
**               | || '_ \ | '__|  / /_\/| '_ ` _ \ | '_ \  / /_/ /           **
**               | || | | || |    / /_\\ | | | | | || |_) |/ __  /            **
**               |_||_| |_||_|    \____/ |_| |_| |_||_.__/ \/ /_/             **
**                                                                            **
**  ihr GmbH                                                                  **
**  Airport Boulevard B210                                                    **
**  77836 Rheinmünster - Germany                                              **
**  http://www.ihr.de                                                         **
**  Phone +49(0) 7229-18475-0                                                 **
**  Fax   +49(0) 7229-18475-11                                                **
**                                                                            **
********************************************************************************
**                                                                            **
** (c) Alle Rechte bei IHR GmbH, auch fuer den Fall von Schutzrechts-         **
** anmeldungen. Jede Verfuegungsbefugnis, wie Kopier- und Weitergaberecht     **
** bei uns.                                                                   **
**                                                                            **
** (c) All rights reserved by IHR GmbH including the right to file            **
** industrial property rights. IHR GmbH retains the sole power of             **
** disposition such as reproduction or distribution.                          **
**                                                                            **
*********************    Workfile:    genLinConfig.c      **********************
**                                                                            **
**  PROJECT-DESCRIPTION:  Infineon LIN Driver                                 **
**                                                                            **
**  FILE-DESCRIPTION:  Generated LIN Configuration File                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Author(s) Identity                             **
********************************************************************************
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** BR           B.Roegl                                                       **
** HS           H. Spinner                                                    **
** BG           Blandine Guillot                                              **
*******************************************************************************/

/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V1.0.0: 2014-02-18, HS:   New Demo driver for Infineon TLE987x             **
** V1.0.1: 2020-04-15, BG:   Updated abstract                                 **
*******************************************************************************/


/* Generated by LDCTool 2.0.3.12      Date: 28.01.2015 */
/* Generated from LDF: c:\userdata\mysliwid\02_produkte\03_proteus\training\disti fae - 2015 jan\lin_ldf.ldf */

#include "genLinConfig.h"
#include "Mem_Mem.h"

volatile t_l_flags_MotorCtrl l_flags_MotorCtrl;
volatile t_l_flags_MotorStatus l_flags_MotorStatus;
volatile t_l_flags_MotorStatus_DIAG l_flags_MotorStatus_DIAG;
volatile t_l_flags_MotorStatus_0x1B l_flags_MotorStatus_0x1B;
volatile t_l_flags_MotorStatus_0x1D l_flags_MotorStatus_0x1D;

void l_Update_Frame_Flags(l_u8 number)
{
  switch (number)
  {
    case (0):
      l_Update_flags_frame0()
      break;

    case (1):
      l_Update_flags_frame1()
      break;

		case (2):
      l_Update_flags_frame2()
      break;
		case (3):
      l_Update_flags_frame3()
      break;
		case (4):
      l_Update_flags_frame4()
      break;

    default:
      break;
  }
}

/* define generated lin data variables with init value */
 t_l_Lin_Data l_LinData =
{
  {
    (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0,
    (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0,
    (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0,
		(l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0,
    (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0, (l_u8)0
  }
};



void ComDrv_Set_APPTxMsgData(uint8*TxMsg,uint8 LINID)
{
		uint8_t l_DataIndx;
	  uint8_t ID =0x01;
	
	if(LINID == 0x20)
		 ID = 0x01;
	else if(LINID == 0x1F)
		 ID = 0x02;
	
	 
		/* Get the recived data */
		for (l_DataIndx = 0; l_DataIndx < 8; l_DataIndx++)
		{
			 l_LinData.Frame[ID].frame_data[l_DataIndx] = TxMsg[l_DataIndx];
		}	
	 
}

/* File Footer */
/* genLinConfig.c file for TLE9879 */
