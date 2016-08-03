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
#include "ProjectMavlinkDefinitons.h"
class CMAV {
public:
	CMAV(HardwareSerial *SerialPIX,HardwareSerial *SerialDEBUG);
	bool sent_HeartBeat();
	void comm_receive();
	virtual ~CMAV();
	HardwareSerial *MegaSerialPIX;
	HardwareSerial *MegaSerialDEBUG;
};

#endif /* CMAV_H_ */
