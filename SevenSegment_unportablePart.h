/*******************************************************************************
 *  
 * File:                SevenSegment_unportablePart.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototypes to enable seven segments chips.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */ 
#ifndef SEVEN_SEGMENT_UNPORTABLE_H
#define	SEVEN_SEGMENT_UNPORTABLE_H

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

/*************************** EnumSevenSegment_Status_t *************************/
typedef enum {
    SEVEN_SEGMENT_ENABLE_CHIP,
    SEVEN_SEGMENT_DISABLE_CHIP
}EnumSevenSegment_Status_t;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	SevenSegment_SelectChip
 *
 * Description: 	enable or disable seven segments chips.
 *
 * Inputs:			EnumSevenSegment_Status_t   typedef to enable or disable seven segment chip 1
 *                  EnumSevenSegment_Status_t   typedef to enable or disable seven segment chip 2
 *                  EnumSevenSegment_Status_t   typedef to enable or disable seven segment chip 3
 *                  EnumSevenSegment_Status_t   typedef to enable or disable seven segment chip 4
 *
 * Outputs:			NULL
 *
 * Return:			NULL 
 *******************************************************************************/
extern void SevenSegment_SelectChip(EnumSevenSegment_Status_t a_Chip1 ,
                                    EnumSevenSegment_Status_t a_Chip2 ,
                                    EnumSevenSegment_Status_t a_Chip3 ,
                                    EnumSevenSegment_Status_t a_Chip4);


#endif	/* SEVEN_SEGMENT_UNPORTABLE_H */

