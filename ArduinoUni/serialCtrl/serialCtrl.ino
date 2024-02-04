void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT); // R
  pinMode(6, OUTPUT); // G
  pinMode(9, OUTPUT); // B

  Serial.begin(9600);
}

void redLedSet (int red, int green, int blue) {
  analogWrite(5, red);
  analogWrite(6, green);
  analogWrite(9, blue);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String strRead = Serial.readStringUntil('\n');
    // RGB=255,255,255
    if (strRead.indexOf("RGB=") != -1) {
      int commaIndex1 = strRead.indexOf(","); // 7번지
      int commaIndex2 = strRead.indexOf(",", commaIndex1+1); // 11번지
      int redValue = strRead.substring(4, commaIndex1).toInt();
      int greenValue = strRead.substring(commaIndex1+1, commaIndex2).toInt();
      int blueValue = strRead.substring(commaIndex2+1, strRead.length()).toInt();
      redLedSet(redValue, greenValue, blueValue);
      Serial.println("OKRGB");
    }
  }

}
