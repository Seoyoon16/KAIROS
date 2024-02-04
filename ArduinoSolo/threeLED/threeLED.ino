const unsigned int rgb[] = {3,5,6};


void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT); // R
  pinMode(5, OUTPUT); // G
  pinMode(6, OUTPUT); // B

  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
  // analogWrite(rgb[0], 255);
  // analogWrite(rgb[1], 0);
  // analogWrite(rgb[2], 0);
  // delay(500);

  // analogWrite(rgb[0], 0);
  // analogWrite(rgb[1], 255);
  // analogWrite(rgb[2], 0);
  // delay(500);

  // analogWrite(rgb[0], 0);
  // analogWrite(rgb[1], 0);
  // analogWrite(rgb[2], 255);
  // delay(500);

  // analogWrite(rgb[0], 255);
  // analogWrite(rgb[1], 255);
  // analogWrite(rgb[2], 255);
  // delay(500);

  for (int i = 0; i < 3; i++) {
    int randomValue = random(0, 256); // 0부터 255까지의 랜덤 값 생성
    analogWrite(rgb[i], randomValue);
  }
  delay(1000);
}
