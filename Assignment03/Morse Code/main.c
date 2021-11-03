#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_BASE 0x48000000
#define GPIO_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ODR5 (1<<5)
#define ONE_UNIT 200000
#define THREE_UNIT (3 * ONE_UNIT)

void Toggle(int unit){
  GPIOA_ODR ^= ODR5;
  for(int i = 0; i < unit; i++);
}

void Dot(){
  Toggle(ONE_UNIT);
}

void Dash(){
  Toggle(THREE_UNIT);
}

void Part_Delimiter(){
  Toggle(ONE_UNIT);
}

void Letter_Delimiter(){
  Toggle(THREE_UNIT);
}

int main()
{
  // Enable clock
  RCC_AHB2ENR |= 0x1;
  
  //Set GIPO port to become an output
  GPIO_MODER &= 0xFFFFF7FF;
  
  // T: -
  Dash();
  
  Letter_Delimiter();
  
  // A: . -
  Dot();
  Part_Delimiter();
  Dash();
    
  Letter_Delimiter();
  
  //Y: - . - -
  Dash();
  Part_Delimiter();
  Dot();
  Part_Delimiter();
  Dash();
  Part_Delimiter();
  Dash();
  
  Letter_Delimiter();
  
  //L: . - . .
  Dot();
  Part_Delimiter();
  Dash();
  Part_Delimiter();
  Dot();
  Part_Delimiter();
  Dot();
  
  Letter_Delimiter();
  
  //O: - - -
  Dash();
  Part_Delimiter();
  Dash();
  Part_Delimiter();
  Dash();
  
  Letter_Delimiter();
  
  //R: . - .
  Dot();
  Part_Delimiter();
  Dash();
  Part_Delimiter();
  Dot();
  
  Letter_Delimiter();
  
  return 0;
}


