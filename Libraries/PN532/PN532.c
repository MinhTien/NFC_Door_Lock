// PN532 library by adafruit/ladyada
// MIT license

// authenticateBlock, readMemoryBlock, writeMemoryBlock contributed
// by Seeed Technology Inc (www.seeedstudio.com)

#include "PN532.h"
#include "global.h"
#include <string.h>

uint8_t pn532ack[] = {0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00};
uint8_t pn532response_firmwarevers[] = {0x00, 0xFF, 0x06, 0xFA, 0xD5, 0x03};

uint8_t pn532_packetbuffer[PN532_PACKBUFFSIZ];
uint8_t _ss, _clk, _mosi, _miso;

void delay_ns(uint32_t ns)
{
  uint32_t i;
  for(i=0;i<ns;i++)
  {
    __nop();
    __nop();
    __nop();
  }
}

void chipSellect(void)
{
	delay_us(10);
	GPIO_ResetBits(SPI1_NSS_PORT, SPI1_NSS_PIN);
	delay_us(10);
}

void chipDeSellect(void)
{
	delay_us(10);
	GPIO_SetBits(SPI1_NSS_PORT, SPI1_NSS_PIN);
	delay_us(10);
}

// /* Config SPI hardware */
// void PN532(uint8_t clk, uint8_t miso, uint8_t mosi, uint8_t ss) {
//     _clk = clk;
//     _miso = miso;
//     _mosi = mosi;
//     _ss = ss;

//     pinMode(_ss, OUTPUT);
//     pinMode(_clk, OUTPUT);
//     pinMode(_mosi, OUTPUT);
//     pinMode(_miso, INPUT);
// }

void begin() {
//  digitalWrite(_ss, LOW);
// 	chipSellect();
//   delay_ms(10);

//  not exactly sure why but we have to send a dummy command to get synced up
	pn532_packetbuffer[0] = PN532_FIRMWAREVERSION;
	sendCommandCheckAck(pn532_packetbuffer, 1, 10); // dummy
//  ignore response!
// 	chipDeSellect();
}

uint32_t getFirmwareVersion(void) {
    uint32_t response;

    pn532_packetbuffer[0] = PN532_FIRMWAREVERSION;

    if (! sendCommandCheckAck(pn532_packetbuffer, 1, 10))
        return 0;

    // read data packet
    readspidata(pn532_packetbuffer, 12);
    // check some basic stuff
    if (0 != strncmp((char *)pn532_packetbuffer, (char *)pn532response_firmwarevers, 6)) {
        return 0;
    }

    response = pn532_packetbuffer[6];
    response <<= 8;
    response |= pn532_packetbuffer[7];
    response <<= 8;
    response |= pn532_packetbuffer[8];
    response <<= 8;
    response |= pn532_packetbuffer[9];

    return response;
}

// default timeout of one second
uint8_t sendCommandCheckAck(uint8_t *cmd, uint8_t cmdlen, uint16_t timeout) {
    uint16_t timer = 0;

    // write the command
    spiwritecommand(cmd, cmdlen);

    // Wait for chip to say its ready!
    while (readspistatus() != PN532_SPI_READY) {
        if (timeout != 0) {
            timer+=10;
            if (timer > timeout)
                return 0; // changed
        }				
        delay_ms(1);
    }

    // read acknowledgement
    if (!spi_readack()) {
        return 0;
    }

    timer = 0;
    // Wait for chip to say its ready!
    while (readspistatus() != PN532_SPI_READY) {
        if (timeout != 0) {
            timer+=10;
            if (timer > timeout)
                return 0;
        }
        delay_ms(1);
    }

    return 0; // ack'd command
}

uint8_t SAMConfig(void) {
    pn532_packetbuffer[0] = PN532_SAMCONFIGURATION;
    pn532_packetbuffer[1] = 0x01; // normal mode;
    pn532_packetbuffer[2] = 0x14; // timeout 50ms * 20 = 1 second
    pn532_packetbuffer[3] = 0x01; // use IRQ pin!

    if (! sendCommandCheckAck(pn532_packetbuffer, 4, 10)) // dummy
        return 0;

    // read data packet
    readspidata(pn532_packetbuffer, 8);

    return  (pn532_packetbuffer[5] == 0x15);
}

