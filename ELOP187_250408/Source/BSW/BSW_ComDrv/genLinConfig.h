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
*********************    Workfile:    genLinConfig.h      **********************
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
** DM           Daniel Mysliwitz                                              **
** JO           Julia Ott                                                     **
*******************************************************************************/

/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V1.0.0: 2014-02-18, HS:   New Demo driver for Infineon TLE987x             **
** V1.0.1: 2020-04-15, BG:   Updated abstract                                 **
** V1.1.0: 2020-07-31, DM:   l_u16_rd_RefSpeed changed to l_s16_rd_RefSpeed   **
** V1.2.0: 2022-07-07, JO:   EP-1206: Changed l_s16_rd_RefSpeed to            **
**                           l_u16_rd_RefSpeed for signal in range [0...5000] **
*******************************************************************************/


/* Generated by LDCTool 2.0.3.12      Date: 28.01.2015 */
/* Generated from LDF: c:\userdata\mysliwid\02_produkte\03_proteus\training\disti fae - 2015 jan\lin_ldf.ldf */
#ifndef        GEN_LIN_CONFIG_H
#define        GEN_LIN_CONFIG_H

#include "Mem_Mem.h"

/* LIN Attributes */
#define        LIN_BAUDRATE 19200    /* for CPU speed of 40 MHz */

/* Node Attributes */

/* Generated Node: Motor */

#define        LIN_SLAVE
#define        LIN_PROTOCOL_VERSION_2_1
#define        LIN_INITIAL_NAD    (l_u8)1
#define        LIN_SUPPLIER_ID    (l_u16)4660
#define        LIN_FUNCTION_ID    (l_u16)22136
#define        LIN_VARIANT_ID     (l_u8)0

/* Access Macros for Node Information */
#define        l_get_current_NAD()        (g_lin_prod_id.NAD)
#define        l_set_current_NAD(x)       (g_lin_prod_id.NAD = (x))
#define        l_get_initial_NAD()        (g_lin_prod_id.Initial_NAD)
#define        l_get_SupplierID_Low()     (g_lin_prod_id.Supplier_lo)
#define        l_get_SupplierID_High()    (g_lin_prod_id.Supplier_hi)
#define        l_get_FunctionID_Low()     (g_lin_prod_id.Function_lo)
#define        l_get_FunctionID_High()    (g_lin_prod_id.Function_hi)
#define        l_get_Variant()            (g_lin_prod_id.Variant)


/* User Defined Attributes */

/* User Defined Diagnostic Attributes */

#define        LIN_DIAG_ENABLE
#define        LIN_COOKED_API
#define        LIN_TASK_CYCLE_MS    1u
#define        LIN_FRAME_TIMEOUT    10u
#define        LIN_AUTOBAUD_TIMEOUT    4u

/* User Defined Node Attributes */

#define        LIN_ENABLE_ASSIGN_FRAME_ID_RANGE


/* User Defined MCU Attributes */

/* TLE9879 */


/* 19200 */
#define        BRG_PRE       (l_u8)0
#define        BRGH_VAL      (l_u8)16
#define        BRGL_VAL      (l_u8)2
#define        BRG_FD_SEL    (l_u8)7

/* 115200 */

//#define        BRG_PRE       (l_u8)0
//#define        BRGH_VAL      (l_u8)2
//#define        BRGL_VAL      (l_u8)5
//#define        BRG_FD_SEL    (l_u8)22


/* 38400 */

//#define        BRG_PRE       (l_u8)0
//#define        BRGH_VAL      (l_u8)8
//#define        BRGL_VAL      (l_u8)1
//#define        BRG_FD_SEL    (l_u8)3




#define        BG_SEL        (l_u8)3
#define        LIN_UART1
#define        LIN_INTERRUPT_PRIORITY  (l_u8)5
#define        STRUCT_ATTRIBUTE
#define        STRUCT16BIT

/* Generate the Signal Attributes */

#include "lin_type.h"


#define      LIN_DiagRequest_PID  0x3C
#define      LIN_DiagResponse_PID  0x7D

/* Frame Attributes */

#define        LIN_NUMBER_OF_FRAMES    (l_u8)7   //2

