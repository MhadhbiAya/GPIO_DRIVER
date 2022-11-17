#include "gpio.h"

void GPIO_CLOCK_Enable(uint32_t *GPIOx)
{
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
  
    if(GPIOx == GPIOA)
    {
      *RCCAHB1 |=(1<<0);
    }
    else if (GPIOx == GPIOB) 
    {
      *RCCAHB1 |=(1<<1);
    }
    else if (GPIOx == GPIOC)
    {
       *RCCAHB1 |=(1<<2);
    }
    else if (GPIOx == GPIOD)
    {
        *RCCAHB1 |=(1<<3);
    }
}
void GPIO_Config(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode, uint8_t Type)
{
  assert (Pin == PIN1 || Pin == PIN2 || Pin == PIN3 || Pin == PIN4 || Pin == PIN5 || Pin == PIN6 || Pin == PIN7 || Pin == PIN8 || Pin == PIN9 || Pin == PIN10 || Pin == PIN11 || Pin == PIN12 || Pin == PIN13 || Pin == PIN14 || Pin == PIN15);
  assert (Mode == INPUT || Mode == OUTPUT || Mode == ALTERNATE  || Mode == ANALOG_INPUT );
  assert (Type == OUTPUT_OPEN_DRAIN || Type == OUTPUT_PUSH_PULL);
  uint16_t *RCC_MODER  = (uint16_t *)(0x40020c00);
  uint16_t *RCC_OTYPER = (uint16_t *)(0x40020c04);
    if (Pin == PIN12)
    { if (Mode == OUTPUT)
    {    
              *RCC_MODER |=(1<<24);
      
           if (Type == OUTPUT_PUSH_PULL)
    {
              *RCC_OTYPER |=(1<<12);
    } 
           else if (Type == OUTPUT_OPEN_DRAIN)
    {
              *RCC_OTYPER |=(0<<12);
    } 
    }
    else if (Mode == INPUT)
    {    
              *RCC_MODER |=(0<<12);
      
           if (Type == OUTPUT_PUSH_PULL)
    {
              *RCC_OTYPER |=(1<<12);
    } 
           else if (Type == OUTPUT_OPEN_DRAIN)
    {
              *RCC_OTYPER |=(0<<12);
    } 
    }
    else if (Mode == ALTERNATE)
    {    
              *RCC_MODER |=(2<<12);
      
           if (Type == OUTPUT_PUSH_PULL)
    {
              *RCC_OTYPER |=(1<<12);
    } 
           else if (Type == OUTPUT_OPEN_DRAIN)
    {
              *RCC_OTYPER |=(0<<12);
    } 
    }
     else if (Mode == ANALOG_INPUT)
    {    
              *RCC_MODER |=(3<<12);
      
           if (Type == OUTPUT_PUSH_PULL)
    {
              *RCC_OTYPER |=(1<<12);
    } 
           else if (Type == OUTPUT_OPEN_DRAIN)
    {
              *RCC_OTYPER |=(0<<12);
    } 
    }
    }
}