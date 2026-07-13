# Arduino ile LCD Ekranlı Hava Durumu İstasyonu

Bu proje, **Robomer Hava Durumu Proje Seti** ile yapılabilecek örnek bir Arduino uygulamasıdır.

Arduino UNO; DHT11 sensörü ile sıcaklık ve nem, BMP180 sensörü ile barometrik basınç ve sıcaklık verilerini okur. Okunan değerler 16x2 I2C LCD ekranda gösterilir. Belirlenen eşik değerleri aşıldığında buzzer ve röle modülü ile alarm simülasyonu yapılır.

> Ürün sayfası: [Robomer Hava Durumu Proje Seti](https://robomer.com/hava-durumu-proje-seti)  
> Blog yazısı: [Arduino ile LCD Ekranlı Hava Durumu İstasyonu Nasıl Yapılır?](https://robomer.com/blog/arduino-ile-lcd-ekranli-hava-durumu-istasyonu-nasil-yapilir)  
> YouTube videosu: [VIDEO_URL_BURAYA](VIDEO_URL_BURAYA)

---

## Proje Görseli

![Arduino LCD Hava Durumu İstasyonu](assets/images/proje-gorseli.jpg)

---

## Proje Özeti

Bu proje ile Arduino üzerinde temel çevresel veri toplama ve görüntüleme sistemi kurulur.

Projede yapılan işlemler:

- DHT11 ile ortam sıcaklığı okunur.
- DHT11 ile ortam nemi okunur.
- BMP180 ile atmosfer basıncı okunur.
- BMP180 ile ikinci sıcaklık değeri okunur.
- Ölçülen değerler LCD ekranda sayfa sayfa gösterilir.
- Eşik değerler aşılırsa buzzer sesli uyarı verir.
- Röle modülü alarm çıkışı gibi çalıştırılır.
- Seri Monitör üzerinden tüm ölçümler takip edilir.

---

## Set İçeriği ve Robomer Bağlantıları

| Parça | Projedeki Görevi | Ürün Linki | Blog / Rehber |
|---|---|---|---|
| Arduino UNO R3 Klon + USB Kablo | Ana kontrol kartı | [Ürünü İncele](https://robomer.com/arduino-uno-r3-klon-usb-kablo-hediyeli-usb-chip-ch340) | [Arduino UNO Nedir?](https://robomer.com/blog/arduino-uno-r3-klon-nedir-arduino-uno-ile-baslangic-seviyesi-elektronik-projeleri) |
| 830 Pin Breadboard | Lehim yapmadan devre kurmak için kullanılır | [Ürünü İncele](https://robomer.com/buyuk-breadboard-830-pin)
| DHT11 Isı ve Nem Sensörü | Ortam sıcaklığı ve nem değerlerini okur | [Ürünü İncele](https://robomer.com/dht11-isi-ve-nem-sensoru-modulu-kablo-hediyeli) | [DHT11 Nedir?](https://robomer.com/blog/dht11-nedir-nasil-calisir-arduino-ile-sicaklik-ve-nem-sensoru-kullanimi) |
| BMP180 Basınç Sensörü | Barometrik basınç ve sıcaklık değeri okur | [Ürünü İncele](https://robomer.com/bmp180-dijital-hava-basinc-barometrik-sensor-gy-68) | [BMP180 Nedir?](https://robomer.com/blog/bmp180-nedir) |
| 16x2 I2C LCD Ekran | Ölçülen değerleri ekranda gösterir | [Ürünü İncele](https://robomer.com/16x2-mavi-lcd-ekran---i2c-lehimli) | [I2C LCD Ekran Nedir?](https://robomer.com/blog/i2c-16x2-lcd-ekran-nedir-arduino-ile-i2c-lcd-ekran-kullanimi) |
| Buzzer | Alarm durumunda sesli uyarı verir | [Ürünü İncele](https://robomer.com/5v-aktif-buzzer) | [Buzzer Nedir?](BUZZER_BLOG_URL_BURAYA) |
| 5V Röle Kartı | Alarm çıkışı simülasyonu için kullanılır | [Ürünü İncele](https://robomer.com/5v-1-kanal-role-karti) | [Röle Modülü Nedir?](https://robomer.com/blog/role-nedir-nasil-calisir-arduino-ile-5v-role-karti-kullanimi) |
| Jumper Kablo | Modüller arası bağlantı için kullanılır | [Ürünü İncele](https://robomer.com/40-adet-erkek-erkek-jumper-kablo-10cm)

---

## Parça Görselleri

| DHT11 | BMP180 | 16x2 LCD |
|---|---|---|
| ![DHT11 Isı ve Nem Sensörü](assets/images/dht11.jpg) | ![BMP180 Basınç Sensörü](assets/images/bmp180.jpg) | ![16x2 LCD Ekran](assets/images/lcd.jpg) |

---

## Devre Bağlantısı

| Modül | Pin | Arduino UNO |
|---|---:|---:|
| DHT11 | VCC | 5V |
| DHT11 | DATA / S | D2 |
| DHT11 | GND | GND |
| BMP180 | VCC | 3.3V veya modüle göre 5V |
| BMP180 | GND | GND |
| BMP180 | SDA | A4 |
| BMP180 | SCL | A5 |
| I2C LCD | VCC | 5V |
| I2C LCD | GND | GND |
| I2C LCD | SDA | A4 |
| I2C LCD | SCL | A5 |
| Buzzer | + | D9 |
| Buzzer | - | GND |
| Röle | VCC | 5V |
| Röle | GND | GND |
| Röle | IN | D7 |

> Not: Arduino UNO üzerinde I2C haberleşmesi için SDA pini A4, SCL pini A5 olarak kullanılır. Bu nedenle BMP180 ve I2C LCD aynı SDA/SCL hattını paylaşır.

---

## Devre Şeması

![Arduino Hava Durumu İstasyonu Devre Şeması](assets/images/devre-semasi.png)

---

## Gerekli Arduino Kütüphaneleri

Arduino IDE içinde **Library Manager** üzerinden şu kütüphaneleri yükleyin:

| Kütüphane | Kullanım Amacı |
|---|---|
| `DHT sensor library` | DHT11 sıcaklık ve nem sensörünü okumak için |
| `Adafruit Unified Sensor` | Adafruit sensör kütüphaneleri için ortak bağımlılık |
| `Adafruit BMP085 Library` | BMP180 / BMP085 basınç sensörünü okumak için |
| `LiquidCrystal I2C` | I2C 16x2 LCD ekranı kontrol etmek için |

---

## Kod Dosyaları

### Ana Proje Kodu

```text
src/hava_durumu_istasyonu/hava_durumu_istasyonu.ino
```

Bu kod DHT11, BMP180, LCD, buzzer ve röle modülünü birlikte kullanır.

### DHT11 Test Kodu

```text
examples/dht11_test/dht11_test.ino
```

DHT11 sensöründen sıcaklık ve nem değerlerini okuyarak Seri Monitör ekranına yazdırır.

### BMP180 Test Kodu

```text
examples/bmp180_test/bmp180_test.ino
```

BMP180 sensöründen sıcaklık ve basınç değerlerini okuyarak Seri Monitör ekranına yazdırır.

### I2C Scanner Kodu

```text
examples/i2c_scanner/i2c_scanner.ino
```

LCD ekranın veya BMP180 sensörünün I2C adresini bulmak için kullanılır. LCD çalışmıyorsa önce bu kodla adres kontrolü yapılmalıdır.

---

## Ana Kodda Kullanılan Eşik Değerler

Ana proje kodunda alarm durumunu belirlemek için şu eşik değerler kullanılır:

```cpp
float sicaklikAlarmEsigi = 30.0;  // C
float nemAlarmEsigi = 75.0;       // %
float dusukBasincEsigi = 990.0;   // hPa
```

Bu değerleri kendi ortam koşullarınıza göre değiştirebilirsiniz.

Örneğin daha hassas bir sıcaklık alarmı istiyorsanız:

```cpp
float sicaklikAlarmEsigi = 28.0;
```

---

## LCD Ekranda Gösterilen Sayfalar

LCD ekran 2 saniyede bir farklı bilgi sayfasına geçer.

| Sayfa | Gösterilen Bilgi |
|---|---|
| 1 | DHT11 sıcaklık ve nem değeri |
| 2 | BMP180 basınç değeri ve basınç yorumu |
| 3 | Alarm durumu |

---

## Hızlı Kurulum

1. Arduino IDE'yi açın.
2. Gerekli kütüphaneleri yükleyin.
3. Devre bağlantılarını tabloya göre yapın.
4. Önce `i2c_scanner.ino` ile LCD adresini kontrol edin.
5. Sonra `dht11_test.ino` kodunu yükleyip DHT11 değerlerini kontrol edin.
6. Ardından `bmp180_test.ino` kodunu yükleyip basınç değerlerini kontrol edin.
7. Her şey doğru çalışıyorsa ana proje kodunu yükleyin.

---

## Sorun Giderme

| Sorun | Olası Sebep | Çözüm |
|---|---|---|
| LCD ekranda yazı yok | I2C adresi farklı olabilir | `i2c_scanner.ino` ile adresi bulun, kodda `0x27` yerine doğru adresi yazın |
| DHT11 HATA yazıyor | DATA pini yanlış bağlanmış olabilir | DHT11 DATA pininin D2'ye bağlı olduğunu kontrol edin |
| BMP180 HATA yazıyor | I2C bağlantısı veya besleme hatası olabilir | SDA A4, SCL A5, VCC ve GND bağlantılarını kontrol edin |
| Buzzer sürekli ötüyor | Eşik değerler ortam koşullarına göre düşük olabilir | Kod içindeki eşik değerleri artırın |
| Röle çalışmıyor | IN pini veya VCC/GND bağlantısı hatalı olabilir | Röle IN pininin D7'ye bağlı olduğunu kontrol edin |
| Değerler kararsız | Kablo bağlantıları gevşek olabilir | Breadboard ve jumper bağlantılarını sıkılaştırın |

Detaylı notlar için:

```text
docs/sorun-giderme.md
```

---


## Dosya Yapısı

```text
lcd-hava-durumu-istasyonu/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── assets/
│   └── images/
│       ├── proje-gorseli.jpg
│       ├── devre-semasi.png
│       ├── dht11.jpg
│       ├── bmp180.jpg
│       └── lcd.jpg
│
├── docs/
│   ├── baglanti-semasi.md
│   └── sorun-giderme.md
│
├── examples/
│   ├── dht11_test/
│   │   └── dht11_test.ino
│   ├── bmp180_test/
│   │   └── bmp180_test.ino
│   └── i2c_scanner/
│       └── i2c_scanner.ino
│
└── src/
    └── hava_durumu_istasyonu/
        └── hava_durumu_istasyonu.ino
```

---

## Robomer

Arduino, sensör, modül, breadboard, jumper kablo ve robotik proje malzemeleri için:

[robomer.com](https://robomer.com)

---

## Lisans

Bu proje Robomer Eğitim İçeriği Lisansı ile paylaşılmıştır.

Kodlar eğitim, kişisel kullanım ve öğrenme amacıyla kullanılabilir. Robomer logosu, ürün görselleri, proje görselleri, blog metinleri ve marka unsurları Robomer'e aittir.
