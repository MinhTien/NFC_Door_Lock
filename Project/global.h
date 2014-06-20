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
#define BUZZER_PORT     GPIOB

#define LED_RED 0x01
#define LED_RED_PIN      GPIO_Pin_6
#define LED_RED_PORT     GPIOB

#define LED_GREEN 0x02
#define LED_GREEN_PIN      GPIO_Pin_7
#define LED_GREEN_PORT     GPIOB

#define LED_COMMON_PIN     GPIO_Pin_8
#define LED_COMMON_PORT    GPIOA

#define RELAY_A_PIN      GPIO_Pin_1
#define RELAY_A_PORT     GPIOA

#define RELAY_B_PIN      GPIO_Pin_2
#define RELAY_B_PORT     GPIOA

#define PWM_OUT_PIN			GPIO_Pin_3
#define PWM_OUT_PORT		GPIOA

#define SPI_NSS_PIN  	GPIO_Pin_12
#define SPI_NSS_PORT  	GPIOB

#define SPI_SCK_PIN  	GPIO_Pin_13
#define SPI_SCK_PORT  	GPIOB

#define SPI_MISO_PIN  	GPIO_Pin_14
#define SPI_MISO_PORT  GPIOB

#define SPI_MOSI_PIN  	GPIO_Pin_15
#define SPI_MOSI_PORT  GPIOB

#define SPI_PORT  GPIOB  

#define _BV(x) 1<<x

void delay_us(uint32_t Nus);
void delay_ms(uint32_t Nus);
void NVIC_Configuration(void);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void USART_Configuration(void);
void SPI_Configuration(void);
void EXTI_Configuration(void);
void TIM_Configuration(void);
void LedCmd(uint8_t led, BitAction cmd);
void BuzzerCmd(BitAction cmd);
void BeepBuzzer(uint8_t ton, uint8_t toff, uint8_t times);
void BlinkingLed(uint8_t led, uint8_t ton, uint8_t toff, uint8_t times);
void Lock(void);
void Unlock(void);

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
