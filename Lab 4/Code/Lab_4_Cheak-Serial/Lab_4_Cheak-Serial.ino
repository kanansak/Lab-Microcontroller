#include<EEPROM.h>

unsigned int addr = 0; //Define eeprom address is 0x00H
int mem_val;//stere value from memory address
int countsw = 0;
void setup() {
  Serial.begin(115200);//(115200,8,N,1)Baud rate , data bits , Parity bit , stop bit
  Serial.println("Lab 4");
  Serial.println("=========================");
  pinMode(6, INPUT);
  pinMode(7, INPUT);

}

void loop() {
  byte r = digitalRead(6);//Read
  delay(100);//debounce
  byte w = digitalRead(7);//Write
  delay(100);//debounce

  if (r == 0) {
    countsw = countsw + 1;
    Serial.print("Read address ");
    mem_val = EEPROM.read(addr);
    Serial.print(addr);
    Serial.print(": ");
    Serial.println(mem_val);
    Serial.println(countsw);
  }
  if (w == 0) {
    if (countsw > 0){
       countsw = countsw - 1;
    }
    Serial.print("Write ");
    EEPROM.write(addr, countsw);
    //EEPROM.commit(); //for esp32
    Serial.print("address ");
    Serial.print(addr);
    Serial.print(": ");
    Serial.println(countsw);
  }

}