//#define        LIN_FRAME_CTRL_INIT {{{(l_u8)17,(l_u8)128,(l_u8)8}},{{(l_u8)146,(l_u8)129,(l_u8)8}}}
//#define        LIN_FRAME_CTRL_INIT {{{(l_u8)17,(l_u8)128,(l_u8)8}},{{(l_u8)146,(l_u8)129,(l_u8)8}},{{(l_u8)60,(l_u8)128,(l_u8)8}},{{(l_u8)125,(l_u8)129,(l_u8)8}}}  //PID 3C 7D
//#define          LIN_FRAME_CTRL_INIT {{{(l_u8)156,(l_u8)128,(l_u8)8}},{{(l_u8)26,(l_u8)129,(l_u8)8}},{{(l_u8)153,(l_u8)129,(l_u8)8}},{{(l_u8)60,(l_u8)128,(l_u8)8}},{{(l_u8)125,(l_u8)129,(l_u8)8}}}  //PID 3C(60) 7D(125)
#define          LIN_FRAME_CTRL_INIT {{{(l_u8)115,(l_u8)128,(l_u8)8}},{{(l_u8)32,(l_u8)129,(l_u8)8}},{{(l_u8)31,(l_u8)129,(l_u8)8}},{{(l_u8)91,(l_u8)129,(l_u8)8}},{{(l_u8)221,(l_u8)129,(l_u8)8}},{{(l_u8)60,(l_u8)128,(l_u8)8}},{{(l_u8)125,(l_u8)129,(l_u8)8}}}  //PID 3C(60) 7D(125)
//156-9C-1C  26-1A-1A   153-99-19    91-0x5B(PID)- 0x1B(ID)   221-0xDD(PID)- 0x1D(ID)
//jili 115 - 0x73(PID)-0x33(ID 51)      32-0x20(PID)-0x20(32ID)   31-0x1F(PID)-0x1F(31 ID) 
/* Notification Flag API, PID and Message ID Access for whole frames */

/* Use only with LIN 2.0 */
#define        l_get_msg_id_low_frame(x)     (g_lin_frame_ctrl[(x)].frame.msg_id.lo)
#define        l_get_msg_id_high_frame(x)    (g_lin_frame_ctrl[(x)].frame.msg_id.hi)
/* Use only with LIN 2.X */
#define        l_get_pid_frame(x)            (g_lin_frame_ctrl[(x)].frame.pid)
#define        l_set_pid_frame(x,y)          (g_lin_frame_ctrl[(x)].frame.pid = (y))
#define        l_flg_tst_frm_MotorCtrl()    (g_lin_frame_ctrl[0].frame.frame_type.update_flag == 1u)
#define        l_flg_clr_frm_MotorCtrl()    (g_lin_frame_ctrl[0].frame.frame_type.update_flag = 0u)
#define        LIN_FRAME_MotorCtrl()    (g_lin_frame_ctrl[0].frame.pid)
#define        LIN_CHANGE_PID_FRAME_MotorCtrl(x)    (g_lin_frame_ctrl[0].frame.pid = (x))
#define        LIN_FRAME_LOW_MotorCtrl_MSG_ID()    (g_lin_frame_ctrl[0].frame.msg_id.lo)
#define        LIN_FRAME_HIGH_MotorCtrl_MSG_ID()    (g_lin_frame_ctrl[0].frame.msg_id.hi)
#define        l_flg_tst_frm_MotorStatus()    (g_lin_frame_ctrl[1].frame.frame_type.update_flag == 1u)
#define        l_flg_clr_frm_MotorStatus()    (g_lin_frame_ctrl[1].frame.frame_type.update_flag = 0u)
#define        LIN_FRAME_MotorStatus()    (g_lin_frame_ctrl[1].frame.pid)
#define        LIN_CHANGE_PID_FRAME_MotorStatus(x)    (g_lin_frame_ctrl[1].frame.pid = (x))
#define        LIN_FRAME_LOW_MotorStatus_MSG_ID()    (g_lin_frame_ctrl[1].frame.msg_id.lo)
#define        LIN_FRAME_HIGH_MotorStatus_MSG_ID()    (g_lin_frame_ctrl[1].frame.msg_id.hi)

/* Signal Attributes */

/* Signal to Frame Mapping and Signal Update Flags */

typedef union
{
  struct
  {
    l_u16 RefSpeed_f  : 1;
    l_u16 res00  : 7;
    l_u16 res01  : 8;
  } flags;
  l_u16 reg[1];
} t_l_flags_MotorCtrl;

