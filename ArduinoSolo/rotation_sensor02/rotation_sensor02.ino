const int analogPin = A0;
const int led[6] = {3, 5, 6, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(analogPin);

  for (int n=0; n<=5; n++) {
    if (val >= 876) {
      for (int k=0; k<=5; k++) {
        analogWrite(led[k], val);
        Serial.println(val);
      }
    }
    if (val <= 876 && val >=730) {
      for (int k=0; k<=4; k++) {
        analogWrite(led[k], val);
        Serial.println(val);
      }
    }
    if (val <=730 && val >=584) {
      for (int k=0; k<=3; k++) {
        analogWrite(led[k], val);
        Serial.println(val);
      }
    }
    if (val <=584 && val >=438) {
      for (int k=0; k<=2; k++) {
        analogWrite(led[k], val);
        Serial.println(val);
      }
    }
    if (val <=438 && val >=292) {
      for (int k=0; k<=1; k++) {
        analogWrite(led[k], val);
        Serial.println(val);
      }
    }
    if (val <=292 && val >=146) {
      int k = 0;
      analogWrite(led[k], val);
      Serial.println(val);
    }
    if (val < 146) {
      for (int k=0; k<=5; k++) {
        analogWrite(led[k], 0);
        Serial.println(val);
      }
    }
  }

}
