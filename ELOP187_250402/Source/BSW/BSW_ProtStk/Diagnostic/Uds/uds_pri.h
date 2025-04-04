/*
* Copyright (c) File 2016-08-11,SHENZHEN HANGSHENG NEW ENERGY Co.,Ltd.
* All Rights Reserved.
* Dept.: Software Department
* File:p
* Description:
* REQ IDs:
* History:
* 2017-12-25
*/

/* ---- Source switch on ------------------------------------------------------*/
#ifndef UDS_PRI_H_
#define UDS_PRI_H_

/*------------------------------------------------------------------------------
 					Include files
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                             Defines and constants
------------------------------------------------------------------------------*/
#define servm_positiveResponeCode(servID) ((servID) + 0x40)
#define servm_negativeResponseSID         (0x7Fu)

#define servm_servID_empty                (0xFFu)

#define servm_saLv_allLocked              (0xFFu)
#define servm_saLv_allSeedChecked         (0x00u)

/*------------------------------------------------------------------------------
                                   Data types
------------------------------------------------------------------------------*/



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

