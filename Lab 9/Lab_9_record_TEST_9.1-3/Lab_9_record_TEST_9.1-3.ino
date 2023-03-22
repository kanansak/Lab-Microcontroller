#include <WiFi.h>
#include <WiFiAP.h>
#include <NTPClient.h>
#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>
#define I2CADDR 0x20
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const char *ssid = "Home";
const char *password = "09379414";
const long offsetTime = 25200;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", offsetTime);
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(13, 12, 14);
const byte ROWS = 4;
const byte COLS = 4; 
char keys[ROWS][COLS] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','B'}
};
byte rowPins[ROWS] = {0, 1, 2, 3}; 
byte colPins[COLS] = {4, 5, 6, 7}; 
Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, 
PCF8574 );
int hourNow, minuteNow, secondNow,dayNow,monthNow,yearNow;
int i1,i2,i3,i4;
 char c1,c2,c3,c4;
 char key;
double i = 0;
double a = millis();
double c ;
void setup() {
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
   Wire.begin( );
   kpd.begin( makeKeymap(keys) );
   //myRTC.setDS1302Time(18, 10, 10, 7, 18, 9, 2020);
  WiFi.begin(ssid, password);
   timeClient.begin();
}
void loop() {
  while(key == NO_KEY){
     myRTC.updateTime();     
     secondNow = myRTC.seconds;
     minuteNow = myRTC.minutes;
     hourNow = myRTC.hours;
     dayNow = myRTC.dayofmonth;
     monthNow = myRTC.month;
     yearNow = myRTC.year;
     
     Serial.print(dayNow);
     Serial.print("/");
     Serial.print(monthNow);
     Serial.print("/");
     Serial.print(yearNow);
     Serial.print(" ");
     Serial.print(hourNow);
     Serial.print(":");
     Serial.print(minuteNow);
     Serial.print(":");
     Serial.println(secondNow);
     lcd.setCursor(4, 0);
     lcd.print(dayNow);
     lcd.print(":");
     lcd.print(monthNow);
     lcd.print(":");
     lcd.print(yearNow);
     lcd.setCursor(4, 1);
     lcd.print(hourNow);
     lcd.print(":");
     lcd.print(minuteNow);
     lcd.print(":");
     lcd.print(secondNow);
     key = kpd.getKey();
     Serial.println(key);
     delay(150);
     if (key == '*') {
       lcd.clear();
       lcd.print(" Setup");
       delay(1000);
       lcd.clear();
       lcd.print("Setup year");
       char keypressed2 = kpd.waitForKey(); 
       if (keypressed2 != NO_KEY && keypressed2 !='*' && keypressed2 !='#' 
      && keypressed2 !='A' && keypressed2 !='B' && keypressed2 !='C' && keypressed2 
      !='D' ){
         c1 = keypressed2;
         lcd.setCursor(0, 1);
         lcd.print(c1);
       }
       char keypressed3 = kpd.waitForKey();
       if (keypressed3 != NO_KEY && keypressed3 !='*' && keypressed3 !='#' 
       && keypressed3 !='A' && keypressed3 !='B' && keypressed3 !='C' && keypressed3 
       !='D' ){
         c2 = keypressed3;
         lcd.setCursor(1, 1);
         lcd.print(c2);
       }
       char keypressed4 = kpd.waitForKey();
       if (keypressed4 != NO_KEY && keypressed4 !='*' && keypressed4 !='#' 
       && keypressed4 !='A' && keypressed4 !='B' && keypressed4 !='C' && keypressed4 
       !='D' ){
         c3 = keypressed4;
         lcd.setCursor(2, 1);
         lcd.print(c3);
       }
       char keypressed5 = kpd.waitForKey();
       if (keypressed5 != NO_KEY && keypressed5 !='*' && keypressed5 !='#' 
       && keypressed5 !='A' && keypressed5 !='B' && keypressed5 !='C' && keypressed5 
       !='D' ){
         c4 = keypressed5;
         lcd.setCursor(3, 1);
         lcd.print(c4);
       }
       i1=(c1-48)*1000; 
       i2=(c2-48)*100;
       i3=(c3-48)*10;
       i4=c4-48;
       int N_year=i1+i2+i3+i4;
       delay(500);
       lcd.clear();
       lcd.print("Setup month");
       char keypressed6 = kpd.waitForKey(); // here all programs are stopped until you enter the four digits then it gets compared to the code above
       if (keypressed6 != NO_KEY && keypressed6 !='*' && keypressed6 !='#' 
       && keypressed6 !='A' && keypressed6 !='B' && keypressed6 !='C' && keypressed6 
       !='D' ){
         c1 = keypressed6;
         lcd.setCursor(0, 1);
         lcd.print(c1);
       }
       char keypressed7 = kpd.waitForKey();
       if (keypressed7 != NO_KEY && keypressed7 !='*' && keypressed7 !='#' 
       && keypressed7 !='A' && keypressed7 !='B' && keypressed7 !='C' && keypressed7 
       !='D' ) {
         c2 = keypressed7;
         lcd.setCursor(1, 1);
         lcd.print(c2);
       }
       i1=(c1-48)*10;
       i2=c2-48;
       int N_month=i1+i2;
       delay(500);
       lcd.clear();
       lcd.print("Setup Day"); 
       char keypressed8 = kpd.waitForKey(); // here all programs are stopped until you enter the four digits then it gets compared to the code above
       if (keypressed8 != NO_KEY && keypressed8 !='*' && keypressed8 !='#' 
       && keypressed8 !='A' && keypressed8 !='B' && keypressed8 !='C' && keypressed8 
       !='D' ){
         c1 = keypressed8;
         lcd.setCursor(0, 1);
         lcd.print(c1);
       }
       char keypressed9 = kpd.waitForKey();
       if (keypressed9 != NO_KEY && keypressed9 !='*' && keypressed9 !='#' 
       && keypressed9 !='A' && keypressed9 !='B' && keypressed9 !='C' && keypressed9 
       !='D' ){
         c2 = keypressed9;
         lcd.setCursor(1, 1);
         lcd.print(c2);
       }
       i1=(c1-48)*10;
       i2=c2-48;
       int N_day=i1+i2;
       delay(500);
       lcd.clear();
       lcd.print("Setup hour"); 
       char keypressed10 = kpd.waitForKey(); // here all programs are stopped until you enter the four digits then it gets compared to the code above
       if (keypressed10 != NO_KEY && keypressed10 !='*' && keypressed10 
       !='#' && keypressed10 !='A' && keypressed10 !='B' && keypressed10 !='C' && 
       keypressed10 !='D' ){
         c1 = keypressed10;
         lcd.setCursor(0, 1);
         lcd.print(c1);
       }
       char keypressed11 = kpd.waitForKey();
       if (keypressed11 != NO_KEY && keypressed11 !='*' && keypressed11 
       !='#' && keypressed11 !='A' && keypressed11 !='B' && keypressed11 !='C' && 
       keypressed11 !='D' ){
         c2 = keypressed11;
         lcd.setCursor(1, 1);
         lcd.print(c2);
       }
       i1=(c1-48)*10;
       i2=c2-48;
       int N_hour=i1+i2;
       delay(500);
       lcd.clear();
       lcd.print("Setup minutes");
       char keypressed12 = kpd.waitForKey(); // here all programs are  stopped until you enter the four digits then it gets compared to the code above
       if (keypressed12 != NO_KEY && keypressed12 !='*' && keypressed12 
       !='#' && keypressed12 !='A' && keypressed12 !='B' && keypressed12 !='C' && 
       keypressed12 !='D' ){
         c1 = keypressed12;
         lcd.setCursor(0, 1);
         lcd.print(c1);
       }
       char keypressed13 = kpd.waitForKey();
       if (keypressed13 != NO_KEY && keypressed13 !='*' && keypressed13 
       !='#' && keypressed13 !='A' && keypressed13 !='B' && keypressed13 !='C' && 
       keypressed13 !='D' ){
         c2 = keypressed13;
         lcd.setCursor(1, 1);
         lcd.print(c2);
       }
       i1=(c1-48)*10;
       i2=c2-48;
       int N_minutes=i1+i2;
       delay(500);
       lcd.clear();
       myRTC.setDS1302Time(22, N_minutes, N_hour, 1, N_day, N_month, N_year); 
       key=NO_KEY; 
       }
       if (key == '#') {
         char keystopa = kpd.waitForKey();
         lcd.clear();
         lcd.print("press start");
         delay(100);
         if(keystopa == '1'){
           lcd.clear();
           a = millis();
         while(keystopa == '2'){
           c = millis();
           i = (c - a) / 1000;
           lcd.print(i);
           lcd.setCursor(7,0);
           lcd.print("Sec's");
           lcd.setCursor(0,0);
           Serial.println(c);
           Serial.println(a);
           Serial.println(i);
           Serial.println("......");
           delay(100);
        }
         if(keystopa == '1'){
           while(keystopa == '2') {
             lcd.setCursor(0,0);
             lcd.print(i);
             lcd.setCursor(11,0);
             lcd.print("");
             lcd.setCursor(0,0);
             delay(100);
           }
         }
       }
     }
   }
}
