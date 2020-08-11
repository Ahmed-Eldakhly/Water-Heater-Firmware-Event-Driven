/*******************************************************************************
 *  
 * File:                SevenSegment_unportablePart.c
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation to enable seven segments chips.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "SevenSegment_unportablePart.h"
#include "SevenSegment_unportablePart_config.h"

/*******************************************************************************
 *                           Functions implementations                         *
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
void SevenSegment_SelectChip(EnumSevenSegment_Status_t a_Chip1 , EnumSevenSegment_Status_t a_Chip2 ,
                             EnumSevenSegment_Status_t a_Chip3 , EnumSevenSegment_Status_t a_Chip4)
{
    /* enable or disable seven segment chip 1 */
    if(a_Chip1 == SEVEN_SEGMENT_ENABLE_CHIP)
    {
        /* enable seven segment chip 1 */
        GPIO_SetPinDirection(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_1 , OUTPUT);
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_1 , HIGH);
    }
    else
    {
        /* disable seven segment chip 1 */
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_1 , LOW);
    }
    /* enable or disable seven segment chip 2 */
    if(a_Chip2 == SEVEN_SEGMENT_ENABLE_CHIP)
    {
        /* enable seven segment chip 2 */
        GPIO_SetPinDirection(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_2 , OUTPUT);
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_2 , HIGH);        
    }
    else
    {
        /* disable seven segment chip 2 */
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_2 , LOW);
    }
    /* enable or disable seven segment chip 3 */
    if(a_Chip3 == SEVEN_SEGMENT_ENABLE_CHIP)
    {
        /* enable seven segment chip 3 */
        GPIO_SetPinDirection(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_3 , OUTPUT);
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_3 , HIGH);       
    }
    else
    {
        /* disable seven segment chip 3 */
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_3 , LOW);
    }
    /* enable or disable seven segment chip 4 */
    if(a_Chip4 == SEVEN_SEGMENT_ENABLE_CHIP)
    {
        /* enable seven segment chip 4 */
        GPIO_SetPinDirection(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_4 , OUTPUT);
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_4 , HIGH);        
    }
    else
    {
        /* disable seven segment chip 4 */
        GPIO_WriteOnPin(SEVEN_SEGMENT_SELECT_CHIP_PORT , SEVEN_SEGMENT_SELECT_CHIP_4 , LOW);
    }
}
