/********************************************************************************** 
 * File:                timers.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains prototypes and enums of all timers peripherals.
 * 
 * Revision history:    2/7/2020
 * 
 **********************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once.*/  
#ifndef TIMERS_H
#define	TIMERS_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"
#include "timers_config.h"

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

/* check if timer 0 will used */
#if TIMER0 == TIMER_ENABLE

/************************** EnumTimer_clockSource_t ****************************/
typedef enum{
            TIMER0_INTERNAL_CLOCK,
            TIMER0_TRANSITION_ON_TCKI_PIN
}EnumTimer0_clockSource_t;

/*************************** EnumTimer0_prescaler_t ****************************/
typedef enum{
            TIMER0_PRESCALER_2,
            TIMER0_PRESCALER_4,
            TIMER0_PRESCALER_8,
            TIMER0_PRESCALER_16,
            TIMER0_PRESCALER_32,
            TIMER0_PRESCALER_64,
            TIMER0_PRESCALER_128,
            TIMER0_PRESCALER_256,
            TIMER0_NO_PRESCALER
}EnumTimer0_prescaler_t;

/************************ EnumTimer0_edgeTypeOn_TCKI_t *************************/
typedef enum{
            TIMER0_RISING_EDGE_CLOCK_ON_TCKI,
            TIMER0_FALLING_EDGE_CLOCK_ON_TCKI,
            TIMER0_NO_TRANSITION_ON_TCKI
}EnumTimer0_edgeTypeOn_TCKI_t;

/***************************** StrTimer0_config_t ******************************/
typedef struct{
            EnumTimer0_prescaler_t          timer_prescaler_t;
            EnumTimer0_clockSource_t         timer_clock_source_t;
            EnumTimer0_edgeTypeOn_TCKI_t    timer_edge_type_on_TCKI_t;
}StrTimer0_config_t;

/*******************************************************************************
 *                           extern Variables                                  *
 *******************************************************************************/
/* structure of timer 0 configuration that the user will set */
extern StrTimer0_config_t Timer0_config_t;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

/********************************************************************************
 * Function Name:	Timer0_Initialization
 *
 * Description: 	Initialize timer 0 with specified configuration in 
 *                  configuration structure.Initialize timer 0 with specified
 *                  configuration in configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer0_Initialization(void);

/********************************************************************************
 * Function Name:	Timer0_read_counter
 *
 * Description: 	read the number has been counted from zero by timer 0. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint8       number of counts
 *******************************************************************************/
extern uint8 Timer0_read_counter(void);

/********************************************************************************
 * Function Name:	Timer0_write_counter
 *
 * Description: 	write user value in timer 0 counter to start count from this
 *                  number. 
 *
 * Inputs:			uint8       user number to put in timer counter.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer0_write_counter(uint8 a_u8init_value_for_timer);
#endif

/* check if timer 1 will used */
#if TIMER1 == TIMER_ENABLE

/*******************************************************************************
 *                           Types Declaration                                 *
 *******************************************************************************/

/************************** EnumTimer_clockSource_t ****************************/
typedef enum{
            TIMER1_INTERNAL_CLOCK,
            TIMER1_TRANSITION_ON_TCKI_PIN
}EnumTimer1_clockSource_t;

/*************************** EnumTimer1_prescaler_t ****************************/
typedef enum{
            TIMER1_NO_PRESCALER,
            TIMER1_PRESCALER_2,
            TIMER1_PRESCALER_4,
            TIMER1_PRESCALER_8
}EnumTimer1_prescaler_t;

/******************** EnumTimer1_sync_with_external_clock_t ********************/
typedef enum{
            TIMER1_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER1_NOT_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER1_NO_EXTERNAL_CLOCK
}EnumTimer1_sync_with_external_clock_t;

/***************************** StrTimer1_config_t ******************************/
typedef struct{
            EnumTimer1_prescaler_t                  timer_prescaler_t;
            EnumTimer1_clockSource_t                 timer_clock_source_t;
            EnumTimer1_sync_with_external_clock_t   timer_sync_with_external_clock;
}StrTimer1_config_t;

/*******************************************************************************
 *                           extern Variables                                  *
 *******************************************************************************/
/* structure of timer 1 configuration that the user will set */
extern StrTimer1_config_t Timer1_config_t;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

