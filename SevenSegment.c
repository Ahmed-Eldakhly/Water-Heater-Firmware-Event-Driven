/*******************************************************************************
 *  
 * File:                SevenSegment.c
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementations for seven segment module.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "SevenSegment.h"
#include "SevenSegment_config.h"

/*******************************************************************************
 *                           Functions implementations                         *
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
void SevenSegment_Initialization(void)
{
    GPIO_SetPortDirection(SEVEN_SEGMENNT_PORT , OUTPUT);
}

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
void SevenSegment_Display(uint8 a_u8displayNumber , EnumSevenSegment_DotStatus_t a_displayDot)
{
/* define array numbers from 0 to 9 depend on the arrangement of seven segments LEDs */
#if SEVEN_SEGMENT_A_LOCATION == SEVEN_SEGMENT_A_LEFT_LOCATION
    uint8 u8numberRepresentation[10] = { 0xFC , 0x60 , 0xDA , 0xF2 , 0x66 , 0xB6 , 0xBE , 0xE0 , 0xFE , 0xF6 };
#elif SEVEN_SEGMENT_A_LOCATION == SEVEN_SEGMENT_A_RIGHT_LOCATION
    uint8 u8numberRepresentation[10] = { 0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F };
#endif
    /* Display the number */
    GPIO_WriteOnPort(SEVEN_SEGMENNT_PORT , u8numberRepresentation[a_u8displayNumber]);
    /* display the dot */
#if SEVEN_SEGMENT_A_LOCATION == SEVEN_SEGMENT_A_LEFT_LOCATION
    if(a_displayDot == SEVEN_SEGMENT_DISPLAY_DOT)
    {
        GPIO_WriteOnPin(SEVEN_SEGMENNT_PORT , GPIO_PIN0 , HIGH);
    }
    else
    {
        GPIO_WriteOnPin(SEVEN_SEGMENNT_PORT , GPIO_PIN0 , LOW);
    }
#elif SEVEN_SEGMENT_A_LOCATION == SEVEN_SEGMENT_A_RIGHT_LOCATION
    if(a_displayDot == SEVEN_SEGMENT_DISPLAY_DOT)
    {
        GPIO_WriteOnPin(SEVEN_SEGMENNT_PORT , GPIO_PIN7 , HIGH);
    }
    else
    {
        GPIO_WriteOnPin(SEVEN_SEGMENNT_PORT , GPIO_PIN7 , LOW);
    }
#endif
}
