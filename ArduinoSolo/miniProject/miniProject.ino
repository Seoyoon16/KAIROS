#include <SoftwareSerial.h>

#define blueTX 12
#define blueRX 11

char ser = 0;
char ble = 0;

int SPright = 10;
int WLright = 9;
int SPleft = 6;
int WLleft = 5;
int val = 127;

const int tpin = 8;
const int epin = A0;

SoftwareSerial HC06(blueTX, blueRX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC06.begin(9600);

  pinMode(SPright, OUTPUT);
  pinMode(WLright, OUTPUT);
  digitalWrite(WLright, LOW);
  analogWrite(SPright, 0);

  pinMode(SPleft, OUTPUT);
  pinMode(WLleft, OUTPUT);
  digitalWrite(WLleft, LOW);
  analogWrite(SPleft, 0);

  pinMode(tpin, OUTPUT);
  pinMode(epin, INPUT);
}

void HC06proc(){
  if(Serial.available()>0){
    ser = Serial.read();
    HC06.write(ser);
  }
  if(HC06.available()>0){
    ble = HC06.read();
    Serial.write(ble);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tpin, 0);
  delayMicroseconds(2);
  digitalWrite(tpin, 1);
  delayMicroseconds(10);
  digitalWrite(tpin, 0);

  long distance = pulseIn(epin, 1) / 58.2;

  if (distance <= 20) {
    tone(13, 150, 1000);
    digitalWrite(WLright, LOW);
    analogWrite(SPright, 0);
    digitalWrite(WLleft, LOW);
    analogWrite(SPleft, 0);
    noTone(13);
  }

  if (HC06.available()>0) {
    Serial.println("ready");
    char c = HC06.read();
    if (c == 'F') { // 앞으로
      digitalWrite(WLright, LOW);
      analogWrite(SPright, val);
      digitalWrite(WLleft, HIGH);
      analogWrite(SPleft, val);
    }
    else if (c == 'B') { // 뒤로
      digitalWrite(WLright, HIGH);
      analogWrite(SPright, val);
      digitalWrite(WLleft, LOW);
      analogWrite(SPleft, val);
    }
    else if (c == 'S') {
      digitalWrite(WLright, LOW);
      analogWrite(SPright, 0);
      digitalWrite(WLleft, LOW);
      analogWrite(SPleft, 0);
    }
    else if (c == 'R') {
      digitalWrite(WLright, HIGH);
      analogWrite(SPright, 70);
      digitalWrite(WLleft, LOW);
      analogWrite(SPleft, 0);
    }
    else if (c == 'L') {
      digitalWrite(WLright, LOW);
      analogWrite(SPright, 0);
      digitalWrite(WLleft, HIGH);
      analogWrite(SPleft, 70);
    }
    else if (c == 'P') {
      tone(13, 150, 5000);
      digitalWrite(WLright, LOW);
      analogWrite(SPright, 0);
      digitalWrite(WLleft, LOW);
      analogWrite(SPleft, LOW);
      noTone(7);
    }
  }
  HC06proc();
}
