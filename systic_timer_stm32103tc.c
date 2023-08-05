////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - Systic timer STM32F103C8   1 Sec delay                  //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"

#define LED_ON (~(1<<13))
#define LED_OFF 1<<13

void clock_config(void);
void port_config(void);
void systic_delay(void);

int main()
{
	clock_config();
	port_config();
	
	while(1)
	{
		//LED O	FF
		GPIOC->ODR &= ~(1<<13);
		//DELAY
	 systic_delay();

		//LED ON
		GPIOC->ODR |= 1<<13;
		//DELAY
	 systic_delay();
		
	}  
}

void clock_config(void)
{
	// HSE on	
	RCC->CR = RCC->CR | 1<<16;

	// waiting for HSE ready flag
	while(!(RCC->CR & 1<<17));

	// RCC clock configuration register
	RCC->CFGR = RCC->CFGR | 1;

	//  System clock switch status
	while(!(RCC->CFGR & 1<<2));

	//RCC_CLOCK enable,GPIOCEN: IO port C clock enable
	RCC->APB2ENR = 1<<4;	
}

void port_config(void)
{
	// C13 pin set as output mode
	GPIOC->CRH &= ~(0xF<<20); //clear bits
	GPIOC->CRH |= 0x1<<20;    // Mode : 00: General purpose output push-pull, MODE : 10: Input with pull-up / pull-down
}

void systic_delay(void)
{
	// loaad delay value   8MHz one cycle time 125ns, 8000000 = 1 sec
	STK->LOAD = 8000000;   //1sec delay

	//Counter enable,source clock selection,enable intrrupt  
	STK->CTRL = 0x5;

	//waiting for count complete 
	while(!(STK->CTRL & (1<<16)));
}
