/*******************************************************************************
 *  
 * File:                SevenSegment_config.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configurations of Seven Segment module.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */ 
#ifndef SEVEN_SEGMENT_CONFIG_H
#define	SEVEN_SEGMENT_CONFIG_H

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "GPIO.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define SEVEN_SEGMENT_A_RIGHT_LOCATION      0u
#define SEVEN_SEGMENT_A_LEFT_LOCATION       1u
/*-----------------------------------------------------------------------------*/
#define SEVEN_SEGMENNT_PORT                 GPIO_PORTD
#define SEVEN_SEGMENT_A_LOCATION            SEVEN_SEGMENT_A_RIGHT_LOCATION

#endif	/* SEVEN_SEGMENT_CONFIG_H */

