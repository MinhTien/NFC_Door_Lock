/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include "Adafruit_PN532.h"
#include "gMavlinkV1_0.h"

extern uint8_t timerStick;
extern uint8_t success;
extern uint8_t uidLength;   
extern uint8_t uid[];
extern gMav_t gMav;
extern uint16_t VirtAddVarTab[];
extern uint16_t boardAddress;
extern uint16_t address;
extern uint8_t lockStatus;
extern uint8_t lockControl;

/* Private function prototypes -----------------------------------------------*/
uint8_t keys[]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
uint8_t writeBuffer[16];
uint8_t written=0;
uint8_t block[16];

int main(void)
{
  uint8_t keya[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//  uint8_t data_1[16];
// 	uint8_t data_2[32];
// 	uint16_t loopCount=0;
	uint32_t versiondata=0;

	gMav.sendType=gMAV_SEND_MSG;
	gMav.sendFinish=1;
	gMav.msgIndex=0;

	RCC_Configuration();
	delay_ms(1);
	GPIO_Configuration();
	delay_ms(1);
	USART_Configuration();
	delay_ms(1);
	TIM_Configuration();
 	delay_ms(1);
	delay_ms(1);
 	NVIC_Configuration();

	/** cau hinh bo system tich */
	if (SysTick_Config(SystemCoreClock/10))
	{
		/* Capture error */ 
		while (1);
	}
	
	begin();
	versiondata = getFirmwareVersion();
	
	if(!versiondata) {
    while (1)
		{
			BlinkingLed(LED_RED, 10, 10, 2);
		}
  }
	LedCmd(LED_GREEN, Bit_SET); // Led ON
//   configure board to read RFID tags and cards
  SAMConfig();
// 	 printf("Waiting for an ISO14443A Card ...\r\n");
	Lock();
	
	while(1)
	{		
		if(timerStick)
		{
			timerStick=0;
			// Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
			// 'uid' will be populated with the UID, and uidLength will indicate
			// if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
			success = readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
			
			mavlinkSend();
			mavlinkReceive();
		}					
	}
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
