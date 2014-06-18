#include "stm32f10x.h"
#include "mavlink_types.h"
 
void mavlinkSend(void);
void handle_mavlink_message(mavlink_channel_t chan, mavlink_message_t* msg);
int  mavlinkReceive(void);
