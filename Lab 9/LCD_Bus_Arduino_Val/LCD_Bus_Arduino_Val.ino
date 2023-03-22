#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Show Quality Sensor");
}
unsigned int i;

void loop() {
  i = analogRead(A0);
  lcd.setCursor(0,1);
  lcd.print("Value : ");
  lcd.setCursor(8,1);
  lcd.print(i);
}
