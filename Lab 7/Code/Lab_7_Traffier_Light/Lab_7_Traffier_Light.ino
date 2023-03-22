int sw1 =10; //รับค่าสวิตซ์sw1 เป็นสวิตช์ใช้กดเพื่อเปลี่ยนโหมดเป็นAutoหรือManual
int sw2 =11; //รับค่าสวิตซ์sw2 เป็นสวิตช์ใช้กดเพื่อเลือกสถานะของสีไปจราจร
int sw3 = 12;
int sw4 = 13;
int r1 =1; //ออกขา1สีแดง
int y1 =2; // ออกขา2สีเหลือง
int g1 =3; //ออกขา3สีเขียว
int r2 =4; //ออกขา4สีแดง
int y2 =5; // ออกขา5สีเหลือง
int g2 =6; //ออกขา6สีเขียว
int r3 =7; //ออกขา7สีแดง
int y3 =8; // ออกขา8สีเหลือง
int g3 =9; //ออกขา9สีเขียว
int Atnumber =1; //ตัวเก็บลำดับการแสดงผลไฟLED
unsigned long previousMillis = 0; //เป็นฟังก์ชั่นที่เก็บประเภทของตัวเเปร
const long interval = 500;

void autoWork();
int modeClick = 0;
void manualWork();
int traf = 0;
int light = 0;
void traffic1();
void traffic2();
void traffic3();
int VR1 = A0;
int VR2 = A1;
int VR3 = A2;
void setup() {
     pinMode(sw1,INPUT);
     pinMode(sw2,INPUT);
     pinMode(sw3,INPUT);
     pinMode(sw4,INPUT);
     pinMode(r1,OUTPUT);
     pinMode(y1,OUTPUT);
     pinMode(g1,OUTPUT);
     pinMode(r2,OUTPUT);
     pinMode(y2,OUTPUT);                 //เป็นการส่งสัญญาณขาออก
     pinMode(g2,OUTPUT);
     pinMode(r3,OUTPUT);
     pinMode(y3,OUTPUT);
     pinMode(g3,OUTPUT);
     digitalWrite(r1,HIGH);
     digitalWrite(y1,HIGH);
     digitalWrite(g1,HIGH);                 //เป็นการเขียนสัญญาณให้LEDทุกดวงไม่ทำงาน
     digitalWrite(r2,HIGH); 
     digitalWrite(y2,HIGH);
     digitalWrite(g2,HIGH);
     digitalWrite(r3,HIGH);
     digitalWrite(y3,HIGH);
     digitalWrite(g3,HIGH);
     pinMode(11, INPUT);
     pinMode(12, INPUT);
     pinMode(13, INPUT);
     pinMode(A0, INPUT);
     pinMode(A1, INPUT);
     pinMode(A2, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  int mode = digitalRead(11);
  
  if (mode == 1) {
    delay(250);
    modeClick = modeClick + 1;
    if (modeClick == 2) {
      modeClick = 0;
    }
  }
  
  Serial.println(modeClick);
  
  switch (modeClick) {
    case 0: manualWork();
      Serial.println("MANUAL MODE");
     break;
    case 1: autoWork();
      Serial.println("AUTO MODE");
     break;
    }
}
  
void manualWork() {
  unsigned long currentMillis = millis();
  int butTraf = digitalRead(12);
  
  if (currentMillis - previousMillis >= interval) {
    if (butTraf == 1) {
      traf = traf + 1;
      if (traf == 3) {
        traf = 0;
    }
  }
  previousMillis = currentMillis;
  }
  
  switch (traf) {
    case 0: traffic1();
      break;
    case 1: traffic2();
      break;
    case 2: traffic3();
      break;
  }
}
  
void traffic1() {
  int butLight = digitalRead(13);
  if (butLight == 1) {
    delay(500);
    light = light + 1;
    if (light == 3) {
    light = 0;
    }
  }

   switch (light) {
      case 0: digitalWrite(g1, LOW);
        digitalWrite(y1, HIGH);
        digitalWrite(r1, HIGH);
      
        digitalWrite(g2, HIGH);
        digitalWrite(y2, HIGH);
        digitalWrite(r2, LOW);
        
        digitalWrite(g3, HIGH);
        digitalWrite(y3, HIGH);
        digitalWrite(r3, LOW);
        break;
      case 1: digitalWrite(g1, HIGH);
        digitalWrite(y1, LOW);
        digitalWrite(r1, HIGH);
        
        digitalWrite(g2, HIGH);
        digitalWrite(y2, LOW);
        digitalWrite(r2, HIGH);
        
        digitalWrite(g3, HIGH);
        digitalWrite(y3, HIGH);
        digitalWrite(r3, LOW);
        break;
      case 2: digitalWrite(g1, HIGH);
        digitalWrite(y1, HIGH);
        digitalWrite(r1, LOW);
        
        digitalWrite(g2, LOW);
        digitalWrite(y2, HIGH);
        digitalWrite(r2, HIGH);
        
        digitalWrite(g3, HIGH);
        digitalWrite(y3, HIGH);
        digitalWrite(r3, LOW);
        break;
    }
}  
void traffic2() {
  int butLight = digitalRead(13);
  if (butLight == 1) {
    delay(500);
    light = light + 1;
    if (light == 3) {
      light = 0;
    }
  }
  switch (light) {
    case 0: digitalWrite(g1, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(r1, LOW);
    
      digitalWrite(g2, LOW);
      digitalWrite(y2, HIGH);
      digitalWrite(r2, HIGH);
      
      digitalWrite(g3, HIGH);
      digitalWrite(y3, HIGH);
      digitalWrite(r3, LOW);
      break;
    case 1: digitalWrite(g1, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(r1, LOW);
      
      digitalWrite(g2, HIGH);
      digitalWrite(y2, LOW);
      digitalWrite(r2, HIGH);

      digitalWrite(g3, HIGH);
      digitalWrite(y3, LOW);
      digitalWrite(r3, HIGH);
      break;
    case 2: digitalWrite(g1, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(r1, LOW);
      
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);
      digitalWrite(r2, LOW);
      
      digitalWrite(g3, LOW);
      digitalWrite(y3, HIGH);
      digitalWrite(r3, HIGH);
      break;
    }
}
void traffic3() {
  int butLight = digitalRead(13);
  if (butLight == 1) {
    delay(500);
    light = light + 1;
    if(light == 3){
      light = 0;
    }
  }
  switch (light) {
    case 0: digitalWrite(g1, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(r1, LOW);
      
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);
      digitalWrite(r2, LOW);
      
      digitalWrite(g3, LOW);
      digitalWrite(y3, HIGH);
      digitalWrite(r3, HIGH);
      break;
    case 1: digitalWrite(g1, HIGH);
      digitalWrite(y1, LOW);
      digitalWrite(r1, HIGH);
      
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);
      digitalWrite(r2, LOW);
      
      digitalWrite(g3, HIGH);
      digitalWrite(y3, LOW);
      digitalWrite(r3, HIGH);
      break; 
    case 2: digitalWrite(g1, LOW);
      digitalWrite(y1, HIGH);
      digitalWrite(r1, HIGH);
      
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);
      digitalWrite(r2, LOW);
      
      digitalWrite(g3, HIGH);
      digitalWrite(y3, HIGH);
      digitalWrite(r3, LOW);
      break;
   }
} 
void autoWork() {
  int car1 = analogRead(A0);
  int car2 = analogRead(A1);
  int car3 = analogRead(A2);
}
