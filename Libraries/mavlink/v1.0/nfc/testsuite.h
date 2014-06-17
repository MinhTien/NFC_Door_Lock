/** @file
 *	@brief MAVLink comm protocol testsuite generated from nfc.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef NFC_TESTSUITE_H
#define NFC_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_nfc(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_nfc(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_general_msg(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_general_msg_t packet_in = {
		5,
	72,
	139,
	206,
	17,
	84,
	151,
	218,
	};
	mavlink_general_msg_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.value0 = packet_in.value0;
        	packet1.value1 = packet_in.value1;
        	packet1.value2 = packet_in.value2;
        	packet1.value3 = packet_in.value3;
        	packet1.value4 = packet_in.value4;
        	packet1.value5 = packet_in.value5;
        	packet1.value6 = packet_in.value6;
        	packet1.value7 = packet_in.value7;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_general_msg_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_general_msg_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_general_msg_pack(system_id, component_id, &msg , packet1.value0 , packet1.value1 , packet1.value2 , packet1.value3 , packet1.value4 , packet1.value5 , packet1.value6 , packet1.value7 );
	mavlink_msg_general_msg_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_general_msg_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.value0 , packet1.value1 , packet1.value2 , packet1.value3 , packet1.value4 , packet1.value5 , packet1.value6 , packet1.value7 );
	mavlink_msg_general_msg_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_general_msg_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_general_msg_send(MAVLINK_COMM_1 , packet1.value0 , packet1.value1 , packet1.value2 , packet1.value3 , packet1.value4 , packet1.value5 , packet1.value6 , packet1.value7 );
	mavlink_msg_general_msg_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_mifare_classic_uid(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_mifare_classic_uid_t packet_in = {
		5,
	72,
	139,
	206,
	};
	mavlink_mifare_classic_uid_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.byte0 = packet_in.byte0;
        	packet1.byte1 = packet_in.byte1;
        	packet1.byte2 = packet_in.byte2;
        	packet1.byte3 = packet_in.byte3;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_classic_uid_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_mifare_classic_uid_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_classic_uid_pack(system_id, component_id, &msg , packet1.byte0 , packet1.byte1 , packet1.byte2 , packet1.byte3 );
	mavlink_msg_mifare_classic_uid_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_classic_uid_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.byte0 , packet1.byte1 , packet1.byte2 , packet1.byte3 );
	mavlink_msg_mifare_classic_uid_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_mifare_classic_uid_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_classic_uid_send(MAVLINK_COMM_1 , packet1.byte0 , packet1.byte1 , packet1.byte2 , packet1.byte3 );
	mavlink_msg_mifare_classic_uid_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_mifare_ultralight_uid(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_mifare_ultralight_uid_t packet_in = {
		5,
	72,
	139,
	206,
	17,
	84,
	151,
	};
	mavlink_mifare_ultralight_uid_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.byte0 = packet_in.byte0;
        	packet1.byte1 = packet_in.byte1;
        	packet1.byte2 = packet_in.byte2;
        	packet1.byte3 = packet_in.byte3;
        	packet1.byte4 = packet_in.byte4;
        	packet1.byte5 = packet_in.byte5;
        	packet1.byte6 = packet_in.byte6;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_ultralight_uid_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_mifare_ultralight_uid_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_ultralight_uid_pack(system_id, component_id, &msg , packet1.byte0 , packet1.byte1 , packet1.byte2 , packet1.byte3 , packet1.byte4 , packet1.byte5 , packet1.byte6 );
	mavlink_msg_mifare_ultralight_uid_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_ultralight_uid_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.byte0 , packet1.byte1 , packet1.byte2 , packet1.byte3 , packet1.byte4 , packet1.byte5 , packet1.byte6 );
	mavlink_msg_mifare_ultralight_uid_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_mifare_ultralight_uid_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mifare_ultralight_uid_send(MAVLINK_COMM_1 , packet1.byte0 , packet1.byte1 , packet1.byte2 , packet1.byte3 , packet1.byte4 , packet1.byte5 , packet1.byte6 );
	mavlink_msg_mifare_ultralight_uid_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_lock_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_lock_control_t packet_in = {
		5,
	};
	mavlink_lock_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.command = packet_in.command;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_lock_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_control_pack(system_id, component_id, &msg , packet1.command );
	mavlink_msg_lock_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.command );
	mavlink_msg_lock_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_lock_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_control_send(MAVLINK_COMM_1 , packet1.command );
	mavlink_msg_lock_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_lock_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_lock_status_t packet_in = {
		5,
	};
	mavlink_lock_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.lockstatus = packet_in.lockstatus;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_lock_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_status_pack(system_id, component_id, &msg , packet1.lockstatus );
	mavlink_msg_lock_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lockstatus );
	mavlink_msg_lock_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_lock_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_lock_status_send(MAVLINK_COMM_1 , packet1.lockstatus );
	mavlink_msg_lock_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_nfc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_general_msg(system_id, component_id, last_msg);
	mavlink_test_mifare_classic_uid(system_id, component_id, last_msg);
	mavlink_test_mifare_ultralight_uid(system_id, component_id, last_msg);
	mavlink_test_lock_control(system_id, component_id, last_msg);
	mavlink_test_lock_status(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // NFC_TESTSUITE_H
