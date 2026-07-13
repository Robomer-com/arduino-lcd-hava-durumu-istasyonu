# Bağlantı Şeması

## DHT11

| DHT11 | Arduino UNO |
|---|---|
| VCC | 5V |
| DATA/S | D2 |
| GND | GND |

## BMP180

| BMP180 | Arduino UNO |
|---|---|
| VCC | 3.3V veya modüle göre 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## I2C LCD

| LCD | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## Buzzer

| Buzzer | Arduino UNO |
|---|---|
| + | D9 |
| - | GND |

## Röle

| Röle | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| IN | D7 |

## Notlar

- BMP180 ve I2C LCD aynı SDA/SCL hattını paylaşabilir.
- Arduino UNO'da SDA = A4, SCL = A5.
- Röle ile yüksek voltajlı cihaz bağlamayın; eğitim videosunda sadece rölenin LED/tıklama simülasyonu kullanılmalıdır.
