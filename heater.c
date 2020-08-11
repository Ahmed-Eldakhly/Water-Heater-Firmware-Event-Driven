/*********************************************************************************
 *  
 * File:                heater.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of heater Module.
 * 
 * Revision history:    13/7/2020
 * 
 ********************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "general_bitConfig.h"
#include "ADC.h"
#include "timers.h"
#include "SevenSegment.h"
#include "SevenSegment_unportablePart.h"
#include "EEPROM24c04.h"
#include "interrupt.h"
#include "heater.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
#define ENABLE                          HIGH
#define DISABLE                         LOW
#define _XTAL_FREQ                      8000000u

/*******************************************************************************
 *                             global variables                                *
 *******************************************************************************/
/* System state variable that used to make system state machine. */
EnumHeater_State_t g_Heater_state_t = HEATER_OFF_STATE;

/*******************************************************************************
 *                           Static Variables                                  *
 *******************************************************************************/
/* Selected temperature by user. */
static uint8 g_u8Heater_wanted_temperature = 60;
/* real time temperature of water. */
static uint8 g_u8Heater_real_time_temperature = 60;
/* flag to synchronize between two Seven Segment to Display two different digits. */
static uint8 g_u8Sync_flag = 0;
/* flag to make sure the ADC read temperature sensor reading every 100ms. */
static uint8 g_u8calculate_temperature_flag = 0;
/* summation of last ten readings of temperature sensor to get the average. */
static uint16 g_u16Sum_of_ten_readings = 0;
/* counter to start get the average after 10 readings. */
static uint8 g_u8Reading_counter = 0;
/* the index of the reading that will be removed to add new reading from temperature sensor. */
static uint8 g_u8Reading_deleted_element = 0;
/* array of 10 elements to add last 10 readings from temperature sensor to calculate the average. */
static uint8 g_u8Reading_arr[10] = {0};
/* flag to blank the temperature every 1 second in the setup state. */
static uint8 g_u8Display_blank_counter = 0;
/* variable to get check if 5 seconds pass without pressing on any key in setup state to return to heating state. */
static uint8 g_u8End_setup_state = 0;
/* flag to blank the LED every 1 second in the heating process. */
static uint8 g_u8Led_blank_counter = 0;

/*******************************************************************************
 *                            Functions Definitions                            *
 *******************************************************************************/

/*******************************************************************************
 *                              Static Functions                               *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Heater_turn_off
 *
 * Description: 	disable all peripherals in the device and reset all used 
 *                  variables and save last temperature on EEPROM for next use.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
static void Heater_turn_off(void)
{
    /* Disable all Seven Segments. */
    SevenSegment_SelectChip(SEVEN_SEGMENT_DISABLE_CHIP , SEVEN_SEGMENT_DISABLE_CHIP ,
                            SEVEN_SEGMENT_DISABLE_CHIP , SEVEN_SEGMENT_DISABLE_CHIP);
    /* Disable Cooler. */
    GPIO_WriteOnPin(COOLER_PORT , COOLER_PIN , DISABLE);
    /* Disable heating resistance. */
    GPIO_WriteOnPin(HEATING_RESISTANCE_PORT , HEATING_RESISTANCE_PIN , DISABLE);
    /* Disable heating LED. */
    GPIO_WriteOnPin(LEDS_PORT , LED5_PIN , DISABLE);
    /* Save last temperature on EEPROM to use it in the next using process when the heater will be turned on. */
    EEPROM_Save_Byte(EEPROM_LOCATION_FOR_SAVED_TEMP , g_u8Heater_wanted_temperature);
    /* Disable peripherals interrupt enable bit. */
    Peripherals_interrupt_disable();
    /* disable timer1. */
    Timer1_disable();
    /* reset all flags. */
    g_u8Sync_flag = 0;
    g_u8calculate_temperature_flag = 0;
    g_u16Sum_of_ten_readings = 0;
    g_u8Reading_counter = 0;
    g_u8Reading_deleted_element = 0;
    g_u8Display_blank_counter = 0;
    g_u8End_setup_state = 0;
    g_u8Led_blank_counter = 0;
    /* reset the array of the last 10 readings. */
    for(uint8 counter = 0; counter < 10; counter++)
    {
        g_u8Reading_arr[counter] = 0;
    }
    /* change the state of the device to Heating off state. */
    g_Heater_state_t = HEATER_OFF_STATE;
}

