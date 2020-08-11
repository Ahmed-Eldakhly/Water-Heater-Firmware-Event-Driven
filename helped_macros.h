/*******************************************************************************
 *  
 * File:                helped_macros.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains some of defines that used in any program.
 * 
 * Revision history:    13/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included*/
/* more than once.  */  
#ifndef HELPED_MACROS_H
#define	HELPED_MACROS_H

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define SET_BIT(REG,BIT)        REG |= 1 << BIT

#define CLEAR_BIT(REG,BIT)      REG &= ~(1 << BIT)

#define GET_BIT(REG,BIT)        ((REG >> BIT) & 0x01)

#define TOGGLE_BIT(REG,BIT)     REG ^= 1 << BIT 

#define SET_REG(REG)            REG = 0xFF

#define CLEAR_REG(REG)          REG = 0x00

#define GET_REG(REG)            (REG & 0xFF)

#define TOGGLE_REG(REG)         REG ^= 0xFF
 
#define SET_H_NIBBLE(REG)       REG |= 0xF0

#define SET_L_NIBBLE(REG)       REG |= 0x0F

#define CLEAR_H_NIBBLE(REG)     REG &= 0x0F

#define CLEAR_L_NIBBLE(REG)     REG &= 0xF0

#define TOGGLE_H_NIBBLE(REG)    REG ^= 0xF0

#define TOGGLE_L_NIBBLE(REG)    REG ^= 0x0F

#define GET_H_NIBBLE(REG)       ((REG & 0xF0) >> 4)

#define GET_L_NEPPLES(REG)      (REG & 0x0F)

#endif	/* HELPED_MACROS_H */

