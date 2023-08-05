////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - Two node Spi receiver transmitter                       //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"
#include "mcp_2515_command.h"
#include <stdio.h>

void rcc_config(void);
void port_config(void);
void spi_init(void);
void spi_tx(unsigned char addr);
unsigned char spi_read(void);
void tim10_delay(unsigned int d_time);
void usart_config(void);
void usart_data(unsigned char data);
void data_tx(unsigned char data);
void mcp2515_write(unsigned char address,unsigned char data);
void mcp2515_data(unsigned char data);
unsigned char mcp2515_read(unsigned char address);

unsigned char spi_data;
int main()
{
	unsigned char data;
	rcc_config();
	usart_config();
	port_config();
	spi_init();
	tim10_delay(2500);

	while(1)
	{
	mcp2515_read(CANSTAT);  // to verify configuration mode or not

	// Reset mcp2515 controller,default configuration mode
	mcp2515_data(RESET);

	tim10_delay(2500);

	// 1. Read and check CANSTATUS register
	mcp2515_read(CANSTAT);  // to verify configuration mode or not

	// 2.Load CNF1 (SJW value & BRP value)
	mcp2515_write(CNF1,0x43);     // BRP = 3,SJW = 2;

	// 3.Load CNF2 value
	mcp2515_write(CNF2,0x5B); // sampled three times,PS1 Length bits = 3, Propagation Segment Length bits=3

	// 4.Load CNF3 value 
	mcp2515_write(CNF3,0x81); //  PS2 Length bits = 2, CLKOUT pin is enabled for SOF signal;

	// 5.Load TXRTSCTRL
	mcp2515_write(TXRTSCTRL,0x3); // Pin is used to request message transmission of TXB0 and TXB1 buffer

	//6.Load filter values
	mcp2515_write(RXF0SIDH,0x00); //FILTER 0 STANDARD IDENTIFIER HIGH
	mcp2515_write(RXF0SIDL,0x20); //FILTER 0 STANDARD IDENTIFIER LOW

	mcp2515_write(RXF1SIDH,0x08); //FILTER 1 STANDARD IDENTIFIER HIGH
	mcp2515_write(RXF1SIDL,0x20); //FILTER 1 STANDARD IDENTIFIER LOW

	// Load mask values
	//MASK 0 STANDARD IDENTIFIER HIGH
	mcp2515_write(RXM0SIDL,0x43);
	mcp2515_write(RXM0SIDH,0x10);


	// set Highest Message Priority
	mcp2515_write(TXB0CTRL,0x3);
	mcp2515_read(TXB0CTRL);

	// TX0RTS Pin mode bit,Pin is used to request message transmission of TXB0 buffer (on falling edge)
	mcp2515_write(TXRTSCTRL,1);

	// TRANSMIT BUFFER 0 STANDARD IDENTIFIER LOW
	mcp2515_write(TXB0SIDL,0x80);  // Standard Identifier 8 bits, Message will transmit standard identifier

	//  TRANSMIT BUFFER 0 STANDARD IDENTIFIER HIGH
	mcp2515_write(TXB0SIDH,0x33);  // buffer 0 standard id 

	//Sets the number of data bytes to be transmitted 1 byte
	mcp2515_write(TXB0DLC,0x1); 

	// Load TXbuffer values
	mcp2515_write(TXB0Dm,0x30);

	// Request-to-send for TXBO
	mcp2515_data(RTS_TXB0);

	// switch to normale mode 
	mcp2515_write(CANCTRL,0x00);
	tim10_delay(2500);

	while(TXB0CTRL & (1<<4));  //  waitng for message transmision completed

	mcp2515_write(TXB0CTRL,0x00);
	mcp2515_read(TXB0CTRL);
	}
	while(1);
}

void rcc_config()
{
		// HSE ON
		RCC->CR |= 1<<16;

		// HSE ready flag
		while(!(RCC->CR & 1<<17));

		// HSE oscillator selected as system clock
		RCC->CFGR |= 1;

		// peripheral PORT A clock enable 
		RCC->AHB1ENR |= 3;

		//RCC_APB2ENR TIMER 10 enable
		// SPI1 clock enabled
		//USART1 clock enable
		RCC->APB2ENR |=  1<<12 | 1<<17 | 1<<4;

 }

