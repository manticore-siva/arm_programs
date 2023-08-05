////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - Timer 2                                                 //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"

void rcc_config(void);
void timer2_config(void);
void port_config(void);

int main()
{
	rcc_config();
	port_config();
	timer2_config();
	while(1);
}

void rcc_config()
{
		// HSI ON
		RCC->CR |= 1;

		// HSI ready flag
		while(!(RCC->CR & 2));

		//port A and B clock enable
		RCC->AHB1ENR |= 3;

		// TIM2 clock enable
		RCC->APB1ENR |= 1;
}

void port_config(void)
{
	// PA0 Alternate function mode
	GPIOA->MODER &= ~(0x3);
	GPIOA->MODER |= 2;

	// PA5 Alternate function mode
	GPIOA->MODER &= ~(0x3<<10);
	GPIOA->MODER |= 1<<11;

	// PA15 Alternate function mode
	GPIOA->MODER &= ~(0x3<<30);
	GPIOA->MODER |= 1<<31;

	// PB10 Alternate function mode
	GPIOB->MODER &= ~(0x3<<20);
	GPIOB->MODER |= 1<<21;


	// PA0 High speed
	GPIOA->OSPEEDR &= ~(0x3);
	GPIOA->OSPEEDR |= 2;

	// PA5 High speed
	GPIOA->OSPEEDR &= ~(0x3<<10);
	GPIOA->OSPEEDR |= 1<<11;

	// PA15 High speed
	GPIOA->OSPEEDR &= ~(0x3<<30);
	GPIOA->OSPEEDR |= 1<<31;

	// PB10 High speed
	GPIOB->OSPEEDR &= ~(0x3<<20);
	GPIOB->OSPEEDR |= 1<<21;


	// PA0 Pull-down
	GPIOA->PUPDR &= ~(0x3);
	GPIOA->PUPDR |= 2;

	// PA5 Pull-down
	GPIOA->PUPDR &= ~(0x3<<10);
	GPIOA->PUPDR |= 1<<11;

	// PA15 Pull-down
	GPIOA->PUPDR &= ~(0x3<<30);
	GPIOA->PUPDR |= 1<<31;

	// PB10 Pull-down
	GPIOB->PUPDR &= ~(0x3<<20);
	GPIOB->PUPDR |= 1<<21;
	
	//GPIO alternate function high register
	GPIOA->AFRL &= ~(0xF);	// clear register
	GPIOA->AFRL |= 1;	    

	GPIOA->AFRL &= ~(0xF<<20);	// clear register
	GPIOA->AFRL |= 1<<20;	   

	GPIOA->AFRH &= ~(0xF<<28);	// clear register
	GPIOA->AFRH |= 1<<28;	    

	GPIOB->AFRH &= ~(0xF<<8);	// clear register
	GPIOB->AFRH |= 1<<8;	    
}

void timer2_config(void)
{
	// clock selection slave mode off
	TIM2->SMCR &= ~7;

	//  CC1E:0: Off - OC1 is not active
	TIM2->CCER &= ~1;
	TIM2->CCER &= ~(1<<4);
	TIM2->CCER &= ~(1<<8);
	TIM2->CCER &= ~(1<<12);

	// OC1PE:0 Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the new value is taken in account immediately. 
	TIM2->CCMR1 &= ~(1<<3);
	TIM2->CCMR1 &= ~(1<<11);
	TIM2->CCMR2 &= ~(1<<3);
	TIM2->CCMR2 &= ~(1<<11);

	// CC1S:00 channel is configured as output
	TIM2->CCMR1 &= ~3;
	TIM2->CCMR1 &= ~(3<<8);
	TIM2->CCMR2 &= ~3;
	TIM2->CCMR2 &= ~(3<<8);

	// OC1M: 110: PWM mode 1 - Channel 1 is active as long as TIMx_CNT < TIMx_CCR1 else inactive
	TIM2->CCMR1 |= 0x60;
	TIM2->CCMR1 |= 0x6<<12;
	TIM2->CCMR2 |= 0x60;
	TIM2->CCMR2 |= 0x6<<12;

	// OC1FE: Output compare 1 fast enable
	TIM2->CCMR1 |= 4;
	TIM2->CCMR1 |= 1<<10;
	TIM2->CCMR2 |= 4;
	TIM2->CCMR2 |= 1<<10;

	// CCR1[15:0]: Capture/Compare value = 8
	TIM2->CCR1 &= ~0xffff;  // clear the register
	TIM2->CCR1 |= 12;        // assign the ccr1 value

	TIM2->CCR2 &= ~0xffff;  // clear the register
	TIM2->CCR2 |= 12;        // assign the ccr1 value


	TIM2->CCR3 &= ~0xffff;  // clear the register
	TIM2->CCR3 |= 12;        // assign the ccr1 value


	TIM2->CCR4 &= ~0xffff;  // clear the register
	TIM2->CCR4 |= 12;        // assign the ccr1 value

	// ARPE: Auto-reload preload enable
	TIM2->CR1 |= 1<<7;

	// ARR[15:0]: Auto-reload value = 30
	TIM2->ARR  = 320;       // assign arr value


	// PSC[15:0]: Prescaler value = 0
	TIM2->PSC = 1000;        // assign pse value

	// CNT[15:0]: Counter value = 0
	TIM2->CNT = 0;

	// CC1P: Capture/Compare 1 output Polarity = 0: OC1 active high

	// CC1NP: Capture/Compare 1 complementary output Polarity = 0:CC1 channel configured as output: CC1NP must be kept cleared.

	// CC1E: Capture/Compare 1 output enable.
	TIM2->CCER |= 0x1111;

	// OC1PE: Output compare 1 fast enable
	TIM2->CCMR1 |= 1<<3 | 1<<11;
	TIM2->CCMR2 |= 1<<3 | 1<<11;
	
	// UG: Update generation 1
	TIM2->EGR |= 0x1F;

	// CEN: Counter enable
	TIM2->CR1 |= 1;

	
}
