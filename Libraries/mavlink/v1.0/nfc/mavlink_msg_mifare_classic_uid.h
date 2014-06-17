// MESSAGE MIFARE_CLASSIC_UID PACKING

#define MAVLINK_MSG_ID_MIFARE_CLASSIC_UID 151

typedef struct __mavlink_mifare_classic_uid_t
{
 uint8_t byte0; ///< uid byte0
 uint8_t byte1; ///< uid byte1
 uint8_t byte2; ///< uid byte2
 uint8_t byte3; ///< uid byte3
} mavlink_mifare_classic_uid_t;

#define MAVLINK_MSG_ID_MIFARE_CLASSIC_UID_LEN 4
#define MAVLINK_MSG_ID_151_LEN 4



#define MAVLINK_MESSAGE_INFO_MIFARE_CLASSIC_UID { \
	"MIFARE_CLASSIC_UID", \
	4, \
	{  { "byte0", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mifare_classic_uid_t, byte0) }, \
         { "byte1", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mifare_classic_uid_t, byte1) }, \
         { "byte2", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mifare_classic_uid_t, byte2) }, \
         { "byte3", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mifare_classic_uid_t, byte3) }, \
         } \
}


/**
 * @brief Pack a mifare_classic_uid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param byte0 uid byte0
 * @param byte1 uid byte1
 * @param byte2 uid byte2
 * @param byte3 uid byte3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mifare_classic_uid_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint8_t(buf, 0, byte0);
	_mav_put_uint8_t(buf, 1, byte1);
	_mav_put_uint8_t(buf, 2, byte2);
	_mav_put_uint8_t(buf, 3, byte3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_mifare_classic_uid_t packet;
	packet.byte0 = byte0;
	packet.byte1 = byte1;
	packet.byte2 = byte2;
	packet.byte3 = byte3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_MIFARE_CLASSIC_UID;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 129);
}

/**
 * @brief Pack a mifare_classic_uid message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param byte0 uid byte0
 * @param byte1 uid byte1
 * @param byte2 uid byte2
 * @param byte3 uid byte3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mifare_classic_uid_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t byte0,uint8_t byte1,uint8_t byte2,uint8_t byte3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint8_t(buf, 0, byte0);
	_mav_put_uint8_t(buf, 1, byte1);
	_mav_put_uint8_t(buf, 2, byte2);
	_mav_put_uint8_t(buf, 3, byte3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_mifare_classic_uid_t packet;
	packet.byte0 = byte0;
	packet.byte1 = byte1;
	packet.byte2 = byte2;
	packet.byte3 = byte3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_MIFARE_CLASSIC_UID;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 129);
}

/**
 * @brief Encode a mifare_classic_uid struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mifare_classic_uid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mifare_classic_uid_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mifare_classic_uid_t* mifare_classic_uid)
{
	return mavlink_msg_mifare_classic_uid_pack(system_id, component_id, msg, mifare_classic_uid->byte0, mifare_classic_uid->byte1, mifare_classic_uid->byte2, mifare_classic_uid->byte3);
}

/**
 * @brief Send a mifare_classic_uid message
 * @param chan MAVLink channel to send the message
 *
 * @param byte0 uid byte0
 * @param byte1 uid byte1
 * @param byte2 uid byte2
 * @param byte3 uid byte3
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mifare_classic_uid_send(mavlink_channel_t chan, uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint8_t(buf, 0, byte0);
	_mav_put_uint8_t(buf, 1, byte1);
	_mav_put_uint8_t(buf, 2, byte2);
	_mav_put_uint8_t(buf, 3, byte3);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIFARE_CLASSIC_UID, buf, 4, 129);
#else
	mavlink_mifare_classic_uid_t packet;
	packet.byte0 = byte0;
	packet.byte1 = byte1;
	packet.byte2 = byte2;
	packet.byte3 = byte3;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIFARE_CLASSIC_UID, (const char *)&packet, 4, 129);
#endif
}

#endif

// MESSAGE MIFARE_CLASSIC_UID UNPACKING


/**
 * @brief Get field byte0 from mifare_classic_uid message
 *
 * @return uid byte0
 */
static inline uint8_t mavlink_msg_mifare_classic_uid_get_byte0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field byte1 from mifare_classic_uid message
 *
 * @return uid byte1
 */
static inline uint8_t mavlink_msg_mifare_classic_uid_get_byte1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field byte2 from mifare_classic_uid message
 *
 * @return uid byte2
 */
static inline uint8_t mavlink_msg_mifare_classic_uid_get_byte2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field byte3 from mifare_classic_uid message
 *
 * @return uid byte3
 */
static inline uint8_t mavlink_msg_mifare_classic_uid_get_byte3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a mifare_classic_uid message into a struct
 *
 * @param msg The message to decode
 * @param mifare_classic_uid C-struct to decode the message contents into
 */
static inline void mavlink_msg_mifare_classic_uid_decode(const mavlink_message_t* msg, mavlink_mifare_classic_uid_t* mifare_classic_uid)
{
#if MAVLINK_NEED_BYTE_SWAP
	mifare_classic_uid->byte0 = mavlink_msg_mifare_classic_uid_get_byte0(msg);
	mifare_classic_uid->byte1 = mavlink_msg_mifare_classic_uid_get_byte1(msg);
	mifare_classic_uid->byte2 = mavlink_msg_mifare_classic_uid_get_byte2(msg);
	mifare_classic_uid->byte3 = mavlink_msg_mifare_classic_uid_get_byte3(msg);
#else
	memcpy(mifare_classic_uid, _MAV_PAYLOAD(msg), 4);
#endif
}
