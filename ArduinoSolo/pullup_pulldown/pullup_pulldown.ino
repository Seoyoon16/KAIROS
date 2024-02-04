void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(8, INPUT_PULLUP);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = digitalRead(8);
  digitalWrite(9, light);
  Serial.println(light);
}

// 회로도: https://eteo.tistory.com/67
