/*
 * CSideSensors.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#include "CSideSensors.h"
#include <WiFiUdp.h>
CSideSensors::CSideSensors() {
}
void CSideSensors::init_pins(unsigned char EchoPinNumber,unsigned char TrigPinNumber) {

	pinMode(TrigPinNumber, OUTPUT); // Set the pin modes
	pinMode(EchoPinNumber, INPUT);

	m_echoPin=EchoPinNumber;
	m_trigPin=TrigPinNumber;

}

CSideSensors::~CSideSensors() {
	// TODO Auto-generated destructor stub
}

short CSideSensors::read_distance_raw() {

	short duration, distance; // Duration used to calculate distance

	/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */
	digitalWrite(TRIGPIN, LOW);
	delayMicroseconds(2);

	digitalWrite(TRIGPIN, HIGH);
	delayMicroseconds(10);

	digitalWrite(TRIGPIN, LOW);
	duration = pulseIn(ECHOPIN, HIGH);

	//Calculate the distance (in cm) based on the speed of sound.
	distance = duration/58.2;
// No delay in reading. this has to be handled by filter functions calling this method.
	return duration;
}

short CSideSensors::read_limit_Filter(short Filter_UpperLimit,short Filter_LowerLimit,unsigned char read_delay)
{
	short NewValue,LimitedValue;
	static short oldValue=0;

	NewValue=read_distance_raw();
	delay(read_delay);
	if(((NewValue - oldValue) > Filter_UpperLimit) || ((oldValue - NewValue) > Filter_LowerLimit))
		LimitedValue= oldValue;
	else
		LimitedValue= NewValue;

	oldValue=LimitedValue;
	return LimitedValue;

}
short CSideSensors::read_median_Filter(unsigned char BufferSize,unsigned char read_delay) {

	short NewValue;
	short filter_buf[BufferSize];
	unsigned char i, j;
	short filter_temp;
	for(i = 0; i < BufferSize; i++)
	{
		filter_buf[i] = read_distance_raw();
		delay(read_delay);
	}
	for(j = 0; j < BufferSize - 1; j++)
	{
		for(i = 0; i < BufferSize - 1 - j; i++)
		{
			if(filter_buf[i] > filter_buf[i + 1])
			{
				filter_temp = filter_buf[i];
				filter_buf[i] = filter_buf[i + 1];
				filter_buf[i + 1] = filter_temp;
			}
		}
	}
	return filter_buf[(BufferSize - 1) / 2];
}
