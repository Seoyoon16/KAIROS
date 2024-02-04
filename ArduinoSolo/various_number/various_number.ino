// C++ code
//

void setup()
{
  Serial.begin(115200);

  Serial.println(78, DEC);
  // 16진수: 0 1 .. 9 A B C D E F
  Serial.println(78, HEX);
  // 2진수
  Serial.println(78, BIN);

  // 소숫점 아래 자리수 지정
  Serial.println(1.23456, 0);
  Serial.println(1.23456, 2);
  Serial.println(1.23456, 4);
}

void loop()
{
 
}