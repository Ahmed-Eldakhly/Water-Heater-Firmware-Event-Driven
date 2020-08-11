# 1 "EEPROM24c04.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "EEPROM24c04.c" 2
# 16 "EEPROM24c04.c"
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
# 16 "EEPROM24c04.c" 2

# 1 "./EEPROM24c04.h" 1
# 38 "./EEPROM24c04.h"
extern void EEPROM_Initialization(void);
# 52 "./EEPROM24c04.h"
extern void EEPROM_Save_Byte(uint16 a_u16Location , uint8 a_u8Data);
# 65 "./EEPROM24c04.h"
extern uint8 EEPROM_Read_Byte(uint16 a_u16Location);
# 80 "./EEPROM24c04.h"
extern void EEPROM_Save_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size);
# 95 "./EEPROM24c04.h"
extern void EEPROM_Read_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size);
# 109 "./EEPROM24c04.h"
extern void EEPROM_Save_Page(uint16 a_u16Location , uint8* a_u8Data);
# 122 "./EEPROM24c04.h"
extern void EEPROM_Erase(void);
# 17 "EEPROM24c04.c" 2

# 1 "./EEPROM24c04_config.h" 1
# 18 "EEPROM24c04.c" 2

# 1 "./I2C.h" 1
# 29 "./I2C.h"
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
# 19 "EEPROM24c04.c" 2
# 36 "EEPROM24c04.c"
extern void EEPROM_Initialization(void)
{

    I2C_Master_Initialization(I2C_MASTER_MODE , I2C_100KHZ);
}
# 54 "EEPROM24c04.c"
void EEPROM_Save_Byte(uint16 a_u16Location , uint8 a_u8Data)
{

    I2C_master_send_start_condition();

    I2C_master_send_address((0x50 | ((a_u16Location >> 8) & 0x0001)), I2C_WRITE_OPERATION);

    I2C_master_send_data((uint8)(a_u16Location & 0x00FF));

    I2C_master_send_data(a_u8Data);

    I2C_master_send_stop_condition();
}
# 79 "EEPROM24c04.c"
uint8 EEPROM_Read_Byte(uint16 a_u16Location)
{

    uint8 u8_retVal;

    I2C_master_send_start_condition();

    I2C_master_send_address((0x50 | ((a_u16Location >> 8) & 0x0001)), I2C_WRITE_OPERATION);

    I2C_master_send_data((uint8)(a_u16Location & 0x00FF));

    I2C_master_send_repeated_start_condition();

    I2C_master_send_address(0x50 , I2C_READ_OPERATION);

    u8_retVal = I2C_master_receive_data(I2C_SEND_NOT_ACK);

    I2C_master_send_stop_condition();

    EEPROM_Save_Byte(0,0);

    return u8_retVal;
}
# 116 "EEPROM24c04.c"
void EEPROM_Save_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size)
{

    I2C_master_send_start_condition();

    I2C_master_send_address((0x50 | (a_u16Location >> 8 & 0x0001)), I2C_WRITE_OPERATION);

    I2C_master_send_data((uint8)(a_u16Location & 0xFF));


    for(uint8 counter = 0; counter < a_u8Size && counter < 16u; counter++)
    {

        I2C_master_send_data(a_u8Data[counter]);
    }

    I2C_master_send_stop_condition();
}
# 148 "EEPROM24c04.c"
void EEPROM_Read_Array(uint16 a_u16Location , uint8* a_u8Data , uint8 a_u8Size)
{

    I2C_master_send_start_condition();

    I2C_master_send_address((0x50 | ((a_u16Location >> 8) & 0x0001)), I2C_WRITE_OPERATION);

    I2C_master_send_data((uint8)(a_u16Location & 0x00FF));

    I2C_master_send_repeated_start_condition();

    I2C_master_send_address(0x50 , I2C_READ_OPERATION);

    for(uint8 counter = 0; counter < a_u8Size; counter++)
    {
        a_u8Data[counter] = I2C_master_receive_data(I2C_SEND_ACK);
    }

    I2C_master_send_stop_condition();

    EEPROM_Save_Byte(0,0);
}
# 183 "EEPROM24c04.c"
void EEPROM_Save_Page(uint16 a_u16Location , uint8* a_u8Data)
{

    I2C_master_send_start_condition();

    I2C_master_send_address((0x50 | (a_u16Location >> 8 & 0x0001)), I2C_WRITE_OPERATION);

    I2C_master_send_data((uint8)(a_u16Location & 0xFF));

    for(uint8 counter = 0; counter < 16u; counter++)
    {

        I2C_master_send_data(a_u8Data[counter]);
    }

    I2C_master_send_stop_condition();
}
# 212 "EEPROM24c04.c"
extern void EEPROM_Erase(void)
{


    for(uint8 counter = 0; counter < 512u / 16u; counter++)
    {

        I2C_master_send_start_condition();

        I2C_master_send_address((0x50 | ((counter * 16u) >> 8 & 0x0001)), I2C_WRITE_OPERATION);

        I2C_master_send_data((uint8)((counter * 16u) & 0xFF));

        for(uint8 counter2 = 0; counter2 < 16u; counter2++)
        {

            I2C_master_send_data(0xFF);
        }

        I2C_master_send_stop_condition();
    }
}
