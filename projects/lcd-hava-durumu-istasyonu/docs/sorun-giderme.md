# Sorun Giderme

## LCD ışığı yanıyor ama yazı görünmüyor
- I2C adresi 0x27 yerine 0x3F olabilir.
- I2C scanner kodunu çalıştırın.
- LCD kontrast ayarı varsa kontrol edin.

## BMP180 bulunamadı
- SDA/SCL bağlantılarını kontrol edin.
- VCC gerilimini kontrol edin.
- I2C scanner koduyla sensörün görünüp görünmediğine bakın.

## DHT11 NaN değeri veriyor
- DATA pini D2'ye bağlı mı kontrol edin.
- DHT sensor library yüklü mü kontrol edin.
- 2 saniye bekleme olmadan hızlı okuma yapmayın.

## Buzzer ses çıkarmıyor
- + ucu D9'a, - ucu GND'ye bağlı mı kontrol edin.
- Pasif buzzer ise tone() fonksiyonu kullanılmalıdır.

## Röle ters çalışıyor
- Bazı röle modülleri aktif LOW çalışır.
- Kodda HIGH/LOW durumlarını ters deneyin.

## Arduino reset atıyor
- Röle veya harici yük fazla akım çekiyor olabilir.
- Başlangıç testinde röleye harici yük bağlamayın.
