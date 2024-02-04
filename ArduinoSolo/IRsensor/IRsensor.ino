int IR = 2;
int LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IRsensor = digitalRead(IR);
  Serial.println(IRsensor);

  if (IRsensor == LOW) { // 감지하면 LOW, 감지하지 못하면(디폴트) HIGH
    digitalWrite(LED, 1);
  }
  else {
    digitalWrite(LED, 0);
  }
}
