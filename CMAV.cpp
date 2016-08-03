/*
 * CMAV.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#include "CMAV.h"
#include "ProjectMavlinkDefinitons.h"
CMAV::CMAV(HardwareSerial *SerialPIX,HardwareSerial *SerialDEBUG) {
	// TODO Auto-generated constructor stub
	MegaSerialPIX=SerialPIX;
	MegaSerialDEBUG=SerialDEBUG;
}

bool CMAV::sent_HeartBeat() {
	// Define the system type (see mavlink_types.h for list of possible types)


			// Initialize the required buffers
			mavlink_message_t msg;
			uint8_t buf[MAVLINK_MAX_PACKET_LEN];

			// Pack the message
			// mavlink_message_heartbeat_pack(system id, component id, message container, system type, MAV_AUTOPILOT_GENERIC)
			mavlink_msg_heartbeat_pack(sys_ID, comp_ID, &msg, system_type, autopilot_type,system_mode,hda_mav_mode,hda_mave_state);

			// Copy the message to send buffer
			uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

			// Send the message (.write sends as bytes)
			MegaSerialPIX->Print::write(buf, len);

			return true;
}
//bool CMAV:: sent_ARM(){
//	mavlink_msg
//	 sys ID = 255, comp ID = 190, target ID = 1, and TargetCompID = 1.
//}

void  CMAV::comm_receive()
	{
		mavlink_message_t msg;
		mavlink_status_t status;

		//receive data over serial
		while(MegaSerialPIX->available() > 0) {
			uint8_t c = MegaSerialPIX->read();

			//try to get a new message
			if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
				MegaSerialDEBUG->print(" detection ");
				// Handle message
	 			switch(msg.msgid) {
				        case MAVLINK_MSG_ID_SET_MODE: {
				        	// set mode
				        }
				        break;
				        case MAVLINK_MSG_ID_HEARTBEAT:
						// EXECUTE ACTION
				        {
				        	MegaSerialDEBUG->println(" Heart Beat received");
				        }
					break;
				        case MAVLINK_MSG_ID_STATUSTEXT: {
				        	char text[50];
				        				        	// set mode
				        	mavlink_msg_statustext_get_text(&msg,text);
				        	MegaSerialDEBUG->print(text);
				        				        }
				        				        break;

					default:{
						MegaSerialDEBUG->print(" Something else received ID : ");
						MegaSerialDEBUG->println(msg.msgid);

					}
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

