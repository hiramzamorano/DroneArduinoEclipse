/*
 * CMAV.h
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#ifndef CMAV_H_
#define CMAV_H_
#include "Arduino.h"
#include "mavlink.h"        // Mavlink interface
#include "HardwareSerial.h"
#include "Print.h"

class CMAV {
public:
	CMAV(HardwareSerial *SerialPIX,HardwareSerial *SerialDEBUG);
	bool send_HeartBeat();
	void comm_receive();
	void start_feeds();
	void send_command();
	void send_message(mavlink_message_t* msg);
	virtual ~CMAV();
	HardwareSerial *MegaSerialPIX;
	HardwareSerial *MegaSerialDEBUG;
};

#endif /* CMAV_H_ */
