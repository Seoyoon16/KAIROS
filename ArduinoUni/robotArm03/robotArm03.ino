#include <Servo.h>

Servo bottom, arm1, arm2, arm3;
Servo servo[4] = {bottom, arm1, arm2, arm3};

int pin[4] = {9,10,11,12};
int pre_angle[4] = {90,90,90,90}; 
int servoSpeed = 20;

void setup() {
  for(int i=0; i<4; i++){
    servo[i].attach(pin[i]);
  }
  Serial.begin(9600);
}

void loop() {
  // 시리얼 버퍼에 데이터가 있는지 확인
  if (Serial.available() > 0) {
    // 시리얼 버퍼에서 데이터를 읽음
    String data = Serial.readStringUntil('\n'); // SERVO={val1},{val2},{val3},{val4}\n
    data.remove(0, 6); // "SERVO=" 부분 제거
    
    // 쉼표를 기준으로 문자열 분할
    int commaIndex = data.indexOf(',');
    String val1 = data.substring(0, commaIndex);
    data.remove(0, commaIndex + 1);

    commaIndex = data.indexOf(',');
    String val2 = data.substring(0, commaIndex);
    data.remove(0, commaIndex + 1);

    commaIndex = data.indexOf(',');
    String val3 = data.substring(0, commaIndex);
    data.remove(0, commaIndex + 1);

    String val4 = data;
    
    // 각각의 서보모터를 제어
    servo[0].write(val1.toInt());
    servo[1].write(val2.toInt());
    servo[2].write(val3.toInt());
    servo[3].write(val4.toInt());

    Serial.println(val1);
    Serial.println(val2);
    Serial.println(val3);
    Serial.println(val4);
  }
}