/*******************************************************************************
 * Function Name:	TIMER1_ISR
 *
 * Description: 	the function that will be sent as a call_back function to 
 *                  Timer1 interrupt to get new sample from temperature sensor
 *                  every 100ms and blank Seven segments every 1 second on setup
 *                  state and finish setup state after 5 seconds without pressing 
 *                  any bush buttons.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
static void TIMER1_ISR(void)
{
    /* initialize timer1 counter to get interrupt every 100ms. */
    Timer1_write_counter(15535);
    /* state machine to check on the device state. */
    switch(g_Heater_state_t)
    {
        case HEATER_OFF_STATE:
            /* Do nothing */
            break;
        case HEATER_ON_STATE:
            /* update this flag to start new sample every 100ms. */
            g_u8calculate_temperature_flag = 0;
            break;
        case HEATER_SET_TEMERATURE:
            /* update this flag to start new sample every 100ms. */
            g_u8calculate_temperature_flag = 0;
            /* increment this flag to blank Seven Segment every second on setup state. */
            g_u8Display_blank_counter++;
            /* increment this flag to return to heating state after 5 seconds without pressing on any bush button. */
            g_u8End_setup_state++;
            /* check if the 5 seconds passed to change the state from setup state to heating state. */
            if(g_u8End_setup_state == 50)
            {
                /* reset blank counter for next setup operation. */
                g_u8Display_blank_counter = 0;
                /* Change the state from setup state to heating state. */
                g_Heater_state_t = HEATER_ON_STATE;
            }
            else
            {
                /* Do Nothing */
            }
            break;
        default:
            /* Do Nothing */
            break;
    }
}

/*******************************************************************************
 * Function Name:	Heater_heating_cooling_process
 *
 * Description: 	turn on the cooler or the heater based on the average of
 *                  the last ten readings values of the temperature sensor.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
static void Heater_heating_cooling_process(void)
{
    /* Get the temperature of water based on average of last 10 readings. */
    g_u8Heater_real_time_temperature = g_u16Sum_of_ten_readings / 10;
    /* check if the average of the last ten readings of temperature sensor is greater than the wanted temperature. */
    if(g_u8Heater_wanted_temperature < g_u8Heater_real_time_temperature)
    {
        /* turn on the LED referring to the cooling process. */
        GPIO_WriteOnPin(LEDS_PORT , LED5_PIN , ENABLE);
        /* Enable Cooler. */
        GPIO_WriteOnPin(COOLER_PORT , COOLER_PIN , ENABLE);
        /* Disable heater. */
        GPIO_WriteOnPin(HEATING_RESISTANCE_PORT , HEATING_RESISTANCE_PIN , DISABLE);
        /* initialize the flag that will be used to blank the LED at heating process. */
        g_u8Led_blank_counter = 20;
    }
    /* check if the average of the last ten readings of temperature sensor is less than the wanted temperature. */
    else if(g_u8Heater_wanted_temperature > g_u8Heater_real_time_temperature)
    {
        /* Disable Cooler. */
        GPIO_WriteOnPin(COOLER_PORT , COOLER_PIN , DISABLE);
        /* Enable heater. */
        GPIO_WriteOnPin(HEATING_RESISTANCE_PORT , HEATING_RESISTANCE_PIN , ENABLE);
        /* check of the blank counter to blank the LED every 1 second. */
        if(g_u8Led_blank_counter == 10)
        {
            /* turn the LED on. */
            GPIO_WriteOnPin(LEDS_PORT , LED5_PIN , ENABLE);
            /* increment blank flag. */
            g_u8Led_blank_counter++;
            
        }
        else if(g_u8Led_blank_counter == 20)
        {
            /* turn the LED off. */
            GPIO_WriteOnPin(LEDS_PORT , LED5_PIN , DISABLE);
            /* reset the blank flag. */ 
            g_u8Led_blank_counter = 0;
        }
        else
        {
            /* increment blank flag. */
            g_u8Led_blank_counter++;
        }
    }
    /* the average of the last ten readings of temperature sensor is equal the wanted temperature. */
    else
    {
        /* Disable Cooler. */
        GPIO_WriteOnPin(COOLER_PORT , COOLER_PIN , DISABLE);
        /* Disable heater. */
        GPIO_WriteOnPin(HEATING_RESISTANCE_PORT , HEATING_RESISTANCE_PIN , DISABLE);
    }
}

