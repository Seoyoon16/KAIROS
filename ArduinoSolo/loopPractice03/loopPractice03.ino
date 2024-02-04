void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int i = 0; int esum = 0;
  while (i <= 20) {
    esum += i;
    i+=2;
  }
  Serial.print("sum: ");
  Serial.println(esum);

}

void loop() {
  // put your main code here, to run repeatedly:

}
