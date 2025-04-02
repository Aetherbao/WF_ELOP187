/* 
 * File:   Uds_DspCfg.h
 * Author: 
 *
 * Created on 2024.6.26
 */

#ifndef UDS_DSPCFG_H
#define	UDS_DSPCFG_H

//#include "ComIf_UdsDspCfg.h"



#define 	  BMS_NAD		        (0x01)  //(0x08)

#define 	  FUNC_AD		        (0x7E)
#define 	  BOARD_AD		      (0x7F)

#define     LIN_TP_PADDING	  (0xFF)




#if 0

/***********************************************27服务相关配置******************************************/
//程序支持的安全等级
#define     SECURITY_LEAVEL0                                0x0
#define     SECURITY_LEAVEL1                                0x01
#define     SECURITY_LEAVEL9                                0x9 
#define     SECURITY_LEAVEL41                               0x29

//27 01和27 02
#if defined(DCM_SERVICE_27_SUB01)|| defined(DCM_SERVICE_27_SUB02)
#define     POWERONDELAY_SECURITY_LEAVEL1                   1000      //上电后，27服务不允许运行的时间，以DcmTaskTime的周期为单位
#define     DELAYTIME_SECURITY_LEAVEL1                      1000      // 在安全访问失败后的延迟时间，以DcmTaskTime的周期为单位
#define     SECURITY_SEED_SIZE_LEAVEL1                      4         //27安全访问seed的长度
#define     SECURITY_KEY_SIZE_LEAVEL1                       4         //27安全访问key的长度
#define     NUM_ACTIVEDELAY_LEAVEL1                         2         //延迟时间激活之前的安全访问失败次数
#define     NUM_LOCKSECURITY_LEAVEL1                        0         //安全访问被锁定之前，安全访问失败次数
#endif

//27 11和27 12
#if defined(DCM_SERVICE_27_SUB11)|| defined(DCM_SERVICE_27_SUB12)
#define     POWERONDELAY_SECURITY_LEAVEL9                   1         //上电后，27服务不允许运行的时间，以DcmTaskTime的周期为单位
#define     DELAYTIME_SECURITY_LEAVEL9                      2000        //10s 在安全访问失败后的延迟时间，以DcmTaskTime的周期为单位
#define     SECURITY_SEED_SIZE_LEAVEL9                      4         //27安全访问seed的长度
#define     SECURITY_KEY_SIZE_LEAVEL9                       4         //27安全访问key的长度
#define     NUM_ACTIVEDELAY_LEAVEL9                         3         //延迟时间激活之前的安全访问失败次数
#define     NUM_LOCKSECURITY_LEAVEL9                        0         //安全访问被锁定之前，安全访问失败次数
#endif

/*************************************************END********************************************************/


/***********************************************22/2E服务相关配置******************************************/
#define    DSP_INFO_NUMBER                                  45    //22和2E 2F服务支持的did总数量



#define    DATA_DID_01                0x0100     //R
#define    DATA_DID_02                0x0101     //R
#define    DATA_DID_03                0x0103     //R
#define    DATA_DID_04                0x04C1     //R
#define    DATA_DID_05                0x04C5     //R
#define    DATA_DID_06                0x04C7     //R
#define    DATA_DID_07                0x04C8     //R
#define    DATA_DID_08                0xD000     //R
#define    DATA_DID_09                0xD001     //R
#define    DATA_DID_10                0xD002     //R
#define    DATA_DID_11                0xD003     //R
#define    DATA_DID_12                0xD004     //R
#define    DATA_DID_13                0xD005     //R
#define    DATA_DID_14                0xD010     //R/W
#define    DATA_DID_15                0xD011     //R/W 
#define    DATA_DID_16                0xD012     //R/W
#define    DATA_DID_17                0xD100     //R  
#define    DATA_DID_18                0xD102     //R
#define    DATA_DID_19                0xD103     //R
#define    DATA_DID_20                0xD104     //R
#define    DATA_DID_21                0xD105     //R 
#define    DATA_DID_22                0xD106     //R
#define    DATA_DID_23                0xD107     //R 
#define    DATA_DID_24                0xD108     //R 
#define    DATA_DID_25                0xD110     //R
#define    DATA_DID_26                0xD118     //R 
#define    DATA_DID_27                0xD119     //R
#define    DATA_DID_28                0xD200     //IOCBI
#define    DATA_DID_29                0xD201     //R 
#define    DATA_DID_30                0xD202     //R
#define    DATA_DID_31                0xE15C     //R/W 
#define    DATA_DID_32                0xE15D     //R/W
#define    DATA_DID_33                0xE15E     //R 
#define    DATA_DID_34                0xE15F     //R
#define    DATA_DID_35                0xF100     //R 
#define    DATA_DID_36                0xF101     //R/W
#define    DATA_DID_37                0xF15A     //R/W 
#define    DATA_DID_38                0xF180     //R 
#define    DATA_DID_39                0xF187     //R/W
#define    DATA_DID_40                0xF18A     //R/W
#define    DATA_DID_41                0xF192     //R/W
#define    DATA_DID_42                0xF193     //R  
#define    DATA_DID_43                0xF194     //R/W
#define    DATA_DID_44                0xF195     //R  
#define    DATA_DID_45                0xFE00     //R
  





