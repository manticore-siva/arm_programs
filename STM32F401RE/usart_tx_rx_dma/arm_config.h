
////RCC REGISTER ADDRESS      ////////////
/*
#define RCC_CR            (*(volatile unsigned int *)0x40023800)     // RCC clock control register (RCC_CR)
#define PLL_CFRG          (*(volatile unsigned int *)0x40023804)     //RCC PLL configuration register (RCC_PLLCFGR)
#define RCC_CFGR          (*(volatile unsigned int *)0x40023808)     // RCC clock configuration register (RCC_CFGR)
#define RCC_CIR           (*(volatile unsigned int *)0x4002380C)     // RCC clock interrupt register (RCC_CIR)
#define RCC_AHB1RSTR      (*(volatile unsigned int *)0x40023810)     // RCC AHB1 peripheral reset register (RCC_AHB1RSTR) 
#define RCC_AHB2RSTR      (*(volatile unsigned int *)0x40023814)     // RCC AHB2 peripheral reset register (RCC_AHB2RSTR) 
#define RCC_APB1RSTR      (*(volatile unsigned int *)0x40023820)     // RCC APB1 peripheral reset register for (RCC_APB1RSTR) 
#define RCC_APB2RSTR      (*(volatile unsigned int *)0x40023824)     // RCC APB2 peripheral reset register (RCC_APB2RSTR)
#define RCC_AHB1ENR       (*(volatile unsigned int *)0x40023830)     // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
#define RCC_AHB2ENR       (*(volatile unsigned int *)0x40023834)     // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define RCC_APB1ENR       (*(volatile unsigned int *)0x40023840)     // RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define RCC_APB2ENR       (*(volatile unsigned int *)0x40023844)     // RCC APB2 peripheral clock enable register (RCC_APB2ENR)
#define RCC_RCC_AHB1LPENR (*(volatile unsigned int *)0x40023850)     // RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)
#define RCC_AHB2LPENR     (*(volatile unsigned int *)0x40023854)     // RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)
#define RCC_APB1LPENR     (*(volatile unsigned int *)0x40023860)     // RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)
#define RCC_APB2LPENR     (*(volatile unsigned int *)0x40023864)     // RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR)
#define RCC_BDCR          (*(volatile unsigned int *)0x40023870)     // RCC Backup domain control register (RCC_BDCR)
#define RCC_CSR           (*(volatile unsigned int *)0x40023874)     // RCC clock control & status register (RCC_CSR)
#define RCC_SSCGR         (*(volatile unsigned int *)0x40023880)     // RCC spread spectrum clock generation register (RCC_SSCGR)
#define RCC_PLLI2SCFGR    (*(volatile unsigned int *)0x40023884)     // RCC PLLI2S configuration register (RCC_PLLI2SCFGR)
#define RCC_DCKCFGR       (*(volatile unsigned int *)0x4002388C)     // RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR)
*/
struct rcc{
			unsigned int CR;                // 0x00
			unsigned int CFRG; 				// 0x04
			unsigned int CFGR; 				// 0x08
			unsigned int CIR; 				// 0x0C
			unsigned int AHB1RSTR; 			// 0X10
			unsigned int AHB2RSTR; 			// 0X14
			unsigned int resr1[2]; 			// 0X18,0X1C
			unsigned int APB1RSTR; 			// 0X20
			unsigned int APB2RSTR; 			// 0X24
			unsigned int resr2[2]; 			// 0X28,0X2C
			unsigned int AHB1ENR; 			// 0X30
			unsigned int AHB2ENR; 			// 0X34
			unsigned int resr3[2]; 			// 0X38,0X3C
			unsigned int APB1ENR; 			// 0X40
			unsigned int APB2ENR; 			// 0X44
			unsigned int resr4[2]; 			// 0X48,0X4C
			unsigned int AHB1LPENR; 		// 0X50
			unsigned int AHB2LPENR; 		// 0X54
			unsigned int resr5[2];			// 0X58,0X5C
			unsigned int APB1LPENR; 		// 0X60
			unsigned int APB2LPENR; 		// 0X64
			unsigned int resr6[2];			// 0X68,0X6C
			unsigned int BDCR; 				// 0X70
			unsigned int CSR; 				// 0X74
			unsigned int resr7[2];			// 0X78,0X7C
			unsigned int SSCGR; 			// 0X80
			unsigned int PLLI2SFCFGR;		// 0X84
			unsigned int resr8;				// 0X88
			unsigned int DCKCFGR;			// 0X8C
};

	struct rcc *RCC = (struct rcc*)0x40023800;

//// END RCC REGISTER ADDRESS /////////////////

////// GPIOA PORT ADDRESS ////////////////////////

