void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  int val = digitalRead(8);
  if (val == 1) {
    for (int i=0; i<256; i+=25) {
      analogWrite(8, i);
      Serial.println(val);
      delay(50);
    }
  }
  else {
    analogWrite(8, 0);
  }
}