/*******************************************************************************
 * Function Name:	Heater_display_off_temperature
 *
 * Description: 	Disable all Seven Segments.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
static void Heater_display_off_temperature(void)
{
    /* Disable all Seven Segments. */
    SevenSegment_SelectChip(SEVEN_SEGMENT_DISABLE_CHIP , SEVEN_SEGMENT_DISABLE_CHIP ,
                            SEVEN_SEGMENT_DISABLE_CHIP , SEVEN_SEGMENT_DISABLE_CHIP);
    /* reset synchronization flag between two Seven Segments. */
    g_u8Sync_flag = 0;
}

/*******************************************************************************
 *                              Extern Functions                               *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Heater_Initialization
 *
 * Description: 	Initialize all peripherals will be used in the module.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_Initialization(void)
{
    /* Initialize EEPROM to save last temperature before turn off the heater. */
    EEPROM_Initialization();
    /* Initialize Seven Segment to Display selected temperature. */
    SevenSegment_Initialization();
    /* Enable pull up resistor on portB. */
    GPIO_Enable_Pull_Up_On_PortB();
    /* Set Cooler pin as output to control the fan. */
    GPIO_SetPinDirection(COOLER_PORT , COOLER_PIN , OUTPUT);
    /* Enable ADC peripheral on channel 2 (A2) for temperature sensor. with pre_scaler 16 for 8MHZ clock. */
    ADC_Initialization(ADC_CHANNEL_2 , ADC_V_REF_DEFAULT_VALUE , ADC_V_REF_DEFAULT_VALUE);
    ADC_Select_prescaler(ADC_PRESCALER_16);
    /* Set Heating resistance pin as output to control the fan. */
    GPIO_SetPinDirection(HEATING_RESISTANCE_PORT , HEATING_RESISTANCE_PIN , OUTPUT);
    /* Set LED pin output to control the heating LED */
    GPIO_SetPinDirection(LEDS_PORT , LED1_PIN , OUTPUT);
    GPIO_SetPinDirection(LEDS_PORT , LED2_PIN , OUTPUT);
    GPIO_SetPinDirection(LEDS_PORT , LED3_PIN , OUTPUT);
    GPIO_SetPinDirection(LEDS_PORT , LED4_PIN , OUTPUT);
    GPIO_SetPinDirection(LEDS_PORT , LED5_PIN , OUTPUT);
    /* Set push button pin as input to get user input when he want to increase heater temperature. */
    GPIO_SetPinDirection(UP_PORT , UP_PIN , INPUT);
    /* Set push button pin as input to get user input when he want to decrease heater temperature. */
    GPIO_SetPinDirection(DOWN_PORT , DOWN_PIN , INPUT);
    /* Set push button pin as input to get user input when he want to turn on/off the device. */
    GPIO_SetPinDirection(ON_OFF_PORT , ON_OFF_PIN , INPUT);
    /* Enable global interrupt for timer interrupt and external interrupt. */
    Global_interrupt_enable();
    /* Enable Timer1 interrupt at overflow. */
    Timer1_enable_overflow_interrupt();
    /* Set call back function of Timer1 ISR to execute at Timer1 interrupt */
    Timer1_set_callback_function(TIMER1_ISR);   
    /* Set Timer1 pre_scaler to get desired time. */
    Timer1_config_t.timer_prescaler_t = TIMER1_PRESCALER_4;
    /* Initialize Timer1 */
    Timer1_Initialization();
    /* Select the edge for External interrupt that the interrupt will trigger. */
    External_interrupt_select_falling_edge();
    /* Enable external interrupt to wake the device up by it at the sleeping mood. */
    External_interrupt_enable();
}

