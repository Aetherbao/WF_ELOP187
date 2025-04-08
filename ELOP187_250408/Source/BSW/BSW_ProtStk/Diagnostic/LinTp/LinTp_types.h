#ifndef LINTP_TYPES_H_
#define LINTP_TYPES_H_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/
#include "Platform_Types.h"


/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/
#ifndef FALSE
#define FALSE  (0)
#endif

#ifndef TRUE
#define TRUE (1)
#endif

#ifndef NULL_PTR
#define NULL_PTR 	((void *) 0)
#endif

#ifndef NULL
#define NULL		((void) 0)
#endif

//#define APP_RECEIVE_BUF_SIZE	(520)  //(4095)
//#define APP_SEND_BUF_SIZE		(520)    //(4095)


#define APP_RECEIVE_BUF_SIZE	(100)  //(4095)
#define APP_SEND_BUF_SIZE		(100)    //(4095)


/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/
typedef unsigned short int nt_word_t;
typedef unsigned char nt_bool_t;
typedef unsigned char nt_byte_t;
typedef unsigned long int nt_dWord_t;



typedef struct
{
	uint8 length;
	uint8 buffer[8];
}linPduType, * linPduRefType;


typedef enum
{
    NTS_IDLE = 0, /* idle */
    NTS_RX_SF,    /* a SF was be received */
    NTS_RX_FF,    /* a FF was be received */
    NTS_WAIT_CF,  /* wait consecutive frame */
    NTS_APPL_LOCKED, /* application layer locked after a valid request was be received */
    NTS_SEND_SF, /* a SF need to be send */
    NTS_SEND_FF, /* a FF need to be send */
    NTS_SEND_CF  /* one or more CF need to be send */
}lintp_state_t;


typedef enum
{
	LinReq_NotReady = 0,
	LinReq_Ready = 1	
}linReqStatus_t;

typedef struct
{
	uint8 * data;
	uint16 bufSize;
	uint16 rcvdPos;
	uint16 remainDl;
	uint16 requestLen;
	linReqStatus_t reqStatus;
}linDiagReq_Rx_t;



typedef enum
{
	LinResp_NotReady = 0,
	LinResp_Ready = 1	
}linRespStatus_t;


typedef struct
{
	uint8 * data;
	uint16 bufSize;
	uint16 sendPos;
	uint16 responseLen;
	uint8  pdServId;
	linRespStatus_t respStatus;
}linDiagResp_Tx_t;




/*------------------------------------------------------------------------------
                      External declaration of global RAM-Variables
------------------------------------------------------------------------------*/




/*------------------------------------------------------------------------------
                      External declaration of global ROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                    External declaration of global EEPROM-Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                              Declaration of global functions
------------------------------------------------------------------------------*/



#endif

