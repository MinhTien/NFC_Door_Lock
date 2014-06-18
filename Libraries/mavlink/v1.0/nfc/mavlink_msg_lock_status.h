// MESSAGE LOCK_STATUS PACKING

#define MAVLINK_MSG_ID_LOCK_STATUS 154

typedef struct __mavlink_lock_status_t
{
 uint16_t address; ///< board address
 uint8_t lockstatus; ///< lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
} mavlink_lock_status_t;

#define MAVLINK_MSG_ID_LOCK_STATUS_LEN 3
#define MAVLINK_MSG_ID_154_LEN 3



#define MAVLINK_MESSAGE_INFO_LOCK_STATUS { \
	"LOCK_STATUS", \
	2, \
	{  { "address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_lock_status_t, address) }, \
         { "lockstatus", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_lock_status_t, lockstatus) }, \
         } \
}


/**
 * @brief Pack a lock_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param address board address
 * @param lockstatus lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lock_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t address, uint8_t lockstatus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, address);
	_mav_put_uint8_t(buf, 2, lockstatus);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 3);
#else
	mavlink_lock_status_t packet;
	packet.address = address;
	packet.lockstatus = lockstatus;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_LOCK_STATUS;
	return mavlink_finalize_message(msg, system_id, component_id, 3, 222);
}

/**
 * @brief Pack a lock_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param address board address
 * @param lockstatus lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lock_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t address,uint8_t lockstatus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, address);
	_mav_put_uint8_t(buf, 2, lockstatus);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 3);
#else
	mavlink_lock_status_t packet;
	packet.address = address;
	packet.lockstatus = lockstatus;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_LOCK_STATUS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 3, 222);
}

/**
 * @brief Encode a lock_status struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lock_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lock_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lock_status_t* lock_status)
{
	return mavlink_msg_lock_status_pack(system_id, component_id, msg, lock_status->address, lock_status->lockstatus);
}

/**
 * @brief Send a lock_status message
 * @param chan MAVLink channel to send the message
 *
 * @param address board address
 * @param lockstatus lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lock_status_send(mavlink_channel_t chan, uint16_t address, uint8_t lockstatus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_uint16_t(buf, 0, address);
	_mav_put_uint8_t(buf, 2, lockstatus);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCK_STATUS, buf, 3, 222);
#else
	mavlink_lock_status_t packet;
	packet.address = address;
	packet.lockstatus = lockstatus;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCK_STATUS, (const char *)&packet, 3, 222);
#endif
}

#endif

// MESSAGE LOCK_STATUS UNPACKING


/**
 * @brief Get field address from lock_status message
 *
 * @return board address
 */
static inline uint16_t mavlink_msg_lock_status_get_address(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field lockstatus from lock_status message
 *
 * @return lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 */
static inline uint8_t mavlink_msg_lock_status_get_lockstatus(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a lock_status message into a struct
 *
 * @param msg The message to decode
 * @param lock_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_lock_status_decode(const mavlink_message_t* msg, mavlink_lock_status_t* lock_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	lock_status->address = mavlink_msg_lock_status_get_address(msg);
	lock_status->lockstatus = mavlink_msg_lock_status_get_lockstatus(msg);
#else
	memcpy(lock_status, _MAV_PAYLOAD(msg), 3);
#endif
}
