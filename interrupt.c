/*******************************************************************************
 *  
 * File:                interrupt.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains implementation of all interrupts in
 *                      this micro_controller.
 * 
 * Revision history:    2/7/2020
 * 
 ******************************************************************************/
 
/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/           
#include "interrupt.h"
#include "interrupt_MemMap.h"
#include "helped_macros.h"

/*******************************************************************************
 *                      Functions implementation                               *
 *******************************************************************************/

/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED

/* static variable used to call user interrupt function in interrupt handler */
static void (*timer0_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Timer0_enable_overflow_interrupt
 *
 * Description: 	enable timer 0 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer0_enable_overflow_interrupt(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG , TIMER0_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Timer0_disable_overflow_interrupt
 *
 * Description: 	disable timer 0 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer0_disable_overflow_interrupt(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG , TIMER0_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Timer0_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer0_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    timer0_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if TIMER_1_INTERRUPT == INTERRUPT_USED 
/* static variable used to call user interrupt function in interrupt handler */
static void (*timer1_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Timer1_enable_overflow_interrupt
 *
 * Description: 	enable timer 1 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_enable_overflow_interrupt(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Timer1_disable_overflow_interrupt
 *
 * Description: 	disable timer 1 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_disable_overflow_interrupt(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Timer1_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    timer1_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if TIMER_2_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*timer2_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Timer2_enable_match_interrupt
 *
 * Description: 	enable timer 2 interrupt when match occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_enable_match_interrupt(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Timer2_disable_match_interrupt
 *
 * Description: 	disable timer 2 interrupt when match occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_disable_match_interrupt(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Timer2_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    timer2_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*external_interrupt_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	External_interrupt_enable
 *
 * Description: 	enable external interrupt when event occur on pin 0 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void External_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG , EXTERNAL_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	External_interrupt_disable
 *
 * Description: 	disable external interrupt when event occur on pin 0 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void External_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG , EXTERNAL_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	External_interrupt_select_rising_edge
 *
 * Description: 	set the rising edge as the reason of external interrupt.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void External_interrupt_select_rising_edge(void)
{
    SET_BIT(INTERRUPT_OPTIAN_REG , EXTERNAL_INTERRUPT_EDGE_SELECT_BIT);
}

/*******************************************************************************
 * Function Name:	External_interrupt_select_falling_edge
 *
 * Description: 	set the falling edge as the reason of external interrupt.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void External_interrupt_select_falling_edge(void)
{
    CLEAR_BIT(INTERRUPT_OPTIAN_REG , EXTERNAL_INTERRUPT_EDGE_SELECT_BIT);
}

/*******************************************************************************
 * Function Name:	External_interrupt_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void External_interrupt_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    external_interrupt_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*port_change_interrupt_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Port_change_interrupt_enable
 *
 * Description: 	enable interrupt when signal change on pin 4,5,6 and 7 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Port_change_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG , PORTB_CHANGE_INTERRUPT__ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Port_change_interrupt_disable
 *
 * Description: 	disable interrupt when signal change on pin 4,5,6 and 7 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Port_change_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG , PORTB_CHANGE_INTERRUPT__ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Port_change_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Port_change_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    port_change_interrupt_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*USART_recieve_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	USART_receive_interrupt_enable
 *
 * Description: 	enable interrupt when USART receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void USART_receive_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_RECEIVE_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	USART_receive_interrupt_disable
 *
 * Description: 	disable interrupt when USART receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void USART_receive_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_RECEIVE_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	USART_receive_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void USART_receive_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    USART_recieve_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*USART_transmit_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	USART_transmit_interrupt_enable
 *
 * Description: 	enable interrupt when USART finish sending data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void USART_transmit_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_TRANSMIT_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	USART_transmit_interrupt_disable
 *
 * Description: 	disable interrupt when USART finish sending data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void USART_transmit_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_TRANSMIT_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	USART_transmit_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void USART_transmit_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    USART_transmit_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if ADC_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*ADC_converter_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	ADC_converter_interrupt_enable
 *
 * Description: 	enable interrupt when ADC finish conversion.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_converter_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , ADC_CONVERTER_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_converter_interrupt_disable
 *
 * Description: 	disable interrupt when ADC finish conversion.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_converter_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , ADC_CONVERTER_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_converter_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_converter_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    ADC_converter_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*spi_master_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	SPI_master_interrupt_enable
 *
 * Description: 	enable interrupt when SPI master finish send and receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void SPI_master_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , SPI_MASTER_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	SPI_master_interrupt_disable
 *
 * Description: 	disable interrupt when SPI master finish send and receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void SPI_master_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , SPI_MASTER_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	SPI_master_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void SPI_master_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    spi_master_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*parallel_slave_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Parallel_slave_interrupt_enable
 *
 * Description: 	enable interrupt when Port D in mode parallel slave when 
 *                  micro_controller receive write or read signal.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Parallel_slave_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , PARALLEL_SLAVE_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Parallel_slave_interrupt_disable
 *
 * Description: 	disable interrupt when Port D in mode parallel slave when 
 *                  micro_controller receive write or read signal.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Parallel_slave_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , PARALLEL_SLAVE_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Parallel_slave_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Parallel_slave_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    parallel_slave_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*capture_compare_1_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Capture_Compare_1_interrupt_enable
 *
 * Description: 	enable interrupt when the micro_controller capture determined
 *                  signal on Pin 2 on Port C.
 *                  enable interrupt when timer 1 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Capture_Compare_1_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Capture_Compare_1_interrupt_disable
 *
 * Description: 	disable interrupt when the micro_controller capture determined
 *                  signal on Pin 2 on Port C.
 *                  disable interrupt when timer 1 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Capture_Compare_1_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Capture_Compare_1_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Capture_Compare_1_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    capture_compare_1_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*capture_compare_2_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Capture_Compare_2_interrupt_enable
 *
 * Description: 	enable interrupt when the micro_controller capture determined
 *                  signal on Pin 1 on Port C.
 *                  enable interrupt when timer 1 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Capture_Compare_2_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Capture_Compare_2_interrupt_disable
 *
 * Description: 	disable interrupt when the micro_controller capture determined
 *                  signal on Pin 1 on Port C.
 *                  disable interrupt when timer 1 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Capture_Compare_2_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Capture_Compare_2_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Capture_Compare_2_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    capture_compare_2_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if COMPARETOR_INTERRUPT == INTERRUPT_USED 
/* static variable used to call user interrupt function in interrupt handler */
static void (*comarator_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Comparator_interrupt_enable
 *
 * Description: 	enable interrupt when comparator input has changed.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Comparator_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , COMPARATOR_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Comparator_interrupt_disable
 *
 * Description: 	disable interrupt when comparator input has changed.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Comparator_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , COMPARATOR_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Comparator_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Comparator_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    comarator_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*EEPROM_write_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	EEPROM_write_interrupt_enable
 *
 * Description: 	enable interrupt when the EEPROM writing operation.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void EEPROM_write_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , EEPROM_WRITE_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	EEPROM_write_interrupt_disable
 *
 * Description: 	disable interrupt when the EEPROM writing operation.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void EEPROM_write_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , EEPROM_WRITE_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	EEPROM_write_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void EEPROM_write_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    EEPROM_write_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*bus_collision_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	Bus_collision_interrupt_enable
 *
 * Description: 	enable interrupt when Bus collision occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Bus_collision_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , BUS_COLLISION_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Bus_collision_interrupt_disable
 *
 * Description: 	disable interrupt when Bus collision occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Bus_collision_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , BUS_COLLISION_INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Bus_collision_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Bus_collision_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    bus_collision_callback_ptr = a_function_ptr;
}
#endif

/*******************************************************************************
 * Function Name:	Global_interrupt_enable
 *
 * Description: 	enable all masked interrupts when their flags equal to 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Global_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG , GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Global_interrupt_disable
 *
 * Description: 	disable all masked interrupts to prevent any interrupt to 
 *                  occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Global_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG , GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Peripherals_interrupt_enable
 *
 * Description: 	enable all peripherals interrupts when their flags equal to 1 
 *                  and the global interrupt is enabled.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Peripherals_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG , PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Peripherals_interrupt_disable
 *
 * Description: 	disable all peripherals interrupts to prevent any peripherals
 *                  interrupt to occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Peripherals_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG , PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ISR
 *
 * Description: 	interrupt handler function in this function all interrupt 
 *                  functions will execute when the interrupt flag, global interrupt
 *                  and the peripherals interrupt in some cases are equal 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void __interrupt () ISR(void)
{
/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer0_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer0_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if TIMER_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if TIMER_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG , EXTERNAL_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG , EXTERNAL_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG , PORTB_CHANGE_INTERRUPT__FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(port_change_interrupt_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            port_change_interrupt_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG , PORTB_CHANGE_INTERRUPT__FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_RECEIVE_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_recieve_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_recieve_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_TRANSMIT_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_transmit_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_transmit_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if ADC_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(ADC_converter_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            ADC_converter_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
    
/* check if this interrupt will use in program or not */   
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(spi_master_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            spi_master_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(parallel_slave_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            parallel_slave_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
 
/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if COMPARETOR_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(comarator_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            comarator_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(EEPROM_write_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            EEPROM_write_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
 
/* check if this interrupt will use in program or not */
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(bus_collision_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            bus_collision_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        //CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
}