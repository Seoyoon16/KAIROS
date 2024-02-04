#include <Bounce2.h>

int button = 2;

Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  debouncer1.attach(button);
  debouncer2.attach(11);

  debouncer1.interval(5);
  debouncer2.interval(5);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  debouncer1.update();
  debouncer2.update();

  if(debouncer1.fell()){
    Serial.println("Pressed");
  }
  if(debouncer2.fell()){
    Serial.println("Pressed too");
  }
  if(debouncer1.rose()){
    Serial.println("Released");
  }
  if(debouncer2.rose()){
    Serial.println("Released too");
  }
}
