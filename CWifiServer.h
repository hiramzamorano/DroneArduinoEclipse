/*
 * CWifiServer.h
 *
 *  Created on: Jun 9, 2016
 *      Author: vinu
 */

#ifndef CWIFISERVER_H_
#define CWIFISERVER_H_
#include "Arduino.h"
#include "SPI.h"
#include <WiFi.h>
class CWifiServer {
public:
	CWifiServer(unsigned char portNo );
	void start_server();
	void Write_to_Client(char data);
	virtual ~CWifiServer();
private:
	 char ssid[3]={'a','a','a'};
	 char pass[3]={'a','a','a'};  // your network password (use for WPA, or use as key for WEP)

	int keyIndex ;            // your network key Index number (needed only for WEP)

	int status ;

	boolean alreadyConnected ; // whether or not the client was connected previously
	WiFiServer server;
	WiFiClient client ;
};

#endif /* CWIFISERVER_H_ */