#define GPIOA_MODER    	(*(volatile unsigned int *)0x40020000)         // GPIOA port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOA_OTYPER    (*(volatile unsigned int *)0x40020004)         // GPIOA port output type register (GPIOx_OTYPER)
#define GPIOA_OSPEEDR  	(*(volatile unsigned int *)0x40020008)         // GPIOA port output speed register (GPIOx_OSPEEDR)
#define GPIOA_PUPDR 	(*(volatile unsigned int *)0x4002000C)         // GPIOA port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOA_IDR    	(*(volatile unsigned int *)0x40020010)         // GPIOA port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOA_ODR     	(*(volatile unsigned int *)0x40020014)         // GPIOA port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOA_BSRR     	(*(volatile unsigned int *)0x40020018)         // GPIOA port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOA_LCKR     	(*(volatile unsigned int *)0x4002001C)         // GPIOA port configuration lock register (GPIOx_LCKR)
#define GPIOA_AFRL    	(*(volatile unsigned int *)0x40020020)         // GPIOA alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOA_AFRH    	(*(volatile unsigned int *)0x40020024)         // GPIOA alternate function high register (GPIOx_AFRH)

//////// GPIOA ADDRESS END ////////////////////


////// GPIOB PORT ADDRESS ////////////////////////

#define GPIOB_MODER    	(*(volatile unsigned int *)0x40020400)         // GPIOB port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOB_OTYPER    (*(volatile unsigned int *)0x40020404)         // GPIOB port output type register (GPIOx_OTYPER)
#define GPIOB_OSPEEDR  	(*(volatile unsigned int *)0x40020408)         // GPIOB port output speed register (GPIOx_OSPEEDR)
#define GPIOB_PUPDR 	(*(volatile unsigned int *)0x4002040C)         // GPIOB port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOB_IDR    	(*(volatile unsigned int *)0x40020410)         // GPIOB port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOB_ODR     	(*(volatile unsigned int *)0x40020414)         // GPIOB port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOB_BSRR     	(*(volatile unsigned int *)0x40020418)         // GPIOB port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOB_LCKR     	(*(volatile unsigned int *)0x4002041C)         // GPIOB port configuration lock register (GPIOx_LCKR)
#define GPIOB_AFRL    	(*(volatile unsigned int *)0x40020420)         // GPIOB alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOB_AFRH    	(*(volatile unsigned int *)0x40020424)         // GPIOB alternate function high register (GPIOx_AFRH)

//////// GPIOA ADDRESS END ////////////////////

////// GPIOC PORT ADDRESS ////////////////////////

#define GPIOC_MODER    	(*(volatile unsigned int *)0x40020800)         // GPIOC port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOC_OTYPER    (*(volatile unsigned int *)0x40020804)         // GPIOC port output type register (GPIOx_OTYPER)
#define GPIOC_OSPEEDR  	(*(volatile unsigned int *)0x40020808)         // GPIOC port output speed register (GPIOx_OSPEEDR)
#define GPIOC_PUPDR 	(*(volatile unsigned int *)0x4002080C)         // GPIOC port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOC_IDR    	(*(volatile unsigned int *)0x40020810)         // GPIOC port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOC_ODR     	(*(volatile unsigned int *)0x40020814)         // GPIOC port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOC_BSRR     	(*(volatile unsigned int *)0x40020818)         // GPIOC port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOC_LCKR     	(*(volatile unsigned int *)0x4002081C)         // GPIOC port configuration lock register (GPIOx_LCKR)
#define GPIOC_AFRL    	(*(volatile unsigned int *)0x40020820)         // GPIOC alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOC_AFRH    	(*(volatile unsigned int *)0x40020824)         // GPIOC alternate function high register (GPIOx_AFRH)

////// END GPIOC ADDRESS ///////////////////////

////// GPIOD PORT ADDRESS ////////////////////////

#define GPIOD_MODER    	(*(volatile unsigned int *)0x40020C00)         // GPIOD port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOD_OTYPER    (*(volatile unsigned int *)0x40020C04)         // GPIOD port output type register (GPIOx_OTYPER)
#define GPIOD_OSPEEDR  	(*(volatile unsigned int *)0x40020C08)         // GPIOD port output speed register (GPIOx_OSPEEDR)
#define GPIOD_PUPDR 	(*(volatile unsigned int *)0x40020C0C)         // GPIOD port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOD_IDR    	(*(volatile unsigned int *)0x40020C10)         // GPIOD port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOD_ODR     	(*(volatile unsigned int *)0x40020C14)         // GPIOD port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOD_BSRR     	(*(volatile unsigned int *)0x40020C18)         // GPIOD port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOD_LCKR     	(*(volatile unsigned int *)0x40020C1C)         // GPIOD port configuration lock register (GPIOx_LCKR)
#define GPIOD_AFRL    	(*(volatile unsigned int *)0x40020C20)         // GPIOD alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOD_AFRH    	(*(volatile unsigned int *)0x40020C24)         // GPIOD alternate function high register (GPIOx_AFRH)

//////// GPIOA ADDRESS END ////////////////////


////// GPIOE PORT ADDRESS ////////////////////////

