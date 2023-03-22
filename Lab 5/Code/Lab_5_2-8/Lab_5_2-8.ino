#include <RTClib.h>
#include<String.h>
#include<EEPROM.h>
RTC_DS1307 RTC;
String DataY , DataM , DataD , Hour , Min , Sec;
int dataY,dataM,dataD,dataH,datam,dataS;
void setup() {
  Serial.begin(115200);
  Wire.begin();
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
  dataY = EEPROM.read(Y);
  dataM = EEPROM.read(M);
  dataD = EEPROM.read(D);
  dataH = EEPROM.read(H);
  datam = EEPROM.read(m);
  dataS = EEPROM.read(s);
  Serial.print(dataY);
  Serial.print('/');
  Serial.print(dataM);
  Serial.print('/');
  Serial.print(dataD);
  Serial.print("====");
  Serial.print(dataH);
  Serial.print(':');
  Serial.print(datam);
  Serial.print(':');
  Serial.println(dataS);
  delay(1000);
}
