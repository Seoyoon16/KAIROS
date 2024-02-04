void setup() {
  // put your setup code here, to run once:
  // 아두이노에서 ~ 붙은 디지털 핀 아날로그도 지원
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int t_high=0; t_high<=10; t_high++) {
    int cnt = 0;
    while (true) {
      digitalWrite(13, 1);
      digitalWrite(3, 1);
      delay(t_high);
      digitalWrite(13, 0);
      digitalWrite(3, 0);
      delay(10-t_high);

      cnt++;
      if (cnt == 10) break;
    }
  }
  
  // delay(1000);

  for (int t_high=0; t_high<=10; t_high++) {
    int cnt = 0;
    while (true) {
      digitalWrite(13, 0);
      digitalWrite(3, 0);
      delay(t_high);
      digitalWrite(13, 1);
      digitalWrite(3, 1);
      delay(10-t_high);

      cnt++;
      if (cnt == 10) break;
    }
  }
  // delay(1000);
  while (true) {
    digitalWrite(13, 0);
    digitalWrite(3, 0);
  }

}
