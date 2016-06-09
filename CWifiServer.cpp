/*
 * CWifiServer.cpp
 *
 *  Created on: Jun 9, 2016
 *      Author: vinu
 */

#include "CWifiServer.h"
void printWifiStatus();
CWifiServer::CWifiServer(unsigned char portNo):server(portNo) {
	// TODO Auto-generated constructor stub
	keyIndex = 0;            // your network key Index number (needed only for WEP)

	status = WL_IDLE_STATUS;



	alreadyConnected = false; // whether or not the client was connected previously
}

void CWifiServer::start_server() {
	int ConnectionAttempts=0;

	if (WiFi.status() != WL_NO_SHIELD) {
		// attempt to connect to Wifi network:
		while ( status != WL_CONNECTED && ConnectionAttempts==3) {
			Serial.print("Attempting to connect to SSID: ");
			Serial.println(ssid);
			// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
			status = WiFi.begin(ssid, pass);

			// wait 10 seconds for connection:
			delay(10000);
			ConnectionAttempts++;
		}
		// start the server:
		server.begin();
		// you're connected now, so print out the status:
		void printWifiStatus();
	}
	else
	{
		Serial.print("No shield present ");
	}
}
void CWifiServer::Write_to_Client(char data){
	client = server.available();
	if (client) {
		if (!alreadyConnected)
		{
			// clear out the input buffer:
			client.flush();
			Serial.println("We have a new client");
			client.println("Hello, client!");
			alreadyConnected = true;
		}

		if (client.available() > 0) {
			// read the bytes incoming from the client:

			// echo the bytes back to the client:
			server.write(data);
			// echo the bytes to the server as well:

		}
		client.stop();
	}


}
void printWifiStatus() {
	// print the SSID of the network you're attached to:
	Serial.print("SSID: ");
	Serial.println(WiFi.SSID());

	// print your WiFi shield's IP address:
	IPAddress ip = WiFi.localIP();
	Serial.print("IP Address: ");
	Serial.println(ip);

	// print the received signal strength:
	long rssi = WiFi.RSSI();
	Serial.print("signal strength (RSSI):");
	Serial.print(rssi);
	Serial.println(" dBm");
}

CWifiServer::~CWifiServer() {
	// TODO Auto-generated destructor stub
}