extern volatile t_l_flags_MotorCtrl l_flags_MotorCtrl;

typedef union
{
  struct
  {
    l_u16 ActSpeed_f  : 1;
    l_u16 Error_f  : 1;
    l_u16 res00  : 6;
    l_u16 res01  : 8;
  } flags;
  l_u16 reg[1];
} t_l_flags_MotorStatus;

extern volatile t_l_flags_MotorStatus l_flags_MotorStatus;


typedef union
{
  struct
  {
    l_u16 ActCurrent_f  : 1;
    l_u16 Error_f  : 1;
    l_u16 res00  : 6;
    l_u16 res01  : 8;
  } flags;
  l_u16 reg[1];
} t_l_flags_MotorStatus_DIAG;

extern volatile t_l_flags_MotorStatus_DIAG l_flags_MotorStatus_DIAG;


typedef union
{
  struct
  {
    l_u16 Act0x1B_f  : 1;
    l_u16 Error_f  : 1;
    l_u16 res00  : 6;
    l_u16 res01  : 8;
  } flags;
  l_u16 reg[1];
} t_l_flags_MotorStatus_0x1B;

extern volatile t_l_flags_MotorStatus_0x1B l_flags_MotorStatus_0x1B;

typedef union
{
  struct
  {
    l_u16 Act0x1C_f  : 1;
    l_u16 Error_f  : 1;
    l_u16 res00  : 6;
    l_u16 res01  : 8;
  } flags;
  l_u16 reg[1];
} t_l_flags_MotorStatus_0x1D;

extern volatile t_l_flags_MotorStatus_0x1D l_flags_MotorStatus_0x1D;




typedef union
{
  l_u8    frame_data[8];
  l_u8    *dataptr;
} t_l_FrmData;

typedef union
{
  l_u8    dataBytes[40];
  struct
  {
    t_l_FrmData    l_frm_MotorCtrl;
    t_l_FrmData    l_frm_MotorStatus;
		t_l_FrmData    l_frm_MotorStatus_DIAG;
		t_l_FrmData    l_frm_MotorStatus_0x1B;
		t_l_FrmData    l_frm_MotorStatus_0x1D;
		
  } frames;
  t_l_FrmData    Frame[LIN_NUMBER_OF_FRAMES];
} t_l_Lin_Data;
extern  t_l_Lin_Data    l_LinData;

/* Signal Access Macros */

/* Signal Read Access for Signal RefSpeed */

#define        l_u8_rd_CrcCalculation()    (l_LinData.frames.l_frm_MotorCtrl.frame_data[0])^\
																					 (l_LinData.frames.l_frm_MotorCtrl.frame_data[1])^\
																					 (l_LinData.frames.l_frm_MotorCtrl.frame_data[2])^\
																					 (l_LinData.frames.l_frm_MotorCtrl.frame_data[3])^\
																					 (l_LinData.frames.l_frm_MotorCtrl.frame_data[4])^\
																					 (l_LinData.frames.l_frm_MotorCtrl.frame_data[5])^\
																					 (l_LinData.frames.l_frm_MotorCtrl.frame_data[6])

//#define        l_u8_rd_Crc()      (l_u8)((l_LinData.frames.l_frm_MotorCtrl.frame_data[0])& 0xFF)
#define        l_u8_rd_OilPmpTemp()      (l_u8)((l_LinData.frames.l_frm_MotorCtrl.frame_data[0])& 0xFF)  //jili

//#define        _s_WRITE_SPEED_0    (l_u8)(l_LinData.frames.l_frm_MotorCtrl.frame_data[2])
//#define        _s_WRITE_SPEED_1    (l_u8)(l_LinData.frames.l_frm_MotorCtrl.frame_data[3])

//#define        l_u16_rd_RefSpeed()    (l_u16)((l_LinData.frames.l_frm_MotorCtrl.frame_data[2])|\
                                    (((l_LinData.frames.l_frm_MotorCtrl.frame_data[3])&(255u))<<8u))
#define        l_u16_rd_RefSpeed()    (l_u16)((l_LinData.frames.l_frm_MotorCtrl.frame_data[1])|\
                                    (((l_LinData.frames.l_frm_MotorCtrl.frame_data[2])&(0x1F))<<8u))    //jili


