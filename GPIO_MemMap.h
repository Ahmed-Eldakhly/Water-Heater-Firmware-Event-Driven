/*******************************************************************************
 * 
 * File:                GPIO_MemMap.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains memory mapping for GPIO registers in 
 *                      micro1-controller.
 * 
 * Revision history:    1/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */
#ifndef GPIO_MEM_MAP_H
#define	GPIO_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define GPIO_DIRECTION_PORTA                    *(volatile uint8*)0x85
#define GPIO_DIRECTION_PORTB                    *(volatile uint8*)0x86
#define GPIO_DIRECTION_PORTC                    *(volatile uint8*)0x87
#define GPIO_DIRECTION_PORTD                    *(volatile uint8*)0x88
#define GPIO_DIRECTION_PORTE                    *(volatile uint8*)0x89

#define GPIO_READ_WRITE_VALUE_PORTA             *(volatile uint8*)0x05
#define GPIO_READ_WRITE_VALUE_PORTB             *(volatile uint8*)0x06
#define GPIO_READ_WRITE_VALUE_PORTC             *(volatile uint8*)0x07
#define GPIO_READ_WRITE_VALUE_PORTD             *(volatile uint8*)0x08
#define GPIO_READ_WRITE_VALUE_PORTE             *(volatile uint8*)0x09

#define ADC_CONTROL_REGISTER_1                  *(volatile uint8*)0x9F
#define COMPARATOR_CONTROL_REGISTER             *(volatile uint8*)0x9C
#define OIPTION_PULL_UP_REGISTER                *(volatile uint8*)0x81
#define ENABLE_PULL_UP_RESISTOR_ON_PORTB_BIT    7u

#endif	/* GPIO_MEM_MAP_H */

