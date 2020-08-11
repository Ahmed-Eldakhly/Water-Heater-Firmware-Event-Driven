/******************************************************************************* 
 * File:                stdtypes.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains typedefs for default data types and general
 *                      user defines.
 * 
 * Revision history:    12/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once.  */
#ifndef STDTYPES_H
#define	STDTYPES_H

/*boolen values defines*/
#ifndef TRUE
#define TRUE                    1u
#endif

#ifndef FALSE                   
#define FALSE                   0u
#endif

#ifndef INPUT
#define INPUT                   1u
#endif

#ifndef OUTPUT
#define OUTPUT                  0u
#endif

#ifndef HIGH
#define HIGH                    1u
#endif

#ifndef LOW
#define LOW                     0u
#endif

#ifndef NULL
#define NULL                    0u
#endif

#ifndef NULL_PTR
#define NULL_PTR                (void*)0x00
#endif

/*typedefs*/
typedef unsigned char           uint8;
typedef signed char             sint8;
typedef unsigned short int      uint16;
typedef signed short int        sint16;
typedef unsigned long int       uint32;
typedef signed long int         sint32;
typedef unsigned long long int  uint64;
typedef signed long long int    sint64;

#endif	/* STDTYPES_H */

