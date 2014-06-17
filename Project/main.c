
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include "Adafruit_PN532.h"

/* Private function prototypes -----------------------------------------------*/
uint8_t keys[]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
uint8_t writeBuffer[16];
uint8_t written=0;
uint8_t block[16];

int main(void)
{
	uint8_t success=0;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength=0;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  uint8_t keya[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
  uint8_t data_1[16];
	uint8_t data_2[32];
	uint16_t loopCount=0;
	uint32_t versiondata=0;

	RCC_Configuration();
	delay_ms(1);
	GPIO_Configuration();
	delay_ms(1);
	USART_Configuration();
	delay_ms(1);
	printf("NFC DEMO...\r\n");
// 	SPI_Configuration();
	delay_ms(1);
// 	EXTI_Configuration();
// 	delay_ms(1);
// 	NVIC_Configuration();
	TIM_Configuration();
 	delay_ms(1);
	
// 	Led(Bit_SET); // Led OFF
	begin();
	versiondata = getFirmwareVersion();
	printf("Data version %d\r\n", versiondata);
	
	if(!versiondata) {
    printf("Didn't find PN53x board\r\n");
    while (1); // halt
  }
	
// Got ok data, print it out!
  printf("Found chip PN5%x\r\n", (versiondata>>24) & 0xFF);
  printf("Firmware ver. %d", (versiondata>>16) & 0xFF);  
  printf(".%d\r\n", (versiondata>>8) & 0xFF);
  printf("Supports %x\r\n", versiondata & 0xFF);
  
  // configure board to read RFID tags and cards
  SAMConfig();
	printf("Waiting for an ISO14443A Card ...\r\n");
	
	while (1)
	{
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  
  if(success) {
    // Display some basic information about the card
    printf("Found an ISO14443A card UID Length: %d bytes\r\n", uidLength);
    printf("UID Value: ");
    PrintHex(uid, uidLength);
    printf("\r\n");
    
    if (uidLength == 4)
    {
			/* Added code to control output */
			if((uid[0] == 0xA4 && uid[1] == 0xB1 && uid[2] == 0xAF && uid[3] == 0xB4) || (uid[0] == 0x4E && uid[1] == 0x01 && uid[2] == 0x02 && uid[3] == 0x03))
			{
				GPIO_SetBits(LED_PORT, LED_PIN);
// 				GPIO_SetBits(RELAY_A_PORT, RELAY_A_PIN);
				TIM_SetCompare4(TIM2, 2900); // 2 ms				
				delay_ms(100);
				TIM_SetCompare4(TIM2, 500); // 2 ms
				delay_ms(100);
			}
			else
			{
				GPIO_ResetBits(LED_PORT, LED_PIN);
// 				GPIO_ResetBits(RELAY_A_PORT, RELAY_A_PIN);
				TIM_SetCompare4(TIM2, 500); // 2 ms
				delay_ms(100);
			}
						
      // We probably have a Mifare Classic card ... 
      printf("Seems to be a Mifare Classic card (4 byte UID)\r\n");
	  
      // Now we need to try to authenticate it for read/write access
      // Try with the factory default KeyA: 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF
      printf("Trying to authenticate block 4 with default KEYA value\r\n");
      
	  // Start with block 4 (the first block of sector 1) since sector 0
	  // contains the manufacturer data and it's probably better just
	  // to leave it alone unless you know what you're doing
      success = mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);
	  
      if(success)
      {
        printf("Sector 1 (Blocks 4..7) has been authenticated\r\n");
        
		
        // If you want to write something to block 4 to test with, uncomment
				// the following line and this text should be read back in a minute
        // data = { 'a', 'd', 'a', 'f', 'r', 'u', 'i', 't', '.', 'c', 'o', 'm', 0, 0, 0, 0};
        // success = nfc.mifareclassic_WriteDataBlock (4, data);

        // Try to read the contents of block 4
        success = mifareclassic_ReadDataBlock(4, data_1);
		
        if (success)
        {
          // Data seems to have been read ... spit it out
          printf("Reading Block 4:\r\n");
          PrintHexChar(data_1, 16);
          printf("\r\n");
		  
          // Wait a bit before reading the card again
          delay_ms(50);
        }
        else
        {
          printf("Ooops ... unable to read the requested block.  Try another key?\r\n");
        }
      }
      else
      {
        printf("Ooops ... authentication failed: Try another key?\r\n");
      }
    }
    
    if (uidLength == 7)
    {
      // We probably have a Mifare Ultralight card ...
      printf("Seems to be a Mifare Ultralight tag (7 byte UID)\r\n");
	  
      // Try to read the first general-purpose user page (#4)
      printf("Reading page 4\r\n");
      
      success = mifareultralight_ReadPage (4, data_2);
      if (success)
      {
        // Data seems to have been read ... spit it out
        PrintHexChar(data_2, 4);
        printf("\r\n");
		
        // Wait a bit before reading the card again
        delay_ms(50);
      }
      else
      {
        printf("Ooops ... unable to read the requested page!?\r\n");
      }
    }
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