//各did的读处理函数在Dcm_DspDataInfo_st的index
#define    INDEX_TO_READFUNC_01                           0
#define    INDEX_TO_READFUNC_02                           1
#define    INDEX_TO_READFUNC_03                           2
#define    INDEX_TO_READFUNC_04                           3
#define    INDEX_TO_READFUNC_05                           4
#define    INDEX_TO_READFUNC_06                           5
#define    INDEX_TO_READFUNC_07                           6
#define    INDEX_TO_READFUNC_08                           7
#define    INDEX_TO_READFUNC_09                           8
#define    INDEX_TO_READFUNC_10                           9
#define    INDEX_TO_READFUNC_11                           10
#define    INDEX_TO_READFUNC_12                           11
#define    INDEX_TO_READFUNC_13                           12
#define    INDEX_TO_READFUNC_14                           13
#define    INDEX_TO_READFUNC_15                           14
#define    INDEX_TO_READFUNC_16                           15
#define    INDEX_TO_READFUNC_17                           16
#define    INDEX_TO_READFUNC_18                           17
#define    INDEX_TO_READFUNC_19                           18
#define    INDEX_TO_READFUNC_20                           19
#define    INDEX_TO_READFUNC_21                           20
#define    INDEX_TO_READFUNC_22                           21
#define    INDEX_TO_READFUNC_23                           22
#define    INDEX_TO_READFUNC_24                           23
#define    INDEX_TO_READFUNC_25                           24
#define    INDEX_TO_READFUNC_26                           25
#define    INDEX_TO_READFUNC_27                           26
#define    INDEX_TO_READFUNC_28                           27
#define    INDEX_TO_READFUNC_29                           28
#define    INDEX_TO_READFUNC_30                           29
#define    INDEX_TO_READFUNC_31                           30
#define    INDEX_TO_READFUNC_32                           31
#define    INDEX_TO_READFUNC_33                           32
#define    INDEX_TO_READFUNC_34                           33
#define    INDEX_TO_READFUNC_35                           34
#define    INDEX_TO_READFUNC_36                           35
#define    INDEX_TO_READFUNC_37                           36
#define    INDEX_TO_READFUNC_38                           37
#define    INDEX_TO_READFUNC_39                           38
#define    INDEX_TO_READFUNC_40                           39
#define    INDEX_TO_READFUNC_41                           40
#define    INDEX_TO_READFUNC_42                           41
#define    INDEX_TO_READFUNC_43                           42
#define    INDEX_TO_READFUNC_44                           43
#define    INDEX_TO_READFUNC_45                           44