uint32_t authenticateBlock(uint8_t cardnumber /*1 or 2*/,uint32_t cid /*Card NUID*/, uint8_t blockaddress /*0 to 63*/,uint8_t authtype/*Either KEY_A or KEY_B */, uint8_t * keys) {
		int iter;
		uint8_t i;  
		pn532_packetbuffer[0] = PN532_INDATAEXCHANGE;
    pn532_packetbuffer[1] = cardnumber;  // either card 1 or 2 (tested for card 1)
    if(authtype == KEY_A)
    {
        pn532_packetbuffer[2] = PN532_AUTH_WITH_KEYA;
    }
    else
    {
        pn532_packetbuffer[2] = PN532_AUTH_WITH_KEYB;
    }
    pn532_packetbuffer[3] = blockaddress; //This address can be 0-63 for MIFARE 1K card

    pn532_packetbuffer[4] = keys[0];
    pn532_packetbuffer[5] = keys[1];
    pn532_packetbuffer[6] = keys[2];
    pn532_packetbuffer[7] = keys[3];
    pn532_packetbuffer[8] = keys[4];
    pn532_packetbuffer[9] = keys[5];

    pn532_packetbuffer[10] = ((cid >> 24) & 0xFF);
    pn532_packetbuffer[11] = ((cid >> 16) & 0xFF);
    pn532_packetbuffer[12] = ((cid >> 8) & 0xFF);
    pn532_packetbuffer[13] = ((cid >> 0) & 0xFF);

    if (! sendCommandCheckAck(pn532_packetbuffer, 14, 10))
        return 0;

    // read data packet
    readspidata(pn532_packetbuffer, 2+6);

#ifdef PN532DEBUG
    for(iter=0;iter<14;iter++)
    {
        printf("%x ", pn532_packetbuffer[iter]);
    }
    printf("\r\n");
    // check some basic stuff

    printf("AUTH\r\n");
    for(i=0;i<2+6;i++)
    {
        printf("%x ", pn532_packetbuffer[i]);
    }
#endif

    if((pn532_packetbuffer[6] == 0x41) && (pn532_packetbuffer[7] == 0x00))
    {
  	return 1;
    }
    else
    {
  	return 0;
    }
}

uint32_t readMemoryBlock(uint8_t cardnumber /*1 or 2*/,uint8_t blockaddress /*0 to 63*/, uint8_t * block) {
		uint8_t i;
		pn532_packetbuffer[0] = PN532_INDATAEXCHANGE;
    pn532_packetbuffer[1] = cardnumber;  // either card 1 or 2 (tested for card 1)
    pn532_packetbuffer[2] = PN532_MIFARE_READ;
    pn532_packetbuffer[3] = blockaddress; //This address can be 0-63 for MIFARE 1K card

    if (! sendCommandCheckAck(pn532_packetbuffer, 4, 10))
        return 0;

    // read data packet
    readspidata(pn532_packetbuffer, 18+6);
    // check some basic stuff
#ifdef PN532DEBUG
    printf("READ\r\n");
#endif
    for(i=8;i<18+6;i++)    
		{
        block[i-8] = pn532_packetbuffer[i];
#ifdef PN532DEBUG
        printf("%x ", pn532_packetbuffer[i]);
#endif
    }
    if((pn532_packetbuffer[6] == 0x41) && (pn532_packetbuffer[7] == 0x00))
    {
  	return 1; //read successful
    }
    else
    {
  	return 0;
    }

}

//Do not write to Sector Trailer Block unless you know what you are doing.
uint32_t writeMemoryBlock(uint8_t cardnumber /*1 or 2*/,uint8_t blockaddress /*0 to 63*/, uint8_t * block) {
		uint8_t byte;  
		uint8_t i;
		pn532_packetbuffer[0] = PN532_INDATAEXCHANGE;
    pn532_packetbuffer[1] = cardnumber;  // either card 1 or 2 (tested for card 1)
    pn532_packetbuffer[2] = PN532_MIFARE_WRITE;
    pn532_packetbuffer[3] = blockaddress;

    for(byte=0; byte <16; byte++)
    {
        pn532_packetbuffer[4+byte] = block[byte];
    }

    if (! sendCommandCheckAck(pn532_packetbuffer, 20, 10))
        return 0;
    // read data packet
    readspidata(pn532_packetbuffer, 2+6);

#ifdef PN532DEBUG
    // check some basic stuff
    printf("WRITE\r\n");
    for(i=0;i<2+6;i++)
    {
        printf("%x ", pn532_packetbuffer[i]); 
    }
#endif

    if((pn532_packetbuffer[6] == 0x41) && (pn532_packetbuffer[7] == 0x00))
    {
  	return 1; //write successful
    }
    else
    {
  	return 0;
    }
}

