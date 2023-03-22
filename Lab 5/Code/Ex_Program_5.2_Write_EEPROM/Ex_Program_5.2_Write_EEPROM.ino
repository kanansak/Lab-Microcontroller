#include<EEPROM.h>
int addr = 0;
byte data;
byte olddata;
boolean state13 = HIGH;

void setup() {
  Serial.begin(115200);
  while(!Serial){;}
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("========================");
  Serial.print("EEPROM Size : ");
  Serial.print(EEPROM.length(),DEC);
  Serial.println(" Byte(s)");
  Serial.println("========================");
}

void loop() {
  data = 0xFF;
  olddata = EEPROM.read(addr);
  state13 = !state13;
  if(data != olddata){
    EEPROM.write(addr,data);
    Serial.println("Write Data ");
    delay(1000);
  }
  else{
    Serial.println("Write Data ");
    digitalWrite(LED_BUILTIN,state13);
    Serial.print("EEPROM Address ");
    Serial.print(addr,HEX);
    Serial.print(" : ");
    Serial.println(data,HEX);
    delay(1000);
  }
}
