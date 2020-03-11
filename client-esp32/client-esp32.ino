#include <WiFi.h>
#include "Arduino.h"

#include "videostream.h"
#include "control.h"

const char* ssid = "OSK-11e1";
const char* password = "Ud9nC7eP";

const uint16_t port = 54321;
const char * hostIP = "192.168.100.5";


WiFiClient socket;
controlData_t controlData;

void setup() {
		Serial.begin(115200);
		Serial.setDebugOutput(false);

		setupCameraServer();

		// Wi-Fi connection
		WiFi.begin(ssid, password);
		while (WiFi.status() != WL_CONNECTED) {
			delay(500);
			Serial.print(".");
		}
		Serial.println("");
		Serial.println("WiFi connected");
		
		Serial.print("Camera Stream Ready! Go to: http://");
		Serial.print(WiFi.localIP());
		
		while (!socket.connect(hostIP, port)) {
			Serial.println("\nConnection to hostIP failed");
			delay(1000);
		}
		Serial.println("Connected to server successful!");
		
		startCameraServer();
}

void loop() {
	
		if(socket.available() > sizeof(PACKET_MARK)) {
            if(socket.read() == PACKET_MARK[1] && socket.read() == PACKET_MARK[0]) {
				socket.readBytes((uint8_t*)&controlData, sizeof(controlData));

				Serial.print(controlData.forward);
				Serial.print("	");
				Serial.print(controlData.backward);
				Serial.print("	");
				Serial.print(controlData.right);
				Serial.print("	");
				Serial.print(controlData.left);
				Serial.print("\n");
            }
            else {
            	Serial.println("Packet mark error");
            }
        }
}

uint16_t readSocketWord() {
	uint8_t buff[2];
	
	for(uint8_t n = 0; n < 2; n++) {
	        buff[n] = socket.read();
	}
	return (uint16_t)(buff[1]<<8 | buff[0]);
}



