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

bool CMAV::send_HeartBeat() {
	// Define the system type (see mavlink_types.h for list of possible types)


	// Initialize the required buffers
	mavlink_message_t msg;

	// Pack the message
	// mavlink_message_heartbeat_pack(system id, component id, message container, system type, MAV_AUTOPILOT_GENERIC)
	mavlink_msg_heartbeat_pack(sys_ID, comp_ID, &msg, system_type, autopilot_type,system_mode,hda_mav_mode,hda_mave_state);

	send_message(&msg);

	return true;
}

void CMAV::start_feeds() //request data
{
  mavlink_message_t msg;
  mavlink_msg_request_data_stream_pack(sys_ID, comp_ID, &msg,
		  target_ID, TargetComp_ID, MAVLINK_MSG_ID_ATTITUDE, 20, 1);
  send_message(&msg);
  delay(10);

}
void CMAV::send_command() //request data
{uint8_t confirmation=0;
	uint16_t command = MAV_CMD_COMPONENT_ARM_DISARM;
  mavlink_message_t msg;
  mavlink_msg_command_long_pack(sys_ID, comp_ID, &msg,
		  target_ID, TargetComp_ID,   command,   confirmation, 0, 0, 0, 0,0, 0, 0);
  send_message(&msg);
  delay(1000);

}



//bool CMAV:: sent_ARM(){
//	mavlink_msg
//	 sys ID = 255, comp ID = 190, target ID = 1, and TargetCompID = 1.
//}
void CMAV::send_message(mavlink_message_t* msg) //send data bit by bit
{
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  uint16_t len = mavlink_msg_to_send_buffer(buf, msg); // Copy the message to send buffer

  MegaSerialPIX->Print::write(buf, len);// Send the message (.write sends as bytes)
}

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
			} break;

			case MAVLINK_MSG_ID_HEARTBEAT:
				// EXECUTE ACTION
			{
				MegaSerialDEBUG->println(" Heart Beat received");
			}break;

			case MAVLINK_MSG_ID_STATUSTEXT: {
				char text[50];
				// set mode
				mavlink_msg_statustext_get_text(&msg,text);
				MegaSerialDEBUG->print(text);
			}break;
			case MAVLINK_MSG_ID_MISSION_ACK: {
				mavlink_mission_ack_t mission_ack;
				mavlink_msg_mission_ack_decode(&msg,&mission_ack);
				MegaSerialDEBUG->print(" Requested component ");
				MegaSerialDEBUG->println(mission_ack.target_component);
				MegaSerialDEBUG->print(" Requested system ");
				MegaSerialDEBUG->println(mission_ack.target_system);
				MegaSerialDEBUG->print(" Status code  ");
				MegaSerialDEBUG->println(mission_ack.type);

						}break;

			case MAVLINK_MSG_ID_COMMAND_ACK: {
				mavlink_command_ack_t command_ack;
				mavlink_msg_command_ack_decode(&msg,&command_ack);
				MegaSerialDEBUG->print("Requested command ");
				MegaSerialDEBUG->println(command_ack.command);
				MegaSerialDEBUG->print("Result of command(MAV_RESULT)= ");
				MegaSerialDEBUG->println(command_ack.result);
						}break;

			default:{
				MegaSerialDEBUG->print(" Something else received ID : ");
				MegaSerialDEBUG->println(msg.msgid);

			}break;
			//Do nothing

			}
		}
		// And get the next one
	}
	//Add your repeated code here
}

CMAV::~CMAV() {
	// TODO Auto-generated destructor stub
}

