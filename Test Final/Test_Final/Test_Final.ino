#include <LiquidCrystal_I2C.h>

#define swManual 12 //สวิตช์กด Manual
#define swMode 13 //สวิตช์กดเปลี่ยน Mode
#define relay 14 //relay
#define MQ135_PIN 36 //
int modeClick = 0;
int swstate = 1;
LiquidCrystal_I2C lcd(0x27 , 16 , 2);

void setup() {
  pinMode(swManual,INPUT);
  pinMode(swMode,INPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int Manual = digitalRead(swManual);
  int mode = digitalRead(swMode);
  unsigned int senser_val = analogRead(MQ135_PIN); //รับค่าแก็ส
//เลือก Mode  
  if (mode == 1) {
    delay(250);
    modeClick = modeClick + 1;
    if (modeClick == 2) {
      modeClick = 0;
    }
  }
  switch(modeClick){
    case 0:
      //Automation 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Mode>Automation");
      Serial.println("Mode>Automation");
      if (senser_val<=1500){             //ค่าแก็สน้อย
        digitalWrite(relay,HIGH);//relay ไม่ทำงาน
        lcd.setCursor(0,1);
        lcd.print("Val>");
        lcd.print(senser_val);
        lcd.setCursor(9,1);
        lcd.print("Normal");
        Serial.println("Normal");
      }else{
        digitalWrite(relay,LOW);//relay ทำงาน
        lcd.setCursor(0,1);
        lcd.print("Val>");
        lcd.print(senser_val);
        lcd.setCursor(9,1);
        lcd.print("GasLeak");
        Serial.println("GasLeak");
      }
      Serial.print("SENSER Value = ");  
      Serial.println(senser_val);
      break;
    case 1:
    //Manual
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Mode>Manual");
      Serial.println("Mode>Manual");
      if( Manual == 1) {
        swstate = !swstate;  
      } 
        if(swstate == 0){
          Serial.println("Turn off valve");
          lcd.setCursor(0,1);
          lcd.print("Turn off Valve");
        }else{
          Serial.println("Turn on valve");
          lcd.setCursor(0,1);
          lcd.print("Turn on Valve");
        }   
      digitalWrite(relay,swstate);
      break;
  }
  Serial.println(); 
  delay(250);
}
