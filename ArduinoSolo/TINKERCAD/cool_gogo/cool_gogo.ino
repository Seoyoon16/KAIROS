// C++ code
//

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  for (int i=7; i>=5; i--) {
    digitalWrite(i, 1);
    if (i==5) { delay(3000); }
    else if (i==6) { delay(4000); }
    else if (i==7) { delay(2000); }
    digitalWrite(i, 0);
    delay(500);
  } 
}