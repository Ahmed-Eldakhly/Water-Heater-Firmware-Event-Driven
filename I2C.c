/*******************************************************************************
 *  
 * File:                I2C.c
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of I2C peripheral.
 * 
 * Revision history:    4/7/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "I2C.h"
#include "I2C_MemMap.h"
#include "I2C_config.h"
#include "helped_macros.h"

/*******************************************************************************
 *                            Functions Implementation                         *
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
void I2C_Master_Initialization(EnumI2C_MasterMode_t a_I2C_master_mode_t ,
                               EnumI2C_BaudRate_t a_I2C_baud_rate_t)
{
    /* reset modes of I2C to select new mode */
    I2C_CONTROL_1_REG &= 0xF0;
    /* check what is the selected mode for master */
    if(a_I2C_master_mode_t == I2C_FIRMWARE_CONTROLLED_MASTER_MODE)
    {
        I2C_CONTROL_1_REG |= 0x0B;
    }
    else
    {
        I2C_CONTROL_1_REG |= 0x08;
    }
    /* disable SMBus feature */
    CLEAR_BIT(I2C_STATUS_REG , I2C_SM_BUS_SELECT_BIT);
    /* check on selected baud rate to enable the high speed feature if it was selected */
    if(a_I2C_baud_rate_t == I2C_400KHZ)
    {
        CLEAR_BIT(I2C_STATUS_REG , I2C_SLEW_RATE_CONTROL_BIT); 
    }
    else
    {
        SET_BIT(I2C_STATUS_REG , I2C_SLEW_RATE_CONTROL_BIT); 
    }
    /* add the value that generate baud rate */
    I2C_ADDRESS_BUFFER = (SYSTEM_CLOCK_USED_IN_I2C_MODULE / (4 * a_I2C_baud_rate_t)) - 1; 
    /* make the SCK and SDL as input pins to enable I2C peripheral */
    SET_BIT(I2C_PIN_DIRECTION_REG , I2C_CLOCK_PIN);
    SET_BIT(I2C_PIN_DIRECTION_REG , I2C_DATA_PIN);
    /* enable I2C peripheral */
    SET_BIT(I2C_CONTROL_1_REG , I2C_ENABILE_BIT);
}

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
void I2C_master_send_start_condition(void)
{
    /* check if the I2C Bus in Idle state */
    if((GET_BIT(I2C_STATUS_REG , I2C_READ_WRITE_INFORMATION_BIT) || (I2C_CONTROL_2_REG & 0x1F)) == 0)
    {
        /* generate start condition on I2c Bus */
        SET_BIT(I2C_CONTROL_2_REG , I2C_START_OR_STRETCH_ENABILE_BIT);
        /* keep holding till start condition is generated correctly */
        while(GET_BIT(I2C_CONTROL_2_REG , I2C_START_OR_STRETCH_ENABILE_BIT));
    }
    /* check if write collision error was happened to clear the collision flag */
    if(GET_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT);
    }
    else
    {
        /* Do Nothing */
    }
}

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
void I2C_master_send_stop_condition(void)
{
    /* generate stop condition on I2c Bus */
    SET_BIT(I2C_CONTROL_2_REG , I2C_STOP_ENABILE_BIT);
    /* keep holding till stop condition is generated correctly */
    while(GET_BIT(I2C_CONTROL_2_REG , I2C_STOP_ENABILE_BIT));
    /* check if write collision error was happened to clear the collision flag */
    if(GET_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT);
    }
    else
    {
        /* Do Nothing */
    }
}

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
void I2C_master_send_repeated_start_condition(void)
{
    /* generate repeated start condition on I2c Bus */
    SET_BIT(I2C_CONTROL_2_REG , I2C_I2C_REPEATED_START_ENABILE_BIT);
    /* keep holding till repeated start condition is generated correctly */
    while(GET_BIT(I2C_CONTROL_2_REG , I2C_I2C_REPEATED_START_ENABILE_BIT));
    /* check if write collision error was happened to clear the collision flag */
    if(GET_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT);
    }
    else
    {
        /* Do Nothing */
    }
}

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
EnumI2C_Slave_Ack_t I2C_master_send_address(uint8 a_I2C_Address , EnumI2C_operation_t a_I2C_operaton_t)
{
    /* return value to inform the user if the slave respond with Ack or not */
    EnumI2C_Slave_Ack_t retVal_t;
    /* put the address of slave on the I2C bus with the selected operation */
    I2C_DATA_BUFFER = (a_I2C_Address << 1) | a_I2C_operaton_t;
    /* check if write collision error was happened to clear the collision flag */
    while(GET_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT);
        /* send the address again */
        I2C_DATA_BUFFER = (a_I2C_Address << 1) | a_I2C_operaton_t;
    }
    /* keep holding till the slave address will be sent correctly */
    while(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , I2C_MASTER_INTERRUPT_FLAG_BIT) == 0);
    /* clear the interrupt flag */
    CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , I2C_MASTER_INTERRUPT_FLAG_BIT);
    /* Get the slave Ack value */
    retVal_t = GET_BIT(I2C_CONTROL_2_REG , I2C_ACK_STATUS_BIT);
    /* check if the operation is Read to enable the Read operation from slave */
    if(a_I2C_operaton_t == I2C_READ_OPERATION)
    {
        SET_BIT(I2C_CONTROL_2_REG , I2C_RECEIVE_ENABILE_BIT);
    }
    else
    {
        /* Do Nothing */
    }
    /* return slave Ack value to the user */
    return retVal_t;
}

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
EnumI2C_Slave_Ack_t I2C_master_send_data(uint8 a_I2C_Data)
{ 
    /* send the data to slave */
    I2C_DATA_BUFFER = a_I2C_Data;
    /* check if write collision error was happened to clear the collision flag */
    while(GET_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT);
        /* Send the data again */
        I2C_DATA_BUFFER = a_I2C_Data;
    }
    while(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , I2C_MASTER_INTERRUPT_FLAG_BIT) == 0);
    /* clear the interrupt flag */
    CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , I2C_MASTER_INTERRUPT_FLAG_BIT);
    /* return slave Ack value to the user */
    return GET_BIT(I2C_CONTROL_2_REG , I2C_ACK_STATUS_BIT);
}

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
uint8 I2C_master_receive_data(EnumI2C_Ack_Status_t a_I2C_ack_status_t)
{
    /* data that will be returned from the slave */
    uint8 u8_retVal;
    /* check if the user want the master to send Ack to slave or not */
    if(a_I2C_ack_status_t == I2C_SEND_ACK)
    {
        CLEAR_BIT(I2C_CONTROL_2_REG , I2C_ACK_DATA_BIT);
    }
    else
    {
        SET_BIT(I2C_CONTROL_2_REG , I2C_ACK_DATA_BIT);
    }
    /* keep holding till the data arrive correctly */
    while(GET_BIT(I2C_CONTROL_2_REG , I2C_RECEIVE_ENABILE_BIT));
    /* check if write collision error was happened to clear the collision flag */
    if(GET_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT);
    }
    else
    {
        /* Do Nothing */
    }
    /* check if overflow is occurred to clear the overflow flag */
    if(GET_BIT(I2C_CONTROL_1_REG , I2C_RECEIVE_OVERFLOW_INDICATOR_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_RECEIVE_OVERFLOW_INDICATOR_BIT);
    }
    else
    {
        /* Do Nothing */
    }
    /* get received data from the I2C buffer */
    u8_retVal = I2C_DATA_BUFFER;
    /* enable Ack sender to send Ack or Not Ack */
    SET_BIT(I2C_CONTROL_2_REG , I2C_ACK_SEQUENCE_ENABILE_BIT);
    /* check if write collision error was happened */
    if(GET_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT))
    {
        CLEAR_BIT(I2C_CONTROL_1_REG , I2C_WRITE_COLLISION_DETECT_BIT);
    }
    else
    {
        /* Do Nothing */
    }
    /* return received data to the user */
    return u8_retVal;
}

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
void I2C_Disable(void)
{
    /* disable I2C peripheral */
    CLEAR_BIT(I2C_CONTROL_1_REG , I2C_ENABILE_BIT);
}