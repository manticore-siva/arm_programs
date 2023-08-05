////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - Timer 1 advance  control                                //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////


#include "arm_config.h"

void rcc_config(void);
void timer1_config(void);
void port_config(void);

int main()
{
	rcc_config();
	timer1_config();
	port_config();
}

void rcc_config()
{
		//port A clock enable
		RCC->AHB1ENR |= 1;

		// TIM1 clock enable
		RCC->APB2ENR |= 1;
}

void port_config(void)
{
	// clear register
	GPIOA->MODER &= ~(0xFF << 16);
	// set as alternative function in PA8,PA9,PA10,PA11
	GPIOA->MODER |= 0xAA <<16;

	//clear register
	GPIOA->OSPEEDR &= ~(0xFF << 16);
	// set as very high speed in PA8,PA9,PA10,PA11
	GPIOA->OSPEEDR |= 0xFF <<16;

	//GPIO alternate function high register
	GPIOA->AFRH &= ~(0xFFFF);	// clear register
	GPIOA->AFRH |= 0x1111;	    // 0001: AF1

}

void timer1_config(void)
{
	// Auto-reload preload enable
	TIM1->CR1 |= 1<<7;



}
