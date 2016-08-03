// Do not remove the include below
#include "droneUpdated.h"

CFrontSensor PMOD1;
CFrontSensor PMOD2;
CFrontSensor PMOD3;

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	// Serial port inits
	Serial.begin(57600); // RX TX with PC
	Serial1.begin(57600); //RXTX from Pixhawk (Port 18TX,19RX Arduino Mega)
		// Sensors pin inits
	PMOD1.Pin_init(PWPIN1,TRIGGERPIN1);
	PMOD2.Pin_init(PWPIN2,TRIGGERPIN2);
	PMOD3.Pin_init(PWPIN3,TRIGGERPIN3);
}

// The loop function is called in an endless loop
void loop()
{
	CMAV MAVlink(&Serial1,&Serial);
//Initialize all control variables


MAVlink.sent_HeartBeat();
MAVlink.comm_receive();
delay(500);
//	while(Serial.available() > 0) {
//Serial.println(" reading");
//	uint8_t c = Serial.read();
//				Serial.println(c);
//	delay(20);}
// Process the input data , create events eg height exceeded threshold , drone too close to object etc

//TODO

//Main Control State Machine

// State - DRONE_INIT
/*
 * before starting flying
 *
 * Waiting for GPS
 * Sensor tuning
 * ARMing of drone etc
 *
 * */

// State -DRONE_FLIGHT_INIT
/* */

//State -DRONE_FLIGHT_HORIZONTAL
/*
 * Fly left or right.
 * */

//State -DRONE_FLIGHT_VERTICAL
/*
 * Fly up/down*/

//State -DRONE_COLLITION_DETECT
/*
 * Collition mitigation
 * */
//State -DRONE_RETURN_HOME
/* */


}




// Arduino MAVLink test code.


// FastSerialPort0(Serial);
