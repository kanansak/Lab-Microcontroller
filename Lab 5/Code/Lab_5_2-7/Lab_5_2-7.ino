#include <RTClib.h>
#include<String.h>
#include<EEPROM.h>
RTC_DS1307 RTC;
String DataY , DataM , DataD , Hour , Min , Sec;
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
  int Y = DataY.toInt();
  int M = DataM.toInt();
  int D = DataD.toInt();
  int H = Hour.toInt();
  int m = Min.toInt();
  int s = Sec.toInt();
  EEPROM.write(1,Y);
  EEPROM.write(1,M);
  EEPROM.write(1,D);
  EEPROM.write(1,H);
  EEPROM.write(1,m);
  EEPROM.write(1,s);
  Serial.print(Y);
  Serial.print('/');
  Serial.print(M);
  Serial.print('/');
  Serial.print(D);
  Serial.print("====");
  Serial.print(H);
  Serial.print(':');
  Serial.print(m);
  Serial.print(':');
  Serial.println(s);
  delay(1000);
}
