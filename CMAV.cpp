/*
 * CMAV.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#include "CMAV.h"

CMAV::CMAV() {
	// TODO Auto-generated constructor stub

}

bool CMAV::sent_HeartBeat() {
	// Define the system type (see mavlink_types.h for list of possible types)
			int system_type = MAV_TYPE_OCTOROTOR;
			int autopilot_type = MAV_AUTOPILOT_PX4;
			int system_mode=MAV_MODE_FLAG_MANUAL_INPUT_ENABLED;
			uint32_t hda_mav_mode=MAV_MODE_PREFLIGHT;
			int hda_mave_state=MAV_STATE_BOOT;

			// Initialize the required buffers
			mavlink_message_t msg;
			uint8_t buf[MAVLINK_MAX_PACKET_LEN];

			// Pack the message
			// mavlink_message_heartbeat_pack(system id, component id, message container, system type, MAV_AUTOPILOT_GENERIC)
			mavlink_msg_heartbeat_pack(100, 200, &msg, system_type, autopilot_type,system_mode,hda_mav_mode,hda_mave_state);

			// Copy the message to send buffer
			uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

			// Send the message (.write sends as bytes)
			Serial.write(buf, len);

			return true;
}

void  CMAV::comm_receive()
	{
		mavlink_message_t msg;
		mavlink_status_t status;

		//receive data over serial
		while(Serial.available() > 0) {
			uint8_t c = Serial.read();

			//try to get a new message
			if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
				// Handle message
	 			switch(msg.msgid) {
				        case MAVLINK_MSG_ID_SET_MODE: {
				        	// set mode
				        }
				        break;
				        case MAVLINK_MSG_ID_HEARTBEAT:
						// EXECUTE ACTION
					break;
					default:
						//Do nothing
					break;
				}
			}
			// And get the next one
		}
//Add your repeated code here
}

CMAV::~CMAV() {
	// TODO Auto-generated destructor stub
}

