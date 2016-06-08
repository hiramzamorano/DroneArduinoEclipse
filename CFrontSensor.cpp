/*
 * CFrontSensor.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#include "CFrontSensor.h"

CFrontSensor::CFrontSensor()
{
	m_PWpinNumber=0;
		 m_TRIGpinNumber=0;

}
void CFrontSensor::Pin_init(unsigned char PWpinnum,unsigned char TRIGGpinnum) {
	// TODO Auto-generated constructor stub
	 pinMode(PWpinnum, INPUT);
	 pinMode(TRIGGpinnum,OUTPUT);
	 m_PWpinNumber=PWpinnum;
	 m_TRIGpinNumber=TRIGGpinnum;

}

CFrontSensor::~CFrontSensor() {
	// TODO Auto-generated destructor stub
}

int CFrontSensor:: read_sensor(){

	int pulseWidth,distanceinCM;
	digitalWrite(m_TRIGpinNumber,HIGH);
	pulseWidth = pulseIn(m_PWpinNumber, HIGH);
	distanceinCM = pulseWidth/58;
	digitalWrite(m_TRIGpinNumber,LOW);
	delay(20);

	return distanceinCM;
}