/*******************************************************************************
 * Function Name:	Heater_turn_on
 *
 * Description: 	Turn the device on by enable Timer1 and enable its interrupt
 *                  and get the last saved temperature from EEPROM.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_turn_on(void)
{
    /* buffer to get saved temperature from EEPROM. */
    uint8 u8Saved_temperature_in_EEPROM = EEPROM_Read_Byte(EEPROM_LOCATION_FOR_SAVED_TEMP);
    /* Get saved temperature from EEPROM if it between 35 and 75, else make the user temperature equal 60 degree. */
    g_u8Heater_wanted_temperature = (u8Saved_temperature_in_EEPROM >= 35 &&
                                     u8Saved_temperature_in_EEPROM <= 75) ? 
                                     u8Saved_temperature_in_EEPROM : 60;
    /* Enable peripherals interrupt to get interrupt from Timer1 at overflow. */
    Peripherals_interrupt_enable();
    /* Initialize Timer1 counter with specific value to get interrupt every 100ms. */
    Timer1_write_counter(15535);
    /* Enable Timer1. */
    Timer1_enable();
    /* Change the device state to heating process to start heating. */
    g_Heater_state_t = HEATER_ON_STATE;
}

/*******************************************************************************
 * Function Name:	Heater_display_on_temperature
 *
 * Description: 	Display the selected temperature on Seven Segments.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_display_on_temperature(void)
{
    /* turn off all Seven segments. */
    SevenSegment_SelectChip(SEVEN_SEGMENT_DISABLE_CHIP , SEVEN_SEGMENT_DISABLE_CHIP ,
                            SEVEN_SEGMENT_DISABLE_CHIP , SEVEN_SEGMENT_DISABLE_CHIP);
    /* if condition to change between two seven segment to display different numbers on them.*/
    if(g_u8Sync_flag == 0)
    {

        /* display the second digit of the temperature. */
        SevenSegment_Display(g_u8Heater_real_time_temperature / 10 ,
                             SEVEN_SEGMENT_NOT_DISPLAY_DOT);
        /* Enable Seven segment number 2 only. */
        SevenSegment_SelectChip(SEVEN_SEGMENT_DISABLE_CHIP ,
                                SEVEN_SEGMENT_ENABLE_CHIP ,
                                SEVEN_SEGMENT_DISABLE_CHIP ,
                                SEVEN_SEGMENT_DISABLE_CHIP);
        g_u8Sync_flag = 1;
        __delay_ms(5);
    }
    else
    {

        /* display the first digit of the temperature. */
        SevenSegment_Display(g_u8Heater_real_time_temperature % 10 ,
                             SEVEN_SEGMENT_NOT_DISPLAY_DOT);
        /* Enable Seven segment number 3 only. */
        SevenSegment_SelectChip(SEVEN_SEGMENT_DISABLE_CHIP ,
                                SEVEN_SEGMENT_DISABLE_CHIP ,
                                SEVEN_SEGMENT_ENABLE_CHIP ,
                                SEVEN_SEGMENT_DISABLE_CHIP);
        g_u8Sync_flag = 0;
        __delay_ms(5);
    }
}

