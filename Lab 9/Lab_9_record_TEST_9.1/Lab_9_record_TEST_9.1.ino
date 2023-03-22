#include <RTClib.h>
#include<String.h>
#include"EEPROM.h"
#include "Keypad_I2C.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
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
Keypad_I2C keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR,PCF8574 );
LiquidCrystal_I2C lcd (0x27, 16, 2 );
RTC_DS1307 RTC;
String Settimer;
unsigned long timer2;
byte Msec, Msec2;
byte Hour, Seccond1, Seccond2, minute1, minute2, hours, hours1;
byte Min, Sec, Date, Mon;
int Year;
byte Modeset = 0, Stop = 0;
bool StatusH = false, Counttime = false, StatusF = false, StatusC = false, StatusA =
false;
void setup(){
  Serial.begin(115200 );
  Wire.begin();
  lcd.init();
  lcd.backlight();
  keypad.begin(makeKeymap(keys));
  rtc.begin();
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(__DATE__, __TIME__));  //สำหรับตั้งเวลา เมื่อตั้งเลาแล้วให้คอมเม้น หรือลบออก
  }
}
void loop(){
  DateTime setTime = rtc.now();   //อ่านค่าเวลาและวันที
  char key = keypad.getKey();
  if (key != NO_KEY && key == 'A' ){
    lcd.clear();
    Modeset++;
    Counttime = false;
    StatusA = false;
    StatusC = false;
    if (Modeset > 6 ){
    Modeset = 1;
  }
  StatusH = true;
  if (Modeset == 1) {
    lcd.setCursor(0, 0 );
    lcd.print("Set Hours ");
  }
  if (Modeset == 2) {
    Settimer = "";
    lcd.setCursor(0, 0) ;
    lcd.print("Set Minute");
  }
  if (Modeset == 3) {
    Settimer = "";
    lcd.setCursor(0, 0 );
    lcd.print("Set Seccond");
  }
  if (Modeset == 4) {
    Settimer = "";
    lcd.setCursor(0, 0) ;
    lcd.print("Set Day");
  }
  if (Modeset == 5) {
    Settimer = "";
    lcd.setCursor(0, 0 );
    lcd.print("Set Month");
  }
  if (Modeset == 6) {
    Settimer = "";
    lcd.setCursor(0, 0) ;
    lcd.print("Set Year");
  }
  }
  if (key != NO_KEY && Modeset == 1 && StatusA == false && (key == '1' || key == '2' ||
    key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' ||
    key == '0')) {
      Settimer = Settimer + key;
      Hour = Settimer.toInt();
      lcd.setCursor(0, 1 );
      lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 2 && StatusA == false && (key == '1' || key == '2' ||key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' ||
    key == '0')) {
      Settimer = Settimer + key;
      Min = Settimer.toInt();
      lcd.setCursor(0, 1) ;
      lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 3 && StatusA == false && (key == '1' || key == '2' ||
    key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' ||
    key == '0')) {
      Settimer = Settimer + key;
      Sec = Settimer.toInt();
      lcd.setCursor(0, 1 );
      lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 4 && StatusA == false && (key == '1' || key == '2' ||
    key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' ||
    key == '0')) {
      Settimer = Settimer + key;
      Date = Settimer.toInt();
      lcd.setCursor(0, 1);
      lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 5 && StatusA == false && (key == '1' || key == '2' ||key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' ||
    key == '0')) {
      Settimer = Settimer + key;
      Mon = Settimer.toInt();
      lcd.setCursor(0, 1 );
      lcd.print(Settimer);
  }
  if (key != NO_KEY && Modeset == 6 && StatusA == false && (key == '1' || key == '2' ||
    key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' ||
    key == '0')) {
      Settimer = Settimer + key;
      Year = Settimer.toInt();
      lcd.setCursor(0, 1 );
      lcd.print(Settimer);
  }
  if (key != NO_KEY && key == '=') {
    Modeset = 0;
    lcd.clear();
    StatusH = false;
    Counttime = false;
    if (StatusA == false) {
      DataY = setTime.year();
      DataM = setTime.month();
      DataD = setTime.day();
      Hour = setTime.hour();
      Min = setTime.minute();
      Sec = setTime.second();
      Settimer = "";
      StatusA = true;
    }
  }
  if (StatusH == false){
    Timer();
  }
  if (key != NO_KEY && key == '*') {
    lcd.clear();
    StatusH = false;
    Settimer = "";
    Modeset = 0;
    Counttime = false;
    StatusC = false;
    Stop = 0;
    minute1 = 0;
    Seccond1 = 0;
    Seccond2 = 0;
    minute2 = 0;
    hours = 0;
    hours1 = 0;
  }
  if (key != NO_KEY && key == 'B') {
    lcd.clear();
    StatusH = true;
    StatusA = true;
    Counttime = true;
    StatusF = true;
    StatusC = true;
  }
  if (key != NO_KEY && key == 'C'){
    Stop++;
  }
  if (Stop == 1){
    StatusC = false;
    Counttime = false;
  }
  if (Stop == 2) {
    StatusC = true;
    Counttime = true;
  }
  if (Stop > 2){
    Stop = 1;
  }
  if (Counttime == true) {
    Functioncount();
  }
}
void Timer() {
  if (millis() - timer >= 1000){
    timer = millis();
    lcd.setCursor(4, 0) ;
    lcd.print(rtc.getTimeStr());
    lcd.setCursor(3, 1) ;
    lcd.print(rtc.getDateStr());
  }
}
void Functioncount() {
  if (millis() - timer2 >= 1000 && StatusC == true) {
    Seccond1++;
    timer2 = millis();
  if (Seccond1 == 10{
    Seccond1 = 0; Seccond2++;
  }
  if (Seccond2 == 6) {
    Seccond1 = 0; Seccond2 = 0; minute1++;
  }
  if (minute1 == 10){
    minute1 = 0; Seccond1 = 0; Seccond2 = 0; minute2++;
  }
  if (minute2 == 6 {
    minute1 = 0; Seccond1 = 0; Seccond2 = 0; minute2 = 0; hours++;
  }
  if (hours == 10
  {
    minute1 = 0; Seccond1 = 0; Seccond2 = 0; minute2 = 0; hours = 0; hours1++;
  }
  lcd.setCursor(2, 0) ;
  lcd.print("Start timer");
  lcd.setCursor(9, 1) ;
  lcd.print(":");
  lcd.setCursor(6, 1) ;
  lcd.print(":");
  lcd.setCursor(11, 1) ;
  lcd.print(Seccond1 ;
  lcd.setCursor(10, 1) ;
  lcd.print(Seccond2) ;
  lcd.setCursor(8, 1) ;
  lcd.print(minute1) ;
  lcd.setCursor(7, 10 ;
  lcd.print(minute2) ;
  lcd.setCursor(5, 1) ;
  lcd.print(hours);
  lcd.setCursor(4, 1);
  lcd.print(hours1 ;
  }
}
