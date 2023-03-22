#include <EEPROM.h>
#include<Time.h>
byte hour,minn,sec,dts,mnts,yrs;
char str[19],dmy[21];
int swd = 2;
int swm = 0;
int swy = 4;
void setup() {
  Serial.begin(115200);
  pinMode(swd,INPUT);
  pinMode(swm,INPUT);
  pinMode(swy,INPUT);
}

void loop() {
  dts = EEPROM.read(swd);
  mnts = EEPROM.read(swm);
  yrs = EEPROM.read(swy);

  if(dts == 0 && mnts == 0 && yrs == 0){
    dts = 1;
    EEPROM.write(swd,dts);
    mnts = 1;
    EEPROM.write(swm, mnts);
    yrs = 16;
    EEPROM.write(swy, yrs);
  }
  
  sec = EEPROM.read(0);
  sec++;
  EEPROM.write(0, sec);
  delay(1000);
  
  if(sec == 60){
    sec=0;
    EEPROM.write(0, sec);
    minn = EEPROM.read(1);
    minn++;
    EEPROM.write(1, minn);
  } 
  if(minn == 60){
    minn=0;
    EEPROM.write(1, minn);
    hour = EEPROM.read(2);
    hour++;
    EEPROM.write(2, hour);
  }
  if(hour == 24){
    hour = 0;
    EEPROM.write(2, hour);
    dts = EEPROM.read(3);
    dts++;
    EEPROM.write(3, dts);

      if(mnts == 12 && dts == 31){
        dts = 1;
        EEPROM.write(3, dts);
        mnts = 1;
        EEPROM.write(4, mnts);
        yrs = EEPROM.read(5);
        yrs++;
        EEPROM.write(5, yrs);
      }
  }
  if(dts == 30 && (mnts == 4 || mnts == 6 || mnts == 9 || mnts == 11) ){
    dts = 1;
    EEPROM.write(3, dts);
    mnts = EEPROM.read(4);
    mnts++;
    EEPROM.write(4, mnts);
  }
  else if(dts > 31 && (mnts == 1 || mnts == 3 || mnts == 5 || mnts == 7 ||
   mnts == 8 || mnts == 10 || mnts == 12)){
    dts = 1;
    EEPROM.write(3, dts);
    mnts = EEPROM.read(4);
    mnts++;
    EEPROM.write(4, mnts);
  }
  
  if(mnts == 2){
    if(yrs%4 == 0 || yrs%400 == 0 || yrs%100 == 0){
      if(dts > 29){
        dts = 1;
        EEPROM.write(3, dts);
        mnts = EEPROM.read(4);
        mnts++;
        EEPROM.write(4, mnts);
      }
    }
    else {
      if(dts > 28){
        dts = 1;
        EEPROM.write(3, dts);
        mnts = EEPROM.read(4);
        mnts++;
        EEPROM.write(4, mnts);
      }
    }
  }
  sprintf(dmy,"%.2d  %.2d  %.2d", EEPROM.read(3),EEPROM.read(4),EEPROM.read(5));
  Serial.println(dmy);
  Serial.println("---------------");
  sprintf(str,"%.2d  %.2d  %.2d", EEPROM.read(2),EEPROM.read(1),EEPROM.read(0));
  Serial.println(str);
  Serial.println("===============");
}
