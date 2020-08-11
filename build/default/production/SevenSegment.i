# 1 "SevenSegment.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "SevenSegment.c" 2
# 16 "SevenSegment.c"
# 1 "./SevenSegment.h" 1
# 21 "./SevenSegment.h"
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
# 21 "./SevenSegment.h" 2







typedef enum {
    SEVEN_SEGMENT_DISPLAY_DOT,
    SEVEN_SEGMENT_NOT_DISPLAY_DOT
}EnumSevenSegment_DotStatus_t;
# 48 "./SevenSegment.h"
extern void SevenSegment_Initialization(void);
# 62 "./SevenSegment.h"
extern void SevenSegment_Display(uint8 a_u8displayNumber ,
                                    EnumSevenSegment_DotStatus_t a_displayDot);
# 16 "SevenSegment.c" 2

# 1 "./SevenSegment_config.h" 1
# 21 "./SevenSegment_config.h"
# 1 "./GPIO.h" 1
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
# 21 "./SevenSegment_config.h" 2
# 17 "SevenSegment.c" 2
# 34 "SevenSegment.c"
void SevenSegment_Initialization(void)
{
    GPIO_SetPortDirection(3u , 0u);
}
# 51 "SevenSegment.c"
void SevenSegment_Display(uint8 a_u8displayNumber , EnumSevenSegment_DotStatus_t a_displayDot)
{




    uint8 u8numberRepresentation[10] = { 0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F };


    GPIO_WriteOnPort(3u , u8numberRepresentation[a_u8displayNumber]);
# 72 "SevenSegment.c"
    if(a_displayDot == SEVEN_SEGMENT_DISPLAY_DOT)
    {
        GPIO_WriteOnPin(3u , 7u , 1u);
    }
    else
    {
        GPIO_WriteOnPin(3u , 7u , 0u);
    }

}
