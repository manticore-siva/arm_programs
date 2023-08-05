#include "arm_config.h"

void rcc_config(void);
void i2c_config(void);
void port_config(void);
void i2c_tx(void);
void usart_config(void);
void usart_data(unsigned int u_data);
void data_tx(unsigned char data);
void tim10_delay(void);

int main()
{
	rcc_config();
    usart_config();
	i2c_config();
	port_config();
	i2c_tx();
	while(1);
}

void rcc_config()
{
		// HSI ON
		RCC->CR |= 1;

		// HSI ready flag
		while(!(RCC->CR & 2));

		// A and B clock enable
		RCC->AHB1ENR |= 3;

		//USART1 clock enable
		RCC->APB2ENR |=0x10;

		// I2c1 clock enable
		RCC->APB1ENR |= 1<<21;

		//USART1 clock enable
		RCC->APB2ENR |=0x10;

		//RCC_APB2ENR TIMER 10 enable
		RCC->APB2ENR |=  1<<17;
}

void port_config(void)
{
	// PB8 and PB9 Alternate function mode
	GPIOB->MODER &= ~(0xF<<16);
	GPIOB->MODER |= 0xA<<16;

	//10: Alternate function mode PIN A9 TX
	GPIOA->MODER &= ~(3<<18);
	GPIOA->MODER |= 1<<19;

	// PB8 and PB9 High speed
	GPIOB->OSPEEDR &= ~(0xF<<16);
	GPIOB->OSPEEDR |= 0xA<<16;

	//GPIO port output speed register
	GPIOA->OSPEEDR &= ~(3<<18);
	GPIOA->OSPEEDR |= 1<<19;   // set as 10: High speed

	// PB8 and PB9 Pull-up
	GPIOB->PUPDR &= ~(0xF<<16);
	GPIOB->PUPDR |= 0x5<<16;

	GPIOB->OTYPER |=3<<8; //Output open-drain

	//GPIO alternate function high register
	GPIOB->AFRH &= ~(0xFF<<0);	// clear register
	GPIOB->AFRH |= 0x44;

	// 0111: AF7 GPIO alternate function high register
	GPIOA->AFRH |= 0x70;

}

void i2c_config(void)
{

		//Reset I2c
		I2C1->CR1 |= 1<<15;
		I2C1->CR1 &= ~(1<<15);

		// FREQ[5:0]: Peripheral clock frequency
		I2C1->CR2 |= 16<<0; // 16MHz

		//
		I2C1->CCR = 0x50;

		//Trise value
		I2C1->TRISE = 17;

		I2C1->FLTR |= 15<<0;

//		I2C1->CR1 |= (1<<10);  // Enable the ACK

		// Enable PE
		I2C1->CR1 |= 1;

		tim10_delay();
//		I2C1->CR1 |= (1<<8);
}

void i2c_tx(void)
{
	volatile int temp;
	unsigned char *data;

	// waiting for No communication on the bus

	while(I2C1->SR2 & 1<<1);

	// 	Enable start condition
	I2C1->CR1 |= (1<<8);

	// Waiting for Start condition generated
	while (!(I2C1->SR1 & (1<<0)));

	// Send slave address + write
	I2C1->DR = (0x68<<1);

	// waiting for ADDR bit set
	while (!(I2C1->SR1 & (1<<1)));

	// Clear status register
	temp = I2C1->SR1 | I2C1->SR2;

	// waiting for DR register empty
	while(!(I2C1->SR1 & 1<<7));

	// Send memory address
	I2C1->DR = 0x75;

	// waiting DR register empty
	while(!(I2C1->SR1 & 1<<7));

	// Genrate Restart condition
	I2C1->CR1 |= (1<<8);

	// Waiting for Start condition generated
	while (!(I2C1->SR1 & (1<<0)));

	// Transmit slave address + read
	I2C1->DR = (0x68<<1 | 1<<0);

	// waiting for ADDR bit set
	while (!(I2C1->SR1 & (1<<1)));

	// Disable ACK
//	I2C1->CR1 &= ~(1<<10);

	// Clear flag
	temp = I2C1->SR1 | I2C1->SR2;

	// wait for RXNE flag set
	while(!(I2C1->SR1 & 1<<6));

	// Genrate Stop bit
	I2C1->CR1 |= 1<<9; //stop

	//Read the data from DR register
	*data = I2C1->DR;
	temp  = I2C1->DR;

	usart_data(temp);
}

void tim10_delay(void)
{
	//Enable Update disable
	TIM10->CR1 |= (1<<1);

	//clear UIF status
	TIM10->SR &= ~(1<<0);

	//Set count value
	TIM10->CNT = 0;

	//Set prescaler value
//	TIM10->PSC = 800;
	TIM10->PSC = 16000;

	//Auto-reload preload enable
	TIM10->CR1 |= (1<<2);

	//Set reload value
	TIM10->ARR = 1000;

	//Update disable OFF
	TIM10->CR1 &= ~(1<<1);

	//Update request source
	TIM10->CR1 |=  (1<<7);


	//Counter enable
	TIM10->CR1 |= 1;

	// condition

	while((TIM10->SR & 1)==0);
}

void usart_config(void)
{
	//Enable UE bit,M: Word length
	USART1->CR1 &= ~(3<<12);
	USART1->CR1 |= 1<<13;

	//number of stop bit
	USART1->CR2 &= ~(3<<12);
	USART1->CR2 |= (1<<13);


	//select baud rate
	USART1->BRR |= 0x3;  // fraction value = 3
	USART1->BRR |= 104<<4; // mantissa value = 104


	//enable TE bit
	USART1->CR1 |= 0x8;

	//cheak sattus
	while(!(USART1->SR & (1<<7)));
//	USART_SR &= ~(1<<6); //clear TC bit

}

void data_tx(unsigned char data)
{

	//Data register
	USART1->DR = data;   // character a

	//cheak sattus
	while(!(USART1->SR & (1<<6)));
	USART1->SR &= ~(1<<6); //clear TC bit
}

void usart_data(unsigned int u_data)
{
	int i=6;

/*	while(*u_data)
	{
		data_tx(*u_data);
		u_data++;
	}*/

	while(i>=1)
	{
		if(u_data & 1<<i)
		{
			data_tx('1');
		}
		else
			data_tx('0');
		i--;
	}
			data_tx('\n');
			data_tx('\r');
}

