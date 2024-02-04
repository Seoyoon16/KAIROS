#define VR_PIN A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write(analogRead(VR_PIN)/4);
  delay(30);

}
