#include <LiquidCrystal_I2C.h>
#include <Keypad_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#define I2CADDR 0x27  // กำหนด Address ของ I2C lcd
#define I2CADDR 0x20  // กำหนด Address ของ I2C
                      // วิธีการหา Address ของ I2C สามารถดูได้จากลิงค์ข้างล่าง 
                      // https://www.myarduino.net/article/98

const byte ROWS = 4;  // กำหนดจำนวนของ Rows
const byte COLS = 4;  // กำหนดจำนวนของ Columns
int lcdColumns = 22;
int lcdRows = 21;
byte Mode = 0;
int i = 0;

// กำหนด Key ที่ใช้งาน (4x4)
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// กำหนด Pin ที่ใช้งาน (4x4)
byte rowPins[ROWS] = {0, 1, 2, 3}; // เชื่อมต่อกับ Pin แถวของปุ่มกด
byte colPins[COLS] = {4, 5, 6, 7}; // เชื่อมต่อกับ Pin คอลัมน์ของปุ่มกด
char b1[3] = {'A','B','C'};
char b2[3] = {'D','E','F'};
char b3[3] = {'G','H','F'};
char b4[3] = {'J','K','L'};
char b5[3] = {'M','N','O'};
char b6[3] = {'P','Q','R'};
char b7[3] = {'S','T','U'};
char b8[3] = {'V','W','X'};
char b9[3] = {'Y','Z'};
// makeKeymap(keys) : กำหนด Keymap
// rowPins : กำหนด Pin แถวของปุ่มกด
// colPins : กำหนด Pin คอลัมน์ของปุ่มกด
// ROWS : กำหนดจำนวนของ Rows
// COLS : กำหนดจำนวนของ Columns
// I2CADDR : กำหนด Address ขอ i2C
// PCF8574 : กำหนดเบอร์ IC
Keypad_I2C keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574 );
LiquidCrystal_I2C lcd (0x27, lcdColumns, lcdRows);
void setup(){
  Wire.begin();  // เรียกการเชื่อมต่อ Wire
  keypad.begin( makeKeymap(keys) );  // เรียกกาเชื่อมต่อ
  Serial.begin(115200);
  lcd.init(); 
  lcd.backlight();
}
void loop(){
 
  char key = keypad.getKey();  // สร้างตัวแปรชื่อ key ชนิด char เพื่อเก็บตัวอักขระที่กด
  lcd.setCursor(0,1);
  lcd.print("Mode > ");
  lcd.print(Mode);
  if (key == '*'){  // ถ้าหากตัวแปร key มีอักขระ
    if(key){
      ++Mode;
      if(Mode == 2){
        Mode = 0;
      }
    }
  }
    if(Mode == 0){
      if(key){
        Serial.println(key);
        lcd.setCursor(0,0);
        lcd.print(key);
      }
    }
//-------------------------------   
    if(Mode == 1){
      if(key == '1'){
        if(i == 3){
          i=0;
        }
      lcd.setCursor(0,0);
      lcd.print(b1[i]);
      Serial.println(b1[i]);
      i++;
      }
    }
}
