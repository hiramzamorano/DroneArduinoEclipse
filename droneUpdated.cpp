// Do not remove the include below
#include "droneUpdated.h"
#include "CMAV.h"


//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	Serial.begin(57600);
}

// The loop function is called in an endless loop
void loop()
{
//Initialize all control variables
CMAV MAVlink;

// Update Sensors and control variables periodically
MAVlink.sent_HeartBeat();
MAVlink.comm_receive();

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
