void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=5; i>0; i--) {
    for (int j=0; i+j<=5; j++ ) {
      Serial.print('$');
    }
  Serial.println();
  }
  
  while (true) {
    continue;
  }

}