//各did的写处理函数在Dcm_DspDataInfo_st的index
#define    INDEX_TO_WRITEFUNC_01                           0
#define    INDEX_TO_WRITEFUNC_02                           1
#define    INDEX_TO_WRITEFUNC_03                           2
#define    INDEX_TO_WRITEFUNC_04                           3
#define    INDEX_TO_WRITEFUNC_05                           4
#define    INDEX_TO_WRITEFUNC_06                           5
#define    INDEX_TO_WRITEFUNC_07                           6
#define    INDEX_TO_WRITEFUNC_08                           7
#define    INDEX_TO_WRITEFUNC_09                           8
#define    INDEX_TO_WRITEFUNC_10                           9
#define    INDEX_TO_WRITEFUNC_11                           10
#define    INDEX_TO_WRITEFUNC_12                           11
#define    INDEX_TO_WRITEFUNC_13                           12
#define    INDEX_TO_WRITEFUNC_14                           13
#define    INDEX_TO_WRITEFUNC_15                           14
#define    INDEX_TO_WRITEFUNC_16                           15
#define    INDEX_TO_WRITEFUNC_17                           16
#define    INDEX_TO_WRITEFUNC_18                           17
#define    INDEX_TO_WRITEFUNC_19                           18
#define    INDEX_TO_WRITEFUNC_20                           19
#define    INDEX_TO_WRITEFUNC_21                           20
#define    INDEX_TO_WRITEFUNC_22                           21
#define    INDEX_TO_WRITEFUNC_23                           22
#define    INDEX_TO_WRITEFUNC_24                           23
#define    INDEX_TO_WRITEFUNC_25                           24
#define    INDEX_TO_WRITEFUNC_26                           25
#define    INDEX_TO_WRITEFUNC_27                           26
#define    INDEX_TO_WRITEFUNC_28                           27
#define    INDEX_TO_WRITEFUNC_29                           28
#define    INDEX_TO_WRITEFUNC_30                           29
#define    INDEX_TO_WRITEFUNC_31                           30
#define    INDEX_TO_WRITEFUNC_32                           31
#define    INDEX_TO_WRITEFUNC_33                           32
#define    INDEX_TO_WRITEFUNC_34                           33
#define    INDEX_TO_WRITEFUNC_35                           34
#define    INDEX_TO_WRITEFUNC_36                           35
#define    INDEX_TO_WRITEFUNC_37                           36
#define    INDEX_TO_WRITEFUNC_38                           37
#define    INDEX_TO_WRITEFUNC_39                           38
#define    INDEX_TO_WRITEFUNC_40                           39
#define    INDEX_TO_WRITEFUNC_41                           40
#define    INDEX_TO_WRITEFUNC_42                           41
#define    INDEX_TO_WRITEFUNC_43                           42
#define    INDEX_TO_WRITEFUNC_44                           43
#define    INDEX_TO_WRITEFUNC_45                           44



//各did的写处理函数在Dcm_SignalDIDSubStructConfig_tst的index

#define    INDEX_TO_IOCBIFUNC_01                           0
#define    INDEX_TO_IOCBIFUNC_02                           1
#define    INDEX_TO_IOCBIFUNC_03                           2
#define    INDEX_TO_IOCBIFUNC_04                           3
#define    INDEX_TO_IOCBIFUNC_05                           4
#define    INDEX_TO_IOCBIFUNC_06                           5
#define    INDEX_TO_IOCBIFUNC_07                           6
#define    INDEX_TO_IOCBIFUNC_08                           7
#define    INDEX_TO_IOCBIFUNC_09                           8
#define    INDEX_TO_IOCBIFUNC_10                           9
#define    INDEX_TO_IOCBIFUNC_11                           10
#define    INDEX_TO_IOCBIFUNC_12                           11
#define    INDEX_TO_IOCBIFUNC_13                           12
#define    INDEX_TO_IOCBIFUNC_14                           13
#define    INDEX_TO_IOCBIFUNC_15                           14
#define    INDEX_TO_IOCBIFUNC_16                           15
#define    INDEX_TO_IOCBIFUNC_17                           16
#define    INDEX_TO_IOCBIFUNC_18                           17
#define    INDEX_TO_IOCBIFUNC_19                           18
#define    INDEX_TO_IOCBIFUNC_20                           19
#define    INDEX_TO_IOCBIFUNC_21                           20
#define    INDEX_TO_IOCBIFUNC_22                           21
#define    INDEX_TO_IOCBIFUNC_23                           22
#define    INDEX_TO_IOCBIFUNC_24                           23
#define    INDEX_TO_IOCBIFUNC_25                           24
#define    INDEX_TO_IOCBIFUNC_26                           25
#define    INDEX_TO_IOCBIFUNC_27                           26
#define    INDEX_TO_IOCBIFUNC_28                           27
#define    INDEX_TO_IOCBIFUNC_29                           28
#define    INDEX_TO_IOCBIFUNC_30                           29
#define    INDEX_TO_IOCBIFUNC_31                           30
#define    INDEX_TO_IOCBIFUNC_32                           31
#define    INDEX_TO_IOCBIFUNC_33                           32
#define    INDEX_TO_IOCBIFUNC_34                           33
#define    INDEX_TO_IOCBIFUNC_35                           34
#define    INDEX_TO_IOCBIFUNC_36                           35
#define    INDEX_TO_IOCBIFUNC_37                           36
#define    INDEX_TO_IOCBIFUNC_38                           37
#define    INDEX_TO_IOCBIFUNC_39                           38
#define    INDEX_TO_IOCBIFUNC_40                           39
#define    INDEX_TO_IOCBIFUNC_41                           40
#define    INDEX_TO_IOCBIFUNC_42                           41
#define    INDEX_TO_IOCBIFUNC_43                           42
#define    INDEX_TO_IOCBIFUNC_44                           43
#define    INDEX_TO_IOCBIFUNC_45                           44



