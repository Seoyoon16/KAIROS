#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &Wire, -1);

void setup() {
  // put your setup code here, to run once:
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 10); // 텍스트를 넣기 위한 위치
  oled.println("Hello");
  oled.setCursor(10, 20);
  oled.println("Hello");
  oled.setCursor(20, 30);
  oled.println("Hello");
  oled.setCursor(30, 40);
  oled.println("Hello");
  oled.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
