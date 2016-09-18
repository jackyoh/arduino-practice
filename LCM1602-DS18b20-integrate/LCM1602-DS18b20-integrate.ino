#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  lcd.begin(16, 2);
  sensors.begin();
  lcd.setCursor(0, 0);
  delay(1000);  

}

void loop() {
 sensors.requestTemperatures();
 lcd.backlight();
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Temperature:");
 lcd.setCursor(0, 1);
 lcd.print(sensors.getTempCByIndex(0));
 delay(5000);
  
}
