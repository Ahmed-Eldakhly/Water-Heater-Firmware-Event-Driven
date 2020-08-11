 /****************************************************************************************
 * 
 * File:                EEPROM24C04_config.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configuration of EEPROM 24C04 device.
 * 
 * Revision history:    5/7/2020
 * 
 ****************************************************************************************/

/* This is a guard condition so that contents of this file are not included
   more than once. */  
#ifndef EEPROM24C04_CONFIG_H
#define	EEPROM24C04_CONFIG_H

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define EEPROM_PAGE_SIZE            16u
#define EEPROM_SIZE                 512u
#define EEPROM_BAUD_RATE            I2C_100KHZ

#endif	/* EEPROM24C04_CONFIG_H */

