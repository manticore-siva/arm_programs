////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - Timer 10                                                //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"

void delay(void);
int main()
{

	// clock selection
	RCC_CR |= 1<<16; //HSE ON

	while(!(RCC_CR & 1<<17));
	RCC_CFGR &= ~0x3; //HSE oscillator selected as system clock
	RCC_CFGR |= 1; //HSE oscillator selected as system clock

	while(!(RCC_CFGR & 0x1<<2)); //waiting for 01: HSE oscillator used as the system clock

	//Port A clock Selection
	RCC_AHB1ENR |= 1;
	
	//timer10 selection
	RCC_APB2ENR |= 1<<17;
	// port set as out put mode
	GPIOA_MODER &= ~0x3<<10;
	GPIOA_MODER |= 1<<10;
	while(1)
	{
		GPIOA_ODR |= 1<<5;
		delay();

		GPIOA_ODR &= ~1<<5;
		delay();
	}
}
void delay(void)
{
	//Enable Update disable
	TIM10_CR1 = TIM10_CR1 | (1<<1);

	//clear UIF status
	TIM10_SR = TIM10_SR * ~(1<<0);

	//Set count value
	TIM10_CNT = 0;  

	//Set prescaler value
	TIM10_PSC = 250;            

	//Set reload value
	TIM10_ARR = 100;

	//Update disable OFF
	TIM10_CR1 = TIM10_CR1 & ~(1<<1); 

	//Update request source
	TIM10_CR1 = TIM10_CR1 | (1<<7);

	//Auto-reload preload enable
	TIM10_CR1 = TIM10_CR1 | (1<<2);

	//Counter enable
	TIM10_CR1 = TIM10_CR1 | 1;

	// condition
	  
	while((TIM10_SR & 1)==0);
}
