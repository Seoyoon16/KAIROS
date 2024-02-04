void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char aaa = 'F';
  for (int i=5; i>=0; i--) {
    for (int j=0; i+j<6; j++) {
      char res = aaa - j;
      Serial.print(res);
    }
  Serial.println();
  }

  while (true) {
    continue;
  }
}

// for (int i=0; i<6; i++) {
//   for (int j=0; j<=i; j++)
//     continue;
// }

// for (char i ='F'; i>='A'; i--) {
//     for (char j ='F'; j>=i; j--) {
//       Serial.print(j);
//     }
// }