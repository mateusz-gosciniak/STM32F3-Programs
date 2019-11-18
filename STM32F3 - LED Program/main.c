#include "stm32f303xc.h"
#include "stm32f3xx.h"

#define TRUE 1
#define FALSE 0

void set_register(volatile uint32_t *reg, uint32_t value)
{
	*reg |= value;
}

void unset_register(volatile uint32_t *reg, uint32_t value)
{
	*reg &= ~value;
}

int main()
{
	set_register(&RCC->AHBENR, RCC_AHBENR_GPIOEEN);
	
	set_register(&GPIOE->MODER, GPIO_MODER_MODER15_0); 
	set_register(&GPIOE->MODER, GPIO_MODER_MODER14_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER13_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER12_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER11_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER10_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER9_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER8_0);
	
	set_register(&GPIOE->ODR, GPIO_ODR_15);
	set_register(&GPIOE->ODR, GPIO_ODR_14);
	set_register(&GPIOE->ODR, GPIO_ODR_13);
	set_register(&GPIOE->ODR, GPIO_ODR_12);
	set_register(&GPIOE->ODR, GPIO_ODR_11);
	set_register(&GPIOE->ODR, GPIO_ODR_10);
	set_register(&GPIOE->ODR, GPIO_ODR_9);
	set_register(&GPIOE->ODR, GPIO_ODR_8);
	
	while(TRUE)
	{

	}
	
	return 0;
}
