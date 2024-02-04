#include <Servo.h>

const int SERVO = 10;
Servo servo;

int tones[] = {261, 277, 294, 311, 330, 349, 370, 500};

void setup()
{
  pinMode(6, OUTPUT); // B
  pinMode(7, OUTPUT); // G
  pinMode(8, OUTPUT); // R
  
  pinMode(11, INPUT_PULLUP); // echo
  pinMode(12, OUTPUT); // trigger

  pinMode(13, OUTPUT);

  Serial.begin(9600);
  
}

void lightLED(int r, int g, int b){
  analogWrite(6, r);
  analogWrite(7, g);
  analogWrite(8, b);
}

void loop()
{
  digitalWrite(12, 0);
  delayMicroseconds(2);
  digitalWrite(12, 1);
  delayMicroseconds(10);
  digitalWrite(12, 0);
  
  long duration = pulseIn(11, 1);
  long distance = (duration/2) / 29.1;

  Serial.println(distance);

  if (distance >= 0 && distance <= 20) {
    lightLED(255, 0, 0);
    for (int i=0; i<8; i++) {
      tone(13, tones[i]);
      delay(100);
      noTone(13);
    }
    servo.attach(10);
    servo.write(0);
    delay(1000);
    servo.detach();
  }
  else if (distance > 20 && distance <= 50) {
    lightLED(0, 255, 0);
    servo.attach(10);
    servo.write(90);
    delay(1000);
    servo.detach();
  }
  else {
    lightLED(0, 0, 255);
    servo.attach(10);
    servo.write(90);
    delay(1000);
    servo.detach();
  }
  delay(500);
}
