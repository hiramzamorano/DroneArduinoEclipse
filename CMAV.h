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
class CMAV {
public:
	CMAV();
	bool sent_HeartBeat();
	void comm_receive();
	virtual ~CMAV();
};

#endif /* CMAV_H_ */
