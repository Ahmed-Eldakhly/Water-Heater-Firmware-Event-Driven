/*******************************************************************************
 * 
 * File:                GPIO.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains prototypes and enums of GPIO Module.
 * 
 * Revision history:    1/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */
#ifndef GPIO_H
#define	GPIO_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define GPIO_PORTA                  0u
#define GPIO_PORTB                  1u
#define GPIO_PORTC                  2u
#define GPIO_PORTD                  3u
#define GPIO_PORTE                  4u

#define GPIO_PIN0                   0u
#define GPIO_PIN1                   1u
#define GPIO_PIN2                   2u
#define GPIO_PIN3                   3u
#define GPIO_PIN4                   4u
#define GPIO_PIN5                   5u
#define GPIO_PIN6                   6u
#define GPIO_PIN7                   7u

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/************************** EnumGPIO_Stutas_t **********************************/
typedef enum {
    GPIO_CORRECT_SET,
    GPIO_UNCORRECT_SET
}EnumGPIO_Status_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
extern EnumGPIO_Status_t GPIO_SetPinDirection(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8direction);

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
extern EnumGPIO_Status_t GPIO_SetPortDirection(uint8 a_u8port , uint8 a_u8direction);

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
extern EnumGPIO_Status_t GPIO_WriteOnPin(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8value);

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
extern EnumGPIO_Status_t GPIO_WriteOnPort(uint8 a_u8port , uint8 a_u8value);

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
extern uint8 GPIO_ReadFromPin(uint8 a_u8port , uint8 a_u8pin);

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
extern uint8 GPIO_ReadFromPort(uint8 a_u8port);

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
extern EnumGPIO_Status_t GPIO_TogglePin(uint8 a_u8port , uint8 a_u8pin);

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
extern EnumGPIO_Status_t GPIO_TogglePort(uint8 a_u8port);

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
extern void GPIO_Disable_Comparator_On_PORTA(void);

/*******************************************************************************
 * Function Name:	GPIO_Disable_ADC_On_Pins
 *
 * Description: 	Disable Comparator  peripherals on selected pins from PortA and PortE.
 *
 * Inputs:			a_u8port          (uint8)
 *                  a_u8pin           (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			Status to check if the function execute correctly (EnumGPIO_Status_t)
 *******************************************************************************/
extern EnumGPIO_Status_t GPIO_Disable_ADC_On_Pins(uint8 a_u8port , uint8 a_u8pin);

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
extern void GPIO_Enable_Pull_Up_On_PortB(void);

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
extern void GPIO_Disable_Pull_Up_On_PortB(void);

#endif	/* GPIO_H */

