/*
 * typedefs.h
 *
 *  Created on: 2017-12-26
 *      Author: Devon
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

typedef signed char int8_t;
typedef short int   int16_t;
//typedef long int    int32_t;
typedef  int    int32_t;

typedef unsigned char		uint8_t;
typedef unsigned short int  uint16_t;
//typedef unsigned long int   uint32_t;
typedef unsigned  int   uint32_t;


typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

#ifndef bool
    typedef uint8_t bool;
#endif

#ifndef FALSE
    #define FALSE (0u)
#endif

#ifndef TRUE
    #define TRUE  (1u)
#endif

#ifndef NULL
    #define NULL (0u)
#endif

//#ifndef NULL_PTR
//    #define NULL_PTR ((void *)0)
//#endif

#endif /* TYPEDEFS_H_ */
