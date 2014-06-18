// MESSAGE LOCK_CONTROL PACKING

#define MAVLINK_MSG_ID_LOCK_CONTROL 153

typedef struct __mavlink_lock_control_t
{
 uint16_t address; ///< board address
 uint8_t command; ///< lock command: LOCK or UNLOCK
} mavlink_lock_control_t;

#define MAVLINK_MSG_ID_LOCK_CONTROL_LEN 3
#define MAVLINK_MSG_ID_153_LEN 3



#define MAVLINK_MESSAGE_INFO_LOCK_CONTROL { \
	"LOCK_CONTROL", \
	2, \
	{  { "address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_lock_control_t, address) }, \
         { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_lock_control_t, command) }, \
         } \
}


/**
 * @brief Pack a lock_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param address board address
 * @param command lock command: LOCK or UNLOCK
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_lock_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t address, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, address);
	_mav_put_uint8_t(buf, 2, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 3);
#else
	mavlink_lock_control_t packet;
	packet.address = address;
	packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_LOCK_CONTROL;
	return mavlink_finalize_message(msg, system_id, component_id, 3, 113);
}

/**
 * @brief Pack a lock_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param address board address
 * @param command lock command: LOCK or UNLOCK
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_lock_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t address,uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, address);
	_mav_put_uint8_t(buf, 2, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 3);
#else
	mavlink_lock_control_t packet;
	packet.address = address;
	packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_LOCK_CONTROL;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 3, 113);
}

/**
 * @brief Encode a lock_control struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lock_control C-struct to read the message contents from
 */
static __inline uint16_t mavlink_msg_lock_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lock_control_t* lock_control)
{
	return mavlink_msg_lock_control_pack(system_id, component_id, msg, lock_control->address, lock_control->command);
}

/**
 * @brief Send a lock_control message
 * @param chan MAVLink channel to send the message
 *
 * @param address board address
 * @param command lock command: LOCK or UNLOCK
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static __inline void mavlink_msg_lock_control_send(mavlink_channel_t chan, uint16_t address, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, address);
	_mav_put_uint8_t(buf, 2, command);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCK_CONTROL, buf, 3, 113);
#else
	mavlink_lock_control_t packet;
	packet.address = address;
	packet.command = command;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCK_CONTROL, (const char *)&packet, 3, 113);
#endif
}

#endif

// MESSAGE LOCK_CONTROL UNPACKING


/**
 * @brief Get field address from lock_control message
 *
 * @return board address
 */
static __inline uint16_t mavlink_msg_lock_control_get_address(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field command from lock_control message
 *
 * @return lock command: LOCK or UNLOCK
 */
static __inline uint8_t mavlink_msg_lock_control_get_command(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a lock_control message into a struct
 *
 * @param msg The message to decode
 * @param lock_control C-struct to decode the message contents into
 */
static __inline void mavlink_msg_lock_control_decode(const mavlink_message_t* msg, mavlink_lock_control_t* lock_control)
{
#if MAVLINK_NEED_BYTE_SWAP
	lock_control->address = mavlink_msg_lock_control_get_address(msg);
	lock_control->command = mavlink_msg_lock_control_get_command(msg);
#else
	memcpy(lock_control, _MAV_PAYLOAD(msg), 3);
#endif
}
