#include <LiquidCrystal.h>
#include <DHT11.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT11 dht11(8);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.setCursor(0, 0);
}

void loop() {
  int temperature = dht11.readTemperature();
  int humidity = dht11.readHumidity();

  if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT  &&  humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C");
    Serial.print(" [] Humidity: ");
    Serial.println(humidity);
    

    lcd.setCursor(13, 0);
    lcd.print(temperature);
    lcd.setCursor(10, 1);
    lcd.print(humidity);



    delay(10000);


    lcd.setCursor(10, 1);
    lcd.print("   ");
    lcd.setCursor(13, 0);
    lcd.print("        ");

  } else {
    // Print error message based on the error code.
    Serial.println(DHT11::getErrorString(temperature));
  }
}
