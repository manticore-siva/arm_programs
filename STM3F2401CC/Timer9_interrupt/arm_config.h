/*
////RCC REGISTER ADDRESS      ////////////

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

//// END TIMER 10 REGISTERS ADDRESS  /////////


*/

/// SysTick timer Register address ////
struct stk{
            unsigned int CTRL;
            unsigned int LOAD;
            unsigned int VAL;
            unsigned int CALIB;
            };
volatile struct stk *STK = (volatile struct stk*)0xE000E010; 

// #define STK_CTRL    (*(volatile unsigned int *)0xE000E010)        //SysTick control and status register (STK_CTRL)
// #define STK_LOAD    (*(volatile unsigned int *)0xE000E014)        //SysTick reload value register (STK_LOAD) 
// #define STK_VAL  	(*(volatile unsigned int *)0xE000E018)        //SysTick current value register (STK_VAL) 
// #define STK_CALIB	(*(volatile unsigned int *)0xE000E01C)        //SysTick calibration value register (STK_CALIB)

/// End Systick timer register address ///




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

//////////////// END DMA2

// PORT A register address

	struct porta{

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

	volatile struct porta *GPIOA = (volatile struct porta *)0x40020000;

// END GPIOA register address


// PORT B register address

	struct portb{

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

	volatile struct portb *GPIOB = (volatile struct portb*)0x40020400;

// END GPIOB register address


// PORT C register address

	struct portc{

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

	volatile struct portc *GPIOC = (volatile struct portc *)0x40020800;

// END GPIOC register address


// PORT D register address

	struct portd{

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

	volatile struct portd *GPIOD = (volatile struct portd *)0x40020C00;

// END GPIOD register address


// PORT E register address

	struct porte{

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

	volatile struct porte *GPIOE = (volatile struct porte *)0x40021000;

// END GPIOD register address


// PORT H register address

	struct porth{

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

	volatile struct porth *GPIOH = (volatile struct porth *)0x40021C00;

// END GPIOH register address


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
	volatile struct timer *TIM9 = (volatile struct timer*)0x40014000;


/////// NVIC //////////////
struct nvic{
			unsigned int ISER[8];  	// 0xE000E100-0xE000E11F
			unsigned int unused1[24]; //offset 288bytes unused
			unsigned int ICER[8];	// 0XE000E180-0xE000E19F 
			unsigned int unused2[24]; //offset 288bytes unused
			unsigned int ISPR[8];	// 0XE000E200-0xE000E21F
			unsigned int unused3[24]; //offset 288bytes unused
			unsigned int ICPR[8];   // 0XE000E280-0xE000E29F
			unsigned int unused4[24]; //offset 288bytes unused
			unsigned int IABR[8];	// 0xE000E300-0xE000E31F
			unsigned int unused5[56]; //offset 288bytes unused
			unsigned int IPR[60];	// 0xE000E400-0xE000E4EF
			unsigned int unused6[644]; //offset 288bytes unused
			unsigned int STIR;		// 0xE000EF00
	};
	volatile struct nvic *NVIC = (volatile struct nvic*)0xE000E100;

#define NVIC_ENABLE_INTERRUPT(number)     (NVIC->ISER[number>>5]|= 1<<(number& 0x1F)) 
#define NVIC_DISABLE_INTERRUPT(number)    (NVIC->ICER[number>>5]|= 1<<(number& 0x1F)) 
#define NVIC_SET_INTERRUPT_FLAG(number)   (NVIC->ISPR[number>>5]|= 1<<(number& 0x1F)) 
#define NVIC_CLEAR_INTERRUPT_FLAG(number) (NVIC->ICPR[number>>5]|= 1<<(number& 0x1F))
