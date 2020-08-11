/*******************************************************************************
 *  
 * File:                ADC.c
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of ADC peripheral.
 * 
 * Revision history:    2/7/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "ADC.h"
#include "ADC_MemMap.h"
#include "helped_macros.h"

/*******************************************************************************
 *                      Functions implementation                               *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	ADC_Initialization
 *
 * Description: 	initialize ADC module with specific channel that is selected
 *                  by the user.
 *
 * Inputs:			a_ADC_channel_t      (typedef for all ADC channels : EnumADC_channels_t)
 *                  a_ADC_Vref_high_t    (typedef to select high Vref : EnumADC_Vref_value_t)
 *                  a_ADC_Vref_low_t     (typedef to select low Vref : EnumADC_Vref_value_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Initialization(EnumADC_channels_t a_ADC_channel_t ,
                               EnumADC_Vref_value_t a_ADC_Vref_high_t ,
                               EnumADC_Vref_value_t a_ADC_Vref_low_t)
{
    /* reset channel selection bits in control register 0 */
    ADC_CONTROL_REG_0 &= 0xC7;
    /* select the ADC channel by control register 0 */
    ADC_CONTROL_REG_0 |= a_ADC_channel_t << 3;
    /* enable selected channel pins for ADC module and set the direction of this
     *  pin as input*/
    ADC_CONTROL_REG_1 &= 0xF0;
    switch(a_ADC_channel_t)
    {
        case ADC_CHANNEL_0:
            /* Check if Vref high enabled */
            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x0F;
            }
            else
            {
                ADC_CONTROL_REG_1 |= 0x0E;
            }
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN0);
            break;   
        case ADC_CHANNEL_1:
            /* Check if Vref high enabled */
            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x0D;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x05;
            }
            else
            {
                ADC_CONTROL_REG_1 |= 0x04;
            }
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN1);
            break;
        case ADC_CHANNEL_2:
            /* Check if Vref high enabled */
            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x03;
            }
            else
            {
                ADC_CONTROL_REG_1 |= 0x02;
            }
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN2);             
            break;
        case ADC_CHANNEL_3:
            ADC_CONTROL_REG_1 |= 0x04;
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN3);
            break;
        case ADC_CHANNEL_4:
            /* Check if Vref high enabled */
            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x0C;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x03;
            }
            else
            {
                ADC_CONTROL_REG_1 |= 0x02;
            }
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN5);
            break;
        case ADC_CHANNEL_5:
            /* Check if Vref high enabled */
            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x0B;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x0A;
            }
            else
            {
                ADC_CONTROL_REG_1 |= 0x09;
            }
            SET_BIT(GPIO_DIRECTION_PORTE , GPIO_PIN0);
            break;
        case ADC_CHANNEL_6:
            /* Check if Vref high enabled */
            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x08;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x01;
            }
            else
            {
                /* Do nothing */
            }
            SET_BIT(GPIO_DIRECTION_PORTE , GPIO_PIN1);
            break;
        case ADC_CHANNEL_7:
            /* Check if Vref high enabled */
            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x08;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                ADC_CONTROL_REG_1 |= 0x01;
            }
            else
            {
                /* Do nothing */
            }
            SET_BIT(GPIO_DIRECTION_PORTE , GPIO_PIN2);
            break;
        default:
            /*Do nothing */
            break;                                                   
    } 
}

/*******************************************************************************
 * Function Name:	ADC_Select_prescaler
 *
 * Description: 	this function allow the user to select the clock frequency for  
 *                  ADC module by devision system clock on selected pre_scaler value.
 *
 * Inputs:			EnumADC_prescaler_t (typedef for all avaliable ADC
 *                  pre_scaler values : EnumADC_prescaler_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Select_prescaler(EnumADC_prescaler_t a_ADC_prescaler_t)
{
    /* set the selected pre_scaler */
    switch(a_ADC_prescaler_t)
    {
        case ADC_PRESCALER_2:
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_0);
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_1);
            CLEAR_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_PRESCALER_BIT_2);
            break;
        case ADC_PRESCALER_4:
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_0);
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_1);
            SET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_PRESCALER_BIT_2);
            break;
        case ADC_PRESCALER_8:
            SET_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_0);
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_1);
            CLEAR_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_PRESCALER_BIT_2);
            break;
        case ADC_PRESCALER_16:
            SET_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_0);
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_1);
            SET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_PRESCALER_BIT_2);
            break;
        case ADC_PRESCALER_32:
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_0);
            SET_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_1);
            CLEAR_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_PRESCALER_BIT_2);
            break;
        case ADC_PRESCALER_64:
            CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_0);
            SET_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_1);
            SET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_PRESCALER_BIT_2);
            break;
        case ADC_OSCILLATOR_CLOCK:
            SET_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_0);
            SET_BIT(ADC_CONTROL_REG_0 , ADC_SELECT_PRESCALER_BIT_1);
            SET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_PRESCALER_BIT_2);
            break;
        default:
            /* Do nothing */
            break;
    }
    /* enable ADC  peripheral */
    SET_BIT(ADC_CONTROL_REG_0 , ADC_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_Read_value
 *
 * Description: 	this function return the value of signal that is converted by ADC.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint16 (result value will be in 10 bits)
 *******************************************************************************/
uint16 ADC_Read_value(void)
{
    uint16 retVal = 0;
    /* polling until the conversion finishes */
    while((GET_BIT(ADC_CONTROL_REG_0 , ADC_START_CONVERSION_BIT)));
    /* chick on the justification format of ADC conversion result in ADC high and low registers */
    if(GET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_RESULT_FORMAT))
    {
        /* get result from right justification format */
        retVal = (uint16)ADC_VALUE_HIGH << 8 | ADC_VALUE_LOW;
    }
    else
    {
        /* get result from left justification format */
        retVal = (uint16)ADC_VALUE_HIGH << 2 | ADC_VALUE_LOW >> 6;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	ADC_Start_conversion
 *
 * Description: 	start the ADC sampling process on initialized channel.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Start_conversion(void)
{
    while(GET_BIT(ADC_CONTROL_REG_0 , ADC_START_CONVERSION_BIT));
    SET_BIT(ADC_CONTROL_REG_0 , ADC_START_CONVERSION_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_Disable
 *
 * Description: 	Disable ADC module.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Disable()
{
    CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_Set_result_format
 *
 * Description: 	select the result justification format left justification or
 *                  right justification.
 *
 * Inputs:			EnumADC_result_format_t (typedef for avaliable justification 
 *                  for result of ADC conversion).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Set_result_format(EnumADC_result_format_t a_ADC_result_format_t)
{
    /* check what is the type of format of result */
    if(a_ADC_result_format_t == ADC_RESULT_LEFT_JUSTIFIED)
    {
        CLEAR_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_RESULT_FORMAT);
    }
    else
    {
        SET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_RESULT_FORMAT);
    }
}
