void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=3; i<=11; i++) {
    if (i == 4 || i == 7 || i == 8) {
      continue;
    }
    else {
      for (int j=0; j<=255; j+=25){
        analogWrite(i, j);
        delay(400);
        }
    }
  }
}
