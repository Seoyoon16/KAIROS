# define BUTTON 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (btn() == 1) Serial.println("BUTTON=CLICK");
}

int btn() {
  static int currBtn = 0;
  static int prevBtn = 0;

  currBtn = digitalRead(BUTTON);

  if (currBtn != prevBtn) {
    prevBtn = currBtn;
    if (currBtn == LOW) {
      return 1;
    }
    delay(50);
  }
  return 0;
}
