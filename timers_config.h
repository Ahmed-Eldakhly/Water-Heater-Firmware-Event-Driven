/*******************************************************************************
 *  
 * File:                timers_config.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configurations for all timer peripherals to 
 *                      enable or disable them.
 * 
 * Revision history:    2/7/2020
 * 
 ******************************************************************************/ 

/* This is a guard condition so that contents of this file are not included
 * more than once. */ 
#ifndef TIMERS_CONFIG_H
#define	TIMERS_CONFIG_H

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define TIMER_ENABLE                        0u
#define TIMER_DISABLE                       1u
/*-----------------------------------------------------------------------------*/
#define TIMER0                      TIMER_DISABLE
#define TIMER1                      TIMER_ENABLE
#define TIMER2                      TIMER_DISABLE

#endif	/* TIMERS_CONFIG_H */

