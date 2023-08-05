////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - Stepper Motor                                           //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"

void rcc_config(void);
void port_config(void);
void tim10_delay(unsigned int d_time);

int main()
{
	rcc_config();
	port_config();
	int arr[]={0x07,0x03,0x0B,0X09,0X0D,0X0C,0X0E,0X06};
	int arr1[]={0x1,0x3,0x2,0X6,0X4,0Xc,0X8,0X9};
while(1)
{	
	for(int i=0;i<50;i++)
	{	
		for(int j=0;j<8;j++)
		{
			GPIOB->ODR = arr[j];
		//	GPIOB->ODR = arr1[j];
			tim10_delay(25);
		}
	} 

}
}

void rcc_config()
{
		// HSE ON
		RCC->CR |= 16<<1;

		// HSI ready flag
		while(!(RCC->CR & 17<<1));

		// HSE oscillator selected as system clock
		RCC->CFGR |= 1;

		// peripheral PORT A clock enable 
		RCC->AHB1ENR |= 2;

		//RCC_APB2ENR TIMER 10 enable
		RCC->APB2ENR |=  1<<17;

 }

void port_config(void)
{
	// General purpose output mode POART B  PB0,PB1,PB2,PB3
	GPIOB->MODER &= ~(0xFF<<0);
	GPIOB->MODER |= 0X55;

	// GPIOA HIGH OSPEEDR
	GPIOB->OSPEEDR |= 0XAA;

	// PB8 and PB9 Pull-up
//	GPIOB->PUPDR &= ~(0xF<<16);
	GPIOB->PUPDR |= 0x55<<0;   // pull up
}


void tim10_delay(unsigned int d_time)
{
	//Enable Update disable
	TIM10->CR1 |= (1<<1);

	//clear UIF status
	TIM10->SR &= ~(1<<0);

	//Set count value
	TIM10->CNT = 0;

	//Set prescaler value
	TIM10->PSC = 1000;

	//Auto-reload preload enable
	TIM10->CR1 |= (1<<2);

	//Set reload value
	TIM10->ARR = d_time;    // 100 ms

	//Update disable OFF
	TIM10->CR1 &= ~(1<<1);

	//Update request source
	TIM10->CR1 |=  (1<<7);


	//Counter enable
	TIM10->CR1 |= 1;

	// condition

	while((TIM10->SR & 1)==0);
}