#define        l_u8_rd_CrashValue()      (l_u8)(((l_LinData.frames.l_frm_MotorCtrl.frame_data[2])& 0x20)>>5)  //jili

#define        l_u8_rd_OpcStartOn()      (l_u8)(((l_LinData.frames.l_frm_MotorCtrl.frame_data[2])& 0x40)>>6)  //jili

#define        l_u8_rd_RollingCounter()    (l_u8)(((l_LinData.frames.l_frm_MotorCtrl.frame_data[6])& 0xF0)>>4)  //jili RollingCounter
#define        l_u8_rd_Crc()               (l_u8)(((l_LinData.frames.l_frm_MotorCtrl.frame_data[7])& 0xFF)>>0)  //jili CRC




//#define        _s_REQ_POST_RUN_SPEED_0    (l_u8)(l_LinData.frames.l_frm_MotorCtrl.frame_data[4])
//#define        _s_REQ_POST_RUN_SPEED_1    (l_u8)(l_LinData.frames.l_frm_MotorCtrl.frame_data[5])

//#define        l_u16_rd_REQPOSTRUNSPEED()    (l_u16)((l_LinData.frames.l_frm_MotorCtrl.frame_data[4])|\
                                              (((l_LinData.frames.l_frm_MotorCtrl.frame_data[5])&(255u))<<8u))



//#define        _s_REQ_POST_RUN_DURATION_0    (l_u8)(l_LinData.frames.l_frm_MotorCtrl.frame_data[6])
//#define        _s_REQ_POST_RUN_DURATION_1    ((l_LinData.frames.l_frm_MotorCtrl.frame_data[7])&(0x0F))

//#define        l_u16_rd_REQPOSTRUNDURATION()    (l_u16)((l_LinData.frames.l_frm_MotorCtrl.frame_data[6])|\
                                              (((l_LinData.frames.l_frm_MotorCtrl.frame_data[7])&(0x0F))<<8u))

//#define        _s_WRITE_STATUS      (l_u8)(((l_LinData.frames.l_frm_MotorCtrl.frame_data[7])& 0xF0)>>4u)       
//#define        l_u8_rd_Status()    (l_u8)(((l_LinData.frames.l_frm_MotorCtrl.frame_data[7])& 0xF0)>>4u)
                                    



#define        l_flg_tst_RefSpeed()    (l_flags_MotorCtrl.flags.RefSpeed_f == 1u)
#define        l_flg_clr_RefSpeed()    (l_flags_MotorCtrl.flags.RefSpeed_f = 0u)

#define        l_flg_tst_ActSpeed()    (l_flags_MotorStatus.flags.ActSpeed_f == 1u)
#define        l_flg_clr_ActSpeed()    (l_flags_MotorStatus.flags.ActSpeed_f = 0u)

#define        l_flg_tst_ActCurrent()    (l_flags_MotorStatus_DIAG.flags.ActCurrent_f == 1u)
#define        l_flg_clr_ActCurrent()    (l_flags_MotorStatus_DIAG.flags.ActCurrent_f = 0u)

#define        l_flg_tst_Act0x1B()    (l_flags_MotorStatus_0x1B.flags.Act0x1B_f == 1u)
#define        l_flg_clr_Act0x1B()    (l_flags_MotorStatus_0x1B.flags.Act0x1B_f = 0u)

#define        l_flg_tst_Act0x1D()    (l_flags_MotorStatus_DIAG.flags.Act0x1D_f == 1u)
#define        l_flg_clr_Act0x1D()    (l_flags_MotorStatus_DIAG.flags.Act0x1D_f = 0u)



//#define        l_u8_wr_READ_SPEED_CRC(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[0]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[0]|=((l_u8)((x)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)

#define        l_u8_wr_McuTemp(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[0]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[0]|=((l_u8)((x)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

#define        l_u8_wr_MosTemp(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[1]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[1]|=((l_u8)((x)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

#define        l_u8_wr_BatteryVoltage(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[2]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[2]|=((l_u8)((x)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

#define        l_u16_wr_ActSpeed(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[3]&=(0x00u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[4]&=(0xE0u); \
	                                  l_LinData.frames.l_frm_MotorStatus.frame_data[3]|=(l_u8)((l_u16)((x&0xFF)<<0u)); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[4]|=(l_u8)((l_u16)(((x)>>8u) & 0x1F )); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)             //jili

