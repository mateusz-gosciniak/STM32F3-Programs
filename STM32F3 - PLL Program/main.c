// Lib

#include "stm32f303xc.h"
#include "stm32f3xx.h"

// Preprocesor

#define TRUE 1
#define FALSE 0

// fun

void set_register(volatile uint32_t *reg, uint32_t value)
{
	*reg |= value;
}

void unset_register(volatile uint32_t *reg, uint32_t value)
{
	*reg &= ~value;
}

// Main Loop

int main()
{
	/// >>>>>>>>>>>>>>>>>> PLL <<<<<<<<<<<<<<<<<<<
	//0. HSI turn on
	set_register(&RCC->CR, RCC_CR_HSION);
	//To modify the PLL configuration, proceed as follows:
	//1. Disable the PLL by setting PLLON to 0.
	unset_register(&RCC->CR, RCC_CR_PLLON);
	//2. Wait until PLLRDY is cleared. The PLL is now fully stopped.
	while((RCC->CR & RCC_CR_PLLRDY) != 0) {}
	//3. Change the desired parameter.
	//	HSI is 8Mhz
	//	HSI must be div by 2
	set_register(&RCC->CFGR, RCC_CFGR_PLLSRC_HSI_DIV2);
	//	PLL Source MUX
	unset_register(&RCC->CFGR, RCC_CFGR_PLLSRC);	
	//  PLL_MUL
	set_register(&RCC->CFGR, RCC_CFGR_PLLMUL12);
	//4. Enable the PLL again by setting PLLON to 1.
	set_register(&RCC->CR, RCC_CR_PLLON);	
	//  Wait until PLLRDY is set.
	while( (RCC->CR &  RCC_CR_PLLRDY) == 0) {}		
	//	System Clock MUX
	set_register(&RCC->CFGR, RCC_CFGR_SW_PLL);
	/// >>>>>>>>>>>>>>>>>> PLL <<<<<<<<<<<<<<<<<<<
		
	/// >>>>>>>>>>>>>>>>>> TIMER <<<<<<<<<<<<<<<<<<<
		//30/27
	/// >>>>>>>>>>>>>>>>>> TIMER <<<<<<<<<<<<<<<<<<<
	
	/// >>>>>>>>>>>>>>>>>> GPIO <<<<<<<<<<<<<<<<<<<
	set_register(&RCC->AHBENR, RCC_AHBENR_GPIOEEN);
	//
	set_register(&GPIOE->MODER, GPIO_MODER_MODER15_0); 
	set_register(&GPIOE->MODER, GPIO_MODER_MODER14_1);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER13_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER12_1);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER11_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER10_1);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER9_0);
	set_register(&GPIOE->MODER, GPIO_MODER_MODER8_1);
	/// >>>>>>>>>>>>>>>>>> GPIO <<<<<<<<<<<<<<<<<<<
		
	set_register(&GPIOE->ODR, GPIO_ODR_15);
	set_register(&GPIOE->ODR, GPIO_ODR_13);
	set_register(&GPIOE->ODR, GPIO_ODR_11);
	set_register(&GPIOE->ODR, GPIO_ODR_9);	
	
	while(TRUE)
	{
		set_register(&GPIOE->ODR, GPIO_ODR_14);
		set_register(&GPIOE->ODR, GPIO_ODR_12);
		set_register(&GPIOE->ODR, GPIO_ODR_10);
		set_register(&GPIOE->ODR, GPIO_ODR_8);
	}
	
	return 0;
}
