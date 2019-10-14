#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <SPI.h>

unsigned long myChannelNumber = 882824;
const char myWriteAPIKey = JXT84S4WW2RXEIRU;

#define WIFI_SSID "STUD"
#define WIFI_PASSWORD "STUD@2019"

long duration;
long cm;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(D1,OUTPUT);
  pinMode(D2,INPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  ThingSpeak.begin(client);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected:");
  Serial.println(WiFi.localIP());
}
void loop() {
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.subnetMask());
}
//  digitalWrite(D1,LOW);
//  delay(2/1000);
//  digitalWrite(D1,HIGH);
//  delay(10/1000);
//  digitalWrite(D1,LOW);
//  delay(2/1000);
//  echo=pulseIn(D2,HIGH);
//  echo=echofun(echo);
//  if(echo<=400){
//    if(echo<20){
//      digitalWrite(D3,HIGH);
//      }
//    else if(echo>100){
//      digitalWrite(D5,HIGH);
//      }
//    else{
//      digitalWrite(D4,HIGH);
//      }
//  Serial.print(echo);
//  Serial.println("cm");
//  }
//  delay(500);
//  digitalWrite(D3,LOW)
//  digitalWrite(D4,LOW);
//  digitalWrite(D5,LOW);
//  delay(500);
//  }
