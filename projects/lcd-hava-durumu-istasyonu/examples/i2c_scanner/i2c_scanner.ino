#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C tarama basladi...");
}

void loop() {
  byte error, address;
  int cihazSayisi = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C cihaz bulundu: 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      cihazSayisi++;
    }
  }

  if (cihazSayisi == 0) {
    Serial.println("I2C cihaz bulunamadi.");
  }

  delay(3000);
}
