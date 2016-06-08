/*
 * CSideSensors.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#include "CSideSensors.h"

CSideSensors::CSideSensors() {
	// TODO Auto-generated constructor stub
	pinMode(TRIGPIN, OUTPUT);
	 pinMode(ECHOPIN, INPUT);
	// pinMode(LEDPIN, OUTPUT); // Use LED indicator (if required)
}

CSideSensors::~CSideSensors() {
	// TODO Auto-generated destructor stub
}

long CSideSensors::read_distance() {

	int maximumRange = 200; // Maximum range needed
	int minimumRange = 0; // Minimum range needed
	long duration, distance; // Duration used to calculate distance

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

 delay(50);

 return duration;
}
