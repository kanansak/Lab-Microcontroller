#define swManual 12 //สวิตช์กด Manual
#define swMode 27 //สวิตช์กดเปลี่ยน Mode
#define relay 14 //relay
int modeClick = 0;
int swstate = 1;

void setup() {
  pinMode(swManual,INPUT);
  pinMode(swMode,INPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  Serial.begin(115200);
}

void loop() {
  int data = digitalRead(swManual);
  int mode = digitalRead(swMode);
  unsigned int val = analogRead(36); //รับค่าความชื้น
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
      Serial.println("Mode > Automation");
      if (val>=2048){             //ค่าความชื้นมาก
        digitalWrite(relay,HIGH);//relay ไม่ทำงาน
        Serial.println("LED OFF");
      }else{
        digitalWrite(relay,LOW);//relay ทำงาน
        Serial.println("LED ON");
      }
      Serial.print("Analog Value = ");  
      Serial.println(val);
      break;
    case 1:
    //Manual
      Serial.println("Mode > Manual");
      if( data== 1) {
        swstate = !swstate;   
        if(swstate == 0){
          Serial.println("RELAY ON");
        }else{
          Serial.println("RELAY OFF");
        }
      }
      digitalWrite(relay,swstate);
      break;
  }
  Serial.println(); 
  delay(250);
}
