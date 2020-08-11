# 1 "interrupt.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "interrupt.c" 2
# 17 "interrupt.c"
# 1 "./interrupt.h" 1
# 22 "./interrupt.h"
# 1 "./interrupt_config.h" 1
# 22 "./interrupt.h" 2

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
# 23 "./interrupt.h" 2
# 40 "./interrupt.h"
extern void Global_interrupt_enable(void);
# 53 "./interrupt.h"
extern void Global_interrupt_disable(void);
# 67 "./interrupt.h"
extern void Peripherals_interrupt_enable(void);
# 81 "./interrupt.h"
extern void Peripherals_interrupt_disable(void);
# 140 "./interrupt.h"
extern void Timer1_enable_overflow_interrupt(void);
# 153 "./interrupt.h"
extern void Timer1_disable_overflow_interrupt(void);
# 166 "./interrupt.h"
extern void Timer1_set_callback_function(void(*a_function_ptr)(void));
# 226 "./interrupt.h"
extern void External_interrupt_enable(void);
# 239 "./interrupt.h"
extern void External_interrupt_disable(void);
# 252 "./interrupt.h"
extern void External_interrupt_select_rising_edge(void);
# 265 "./interrupt.h"
extern void External_interrupt_select_falling_edge(void);
# 278 "./interrupt.h"
extern void External_interrupt_set_callback_function(void(*a_function_ptr)(void));
# 17 "interrupt.c" 2

# 1 "./interrupt_MemMap.h" 1
# 18 "interrupt.c" 2

# 1 "./helped_macros.h" 1
# 19 "interrupt.c" 2
# 84 "interrupt.c"
static void (*timer1_callback_ptr)(void) = (void*)0x00;
# 97 "interrupt.c"
void Timer1_enable_overflow_interrupt(void)
{
    *(volatile uint8*)0x8C |= 1 << 0u;
}
# 113 "interrupt.c"
void Timer1_disable_overflow_interrupt(void)
{
    *(volatile uint8*)0x8C &= ~(1 << 0u);
}
# 129 "interrupt.c"
void Timer1_set_callback_function(void(*a_function_ptr)(void))
{

    timer1_callback_ptr = a_function_ptr;
}
# 196 "interrupt.c"
static void (*external_interrupt_callback_ptr)(void) = (void*)0x00;
# 209 "interrupt.c"
void External_interrupt_enable(void)
{
    *(volatile uint8*)0x0B |= 1 << 4u;
}
# 225 "interrupt.c"
void External_interrupt_disable(void)
{
    *(volatile uint8*)0x0B &= ~(1 << 4u);
}
# 241 "interrupt.c"
void External_interrupt_select_rising_edge(void)
{
    *(volatile uint8*)0x81 |= 1 << 6u;
}
# 257 "interrupt.c"
void External_interrupt_select_falling_edge(void)
{
    *(volatile uint8*)0x81 &= ~(1 << 6u);
}
# 273 "interrupt.c"
void External_interrupt_set_callback_function(void(*a_function_ptr)(void))
{

    external_interrupt_callback_ptr = a_function_ptr;
}
# 916 "interrupt.c"
void Global_interrupt_enable(void)
{
    *(volatile uint8*)0x0B |= 1 << 7u;
}
# 933 "interrupt.c"
void Global_interrupt_disable(void)
{
    *(volatile uint8*)0x0B &= ~(1 << 7u);
}
# 950 "interrupt.c"
void Peripherals_interrupt_enable(void)
{
    *(volatile uint8*)0x0B |= 1 << 6u;
}
# 967 "interrupt.c"
void Peripherals_interrupt_disable(void)
{
    *(volatile uint8*)0x0B &= ~(1 << 6u);
}
# 985 "interrupt.c"
void __attribute__((picinterrupt(("")))) ISR(void)
{
# 1014 "interrupt.c"
    if(((*(volatile uint8*)0x0C >> 0u) & 0x01))
    {

        if(timer1_callback_ptr != (void*)0x00)
        {

            timer1_callback_ptr();
        }
        else
        {

        }

        *(volatile uint8*)0x0C &= ~(1 << 0u);
    }
    else
    {

    }
# 1062 "interrupt.c"
    if(((*(volatile uint8*)0x0B >> 1u) & 0x01))
    {

        if(external_interrupt_callback_ptr != (void*)0x00)
        {

            external_interrupt_callback_ptr();
        }
        else
        {

        }

        *(volatile uint8*)0x0B &= ~(1 << 1u);
    }
    else
    {

    }
# 1342 "interrupt.c"
}
