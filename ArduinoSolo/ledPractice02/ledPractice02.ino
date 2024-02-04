const unsigned int led_0 = 3;
const unsigned int led_1 = 4;
const unsigned int led_2 = 6;
const unsigned int led_3 = 7;
const unsigned int led_4 = 8;
const unsigned int led_5 = 9;
const unsigned int led_6 = 10;
const unsigned int led_7 = 11;

void setup() {
  // put your setup code here, to run once:
  // Led 초기화
  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);

  // Led 켜기
  digitalWrite(led_0, HIGH);
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=3; i<=11; i++) {
    digitalWrite(i, 1);
    delay(100);
    digitalWrite(i, 0);
    delay(100);
  // }
  // int arr[8] = {3, 4, 6, 7, 8, 9, 10, 11};
  // for (int i=0; i<8; i++) {
  //   digitalWrite(arr[i], 1);
  //   delay(100);
  //   digitalWrite(arr[i], 0);
  //   delay(100);
  }



}
