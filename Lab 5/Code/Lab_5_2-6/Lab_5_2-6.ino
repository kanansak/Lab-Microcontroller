#include <Wire.h>
#include<EEPROM.h>
#include "RTClib.h"
#include<String.h>
String DataY,DataM,DataD;
RTC_DS1307 RTC;

void setup () {
    Serial.begin(115200);
    Wire.begin();
    RTC.begin();
    

}
void loop () {
  DateTime now = RTC.now();
  DataY =now.year();
  DataM =now.month();
  DataD = now.day();
  //(t.hour()),(t.minute()),(t.second());
  /*Data = String((t.day))+'/'+String(RTC,month())+'/'+String((t.year))+"...TIME :"
  +String((t,hour))+'/'+String((t.min))+'/'+String((t.second));      */
  int Time = DataY.toInt();
  EEPROM.write(1,Time);
  Serial.println(DataY);
  Serial.println(DataM);
  Serial.println(DataD);
 }
