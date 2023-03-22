#include "PCF8574.h"
#include <Wire.h>
PCF8574 PCF(0x20) ;
int P[] = { P0 , P1 , P2 , P3 , P4 , P5 , P6 , P7};
void setup() {
  Serial.begin(115200) ;
  PCF.begin();
  for(int j = 0 ; j<8 ;j++){
    PCF.pinMode(P[j], OUTPUT);
  }
}
void loop() {
  for(int i = 0 ; i<8 ; i++){
    PCF.digitalWrite(P[i],HIGH);
    delay(500) ;
    for(int i = 0 ; i<8 ; i++){
      PCF.digitalWrite(P[i], LOW);
    }
  } 
  for(int i = 0 ; i<5 ; i++){
    PCF.digitalWrite(P0, HIGH);
    PCF.digitalWrite(P1, HIGH);
    PCF.digitalWrite(P2, HIGH);
    PCF.digitalWrite(P3, HIGH);
    PCF.digitalWrite(P4, HIGH);
    PCF.digitalWrite(P5, HIGH);
    PCF.digitalWrite(P6, HIGH);
    PCF.digitalWrite(P7, HIGH);
    delay(500) ;
    PCF.digitalWrite(P0, LOW);
    PCF.digitalWrite(P1, LOW);
    PCF.digitalWrite(P2, LOW);
    PCF.digitalWrite(P3, LOW);
    PCF.digitalWrite(P4, LOW);
    PCF.digitalWrite(P5, LOW);
    PCF.digitalWrite(P6, LOW);
    PCF.digitalWrite(P7, LOW);
    delay(500) ;
  }
  
  for(int i = 0 ; i<4 ; i++){
    PCF.digitalWrite(P[i], HIGH);
    delay(100) ;
  }
  for(int x = 7 ; x>=4 ; x--){
    PCF.digitalWrite(P[x], HIGH);
    delay(100) ;
  }
  for(int x = 7 ; x>=4 ; x--){
    PCF.digitalWrite(P[x], LOW);
    delay(100) ;
  }
  for(int i = 0 ; i<4 ; i++){ 
    PCF.digitalWrite(P[i], LOW);
    delay(100) ;
  }
}
