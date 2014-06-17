// MESSAGE GENERAL_MSG PACKING

#define MAVLINK_MSG_ID_GENERAL_MSG 150

typedef struct __mavlink_general_msg_t
{
 uint8_t value0; ///< value0
 uint8_t value1; ///< value1
 uint8_t value2; ///< value2
 uint8_t value3; ///< value3
 uint8_t value4; ///< value4
 uint8_t value5; ///< value5
 uint8_t value6; ///< value6
 uint8_t value7; ///< value7
} mavlink_general_msg_t;

#define MAVLINK_MSG_ID_GENERAL_MSG_LEN 8
#define MAVLINK_MSG_ID_150_LEN 8



#define MAVLINK_MESSAGE_INFO_GENERAL_MSG { \
	"GENERAL_MSG", \
	8, \
	{  { "value0", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_general_msg_t, value0) }, \
         { "value1", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_general_msg_t, value1) }, \
         { "value2", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_general_msg_t, value2) }, \
         { "value3", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_general_msg_t, value3) }, \
         { "value4", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_general_msg_t, value4) }, \
         { "value5", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_general_msg_t, value5) }, \
         { "value6", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_general_msg_t, value6) }, \
         { "value7", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_general_msg_t, value7) }, \
         } \
}


/**
 * @brief Pack a general_msg message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param value0 value0
 * @param value1 value1
 * @param value2 value2
 * @param value3 value3
 * @param value4 value4
 * @param value5 value5
 * @param value6 value6
 * @param value7 value7
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_general_msg_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t value0, uint8_t value1, uint8_t value2, uint8_t value3, uint8_t value4, uint8_t value5, uint8_t value6, uint8_t value7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint8_t(buf, 0, value0);
	_mav_put_uint8_t(buf, 1, value1);
	_mav_put_uint8_t(buf, 2, value2);
	_mav_put_uint8_t(buf, 3, value3);
	_mav_put_uint8_t(buf, 4, value4);
	_mav_put_uint8_t(buf, 5, value5);
	_mav_put_uint8_t(buf, 6, value6);
	_mav_put_uint8_t(buf, 7, value7);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_general_msg_t packet;
	packet.value0 = value0;
	packet.value1 = value1;
	packet.value2 = value2;
	packet.value3 = value3;
	packet.value4 = value4;
	packet.value5 = value5;
	packet.value6 = value6;
	packet.value7 = value7;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_GENERAL_MSG;
	return mavlink_finalize_message(msg, system_id, component_id, 8, 185);
}

/**
 * @brief Pack a general_msg message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param value0 value0
 * @param value1 value1
 * @param value2 value2
 * @param value3 value3
 * @param value4 value4
 * @param value5 value5
 * @param value6 value6
 * @param value7 value7
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_general_msg_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t value0,uint8_t value1,uint8_t value2,uint8_t value3,uint8_t value4,uint8_t value5,uint8_t value6,uint8_t value7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint8_t(buf, 0, value0);
	_mav_put_uint8_t(buf, 1, value1);
	_mav_put_uint8_t(buf, 2, value2);
	_mav_put_uint8_t(buf, 3, value3);
	_mav_put_uint8_t(buf, 4, value4);
	_mav_put_uint8_t(buf, 5, value5);
	_mav_put_uint8_t(buf, 6, value6);
	_mav_put_uint8_t(buf, 7, value7);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_general_msg_t packet;
	packet.value0 = value0;
	packet.value1 = value1;
	packet.value2 = value2;
	packet.value3 = value3;
	packet.value4 = value4;
	packet.value5 = value5;
	packet.value6 = value6;
	packet.value7 = value7;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_GENERAL_MSG;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 8, 185);
}

/**
 * @brief Encode a general_msg struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param general_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_general_msg_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_general_msg_t* general_msg)
{
	return mavlink_msg_general_msg_pack(system_id, component_id, msg, general_msg->value0, general_msg->value1, general_msg->value2, general_msg->value3, general_msg->value4, general_msg->value5, general_msg->value6, general_msg->value7);
}

/**
 * @brief Send a general_msg message
 * @param chan MAVLink channel to send the message
 *
 * @param value0 value0
 * @param value1 value1
 * @param value2 value2
 * @param value3 value3
 * @param value4 value4
 * @param value5 value5
 * @param value6 value6
 * @param value7 value7
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_general_msg_send(mavlink_channel_t chan, uint8_t value0, uint8_t value1, uint8_t value2, uint8_t value3, uint8_t value4, uint8_t value5, uint8_t value6, uint8_t value7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint8_t(buf, 0, value0);
	_mav_put_uint8_t(buf, 1, value1);
	_mav_put_uint8_t(buf, 2, value2);
	_mav_put_uint8_t(buf, 3, value3);
	_mav_put_uint8_t(buf, 4, value4);
	_mav_put_uint8_t(buf, 5, value5);
	_mav_put_uint8_t(buf, 6, value6);
	_mav_put_uint8_t(buf, 7, value7);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GENERAL_MSG, buf, 8, 185);
#else
	mavlink_general_msg_t packet;
	packet.value0 = value0;
	packet.value1 = value1;
	packet.value2 = value2;
	packet.value3 = value3;
	packet.value4 = value4;
	packet.value5 = value5;
	packet.value6 = value6;
	packet.value7 = value7;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GENERAL_MSG, (const char *)&packet, 8, 185);
#endif
}

#endif

// MESSAGE GENERAL_MSG UNPACKING


/**
 * @brief Get field value0 from general_msg message
 *
 * @return value0
 */
static inline uint8_t mavlink_msg_general_msg_get_value0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field value1 from general_msg message
 *
 * @return value1
 */
static inline uint8_t mavlink_msg_general_msg_get_value1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field value2 from general_msg message
 *
 * @return value2
 */
static inline uint8_t mavlink_msg_general_msg_get_value2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field value3 from general_msg message
 *
 * @return value3
 */
static inline uint8_t mavlink_msg_general_msg_get_value3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field value4 from general_msg message
 *
 * @return value4
 */
static inline uint8_t mavlink_msg_general_msg_get_value4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field value5 from general_msg message
 *
 * @return value5
 */
static inline uint8_t mavlink_msg_general_msg_get_value5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field value6 from general_msg message
 *
 * @return value6
 */
static inline uint8_t mavlink_msg_general_msg_get_value6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field value7 from general_msg message
 *
 * @return value7
 */
static inline uint8_t mavlink_msg_general_msg_get_value7(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Decode a general_msg message into a struct
 *
 * @param msg The message to decode
 * @param general_msg C-struct to decode the message contents into
 */
static inline void mavlink_msg_general_msg_decode(const mavlink_message_t* msg, mavlink_general_msg_t* general_msg)
{
#if MAVLINK_NEED_BYTE_SWAP
	general_msg->value0 = mavlink_msg_general_msg_get_value0(msg);
	general_msg->value1 = mavlink_msg_general_msg_get_value1(msg);
	general_msg->value2 = mavlink_msg_general_msg_get_value2(msg);
	general_msg->value3 = mavlink_msg_general_msg_get_value3(msg);
	general_msg->value4 = mavlink_msg_general_msg_get_value4(msg);
	general_msg->value5 = mavlink_msg_general_msg_get_value5(msg);
	general_msg->value6 = mavlink_msg_general_msg_get_value6(msg);
	general_msg->value7 = mavlink_msg_general_msg_get_value7(msg);
#else
	memcpy(general_msg, _MAV_PAYLOAD(msg), 8);
#endif
}
