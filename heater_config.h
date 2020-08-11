/*******************************************************************************
 *  
 * File:                heater_config.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configuration of pins that will be used.
 * 
 * Revision history:    7/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
   more than once. */
#ifndef HEATER_CONFIG_H
#define	HEATER_CONFIG_H

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
#define COOLER_PORT                         GPIO_PORTC
#define COOLER_PIN                          GPIO_PIN2
#define HEATING_RESISTANCE_PORT             GPIO_PORTC
#define HEATING_RESISTANCE_PIN              GPIO_PIN5
#define LEDS_PORT                           GPIO_PORTB
#define LED1_PIN                            GPIO_PIN3
#define LED2_PIN                            GPIO_PIN4
#define LED3_PIN                            GPIO_PIN5
#define LED4_PIN                            GPIO_PIN6
#define LED5_PIN                            GPIO_PIN7
#define UP_PORT                             GPIO_PORTB
#define UP_PIN                              GPIO_PIN2
#define DOWN_PORT                           GPIO_PORTB
#define DOWN_PIN                            GPIO_PIN1
#define ON_OFF_PORT                         GPIO_PORTB
#define ON_OFF_PIN                          GPIO_PIN0
#define MAX_TEMPERATURE                     75u
#define MIN_TEMPERATURE                     35u
#define EEPROM_LOCATION_FOR_SAVED_TEMP      0u

#endif	/* HEATER_CONFIG_H */