/*******************************************************************************
 * Function Name:	Heater_change_temperature
 *
 * Description: 	change the temperature based on the user input by UP or DOWN
 *                  buttons in the Setup state.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_change_temperature(void)
{
    /* Check if the Down button was pressed to decrease the temperature. */
    if(Check_ON_Push_Button(DOWN_PORT , DOWN_PIN) == PUSH_BUTTON_IS_PRESSED)
    {
        /* reset the flag that make sure the 5 seconds pass without press any buttons to return to heating state. */
        g_u8End_setup_state = 0;
        /* reset the flag that make sure the temperature blank every one second at setup state. */
        g_u8Display_blank_counter = 0;
        /* check if the user input temperature less than the boundary temperature or not. */
        if(g_u8Heater_wanted_temperature > MIN_TEMPERATURE)
        {
            /* decrease the heating temperature with 5 degrees. */
            g_u8Heater_wanted_temperature -= 5;
            /* make real time temperature equal wanted temperature to display wanted temperature. */
            g_u8Heater_real_time_temperature = g_u8Heater_wanted_temperature;
        }
        else
        {
            /* Do Nothing */
        }
    }
    /* Check if the Up button was pressed to increase the temperature. */
    else if(Check_ON_Push_Button(UP_PORT , UP_PIN) == PUSH_BUTTON_IS_PRESSED)
    {
        /* reset the flag that make sure the 5 seconds pass without press any buttons to return to heating state. */
        g_u8End_setup_state = 0;
        /* reset the flag that make sure the temperature blank every one second at setup state. */
        g_u8Display_blank_counter = 0;
        /* check if the user input temperature greater than the boundary temperature or not. */
        if(g_u8Heater_wanted_temperature < MAX_TEMPERATURE)
        {
            /* increase the heating temperature with 5 degrees. */
            g_u8Heater_wanted_temperature += 5;
            /* make real time temperature equal wanted temperature to display wanted temperature. */
            g_u8Heater_real_time_temperature = g_u8Heater_wanted_temperature;
        }
        else
        {
            /* Do Nothing */
        }
    }
    /* Check if the On/Off button was pressed to turn the device off. */
    else if(Check_ON_Push_Button(ON_OFF_PORT , ON_OFF_PIN) == PUSH_BUTTON_IS_PRESSED)
    {
        /* turn off all used peripherals and save temperature on EEPROM for next usage. */
        Heater_turn_off();
    }
    else
    {
        /* Do nothing */
    }
}

/*******************************************************************************
 * Function Name:	Heater_reading_last_ten_temperature_values
 *
 * Description: 	get new reading from temperature sensor every 100ms and add
 *                  it to the array for last 10 readings.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_reading_last_ten_temperature_values(void)
{
    /* buffer to get the temperature sensor reading. */
    uint8 g_u8Current_reading_temperature;
    /* check on the calculation flag to get a sample every 100ms. */
    if(g_u8calculate_temperature_flag == 0)
    {
        /* start ADC sampling. */
        ADC_Start_conversion();
        /* get the temperature from ADC channel. */
        g_u8Current_reading_temperature = ADC_Read_value() / 2;
        /* check on the temperature to make it suitable with showing temperature on the PICSimulation program. (issue in the Simulation program) */
        g_u8Current_reading_temperature = g_u8Current_reading_temperature > 40 ?
                                          g_u8Current_reading_temperature - 1 : g_u8Current_reading_temperature;
        /* check if the sensor reading less than 10 readings to get the average. */
        if(g_u8Reading_counter < 10)
        {
            /* add the current sample to the sum of last samples. */
            g_u16Sum_of_ten_readings += g_u8Current_reading_temperature;
            /* add the reading to the array of the last 10 readings. */
            g_u8Reading_arr[g_u8Reading_counter] = g_u8Current_reading_temperature;
            /* increment the counter. */
            g_u8Reading_counter++;
            /* make real time temperature equal the current sensor reading. */
            g_u8Heater_real_time_temperature = g_u8Heater_wanted_temperature;
        }
        /* the sensor sampled 10 samples or more. */
        else
        {
            /* add the new reading to the summation and remove the tenth oldest one. */
            g_u16Sum_of_ten_readings = g_u16Sum_of_ten_readings + g_u8Current_reading_temperature -
                                       g_u8Reading_arr[g_u8Reading_deleted_element];
            /* replace the tenth oldest sample with the current reading. */
            g_u8Reading_arr[g_u8Reading_deleted_element] = g_u8Current_reading_temperature;
            /* check if the array get its limit to return to the first element in the array of readings. */
            if(g_u8Reading_deleted_element == 9)
            {
                g_u8Reading_deleted_element = 0;
            }
            else
            {
                /* increment the index of the next deleted reading. */
                g_u8Reading_deleted_element++;
            }
            /* turn heating or cooling based on the new average of the new last 10 readings. */
            Heater_heating_cooling_process();
        }
        /* change the calculation flag to not get new reading for 100ms. */
        g_u8calculate_temperature_flag = 1;
    }
    else
    {
        /* Do nothing */
    }
}

