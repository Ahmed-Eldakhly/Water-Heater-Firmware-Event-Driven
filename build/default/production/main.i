# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2
# 16 "main.c"
# 1 "./heater.h" 1
# 22 "./heater.h"
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
# 22 "./heater.h" 2


# 1 "./CPU_sleep.h" 1
# 33 "./CPU_sleep.h"
extern void CPU_sleep(void);
# 24 "./heater.h" 2

# 1 "./heater_config.h" 1
# 25 "./heater.h" 2







typedef enum{
    HEATER_OFF_STATE,
    HEATER_ON_STATE,
    HEATER_SET_TEMERATURE
}EnumHeater_State_t;


typedef enum{
    PUSH_BUTTON_IS_PRESSED,
    PUSH_BUTTON_IS_NOT_PRESSED
}EnumButton_State_t;





extern EnumHeater_State_t g_Heater_state_t;
# 65 "./heater.h"
void Heater_Initialization(void);
# 79 "./heater.h"
void Heater_turn_on(void);
# 92 "./heater.h"
void Heater_display_on_temperature(void);
# 106 "./heater.h"
void Heater_change_temperature(void);
# 120 "./heater.h"
void Heater_reading_last_ten_temperature_values(void);
# 133 "./heater.h"
void Heater_check_if_change_state_to_setup_or_off(void);
# 146 "./heater.h"
void Heater_blank_temperature(void);
# 160 "./heater.h"
EnumButton_State_t Check_ON_Push_Button(uint8 a_u8Port , uint8 a_u8Pin);
# 16 "main.c" 2



void main(void)
{

    Heater_Initialization();
    while(1)
    {

        switch(g_Heater_state_t)
        {
            case HEATER_OFF_STATE:

                if(Check_ON_Push_Button(1u , 0u) == PUSH_BUTTON_IS_PRESSED)
                {

                    Heater_turn_on();
                }
                else
                {

                    CPU_sleep();
                }
                break;
            case HEATER_ON_STATE:

                Heater_display_on_temperature();

                Heater_reading_last_ten_temperature_values();

                Heater_check_if_change_state_to_setup_or_off();
                break;
            case HEATER_SET_TEMERATURE:

                Heater_blank_temperature();

                Heater_change_temperature();
                break;
            default:

                break;
        }
    }
}
