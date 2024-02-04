#include <SoftwareSerial.h>

#define blueTX 2
#define blueRX 3

char ser = 0;
char ble = 0;

SoftwareSerial HC06(blueTX, blueRX); // 객체화

void setup(){
  // 통신속도 둘 다 동일하게
   Serial.begin(9600);
   HC06.begin(9600);
}

void HC06proc(){
  if(Serial.available()>0){
    ser = Serial.read();
    HC06.write(ser); // 블루투스로 값 전달
  }
  if(HC06.available()>0){
    ble = HC06.read();
    Serial.write(ble);
  }
}

void loop(){
  HC06proc();
}