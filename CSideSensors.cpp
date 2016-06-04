/*
 * CSideSensors.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#include "CSideSensors.h"

CSideSensors::CSideSensors() {
	// TODO Auto-generated constructor stub
	pinMode(trigPin, OUTPUT);
	 pinMode(echoPin, INPUT);
	 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
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
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);

 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;

 delay(50);

 return duration;
}
