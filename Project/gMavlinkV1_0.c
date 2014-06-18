#include "gMavlinkV1_0.h"
#include "global.h"
#include "../Libraries/mavlink/v1.0/nfc/mavlink.h"

extern uint8_t success;
extern uint8_t uidLength;
extern uint8_t uid[];
extern uint8_t mav_tx_buffer[];
extern uint8_t mav_rx_buffer[];
extern uint8_t mav_rx_tmp[];
extern gMav_t gMav;
	
mavlink_message_t msg;
mavlink_status_t status;

uint8_t len;
uint8_t buffer[255];		   //without number elements of array the program running crazy.

void mavlinkSend(void)
{ 
  if(gMav.sendFinish)
  { 
		 if(gMav.sendType==gMAV_SEND_MSG)
     {
				switch(gMav.msgIndex)
			  {
						case 0:				
							mavlink_msg_heartbeat_pack(SYSTEM_ID, MAV_COMP_ID_NFC_READER, &msg, MAV_TYPE_FIXED_WING, MAV_AUTOPILOT_GENERIC, MAV_MODE_AUTO_ARMED, 0, MAV_STATE_ACTIVE);
							len = mavlink_msg_to_send_buffer(buffer, &msg);
							_mavlink_send_uart(MAVLINK_COMM_0, buffer, len); 							
							gMav.msgIndex=1;
						  break; 
						case 1:
							if(success)
							{
								if(uidLength == 4) // Mifare Classic Card
								{
									mavlink_msg_mifare_classic_uid_pack(SYSTEM_ID, MAV_COMP_ID_NFC_READER, &msg, uid[0], uid[1], uid[2], uid[3]);
									len = mavlink_msg_to_send_buffer(buffer, &msg);
								  _mavlink_send_uart(MAVLINK_COMM_0, buffer, len); 
								}
								else if(uidLength == 7) // Mifare Classic Card
								{
									mavlink_msg_mifare_ultralight_uid_pack(SYSTEM_ID, MAV_COMP_ID_NFC_READER, &msg, uid[0], uid[1], uid[2], uid[3], uid[4], uid[5], uid[6]);
									len = mavlink_msg_to_send_buffer(buffer, &msg);
								  _mavlink_send_uart(MAVLINK_COMM_0, buffer, len); 
								}
							}
							gMav.msgIndex=0;
						  break;		
						default:
							break;
	       }
			}
	}
}
 
void handle_mavlink_message(mavlink_channel_t chan, mavlink_message_t* msg)
{
	switch (msg->msgid)
	{
		case MAVLINK_MSG_ID_GENERAL_MSG:
		{
// 			recBoard_address = mavlink_msg_mav_gmotor_test_pc2mcu_get_board_address(msg); // get board address from pc
			break;
		}
		case MAVLINK_MSG_ID_LOCK_CONTROL:
		{
			break;
		}			
		default:
			break;
	}
}

int mavlinkReceive(void)
{
	  int i, k, numc;
	  static int data_counter_1=0;
	  int data_counter;
	
		data_counter=MAV_RX_BUFF_SIZE-DMA_GetCurrDataCounter(DMA1_Channel5);
	
		numc=data_counter-data_counter_1;
		if (numc<0) numc=MAV_RX_BUFF_SIZE+numc;
		if (numc)
		{ 	   
		  for (i=0;i<numc;i++)
		  {  
				k=i+data_counter_1;
		    if (k>=MAV_RX_BUFF_SIZE)   k-=MAV_RX_BUFF_SIZE;
		    mav_rx_tmp[i]=mav_rx_buffer[k] ;
		  }
			data_counter_1=data_counter;

			for(i = 0; i < numc; i++)	// Process bytes received
			{
				if(mavlink_parse_char(MAVLINK_COMM_0,mav_rx_tmp[i],&msg,&status))
				{
					handle_mavlink_message(MAVLINK_COMM_0, &msg);			
		    }
			}
		}
		return numc;
}
