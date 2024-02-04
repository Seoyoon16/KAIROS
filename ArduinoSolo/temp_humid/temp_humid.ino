#include <DHT.h>
#include <SoftwareSerial.h>

DHT myDHT (7, DHT11);
SoftwareSerial myBlueT (2, 3);

void setup() {
  // put your setup code here, to run once:
  myBlueT.begin(9600);
  myDHT.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temper = myDHT.readTemperature();
  myBlueT.println("t " + String(temper)); // 't' 붙여 전송
  delay(1000);

  float humid = myDHT.readHumidity();
  myBlueT.println("h " + String(humid)); // 'h' 붙여 전송
  delay(1000);
}
