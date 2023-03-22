#include"Keypad_I2C.h"
#include <Keypad_I2C.h>
#include"LiquidCrystal_I2C.h"
#include"Wire.h"
#define I2CADDR 0x20
#define LiquidCrystal_I2C_Addr 0x27
const byte ROWS = 4 ;
const byte COLS = 4 ;
char keys[ROWS][COLS] = {
{'1', '2', '3', '+'},
{'4', '5', '6', '-'},
{'7', '8', '9', '*'},
{'M', '0', '=', '/'}
};
byte rowPins[ROWS] = {0 , 1 , 2 , 3};
byte colPins[COLS] = {4 , 5 , 6 , 7};
Keypad_I2C keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR,
PCF8574 );
LiquidCrystal_I2C lcd(LiquidCrystal_I2C_Addr , 16 , 2);
String num1 , num2 ;
String inA , inB ;
bool presentValue = false;
bool final0 = false;
bool finalBit = false ;
int answer = 0;
char op;
bool Clear = false;
bool next = false ;
byte Mode = 0 ;
byte logic = 0 ;
byte Size = 0;
byte Size2 = 0;
String numBer ;
String numBer2 ;
String allSize2[8] ;
bool num1_Shiftbit = false ;
char opBit ;
int ansBit ;
bool ClearBit = false ;
int i = 0;
int j = 0;
int b = 0;
int b1 = -1;

//======Binary Covertor========
bool presentValueBase2 = false ;
String num1_2Base ;
bool final_2Base ;
char op_2Base ;
bool Clear_2Base = false ;

