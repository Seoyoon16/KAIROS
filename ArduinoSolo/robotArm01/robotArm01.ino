#include <Servo.h>
#define SERVO_PIN 12

Servo myservo;

void setup() {
  // 90도 맞추기
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  myservo.write(0);
  delay(1000);
  myservo.write(90);
}

void loop() {
}