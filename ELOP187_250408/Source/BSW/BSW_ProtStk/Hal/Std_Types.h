/***********************************************************************************************************************
* File:         Std_Types.h
* Revision:
* Author:
* Date:         30.07.2012
* Description:  Standard Autorsar file - ATTENTION not every specified AUTOSAR definition is used so far
***********************************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H
#include "tle987x.h"


#include "Platform_Types.h"



typedef uint8 Std_ReturnType;

typedef unsigned char Dcm_NegativeResponseCodeType;







/* ARREF:STD006 */
#define E_OK        0
#define E_NOT_OK    1

/* ARREF:STD007 */
#define STD_HIGH    1  /* Physical state 5V or 3.3V */
#define STD_LOW     0  /* Physical state 0V         */

/* ARREF:STD010 */
#define STD_ON      (1u)
#define STD_OFF     (0u)

/* ARREF:STD013 */
#define STD_ACTIVE  1  /* Logical state active */
#define STD_IDLE    0  /* Logical state idle   */

#ifndef TRUE
   #define TRUE      1
   #define RB_DATATYPES_TRUE   (1U)
#endif
#ifndef FALSE
    #define FALSE     0
    #define RB_DATATYPES_FALSE  (0U)
#endif

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/

#endif // STD_TYPES_H
