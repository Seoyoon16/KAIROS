int SPEED = 10;
int WHEEL = 9;
int val = 127;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SPEED, OUTPUT);
  pinMode(WHEEL, OUTPUT);
  digitalWrite(WHEEL, LOW);
  analogWrite(SPEED, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0) {
    char c = Serial.read();
    if (c == 'R') {
      digitalWrite(WHEEL, LOW);
      analogWrite(SPEED, val);
    }
    else if (c == 'L') {
      digitalWrite(WHEEL, HIGH);
      analogWrite(SPEED, val);
    }
    else if (c == 'S') {
      digitalWrite(WHEEL, LOW);
      analogWrite(SPEED, 0); // LOW: 멈춤, 0: 최소속도
    }
  }

}
