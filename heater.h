/*******************************************************************************
 *  
 * File:                heater.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains prototypes, enums and definitions of
 *                      heater Module.
 * 
 * Revision history:    7/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
   more than once. */
#ifndef HEATER_H
#define	HEATER_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "GPIO.h"
#include "stdtypes.h"
#include "CPU_sleep.h"
#include "heater_config.h"

/*******************************************************************************
 *                             Types Declaration                               *
 *******************************************************************************/

/***************************** EnumHeater_State_t ******************************/
typedef enum{
    HEATER_OFF_STATE,
    HEATER_ON_STATE,
    HEATER_SET_TEMERATURE
}EnumHeater_State_t;

/***************************** EnumButton_State_t ******************************/
typedef enum{
    PUSH_BUTTON_IS_PRESSED,
    PUSH_BUTTON_IS_NOT_PRESSED
}EnumButton_State_t;

/*******************************************************************************
 *                             extern variables                                *
 *******************************************************************************/
/* System state variable that used to make system state machine */
extern EnumHeater_State_t g_Heater_state_t;

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Heater_Initialization
 *
 * Description: 	Initialize all peripherals will be used in the module.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_Initialization(void);

/*******************************************************************************
 * Function Name:	Heater_turn_on
 *
 * Description: 	Turn the device on by enable Timer1 and enable its interrupt
 *                  and get the last saved temperature from EEPROM.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_turn_on(void);

/*******************************************************************************
 * Function Name:	Heater_display_on_temperature
 *
 * Description: 	Display the selected temperature on Seven Segments.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_display_on_temperature(void);

/*******************************************************************************
 * Function Name:	Heater_change_temperature
 *
 * Description: 	change the temperature based on the user input by UP or DOWN
 *                  buttons in the Setup state.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_change_temperature(void);

/*******************************************************************************
 * Function Name:	Heater_reading_last_ten_temperature_values
 *
 * Description: 	get new reading from temperature sensor every 100ms and add
 *                  it to the array for last 10 readings.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_reading_last_ten_temperature_values(void);

/*******************************************************************************
 * Function Name:	Heater_check_if_change_state_to_setup_or_off
 *
 * Description: 	check if the user press on any button while the heating state.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_check_if_change_state_to_setup_or_off(void);

/*******************************************************************************
 * Function Name:	Heater_blank_temperature
 *
 * Description: 	blank the temperature on the Seven Segments Every 1 second at setup state..
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_blank_temperature(void);

/*******************************************************************************
 * Function Name:	Check_ON_Push_Button
 *
 * Description: 	Get the state of Push Button.
 *
 * Inputs:			uint8 a_u8Port: for push Button connecting port.
 *                  uint8 a_u8Pin:  for push Button connecting pin.
 *
 * Outputs:			NULL
 *
 * Return:			EnumButton_State_t: typedef for states of the Push Button.
 *******************************************************************************/
EnumButton_State_t Check_ON_Push_Button(uint8 a_u8Port , uint8 a_u8Pin);

#endif	/* HEATER_H */