void port_config(void)
{

		// Alternate function mode PA5,PA6,PA7, PA4 GPIO output pin
		GPIOA->MODER &= ~(0xFF<<8);
		GPIOA->MODER |= 0XA9<<8;

		// Output push-pull
		GPIOA->OTYPER &= ~(0xF<<4);

		// GPIOA HIGH OSPEEDR
		GPIOA->OSPEEDR |= 0XAA<<8;
	
		// Alternate function selection AF5
		GPIOA->AFRL = 0x5550<<16;

		//10: Alternate function mode UART PIN A9 TX
		GPIOA->MODER &= ~(3<<18);
		GPIOA->MODER |= 1<<19;

		//GPIO port output speed register
		GPIOA->OSPEEDR &= ~(3<<18);
		GPIOA->OSPEEDR |= 1<<19;   // set as 10: High speed

		// 0111: AF7 GPIO alternate function high register
		GPIOA->AFRH |= 0x70;

		GPIOA->ODR |= 1<<4; // slave selection high

		GPIOB->MODER &= ~(3);
		GPIOB->MODER |= 1;

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

void spi_init(void)
{

		// enable spi mode
		SPI1->I2SCFGR &= ~(1<<11);

		// Master selection
		SPI1->CR1 |= 1<<2;

		// CPOL: Clock polarity and CPHA: Clock phase 00 mode transaction 
		SPI1->CR1 &= ~(0x3);

		// Data frame format
		SPI1->CR1 &= ~(1<<11);

		// 0: MSB transmitted first
		SPI1->CR1 &= ~(1<<7);

		// Select the BR[2:0] bits  011: fPCLK/16
		SPI1->CR1 &= ~(0x7<<3);
		SPI1->CR1 |= 0x3<<3;

		// 0: SPI Motorola mode
		SPI1->CR2 &= ~(1<<4);

		// SSM: Software slave management
		SPI1->CR1 &= ~(1<<9);

		// SSOE: 1 SS output enable
		SPI1->CR2 |= 1<<2;

		// SPI enable 
		SPI1->CR1 |= 1<<6;

}

void spi_tx(unsigned char addr)
{

		volatile unsigned int temp;
		// Transmit buffer empty
		while(!((SPI1->SR) & (1<<1)));

		//transmit data
		SPI1->DR = addr;

		// Transmit buffer empty
		while(!((SPI1->SR) & (1<<1)));
		
		while (((SPI1->SR)&(1<<7)));  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication

	//  Clear the Overrun flag by reading DR and SR
	    temp = SPI1->DR;
	    temp = SPI1->SR;
}

unsigned char spi_read(void)
{
	unsigned char data,temp;

	while (((SPI1->SR)&(1<<7)));
	SPI1->DR = 0x1;					 // send dummy data 
	while (!((SPI1->SR) &(1<<0)));
	data = (SPI1->DR);
	return(data);
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
	USART1->BRR |= 12;  // fraction value = 3
	USART1->BRR |= 162<<4; // mantissa value = 104


	//enable TE bit
	USART1->CR1 |= 0x8;

	//cheak sattus
	while(!(USART1->SR & (1<<7)));
//	USART_SR &= ~(1<<6); //clear TC bit

}

void data_tx(unsigned char data)
{

	//Data register
	USART1->DR =data;   // character a

	//cheak sattus
	while(!(USART1->SR & (1<<6)));
	USART1->SR &= ~(1<<6); //clear TC bit

}

void usart_data(unsigned char data)
{
	char buffer[20];
	char *bufferp = buffer;

	// int snprintf(char *str, size_t size, const char *format, ...);
	snprintf(buffer,19,"0x%x\n\r",data);

	buffer[19] = 0;

	while(*bufferp)
	{
		data_tx(*bufferp);
		bufferp++;
	}
}

void mcp2515_write(unsigned char address,unsigned char data)
{

	GPIOA->ODR &= ~(1<<4);    // slave selection low
	spi_tx(WRITE);            // write instruction
	spi_tx(address);          // address
	spi_tx(data);
	GPIOA->ODR |= 1<<4;       // slave selection high
}

void mcp2515_data(unsigned char data)
{
	GPIOA->ODR &= ~(1<<4);    // slave selection low
//	spi_tx(WRITE);
	spi_tx(data);
	GPIOA->ODR |= 1<<4;      // slave selection high
	
}

unsigned char mcp2515_read(unsigned char address)
{

	GPIOA->ODR &= ~(1<<4);    // slave selection low
	spi_tx(READ);             // read instruction
	spi_tx(address);          // which address to read 
	spi_data = spi_read();
	GPIOA->ODR |= 1<<4;      // slave selection high
	usart_data(spi_data);
	return(spi_data);
}

