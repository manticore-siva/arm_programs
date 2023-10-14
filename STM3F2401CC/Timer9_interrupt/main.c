////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - Timer 9 interrupt                                       //
//   Date  : 14/10/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"
void rcc_config(void);
void timer9_config(void);
void port_config(void);
void timer9_interrupt(void);

int main()
{
    // RCC configuration
	rcc_config();

    // Timer9 Configuration
	timer9_config();

    // Port configuration
	port_config();

    while(1)
    {

    }
	while(1);
}

void rcc_config()
{
        // HSI ON
        RCC->CR |= 1;

		// HSI ready flag
		while(!(RCC->CR & 1<<1));

		//port C clock enable
        RCC->AHB1ENR |= 1<<2;

		// TIM9 clock enable
		RCC->APB2ENR |= 1<<16;
}

void port_config(void)
{
	// set as  General purpose output mode, pin C13
	GPIOC->MODER = 1<<26;

    // Output push-pull (reset state)
	GPIOC->OTYPER &= ~(1<<12);

	// Medium speed
	GPIOC->OSPEEDR |= 1<<27;
}

void timer9_config(void)
{

    //  UEV disabled
    TIM9->CR1 |= 1<<1;

    // Only counter overflow generates an update interrupt if enabled.
    TIM9->CR1 |= 1<<2;

    //  Auto-reload preload enable
    TIM9->CR1 |= 1<<7;

    // clear UIF status
    TIM9->SR &= ~(1<<0);

    // 10ms delay values to PSC and ARR registers
 
    // Load Psc value 
    TIM9->PSC = 1600;

    // TIM9 auto-reload register value
    TIM9->ARR = 100;

    // Update interrupt enable
    TIM9->DIER |= (1<<0);

    // Enable Timer9 interrupt by use NVIC table
    timer9_interrupt();
}

void TIM1_BRK_TIM9_IRQHandler(void)
{

      TIM9->SR &= ~(1<<0);  // Clear UIF update interrupt flag
   
    if(GPIOC->ODR & 1<<13)
    {
		GPIOC->ODR &= ~1<<13;   //Led off
    }

    else
    {
		GPIOC->ODR |= 1<<13;   //Led on
    }
}

void timer9_interrupt(void)
{
    //Timer 9 interrupt enable
	NVIC_ENABLE_INTERRUPT(24);

    // Counter enabled
    TIM9->CR1 |= (1<<0);
    
    // UEV enable
    TIM9->CR1 &= ~(1<<1);
}
