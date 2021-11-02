#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_BASE 0x48000000
#define GPIO_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ODR5 (1<<5)

int main()
{
  // Enable clock
  RCC_AHB2ENR |= 0x1;
  
  //Set GIPO port to become an output
  GPIO_MODER &= 0xFFFFF7FF;
  
  while(1){
    //Use XOR to toggle LED
    GPIOA_ODR ^= ODR5;
    
    for(int i = 0; i < 80000; i++);
    
  }
  return 0;
}
