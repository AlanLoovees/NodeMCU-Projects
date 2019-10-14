#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <SPI.h>


//Channel Field Values Measurement
unsigned long myChannelNumber = 882815;
const char * myReadAPIKey = "IBVVDHRH46CE3VDY";
#define WIFI_SSID "STUD"
#define WIFI_PASSWORD "STUD@2019"
WiFiClient client; 
void setup() {
  Serial.begin(9600);
//  pinMode(D5,OUTPUT);
  //pinMode(D6,OUTPUT);
  pinMode(D5,OUTPUT);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
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
   float sen1 = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);
   float sen2 = ThingSpeak.readFloatField(myChannelNumber, 2, myReadAPIKey);
   int control = ThingSpeak.readFloatField(myChannelNumber, 3, myReadAPIKey);
 
   switch(control){
    case 1: Serial.println(sen1);
            Serial.println(sen2);
            Serial.println(control);
            if(sen1 > 50){
               digitalWrite(D5,HIGH);
              }
            else{
            digitalWrite(D5,LOW);
              }
            break;
    case 0: Serial.println(control);
            digitalWrite(D5,LOW);
            break;
   }
   
  }
