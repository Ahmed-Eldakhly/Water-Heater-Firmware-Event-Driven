/*******************************************************************************
 *  
 * File:                SevenSegment.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototypes for seven segment module.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */  
#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                             Types Declaration                               *
 *******************************************************************************/

/************************ EnumSevenSegment_DotStatus_t *************************/
typedef enum {
    SEVEN_SEGMENT_DISPLAY_DOT,
    SEVEN_SEGMENT_NOT_DISPLAY_DOT
}EnumSevenSegment_DotStatus_t;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	SevenSegment_Initialization
 *
 * Description: 	Initialize the Seven Segment module.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL 
 *******************************************************************************/
extern void SevenSegment_Initialization(void);

/*******************************************************************************
 * Function Name:	SevenSegment_Display
 *
 * Description: 	Display the desired number on seven segment.
 *
 * Inputs:			uint8                           desired number
 *                  EnumSevenSegment_DotStatus_t    (typedef to display dot or not).   
 *
 * Outputs:			NULL
 *
 * Return:			NULL 
 *******************************************************************************/
extern void SevenSegment_Display(uint8 a_u8displayNumber ,
                                    EnumSevenSegment_DotStatus_t a_displayDot);

#endif	/* SEVEN_SEGMENT_H */

