////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM - UASR receive data by use DMA(Direct memory access       //
//   Date  : 05/08/2023                                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"

#define PRINT_BUFFER_LIMIT 40
#define STRING_SIZE        40

void rcc_config(void);
void port_config(void);
void usart_config(void);
void data_tx(unsigned char data);
void usar_data(unsigned char *u_data);
void dma_config(void);
void dma_data_tx(void);
void print_uart1(char *string1);
void DMA2_Stream5_IRQHandler(void);
void DMA2_Stream7_IRQHandler(void);
void nvic_config(void);

struct string_list{
				unsigned int  size;
				char string[STRING_SIZE];
};

struct string_list list1[PRINT_BUFFER_LIMIT];

int main()
{

	rcc_config();
    usart_config();
	dma_config();
	port_config();
	nvic_config();
    print_uart1( "Hello world\n\r");
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

	//10: Alternate function mode PIN A10 RX 
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
	
	// 0111: AF7 GPIO alternate function high register 
	GPIOA_AFRH |= 0x700;
}
void usart_config(void)
{
	//Enable UE bit,M: Word length
	USART1->CR1 &= ~(3<<12);
	USART1->CR1 |= 1<<13;

	//number of stop bit 
	USART1->CR2 &= ~(3<<12);
	USART1->CR2 |= (1<<13);

	//Over 8 = 0
	USART1->CR1 &= ~(1<<15);

	//select baud rate
	USART1->BRR |= 11;  // fraction value = 11
	USART1->BRR |= 8<<4; // mantissa value = 8

	//DMA enable transmitter
	USART1->CR3 |= 1<<7;

	//DMA enable Receiver
	USART1->CR3 |= 1<<6;

	//enable TE bit 
	USART1->CR1 |= 0x8;

	//enable RE bit 
	USART1->CR1 |= 0x4;

	//cheak sattus 			
	while(!(USART1->SR & (1<<7)));
//	USART_SR &= ~(1<<6); //clear TC bit

}


void dma_config(void)
{

	//clear LISR
	DMA2->LISR &= ~(0xffffffff);

	//clear HISR
	DMA2->HISR &= ~(0xffffffff);

	// Peripheral flow controller stream 7
	DMA2->S7CR &= ~(1<<5);  // Dma control

	// Peripheral flow controller stream 5
	DMA2->S5CR |= 1<<5;  // Peripheral control

	//  Data transfer direction stream 7
	DMA2->S5CR &= ~(0X3<<6); 
	DMA2->S5CR |= 1<<6; //Memory-to-peripheral

	//  Data transfer direction channel 4
	DMA2->S7CR &= ~(0X3<<6); //peripheral-to-memory
	
	// Memory increment mode
	DMA2->S7CR |= 1<<10; // increment is done according to MSIZE

	// Memory increment mode
	DMA2->S5CR |= 1<<10; // increment is done according to MSIZE

	// Peripheral data size 8bit
	DMA2->S7CR &= ~(0X3<<11); 

	// Peripheral data size 8bit
	DMA2->S5CR &= ~(0X3<<11); 

	// Memory data size 8 bit
	DMA2->S7CR &= ~(0X3<<13); 

	// Memory data size 8 bit
	DMA2->S5CR &= ~(0X3<<13); 

	// Priority level
	DMA2->S7CR &= ~(0X3<<16); 
	DMA2->S7CR |= 1<<16;  // medium

	// Priority level
	DMA2->S5CR &= ~(0X3<<16); 
	DMA2->S5CR |= 1<<16;  // medium

	// Channel selection 4
	DMA2->S7CR &= ~(7<<25); 
	DMA2->S7CR |= 4<<25; 
	

	// Channel selection 4
	DMA2->S5CR &= ~(7<<25); 
	DMA2->S5CR |= 1<<27; 

	//Enable DMA2_stream7 interrupt
	DMA2->S7CR |= 1<<4;

	//Enable DMA2_stream5 interrupt
	DMA2->S5CR |= 1<<4;

	// peripheral address like DR register 
	DMA2->S7PAR = (unsigned int )&USART1->DR;

	// peripheral address like DR register 
	DMA2->S5PAR = (unsigned int )&USART1->DR;
}

void print_uart1(char *string1)
{
	static unsigned int l_index = 0;
	unsigned int inc = 0;

	char *temp_string = string1;

	list1[l_index].size = 0;

	while(*temp_string)
	{
		list1[l_index].string[inc++] = *temp_string++;
	}

	list1[l_index].size = inc;

	l_index++;

	if(l_index >= PRINT_BUFFER_LIMIT)
		l_index = 0;
	
	if(!(DMA2->S7CR & 1))
	{	
		//Enable interrupt flag to initiate DMA Trasfer
		NVIC_SET_INTERRUPT_FLAG(70);
	}

}

void DMA2_Stream7_IRQHandler(void)
{
	static int index = 0;

	// clear interrupt flag
	NVIC_CLEAR_INTERRUPT_FLAG(70);

	// clear HISR flag
	DMA2->HIFCR |= 1<<27;
	
	// Stream disable
	DMA2->S7CR &= (~1);

	if(list1[index].size)
	{
		// USART1_DR register address
		DMA2->S7M0AR =(unsigned int) list1[index].string;

		//hear store number of byte to send
		DMA2->S7NDTR = list1[index].size; 

		// Stream enable
		DMA2->S7CR |= 1;
	}
	else
	{
		// Stream Disable
		DMA2->S7CR &= ~1;
	}

		list1[index].size = 0;

	index++;

	if(index >= PRINT_BUFFER_LIMIT)
		index = 0;
}

void nvic_config(void)
{

	//interrupt no 68-DMA2 stream 5 enable
	NVIC_ENABLE_INTERRUPT(68);
}

void DMA2_Stream5_IRQHandler(void)
{
	char r_data;

	// clear interrupt flag
	NVIC_CLEAR_INTERRUPT_FLAG(68);

	// clear HISR flag
	DMA2->HIFCR |= 1<<27;

	// Stream disable
	DMA2->S5CR &= (~1);

	//
	USART1->DR = USART1->DR;

	//interrupt no 70-DMA2 stream 7 enable
	NVIC_ENABLE_INTERRUPT(70);
}
