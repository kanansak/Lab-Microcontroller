#include<EEPROM.h>
#include<RTClib.h>
#include <Wire.h>
RTC_DS1307 rtc,D1,D2,D3;
String  t;
String gg;
void setup() {
  rtc.half(false);
  rtc.writeProtect(false);
  Serial.begin(115200);

}

void loop() {
  t = rtc.getTime();
  gg = String((t.date))+'/'+String(rtc,getMonth())+'/'+String((t.year))+"...TIME :"
  +String((t,hour))+'/'+String((t.min))+'/'+String((t.sec));
  int x = gg.tolnt();
  EEPROM.write(1,x);
  Serial.println(gg);
  Serial.println("=================");
  delay(1000);
}
