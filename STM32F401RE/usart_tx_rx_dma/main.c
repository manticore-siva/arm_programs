////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - UART tx rx by use DMA                                   //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"

void rcc_config(void);
void port_config(void);
void usart_config(void);
void data_tx(unsigned char data);
void usar_data(unsigned char *u_data);
void dma_config(void);
void dma_data_tx(void);
unsigned char usart_rx(void);
int main()
{
//	unsigned char data;

	rcc_config();
    usart_config();
	dma_config();
	port_config();
    usart_rx();
    dma_data_tx();

	while(1);

}

void rcc_config(void)
{
	//DMA2 clock enable
	RCC->AHB1ENR |= 1<<22;

	//USART1 clock enable
	RCC->APB2ENR |= 0x10;

	//GPIOAEN: IO port A clock enable
	RCC->AHB1ENR |= 0x1; 
}
void port_config(void)
{
	//10: Alternate function mode PIN A9 TX 
	GPIOA_MODER &= ~(3<<18);
	GPIOA_MODER |= 1<<19;

	//10: Alternate function mode PIN A10 TX 
	GPIOA_MODER &= ~(3<<20);
	GPIOA_MODER |= 1<<21;

	//GPIO port output speed register
	GPIOA_OSPEEDR &= ~(3<<18);
	GPIOA_OSPEEDR |= 1<<19;   // set as 10: High speed

	//GPIO port output speed register
	GPIOA_OSPEEDR &= ~(3<<20);
	GPIOA_OSPEEDR |= 1<<21;   // set as 10: High speed

	// 0111: AF7 GPIO alternate function high register 
	GPIOA_AFRH |= 0x70;

	GPIOA_AFRH |= 0x700;
	
	
}
void usart_config(void)
{
	//Enable UE bit,M: Word length
	USART_CR1 &= ~(3<<12);
	USART_CR1 |= 1<<13;

	//number of stop bit 
	USART_CR2 &= ~(3<<12);
	USART_CR2 |= (1<<13);


	//select baud rate
	USART_BRR |= 11;     // fraction value = 11
	USART_BRR |= 8<<4;  // mantissa value = 8

	//DMA enable transmitter
	USART_CR3 |= 1<<7;

	//DMA enable reciver
	USART_CR3 |= 1<<6;

	//enable TE bit 
	USART_CR1 |= 0x8;

	//enable RX bit 
	USART_CR1 |= 4;

	//cheak sattus 			
	while(!(USART_SR & (1<<7)));

}
void data_tx(unsigned char data)
{

	//Data register
	USART_DR =data;   // character a

	//cheak sattus 			
	while(!(USART_SR & (1<<6)));
	USART_SR &= ~(1<<6); //clear TC bit

}
void usar_data(unsigned char *u_data)
{
	while(*u_data)
	{
		data_tx(*u_data);
		u_data++;
	}

}

void dma_config(void)
{

	//clear LISR
	DMA2->LISR &= ~(0xffffffff);

	//clear HISR
	DMA2->HISR &= ~(0xffffffff);

	// Peripheral flow controller
	DMA2->S7CR &= ~(1<<5);  // Dma control

	//  Data transfer direction
	DMA2->S7CR &= ~(0X3<<6); 
	DMA2->S7CR |= 1<<6; //Memory-to-peripheral

	//  Data transfer direction
	DMA2->S7CR &= ~(0X3<<6); 
	DMA2->S7CR |= 1<<6; //peripheral-to-memory

	// Memory increment mode
	DMA2->S7CR |= 1<<10; // increment is done according to MSIZE

	// Peripheral data size
	DMA2->S7CR &= ~(0X3<<11); 
	DMA2->S7CR |= 1<<12;  // 10: Word (32-bit)

	// Memory data size
	DMA2->S7CR &= ~(0X3<<13); 
	DMA2->S7CR |= 1<<14;  //10: word (32-bit)

	// Priority level
	DMA2->S7CR &= ~(0X3<<16); 
	DMA2->S7CR |= 1<<16;  // medium

	// Channel selection
	DMA2->S7CR &= ~(7<<25); 
	DMA2->S7CR |= 4<<25; 
	

//	DMA2->S7CR |= 0X08015c40;
}

void dma_data_tx(void)
{

//	// USART1_DR register address
	DMA2->S7M0AR = 0x40011004 ;
	

	// peripheral address like DR register 
	DMA2->S7PAR = 0x40011004 ;

	//hear store number of byte to send
	DMA2->S7NDTR = 15; 

//	while(DMA2->S7NDTR);

	// Stream enable
	DMA2->S7CR |= 1;

}
unsigned char usart_rx(void)
{
	unsigned char data;
	data = USART_DR;
	while(!(USART_SR & 1<<5));
	return data;
}