//======Power=======
bool presentValue_power = false ;
String num1_power ;
String num2_power ;
bool final_power = false ;
char op_power ;
int answer_power ;
bool Clear_power = false ;
void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();
  keypad.begin(makeKeymap(keys));
  lcd.setCursor(3, 0);
  lcd.print("LOGIC GATE");
  lcd.setCursor(3, 1);
  lcd.print("Calculator");
  delay(2000);
  lcd.clear();
}
void loop() {
  char key = keypad.getKey();
  if (key == 'M') { // M = mode
    lcd.clear();
    Mode++;
    if (Mode == 6) {
      Mode = 0 ;
    }
  }
  lcd.setCursor(0, 1);
  lcd.print("M");
  lcd.setCursor(1, 1);
  lcd.print(Mode);
  if (Mode == 0) {
      lcd.setCursor(3, 1);
      lcd.print("Calculate"); // mode คํานวณ
      if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key =='5' ||
      key == '6' || key == '7' || key == '8' || key == '9' || key == '0'))
      {
    if (presentValue == false){
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(0, 0);
      lcd.print(num1);
    }else{
      num2 = num2 + key;
      int numLength = num2.length();
      int numLength1 = num1.length();
      lcd.setCursor(1 + numLength1, 0);
      lcd.print(num2);
      final0 = true;
      }
    }
    else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' ||key== '-' || key == '+'))
    {
      if (presentValue == false){
        int numLength = num1.length();
        presentValue = true;
        op = key;
        lcd.setCursor(0 + numLength, 0);
        lcd.print(op);
      }
    }
    else if (final0 == true && key != NO_KEY && key == '=' && Clear == false) {
      if (op == '+') {
        answer = num1.toInt() + num2.toInt();
      }
      else if (op == '-') {
        answer = num1.toInt() - num2.toInt();
      }
      else if (op == '*') {
        answer = num1.toInt() * num2.toInt();
      }
      else if (op == '/') {
        answer = num1.toInt() / num2.toInt();
      }
      lcd.clear();
      lcd.setCursor(16, 1);
      lcd.autoscroll(); // ขยับauto
      lcd.print(answer);
      lcd.noAutoscroll();
      Clear = true ;
    }
    else if (key != NO_KEY && key == '=' && Clear == true) { // รีค่ากลับเพื่อให้สามารถทําใหม่ได้
      lcd.clear();
      Clear = false ;
      presentValue = false;
      final0 = false;
      num1 = "";
      num2 = "";
      answer = 0;
      op = ' ';
    }
  }
  if (Mode == 1){
    lcd.setCursor(3, 1);
    lcd.print("LOGIC");
    if (key != NO_KEY && next == false && (key == '1' || key == '0')) {
      inA = key ;
      lcd.setCursor(0, 0);
      lcd.print(inA);
      next = true ;
    } else if (key != NO_KEY && next == true && (key == '1' || key == '0')) {
        inB = key ;
        lcd.setCursor(5, 0);
        lcd.print(inB);
        next = false ;
    } else if (key != NO_KEY && key == '3') {
        logic++ ;
        if (logic == 6) {
          logic = 0 ;
        }
    } else if (key != NO_KEY && key == '=' ) {
        lcd.clear();
        next = false ;
        logic = 0 ;
        inA = ' ';
        inB = ' ';
    }
    switch (logic){
      case 1 :
        lcd.setCursor(9, 1);
        lcd.print("NOT : ");
        lcd.print(!inA.toInt());
        break ;
      case 2 :
        lcd.setCursor(9, 1);
        lcd.print("AND : ");
        lcd.print(inA.toInt() && inB.toInt());
        break ;
      case 3 :
        lcd.setCursor(9, 1);
        lcd.print(" OR : ");
        lcd.print(inA.toInt() || inB.toInt());
        break ;
      case 4 :
        lcd.setCursor(9, 1);
        lcd.print("NOR : ");
        lcd.print(!(inA.toInt() || inB.toInt()));
        break ;
      case 5 :
        lcd.setCursor(9, 1);
        lcd.print("NAND: ");
        lcd.print(!(inA.toInt() && inB.toInt()));
        break ;
      }
  }
  if (Mode == 2 ) {
      lcd.setCursor(3, 1);
      lcd.print("Shift Bit");
      if (key != NO_KEY && Size == 0 && (key == '1' || key == '2' || key == '3' || key ==
      '4'|| key == '5' || key == '6' || key == '7' || key == '8' || key== '9' || key == '0')) {
      if (num1_Shiftbit == false){
        numBer = numBer + key;
        int numBerLength = numBer.length();
        lcd.setCursor(0, 0);
        lcd.print(numBer);
      } else{
        numBer2 = numBer2 + key;
        int numBer2Length = numBer2.length();
        int numBer1Length = numBer.length();
        lcd.setCursor(2 + numBer1Length, 0);
        lcd.print(numBer2);
        finalBit = true ;
      }
      } else if (num1_Shiftbit == false && key != NO_KEY && (key == '+' || key == '-')){
        if (num1_Shiftbit == false) {
        int numLength = numBer.length();
        num1_Shiftbit = true ;
        opBit = key ;
        lcd.setCursor(0 + numLength , 0);
        if (opBit == '+') {
          lcd.print("<<");
        } else{
          lcd.print(">>");
          }
        }
    }
    else if (finalBit == true && key != NO_KEY && key == '=' && ClearBit == false){
      if (opBit == '+') {
        ansBit = numBer.toInt() << numBer2.toInt();
      } else if (opBit == '-'){
        ansBit = numBer.toInt() >> numBer2.toInt();
      }
      lcd.clear();
      lcd.setCursor(16, 0);
      lcd.autoscroll();
      lcd.print(ansBit);
      lcd.noAutoscroll();
      ClearBit = true ;
    }
    else if (key != NO_KEY && key == '=' && ClearBit == true){
      lcd.clear();
      ClearBit = false ;
      num1_Shiftbit = false ;
      numBer = ' ';
      numBer2 = ' ';
      ansBit = 0 ;
      opBit = ' ' ;
    }
  }
  if (Mode == 3) {
      lcd.setCursor(3, 1);
      lcd.print("Rotate Bit");
      if (key != NO_KEY && Size2 == 0 && (key == '0' || key == '1')) {
        allSize2[0] = key;
        lcd.setCursor(0, 0);
        lcd.print(allSize2[0]);
        Size2 = 1;
      } else if (key != NO_KEY && Size2 == 1 && (key == '0' || key == '1')) {
        allSize2[1] = key;
        lcd.setCursor(1, 0);
        lcd.print(allSize2[1]);
        Size2 = 2;
      } else if (key != NO_KEY && Size2 == 2 && (key == '0' || key == '1')) {
        allSize2[2] = key;
        lcd.setCursor(2, 0);
        lcd.print(allSize2[2]);
        Size2 = 3;
      } else if (key != NO_KEY && Size2 == 3 && (key == '0' || key == '1')) {
        allSize2[3] = key;
        lcd.setCursor(3, 0);
        lcd.print(allSize2[3]);
        Size2 = 4;
      } else if (key != NO_KEY && Size2 == 4 && (key == '0' || key == '1')) {
        allSize2[4] = key;
        lcd.setCursor(4, 0);
        lcd.print(allSize2[4]);
        Size2 = 5;
      } else if (key != NO_KEY && Size2 == 5 && (key == '0' || key == '1')) {
        allSize2[5] = key;
        lcd.setCursor(5, 0);
        lcd.print(allSize2[5]);
        Size2 = 6;
      } else if (key != NO_KEY && Size2 == 6 && (key == '0' || key == '1')) {
        allSize2[6] = key;
        lcd.setCursor(6, 0);
        lcd.print(allSize2[6]);
        Size2 = 7;
      } else if (key != NO_KEY && Size2 == 7 && (key == '0' || key == '1')) {
        allSize2[7] = key;
        lcd.setCursor(7, 0);
        lcd.print(allSize2[7]);
        Size2 = 8;
      } else if (key != NO_KEY && key == '4') { // กด 4 เพื่อหมุนขวา
          b++ ;
          if (b == 1) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[1]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[2]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[3]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[4]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[5]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[6]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[7]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[0]);
          } else if (b == 2) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[2]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[3]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[4]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[5]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[6]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[7]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[0]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[1]);
          } else if (b == 3) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[3]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[4]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[5]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[6]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[7]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[0]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[1]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[2]);
          } else if (b == 4) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[4]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[5]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[6]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[7]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[0]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[1]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[2]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[3]);
          } else if (b == 5) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[5]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[6]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[7]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[0]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[1]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[2]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[3]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[4]);
          } else if (b == 6) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[6]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[7]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[0]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[1]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[2]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[3]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[4]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[5]);
          } else if (b == 7) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[7]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[0]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[1]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[2]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[3]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[4]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[5]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[6]);
          } else if (b == 8) {
              lcd.setCursor(0 , 0);
              lcd.print(allSize2[0]);
              lcd.setCursor(1 , 0);
              lcd.print(allSize2[1]);
              lcd.setCursor(2 , 0);
              lcd.print(allSize2[2]);
              lcd.setCursor(3 , 0);
              lcd.print(allSize2[3]);
              lcd.setCursor(4 , 0);
              lcd.print(allSize2[4]);
              lcd.setCursor(5 , 0);
              lcd.print(allSize2[5]);
              lcd.setCursor(6 , 0);
              lcd.print(allSize2[6]);
              lcd.setCursor(7 , 0);
              lcd.print(allSize2[7]);
              b = 0 ;
          }
          } else if (key != NO_KEY && key == '6') { // กด4 หมุนบิต ซ้าย
              b1++ ;
              if (b1 == 0) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[0]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[1]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[2]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[3]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[4]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[5]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[6]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[7]);
              }else if (b1 == 1) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[7]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[0]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[1]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[2]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[3]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[4]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[5]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[6]);
              } else if (b1 == 2) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[6]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[7]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[0]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[1]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[2]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[3]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[4]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[5]);
              } else if (b1 == 3) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[5]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[6]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[7]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[0]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[1]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[2]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[3]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[4]);
              } else if (b1 == 4) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[4]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[5]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[6]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[7]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[0]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[1]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[2]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[3]);
              } else if (b1 == 5) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[3]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[4]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[5]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[6]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[7]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[0]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[1]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[2]);
              } else if (b1 == 6) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[2]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[3]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[4]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[5]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[6]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[7]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[0]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[1]);
              } else if (b1 == 7) {
                  lcd.setCursor(0 , 0);
                  lcd.print(allSize2[1]);
                  lcd.setCursor(1 , 0);
                  lcd.print(allSize2[2]);
                  lcd.setCursor(2 , 0);
                  lcd.print(allSize2[3]);
                  lcd.setCursor(3 , 0);
                  lcd.print(allSize2[4]);
                  lcd.setCursor(4 , 0);
                  lcd.print(allSize2[5]);
                  lcd.setCursor(5 , 0);
                  lcd.print(allSize2[6]);
                  lcd.setCursor(6 , 0);
                  lcd.print(allSize2[7]);
                  lcd.setCursor(7 , 0);
                  lcd.print(allSize2[0]);
                  b1 = 0 ;
              }
              } else if (key != NO_KEY && key == '=') {
                  lcd.clear();
                  b1 = -1 ;
                  b = 0 ;
                  Size2 = 0 ;
                  for (int y = 0 ; y < 8 ; y++) {
                  allSize2[y] = ' ' ;
                  }
              }
 }

  if (Mode == 4) {
    lcd.setCursor(3, 1);
    lcd.print("DEC");
    if (key != NO_KEY && (key == '0' || key == '1' || key == '2' || key == '3' || key ==
    '4' ||key == '5' || key == '6' || key == '7' || key == '8' || key == '9' )){
      if (presentValueBase2 == false){
        num1_2Base = num1_2Base + key;
        int numLength = num1_2Base.length();
        lcd.setCursor(0, 0);
        lcd.print(num1_2Base);
        final_2Base = true ;
      }
    }
    else if (presentValueBase2 == false && key != NO_KEY && (key == '*' || key ==
    '-' ||key == '+')){
      if (presentValueBase2 == false){
        int numLength = num1_2Base.length();
        presentValueBase2 = true;
        op_2Base = key;
        lcd.setCursor(0 + numLength, 0);
        lcd.print("=");
       }
    }
    else if (final_2Base == true && key != NO_KEY && key == '=' && Clear_2Base==false) {
      if (op_2Base == '+') {
        lcd.clear();
        lcd.setCursor(16, 1);
        lcd.autoscroll();
        lcd.print(num1_2Base.toInt(), BIN);
        lcd.noAutoscroll();
      }
      else if (op_2Base == '-') {
        lcd.clear();
        lcd.setCursor(16, 1);
        lcd.autoscroll();
        lcd.print( num1_2Base.toInt(), OCT);
        lcd.noAutoscroll();
      }
      else if (op_2Base == '*') {
        lcd.clear();
        lcd.setCursor(16, 1);
        lcd.autoscroll();
        lcd.print(num1_2Base.toInt(), HEX);
        lcd.noAutoscroll();
      }
      Clear_2Base = true ;
      }
      else if (key != NO_KEY && key == '=' && Clear_2Base == true) {
        lcd.clear();
        Clear_2Base = false ;
        presentValueBase2 = false;
        final_2Base = false;
        num1_2Base = "";
        op_2Base = ' ';
      }
  } 
  if (Mode == 5) {
    lcd.setCursor(4, 1);
    lcd.print("POWER");
    if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key ==
    '5'|| key == '6' || key == '7' || key == '8' || key == '9' || key == '0')){
      if (presentValue_power != true){
        num1_power = num1_power + key;
        int numLength = num1_power.length();
        lcd.setCursor(0, 0);
        lcd.print(num1_power);
      }else{
        num2_power = num2_power + key;
        int numLength = num2_power.length();
        int numLength1 = num1_power.length();
        lcd.setCursor(1 + numLength1, 0);
        lcd.print(num2_power);
        final_power = true;
       }
    }
    else if (presentValue_power == false && key != NO_KEY && key == '+'){
      if (presentValue_power == false){
        int numLength = num1_power.length();
        presentValue_power = true;
        op_power = key;
        lcd.setCursor(0 + numLength, 0);
        lcd.print("^");
      }
    }
    else if (final_power == true && key != NO_KEY && key == '=' && Clear_power==false) {
      if (op_power == '+') {
        answer_power = num1_power.toInt();
      for (int z = 1 ; z < num2_power.toInt() ; z++) {
        answer_power = answer_power * num1_power.toInt() ;
      }
    }
    lcd.clear();
    lcd.setCursor(16, 1);
    lcd.autoscroll();
    lcd.print(answer_power);
    lcd.noAutoscroll();
    Clear_power = true ;
    }
    else if (key != NO_KEY && key == '=' && Clear_power == true) {
      lcd.clear();
      Clear_power = false ;
      presentValue_power = false;
      final_power = false;
      num1_power = "";
      num2_power = "";
      answer_power = 0;
      op_power = ' ';
    }
  }
}
