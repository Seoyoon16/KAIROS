void setup() {
  Serial.begin(9600);
  
  for (int i=0; i<7; i++) {
    for (int j=0; j<i+1; j++ ) {
      Serial.print('*');
    }
    Serial.print("\n");
  }
  return 0;
}

void loop() {
  // put your main code here, to run repeatedly:

}
