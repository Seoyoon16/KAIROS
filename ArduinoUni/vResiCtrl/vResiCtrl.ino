#define VR_PIN  A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    String strRead = Serial.readStringUntil('\n');
    if(strRead.indexOf("VR=?") != -1)
    {
      Serial.print("VR=");
      Serial.println(analogRead(VR_PIN));
    }
  }
}