#define        l_u8_wr_Mostempsensorfault(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[4]&=(0xDFu); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[4]|=((l_u8)((x & 0x01)<<5u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

#define        l_u8_wr_Mostempsensorrangefault(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[4]&=(0xBFu); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[4]|=((l_u8)((x & 0x01)<<6u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili
#define        l_u8_wr_Mcutempsensorvoltagedetection(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[4]&=(0x7Fu); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[4]|=((l_u8)((x & 0x01)<<7u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

																		
#define        l_u8_wr_SpdBaseAngleValueSts(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0xFEu); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=((l_u8)((x & 0x01)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili
#define        l_u8_wr_SpdBaseUVWIncPosSts(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0xFDu); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=((l_u8)((x & 0x01)<<1u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

#define        l_u8_wr_McuTOutRngSts(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0xFBu); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=((l_u8)((x & 0x01)<<2u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili
																		
																		
#define        l_u8_wr_IgnitionStatus(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0xF7u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=((l_u8)((x & 0x01)<<3u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

#define        l_u8_wr_RollingCounter_32(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0x0Fu); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=((l_u8)((x & 0x0F)<<4u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

	
#define        l_u8_CheckSum32_Value       (l_LinData.frames.l_frm_MotorStatus.frame_data[0])^\
																					 (l_LinData.frames.l_frm_MotorStatus.frame_data[1])^\
																					 (l_LinData.frames.l_frm_MotorStatus.frame_data[2])^\
																					 (l_LinData.frames.l_frm_MotorStatus.frame_data[3])^\
																					 (l_LinData.frames.l_frm_MotorStatus.frame_data[4])^\
																					 (l_LinData.frames.l_frm_MotorStatus.frame_data[5])^\
																					 (l_LinData.frames.l_frm_MotorStatus.frame_data[6])
																		
																	
																		
#define        l_u8_wr_CheckSum_32(x)   do{ l_LinData.frames.l_frm_MotorStatus.frame_data[7]&=(0x00u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[7]|=((l_u8)((x & 0xFF)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

																		
																		

//#define       _s_READ_ACTUAL_SPEED_0				l_LinData.frames.l_frm_MotorStatus.frame_data[1]														
//#define       _s_READ_ACTUAL_SPEED_1				l_LinData.frames.l_frm_MotorStatus.frame_data[2]																			
																		
																		
/* Signal Write Access for Signal ActSpeed */																		
//#define        l_u16_wr_ActSpeed(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[1]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[2]&=(0u); \
	                                  l_LinData.frames.l_frm_MotorStatus.frame_data[1]|=(l_u8)((l_u16)((x)<<0u)); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[2]|=(l_u8)((l_u16)((x)>>8u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)

/* Signal Write Access for Signal Error */
//#define        l_bool_wr_Error(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[2]&=(254u); \
//                                    l_LinData.frames.l_frm_MotorStatus.frame_data[2]|=((l_u8)((x)<<0u)); \
//                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
//                                    }while(0)

#define        l_bool_wr_Error(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[0]&=(255u); \
																l_LinData.frames.l_frm_MotorStatus.frame_data[0]|=((l_u8)(0u)); \
																g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
																}while(0)
																		
																		

//#define        l_u8_wr_READ_AC(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[3]&=(0u); \
																l_LinData.frames.l_frm_MotorStatus.frame_data[3]|=(l_u8)((l_u16)((x)<<0u)); \
																g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
																}while(0)

															
//#define    	 _s_READ_OIL_TEMPERATURE			l_LinData.frames.l_frm_MotorStatus.frame_data[4]											
															

/* Signal Write Access for Signal ChipTemp */
//#define        l_u8_wr_ActoilTemp(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[4]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[4]|=(l_u8)(((x)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)																		
																		
/* Signal Write Access for Signal ChipTemp */
//#define        l_u16_wr_ActSysVoltage(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[5]&=(0u); \
//                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0u); \
//                                    l_LinData.frames.l_frm_MotorStatus.frame_data[5]|=(l_u8)((l_u16)((x)<<0u)); \
//                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=(l_u8)((l_u16)((x)>>8u)); \
//                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
//                                    }while(0)																			
																		
