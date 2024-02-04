void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0) { // flag check, 0 or 1
    char myInput = Serial.read();

    if (myInput == 'R') {
      Serial.println("RED LED");
    }
    else if (myInput == 'G') {
      Serial.println("GREEN LED");
    }
    else if (myInput == 'B') {
      Serial.println("BLUE LED");
    }
  }
}

//   char myInput = ' ';
//   myInput = Serial.read();

//   if (myInput == 'R') {
//     Serial.println("RED LED");
//   }
//   else if (myInput == 'G') {
//     Serial.println("GREEN LED");
//   }
//   else if (myInput == 'B') {
//     Serial.println("BLUE LED");
//   }
