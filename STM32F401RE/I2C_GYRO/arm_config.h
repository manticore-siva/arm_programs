
// RCC block 

	struct rcc{
				unsigned int CR;             // 0x00
				unsigned int PLLCFGR;		 // 0x04
				unsigned int CFGR; 			 // 0x08
				unsigned int CIR;			 // 0x0c
				unsigned int AHB1STR;		 // 0x10
				unsigned int AHB2RSTR;		 // 0x14
				unsigned int res[2]; 		 // 0x18,0x1c
				unsigned int APB1RSTR;		 // 0x20
				unsigned int APB2RSTR;		 // 0x24
				unsigned int res1[2];		 // 0x28,2c
				unsigned int AHB1ENR;		 // 0x30
				unsigned int AHB2ENR;		 // 0x34
				unsigned int res2[2];		 // 0x38,0x3c
				unsigned int APB1ENR;		 // 0x40
				unsigned int APB2ENR;		 // 0x44
				unsigned int res3[2];		 // 0x48,0x4c
				unsigned int AHB1LPENR;		 // 0x50
				unsigned int AHB2LPENR;		 // 0x54
				unsigned int res4[2];        // 0x58,0x5c
				unsigned int APB1LPENR;		 // 0x60
				unsigned int APB2LPENR;		 // 0x64
				unsigned int res5[2];		 // 0x68,0x6c
				unsigned int BDCR;			 // 0x70
				unsigned int CSR;            // 0x74
				unsigned int res6[2];        // 0x78,0x7c
				unsigned int SSCGR;          // 0x80
				unsigned int PLLI2SCFGR;     // 0x84
				unsigned int res7;           // 0x88
				unsigned int DCKCFGR;        // 0x8c
	};
	volatile struct rcc *RCC = (volatile struct rcc*)0x40023800;


/// END rcc block

//  DMA 2 REGISTER ADDRESS ///////////////////////

	struct dma2{

			unsigned int LISR;		// 0x00
			unsigned int HISR;		// 0x04
			unsigned int LIFCR;		// 0x08
			unsigned int HIFCR;		// 0x0c
			unsigned int S0CR;		// 0x10
			unsigned int S0NDTR;	// 0x14
			unsigned int S0PAR;		// 0x18
			unsigned int S0M0AR;	// 0x1c
			unsigned int S0M1AR;	// 0x20
			unsigned int S0FCR;		// 0x24
			unsigned int S1CR;		// 0x28
			unsigned int S1NDTR;	// 0x2C
			unsigned int S1PAR;		// 0x30
			unsigned int S1M0AR;	// 0x34
			unsigned int S1M1AR;	// 0x38
			unsigned int S1FCR;		// 0x3C
			unsigned int S2CR;		// 0x40
			unsigned int S2NDTR;	// 0x44
			unsigned int S2PAR;		// 0x48
			unsigned int S2M0AR;	// 0x4C
			unsigned int S2M1AR;	// 0x50
			unsigned int S2FCR;		// 0x54
			unsigned int S3CR;		// 0x58
			unsigned int S3NDTR;	// 0x5C
			unsigned int S3PAR;		// 0x60
			unsigned int S3M0AR;	// 0x64
			unsigned int S3M1AR;	// 0x68
			unsigned int S3FCR;		// 0x6C
			unsigned int S4CR;		// 0x70
			unsigned int S4NDTR;	// 0x74
			unsigned int S4PAR;		// 0x78
			unsigned int S4M0AR;	// 0x7C
			unsigned int S4M1AR;	// 0x80
			unsigned int S4FCR;		// 0x84
			unsigned int S5CR;		// 0x88
			unsigned int S5NDTR;	// 0x8C
			unsigned int S5PAR;		// 0x90
			unsigned int S5M0AR;	// 0x94
			unsigned int S5M1AR;	// 0x98
			unsigned int S5FCR;		// 0x9C
			unsigned int S6CR;		// 0xA0
			unsigned int S6NDTR;	// 0xA4
			unsigned int S6PAR;		// 0xA8
			unsigned int S6M0AR;	// 0XAC
			unsigned int S6M1AR;	// 0XB0
			unsigned int S6FCR;		// 0XB4
			unsigned int S7CR;		// 0XB8
			unsigned int S7NDTR;	// 0XBC
			unsigned int S7PAR;		// 0XC0
			unsigned int S7M0AR;	// 0XC4
			unsigned int S7M1AR;	// 0XC8
			unsigned int S7FCR;		// 0XCC
	};		

	volatile struct dma2 *DMA2 = (volatile struct dma2*)0x40026400;

//////////////// END DMA2 ////////////////////

