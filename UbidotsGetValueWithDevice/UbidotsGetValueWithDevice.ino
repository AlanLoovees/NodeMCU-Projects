#include "UbidotsMicroESP8266.h"

#define DEVICE  "bcddc2fded67"  // Put here your Ubidots device label
#define VARIABLE  "temp"  // Put here your Ubidots variable label
#define BUTTON "button"
#define TOKEN  "BBFF-3Ayr2UXTMgrDrx7jhbFo4WKIJuH1IZ"  // Put here your Ubidots TOKEN
#define WIFISSID "STUD" // Put here your Wi-Fi SSID
#define PASSWORD "STUD@2019" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup() {
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);
//    client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop() {
    float value = client.getValueWithDevice(DEVICE, VARIABLE);
    int button = client.getValueWithDevice(DEVICE, BUTTON);

    if(button==1){
      if (value != ERROR_VALUE){
      Serial.print(F("value obtained: "));
      Serial.println(value);
    }else{
      Serial.println(F("Error getting value"));
    }
    }
    else {
      Serial.println("Switch is 0! Try Again!!");
    }
    delay(1000);
}
