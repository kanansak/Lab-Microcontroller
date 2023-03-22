#include<EEPROM.h>
//#include <Keypad.h>
//#include <Keypad_I2C.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define I2CADDR 0x20
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '=', 'D'}
};
unsigned long timer;
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};
Keypad_I2C keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS,I2CADDR, PCF8574 );
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <DS1302.h>
String Settimer, Clockhour, Clockmin, Clocksec, Clock;
byte Hour;
byte Min, Sec, Date, Month;
int Year;
byte Modeset = 0, Mode = 0, lengthH, lengthM, lengthS;
bool StatusH = false, State = false, SET = false, SET1 = false, Clock1 = false;
String TIME;
DS1302 rtc(D6, D7, D8);

void setup(){
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(115200);
  //rtc.setDOW(THURSDAY);
  //rtc.setTime(16, 35, 0);
  //rtc.setDate(5, 11, 2020);
  Wire.begin();
  lcd.begin();
  keypad.begin(makeKeymap(keys));
}
void loop(){
  char key = keypad.getKey();
  if (key != NO_KEY && key == 'A' ) {
    Clock1 = true;
    Clockhour = "";
    Clockmin = "";
    Clocksec = "";
    lcd.clear();
    Modeset++;
    if (Modeset > 6) {
      Modeset = 1;
    }
    StatusH = true;
    if (Modeset == 1) {
      lcd.setCursor(0, 0);
      lcd.print("Set Hours ");
    }
    if (Modeset == 2) {
      Settimer = "";
      lcd.setCursor(0, 0);
      lcd.print("Set Minute");
    }
    if (Modeset == 3) {
      Settimer = "";
      lcd.setCursor(0, 0);
      lcd.print("Set Seccond");
    }
    if (Modeset == 4) {
      Settimer = "";
      lcd.setCursor(0, 0);
      lcd.print("Set Day");
    }
    if (Modeset == 5) {
      Settimer = "";
      lcd.setCursor(0, 0);
      lcd.print("Set Month");
    }
    if (Modeset == 6) {
      Settimer = "";
      lcd.setCursor(0, 0);
      lcd.print("Set Year");
    }
  }
  if (key != NO_KEY && Modeset == 1 && (key == '1' || key == '2' || key == '3' ||
  key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
    Settimer = Settimer + key;
    Hour = Settimer.toInt();
    lcd.setCursor(0, 1);
    lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 2 && (key == '1' || key == '2' || key == '3' ||
  key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
  Settimer = Settimer + key;
    Min = Settimer.toInt();
    lcd.setCursor(0, 1);
    lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 3 && (key == '1' || key == '2' || key == '3' ||
  key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
  Settimer = Settimer + key;
    Sec = Settimer.toInt();
    lcd.setCursor(0, 1);
    lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 4 && (key == '1' || key == '2' || key == '3' ||
  key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
    Settimer = Settimer + key;
    Date = Settimer.toInt();
    lcd.setCursor(0, 1);
    lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 5 && (key == '1' || key == '2' || key == '3' ||
  key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
    Settimer = Settimer + key;
    Month = Settimer.toInt();
    lcd.setCursor(0, 1);
    lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 6 && (key == '1' || key == '2' || key == '3' ||
  key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
  Settimer = Settimer + key;
    Year = Settimer.toInt();
    lcd.setCursor(0, 1);
    lcd.print(Settimer);
    SET = true;
    SET1 = true;
  }
  if (key != NO_KEY && key == '=') {
    Modeset = 0;
    Mode = 0;
    lcd.clear();
    State = true;
    Clock1 = false;
    StatusH = false;
    if (SET1 == true) {
      SET1 = false;
      Settimer = "";
      rtc.setTime(Hour, Min, Sec);
      rtc.setDate(Date, Month, Year);
    }
  }
  if (StatusH == false){
    Timer();
  }
  if (key != NO_KEY && key == 'C') {
    lcd.clear();
    StatusH = false;
    State = false;
    Clock1 = false;
    Settimer = "";
    Modeset = 0;
    Clockhour = "";
    Clockmin = "";
    Clocksec = "";
  }
  if (key != NO_KEY && key == '*'){
    Settimer = "";
    Clock1 = false;
    SET1 = false;
    StatusH = true;
    Mode++;
    lcd.clear();
    if (Mode > 3){
      Mode = 1;
    }
  }
  if (Mode == 1 && key != NO_KEY && Clock1 == false && (key == '1' || key ==
  '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' ||
  key == '9' || key == '0')) {
    lcd.clear();
    Clockhour = Clockhour + key;
    lengthH = Clockhour.length();
    lcd.setCursor(0, 0);
    lcd.print("Set alarm : Hour");
    lcd.setCursor(1, 1);
    lcd.print(Clockhour);
  }
  if (Mode == 2 && key != NO_KEY && Clock1 == false && (key == '1' || key ==
  '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' ||
  key == '9' || key == '0')) {
    lcd.clear();
    Clockmin = Clockmin + key;
    lengthM = Clockmin.length();
    lcd.setCursor(0, 0);
    lcd.print("Set alarm : Min");
    lcd.setCursor(1, 1);
    lcd.print(Clockmin);
  }
  if (Mode == 3 && key != NO_KEY && Clock == false && (key == '1' || key == '2'
  || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key
  == '9' || key == '0')) {
    lcd.clear();
    Clocksec = Clocksec + key;
    lengthS = Clocksec.length();
    lcd.setCursor(0, 0);
    lcd.print("Set alarm : Sec");
    lcd.setCursor(1, 1);
    lcd.print(Clocksec);
  }
  TIME = String(rtc.getTimeStr());
  if (State == true){
    Clock = Clockhour + ":" + Clockmin + ":" + Clocksec;
    if (Clock == TIME){
      lcd.clear();
      StatusH = true;
      lcd.setCursor(4, 0);
      lcd.print(TIME);
      lcd.setCursor(2, 1);
      lcd.print("Notification ");
    }
  }
}

void Timer() {
  if (millis() - timer >= 1000 && StatusH == false){
    timer = millis();
    lcd.setCursor(4, 0);
    lcd.print(rtc.getTimeStr());
    lcd.setCursor(3, 1);
    lcd.print(rtc.getDateStr());
  }
}
