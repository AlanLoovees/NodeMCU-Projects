#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <SPI.h>

//Thingspeak Channel Field Values Measurement
unsigned long myChannelNumber = 882824;
const char * myWriteAPIKey = "JXT84S4WW2RXEIRU";

#define WIFI_SSID "STUD"
#define WIFI_PASSWORD "STUD@2019"

long duration;
long cm;
WiFiClient client; 
void setup() {
  pinMode(D1,OUTPUT);//Trigger
  pinMode(D2,INPUT);//Echo
//  pinMode(,OUTPUT);//Switch
//  pinMode(,INPUT);
//  pinMode(D7,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);// connect to wifi.
  ThingSpeak.begin(client);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
}
Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
} 

void loop() {

   Serial.println(WiFi.localIP());
  digitalWrite(D1, LOW);  // The PING))) is triggered by a HIGH pulse of 10 microseconds.
  delay(2/1000);           // Give a short LOW pulse (2 microsec) beforehand to ensure a clean HIGH pulse:
  digitalWrite(D1, HIGH);
  delay(10/1000);
  digitalWrite(D1, LOW);
  
  duration = pulseIn(D2, HIGH);// The same pin is used to read the signal from the PING))): a HIGH pulse
                               // whose duration is the time (in microseconds) from the sending of the ping
                               // to the reception of its echo off of an object.
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.println("cm");
  Serial.println(analogRead(
  delay(1000);

  ThingSpeak.setField(1,cm);
  ThingSpeak.setField(2, analogRead(A0));
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(20000);
//  digitalWrite(D7,HIGH);
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1,field 2 and field 3.
}

long microsecondsToCentimeters(long microseconds) {
return (duration *.034)/ 2; // The speed of sound is 340 m/s
}
