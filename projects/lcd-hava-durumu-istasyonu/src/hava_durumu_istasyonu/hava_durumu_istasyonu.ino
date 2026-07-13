#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Adafruit_BMP085.h>

// -------------------- PIN TANIMLARI --------------------
#define DHTPIN 2
#define DHTTYPE DHT11

#define ROLE_PIN 7
#define BUZZER_PIN 9

// -------------------- NESNELER --------------------
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

// LCD adresi genellikle 0x27 veya 0x3F olur.
// LCD çalışmazsa 0x27 yerine 0x3F deneyin.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------------------- EŞİK DEĞERLER --------------------
float sicaklikAlarmEsigi = 30.0;  // C
float nemAlarmEsigi = 75.0;       // %
float dusukBasincEsigi = 990.0;  // hPa

// -------------------- ZAMANLAMA --------------------
unsigned long oncekiEkranZamani = 0;
int ekranSayfasi = 0;

void setup() {
  Serial.begin(9600);

  pinMode(ROLE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(ROLE_PIN, LOW);
  digitalWrite(BUZZER_PIN, HIGH);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Robomer");
  lcd.setCursor(0, 1);
  lcd.print("Hava Durumu");
  delay(2000);
  lcd.clear();

  dht.begin();

  if (!bmp.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("BMP180 HATA");
    lcd.setCursor(0, 1);
    lcd.print("Baglanti?");
    Serial.println("BMP180 bulunamadi. SDA/SCL ve VCC/GND baglantilarini kontrol edin.");

    while (1) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      delay(800);
    }
  }
}

void loop() {
  float dhtSicaklik = dht.readTemperature();
  float nem = dht.readHumidity();
  float bmpSicaklik = bmp.readTemperature();
  float basinc = bmp.readPressure() / 100.0; // hPa

  bool dhtHatasi = isnan(dhtSicaklik) || isnan(nem);

  Serial.print("DHT Sicaklik: ");
  Serial.print(dhtSicaklik);
  Serial.print(" C | Nem: ");
  Serial.print(nem);
  Serial.print(" % | BMP Sicaklik: ");
  Serial.print(bmpSicaklik);
  Serial.print(" C | Basinc: ");
  Serial.print(basinc);
  Serial.println(" hPa");

  bool alarmDurumu = false;

  if (!dhtHatasi) {
    if (dhtSicaklik >= sicaklikAlarmEsigi || nem >= nemAlarmEsigi) {
      alarmDurumu = true;
    }
  }

  if (basinc <= dusukBasincEsigi) {
    alarmDurumu = true;
  }

  if (alarmDurumu) {
    digitalWrite(ROLE_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(150);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    digitalWrite(ROLE_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // LCD ekranı sayfa sayfa güncelle
  if (millis() - oncekiEkranZamani > 2000) {
    oncekiEkranZamani = millis();
    ekranSayfasi++;
    if (ekranSayfasi > 2) ekranSayfasi = 0;

    lcd.clear();

    if (dhtHatasi) {
      lcd.setCursor(0, 0);
      lcd.print("DHT11 HATA");
      lcd.setCursor(0, 1);
      lcd.print("D2 kontrol");
      return;
    }

    if (ekranSayfasi == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Sicaklik:");
      lcd.print(dhtSicaklik, 1);
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("Nem:");
      lcd.print(nem, 0);
      lcd.print("%");
    }

    else if (ekranSayfasi == 1) {
      lcd.setCursor(0, 0);
      lcd.print("Basinc:");
      lcd.print(basinc, 0);

      lcd.setCursor(0, 1);
      lcd.print("hPa ");
      if (basinc > 1015) {
        lcd.print("Yuksek");
      } else if (basinc < 1005) {
        lcd.print("Dusuk");
      } else {
        lcd.print("Normal");
      }
    }

    else {
      lcd.setCursor(0, 0);
      lcd.print("Alarm Durumu");

      lcd.setCursor(0, 1);
      if (alarmDurumu) {
        lcd.print("UYARI AKTIF");
      } else {
        lcd.print("Normal");
      }
    }
  }

  delay(300);
}
