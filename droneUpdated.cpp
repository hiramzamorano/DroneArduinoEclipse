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
	Serial.begin(9600);
		// Sensors pin inits
	PMOD1.Pin_init(PWPIN1,TRIGGERPIN1);
	PMOD2.Pin_init(PWPIN2,TRIGGERPIN2);
	PMOD3.Pin_init(PWPIN3,TRIGGERPIN3);
}

// The loop function is called in an endless loop
void loop()
{
//Initialize all control variables
//CMAV MAVlink;
int sensor1, sensor2, sensor3;

sensor1=PMOD1.read_sensor();
sensor2=PMOD2.read_sensor();
sensor3=PMOD3.read_sensor();

Serial.print("S1");
Serial.print(" : ");
Serial.print(sensor1);
Serial.print(" ");
Serial.print("S2");
Serial.print(" : ");
Serial.print(sensor2);
Serial.print(" ");
Serial.print("S3");
Serial.print(" : ");
Serial.print(sensor3);
Serial.print(" ");
Serial.println(" ");

// Update Sensors and control variables periodically
//MAVlink.sent_HeartBeat();
//MAVlink.comm_receive();

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
