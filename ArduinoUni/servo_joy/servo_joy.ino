#include <Servo.h>

#define MIN 0
#define MAX 1023
#define REF 512
#define SW 4
#define SERVO_MIN  0
#define SERVO_MAX 180

Servo myservo;

void setup(){
 Serial.begin(9600); 
 pinMode(SW, INPUT_PULLUP); 
 myservo.attach(10);
}

void loop(){
  int x = analogRead(A0);
  int y = analogRead(A1);
  int s = digitalRead(SW);
 

  int angle = map(x, MIN, MAX, SERVO_MIN, SERVO_MAX);
  myservo.write(angle); // 매핑된 각도로 서보 모터 제어

  Serial.print(angle);
  Serial.print('\t');
  Serial.print(x);
  Serial.print('\t');
  Serial.print(y);
  Serial.print('\t');
  Serial.print(s);
  Serial.print('.');
  delay(20);
}