const int analogPin = A0;
const int ledPin = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(analogPin);
  analogWrite(10, analogValue/4);
  Serial.println(analogValue/4);
}
