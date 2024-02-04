int red = 9;
int green = 10;
int blue = 11;
int tpin = 4;
int epin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(tpin, OUTPUT);
  pinMode(epin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tpin, 0);
  digitalWrite(epin, 0); // 신호를 받으면 켜져야하기 때문에 꺼놓음
  delayMicroseconds(2);
  digitalWrite(tpin, 1);
  delayMicroseconds(10);
  digitalWrite(tpin, 0);

  long distance  = pulseIn(epin, 1) / 58.2;
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.print("(cm)");

  if (distance <= 5) {
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
  else if (distance <= 10) {
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 0);
  }
  else {
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 255);
  }
}
