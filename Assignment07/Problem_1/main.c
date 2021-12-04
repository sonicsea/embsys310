#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"

#define SYS_CLOCK_HZ 4000u;

const int TOTAL_DELAY_MS = 1000;

int delay_counter;

void SysTick_Initialize(void);

int main()
{
  // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x5
    // Set bit[5] to 1 --> 0x4000; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    SysTick_Initialize();
    
    while(1)
    {
      if (delay_counter == 0)
      {
        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(TOTAL_DELAY_MS);
      }
    } 
    return 0;
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;
    SysTick->VAL = 0x0;
    SysTick->CTRL = 0x7;
}

void SysTick_Handler(void)
{
    delay_counter--;
}
