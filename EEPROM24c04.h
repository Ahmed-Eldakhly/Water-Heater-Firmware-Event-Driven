/****************************************************************************************
 * 
 * File:                EEPROM20c04.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototypes for EEPROM 24c04 device.
 * 
 * Revision history:    5/7/2020
 * 
 ****************************************************************************************/

/* This is a guard condition so that contents of this file are not included
   more than once. */  
#ifndef EEPROM24C04_H
#define	EEPROM24C04_H

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	EEPROM_Initialization
 *
 * Description: 	Initialize I2C to communicate with EEPROM.
 *
 * Inputs:			NULL
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_Initialization(void);

/*******************************************************************************
 * Function Name:	EEPROM_Save_Byte
 *
 * Description: 	store specific value in specific location in EEPROM.
 *
 * Inputs:			a_u16Location       location in the memory:     uint16.
 *                  a_u8Data            data that will be saved:    uint8.
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_Save_Byte(uint16 a_u16Location , uint8 a_u8Data);

/*******************************************************************************
 * Function Name:	EEPROM_Read_Byte
 *
 * Description: 	return data value from specific location in EEPROM.
 *
 * Inputs:			a_u16Location       location in the memory:     uint16.
 * 
 * Outputs:			NULL
 *
 * Return:			uint8               Data
 *******************************************************************************/
extern uint8 EEPROM_Read_Byte(uint16 a_u16Location);

/*******************************************************************************
 * Function Name:	EEPROM_Save_Array
 *
 * Description: 	store specific array of values in specific locations in EEPROM.
 *
 * Inputs:			a_u16Location  location in the memory:                      uint16
 *                  a_u8Data       pointer to array of data that will be saved. *uint8
 *                  a_u8Size       size of array that will add to page          uint8
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_Save_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size);

/*******************************************************************************
 * Function Name:	EEPROM_Read_Array
 *
 * Description: 	read specific array of values from specific locations in EEPROM
 * 
 * Inputs:			a_u16Location  location in the memory:                      uint16
 *                  a_u8Data       pointer to array of data that will returned. *uint8
 *                  a_u8Size       size of array that will read from EEPROM     uint8
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_Read_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size);

/*******************************************************************************
 * Function Name:	EEPROM_Save_Page
 *
 * Description: 	store specific full page in specific locations in EEPROM.
 *
 * Inputs:			a_u16Location  location in the memory:                      uint16
 *                  a_u8Data       pointer to array of data that will be saved. *uint8
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_Save_Page(uint16 a_u16Location , uint8* a_u8Data);

/*******************************************************************************
 * Function Name:	EEPROM_Erase
 *
 * Description: 	delete all data in EEPROM and return all values to 0xFF.
 *
 * Inputs:			NULL
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_Erase(void);

#endif	/* EEPROM24C04_H */