/********************************************************************************
 * Function Name:	Timer1_Initialization
 *
 * Description: 	Initialize timer 1 with specified configuration in 
 *                  configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_Initialization(void);

/********************************************************************************
 * Function Name:	Timer1_enable
 *
 * Description: 	enable timer 1 to start counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_enable(void);

/********************************************************************************
 * Function Name:	Timer1_disable
 *
 * Description: 	disable timer 1 to stop counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_disable(void);

/********************************************************************************
 * Function Name:	Timer1_read_counter
 *
 * Description: 	read the number has been counted from zero by timer 1. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint16       number of counts
 *******************************************************************************/
extern uint16 Timer1_read_counter(void);

/********************************************************************************
 * Function Name:	Timer1_write_counter
 *
 * Description: 	write user value in timer 1 counter to start count from this
 *                  number. 
 *
 * Inputs:			uint16       user number to put in timer counter
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_write_counter(uint16 a_u16init_value_for_timer);

/********************************************************************************
 * Function Name:	Timer1_oscillator_enable
 *
 * Description: 	enable timer 1 oscillator to use. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_oscillator_enable(void);

/********************************************************************************
 * Function Name:	Timer1_oscillator_disable
 *
 * Description: 	disable timer 1 oscillator. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_oscillator_disable(void);

#endif

/* check if timer 2 will used */
#if TIMER2 == TIMER_ENABLE

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

/*************************** EnumTimer2_prescaler_t ****************************/
typedef enum{
            TIMER2_NO_PRESCALER,
            TIMER2_PRESCALER_4,
            TIMER2_PRESCALER_16
}EnumTimer2_prescaler_t;

/*************************** EnumTimer2_postscaler_t ***************************/
typedef enum{
            TIMER2_POSTSCALER_1,
            TIMER2_POSTSCALER_2,
            TIMER2_POSTSCALER_3,
            TIMER2_POSTSCALER_4,
            TIMER2_POSTSCALER_5,
            TIMER2_POSTSCALER_6,
            TIMER2_POSTSCALER_7,
            TIMER2_POSTSCALER_8,
            TIMER2_POSTSCALER_9,
            TIMER2_POSTSCALER_10,
            TIMER2_POSTSCALER_11,
            TIMER2_POSTSCALER_12,
            TIMER2_POSTSCALER_13,
            TIMER2_POSTSCALER_14,
            TIMER2_POSTSCALER_15,
            TIMER2_POSTSCALER_16
}EnumTimer2_postscaler_t;

/***************************** StrTimer2_config_t ******************************/
typedef struct{
            EnumTimer2_prescaler_t                  timer_prescaler_t;
            EnumTimer2_postscaler_t                 timer_postscaler_t;
}StrTimer2_config_t;

/*******************************************************************************
 *                           extern Variables                                  *
 *******************************************************************************/
/* structure of timer 2 configuration that the user will set */
extern StrTimer2_config_t Timer2_config_t;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

/********************************************************************************
 * Function Name:	Timer2_Initialization
 *
 * Description: 	Initialize timer 2 with specified configuration in 
 *                  configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_Initialization(void);

/********************************************************************************
 * Function Name:	Timer2_enable
 *
 * Description: 	enable timer 2 to start counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_enable(void);

/********************************************************************************
 * Function Name:	Timer2_disable
 *
 * Description: 	disable timer 2 to stop counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_disable(void);

/********************************************************************************
 * Function Name:	Timer2_read_counter
 *
 * Description: 	read the number has been counted from zero by timer 2. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint8       number of counts
 *******************************************************************************/
extern uint8 Timer2_read_counter(void);

/********************************************************************************
 * Function Name:	Timer2_write_counter
 *
 * Description: 	write user value in timer 2 counter to start count from this
 *                  number. 
 *
 * Inputs:			uint8       user number to put in timer counter
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_write_counter(uint8 a_u8init_value_for_timer);

/********************************************************************************
 * Function Name:	Timer2_read_period_register
 *
 * Description: 	read the match value that the timer 2 counter will reset when
 *                  matching with it. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint8       number of counts
 *******************************************************************************/
extern uint8 Timer2_read_period_register(void);
/********************************************************************************
 * Function Name:	Timer2_write_period_register
 *
 * Description: 	write the match value that the timer 2 counter will reset when
 *                  matching with it.
 *
 * Inputs:			uint8       match value to reset the timer 2 counter.
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_write_period_register(uint8 a_u8init_value_for_period_register);
#endif

#endif	/* TIMERS_H */

