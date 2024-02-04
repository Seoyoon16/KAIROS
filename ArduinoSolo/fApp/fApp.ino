#include <SoftwareSerial.h>
#define tx 2;
#define rx 3;

SoftwareSerial myBlue(2, 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myBlue.begin(9600);
  myBlue.println("Hi");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (myBlue.available()) {
    Serial.write(myBlue.read());
  }
  if (Serial.available()) {
    myBlue.write(Serial.read());
  }

}
