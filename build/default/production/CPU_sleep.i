# 1 "CPU_sleep.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "CPU_sleep.c" 2
# 15 "CPU_sleep.c"
# 1 "./helped_macros.h" 1
# 15 "CPU_sleep.c" 2

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
# 16 "CPU_sleep.c" 2
# 39 "CPU_sleep.c"
void CPU_sleep(void)
{

    __asm(" sleep");
}
