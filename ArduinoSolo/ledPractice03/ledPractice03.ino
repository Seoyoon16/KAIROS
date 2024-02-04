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
  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);

  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int t_high=0; t_high<=10; t_high++) {
    digitalWrite(13, 1);
    digitalWrite(3, 1);
    delay(t_high);
    digitalWrite(13, 0);
    digitalWrite(3, 0);
    delay(10-t_high);
  }

}
