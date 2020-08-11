# 1 "I2C.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "I2C.c" 2
# 16 "I2C.c"
# 1 "./I2C.h" 1
# 22 "./I2C.h"
# 1 "./stdtypes.h" 1
# 52 "./stdtypes.h"
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short int uint16;
typedef signed short int sint16;
typedef unsigned long int uint32;
typedef signed long int sint32;
typedef unsigned long long int uint64;
typedef signed long long int sint64;
# 22 "./I2C.h" 2







typedef enum {
    I2C_MASTER_MODE,
    I2C_FIRMWARE_CONTROLLED_MASTER_MODE
}EnumI2C_MasterMode_t;


typedef enum {
    I2C_100KHZ = 100000,
    I2C_400KHZ = 400000,
    I2C_1MHZ = 1000000
}EnumI2C_BaudRate_t;



typedef enum {
    I2C_WRITE_OPERATION,
    I2C_READ_OPERATION
}EnumI2C_operation_t;


typedef enum {
    I2C_SEND_ACK,
    I2C_SEND_NOT_ACK
}EnumI2C_Ack_Status_t;


typedef enum {
    I2C_SLAVE_ACK,
    I2C_SLAVE_NOT_ACK
}EnumI2C_Slave_Ack_t;
# 76 "./I2C.h"
extern void I2C_Master_Initialization(EnumI2C_MasterMode_t a_I2C_master_mode_t ,
                               EnumI2C_BaudRate_t a_I2C_baud_rate_t);
# 90 "./I2C.h"
extern void I2C_master_send_start_condition(void);
# 103 "./I2C.h"
extern void I2C_master_send_stop_condition(void);
# 117 "./I2C.h"
extern void I2C_master_send_repeated_start_condition(void);
# 131 "./I2C.h"
extern EnumI2C_Slave_Ack_t I2C_master_send_address(uint8 a_I2C_Address , EnumI2C_operation_t a_I2C_operaton_t);
# 144 "./I2C.h"
extern EnumI2C_Slave_Ack_t I2C_master_send_data(uint8 a_I2C_Data);
# 157 "./I2C.h"
extern uint8 I2C_master_receive_data(EnumI2C_Ack_Status_t a_I2C_ack_status_t);
# 170 "./I2C.h"
extern void I2C_Disable(void);
# 16 "I2C.c" 2

# 1 "./I2C_MemMap.h" 1
# 17 "I2C.c" 2

# 1 "./I2C_config.h" 1
# 18 "I2C.c" 2

# 1 "./helped_macros.h" 1
# 19 "I2C.c" 2
# 37 "I2C.c"
void I2C_Master_Initialization(EnumI2C_MasterMode_t a_I2C_master_mode_t ,
                               EnumI2C_BaudRate_t a_I2C_baud_rate_t)
{

    *(volatile uint8*)0x14 &= 0xF0;

    if(a_I2C_master_mode_t == I2C_FIRMWARE_CONTROLLED_MASTER_MODE)
    {
        *(volatile uint8*)0x14 |= 0x0B;
    }
    else
    {
        *(volatile uint8*)0x14 |= 0x08;
    }

    *(volatile uint8*)0x94 &= ~(1 << 6u);

    if(a_I2C_baud_rate_t == I2C_400KHZ)
    {
        *(volatile uint8*)0x94 &= ~(1 << 7u);
    }
    else
    {
        *(volatile uint8*)0x94 |= 1 << 7u;
    }

    *(volatile uint8*)0x93 = (8000000u / (4 * a_I2C_baud_rate_t)) - 1;

    *(volatile uint8*)0x87 |= 1 << 3u;
    *(volatile uint8*)0x87 |= 1 << 4u;

    *(volatile uint8*)0x14 |= 1 << 5u;
}
# 82 "I2C.c"
void I2C_master_send_start_condition(void)
{

    if((((*(volatile uint8*)0x94 >> 2u) & 0x01) || (*(volatile uint8*)0x91 & 0x1F)) == 0)
    {

        *(volatile uint8*)0x91 |= 1 << 0u;

        while(((*(volatile uint8*)0x91 >> 0u) & 0x01));
    }

    if(((*(volatile uint8*)0x14 >> 7u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 7u);
    }
    else
    {

    }
}
# 114 "I2C.c"
void I2C_master_send_stop_condition(void)
{

    *(volatile uint8*)0x91 |= 1 << 2u;

    while(((*(volatile uint8*)0x91 >> 2u) & 0x01));

    if(((*(volatile uint8*)0x14 >> 7u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 7u);
    }
    else
    {

    }
}
# 143 "I2C.c"
void I2C_master_send_repeated_start_condition(void)
{

    *(volatile uint8*)0x91 |= 1 << 1u;

    while(((*(volatile uint8*)0x91 >> 1u) & 0x01));

    if(((*(volatile uint8*)0x14 >> 7u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 7u);
    }
    else
    {

    }
}
# 172 "I2C.c"
EnumI2C_Slave_Ack_t I2C_master_send_address(uint8 a_I2C_Address , EnumI2C_operation_t a_I2C_operaton_t)
{

    EnumI2C_Slave_Ack_t retVal_t;

    *(volatile uint8*)0x13 = (a_I2C_Address << 1) | a_I2C_operaton_t;

    while(((*(volatile uint8*)0x14 >> 7u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 7u);

        *(volatile uint8*)0x13 = (a_I2C_Address << 1) | a_I2C_operaton_t;
    }

    while(((*(volatile uint8*)0x0C >> 3u) & 0x01) == 0);

    *(volatile uint8*)0x0C &= ~(1 << 3u);

    retVal_t = ((*(volatile uint8*)0x91 >> 6u) & 0x01);

    if(a_I2C_operaton_t == I2C_READ_OPERATION)
    {
        *(volatile uint8*)0x91 |= 1 << 3u;
    }
    else
    {

    }

    return retVal_t;
}
# 215 "I2C.c"
EnumI2C_Slave_Ack_t I2C_master_send_data(uint8 a_I2C_Data)
{

    *(volatile uint8*)0x13 = a_I2C_Data;

    while(((*(volatile uint8*)0x14 >> 7u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 7u);

        *(volatile uint8*)0x13 = a_I2C_Data;
    }
    while(((*(volatile uint8*)0x0C >> 3u) & 0x01) == 0);

    *(volatile uint8*)0x0C &= ~(1 << 3u);

    return ((*(volatile uint8*)0x91 >> 6u) & 0x01);
}
# 244 "I2C.c"
uint8 I2C_master_receive_data(EnumI2C_Ack_Status_t a_I2C_ack_status_t)
{

    uint8 u8_retVal;

    if(a_I2C_ack_status_t == I2C_SEND_ACK)
    {
        *(volatile uint8*)0x91 &= ~(1 << 5u);
    }
    else
    {
        *(volatile uint8*)0x91 |= 1 << 5u;
    }

    while(((*(volatile uint8*)0x91 >> 3u) & 0x01));

    if(((*(volatile uint8*)0x14 >> 7u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 7u);
    }
    else
    {

    }

    if(((*(volatile uint8*)0x14 >> 6u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 6u);
    }
    else
    {

    }

    u8_retVal = *(volatile uint8*)0x13;

    *(volatile uint8*)0x91 |= 1 << 4u;

    if(((*(volatile uint8*)0x14 >> 7u) & 0x01))
    {
        *(volatile uint8*)0x14 &= ~(1 << 7u);
    }
    else
    {

    }

    return u8_retVal;
}
# 305 "I2C.c"
void I2C_Disable(void)
{

    *(volatile uint8*)0x14 &= ~(1 << 5u);
}
