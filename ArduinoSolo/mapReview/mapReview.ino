int led[] = {3, 5, 6, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorInput = analogRead(A0);
  int level = map(sensorInput, 0, 1023, 0, 6); // 0~1023을 6단계로 나눈다

  for (int n=0; n<6; n++) {
    if (n<level) {
      analogWrite(led[n], 255);
    }
    else {
      analogWrite(led[n], 0);
    }
  }
}
