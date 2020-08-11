/****************************************************************************************
 * 
 * File:                EEPROM20c04.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation for EEPROM 24c04 device.
 * 
 * Revision history:    5/7/2020
 * 
 ****************************************************************************************/

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "stdtypes.h"
#include "EEPROM24c04.h"
#include "EEPROM24c04_config.h"
#include "I2C.h"

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
extern void EEPROM_Initialization(void)
{
    /* initialize I2C in master mode with suitable configurations to communicate with EEPROM */
    I2C_Master_Initialization(I2C_MASTER_MODE , I2C_100KHZ);
}

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
void EEPROM_Save_Byte(uint16 a_u16Location , uint8 a_u8Data)
{
    /* start communication */
    I2C_master_send_start_condition();
    /* send default address with the first bit of the location address and select write operation */
    I2C_master_send_address((0x50 | ((a_u16Location >> 8) & 0x0001)), I2C_WRITE_OPERATION);
    /* send the reminding 8 bits of the location */
    I2C_master_send_data((uint8)(a_u16Location & 0x00FF));
    /* send the data */
    I2C_master_send_data(a_u8Data);
    /* end the communication */
    I2C_master_send_stop_condition();
}

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
uint8 EEPROM_Read_Byte(uint16 a_u16Location)
{
    /* buffer to save reading data */
    uint8 u8_retVal;
    /* start communication */
    I2C_master_send_start_condition();
    /* send default address with the first bit of the location address and select write operation */
    I2C_master_send_address((0x50 | ((a_u16Location >> 8) & 0x0001)), I2C_WRITE_OPERATION);
    /* send the reminding 8 bits of the location */
    I2C_master_send_data((uint8)(a_u16Location & 0x00FF));
    /* send repeated start to change operation to read */
    I2C_master_send_repeated_start_condition();
    /* send address with read operation */
    I2C_master_send_address(0x50 , I2C_READ_OPERATION);
    /* read the data from selected location */
    u8_retVal = I2C_master_receive_data(I2C_SEND_NOT_ACK);
    /* end the communication */
    I2C_master_send_stop_condition();
    /* Send dummy to release EEPROM operations */
    EEPROM_Save_Byte(0,0);
    /* return reading data */
    return u8_retVal;
}

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
void EEPROM_Save_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size)
{
    /* start communication */
    I2C_master_send_start_condition();
    /* send default address with the first bit of the location address and select write operation */
    I2C_master_send_address((0x50 | (a_u16Location >> 8 & 0x0001)), I2C_WRITE_OPERATION);
    /* send the reminding 8 bits of the location */
    I2C_master_send_data((uint8)(a_u16Location & 0xFF));
    /* loop on the all array elements (less than 17 to avoid overwrite)
     *  that need to be added  in the specific locations */
    for(uint8 counter = 0; counter < a_u8Size && counter < EEPROM_PAGE_SIZE; counter++)
    {
        /* send the data */
        I2C_master_send_data(a_u8Data[counter]);
    }
    /* end the communication */
    I2C_master_send_stop_condition();
}

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
void EEPROM_Read_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size)
{
    /* start communication */
    I2C_master_send_start_condition();
    /* send default address with the first bit of the location address and select write operation */
    I2C_master_send_address((0x50 | ((a_u16Location >> 8) & 0x0001)), I2C_WRITE_OPERATION);
    /* send the reminding 8 bits of the location */
    I2C_master_send_data((uint8)(a_u16Location & 0x00FF));
    /* send repeated start to change operation to read */
    I2C_master_send_repeated_start_condition();
    /* send address with read operation */
    I2C_master_send_address(0x50 , I2C_READ_OPERATION);
    /* read the array data till the selected size start from the selected location */
    for(uint8 counter = 0; counter < a_u8Size; counter++)
    {
        a_u8Data[counter] = I2C_master_receive_data(I2C_SEND_ACK);
    }
    /* end the communication */
    I2C_master_send_stop_condition();
    /* Send dummy to release EEPROM operations */
    EEPROM_Save_Byte(0,0);
}

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
void EEPROM_Save_Page(uint16 a_u16Location , uint8* a_u8Data)
{
    /* start communication */
    I2C_master_send_start_condition();
    /* send default address with the first bit of the location address and select write operation */
    I2C_master_send_address((0x50 | (a_u16Location >> 8 & 0x0001)), I2C_WRITE_OPERATION);
    /* send the reminding 8 bits of the location */
    I2C_master_send_data((uint8)(a_u16Location & 0xFF));
    /* loop to fill one Page with 16 byte Data */
    for(uint8 counter = 0; counter < EEPROM_PAGE_SIZE; counter++)
    {
        /* send the data */
        I2C_master_send_data(a_u8Data[counter]);
    }
    /* end the communication */
    I2C_master_send_stop_condition();
}

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
extern void EEPROM_Erase(void)
{

    /* loop to erase EEPROM */
    for(uint8 counter = 0; counter < EEPROM_SIZE / EEPROM_PAGE_SIZE; counter++)
    {
        /* start communication */
        I2C_master_send_start_condition();
        /* send default address with the first bit of the location address and select write operation */
        I2C_master_send_address((0x50 | ((counter * EEPROM_PAGE_SIZE) >> 8 & 0x0001)), I2C_WRITE_OPERATION);
        /* send the reminding 8 bits of the location */
        I2C_master_send_data((uint8)((counter * EEPROM_PAGE_SIZE) & 0xFF));
        /* loop to erase the page */
        for(uint8 counter2 = 0; counter2 < EEPROM_PAGE_SIZE; counter2++)
        {
            /* send the data */
            I2C_master_send_data(0xFF);
        }
        /* end the communication */
        I2C_master_send_stop_condition();
    }
}
