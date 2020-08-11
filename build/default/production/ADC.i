# 1 "ADC.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ADC.c" 2
# 16 "ADC.c"
# 1 "./ADC.h" 1
# 22 "./ADC.h"
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
# 22 "./ADC.h" 2







typedef enum{
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7
}EnumADC_channels_t;


typedef enum{
    ADC_PRESCALER_2,
    ADC_PRESCALER_8,
    ADC_PRESCALER_32,
    ADC_OSCILLATOR_CLOCK,
    ADC_PRESCALER_4,
    ADC_PRESCALER_16,
    ADC_PRESCALER_64
}EnumADC_prescaler_t;


typedef enum{
    ADC_RESULT_LEFT_JUSTIFIED,
    ADC_RESULT_RIGHT_JUSTIFIED
}EnumADC_result_format_t;


typedef enum{
    ADC_V_REF_INPUT_PIN,
    ADC_V_REF_DEFAULT_VALUE
}EnumADC_Vref_value_t;
# 81 "./ADC.h"
extern void ADC_Initialization(EnumADC_channels_t a_ADC_channel_t ,
                               EnumADC_Vref_value_t a_ADC_Vref_high_t ,
                               EnumADC_Vref_value_t a_ADC_Vref_low_t);
# 98 "./ADC.h"
extern void ADC_Select_prescaler(EnumADC_prescaler_t a_ADC_prescaler_t);
# 111 "./ADC.h"
extern uint16 ADC_Read_value(void);
# 124 "./ADC.h"
extern void ADC_Start_conversion(void);
# 137 "./ADC.h"
extern void ADC_Disable(void);
# 152 "./ADC.h"
extern void ADC_Set_result_format(EnumADC_result_format_t a_ADC_result_format_t);
# 16 "ADC.c" 2

# 1 "./ADC_MemMap.h" 1
# 17 "ADC.c" 2

