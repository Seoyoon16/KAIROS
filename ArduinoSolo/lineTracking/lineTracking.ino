int IR1 = 2;
int IR2 = 3;

void setup() {
  pinMode(IR1, INPUT); // right
  pinMode(IR2, INPUT); // left
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int val1 = digitalRead(IR1);
  int val2 = digitalRead(IR2);
  Serial.print(val1);
  Serial.println(val2);

  if (val1 == LOW && val2 == LOW) {
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 200);
    analogWrite(10, 200);
  }
  else if (val1 == LOW && val2 == HIGH) { // 좌회전
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 0);
    analogWrite(10, 200);
    delay(100);
  }
  else if (val1 == HIGH && val2 == LOW) { // 우회전
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 200);
    analogWrite(10, 0);
    delay(100);
  }
  else if (val1 == HIGH && val2 == HIGH) {
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 0);
    analogWrite(10, 0);

  }
  delay(10);

}