// MESSAGE MAV_GMOTOR_TEST_PC2MCU PACKING

#define MAVLINK_MSG_ID_MAV_GMOTOR_TEST_PC2MCU 150

typedef struct __mavlink_mav_gmotor_test_pc2mcu_t
{
 float motor_speed; ///<  toc do dong co 
 uint16_t motor_power; ///<  power dong co 
 uint8_t board_address; ///<  dia chi board 
 uint8_t motor_address; ///<  dia chi dong co 
 uint8_t motor_dir; ///<  chieu dong co 
} mavlink_mav_gmotor_test_pc2mcu_t;

#define MAVLINK_MSG_ID_MAV_GMOTOR_TEST_PC2MCU_LEN 9
#define MAVLINK_MSG_ID_150_LEN 9



#define MAVLINK_MESSAGE_INFO_MAV_GMOTOR_TEST_PC2MCU { \
	"MAV_GMOTOR_TEST_PC2MCU", \
	5, \
	{  { "motor_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mav_gmotor_test_pc2mcu_t, motor_speed) }, \
         { "motor_power", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mav_gmotor_test_pc2mcu_t, motor_power) }, \
         { "board_address", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mav_gmotor_test_pc2mcu_t, board_address) }, \
         { "motor_address", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_mav_gmotor_test_pc2mcu_t, motor_address) }, \
         { "motor_dir", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_mav_gmotor_test_pc2mcu_t, motor_dir) }, \
         } \
}


/**
 * @brief Pack a mav_gmotor_test_pc2mcu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param board_address  dia chi board 
 * @param motor_address  dia chi dong co 
 * @param motor_dir  chieu dong co 
 * @param motor_power  power dong co 
 * @param motor_speed  toc do dong co 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_mav_gmotor_test_pc2mcu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t board_address, uint8_t motor_address, uint8_t motor_dir, uint16_t motor_power, float motor_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[9];
	_mav_put_float(buf, 0, motor_speed);
	_mav_put_uint16_t(buf, 4, motor_power);
	_mav_put_uint8_t(buf, 6, board_address);
	_mav_put_uint8_t(buf, 7, motor_address);
	_mav_put_uint8_t(buf, 8, motor_dir);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 9);
#else
	mavlink_mav_gmotor_test_pc2mcu_t packet;
	packet.motor_speed = motor_speed;
	packet.motor_power = motor_power;
	packet.board_address = board_address;
	packet.motor_address = motor_address;
	packet.motor_dir = motor_dir;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 9);
#endif

	msg->msgid = MAVLINK_MSG_ID_MAV_GMOTOR_TEST_PC2MCU;
	return mavlink_finalize_message(msg, system_id, component_id, 9, 27);
}

/**
 * @brief Pack a mav_gmotor_test_pc2mcu message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param board_address  dia chi board 
 * @param motor_address  dia chi dong co 
 * @param motor_dir  chieu dong co 
 * @param motor_power  power dong co 
 * @param motor_speed  toc do dong co 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_mav_gmotor_test_pc2mcu_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t board_address,uint8_t motor_address,uint8_t motor_dir,uint16_t motor_power,float motor_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[9];
	_mav_put_float(buf, 0, motor_speed);
	_mav_put_uint16_t(buf, 4, motor_power);
	_mav_put_uint8_t(buf, 6, board_address);
	_mav_put_uint8_t(buf, 7, motor_address);
	_mav_put_uint8_t(buf, 8, motor_dir);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 9);
#else
	mavlink_mav_gmotor_test_pc2mcu_t packet;
	packet.motor_speed = motor_speed;
	packet.motor_power = motor_power;
	packet.board_address = board_address;
	packet.motor_address = motor_address;
	packet.motor_dir = motor_dir;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 9);
#endif

	msg->msgid = MAVLINK_MSG_ID_MAV_GMOTOR_TEST_PC2MCU;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 9, 27);
}

/**
 * @brief Encode a mav_gmotor_test_pc2mcu struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mav_gmotor_test_pc2mcu C-struct to read the message contents from
 */
static __inline uint16_t mavlink_msg_mav_gmotor_test_pc2mcu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mav_gmotor_test_pc2mcu_t* mav_gmotor_test_pc2mcu)
{
	return mavlink_msg_mav_gmotor_test_pc2mcu_pack(system_id, component_id, msg, mav_gmotor_test_pc2mcu->board_address, mav_gmotor_test_pc2mcu->motor_address, mav_gmotor_test_pc2mcu->motor_dir, mav_gmotor_test_pc2mcu->motor_power, mav_gmotor_test_pc2mcu->motor_speed);
}

/**
 * @brief Send a mav_gmotor_test_pc2mcu message
 * @param chan MAVLink channel to send the message
 *
 * @param board_address  dia chi board 
 * @param motor_address  dia chi dong co 
 * @param motor_dir  chieu dong co 
 * @param motor_power  power dong co 
 * @param motor_speed  toc do dong co 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static __inline void mavlink_msg_mav_gmotor_test_pc2mcu_send(mavlink_channel_t chan, uint8_t board_address, uint8_t motor_address, uint8_t motor_dir, uint16_t motor_power, float motor_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[9];
	_mav_put_float(buf, 0, motor_speed);
	_mav_put_uint16_t(buf, 4, motor_power);
	_mav_put_uint8_t(buf, 6, board_address);
	_mav_put_uint8_t(buf, 7, motor_address);
	_mav_put_uint8_t(buf, 8, motor_dir);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAV_GMOTOR_TEST_PC2MCU, buf, 9, 27);
#else
	mavlink_mav_gmotor_test_pc2mcu_t packet;
	packet.motor_speed = motor_speed;
	packet.motor_power = motor_power;
	packet.board_address = board_address;
	packet.motor_address = motor_address;
	packet.motor_dir = motor_dir;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAV_GMOTOR_TEST_PC2MCU, (const char *)&packet, 9, 27);
#endif
}

#endif

// MESSAGE MAV_GMOTOR_TEST_PC2MCU UNPACKING


/**
 * @brief Get field board_address from mav_gmotor_test_pc2mcu message
 *
 * @return  dia chi board 
 */
static __inline uint8_t mavlink_msg_mav_gmotor_test_pc2mcu_get_board_address(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field motor_address from mav_gmotor_test_pc2mcu message
 *
 * @return  dia chi dong co 
 */
static __inline uint8_t mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_address(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field motor_dir from mav_gmotor_test_pc2mcu message
 *
 * @return  chieu dong co 
 */
static __inline uint8_t mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_dir(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field motor_power from mav_gmotor_test_pc2mcu message
 *
 * @return  power dong co 
 */
static __inline uint16_t mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_power(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field motor_speed from mav_gmotor_test_pc2mcu message
 *
 * @return  toc do dong co 
 */
static __inline float mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_speed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a mav_gmotor_test_pc2mcu message into a struct
 *
 * @param msg The message to decode
 * @param mav_gmotor_test_pc2mcu C-struct to decode the message contents into
 */
static __inline void mavlink_msg_mav_gmotor_test_pc2mcu_decode(const mavlink_message_t* msg, mavlink_mav_gmotor_test_pc2mcu_t* mav_gmotor_test_pc2mcu)
{
#if MAVLINK_NEED_BYTE_SWAP
	mav_gmotor_test_pc2mcu->motor_speed = mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_speed(msg);
	mav_gmotor_test_pc2mcu->motor_power = mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_power(msg);
	mav_gmotor_test_pc2mcu->board_address = mavlink_msg_mav_gmotor_test_pc2mcu_get_board_address(msg);
	mav_gmotor_test_pc2mcu->motor_address = mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_address(msg);
	mav_gmotor_test_pc2mcu->motor_dir = mavlink_msg_mav_gmotor_test_pc2mcu_get_motor_dir(msg);
#else
	memcpy(mav_gmotor_test_pc2mcu, _MAV_PAYLOAD(msg), 9);
#endif
}
