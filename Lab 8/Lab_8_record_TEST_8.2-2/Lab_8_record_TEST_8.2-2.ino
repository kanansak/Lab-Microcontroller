#include <Keypad.h>
#include <Keypad_I2C.h>
#include <LiquidCrystal_I2C.h>
#include<Adafruit_Keypad.h>
#include<Wire.h>
#define I2CADDR 0x20
const byte row = 4;
const byte col = 4;
byte Mode = 0;
char keys[row][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowpin[row] = {0,1,2,3};
byte colpin[col] = {4,5,6,7};
char b1[] = {'A','B','C'};
char b2[] = {'D','E','F'};
char b3[] = {'G','H','F'};
char b4[] = {'J','K','L'};
char b5[] = {'M','N','O'};
char b6[] = {'P','Q','R'};
char b7[] = {'S','T','U'};
char b8[] = {'V','W','X'};
char b9[] = {'Y','Z'};
int i = 0;
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys),rowpin,colpin,row,col);
LiquidCrystal_I2C lcd(0x27 ,16,2);
void setup() {
  Wire.begin();
  customKeypad.begin();
  keypad.begin( makeKeymap(keys) ); 
  Serial.begin(115200);
  lcd.init();
}
void loop() {
  char key = keypad.getKey();  // สร้างตัวแปรชื่อ key ชนิด char เพื่อเก็บตัวอักขระที่กด
  lcd.setCursor(0,1);
  lcd.print("Mode : ");
  lcd.print(Mode);
  if(key == '*'){
    ++Mode;
    if(Mode == 2){
      Mode = 0
    }
  }
  if (Mode == 0){
    if(key){
      lcd.setCursor(0,0);
      lcd.print(key);
    }
  }
  if(Mode == 1){
    if(key == '1'){
      if(i == 3){
        i=0;
      }
    lcd.setCursor(0,0);
    lcd.print(b1[i]);
    i++;
    }
//-------------------------------    
    else if (key == '2'){
        if(i == 3){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b2[i]);
    i++;
  }
//-------------------------------    
  else if (key == '3'){
        if(i == 3){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b3[i]);
    i++;
  }
//-------------------------------    
  else if (key == '4'){
        if(i == 3){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b4[i]);
    i++;
  }
//-------------------------------    
  else if (key == '5'){
        if(i == 3){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b5[i]);
    i++;
  }
//-------------------------------    
  else if (key == '6'){
        if(i == 3){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b6[i]);
    i++;
  }
//-------------------------------    
  else if (key == '7'){
        if(i == 3){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b7[i]);
    i++;
  }
//-------------------------------      
  else if (key == '8'){
        if(i == 3){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b8[i]);
    i++;
  }
//-------------------------------      
  else if (key == '9'){
        if(i == 2){
        i=0;  
    }
    lcd.setCursor(0,0);
    lcd.print(b9[i]);
    i++;
  }
}
