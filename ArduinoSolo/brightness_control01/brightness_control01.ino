void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=1; i<=11; i++) {
    int h = 256 - (256 / i);
    analogWrite(3, h); // h에는 정수값이 와야 함
    delay(400);
  }
  // for (int br = 0; br <= 255; br += 25) {
  //   analogWrite(3, br);
  //   delay(400);
  // }
  // delay(1000);
}