/* Signal Write Access for Signal ChipTemp */
//#define        l_u8_wr_Actoilpressure(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[5]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[5]|=(l_u8)(((x)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)	

																		
//#define    	 _s_READ_OIL_PRESSURE			l_LinData.frames.l_frm_MotorStatus.frame_data[5]																			
																		
																		
																		
/* Signal Write Access for Signal ChipTemp */
//#define        l_u8_wr_Actoilstatus(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0xF0); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=(l_u8)(((x)& 0x0F)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)																			
		
//#define 			_s_READ_STATUS	  		l_LinData.frames.l_frm_MotorStatus.frame_data[6]				


//#define        l_u8_wr_RESERVED(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[6]&=(0x0F); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[6]|=(l_u8)(((x << 4)& 0xF0)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)																			
	

//#define 			_s_RESERVED	  		((l_LinData.frames.l_frm_MotorStatus.frame_data[6] >>4)& 0x0F)																		
																		
/* Signal Write Access for Signal ChipTemp */
//#define        l_u8_wr_Ntctemp(x)    do{ l_LinData.frames.l_frm_MotorStatus.frame_data[7]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus.frame_data[7]|=(l_u8)(((x)<<0u)); \
                                    g_lin_frame_ctrl[1].frame.frame_type.update_flag = 1u; \
                                    }while(0)																			
																		
																
//#define 			_s_RESERVED3	  		l_LinData.frames.l_frm_MotorStatus.frame_data[7]																			
																		
		
#define       l_u8_wr_PhaseOverCurrentFault(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0xFEu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<0u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

#define       l_u8_wr_PumpSystemFailed(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0xFDu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<1u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

#define       l_u8_wr_ZeropositionLearnt(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0xFBu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<2u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

																		
#define       l_u8_wr_MotorStallFault(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0xF7u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<3u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

#define       l_u8_wr_MosSelfcheckFailure(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0xEFu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<4u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

#define       l_u8_wr_GduOverCurrent(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0xDFu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<5u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

#define       l_u8_wr_CanNodeLoss(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0xBFu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<6u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

#define       l_u8_wr_BaseVoltagecheckFailure(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0x7Fu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)(((x&0x01)<<7u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

																		
#define       l_u8_wr_MosOvertemp(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]&=(0xFEu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]|=(l_u8)(((x&0x01)<<0u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

																																				
#define       l_u8_wr_AngleSensorFault(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]&=(0xFDu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]|=(l_u8)(((x&0x01)<<1u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili
																		
																		
#define       l_u8_wr_GduandBatteryOverVoltage(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]&=(0xF3u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]|=(l_u8)(((x&0x03)<<2u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili

																		
#define       l_u8_wr_UnderGduandBatteryVoltage(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]&=(0xCFu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]|=(l_u8)(((x&0x03)<<4u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili																		
																		
#define       l_u8_wr_UnderSpeedModeStatus(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]&=(0x3Fu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]|=(l_u8)(((x&0x03)<<6u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili																				
																		
																		
#define        l_u16_wr_Buscurrent(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[2]&=(0x00u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]&=(0xFCu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[2]|=(l_u8)((l_u16)((x&0xFF)<<0u)); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]|=(l_u8)((l_u16)(((x)>>8u)& 0x03)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)																	
																		
																		
#define       l_u8_wr_RollingCounterFault(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]&=(0xFBu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]|=(l_u8)(((x&0x01)<<2u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili		

#define       l_u8_wr_ChecksumFault(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]&=(0xF7u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]|=(l_u8)(((x&0x01)<<3u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili	


#define       l_u8_wr_RunningStatus(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]&=(0x0Fu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]|=(l_u8)(((x&0x0F)<<4u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili	

																		
#define				l_u8_wr_EOP_OffCmdRecFb(x)   do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[4]&=(0xFEu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[4]|=(l_u8)(((x&0x01)<<0u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili													
																		
																		

#define       l_u8_wr_SPICommunicationError(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]&=(0xFEu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]|=(l_u8)(((x&0x01)<<0u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		 //jili																			
																		
#define        l_u16_wr_Phasecurrent(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]&=(0x01u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6]&=(0xF0u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]|=(l_u8)((l_u16)((x&0x7F)<<1u)); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6]|=(l_u8)((l_u16)(((x>>7u)&0x0F)<<0u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)																				
																		
	#define        l_u8_wr_RollingCounter_31(x)   do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6]&=(0x0Fu); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6]|=((l_u8)((x & 0x0F)<<4u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili

	
