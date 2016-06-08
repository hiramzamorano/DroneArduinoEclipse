/*
 * CFrontSensor.h
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#ifndef CFRONTSENSOR_H_
#define CFRONTSENSOR_H_
#include "Arduino.h"
class CFrontSensor {
public:
	CFrontSensor();
	void Pin_init(unsigned char PWpinnum,unsigned char TRIGpinnum);
	virtual ~CFrontSensor();
	int read_sensor();
private:
	unsigned char	m_PWpinNumber;
	unsigned char	m_TRIGpinNumber;
};

#endif /* CFRONTSENSOR_H_ */
