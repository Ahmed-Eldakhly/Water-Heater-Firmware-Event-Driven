/******************************************************************************* 
 * File:                GPIO.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains implementation of GPIO functions.
 * 
 * Revision history:    1/7/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "GPIO.h"
#include "GPIO_MemMap.h"
#include "helped_macros.h"

/*******************************************************************************
 *                      Functions implementation                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	GPIO_SetPinDirection
 *
 * Description: 	Select direction of GPIO pin.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8pin           (uint8)
 *                  a_u8direction     (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
EnumGPIO_Status_t GPIO_SetPinDirection(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8direction)
{
    /* return variable that obvious if function executed right or wrong */
    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN5)
            {
                if(a_u8direction == INPUT)
                {
                    SET_BIT(GPIO_DIRECTION_PORTA,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == OUTPUT)
                {
                    CLEAR_BIT(GPIO_DIRECTION_PORTA,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTB:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                if(a_u8direction == INPUT)
                {
                    SET_BIT(GPIO_DIRECTION_PORTB,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == OUTPUT)
                {
                    CLEAR_BIT(GPIO_DIRECTION_PORTB,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTC:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                if(a_u8direction == INPUT)
                {
                    SET_BIT(GPIO_DIRECTION_PORTC,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == OUTPUT)
                {
                    CLEAR_BIT(GPIO_DIRECTION_PORTC,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTD:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                if(a_u8direction == INPUT)
                {
                    SET_BIT(GPIO_DIRECTION_PORTD,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == OUTPUT)
                {
                    CLEAR_BIT(GPIO_DIRECTION_PORTD,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTE:
            /* check on inserted Pin */
            if(a_u8pin < GPIO_PIN3)
            {
                if(a_u8direction == INPUT)
                {
                    SET_BIT(GPIO_DIRECTION_PORTE,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == OUTPUT)
                {
                    CLEAR_BIT(GPIO_DIRECTION_PORTE,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:
            /* inserted port doesn't met the limits on ports in this micro_controller */
            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_SetPortDirection
 *
 * Description: 	Select direction of GPIO port.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8direction     (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
EnumGPIO_Status_t GPIO_SetPortDirection(uint8 a_u8port , uint8 a_u8direction)
{
    /* return variable that obvious if function executed right or wrong */
    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            if(a_u8direction == INPUT)
            {
                GPIO_DIRECTION_PORTA |= 0x3F;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == OUTPUT)
            {
                GPIO_DIRECTION_PORTA &= 0xC0;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted direction doesn't met the allowable values */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTB:
            if(a_u8direction == INPUT)
            {
                GPIO_DIRECTION_PORTB |= 0xFF;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == OUTPUT)
            {
                GPIO_DIRECTION_PORTA &= 0x00;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted direction doesn't met the allowable values */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTC:
            if(a_u8direction == INPUT)
            {
                GPIO_DIRECTION_PORTC |= 0xFF;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == OUTPUT)
            {
                GPIO_DIRECTION_PORTC &= 0x00;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted direction doesn't met the allowable values */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTD:
            if(a_u8direction == INPUT)
            {
                GPIO_DIRECTION_PORTD |= 0xFF;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == OUTPUT)
            {
                GPIO_DIRECTION_PORTD &= 0x00;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted direction doesn't met the allowable values */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTE:
            if(a_u8direction == INPUT)
            {
                GPIO_DIRECTION_PORTE |= 0x08;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == OUTPUT)
            {
                GPIO_DIRECTION_PORTE &= 0xF8;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted direction doesn't met the allowable values */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:
            /* inserted port doesn't met the limits on ports in this micro_controller */
            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_WriteOnPin
 *
 * Description: 	Write value on GPIO pin.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8pin           (uint8)
 *                  a_u8value         (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
EnumGPIO_Status_t GPIO_WriteOnPin(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8value)
{
    /* return variable that obvious if function executed right or wrong */
    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN5)
            {
                if(a_u8value == HIGH)
                {
                    SET_BIT(GPIO_READ_WRITE_VALUE_PORTA,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == LOW)
                {
                    CLEAR_BIT(GPIO_READ_WRITE_VALUE_PORTA,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTB:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                if(a_u8value == HIGH)
                {
                    SET_BIT(GPIO_READ_WRITE_VALUE_PORTB,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == LOW)
                {
                    CLEAR_BIT(GPIO_READ_WRITE_VALUE_PORTB,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTC:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                if(a_u8value == HIGH)
                {
                    SET_BIT(GPIO_READ_WRITE_VALUE_PORTC,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == LOW)
                {
                    CLEAR_BIT(GPIO_READ_WRITE_VALUE_PORTC,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTD:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                if(a_u8value == HIGH)
                {
                    SET_BIT(GPIO_READ_WRITE_VALUE_PORTD,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == LOW)
                {
                    CLEAR_BIT(GPIO_READ_WRITE_VALUE_PORTD,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTE:
            /* check on inserted Pin */
            if(a_u8pin < GPIO_PIN3)
            {
                if(a_u8value == HIGH)
                {
                    SET_BIT(GPIO_READ_WRITE_VALUE_PORTE,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == LOW)
                {
                    CLEAR_BIT(GPIO_READ_WRITE_VALUE_PORTE,a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {
                    /* inserted direction doesn't met the allowable values */
                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:
            /* inserted port doesn't met the limits on ports in this micro_controller */
            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_WriteOnPort
 *
 * Description: 	Write value on GPIO port.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8value         (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
EnumGPIO_Status_t GPIO_WriteOnPort(uint8 a_u8port , uint8 a_u8value)
{
    /* return variable that obvious if function executed right or wrong */
    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            GPIO_READ_WRITE_VALUE_PORTA &= 0x30;
            GPIO_READ_WRITE_VALUE_PORTA |= (0x3F & a_u8value);
            break;
        case GPIO_PORTB:
            GPIO_READ_WRITE_VALUE_PORTB &= 0x00;
            GPIO_READ_WRITE_VALUE_PORTB |= a_u8value;
            break;
        case GPIO_PORTC:
            GPIO_READ_WRITE_VALUE_PORTC &= 0x00;
            GPIO_READ_WRITE_VALUE_PORTC |= a_u8value;
            break;
        case GPIO_PORTD:
            GPIO_READ_WRITE_VALUE_PORTD &= 0x00;
            GPIO_READ_WRITE_VALUE_PORTD |= a_u8value;
            break;
        case GPIO_PORTE:
            GPIO_READ_WRITE_VALUE_PORTE &= 0xF8;
            GPIO_READ_WRITE_VALUE_PORTE |= (a_u8value & 0x07);
            break;
        default:
            /* inserted port doesn't met the limits on ports in this micro_controller */
            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_ReadFromPin
 *
 * Description: 	Read value from GPIO pin.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8pin           (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			value of pin    (uint8)
 *******************************************************************************/
uint8 GPIO_ReadFromPin(uint8 a_u8port , uint8 a_u8pin)
{
    uint8 retVal = 0xFF;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            retVal = GET_BIT(GPIO_READ_WRITE_VALUE_PORTA,a_u8pin);
            break;
        case GPIO_PORTB:
            retVal = GET_BIT(GPIO_READ_WRITE_VALUE_PORTB,a_u8pin);
            break;
        case GPIO_PORTC:
            retVal = GET_BIT(GPIO_READ_WRITE_VALUE_PORTC,a_u8pin);
            break;
        case GPIO_PORTD:
            retVal = GET_BIT(GPIO_READ_WRITE_VALUE_PORTD,a_u8pin);
            break;
        case GPIO_PORTE:
            retVal = GET_BIT(GPIO_READ_WRITE_VALUE_PORTE,a_u8pin);
            break;
        default:
            /*Do Nothing*/;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_ReadFromPort
 *
 * Description: 	Read value from GPIO port.
 *
 * Inputs:			a_u8port          (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			value of port   (uint8)
 *******************************************************************************/
uint8 GPIO_ReadFromPort(uint8 a_u8port)
{
    uint8 retVal = 0x00;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            retVal = GET_REG(GPIO_READ_WRITE_VALUE_PORTA);
            break;
        case GPIO_PORTB:
            retVal = GET_REG(GPIO_READ_WRITE_VALUE_PORTB);
            break;
        case GPIO_PORTC:
            retVal = GET_REG(GPIO_READ_WRITE_VALUE_PORTC);
            break;
        case GPIO_PORTD:
            retVal = GET_REG(GPIO_READ_WRITE_VALUE_PORTD);
            break;
        case GPIO_PORTE:
            retVal = GET_REG(GPIO_READ_WRITE_VALUE_PORTE);
            break;
        default:
            /*Do Nothing*/;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_TogglePin
 *
 * Description: 	Toggle GPIO pin.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8pin           (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
EnumGPIO_Status_t GPIO_TogglePin(uint8 a_u8port , uint8 a_u8pin)
{
    /* return variable that obvious if function executed right or wrong */
    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN5)
            {
                TOGGLE_BIT(GPIO_READ_WRITE_VALUE_PORTA,a_u8pin);
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTB:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                TOGGLE_BIT(GPIO_READ_WRITE_VALUE_PORTB,a_u8pin);
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTC:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                TOGGLE_BIT(GPIO_READ_WRITE_VALUE_PORTC,a_u8pin);
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTD:
            /* check on inserted Pin */
            if(a_u8pin <= GPIO_PIN7)
            {
                TOGGLE_BIT(GPIO_READ_WRITE_VALUE_PORTD,a_u8pin);
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case GPIO_PORTE:
            /* check on inserted Pin */
            if(a_u8pin < GPIO_PIN3)
            {
                TOGGLE_BIT(GPIO_READ_WRITE_VALUE_PORTE,a_u8pin);
                retVal = GPIO_CORRECT_SET;
            }
            else
            {
                /* inserted pin doesn't met the limits on this Port */
                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:
            /* inserted port doesn't met the limits on ports in this micro_controller */
            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_TogglePort
 *
 * Description: 	Toggle GPIO port.
 *
 * Inputs:			a_u8port          (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
EnumGPIO_Status_t GPIO_TogglePort(uint8 a_u8port)
{
    /* return variable that obvious if function executed right or wrong */
    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;
    uint8 temp;
    /* check on inserted Port */
    switch(a_u8port)
    {
        case GPIO_PORTA:
            temp = (GPIO_READ_WRITE_VALUE_PORTA>>6)<<6;
            TOGGLE_REG(GPIO_READ_WRITE_VALUE_PORTA);
            GPIO_READ_WRITE_VALUE_PORTA = ((GPIO_READ_WRITE_VALUE_PORTA<<2)>>2) | temp;
            break;
        case GPIO_PORTB:
            TOGGLE_REG(GPIO_READ_WRITE_VALUE_PORTB);
            break;
        case GPIO_PORTC:
            TOGGLE_REG(GPIO_READ_WRITE_VALUE_PORTC);
            break;
        case GPIO_PORTD:
            TOGGLE_REG(GPIO_READ_WRITE_VALUE_PORTD);
            break;
        case GPIO_PORTE:
            temp = (GPIO_READ_WRITE_VALUE_PORTE>>3)<<3;
            TOGGLE_REG(GPIO_READ_WRITE_VALUE_PORTE);
            GPIO_READ_WRITE_VALUE_PORTE = ((GPIO_READ_WRITE_VALUE_PORTE<<5)>>5) | temp;
            break;
        default:
            /* inserted port doesn't met the limits on ports in this micro_controller */
            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	GPIO_Disable_Comparator_On_PORTA
 *
 * Description: 	Disable Comparator peripheral on PortA pins.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void GPIO_Disable_Comparator_On_PORTA(void)
{    
    /* value that disable all comparator pin on Port A */
    COMPARATOR_CONTROL_REGISTER |=0x07;
}

/*******************************************************************************
 * Function Name:	GPIO_Disable_ADC_On_Pins
 *
 * Description: 	Disable ADC peripherals on selected pins from PortA and PortE.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8pin           (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
EnumGPIO_Status_t GPIO_Disable_ADC_On_Pins(uint8 a_u8port , uint8 a_u8pin)
{
    /* value that disable all ADC pin on Port A */
    CLEAR_BIT(ADC_CONTROL_REGISTER_1 , 3);
    ADC_CONTROL_REGISTER_1 |= 0x06;
}

/*******************************************************************************
 * Function Name:	GPIO_Enable_Pull_Up_On_PortB
 *
 * Description: 	Enable all weak pull up resistors on PortB's Pins.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void GPIO_Enable_Pull_Up_On_PortB(void)
{
    CLEAR_BIT(OIPTION_PULL_UP_REGISTER , ENABLE_PULL_UP_RESISTOR_ON_PORTB_BIT);
}

/*******************************************************************************
 * Function Name:	GPIO_Disable_Pull_Up_On_PortB
 *
 * Description: 	Disable all weak pull up resistors on PortB's Pins.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void GPIO_Disable_Pull_Up_On_PortB(void)
{
    SET_BIT(OIPTION_PULL_UP_REGISTER , ENABLE_PULL_UP_RESISTOR_ON_PORTB_BIT);
}

