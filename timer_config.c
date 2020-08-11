/*******************************************************************************
 *  
 * File:                timers_config.c
 *  
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configurations for all timer peripherals to 
 *                      set configuration parameters for enabled timer.
 * 
 * Revision history:    2/7/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "timers.h"

/*******************************************************************************
 *                       	configuration structures                           *
 *******************************************************************************/
/* check if timer 0 will used */
#if TIMER0 == TIMER_ENABLE
/* configuration structure to configure timer 0 with specified parameters. */
StrTimer0_config_t Timer0_config_t = {TIMER0_PRESCALER_32 , TIMER0_INTERNAL_CLOCK ,
                                      TIMER0_NO_TRANSITION_ON_TCKI};
#endif

/* check if timer 1 will used */
#if TIMER1 == TIMER_ENABLE
/* configuration structure to configure timer 1 with specified parameters. */
StrTimer1_config_t Timer1_config_t = {TIMER1_NO_PRESCALER , TIMER1_INTERNAL_CLOCK ,
                                      TIMER1_NO_EXTERNAL_CLOCK};
#endif

/* check if timer 2 will used */
#if TIMER2 == TIMER_ENABLE
/* configuration structure to configure timer 2 with specified parameters. */
StrTimer2_config_t Timer2_config_t = {TIMER2_NO_PRESCALER , TIMER2_POSTSCALER_1};
#endif