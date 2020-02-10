/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */
 
#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
#define RXD2 16
#define TXD2 17

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
//SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(115200);
  Serial2.begin(9600);
  Serial.println(F("Start"));
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (Serial2.available() > 0){
    gps.encode(Serial2.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      float datLat = gps.location.lat();
      Serial.print(datLat);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
    }
  }
}
