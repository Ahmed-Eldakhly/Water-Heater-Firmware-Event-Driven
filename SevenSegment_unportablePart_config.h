/*******************************************************************************
 *  
 * File:                SevenSegment_unportablePart_config.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configurations of number of chips on 
 *                      Seven Segment module.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */ 
#ifndef SEVEN_SEGMENT_UNPORTABLE_CONFIG_H
#define	SEVEN_SEGMENT_UNPORTABLE_CONFIG_H

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "GPIO.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define SEVEN_SEGMENT_SELECT_CHIP_PORT      GPIO_PORTA
#define SEVEN_SEGMENT_SELECT_CHIP_1         GPIO_PIN2
#define SEVEN_SEGMENT_SELECT_CHIP_2         GPIO_PIN3
#define SEVEN_SEGMENT_SELECT_CHIP_3         GPIO_PIN4
#define SEVEN_SEGMENT_SELECT_CHIP_4         GPIO_PIN5

#endif	/* SEVEN_SEGMENT_UNPORTABLE_CONFIG_H */