#define GPIOE_MODER    	(*(volatile unsigned int *)0x40021000)         // GPIOE port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOE_OTYPER    (*(volatile unsigned int *)0x40021004)         // GPIOE port output type register (GPIOx_OTYPER)
#define GPIOE_OSPEEDR  	(*(volatile unsigned int *)0x40021008)         // GPIOE port output speed register (GPIOx_OSPEEDR)
#define GPIOE_PUPDR 	(*(volatile unsigned int *)0x4002100C)         // GPIOE port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOE_IDR    	(*(volatile unsigned int *)0x40021010)         // GPIOE port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOE_ODR     	(*(volatile unsigned int *)0x40021014)         // GPIOE port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOE_BSRR     	(*(volatile unsigned int *)0x40021018)         // GPIOE port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOE_LCKR     	(*(volatile unsigned int *)0x4002101C)         // GPIOE port configuration lock register (GPIOx_LCKR)
#define GPIOE_AFRL    	(*(volatile unsigned int *)0x40021020)         // GPIOE alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOE_AFRH    	(*(volatile unsigned int *)0x40021024)         // GPIOE alternate function high register (GPIOx_AFRH)

//////// GPIOE ADDRESS END ////////////////////


////// GPIOH PORT ADDRESS ////////////////////////

#define GPIOH_MODER    	(*(volatile unsigned int *)0x40021C00)         // GPIOA port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOH_OTYPER    (*(volatile unsigned int *)0x40021C04)         // GPIOA port output type register (GPIOx_OTYPER)
#define GPIOH_OSPEEDR  	(*(volatile unsigned int *)0x40021C08)         // GPIOA port output speed register (GPIOx_OSPEEDR)
#define GPIOH_PUPDR 	(*(volatile unsigned int *)0x40021C0C)         // GPIOA port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOH_IDR    	(*(volatile unsigned int *)0x40021C10)         // GPIOA port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOH_ODR     	(*(volatile unsigned int *)0x40021C14)         // GPIOA port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOH_BSRR     	(*(volatile unsigned int *)0x40021C18)         // GPIOA port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOH_LCKR     	(*(volatile unsigned int *)0x40021C1C)         // GPIOA port configuration lock register (GPIOx_LCKR)
#define GPIOH_AFRL    	(*(volatile unsigned int *)0x40021C20)         // GPIOA alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOH_AFRH    	(*(volatile unsigned int *)0x40021C24)         // GPIOA alternate function high register (GPIOx_AFRH)

//////// GPIOH ADDRESS END ////////////////////

////TIMER 10 REGISRERS ///////////////////////

#define TIM10_CR1   (*(volatile unsigned int *)0x40014400)    // TIM10 control register 1 (TIM10_CR1)
#define TIM10_DIER  (*(volatile unsigned int *)0x4001440C)    // TIM10 Interrupt enable register (TIM10_DIER)
#define TIM10_SR    (*(volatile unsigned int *)0x40014410)    // TIM10 status register
#define TIM10_EGR   (*(volatile unsigned int *)0x40014414)    // TIM10 event generation register (TIM10_EGR)
#define TIM10_CCMR1 (*(volatile unsigned int *)0x40014418)    // TIM10 capture/compare mode register 1 (TIM10_CCMR1)
#define TIM10_CCER  (*(volatile unsigned int *)0x40014420)    // TIM10 capture/compare enable register (TIM10_CCER)
#define TIM10_CNT   (*(volatile unsigned int *)0x40014424)    // TIM10 counter (TIM10_CNT)
#define TIM10_PSC   (*(volatile unsigned int *)0x40014428)    // TIM10 prescaler (TIM10_PSC)
#define TIM10_ARR   (*(volatile unsigned int *)0x4001442C)    // TIM10 auto-reload register (TIM10_ARR)
#define TIM10_CCR1  (*(volatile unsigned int *)0x40014434)    // TIM10 capture/compare register 1 (TIM10_CCR1)
#define TIM10_OR    (*(volatile unsigned int *)0x40014450)    // TIM11 option register 1 (TIM11_OR)

//// END TIMER 10 REGISTERS ADDRESS  ////////

//// USART  REGISGER ////////////////////////
#define USART_SR   (*(volatile unsigned int *)0x40011000)      // USART 1 Status register (USART_SR) 
#define USART_DR   (*(volatile unsigned int *)0x40011004)      // USART 1 Data register (USART_DR) 
#define USART_BRR  (*(volatile unsigned int *)0x40011008)      // USART 1 Baud rate register (USART_BRR) 
#define USART_CR1  (*(volatile unsigned int *)0x4001100C)      // USART 1 Control register 1 (USART_CR1) 
#define USART_CR2  (*(volatile unsigned int *)0x40011010)      // USART 2 Control register 2 (USART_CR2) 
#define USART_CR3  (*(volatile unsigned int *)0x40011014)      // USART 3 Control register 3 (USART_CR3) 
#define USART_GTPR (*(volatile unsigned int *)0x40011018)      // USART  Guard time and prescaler register (USART_GTPR) 

////////// USART REGISTER END /////////////////

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