# 1 "./helped_macros.h" 1
# 18 "ADC.c" 2
# 38 "ADC.c"
extern void ADC_Initialization(EnumADC_channels_t a_ADC_channel_t ,
                               EnumADC_Vref_value_t a_ADC_Vref_high_t ,
                               EnumADC_Vref_value_t a_ADC_Vref_low_t)
{

    *(volatile uint8*)0x1F &= 0xC7;

    *(volatile uint8*)0x1F |= a_ADC_channel_t << 3;


    *(volatile uint8*)0x9F &= 0xF0;
    switch(a_ADC_channel_t)
    {
        case ADC_CHANNEL_0:

            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x0F;
            }
            else
            {
                *(volatile uint8*)0x9F |= 0x0E;
            }
            *(volatile uint8*)0x85 |= 1 << 0u;
            break;
        case ADC_CHANNEL_1:

            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x0D;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x05;
            }
            else
            {
                *(volatile uint8*)0x9F |= 0x04;
            }
            *(volatile uint8*)0x85 |= 1 << 1u;
            break;
        case ADC_CHANNEL_2:

            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x03;
            }
            else
            {
                *(volatile uint8*)0x9F |= 0x02;
            }
            *(volatile uint8*)0x85 |= 1 << 2u;
            break;
        case ADC_CHANNEL_3:
            *(volatile uint8*)0x9F |= 0x04;
            *(volatile uint8*)0x85 |= 1 << 3u;
            break;
        case ADC_CHANNEL_4:

            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x0C;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x03;
            }
            else
            {
                *(volatile uint8*)0x9F |= 0x02;
            }
            *(volatile uint8*)0x85 |= 1 << 5u;
            break;
        case ADC_CHANNEL_5:

            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x0B;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x0A;
            }
            else
            {
                *(volatile uint8*)0x9F |= 0x09;
            }
            *(volatile uint8*)0x89 |= 1 << 0u;
            break;
        case ADC_CHANNEL_6:

            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x08;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x01;
            }
            else
            {

            }
            *(volatile uint8*)0x89 |= 1 << 1u;
            break;
        case ADC_CHANNEL_7:

            if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN && a_ADC_Vref_low_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x08;
            }
            else if(a_ADC_Vref_high_t == ADC_V_REF_INPUT_PIN)
            {
                *(volatile uint8*)0x9F |= 0x01;
            }
            else
            {

            }
            *(volatile uint8*)0x89 |= 1 << 2u;
            break;
        default:

            break;
    }
}
# 178 "ADC.c"
void ADC_Select_prescaler(EnumADC_prescaler_t a_ADC_prescaler_t)
{

    switch(a_ADC_prescaler_t)
    {
        case ADC_PRESCALER_2:
            *(volatile uint8*)0x1F &= ~(1 << 6u);
            *(volatile uint8*)0x1F &= ~(1 << 7u);
            *(volatile uint8*)0x9F &= ~(1 << 6u);
            break;
        case ADC_PRESCALER_4:
            *(volatile uint8*)0x1F &= ~(1 << 6u);
            *(volatile uint8*)0x1F &= ~(1 << 7u);
            *(volatile uint8*)0x9F |= 1 << 6u;
            break;
        case ADC_PRESCALER_8:
            *(volatile uint8*)0x1F |= 1 << 6u;
            *(volatile uint8*)0x1F &= ~(1 << 7u);
            *(volatile uint8*)0x9F &= ~(1 << 6u);
            break;
        case ADC_PRESCALER_16:
            *(volatile uint8*)0x1F |= 1 << 6u;
            *(volatile uint8*)0x1F &= ~(1 << 7u);
            *(volatile uint8*)0x9F |= 1 << 6u;
            break;
        case ADC_PRESCALER_32:
            *(volatile uint8*)0x1F &= ~(1 << 6u);
            *(volatile uint8*)0x1F |= 1 << 7u;
            *(volatile uint8*)0x9F &= ~(1 << 6u);
            break;
        case ADC_PRESCALER_64:
            *(volatile uint8*)0x1F &= ~(1 << 6u);
            *(volatile uint8*)0x1F |= 1 << 7u;
            *(volatile uint8*)0x9F |= 1 << 6u;
            break;
        case ADC_OSCILLATOR_CLOCK:
            *(volatile uint8*)0x1F |= 1 << 6u;
            *(volatile uint8*)0x1F |= 1 << 7u;
            *(volatile uint8*)0x9F |= 1 << 6u;
            break;
        default:

            break;
    }

    *(volatile uint8*)0x1F |= 1 << 0u;
}
# 237 "ADC.c"
uint16 ADC_Read_value(void)
{
    uint16 retVal = 0;

    while((((*(volatile uint8*)0x1F >> 2u) & 0x01)));

    if(((*(volatile uint8*)0x9F >> 7u) & 0x01))
    {

        retVal = (uint16)*(volatile uint8*)0x1E << 8 | *(volatile uint8*)0x9E;
    }
    else
    {

        retVal = (uint16)*(volatile uint8*)0x1E << 2 | *(volatile uint8*)0x9E >> 6;
    }
    return retVal;
}
# 267 "ADC.c"
void ADC_Start_conversion(void)
{
    while(((*(volatile uint8*)0x1F >> 2u) & 0x01));
    *(volatile uint8*)0x1F |= 1 << 2u;
}
# 284 "ADC.c"
void ADC_Disable()
{
    *(volatile uint8*)0x1F &= ~(1 << 0u);
}
# 302 "ADC.c"
void ADC_Set_result_format(EnumADC_result_format_t a_ADC_result_format_t)
{

    if(a_ADC_result_format_t == ADC_RESULT_LEFT_JUSTIFIED)
    {
        *(volatile uint8*)0x9F &= ~(1 << 7u);
    }
    else
    {
        *(volatile uint8*)0x9F |= 1 << 7u;
    }
}
