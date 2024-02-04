// C++ code
//
void setup()
{
  pinMode(10, OUTPUT); //B
  pinMode(11, OUTPUT); //R
  pinMode(3, INPUT);
  digitalWrite(3, LOW); // 처음에 PIR 꺼두기
  
  Serial.begin(9600);
}

void loop()
{
  int val = digitalRead(3);
  if (val == 1) {
    digitalWrite(11, 1);
    digitalWrite(10, 0);
    Serial.println("cause");
  }
  else {
    digitalWrite(11, 0);
    digitalWrite(10, 1);
    Serial.println("none");
  }
  delay(200);
}