uint32_t readPassiveTargetID(uint8_t cardbaudrate) {
    uint32_t cid;
		uint16_t sens_res;
		uint8_t i;
    pn532_packetbuffer[0] = PN532_INLISTPASSIVETARGET;
    pn532_packetbuffer[1] = 1;  // max 1 cards at once (we can set this to 2 later)
    pn532_packetbuffer[2] = cardbaudrate;

    if (! sendCommandCheckAck(pn532_packetbuffer, 3, 10))
        return 0x0;  // no cards read

    // read data packet
    readspidata(pn532_packetbuffer, 20);
    // check some basic stuff

    printf("Found %d tags\r\n", pn532_packetbuffer[7]);
    if (pn532_packetbuffer[7] != 1)
        return 0;
    
    sens_res = pn532_packetbuffer[9];
    sens_res <<= 8;
    sens_res |= pn532_packetbuffer[10];
    printf("Sens Response: %x\r\n", sens_res);
    printf("Sel Response: %x ", pn532_packetbuffer[11]);
    cid = 0;
    for (i=0; i< pn532_packetbuffer[12]; i++) {
        cid <<= 8;
        cid |= pn532_packetbuffer[13+i];
        printf("%x ", pn532_packetbuffer[13+i]);
    }

#ifdef PN532DEBUG
    printf("TargetID");
    for(i=0;i<20;i++)
    {
        printf("%x ",pn532_packetbuffer[i]);
    }
#endif  
    return cid;
}


/************** high level SPI */


uint8_t spi_readack(void) {
    uint8_t ackbuff[6];

    readspidata(ackbuff, 6);

    return (0 == strncmp((char *)ackbuff, (char *)pn532ack, 6));
}

/************** mid level SPI */

uint8_t readspistatus(void) {
	uint8_t x;
    chipSellect();
//     delay_ms(1);
    spiwrite(PN532_SPI_STATREAD);
    // read byte
    x = spiread();

    chipDeSellect();
    return x;
}

void readspidata(uint8_t* buff, uint8_t n) {
	uint8_t i;
    chipSellect();
//     delay_ms(1);
    spiwrite(PN532_SPI_DATAREAD);

#ifdef PN532DEBUG
    printf("Reading: \r\n");
#endif
    for (i=0; i<n; i++) {
//         delay_ms(1);
        buff[i] = spiread();
#ifdef PN532DEBUG
        printf(" 0x%x", buff[i]);
#endif
    }

#ifdef PN532DEBUG
    printf("\r\n");
#endif

    chipDeSellect();
}

void spiwritecommand(uint8_t* cmd, uint8_t cmdlen) {
    uint8_t checksum;
		uint8_t checksum_1;
		uint8_t cmdlen_1;
		uint8_t i;
    cmdlen++;

#ifdef PN532DEBUG
    printf("Sending: ");
#endif

    chipSellect();
//     delay_ms(1);     // or whatever the delay is for waking up the board
    spiwrite(PN532_SPI_DATAWRITE);

    checksum = PN532_PREAMBLE + PN532_PREAMBLE + PN532_STARTCODE2;
    spiwrite(PN532_PREAMBLE);
    spiwrite(PN532_PREAMBLE);
    spiwrite(PN532_STARTCODE2);

    spiwrite(cmdlen);
    cmdlen_1=~cmdlen + 1;
    spiwrite(cmdlen_1);

    spiwrite(PN532_HOSTTOPN532);
    checksum += PN532_HOSTTOPN532;

#ifdef PN532DEBUG
    printf(" 0x%x", PN532_PREAMBLE);
		printf(" 0x%x", PN532_PREAMBLE);
		printf(" 0x%x", PN532_STARTCODE2);
		printf(" 0x%x", cmdlen);
		printf(" 0x%x", cmdlen_1);
		printf(" 0x%x", PN532_HOSTTOPN532);
#endif

    for (i=0; i<cmdlen-1; i++) {
        spiwrite(cmd[i]);
        checksum += cmd[i];
#ifdef PN532DEBUG
        printf(" 0x%x", cmd[i]);
#endif
    }
    checksum_1=~checksum;
    spiwrite(checksum_1);
    spiwrite(PN532_POSTAMBLE);
    chipDeSellect();

#ifdef PN532DEBUG
		printf(" 0x%x", checksum_1);
		printf(" 0x%x\r\n", PN532_POSTAMBLE);
#endif
} 
/************** low level SPI */

uint8_t spiwrite(uint8_t c) {
		// Wait until it's 1, so we can write in
    while ((SPI1->SR & SPI_SR_TXE) == 0){}
    SPI1->DR = c;
    // wait until it's 1, so we can read out
    while ((SPI1->SR & SPI_SR_RXNE) == 0){}
    return SPI1->DR;   
}

uint8_t spiread(void) {
		// Wait until it's 1, so we can write in
    while ((SPI1->SR & SPI_SR_TXE) == 0){}
    SPI1->DR = 0;
    // wait until it's 1, so we can read out
    while ((SPI1->SR & SPI_SR_RXNE) == 0){}
    return SPI1->DR; 
}
