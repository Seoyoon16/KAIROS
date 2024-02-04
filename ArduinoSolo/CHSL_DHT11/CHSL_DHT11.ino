#include <DHT.h>
#include <DHT_U.h>

int DHTPIN = 7;
int DHTTYPE = DHT11;
int LED = 13;

DHT dht (DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(LED, OUTPUT);
  pinMode(9, OUTPUT); // B
  pinMode(10, OUTPUT); // R
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(h) || isnan(t)) { // Is Not a Number
    Serial.println("Failed to read from DHT sensor!");
    return ; // escape if구문 or loop, 여기서는  void loop()로 돌아가서 시작
  }

  Serial.print("Tem: ");
  Serial.print(t);
  Serial.print(" °C");
  Serial.print("    ");
  Serial.print("Hum: ");
  Serial.print(h);
  Serial.print(" %");
  Serial.println();

  delay(200);

  if (t>=22.5) {
    digitalWrite(9, 1);
    digitalWrite(10, 1);
  }
  else if (t>=22) {
    digitalWrite(9, 0);
    digitalWrite(10, 1);
  }
  else {
    digitalWrite(9, 0);
    digitalWrite(10, 0);
  }
}
