/** @file
 *	@brief MAVLink comm protocol testsuite generated from mavGmotorTesterSC.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef MAVGMOTORTESTERSC_TESTSUITE_H
#define MAVGMOTORTESTERSC_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_mavGmotorTesterSC(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_mavGmotorTesterSC(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_mav_gmotor_test_pc2mcu(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_mav_gmotor_test_pc2mcu_t packet_in = {
		17.0,
	17443,
	151,
	218,
	29,
	};
	mavlink_mav_gmotor_test_pc2mcu_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.motor_speed = packet_in.motor_speed;
        	packet1.motor_power = packet_in.motor_power;
        	packet1.board_address = packet_in.board_address;
        	packet1.motor_address = packet_in.motor_address;
        	packet1.motor_dir = packet_in.motor_dir;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_pc2mcu_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_mav_gmotor_test_pc2mcu_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_pc2mcu_pack(system_id, component_id, &msg , packet1.board_address , packet1.motor_address , packet1.motor_dir , packet1.motor_power , packet1.motor_speed );
	mavlink_msg_mav_gmotor_test_pc2mcu_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_pc2mcu_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.board_address , packet1.motor_address , packet1.motor_dir , packet1.motor_power , packet1.motor_speed );
	mavlink_msg_mav_gmotor_test_pc2mcu_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_mav_gmotor_test_pc2mcu_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_pc2mcu_send(MAVLINK_COMM_1 , packet1.board_address , packet1.motor_address , packet1.motor_dir , packet1.motor_power , packet1.motor_speed );
	mavlink_msg_mav_gmotor_test_pc2mcu_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_mav_gmotor_test_mcu2pc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_mav_gmotor_test_mcu2pc_t packet_in = {
		17.0,
	17,
	84,
	151,
	};
	mavlink_mav_gmotor_test_mcu2pc_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.motor_temp = packet_in.motor_temp;
        	packet1.board_address = packet_in.board_address;
        	packet1.motor_address = packet_in.motor_address;
        	packet1.motor_status = packet_in.motor_status;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_mcu2pc_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_mav_gmotor_test_mcu2pc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_mcu2pc_pack(system_id, component_id, &msg , packet1.board_address , packet1.motor_address , packet1.motor_status , packet1.motor_temp );
	mavlink_msg_mav_gmotor_test_mcu2pc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_mcu2pc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.board_address , packet1.motor_address , packet1.motor_status , packet1.motor_temp );
	mavlink_msg_mav_gmotor_test_mcu2pc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_mav_gmotor_test_mcu2pc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_mav_gmotor_test_mcu2pc_send(MAVLINK_COMM_1 , packet1.board_address , packet1.motor_address , packet1.motor_status , packet1.motor_temp );
	mavlink_msg_mav_gmotor_test_mcu2pc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_mavGmotorTesterSC(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_mav_gmotor_test_pc2mcu(system_id, component_id, last_msg);
	mavlink_test_mav_gmotor_test_mcu2pc(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVGMOTORTESTERSC_TESTSUITE_H
