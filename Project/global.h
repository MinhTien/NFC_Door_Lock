#ifndef __GLOBAL_H
#define __GLOBAL_H

#include <stdio.h>
#include "stm32f10x.h" 

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#endif /* __GNUC__ */

#define SYSTEM_ID 1

#define MAVLINK_BAUD 57600
#define MAV_RX_BUFF_SIZE 100
#define MAV_TX_BUFF_SIZE 100

#define BUZZER_PIN      GPIO_Pin_0
#define BUZZER_PORT     GPIOA

#define RELAY_A_PIN      GPIO_Pin_1
#define RELAY_A_PORT     GPIOA

#define RELAY_B_PIN      GPIO_Pin_2
#define RELAY_B_PORT     GPIOA

#define LED_PIN      GPIO_Pin_9
#define LED_PORT     GPIOB

#define SPI1_NSS_PIN  	GPIO_Pin_4
#define SPI1_NSS_PORT  	GPIOA

#define SPI1_SCK_PIN  	GPIO_Pin_5
#define SPI1_SCK_PORT  	GPIOA

#define SPI1_MISO_PIN  	GPIO_Pin_6
#define SPI1_MISO_PORT  GPIOA

#define SPI1_MOSI_PIN  	GPIO_Pin_7
#define SPI1_MOSI_PORT  GPIOA

#define SPI1_PORT  GPIOA   

#define _BV(x) 1<<x

void delay_us(uint32_t Nus);
void delay_ms(uint32_t Nus);
void NVIC_Configuration(void);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void beep_Buzzer(uint8_t ton, uint8_t toff, uint8_t times);
void USART_Configuration(void);
void SPI_Configuration(void);
void EXTI_Configuration(void);
void TIM_Configuration(void);
void Led(BitAction cmd);
void Buzzer(BitAction cmd);

enum gMAV_ENUM
{
	gMAV_SEND_MSG,
  gMAV_SEND_PARAM,
  gMAV_SEND_NONE,
};

typedef struct __gMav
{ uint8_t sendType;
  uint8_t sendFinish;
  uint8_t msgIndex;
  uint8_t update;
} gMav_t ;

#endif
