#include <LiquidCrystal_I2C.h>
int lcdColumns = 22;
int lcdRows = 21;
unsigned int val = 0;
LiquidCrystal_I2C lcd(0x27 , lcdColumns , lcdRows);
void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() {
  val = analogRead(36);
  int resistor = map(val ,0,4095,0,10000);
  float voltageval = (val*5.0) / 4095;
  lcd.setCursor(0,0);
  lcd.print("R>");
  lcd.print(resistor);
  lcd.setCursor(9,0);
  lcd.print("A>");
  lcd.print(val);
  lcd.setCursor(0,1);
  lcd.print("V>");
  lcd.print(voltageval);
  delay(100);
}