#define        l_u8_CheckSum31_Value       (l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0])^\
																					 (l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1])^\
																					 (l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[2])^\
																					 (l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3])^\
																					 (l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[4])^\
																					 (l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5])^\
																					 (l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6])
																		
																	
																		
#define        l_u8_wr_CheckSum_31(x)   do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]&=(0x00u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]|=((l_u8)((x & 0xFF)<<0u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)              //jili																	
																		
																		
																		
/* Signal Write Access for Signal Readcurrent */
//#define        l_u16_wr_Readcurrent(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[0]|=(l_u8)((l_u16)((x)<<0u)); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[1]|=(l_u8)((l_u16)((x)>>8u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)

																		
/* Signal Write Access for Signal Readvoltage */
//#define        l_u16_wr_Readvoltage(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[2]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[2]|=(l_u8)((l_u16)((x)<<0u)); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[3]|=(l_u8)((l_u16)((x)>>8u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)

//ELOP FAULT
//#define       l_u8_wr_ElopFault(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[4]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[4]|=(l_u8)(((x)<<0u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		

//Supplier
//#define        l_u8_wr_INFO_QS(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]&=(0xF0); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]|=(l_u8)(((x)& 0x0F)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)		


//相电�?																
//#define        l_u16_wr_Phasecurrent(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]&=(0x0F); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6]&=(0u); \
	                                  l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]&=(0xF0); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[5]|=(l_u8)((l_u16)(((x)& 0x0F)<<4u)); \
	                                  l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6]|=(l_u8)((l_u16)(((x)& 0xF0)>>4u)); \
	                                  l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[6]|=(l_u8)((l_u16)((((x)>>8u)& 0x0F)<<4u)); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]|=(l_u8)((l_u16)((((x)>>8u)& 0xF0)>>4u)); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)																	
	

//MOTOR BLOCK																		
//#define        l_u8_wr_MotorBlock(x)    do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]&=(0xEF); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]|=(l_u8)(((x)& 0x01)<<4u); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)					

																		
//#define        l_u8_wr_RESERVED2(x)     do{ l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]&=(0x1F); \
                                    l_LinData.frames.l_frm_MotorStatus_DIAG.frame_data[7]|=(l_u8)(((x)& 0x07)<<5u); \
                                    g_lin_frame_ctrl[2].frame.frame_type.update_flag = 1u; \
                                    }while(0)																						
			

#define	    l_u16_wr_0x1BMotCtrlgetReferenceSpeed(x)      do{ l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[0]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[1]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[0]|=(l_u8)((l_u16)((x)<<0u)); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[1]|=(l_u8)((l_u16)((x)>>8u)); \
																															g_lin_frame_ctrl[3].frame.frame_type.update_flag = 1u; \
																															}while(0) 

#define			l_u16_wr_0x1BMotCtrlgetReferenceQaxCurrs16(x)     do{ l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[2]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[3]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[2]|=(l_u8)((l_u16)((x)<<0u)); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[3]|=(l_u8)((l_u16)((x)>>8u)); \
																															g_lin_frame_ctrl[3].frame.frame_type.update_flag = 1u; \
																															}while(0) 

#define			l_u16_wr_0x1BMotCtrlgetActualQaxCurrs16(x)        do{ l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[4]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[5]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[4]|=(l_u8)((l_u16)((x)<<0u)); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[5]|=(l_u8)((l_u16)((x)>>8u)); \
																															g_lin_frame_ctrl[3].frame.frame_type.update_flag = 1u; \
																															}while(0) 

																															
#define			l_u16_wr_0x1BPhasecurrent(x)                         do{ l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[6]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[7]&=(0u); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[6]|=(l_u8)((l_u16)((x)<<0u)); \
																															l_LinData.frames.l_frm_MotorStatus_0x1B.frame_data[7]|=(l_u8)((l_u16)((x)>>8u)); \
																															g_lin_frame_ctrl[3].frame.frame_type.update_flag = 1u; \
																															}while(0) 

																															
																															

