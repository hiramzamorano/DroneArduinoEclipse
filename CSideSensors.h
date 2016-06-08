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
	void init_pins(unsigned char EchoPinNumber,unsigned char TrigPinNumber);
	short read_distance_raw();
	short read_median_Filter(unsigned char BufferSize,unsigned char read_delay);
	short read_limit_Filter(short Filter_UpperLimit,short Filter_LowerLimit,unsigned char read_delay);
	virtual ~CSideSensors();
private:
	unsigned char m_trigPin,m_echoPin;

};

#endif /* CSIDESENSORS_H_ */
