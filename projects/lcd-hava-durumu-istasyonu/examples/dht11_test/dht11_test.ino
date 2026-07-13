#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float sicaklik = dht.readTemperature();
  float nem = dht.readHumidity();

  if (isnan(sicaklik) || isnan(nem)) {
    Serial.println("DHT11 okuma hatasi.");
  } else {
    Serial.print("Sicaklik: ");
    Serial.print(sicaklik);
    Serial.print(" C | Nem: ");
    Serial.print(nem);
    Serial.println(" %");
  }

  delay(2000);
}
