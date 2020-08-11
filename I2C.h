/*******************************************************************************
 * 
 * File:                I2C.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototypes, enums and definitions 
 *                      of I2C peripheral.
 * 
 * Revision history:    4/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
   more than once. */  
#ifndef I2C_H
#define	I2C_H

/*******************************************************************************
 *                              Included Libraries                             *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

/***************************** EnumI2C_MasterMode_t ***************************/
typedef enum {
    I2C_MASTER_MODE,
    I2C_FIRMWARE_CONTROLLED_MASTER_MODE
}EnumI2C_MasterMode_t;

/****************************** EnumI2C_BaudRate_t ****************************/
typedef enum {
    I2C_100KHZ = 100000,
    I2C_400KHZ = 400000,
    I2C_1MHZ   = 1000000
}EnumI2C_BaudRate_t;


/****************************** EnumI2C_operation_t ****************************/
typedef enum {
    I2C_WRITE_OPERATION,
    I2C_READ_OPERATION        
}EnumI2C_operation_t;

/***************************** EnumI2C_Ack_Status_t ****************************/
typedef enum {
    I2C_SEND_ACK,
    I2C_SEND_NOT_ACK        
}EnumI2C_Ack_Status_t;

/***************************** EnumI2C_Slave_Ack_t *****************************/
typedef enum {
    I2C_SLAVE_ACK,
    I2C_SLAVE_NOT_ACK
}EnumI2C_Slave_Ack_t;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	I2C_Master_Initialization
 *
 * Description: 	initialize I2C master module with specific mode by the user.
 *
 * Inputs:			a_I2C_master_mode_t  (typedef for all I2C master modes: EnumI2C_MasterMode_t)
 *                  a_I2C_baud_rate_t    (typedef for all I2C Baud Rates: EnumI2C_BaudRate_t)
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void I2C_Master_Initialization(EnumI2C_MasterMode_t a_I2C_master_mode_t ,
                               EnumI2C_BaudRate_t a_I2C_baud_rate_t);

/*******************************************************************************
 * Function Name:	I2C_master_send_start_condition
 *
 * Description: 	generate start bit on I2C bus and make sure it happened correctly.
 *
 * Inputs:			NULL
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void I2C_master_send_start_condition(void);

/*******************************************************************************
 * Function Name:	I2C_master_send_stop_condition
 *
 * Description: 	generate stop bit on I2C bus and make sure it happened correctly.
 *
 * Inputs:			NULL
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void I2C_master_send_stop_condition(void);

/*******************************************************************************
 * Function Name:	I2C_master_send_repeated_start_condition
 *
 * Description: 	generate repeated start bit on I2C bus and make sure it 
 *                  happened correctly to control I2C bus again.
 *
 * Inputs:			NULL
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void I2C_master_send_repeated_start_condition(void);

/*******************************************************************************
 * Function Name:	I2C_master_send_address
 *
 * Description: 	send slave address and wait for Ack to communicate with this slave.
 *
 * Inputs:			a_I2C_Address       (slave address: uint8)
 *                  a_I2C_operaton_t    (typedef for I2C operations: EnumI2C_operation_t)
 * 
 * Outputs:			NULL
 *
 * Return:			EnumI2C_Slave_Ack_t (typedef to check if the slave sent Ack or Not)
 *******************************************************************************/
extern EnumI2C_Slave_Ack_t I2C_master_send_address(uint8 a_I2C_Address , EnumI2C_operation_t a_I2C_operaton_t);

/*******************************************************************************
 * Function Name:	I2C_master_send_data
 *
 * Description: 	send data to slave and wait for Ack.
 *
 * Inputs:			a_I2C_Data       (sending data : uint8)
 * 
 * Outputs:			NULL
 *
 * Return:			EnumI2C_Slave_Ack_t (typedef to check if the slave sent Ack or Not)
 *******************************************************************************/
extern EnumI2C_Slave_Ack_t I2C_master_send_data(uint8 a_I2C_Data);

/*******************************************************************************
 * Function Name:	I2C_master_receive_data
 *
 * Description: 	receive data from slave with send or not send Ack.
 *
 * Inputs:			a_I2C_ack_status_t  (typedef to send or not send Ack: EnumI2C_Ack_Status_t)
 * 
 * Outputs:			NULL
 *
 * Return:			uint8
 *******************************************************************************/
extern uint8 I2C_master_receive_data(EnumI2C_Ack_Status_t a_I2C_ack_status_t);

/*******************************************************************************
 * Function Name:	I2C_Disable
 *
 * Description: 	Disable I2C module.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void I2C_Disable(void);

#endif	/* I2C_H */

