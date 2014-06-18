#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
	
uint8_t timerStick=0;
uint8_t success=0;
uint8_t uidLength=0;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
uint8_t uid[] = {0, 0, 0, 0, 0, 0, 0};  // Buffer to store the returned UID
uint16_t updateMav;
uint8_t mav_tx_buffer[MAV_TX_BUFF_SIZE];
uint8_t mav_rx_buffer[MAV_RX_BUFF_SIZE];
uint8_t mav_rx_tmp[MAV_RX_BUFF_SIZE];
gMav_t gMav;

PUTCHAR_PROTOTYPE
{
		//Place your implementation of fputc here 
	//e.g. write a character to the USART 
	USART_SendData(USART1, (uint8_t) ch);

	//Loop until the end of transmission 
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
	{}
		
	return ch;
}

void delay_us(uint32_t Nus)
{ 
	__IO uint32_t index = 0;

	/* default system clock is 72MHz */
	for(index = (72 * Nus); index != 0; index--)
	{
	}
}

void delay_ms(uint32_t Nus)
{ 
   __IO uint32_t index = 0;

	/* default system clock is 72MHz */
	for(index = (72000 * Nus); index != 0; index--)
	{
	}
}

void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
// 	/* EXTI */
// 	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;					 
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		   
// 	NVIC_Init(&NVIC_InitStructure);
	
// 	/* USART1 Receive Interrupt */
// 	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);
// 	
// 	/* TIM2 Updated Interrupt */
// 	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);
	
	/* Enable the DMA1_Channel4 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;			
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;					
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
  NVIC_Init(&NVIC_InitStructure);
}

void RCC_Configuration(void)
{
	/* Enable GPIOA, GPIOC clocks */
	ErrorStatus HSEStartUpStatus;
	/* Setup the microcontroller system. Initialize the Embedded Flash Interface,  
	initialize the PLL and update the SystemFrequency variable. */

	/* Enable HSE */
	RCC_HSEConfig(RCC_HSE_ON);

	/* Wait till HSE is ready */
  HSEStartUpStatus = RCC_WaitForHSEStartUp();

  if (HSEStartUpStatus == SUCCESS)
  {
   		/* Enable Prefetch Buffer */
    	FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

    	/* Flash 2 wait state */
    	FLASH_SetLatency(FLASH_Latency_2);

    	/* HCLK = SYSCLK */
    	RCC_HCLKConfig(RCC_SYSCLK_Div1);

    	/* PCLK2 = HCLK */
    	RCC_PCLK2Config(RCC_HCLK_Div1);

    	/* PCLK1 = HCLK/4 */
    	RCC_PCLK1Config(RCC_HCLK_Div4);

    	/* PLLCLK = 8MHz * 9 = 72 MHz */
    	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

    	/* Enable PLL */
    	RCC_PLLCmd(ENABLE);

    	/* Wait till PLL is ready */
    	while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
    	{}
	
	    /* Select PLL as system clock source */
	    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	
	    /* Wait till PLL is used as system clock source */
	    while (RCC_GetSYSCLKSource()!= 0x08)
	    {}
	}
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_USART1 | RCC_APB2Periph_SPI1 | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
}

