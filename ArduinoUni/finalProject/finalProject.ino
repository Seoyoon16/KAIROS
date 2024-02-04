#include <Servo.h>

Servo bottom, arm1, arm2, arm3;
Servo servo[4] = {bottom, arm1, arm2, arm3};

int pin[4] = {9,10,11,12}; 

void setup() {
  for(int i=0; i<4; i++){
    servo[i].attach(pin[i]);
  }
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, INPUT_PULLUP);
}

void singSong() {
  int melodies[][16] = {
  {262, 196, 196, 220, 196, 0, 247, 262, 262, 262, 294, 262, 0, 330, 392, 349}, // 멜로디 1
  {262, 294, 330, 349, 392, 440, 494, 523, 0, 523, 494, 440, 392, 349, 330, 294}, // 멜로디 2
  };

  int noteDuration = 1000 / 16; // 음 길이 설정

  for (int i = 0; i < 16; i++) {
    int randomMelodyIndex = random(0, 2);
    int note = melodies[i];

    if (note == 0) {
      noTone(3); // 소리 끄기
    } else {
      tone(3, note, noteDuration); // 부저로 음 재생
    }

    delay(noteDuration); // 음 간 딜레이
  }
}

void lightUp() {
  int btn = digitalRead(8);

  if (btn == 0) {
    digitalWrite(4, 1);
    Serial.println("ON");
  }
  else {
    digitalWrite(4, 0);
    Serial.println("OFF");
  }
  delay(100);
}

void loop() {
  // 시리얼 버퍼에 데이터가 있는지 확인
  if (Serial.available() > 0) {
    // 시리얼 버퍼에서 데이터를 읽음
    String data = Serial.readStringUntil('\n'); // DATA=0,0,30,0,0\n
    data.remove(0, 5); // "DATA=" 부분 제거
    
    // 쉼표를 기준으로 문자열 분할
    int commaIndex = data.indexOf(',');
    String indexMenu = data.substring(0, commaIndex);
    data.remove(0, commaIndex + 1);

    commaIndex = data.indexOf(',');
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
    if (indexMenu == "0") {
      // 안녕 DATA=0,90,30,90,90
      servo[0].write(val1.toInt());
      servo[1].write(val2.toInt());
      servo[2].write(val3.toInt());
      servo[3].write(val4.toInt());
      delay(500);
      servo[0].write(90);
      servo[1].write(120);
      servo[2].write(90);
      servo[3].write(90);
      delay(500);
      servo[0].write(val1.toInt());
      servo[1].write(val2.toInt());
      servo[2].write(val3.toInt());
      servo[3].write(val4.toInt());
      delay(500);
      servo[0].write(90);
      servo[1].write(120);
      servo[2].write(90);
      servo[3].write(90);
      delay(500);
      servo[0].write(90);
      servo[1].write(90);
      servo[2].write(90);
      servo[3].write(90);
      delay(500);
      Serial.println("안녕~");
    }
    else if (indexMenu == "1") {
      // 악수 DATA=1,150,90,45,50
      servo[0].write(val1.toInt());
      servo[1].write(val2.toInt());
      servo[2].write(val3.toInt());
      servo[3].write(val4.toInt());
      delay(500);
      servo[0].write(180);
      servo[1].write(90);
      servo[2].write(135);
      servo[3].write(140);
      delay(500);
      servo[0].write(180);
      servo[1].write(90);
      servo[2].write(135);
      servo[3].write(50);
      delay(500);
      servo[0].write(180);
      servo[1].write(90);
      servo[2].write(135);
      servo[3].write(140);
      delay(500);
      servo[0].write(180);
      servo[1].write(90);
      servo[2].write(135);
      servo[3].write(50);
      delay(500);
      servo[0].write(180);
      servo[1].write(90);
      servo[2].write(135);
      servo[3].write(140);
      delay(500);
      servo[0].write(90);
      servo[1].write(90);
      servo[2].write(90);
      servo[3].write(90);
      delay(500);
      Serial.println("반가워~");
    }
    else if (indexMenu == "2") {
      // 춤 DATA=2,90,90,90,90
      int deg1 = random(30, 150);
      int deg2 = random(30, 150);
      int deg3 = random(30, 150);
      int deg4 = random(30, 150);
      int degs[] = {deg1, deg2, deg3, deg4};

      servo[0].write(val1.toInt());
      servo[1].write(val2.toInt());
      servo[2].write(val3.toInt());
      servo[3].write(val4.toInt());
      delay(500);

      // singSong();

      for (int i=0; i<6; i++) {
        servo[i].write(degs[i]);
        singSong();
        delay(500);
      }

      servo[0].write(90);
      servo[1].write(90);
      servo[2].write(90);
      servo[3].write(90);
      delay(500);

      Serial.println("두둠칫");
    }
    else if (indexMenu == "3") {
      // 불 DATA=3,90,180,135,115

      servo[0].write(val1.toInt());
      servo[1].write(val2.toInt());
      servo[2].write(val3.toInt());
      servo[3].write(val4.toInt());
      delay(100);

      digitalWrite(4, 1);
      delay(5000);
      
      servo[0].write(90);
      servo[1].write(90);
      servo[2].write(90);
      servo[3].write(90);
      delay(500);

      digitalWrite(4, 0);
      delay(100);

      Serial.println("탁!");
    }
    
    Serial.println(indexMenu);
    Serial.println(val1);
    Serial.println(val2);
    Serial.println(val3);
    Serial.println(val4);

  }
}