#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Hello World");
  delay(500);
}
unsigned int i;
unsigned int j;
void loop() {
  lcd.clear();
  for(i=0;i<16;i++){
    lcd.setCursor(i,0);
    lcd.print("*");
    delay(250);
  }
  for(j=0;j<16;j++){
    lcd.setCursor(j,1);
    lcd.print("*");
    delay(250);
  }
}
