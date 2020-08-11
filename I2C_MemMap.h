/********************************************************************************** 
 * 
 * File:                I2C_MemMap.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains registers and bits that control I2C peripheral.
 * 
 * Revision history:    4/7/2020
 * 
 **********************************************************************************/

/* This is a guard condition so that contents of this file are not included
   more than once. */  
#ifndef I2C_MEM_MAP_H
#define	I2C_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define I2C_CONTROL_1_REG                           *(volatile uint8*)0x14
#define I2C_WRITE_COLLISION_DETECT_BIT              7u 
#define I2C_RECEIVE_OVERFLOW_INDICATOR_BIT          6u
#define I2C_ENABILE_BIT                             5u
#define I2C_CLOCK_RELEASE_CONTROL_BIT               4u
#define I2C_SELECT_MODE_BIT_3                       3u
#define I2C_SELECT_MODE_BIT_2                       2u
#define I2C_SELECT_MODE_BIT_1                       1u
#define I2C_SELECT_MODE_BIT_0                       0u

#define I2C_CONTROL_2_REG                           *(volatile uint8*)0x91
#define I2C_GENERIAL_CALL_ENABILE_BIT               7u 
#define I2C_ACK_STATUS_BIT                          6u
#define I2C_ACK_DATA_BIT                            5u
#define I2C_ACK_SEQUENCE_ENABILE_BIT                4u
#define I2C_RECEIVE_ENABILE_BIT                     3u
#define I2C_STOP_ENABILE_BIT                        2u
#define I2C_I2C_REPEATED_START_ENABILE_BIT          1u
#define I2C_START_OR_STRETCH_ENABILE_BIT            0u

#define I2C_STATUS_REG                              *(volatile uint8*)0x94
#define I2C_SLEW_RATE_CONTROL_BIT                   7u 
#define I2C_SM_BUS_SELECT_BIT                       6u
#define I2C_DATA_ADDRESS_BIT                        5u
#define I2C_STOP_BIT                                4u
#define I2C_START_BIT                               3u
#define I2C_READ_WRITE_INFORMATION_BIT              2u
#define I2C_UPDATE_ADDRESS_BIT                      1u
#define I2C_BUFFER_FULL_STATES_BIT                  0u

#define I2C_DATA_BUFFER                             *(volatile uint8*)0x13
#define I2C_ADDRESS_BUFFER                          *(volatile uint8*)0x93

#define I2C_PIN_DIRECTION_REG                       *(volatile uint8*)0x87
#define I2C_CLOCK_PIN                               3u
#define I2C_DATA_PIN                                4u

#define INTERRUPT_PERIPHERAL_FLAGS_1                *(volatile uint8*)0x0C
#define I2C_MASTER_INTERRUPT_FLAG_BIT               3u  

#endif	/* I2C_MEM_MAP_H */

