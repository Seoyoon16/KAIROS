const int tpin = 10;
const int epin = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(tpin, OUTPUT);
  pinMode(epin, INPUT);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tpin, 0);
  delayMicroseconds(2);
  digitalWrite(tpin, 1); // 초음파 발사
  delayMicroseconds(10);
  digitalWrite(tpin, 0); // 10 마이크로초 후 끔

  long duration = pulseIn(epin, 1); // 수신 high로, 그 때까지의 리턴 반환
  long distance = (duration/2) / 29.1;
  // 공기에서의 초음파 속도는 약 343m/s 이므로, 이를 2로 나누어 왕복 거리를 계산하고, 그 후에 cm로 변환하기 위해 29.1(약 343m/s를 2로 나눈 값의 cm 변환 상수)을 사용

  Serial.print(distance);
  Serial.println(" cm");
}
