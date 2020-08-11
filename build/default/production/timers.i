# 1 "timers.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "timers.c" 2
# 17 "timers.c"
# 1 "./timers.h" 1
# 20 "./timers.h"
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
# 20 "./timers.h" 2

# 1 "./timers_config.h" 1
# 21 "./timers.h" 2
# 124 "./timers.h"
typedef enum{
            TIMER1_INTERNAL_CLOCK,
            TIMER1_TRANSITION_ON_TCKI_PIN
}EnumTimer1_clockSource_t;


typedef enum{
            TIMER1_NO_PRESCALER,
            TIMER1_PRESCALER_2,
            TIMER1_PRESCALER_4,
            TIMER1_PRESCALER_8
}EnumTimer1_prescaler_t;


typedef enum{
            TIMER1_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER1_NOT_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER1_NO_EXTERNAL_CLOCK
}EnumTimer1_sync_with_external_clock_t;


typedef struct{
            EnumTimer1_prescaler_t timer_prescaler_t;
            EnumTimer1_clockSource_t timer_clock_source_t;
            EnumTimer1_sync_with_external_clock_t timer_sync_with_external_clock;
}StrTimer1_config_t;





extern StrTimer1_config_t Timer1_config_t;
# 173 "./timers.h"
extern void Timer1_Initialization(void);
# 186 "./timers.h"
extern void Timer1_enable(void);
# 199 "./timers.h"
extern void Timer1_disable(void);
# 212 "./timers.h"
extern uint16 Timer1_read_counter(void);
# 226 "./timers.h"
extern void Timer1_write_counter(uint16 a_u16init_value_for_timer);
# 239 "./timers.h"
extern void Timer1_oscillator_enable(void);
# 252 "./timers.h"
extern void Timer1_oscillator_disable(void);
# 17 "timers.c" 2

# 1 "./timers_MemMap.h" 1
# 18 "timers.c" 2

# 1 "./helped_macros.h" 1
# 19 "timers.c" 2
# 123 "timers.c"
void Timer1_Initialization(void)
{

    if(Timer1_config_t.timer_clock_source_t == TIMER1_INTERNAL_CLOCK)
    {
        *(volatile uint8*)0x10 &= ~(1 << 1u);
    }
    else
    {
        *(volatile uint8*)0x10 |= 1 << 1u;
    }

    if(Timer1_config_t.timer_clock_source_t != TIMER1_INTERNAL_CLOCK)
    {
        *(volatile uint8*)0x10 &= 0xFB;
        *(volatile uint8*)0x10 |= Timer1_config_t.timer_sync_with_external_clock << 2;
    }
    else
    {
                      ;
    }

    switch(Timer1_config_t.timer_prescaler_t)
    {
        case TIMER1_NO_PRESCALER:
            *(volatile uint8*)0x10 &= ~(1 << 5u);
            *(volatile uint8*)0x10 &= ~(1 << 4u);
            break;
        case TIMER1_PRESCALER_2:
            *(volatile uint8*)0x10 &= ~(1 << 5u);
            *(volatile uint8*)0x10 |= 1 << 4u;
            break;
        case TIMER1_PRESCALER_4:
            *(volatile uint8*)0x10 |= 1 << 5u;
            *(volatile uint8*)0x10 &= ~(1 << 4u);
            break;
        case TIMER1_PRESCALER_8:
            *(volatile uint8*)0x10 |= 1 << 5u;
            *(volatile uint8*)0x10 |= 1 << 4u;
            break;
        default:

            break;
    }
}
# 180 "timers.c"
void Timer1_enable(void)
{
    *(volatile uint8*)0x10 |= 1 << 0u;
}
# 196 "timers.c"
void Timer1_disable(void)
{
    *(volatile uint8*)0x10 &= ~(1 << 0u);
}
# 212 "timers.c"
uint16 Timer1_read_counter(void)
{
    uint16 retVal;

    *(volatile uint8*)0x10 &= ~(1 << 0u);

    retVal = *(volatile uint8*)0x0E;

    retVal |= ((uint16)*(volatile uint8*)0x0F) << 8;

    *(volatile uint8*)0x10 |= 1 << 0u;
    return retVal;
}
# 238 "timers.c"
void Timer1_write_counter(uint16 a_u16init_value_for_timer)
{

    *(volatile uint8*)0x10 &= ~(1 << 0u);

    *(volatile uint8*)0x0F = a_u16init_value_for_timer >> 8;

    *(volatile uint8*)0x0E = (uint8)a_u16init_value_for_timer;

    *(volatile uint8*)0x10 |= 1 << 0u;
}
# 261 "timers.c"
void Timer1_oscillator_enable(void)
{
    *(volatile uint8*)0x10 |= 1 << 3u;
}
# 277 "timers.c"
void Timer1_oscillator_disable(void)
{
    *(volatile uint8*)0x10 &= ~(1 << 3u);
}
