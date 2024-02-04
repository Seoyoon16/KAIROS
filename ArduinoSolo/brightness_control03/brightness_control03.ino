void setup() {
  // put your setup code here, to run once:
  // analog pinMode() setting 필요없음

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
        if (j >= 250) {
          analogWrite(i, 0);
        }
      }
    }
  }

}
