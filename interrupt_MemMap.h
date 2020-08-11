/*******************************************************************************
 *  
 * File:                interrupt_MemMap.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains memory mapping of interrupt registers in 
 *                      micro1-controller.
 * 
 * Revision history:    2/7/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */
#ifndef INTERRUPT_MEM_MAP_H
#define	INTERRUPT_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define INTERRUPT_OPTIAN_REG                            *(volatile uint8*)0x81
#define EXTERNAL_INTERRUPT_EDGE_SELECT_BIT              6u  

#define INTERRUPT_CONTROL_REG                           *(volatile uint8*)0x0B
#define GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT      7u  
#define PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT   6u  
#define TIMER0_OVERFLOW_INTERRUPT_ENABLE_BIT            5u  
#define EXTERNAL_INTERRUPT_ENABLE_BIT                   4u  
#define PORTB_CHANGE_INTERRUPT__ENABLE_BIT              3u  
#define TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT              2u  
#define EXTERNAL_INTERRUPT_FLAG_BIT                     1u  
#define PORTB_CHANGE_INTERRUPT__FLAG_BIT                0u  

#define INTERRUPT_PERIPHERAL_ENABLE_1                   *(volatile uint8*)0x8C
#define PARALLEL_SLAVE_INTERRUPT_ENABLE_BIT             7u  
#define ADC_CONVERTER_INTERRUPT_ENABLE_BIT              6u  
#define USART_RECEIVE_INTERRUPT_ENABLE_BIT              5u  
#define USART_TRANSMIT_INTERRUPT_ENABLE_BIT             4u  
#define SPI_MASTER_INTERRUPT_ENABLE_BIT                 3u  
#define CAPTURE_COMPARE_PWM_1_INTERRUPT_ENABLE_BIT      2u  
#define TIMER2_TO_PR2_MATCH_INTERRUPT_ENABLE_BIT        1u  
#define TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT            0u  

#define INTERRUPT_PERIPHERAL_ENABLE_2                   *(volatile uint8*)0x8D
#define COMPARATOR_INTERRUPT_ENABLE_BIT                 6u   
#define EEPROM_WRITE_INTERRUPT_ENABLE_BIT               4u  
#define BUS_COLLISION_INTERRUPT_ENABLE_BIT              3u 
#define CAPTURE_COMPARE_PWM_2_INTERRUPT_ENABLE_BIT      0u  

#define INTERRUPT_PERIPHERAL_FLAGS_1                    *(volatile uint8*)0x0C
#define PARALLEL_SLAVE_INTERRUPT_FLAG_BIT               7u  
#define ADC_CONVERTER_INTERRUPT_FLAG_BIT                6u  
#define USART_RECEIVE_INTERRUPT_FLAG_BIT                5u  
#define USART_TRANSMIT_INTERRUPT_FLAG_BIT               4u  
#define SPI_MASTER_INTERRUPT_FLAG_BIT                   3u  
#define CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT        2u  
#define TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT          1u  
#define TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT              0u  

#define INTERRUPT_PERIPHERAL_FLAGS_2                    *(volatile uint8*)0x0D
#define COMPARATOR_INTERRUPT_FLAG_BIT                   6u 
#define EEPROM_WRITE_INTERRUPT_FLAG_BIT                 4u  
#define BUS_COLLISION_INTERRUPT_FLAG_BIT                3u    
#define CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT        0u   

#endif	/* INTERRUPT_MEM_MAP_H */

