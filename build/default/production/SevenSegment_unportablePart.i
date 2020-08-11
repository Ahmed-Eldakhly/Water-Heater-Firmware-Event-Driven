# 1 "SevenSegment_unportablePart.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "SevenSegment_unportablePart.c" 2
# 16 "SevenSegment_unportablePart.c"
# 1 "./SevenSegment_unportablePart.h" 1
# 23 "./SevenSegment_unportablePart.h"
typedef enum {
    SEVEN_SEGMENT_ENABLE_CHIP,
    SEVEN_SEGMENT_DISABLE_CHIP
}EnumSevenSegment_Status_t;
# 46 "./SevenSegment_unportablePart.h"
extern void SevenSegment_SelectChip(EnumSevenSegment_Status_t a_Chip1 ,
                                    EnumSevenSegment_Status_t a_Chip2 ,
                                    EnumSevenSegment_Status_t a_Chip3 ,
                                    EnumSevenSegment_Status_t a_Chip4);
# 16 "SevenSegment_unportablePart.c" 2

# 1 "./SevenSegment_unportablePart_config.h" 1
# 22 "./SevenSegment_unportablePart_config.h"
# 1 "./GPIO.h" 1
# 21 "./GPIO.h"
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
# 21 "./GPIO.h" 2
# 46 "./GPIO.h"
typedef enum {
    GPIO_CORRECT_SET,
    GPIO_UNCORRECT_SET
}EnumGPIO_Status_t;
# 68 "./GPIO.h"
extern EnumGPIO_Status_t GPIO_SetPinDirection(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8direction);
# 82 "./GPIO.h"
extern EnumGPIO_Status_t GPIO_SetPortDirection(uint8 a_u8port , uint8 a_u8direction);
# 97 "./GPIO.h"
extern EnumGPIO_Status_t GPIO_WriteOnPin(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8value);
# 111 "./GPIO.h"
extern EnumGPIO_Status_t GPIO_WriteOnPort(uint8 a_u8port , uint8 a_u8value);
# 125 "./GPIO.h"
extern uint8 GPIO_ReadFromPin(uint8 a_u8port , uint8 a_u8pin);
# 138 "./GPIO.h"
extern uint8 GPIO_ReadFromPort(uint8 a_u8port);
# 152 "./GPIO.h"
extern EnumGPIO_Status_t GPIO_TogglePin(uint8 a_u8port , uint8 a_u8pin);
# 165 "./GPIO.h"
extern EnumGPIO_Status_t GPIO_TogglePort(uint8 a_u8port);
# 178 "./GPIO.h"
extern void GPIO_Disable_Comparator_On_PORTA(void);
# 192 "./GPIO.h"
extern EnumGPIO_Status_t GPIO_Disable_ADC_On_Pins(uint8 a_u8port , uint8 a_u8pin);
# 205 "./GPIO.h"
extern void GPIO_Enable_Pull_Up_On_PortB(void);
# 218 "./GPIO.h"
extern void GPIO_Disable_Pull_Up_On_PortB(void);
# 22 "./SevenSegment_unportablePart_config.h" 2
# 17 "SevenSegment_unportablePart.c" 2
# 37 "SevenSegment_unportablePart.c"
void SevenSegment_SelectChip(EnumSevenSegment_Status_t a_Chip1 , EnumSevenSegment_Status_t a_Chip2 ,
                             EnumSevenSegment_Status_t a_Chip3 , EnumSevenSegment_Status_t a_Chip4)
{

    if(a_Chip1 == SEVEN_SEGMENT_ENABLE_CHIP)
    {

        GPIO_SetPinDirection(0u , 2u , 0u);
        GPIO_WriteOnPin(0u , 2u , 1u);
    }
    else
    {

        GPIO_WriteOnPin(0u , 2u , 0u);
    }

    if(a_Chip2 == SEVEN_SEGMENT_ENABLE_CHIP)
    {

        GPIO_SetPinDirection(0u , 3u , 0u);
        GPIO_WriteOnPin(0u , 3u , 1u);
    }
    else
    {

        GPIO_WriteOnPin(0u , 3u , 0u);
    }

    if(a_Chip3 == SEVEN_SEGMENT_ENABLE_CHIP)
    {

        GPIO_SetPinDirection(0u , 4u , 0u);
        GPIO_WriteOnPin(0u , 4u , 1u);
    }
    else
    {

        GPIO_WriteOnPin(0u , 4u , 0u);
    }

    if(a_Chip4 == SEVEN_SEGMENT_ENABLE_CHIP)
    {

        GPIO_SetPinDirection(0u , 5u , 0u);
        GPIO_WriteOnPin(0u , 5u , 1u);
    }
    else
    {

        GPIO_WriteOnPin(0u , 5u , 0u);
    }
}
