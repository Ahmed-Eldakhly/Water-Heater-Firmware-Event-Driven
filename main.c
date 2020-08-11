/*******************************************************************************
 *  
 * File:                main.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            the application code.
 * 
 * Revision history:    7/7/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "heater.h"

/* main application code */
void main(void)
{
    /* initialize all peripherals that will be used in this device. */
    Heater_Initialization();
    while(1)
    {
        /* state machine for heater device. */
        switch(g_Heater_state_t)
        {
            case HEATER_OFF_STATE:
                /* check if the on button was pressed. */
                if(Check_ON_Push_Button(ON_OFF_PORT , ON_OFF_PIN) == PUSH_BUTTON_IS_PRESSED)
                {
                    /* turn the device on. */
                    Heater_turn_on();
                }
                else
                {
                    /* go to sleep mood to save the power. */
                    CPU_sleep();
                }
                break;
            case HEATER_ON_STATE:
                /* display the temperature on 2 Seven segments. */
                Heater_display_on_temperature();
                /* read a new sample from temperature sensor and update last 10 readings. */
                Heater_reading_last_ten_temperature_values();
                /* check if any button was pressed to change the device state. */
                Heater_check_if_change_state_to_setup_or_off();
                break;
            case HEATER_SET_TEMERATURE:
                /* plank the temperature on the Seven Segments every second. */
                Heater_blank_temperature();
                /* update the wanted temperature with the new user input. */
                Heater_change_temperature();
                break;
            default:
                /* Do Nothing */
                break;
        }
    }
}