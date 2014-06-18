// MESSAGE SET_ADDRESS PACKING

#define MAVLINK_MSG_ID_SET_ADDRESS 155

typedef struct __mavlink_set_address_t
{
 uint16_t address; ///< board address
} mavlink_set_address_t;

#define MAVLINK_MSG_ID_SET_ADDRESS_LEN 2
#define MAVLINK_MSG_ID_155_LEN 2



#define MAVLINK_MESSAGE_INFO_SET_ADDRESS { \
	"SET_ADDRESS", \
	1, \
	{  { "address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_set_address_t, address) }, \
         } \
}


/**
 * @brief Pack a set_address message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param address board address
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_set_address_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t address)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint16_t(buf, 0, address);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_set_address_t packet;
	packet.address = address;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_ADDRESS;
	return mavlink_finalize_message(msg, system_id, component_id, 2, 214);
}

/**
 * @brief Pack a set_address message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param address board address
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_set_address_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t address)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint16_t(buf, 0, address);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_set_address_t packet;
	packet.address = address;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_ADDRESS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 214);
}

/**
 * @brief Encode a set_address struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_address C-struct to read the message contents from
 */
static __inline uint16_t mavlink_msg_set_address_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_address_t* set_address)
{
	return mavlink_msg_set_address_pack(system_id, component_id, msg, set_address->address);
}

/**
 * @brief Send a set_address message
 * @param chan MAVLink channel to send the message
 *
 * @param address board address
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static __inline void mavlink_msg_set_address_send(mavlink_channel_t chan, uint16_t address)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint16_t(buf, 0, address);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ADDRESS, buf, 2, 214);
#else
	mavlink_set_address_t packet;
	packet.address = address;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ADDRESS, (const char *)&packet, 2, 214);
#endif
}

#endif

// MESSAGE SET_ADDRESS UNPACKING


/**
 * @brief Get field address from set_address message
 *
 * @return board address
 */
static __inline uint16_t mavlink_msg_set_address_get_address(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a set_address message into a struct
 *
 * @param msg The message to decode
 * @param set_address C-struct to decode the message contents into
 */
static __inline void mavlink_msg_set_address_decode(const mavlink_message_t* msg, mavlink_set_address_t* set_address)
{
#if MAVLINK_NEED_BYTE_SWAP
	set_address->address = mavlink_msg_set_address_get_address(msg);
#else
	memcpy(set_address, _MAV_PAYLOAD(msg), 2);
#endif
}
