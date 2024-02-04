void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String strRead = Serial.readStringUntil('\n');

    Serial.print("read: ");
    Serial.println(strRead);
  }

}