//22或者2E服务数据长度
#define    DATA_BYTE_SIZE_01                               2
#define    DATA_BYTE_SIZE_02                               4
#define    DATA_BYTE_SIZE_03                               7
#define    DATA_BYTE_SIZE_04                               1
#define    DATA_BYTE_SIZE_05                               1
#define    DATA_BYTE_SIZE_06                               1
#define    DATA_BYTE_SIZE_07                               2
#define    DATA_BYTE_SIZE_08                               1
#define    DATA_BYTE_SIZE_09                               2
#define    DATA_BYTE_SIZE_10                               1
#define    DATA_BYTE_SIZE_11                               1
#define    DATA_BYTE_SIZE_12                               1
#define    DATA_BYTE_SIZE_13                               1
#define    DATA_BYTE_SIZE_14                               2
#define    DATA_BYTE_SIZE_15                               2
#define    DATA_BYTE_SIZE_16                               2
#define    DATA_BYTE_SIZE_17                               1
#define    DATA_BYTE_SIZE_18                               2
#define    DATA_BYTE_SIZE_19                               2
#define    DATA_BYTE_SIZE_20                               2
#define    DATA_BYTE_SIZE_21                               1
#define    DATA_BYTE_SIZE_22                               2
#define    DATA_BYTE_SIZE_23                               1
#define    DATA_BYTE_SIZE_24                               1
#define    DATA_BYTE_SIZE_25                               2
#define    DATA_BYTE_SIZE_26                               25
#define    DATA_BYTE_SIZE_27                               6
#define    DATA_BYTE_SIZE_28                               1
#define    DATA_BYTE_SIZE_29                               2
#define    DATA_BYTE_SIZE_30                               2
#define    DATA_BYTE_SIZE_31                               6
#define    DATA_BYTE_SIZE_32                               5
#define    DATA_BYTE_SIZE_33                               7
#define    DATA_BYTE_SIZE_34                               6
#define    DATA_BYTE_SIZE_35                               14
#define    DATA_BYTE_SIZE_36                               9
#define    DATA_BYTE_SIZE_37                               9
#define    DATA_BYTE_SIZE_38                               20
#define    DATA_BYTE_SIZE_39                               15
#define    DATA_BYTE_SIZE_40                               4
#define    DATA_BYTE_SIZE_41                               10
#define    DATA_BYTE_SIZE_42                               6
#define    DATA_BYTE_SIZE_43                               10
#define    DATA_BYTE_SIZE_44                               20
#define    DATA_BYTE_SIZE_45                               8





/*************************************************END********************************************************/


/***********************************************31服务相关配置******************************************/

#define CHECK_PROGRAM_PRECONDITION_ID          0xFA00




/*************************************************END********************************************************/
#endif


#endif	/* UDS_DSPCFG_H */

