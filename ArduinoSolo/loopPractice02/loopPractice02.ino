void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=2; i<=9; i++) {
    for (int j=1; j<=9; j++) {
      // 1. Serial.println(String(i) + 'x' + String(j) + '=' + String(i*j) + ' ');
      // 2. char output[20]; // 출력할 문자열을 저장할 배열
      //    sprintf(output, "%dx%d=%d ", i, j, i*j); // 형식에 맞게 문자열 생성
      //    Serial.print(output); // 생성된 문자열 출력
      
      Serial.print(i);
      Serial.print('x');
      Serial.print(j);
      Serial.print('=');
      Serial.print(i*j);
      Serial.print(' ');
    }
    Serial.println();
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