/*******************************************************************************
 * Function Name:	Heater_check_if_change_state_to_setup_or_off
 *
 * Description: 	check if the user press on any button while the heating state.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_check_if_change_state_to_setup_or_off(void)
{
    /* check if the user want to update heating temperature while the heating process. */
    if(Check_ON_Push_Button(DOWN_PORT , DOWN_PIN) == PUSH_BUTTON_IS_PRESSED ||
       Check_ON_Push_Button(UP_PORT , UP_PIN) == PUSH_BUTTON_IS_PRESSED)
    {
        /* change the device state to setup state. */
        g_Heater_state_t = HEATER_SET_TEMERATURE;
        /* Disable heater, cooler and LED. */
        GPIO_WriteOnPin(HEATING_RESISTANCE_PORT , HEATING_RESISTANCE_PIN , DISABLE);
        GPIO_WriteOnPin(COOLER_PORT , COOLER_PIN , DISABLE);
        GPIO_WriteOnPin(LEDS_PORT , LED5_PIN , DISABLE);
        /* make real time temperature equal wanted temperature to display wanted temperature. */
        g_u8Heater_real_time_temperature = g_u8Heater_wanted_temperature;
        g_u8Sync_flag = 0;
    }
    /* check if the user want to turn the device off while the heating process. */
    else if(Check_ON_Push_Button(ON_OFF_PORT , ON_OFF_PIN) == PUSH_BUTTON_IS_PRESSED)
    {
        /* turn off all peripherals and reset all flags and save the temperature on EEPROM for the next usage. */
        Heater_turn_off();
    }
    else
    {
        /* Do nothing */
    }
}

/*******************************************************************************
 * Function Name:	Heater_blank_temperature
 *
 * Description: 	blank the temperature on the Seven Segments Every 1 second at setup state..
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Heater_blank_temperature(void)
{
    /* check on blank flag to blank the temperature on the Seven Segments Every 1 second at setup state. */
    if(g_u8Display_blank_counter < 10)
    {
        Heater_display_on_temperature();
    }
    else if(g_u8Display_blank_counter == 10)
    {
        Heater_display_off_temperature();
    }
    else if(g_u8Display_blank_counter == 20)
    {
        g_u8Display_blank_counter = 0;
    }
    else
    {
        /* Do Nothing */
    }
}

/*******************************************************************************
 * Function Name:	Check_ON_Push_Button
 *
 * Description: 	Get the state of Push Button.
 *
 * Inputs:			uint8 a_u8Port: for push Button connecting port.
 *                  uint8 a_u8Pin:  for push Button connecting pin.
 *
 * Outputs:			NULL
 *
 * Return:			EnumButton_State_t: typedef for states of the Push Button.
 *******************************************************************************/
EnumButton_State_t Check_ON_Push_Button(uint8 a_u8Port , uint8 a_u8Pin)
{
    /* return value to determine if the bush button was pressed or not. */
    EnumButton_State_t retVal_t = PUSH_BUTTON_IS_NOT_PRESSED;
    /* check on the button. */
    if(GPIO_ReadFromPin(a_u8Port , a_u8Pin) == PUSH_BUTTON_IS_PRESSED)
    {
        /* de_bouncing time to make sure the button was pressed. */
        __delay_ms(5);
        /* check the button again. */
        if(GPIO_ReadFromPin(a_u8Port , a_u8Pin) == PUSH_BUTTON_IS_PRESSED)
        {
            /* keep in this point till the button is released to prevent multi presses for the one press. */
            while(GPIO_ReadFromPin(a_u8Port , a_u8Pin) == PUSH_BUTTON_IS_PRESSED);
            retVal_t = PUSH_BUTTON_IS_PRESSED;
        }
        else
        {
            /* Do Nothing. */
        }
    }
    else
    {
        /* Do Nothing. */
    }
    /* return the status of button. */
    return retVal_t;
}