// GPIO register address ////////////////////

	struct port{

				unsigned int MODER;     // 0x00
				unsigned int OTYPER;	// 0x04	
				unsigned int OSPEEDR;	// 0x08
				unsigned int PUPDR;		// 0x0c
				unsigned int IDR;		// 0x10
				unsigned int ODR;		// 0x14
				unsigned int BSRR;		// 0x18
				unsigned int LCKR;		// 0x1c
				unsigned int AFRL;		// 0x20
				unsigned int AFRH;		// 0x24
	};

	volatile struct port *GPIOA = (volatile struct port*)0x40020000;
	volatile struct port *GPIOB = (volatile struct port*)0x40020400;
	volatile struct port *GPIOC = (volatile struct port*)0x40020800;
	volatile struct port *GPIOD = (volatile struct port*)0x40020C00;
	volatile struct port *GPIOE = (volatile struct port*)0x40021000;
	volatile struct port *GPIOH = (volatile struct port*)0x40021C00;
// END GPIO register address


// TIMER 1 register address

	struct timer1{

		unsigned int CR1;		// 0x00
		unsigned int CR2; 		// 0x04
		unsigned int SMCR;		// 0x08
		unsigned int DIER;		// 0x0c
		unsigned int SR;		// 0x10
		unsigned int EGR;		// 0x14
		unsigned int CCMR1;		// 0x18
		unsigned int CCMR2;		// 0x1c
		unsigned int CCER;		// 0x20
		unsigned int CNT;		// 0x24
		unsigned int PSC;		// 0x28
		unsigned int ARR;		// 0x2c
		unsigned int RCR;		// 0x30
		unsigned int CCR1;		// 0x34
		unsigned int CCR2;		// 0x38
		unsigned int CCR3;  	// 0x3c
		unsigned int CCR4;		// 0x40
		unsigned int BDTR;		// 0x44
		unsigned int DCR;		// 0x48
		unsigned int DMAR;		// 0x4c
	};
	volatile struct timer1 *TIMER1 = (volatile struct timer1 *)0x40010000;
///TIMER 9 register 

	struct timer{
		unsigned int CR1;		// 0x00
		unsigned int resrd0;	// 0x04
		unsigned int SMCR;		// 0x08
		unsigned int DIER;		// 0x0c
		unsigned int SR;		// 0x10
		unsigned int EGR;		// 0x14
		unsigned int CCMR1;		// 0x18
		unsigned int resrd1;	// 0x1c
		unsigned int CCER;		// 0x20
		unsigned int CNT;		// 0x24
		unsigned int PSC;		// 0x28
		unsigned int ARR;		// 0x2c
		unsigned int resrd2;	// 0x30
		unsigned int CCR1;		// 0x34
		unsigned int CCR2;		// 0x38
		unsigned int resrd3[5];	// 0x3c,0x4c
	};
	volatile struct timer *TIM9  = (volatile struct timer*)0x40014000;
	volatile struct timer *TIM10 = (volatile struct timer*)0x40014400 ;

	struct Timer{
		unsigned int CR1;		// 0x00
		unsigned int CR2;		// 0x04
		unsigned int SMCR;		// 0x08
		unsigned int DIER;		// 0x0C
		unsigned int SR;		// 0x10
		unsigned int EGR;		// 0x14
		unsigned int CCMR1;		// 0x18
		unsigned int CCMR2;		// 0x1c
		unsigned int CCER;		// 0x20
		unsigned int CNT;		// 0x24
		unsigned int PSC;		// 0x28
		unsigned int ARR;		// 0x2c
		unsigned int Res;		// 0x30
		unsigned int CCR1;		// 0x34
		unsigned int CCR2;		// 0x38
		unsigned int CCR3;		// 0x3c
		unsigned int CCR4;		// 0x40
		unsigned int Res1;		// 0x44
		unsigned int DCR;		// 0x48
		unsigned int DMAR;		// 0x4c
		unsigned int OR;		// 0x50
	};
	volatile struct Timer *TIM2 = (volatile struct Timer*)0x40000000; 
	volatile struct Timer *TIM5 = (volatile struct Timer*)0x40000C00; 


	/// I2c register address

	struct i2c{
		volatile int CR1;   	// 0x00
		volatile int CR2;		// 0x04
		volatile int OAR1;		// 0x08
		volatile int OAR2;		// 0x0c
		volatile int DR;		// 0x10
		volatile int SR1;		// 0x14	
		volatile int SR2;		// 0x18
		volatile int CCR;		// 0x1c
		volatile int TRISE;		// 0x20
		volatile int FLTR;		// 0x24
	};
	volatile struct i2c *I2C1 = (volatile struct i2c*)0x40005400;
	volatile struct i2c *I2C2 = (volatile struct i2c*)0x40005800;
	volatile struct i2c *I2C3 = (volatile struct i2c*)0x40005C00;


	struct usart{

		volatile int SR;		// 0x00
		volatile int DR;		// 0x04
		volatile int BRR;		// 0x08
		volatile int CR1;		// 0x0c
		volatile int CR2;		// 0x10
		volatile int CR3;		// 0x14
		volatile int GTPR;		// 0x18
	};
	volatile struct usart *USART1 = (volatile struct usart*)0x40011000;
	volatile struct usart *USART2 = (volatile struct usart*)0x40004400;
	volatile struct usart *USART6 = (volatile struct usart*)0x40011400;
