
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "global.h"
#include "PN532.h"
#include <stdlib.h>
#include <stdio.h>

/* Private function prototypes -----------------------------------------------*/
uint8_t keys[]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
uint8_t writeBuffer[16];
uint8_t written=0;
uint8_t block[16];

int main(void)
{
	uint16_t loopCount=0;
	uint32_t id;
	uint32_t versiondata;
	uint8_t ii;
	uint8_t i;
	RCC_Configuration();
	delay_ms(1);
	GPIO_Configuration();
	delay_ms(1);
	USART_Configuration();
	delay_ms(1);
	printf("NFC DEMO...\r\n");
	SPI_Configuration();
	delay_ms(1);
// 	EXTI_Configuration();
// 	delay_ms(1);
// 	NVIC_Configuration();
// 	delay_ms(1);
	
	Led(Bit_SET); // Led OFF
	begin();
	versiondata = getFirmwareVersion();
	printf("Data version %d\r\n", versiondata);
	
	if(!versiondata) {
    printf("Didn't find PN53x board\r\n");
//     while (1); // halt
  }
	
// Got ok data, print it out!
  printf("Found chip PN5 %x\r\n", (versiondata>>24) & 0xFF);
  printf("Firmware ver. %d", (versiondata>>16) & 0xFF);  
  printf(".%d\r\n", (versiondata>>8) & 0xFF);
  printf("Supports %x\r\n", versiondata & 0xFF);
  
  // configure board to read RFID tags and cards
  SAMConfig();
	printf("SAM Config\r\n");
	
	while (1)
	{
		loopCount++;
		if(loopCount>=10000)
		{
			loopCount=0;
			
			// look for MiFare type cards
			id = readPassiveTargetID(PN532_MIFARE_ISO14443A);

			if (id != 0) 
			{
				printf("Read card #%d\r\n", id);
				
				for(ii=0;ii<16;ii++)
				{ 
					 writeBuffer[ii]=ii; //Fill buffer with 0,1,2....F
				}
				if(authenticateBlock(1, id ,0x08,KEY_A,keys)) //authenticate block 0x08
				{
					//if authentication successful

					if(written == 0) //Not written
					{
						written = writeMemoryBlock(1,0x08,writeBuffer); // Write writeBuffer[] to block 0x08
						if(written) printf("Write Successful\r\n");   
						else 				printf("Write Error\r\n"); 
					}
				 

					//read memory block 0x08
					if(readMemoryBlock(1,0x08,block))
					{
						printf("Read block 0x08:\r\n");   
						//if read operation is successful
						for(i=0;i<16;i++)
						{
							//print memory block
							printf("%x ", block[i]);
						}
						printf("\r\n");
					}
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
