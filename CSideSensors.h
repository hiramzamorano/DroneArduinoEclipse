/*
 * CSideSensors.h
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#ifndef CSIDESENSORS_H_
#define CSIDESENSORS_H_
#include "Arduino.h"
#include "PinDefinitions.h"
class CSideSensors {
public:
	CSideSensors();
	long read_distance();
	virtual ~CSideSensors();
};

#endif /* CSIDESENSORS_H_ */
