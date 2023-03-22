#include<EEPROM.h>
int addr = 0;
byte data;
boolean state13 = HIGH;

void setup() {
  Serial.begin(115200);
  while(!Serial){;}
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  data = EEPROM.read(addr); state13 = !state13;
  digitalWrite(LED_BUILTIN, state13);
  Serial.print("EEPROM Address ");
  Serial.print(addr,HEX);
  Serial.print(" : ");
  Serial.println(data,HEX); delay(1000);
}
