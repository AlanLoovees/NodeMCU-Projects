#include "DHT.h"ES
#define DHTTYPE DHT11
#include "UbidotsMicroESP8266.h"
#define TOKEN "BBFF-3Ayr2UXTMgrDrx7jhbFo4WKIJuH1IZ"
#define WIFISSID "STUD"
#define PASSWORD "STUD@2019"

Ubidots client(TOKEN);

#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE);

void setup(void) {
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);
  client.wifiConnection(WIFISSID, PASSWORD);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();         
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Serial.println("C  ");
  delay(800);
  client.add("Temp", t);
  client.add("Hum", h);
  client.sendAll(true);

}
