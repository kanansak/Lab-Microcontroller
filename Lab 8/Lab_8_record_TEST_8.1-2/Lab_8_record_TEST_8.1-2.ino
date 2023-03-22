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
  float voltageval = (val*5.0) / 4095;
  int resistor = voltageval/0.0005;
  lcd.setCursor(0,0);
  lcd.print("A>");
  lcd.print(val);
  lcd.setCursor(8,0);
  lcd.print("R>");
  lcd.print(resistor);
  lcd.setCursor(0,1);
  lcd.print("V>");
  lcd.print(voltageval);
  delay(100);
}
