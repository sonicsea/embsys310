#include "delay.h"
#include <stdint.h>

extern int delay_counter;
void delay(uint32_t delayInMilliseconds)
{
    delay_counter = delayInMilliseconds;
}