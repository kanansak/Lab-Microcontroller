#include <RTClib.h>
#include<String.h>
#include<EEPROM.h>
RTC_DS1307 RTC;
String DataY , DataM , DataD , Hour , Min , Sec;
int years, months, days, hours, mins, secs;
void setup() {
  Serial.begin(115200);
  Wire.begin();
  EEPROM.begin(1000);
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(__DATE__, __TIME__));  //สำหรับตั้งเวลา เมื่อตั้งเลาแล้วให้คอมเม้น หรือลบออก
  }
}

void loop() {
  DateTime now = RTC.now();   //อ่านค่าเวลาและวันที
  DataY = now.year();
  DataM = now.month();
  DataD = now.day();
  Hour = now.hour();
  Min = now.minute();
  Sec = now.second();
  EEPROM.write(0,DataY.toInt());
  EEPROM.write(2,DataM.toInt());
  EEPROM.write(3,DataD.toInt());
  EEPROM.write(4,Hour.toInt());
  EEPROM.write(5,Min.toInt());
  EEPROM.write(6,Sec.toInt());
  years = EEPROM.read(0);
  months = EEPROM.read(2);
  days = EEPROM.read(3);
  hours = EEPROM.read(4);
  mins = EEPROM.read(5);
  secs = EEPROM.read(6);
  Serial.print(DataY);
  Serial.print('/');
  Serial.print(months);
  Serial.print('/');
  Serial.print(days);
  Serial.print("====");
  Serial.print(hours);
  Serial.print(':');
  Serial.print(mins);
  Serial.print(':');
  Serial.println(secs);
  delay(1000);
}
