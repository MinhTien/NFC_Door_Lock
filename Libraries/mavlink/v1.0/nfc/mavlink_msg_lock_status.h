// MESSAGE LOCK_STATUS PACKING

#define MAVLINK_MSG_ID_LOCK_STATUS 154

typedef struct __mavlink_lock_status_t
{
 uint8_t lockstatus; ///< lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
} mavlink_lock_status_t;

#define MAVLINK_MSG_ID_LOCK_STATUS_LEN 1
#define MAVLINK_MSG_ID_154_LEN 1



#define MAVLINK_MESSAGE_INFO_LOCK_STATUS { \
	"LOCK_STATUS", \
	1, \
	{  { "lockstatus", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_lock_status_t, lockstatus) }, \
         } \
}


/**
 * @brief Pack a lock_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lockstatus lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_lock_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t lockstatus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, lockstatus);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_lock_status_t packet;
	packet.lockstatus = lockstatus;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_LOCK_STATUS;
	return mavlink_finalize_message(msg, system_id, component_id, 1, 225);
}

/**
 * @brief Pack a lock_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param lockstatus lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_lock_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t lockstatus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, lockstatus);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_lock_status_t packet;
	packet.lockstatus = lockstatus;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_LOCK_STATUS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 1, 225);
}

/**
 * @brief Encode a lock_status struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lock_status C-struct to read the message contents from
 */
static __inline uint16_t mavlink_msg_lock_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lock_status_t* lock_status)
{
	return mavlink_msg_lock_status_pack(system_id, component_id, msg, lock_status->lockstatus);
}

/**
 * @brief Send a lock_status message
 * @param chan MAVLink channel to send the message
 *
 * @param lockstatus lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static __inline void mavlink_msg_lock_status_send(mavlink_channel_t chan, uint8_t lockstatus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, lockstatus);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCK_STATUS, buf, 1, 225);
#else
	mavlink_lock_status_t packet;
	packet.lockstatus = lockstatus;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCK_STATUS, (const char *)&packet, 1, 225);
#endif
}

#endif

// MESSAGE LOCK_STATUS UNPACKING


/**
 * @brief Get field lockstatus from lock_status message
 *
 * @return lock status: LOCKED, UNLOCKED, LOCK_ERROR, UNLOCK_ERROR
 */
static __inline uint8_t mavlink_msg_lock_status_get_lockstatus(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a lock_status message into a struct
 *
 * @param msg The message to decode
 * @param lock_status C-struct to decode the message contents into
 */
static __inline void mavlink_msg_lock_status_decode(const mavlink_message_t* msg, mavlink_lock_status_t* lock_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	lock_status->lockstatus = mavlink_msg_lock_status_get_lockstatus(msg);
#else
	memcpy(lock_status, _MAV_PAYLOAD(msg), 1);
#endif
}
