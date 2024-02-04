#define PIEZO_BUZZER1  3
#define PIEZO_BUZZER2  4

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    String strRead = Serial.readStringUntil('\n'); // BUZZER={freq1},{freq2}
    if (strRead.indexOf("BUZZER=") != -1)
    {
      int commaIndex = strRead.indexOf(',');
      float bzFreq1 = strRead.substring(7, commaIndex).toFloat();
      float bzFreq2 = strRead.substring(commaIndex+1, strRead.length()).toFloat();
      Serial.println(bzFreq1);
      Serial.println(bzFreq2);

      setBuzzer(bzFreq1, bzFreq2);
    }
  }
}

void setBuzzer(int freq1, int freq2)
{
  if (freq1 > 31 || freq2 > 31)
  {
    tone(PIEZO_BUZZER1, freq1);
    tone(PIEZO_BUZZER2, freq2);
    Serial.println("OKBUZZER");
  }
  else
  {
    noTone(PIEZO_BUZZER1);
    noTone(PIEZO_BUZZER2);
    Serial.println("OKBUZZER");
  }
}