#define        l_u16_wr_0x1DerrOBDCode(x)    do{ l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[0]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[1]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[0]|=(l_u8)((l_u16)((x)<<0u)); \
                                    l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[1]|=(l_u8)((l_u16)((x)>>8u)); \
                                    g_lin_frame_ctrl[4].frame.frame_type.update_flag = 1u; \
                                    }while(0)

																		
//ELOP FAULT
#define      l_u8_wr_0x1Dct9140Fualt(x)    do{ l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[2]&=(0u); \
                                    l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[2]|=(l_u8)(((x)<<0u)); \
                                    g_lin_frame_ctrl[4].frame.frame_type.update_flag = 1u; \
                                    }while(0)																				
																		
/* Signal Write Access for Signal Readvoltage */
#define        l_u8_wr_0x1DMotCtlgetFault(x)     do{ l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[3]&=(0u); \
																											l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[3]|=(l_u8)(((x)<<0u)); \
																											g_lin_frame_ctrl[4].frame.frame_type.update_flag = 1u; \
																											}while(0)			


#define 		  l_u16_wr_0x1Dreserved1(x)     do{ l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[4]&=(0u); \
																								l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[5]&=(0u); \
																								l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[4]|=(l_u8)((l_u16)((x)<<0u)); \
																								l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[5]|=(l_u8)((l_u16)((x)>>8u)); \
																								g_lin_frame_ctrl[4].frame.frame_type.update_flag = 1u; \
																								}while(0)

																		
/*#define 			l_u8_wr_0x1Dreserved2(x)        do{ l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[6]&=(0u); \
																											l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[6]|=(l_u8)(((x)<<0u)); \
																											g_lin_frame_ctrl[4].frame.frame_type.update_flag = 1u; \
																											}while(0)	

																											
#define 			l_u8_wr_0x1Dreserved3(x)		      do{ l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[7]&=(0u); \
																											l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[7]|=(l_u8)(((x)<<0u)); \
																											g_lin_frame_ctrl[4].frame.frame_type.update_flag = 1u; \
																											}while(0)				*/	

#define 		  l_u16_wr_0x1Dreserved2(x)     do{ l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[6]&=(0u); \
																								l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[7]&=(0u); \
																								l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[6]|=(l_u8)((l_u16)((x)<<0u)); \
																								l_LinData.frames.l_frm_MotorStatus_0x1D.frame_data[7]|=(l_u8)((l_u16)((x)>>8u)); \
																								g_lin_frame_ctrl[4].frame.frame_type.update_flag = 1u; \
																								}while(0)																								
																															
																		

/* Lin Driver Access to Update Signal Flags for Frame MotorCtrl */
#define        l_Update_flags_frame0() l_flags_MotorCtrl.reg[0]=(l_u16)0xFFFF;

/* Lin Driver Access to Update Signal Flags for Frame MotorStatus */
#define        l_Update_flags_frame1() l_flags_MotorStatus.reg[0]=(l_u16)0xFFFF;

#define        l_Update_flags_frame2() l_flags_MotorStatus_DIAG.reg[0]=(l_u16)0xFFFF;

#define        l_Update_flags_frame3() l_flags_MotorStatus_0x1B.reg[0]=(l_u16)0xFFFF;
#define        l_Update_flags_frame4() l_flags_MotorStatus_0x1D.reg[0]=(l_u16)0xFFFF;																		

#define        l_Update_flags_frame(x) l_Update_Frame_Flags((x))
void l_Update_Frame_Flags(l_u8 number);

/* Prototype for Byte Array Signal Access Function  */
void l_get_byte_array(l_u8 start[], l_u8  count, l_u8 destination[]);
void l_set_byte_array(l_u8 start[], l_u8  count, const l_u8 source[]);

/* Macros for Response Error Flag / Frame handling */

#define        l_Set_Response_Error_Flag() l_bool_wr_Error(1u)

#define        l_Reset_Response_Error_Flag() l_bool_wr_Error(0u)

//#define        LIN_Response_Error_Frame_PID g_lin_frame_ctrl[1].frame.pid
#define        LIN_Response_Error_Frame_PID g_lin_frame_ctrl[g_lin_frame_index].frame.pid

extern void ComDrv_Set_APPTxMsgData(uint8*TxMsg,uint8 ID);

/* File Footer */
#endif /* end #ifndef GEN_LIN_CONFIG_H */

/* genLinConfig.h file for TLE9879 */