void GPIO_Configuration(void)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	
// 	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST, ENABLE);
	/*------------------------------------------
	PA.3 (RST)    -->   MFRC522's RST Pin
	PA.4 (NSS)    -->   MFRC522's SDA Pin
	PA.5 (SCK)    -->   MFRC522's SCK Pin
	PA.6 (MISO)   -->   MFRC522's MISO Pin
	PA.7 (MOSI)   -->   MFRC522's MOSI Pin
	-------------------------------------------*/
	/* PA.1 for Relay A control */
	GPIO_InitStructure.GPIO_Pin = RELAY_A_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
	GPIO_Init(RELAY_A_PORT, &GPIO_InitStructure);
	
	GPIO_ResetBits(RELAY_A_PORT, RELAY_A_PIN); 
	
	/* PA.2 for Relay A control */
	GPIO_InitStructure.GPIO_Pin = RELAY_B_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
	GPIO_Init(RELAY_B_PORT, &GPIO_InitStructure);
	
	GPIO_ResetBits(RELAY_B_PORT, RELAY_B_PIN); 
	
	/* PA.0 for Buzzer */
	GPIO_InitStructure.GPIO_Pin = BUZZER_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
	GPIO_Init(BUZZER_PORT, &GPIO_InitStructure);
	
	/* PA.1 for Led output */
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
	GPIO_Init(LED_PORT, &GPIO_InitStructure);
	
	Led(Bit_RESET); // OFF
	Buzzer(Bit_RESET);
	
	/* SPI NSS Pin */
	GPIO_InitStructure.GPIO_Pin = SPI1_NSS_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
	GPIO_Init(SPI1_PORT, &GPIO_InitStructure);
	
	GPIO_SetBits(SPI1_NSS_PORT, SPI1_NSS_PIN); // desellect chip
	
	/* PWM output Pin to control RC Servo Motor*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	 
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* SPI SCK, MOSI Pins */
	GPIO_InitStructure.GPIO_Pin = SPI1_SCK_PIN | SPI1_MOSI_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
	GPIO_Init(SPI1_PORT, &GPIO_InitStructure);
	
	/* SPI MISO Pin */
	GPIO_InitStructure.GPIO_Pin = SPI1_MISO_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	 
	GPIO_Init(SPI1_PORT, &GPIO_InitStructure);
	
	/* Configure PA9 for USART1 Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure PA10 for USART1 Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void beep_Buzzer(uint8_t ton, uint8_t toff, uint8_t times)
{
	unsigned char i;
	for (i=1; i<=times;i++)
	{
// 		GPIO_ResetBits(BUZZER_PORT, BUZZER_PIN);
		GPIO_SetBits(LED_PORT, LED_PIN);
		delay_ms(ton);
// 		GPIO_SetBits(BUZZER_PORT, BUZZER_PIN);
		GPIO_ResetBits(LED_PORT, LED_PIN);
		delay_ms(toff);
	}
}

void USART_Configuration(void)
{  	 
	USART_InitTypeDef USART_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	
	#ifdef  VECT_TAB_RAM
		/* Set the Vector Table base location at 0x20000000 */
		NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
	#else  /* VECT_TAB_FLASH  */
		/* Set the Vector Table base location at 0x08000000 */
		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	#endif	
	
	/* Set address for DMA memory TX*/ 
	DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_BASE + 0x04;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)mav_tx_buffer;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_BufferSize = 0;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	/* Clear the TC bit in the SR */
	USART_ClearFlag(USART1, USART_FLAG_TC);	
	/* DMA1_Channel4 configuration */
	DMA_Init(DMA1_Channel4, &DMA_InitStructure);	
	/* Enable DMA interupt */
	DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE);	
	/* Enable DMA */
	DMA_Cmd(DMA1_Channel4, DISABLE);
	
	/* Set address for DMA USART1 RX*/
	DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_BASE + 0x04;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t) mav_rx_buffer;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = MAV_RX_BUFF_SIZE; 
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	/* DMA1_Channel5 configuration */
	DMA_Init(DMA1_Channel5, &DMA_InitStructure);
	
	/* Enable DMA */
	DMA_Cmd(DMA1_Channel5, ENABLE);
	
	USART_InitStructure.USART_BaudRate = 57600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	
	/* USART configuration */
	USART_Init(USART1, &USART_InitStructure);
	/* Enable USART  DMA */
	USART_DMACmd(USART1, USART_DMAReq_Tx | USART_DMAReq_Rx, ENABLE);
	/* Enable USART */
	USART_Cmd(USART1, ENABLE);
}

void SPI_Configuration(void)
{
	SPI_InitTypeDef   SPI_InitStructure;
	
	/* SPI1 Configuration */
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1, &SPI_InitStructure);
	
	/* Enable SPI1 */
	SPI_Cmd(SPI1, ENABLE);
}

void TIM_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 2999;	  //TIM2 frequency is 400Hz
	TIM_TimeBaseStructure.TIM_Prescaler = 35;		 //clock for TIM2 is 1 MHz
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 500;		//999			   
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	
	TIM_SetCounter(TIM2, 0);
 	TIM_Cmd(TIM2, ENABLE);
}
void EXTI_Configuration(void)
{
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	
// 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);
// 	EXTI_InitStructure.EXTI_Mode		=	EXTI_Mode_Interrupt;
//   EXTI_InitStructure.EXTI_Trigger	=	EXTI_Trigger_Falling;
//   EXTI_InitStructure.EXTI_Line		=	EXTI_Line5;
//   EXTI_InitStructure.EXTI_LineCmd	=	ENABLE;
//   EXTI_Init(&EXTI_InitStructure);
}

void Led(BitAction cmd)
{
	GPIO_WriteBit(LED_PORT, LED_PIN, (BitAction)cmd);
}

void Buzzer(BitAction cmd)
{
	GPIO_WriteBit(BUZZER_PORT, BUZZER_PIN, (BitAction)(1-cmd));
}

/*----------------------------------------------------------------------------
  Write character to Serial Port.
 *----------------------------------------------------------------------------*/
int SendChar (int ch)  
{
  while (!(USART1->SR & 0X80));
  USART1->DR = (ch & 0x1FF);

  return (ch);
}

/*----------------------------------------------------------------------------
  Read character to Serial Port.
 *----------------------------------------------------------------------------*/
int GetKey (void)  
{
  while (!(USART1->SR & 0X40));
  return ((int)(USART1->DR & 0x1FF));
}
