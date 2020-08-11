# 1 "GPIO.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "GPIO.c" 2
# 15 "GPIO.c"
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
# 15 "GPIO.c" 2

# 1 "./GPIO_MemMap.h" 1
# 16 "GPIO.c" 2

# 1 "./helped_macros.h" 1
# 17 "GPIO.c" 2
# 36 "GPIO.c"
EnumGPIO_Status_t GPIO_SetPinDirection(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8direction)
{

    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;

    switch(a_u8port)
    {
        case 0u:

            if(a_u8pin <= 5u)
            {
                if(a_u8direction == 1u)
                {
                    *(volatile uint8*)0x85 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == 0u)
                {
                    *(volatile uint8*)0x85 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 1u:

            if(a_u8pin <= 7u)
            {
                if(a_u8direction == 1u)
                {
                    *(volatile uint8*)0x86 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == 0u)
                {
                    *(volatile uint8*)0x86 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 2u:

            if(a_u8pin <= 7u)
            {
                if(a_u8direction == 1u)
                {
                    *(volatile uint8*)0x87 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == 0u)
                {
                    *(volatile uint8*)0x87 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 3u:

            if(a_u8pin <= 7u)
            {
                if(a_u8direction == 1u)
                {
                    *(volatile uint8*)0x88 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == 0u)
                {
                    *(volatile uint8*)0x88 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 4u:

            if(a_u8pin < 3u)
            {
                if(a_u8direction == 1u)
                {
                    *(volatile uint8*)0x89 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8direction == 0u)
                {
                    *(volatile uint8*)0x89 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:

            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}
# 193 "GPIO.c"
EnumGPIO_Status_t GPIO_SetPortDirection(uint8 a_u8port , uint8 a_u8direction)
{

    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;

    switch(a_u8port)
    {
        case 0u:
            if(a_u8direction == 1u)
            {
                *(volatile uint8*)0x85 |= 0x3F;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == 0u)
            {
                *(volatile uint8*)0x85 &= 0xC0;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 1u:
            if(a_u8direction == 1u)
            {
                *(volatile uint8*)0x86 |= 0xFF;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == 0u)
            {
                *(volatile uint8*)0x85 &= 0x00;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 2u:
            if(a_u8direction == 1u)
            {
                *(volatile uint8*)0x87 |= 0xFF;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == 0u)
            {
                *(volatile uint8*)0x87 &= 0x00;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 3u:
            if(a_u8direction == 1u)
            {
                *(volatile uint8*)0x88 |= 0xFF;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == 0u)
            {
                *(volatile uint8*)0x88 &= 0x00;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 4u:
            if(a_u8direction == 1u)
            {
                *(volatile uint8*)0x89 |= 0x08;
                retVal = GPIO_CORRECT_SET;
            }
            else if(a_u8direction == 0u)
            {
                *(volatile uint8*)0x89 &= 0xF8;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:

            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}
# 306 "GPIO.c"
EnumGPIO_Status_t GPIO_WriteOnPin(uint8 a_u8port , uint8 a_u8pin , uint8 a_u8value)
{

    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;

    switch(a_u8port)
    {
        case 0u:

            if(a_u8pin <= 5u)
            {
                if(a_u8value == 1u)
                {
                    *(volatile uint8*)0x05 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == 0u)
                {
                    *(volatile uint8*)0x05 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 1u:

            if(a_u8pin <= 7u)
            {
                if(a_u8value == 1u)
                {
                    *(volatile uint8*)0x06 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == 0u)
                {
                    *(volatile uint8*)0x06 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 2u:

            if(a_u8pin <= 7u)
            {
                if(a_u8value == 1u)
                {
                    *(volatile uint8*)0x07 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == 0u)
                {
                    *(volatile uint8*)0x07 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 3u:

            if(a_u8pin <= 7u)
            {
                if(a_u8value == 1u)
                {
                    *(volatile uint8*)0x08 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == 0u)
                {
                    *(volatile uint8*)0x08 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 4u:

            if(a_u8pin < 3u)
            {
                if(a_u8value == 1u)
                {
                    *(volatile uint8*)0x09 |= 1 << a_u8pin;
                    retVal = GPIO_CORRECT_SET;
                }
                else if(a_u8value == 0u)
                {
                    *(volatile uint8*)0x09 &= ~(1 << a_u8pin);
                    retVal = GPIO_CORRECT_SET;
                }
                else
                {

                    retVal = GPIO_UNCORRECT_SET;
                }
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:

            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}
# 463 "GPIO.c"
EnumGPIO_Status_t GPIO_WriteOnPort(uint8 a_u8port , uint8 a_u8value)
{

    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;

    switch(a_u8port)
    {
        case 0u:
            *(volatile uint8*)0x05 &= 0x30;
            *(volatile uint8*)0x05 |= (0x3F & a_u8value);
            break;
        case 1u:
            *(volatile uint8*)0x06 &= 0x00;
            *(volatile uint8*)0x06 |= a_u8value;
            break;
        case 2u:
            *(volatile uint8*)0x07 &= 0x00;
            *(volatile uint8*)0x07 |= a_u8value;
            break;
        case 3u:
            *(volatile uint8*)0x08 &= 0x00;
            *(volatile uint8*)0x08 |= a_u8value;
            break;
        case 4u:
            *(volatile uint8*)0x09 &= 0xF8;
            *(volatile uint8*)0x09 |= (a_u8value & 0x07);
            break;
        default:

            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}
# 510 "GPIO.c"
uint8 GPIO_ReadFromPin(uint8 a_u8port , uint8 a_u8pin)
{
    uint8 retVal = 0xFF;

    switch(a_u8port)
    {
        case 0u:
            retVal = ((*(volatile uint8*)0x05 >> a_u8pin) & 0x01);
            break;
        case 1u:
            retVal = ((*(volatile uint8*)0x06 >> a_u8pin) & 0x01);
            break;
        case 2u:
            retVal = ((*(volatile uint8*)0x07 >> a_u8pin) & 0x01);
            break;
        case 3u:
            retVal = ((*(volatile uint8*)0x08 >> a_u8pin) & 0x01);
            break;
        case 4u:
            retVal = ((*(volatile uint8*)0x09 >> a_u8pin) & 0x01);
            break;
        default:
                          ;
            break;
    }
    return retVal;
}
# 549 "GPIO.c"
uint8 GPIO_ReadFromPort(uint8 a_u8port)
{
    uint8 retVal = 0x00;

    switch(a_u8port)
    {
        case 0u:
            retVal = (*(volatile uint8*)0x05 & 0xFF);
            break;
        case 1u:
            retVal = (*(volatile uint8*)0x06 & 0xFF);
            break;
        case 2u:
            retVal = (*(volatile uint8*)0x07 & 0xFF);
            break;
        case 3u:
            retVal = (*(volatile uint8*)0x08 & 0xFF);
            break;
        case 4u:
            retVal = (*(volatile uint8*)0x09 & 0xFF);
            break;
        default:
                          ;
            break;
    }
    return retVal;
}
# 589 "GPIO.c"
EnumGPIO_Status_t GPIO_TogglePin(uint8 a_u8port , uint8 a_u8pin)
{

    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;

    switch(a_u8port)
    {
        case 0u:

            if(a_u8pin <= 5u)
            {
                *(volatile uint8*)0x05 ^= 1 << a_u8pin;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 1u:

            if(a_u8pin <= 7u)
            {
                *(volatile uint8*)0x06 ^= 1 << a_u8pin;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 2u:

            if(a_u8pin <= 7u)
            {
                *(volatile uint8*)0x07 ^= 1 << a_u8pin;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 3u:

            if(a_u8pin <= 7u)
            {
                *(volatile uint8*)0x08 ^= 1 << a_u8pin;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        case 4u:

            if(a_u8pin < 3u)
            {
                *(volatile uint8*)0x09 ^= 1 << a_u8pin;
                retVal = GPIO_CORRECT_SET;
            }
            else
            {

                retVal = GPIO_UNCORRECT_SET;
            }
            break;
        default:

            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}
# 680 "GPIO.c"
EnumGPIO_Status_t GPIO_TogglePort(uint8 a_u8port)
{

    EnumGPIO_Status_t retVal = GPIO_UNCORRECT_SET;
    uint8 temp;

    switch(a_u8port)
    {
        case 0u:
            temp = (*(volatile uint8*)0x05>>6)<<6;
            *(volatile uint8*)0x05 ^= 0xFF;
            *(volatile uint8*)0x05 = ((*(volatile uint8*)0x05<<2)>>2) | temp;
            break;
        case 1u:
            *(volatile uint8*)0x06 ^= 0xFF;
            break;
        case 2u:
            *(volatile uint8*)0x07 ^= 0xFF;
            break;
        case 3u:
            *(volatile uint8*)0x08 ^= 0xFF;
            break;
        case 4u:
            temp = (*(volatile uint8*)0x09>>3)<<3;
            *(volatile uint8*)0x09 ^= 0xFF;
            *(volatile uint8*)0x09 = ((*(volatile uint8*)0x09<<5)>>5) | temp;
            break;
        default:

            retVal = GPIO_UNCORRECT_SET;
            break;
    }
    return retVal;
}
# 726 "GPIO.c"
void GPIO_Disable_Comparator_On_PORTA(void)
{

    *(volatile uint8*)0x9C |=0x07;
}
# 744 "GPIO.c"
EnumGPIO_Status_t GPIO_Disable_ADC_On_Pins(uint8 a_u8port , uint8 a_u8pin)
{

    *(volatile uint8*)0x9F &= ~(1 << 3);
    *(volatile uint8*)0x9F |= 0x06;
}
# 762 "GPIO.c"
void GPIO_Enable_Pull_Up_On_PortB(void)
{
    *(volatile uint8*)0x81 &= ~(1 << 7u);
}
# 778 "GPIO.c"
void GPIO_Disable_Pull_Up_On_PortB(void)
{
    *(volatile uint8*)0x81 |= 1 << 7u;
}
