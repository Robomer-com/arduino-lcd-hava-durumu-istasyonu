#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);

  if (!bmp.begin()) {
    Serial.println("BMP180 bulunamadi.");
    while (1) {}
  }
}

void loop() {
  Serial.print("Sicaklik: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C");

  Serial.print("Basinc: ");
  Serial.print(bmp.readPressure() / 100.0);
  Serial.println(" hPa");

  Serial.println("---");
  delay(2000);
}
