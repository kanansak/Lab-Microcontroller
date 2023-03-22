#include <EEPROM.h>
#define readMode 16
#define writeMode 17

int addrR = 0;
int addrw = 0;
byte data;
void setup() {
  pinMode (readMode, INPUT);
  pinMode (writeMode, INPUT);
  pinMode (4, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  if(digitalRead(readMode) == 0) {
    delay(150);
    Serial.print("Address Read ");
    Serial.print (addrR, HEX);
    Serial.print(": ");
    Serial.println(data);
    if(addrR<255) addrR++;
    else addrR = 0;
    delay(500);
  }
  if(digitalRead(writeMode) == 0) {
    delay(150);
    data++;
      if(data<256) EEPROM.write(addrw, data);
      else data = 0;
        Serial.print ("Address Write ");
        Serial.print(addrw, HEX);
        Serial.print(": ");
        Serial.println(data);
      if (addrw<255) addrw++;
      else addrw = 0;
      delay(500);
  }
}
