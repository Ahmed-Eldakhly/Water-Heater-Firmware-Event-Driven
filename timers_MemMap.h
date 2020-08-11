/******************************************************************************* 
 * File:                timers_MemMap.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains memory mapping for all timers registers in
 *                      micro1-controller.
 * 
 * Revision history:    2/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */ 
#ifndef TIMERS_MEM_MAP_H
#define	TIMERS_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define TIMER_0_REG                                  *(volatile uint8*)0x01
#define TIMER_0_OPTION_REG                           *(volatile uint8*)0x81
#define TIMER_0_CLOCK_SOURCE_SELECT                 5u
#define TIMER_0_SOURCE_EDGE_SELECT                  4u
#define TIMER_0_PRESCALER_ENABLE_BIT                3u
#define TIMER_0_PRESCALER_SELECT_BIT_2              2u
#define TIMER_0_PRESCALER_SELECT_BIT_1              1u
#define TIMER_0_PRESCALER_SELECT_BIT_0              0u

#define TIMER_1_HIGH_REG                            *(volatile uint8*)0x0F
#define TIMER_1_LOW_REG                             *(volatile uint8*)0x0E
#define TIMER_1_CONTROL_REG                         *(volatile uint8*)0x10
#define TIMER_1_PRESCALER_SELECT_BIT_1              5u
#define TIMER_1_PRESCALER_SELECT_BIT_0              4u
#define TIMER_1_OSCILLATOR_ENABLE_BIT               3u
#define TIMER_1_EXTERNAL_CLOCK_SYNC_BIT_ACTIVE_LOW  2u
#define TIMER_1_CLOCK_SOURCE_SELECT                 1u
#define TIMER_1_ON_OFF_BIT                          0u

#define TIMER_2_REG                                 *(volatile uint8*)0x11
#define TIMER_2_PERIOD_REG                          *(volatile uint8*)0x92
#define TIMER_2_CONTROL_REG                         *(volatile uint8*)0x12
#define TIMER_2_POSTSCALER_SELECT_BIT_3             6u
#define TIMER_2_POSTSCALER_SELECT_BIT_2             5u
#define TIMER_2_POSTSCALER_SELECT_BIT_1             4u
#define TIMER_2_POSTSCALER_SELECT_BIT_0             3u
#define TIMER_2_ON_OFF_BIT                          2u
#define TIMER_2_PRESCALER_SELECT_BIT_1              1u
#define TIMER_2_PRESCALER_SELECT_BIT_0              0u


#endif	/* TIMERS_MEM_MAP_H */

