/********************************************************************************** 
 * 
 * File:                ADC_MemMap.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains registers and bits that control ADC peripheral.
 * 
 * Revision history:    2/7/2020
 * 
 **********************************************************************************/

/* This is a guard condition so that contents of this file are not included 
 * more than once. */
#ifndef ADC_MEM_MAP_H
#define	ADC_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define ADC_CONTROL_REG_0           *(volatile uint8*)0x1F
#define ADC_SELECT_PRESCALER_BIT_1  7u 
#define ADC_SELECT_PRESCALER_BIT_0  6u
#define ADC_SELECT_CHANNEL_BIT_2    5u
#define ADC_SELECT_CHANNEL_BIT_1    4u
#define ADC_SELECT_CHANNEL_BIT_0    3u
#define ADC_START_CONVERSION_BIT    2u
#define ADC_ENABLE_BIT              0u

#define ADC_CONTROL_REG_1           *(volatile uint8*)0x9F
#define ADC_SELECT_RESULT_FORMAT    7u
#define ADC_SELECT_PRESCALER_BIT_2  6u
#define ADC_SELECT_PINS_BIT_3       3u
#define ADC_SELECT_PINS_BIT_2       2u
#define ADC_SELECT_PINS_BIT_1       1u
#define ADC_SELECT_PINS_BIT_0       0u

#define ADC_VALUE_HIGH              *(volatile uint8*)0x1E
#define ADC_VALUE_LOW               *(volatile uint8*)0x9E

#define GPIO_DIRECTION_PORTA        *(volatile uint8*)0x85
#define GPIO_DIRECTION_PORTE        *(volatile uint8*)0x89

#define GPIO_PIN0                   0u
#define GPIO_PIN1                   1u
#define GPIO_PIN2                   2u
#define GPIO_PIN3                   3u
#define GPIO_PIN4                   4u
#define GPIO_PIN5                   5u
#define GPIO_PIN6                   6u
#define GPIO_PIN7                   7u

#endif	/* ADC_MEM_MAP_H */

