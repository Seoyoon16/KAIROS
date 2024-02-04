#define LED_RED 5
#define LED_GREEN 6
#define LED_BLUE 11

void setup() {
  Serial.begin(9600);
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 0);
}

void loop() {
  if (Serial.available() > 0)
  {
    String strRead = Serial.readStringUntil('\n'); // RGB={red},{green},{blue}
    if(strRead.indexOf("RGB=") != -1)
    {
      int commaIndex1 = strRead.indexOf(",");
      int commaIndex2 = strRead.indexOf(",", commaIndex1+1);
      int redValue = strRead.substring(4, commaIndex1).toInt();
      int greenValue = strRead.substring(commaIndex1+1, commaIndex2).toInt();
      int blueValue = strRead.substring(commaIndex2+1, strRead.length()).toInt();

      ledSet(redValue, greenValue, blueValue);

      Serial.println("OKRGB");
      Serial.println(redValue);
      Serial.println(greenValue);
      Serial.println(blueValue);
    }
  }
}

void ledSet(int red, int green, int blue)
{
  analogWrite(LED_RED, red);
  analogWrite(LED_GREEN, green);
  analogWrite(LED_BLUE, blue);
}