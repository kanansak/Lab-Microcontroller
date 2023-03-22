//กำหนดขา ตัว R = แดง Y = เหลือง G = เขียว 
#define r1 21
#define y1 19
#define g1 18

#define r2 5
#define y2 17
#define g2 16

#define r3 4
#define y3 0
#define g3 2

#define sw1 12
#define sw2 14
#define sw3 27
//กำหนดเวลา
unsigned long previousMillis = 0;
const long interval = 500;

int modeClick = 0; //กำหนดค่า การสลับmode
int traf = 0;
int light = 0;

void autoWork();
void mannualWork();
void traffic1();
void traffic2();
void traffic3();


void setup() {
  Serial.begin(115200);
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);

  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
  
  pinMode(r3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(g3, OUTPUT);

  digitalWrite(r1, HIGH);
  digitalWrite(y1, HIGH);
  digitalWrite(g1, HIGH);

  digitalWrite(r2, HIGH);
  digitalWrite(y2, HIGH);
  digitalWrite(g2, HIGH);
  
  digitalWrite(r3, HIGH);
  digitalWrite(y3, HIGH);
  digitalWrite(g3, HIGH);

  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);

  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop() {
  unsigned long currentMillis = millis();
  int mode = digitalRead(sw1); //กำหนดปุ่มเปลี่ยน mode

  if (mode == 1) {
    delay(250); //เวลาในการกดปุ่ม mode
    modeClick = modeClick + 1;
    if (modeClick == 2) {
      modeClick = 0;
    }
  }

  Serial.println(modeClick);
  
  switch (modeClick) {
    case 0: mannualWork();
            Serial.println("MANNUAL MODE");
      break;
    case 1: autoWork();
            Serial.println("AUTO MODE");
      break;
  }
}

void mannualWork() {
  unsigned long currentMillis = millis();
  int butTraf = digitalRead(sw2);//กำหนดปุ่มเลือกไฟจราจรแต่ละต้น

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
        Serial.println(traf);
      break;
    case 1: traffic2();
        Serial.println(traf);
      break;
    case 2: traffic3();
        Serial.println(traf);
      break;
  }
}

void traffic1() {
  int butLight = digitalRead(sw3);//กำหนดปุ่มเลือกไฟจราจรเสาที่1
  if (butLight == 1) {
    delay(500);//เวลาในการกดปุ่ม
    light = light + 1;
    if (light == 3) {
      light = 0;
    }
  }

  switch (light) {
    case 0: digitalWrite(g1, HIGH);
      digitalWrite(y1, LOW);
      digitalWrite(r1, LOW);

      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(r2, HIGH);

      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(r3, HIGH);
      break;
    case 1: digitalWrite(g1, LOW);
      digitalWrite(y1, HIGH);
      digitalWrite(r1, LOW);

      digitalWrite(g2, LOW);
      digitalWrite(y2, HIGH);
      digitalWrite(r2, LOW);

      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(r3, HIGH);
      break;
    case 2: digitalWrite(g1, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(r1, HIGH);

      digitalWrite(g2, HIGH);
      digitalWrite(y2, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(r3, HIGH);
      break;
  }
}

void traffic2() {
  int butLight = digitalRead(sw3);//กำหนดปุ่มเลือกไฟจราจรเสาที่2
  if (butLight == 1) {
    delay(500);//เวลาในการกดปุ่ม
    light = light + 1;
    if (light == 3) {
      light = 0;
    }
  }

  switch (light) {
    case 0: digitalWrite(g1, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(r1, HIGH);

      digitalWrite(g2, HIGH);
      digitalWrite(y2, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(r3, HIGH);
      break;
    case 1: digitalWrite(g1, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(r1, HIGH);

      digitalWrite(g2, LOW);
      digitalWrite(y2, HIGH);
      digitalWrite(r2, LOW);

      digitalWrite(g3, LOW);
      digitalWrite(y3, HIGH);
      digitalWrite(r3, LOW);
      break;
    case 2: digitalWrite(g1, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(r1, HIGH);

      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(r2, HIGH);

      digitalWrite(g3, HIGH);
      digitalWrite(y3, LOW);
      digitalWrite(r3, LOW);
      break;
  }
}

void traffic3() {
  int butLight = digitalRead(sw3);//กำหนดปุ่มเลือกไฟจราจรเสาที่ 3
  if (butLight == 1) {
    delay(500); //เวลาในการกดปุ่ม
    light = light + 1;
    if (light == 3) {
      light = 0;
    }
  }

  switch (light) {
    case 0: digitalWrite(g1, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(r1, HIGH);

      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(r2, HIGH);

      digitalWrite(g3, HIGH);
      digitalWrite(y3, LOW);
      digitalWrite(r3, LOW);
      break;
      
    case 1: digitalWrite(g1, LOW);
      digitalWrite(y1, HIGH);
      digitalWrite(r1, LOW);

      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(r2, HIGH);

      digitalWrite(g3, LOW);
      digitalWrite(y3, HIGH);
      digitalWrite(r3, LOW);
      break;
    case 2: digitalWrite(g1, HIGH);
      digitalWrite(y1, LOW);
      digitalWrite(r1, LOW);

      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(r2, HIGH);

      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(r3, HIGH);
      break;
  }
}

void autoWork() {

  int carway1 = analogRead(36); //กำหนดปุ่มปรับไฟจราจรเสาที่ 1
  int carway2 = analogRead(39); //กำหนดปุ่มปรับไฟจราจรเสาที่ 2
  int carway3 = analogRead(34); //กำหนดปุ่มปรับไฟจราจรเสาที่ 3

  Serial.print("Car way 1 = ");  
  Serial.println(carway1);

  Serial.print("Car way 2 = ");  
  Serial.println(carway2);

  Serial.print("Car way 3 = ");  
  Serial.println(carway3);

  if(carway1 < 512){
    digitalWrite(g1,1); //enables the 1st set of signals ไฟจราจรเสาที่ 1
    digitalWrite(r2,1);
    digitalWrite(r3,1);
  
    digitalWrite(y1,0);
    digitalWrite(r1,0);
     
    digitalWrite(y2,0);
    digitalWrite(g2,0);
  
    digitalWrite(y3,0);
    digitalWrite(g3,0);
  
    delay(30000);
  }
  else{
        digitalWrite(g1,1); //enables the 1st set of signals
    digitalWrite(r2,1);
    digitalWrite(r3,1);
  
    digitalWrite(y1,0);
    digitalWrite(r1,0);
     
    digitalWrite(y2,0);
    digitalWrite(g2,0);
  
    digitalWrite(y3,0);
    digitalWrite(g3,0);
  
    delay(60000);
    }

  digitalWrite(y1,1); //enables the yellow lights
  digitalWrite(y2,1);
  digitalWrite(g1,0); 
  digitalWrite(r2,0);
  delay(5000);

  if(carway2 < 512){
  digitalWrite(g2,1); //enables the 2nd set of signals ไฟจราจรเสาที่ 2
  digitalWrite(r1,1);
  digitalWrite(r3,1);
  
  digitalWrite(y1,0);
  digitalWrite(g1,0);
    
  digitalWrite(y2,0);
  digitalWrite(r2,0);
  
  digitalWrite(y3,0);
  digitalWrite(g3,0);
  delay(30000);
  }
  else{
    digitalWrite(g2,1); //enables the 2nd set of signals
  digitalWrite(r1,1);
  digitalWrite(r3,1);
  
  digitalWrite(y1,0);
  digitalWrite(g1,0);
    
  digitalWrite(y2,0);
  digitalWrite(r2,0);
  
  digitalWrite(y3,0);
  digitalWrite(g3,0);
  delay(60000);
  }
  
  digitalWrite(y3,1); //enables the yellow lights 2 
  digitalWrite(y2,1);
  
  digitalWrite(r3,0);
  digitalWrite(g2,0);  
  digitalWrite(r1,0);
  delay(5000); 

   if(carway3 < 512){
  digitalWrite(g3,1); //enables the 3rd set of signals ไฟจราจรเสาที่ 3
  digitalWrite(r1,1);
  digitalWrite(r2,1);
  
  digitalWrite(y1,0);
  digitalWrite(g1,0);
    
  digitalWrite(y2,0);
  digitalWrite(g2,0);
  
  digitalWrite(y3,0);
  digitalWrite(r3,0);
  
  delay(30000);
   }
   else{
      digitalWrite(g3,1); //enables the 3rd set of signals
  digitalWrite(r1,1);
  digitalWrite(r2,1);
  
  digitalWrite(y1,0);
  digitalWrite(g1,0);
    
  digitalWrite(y2,0);
  digitalWrite(g2,0);
  
  digitalWrite(y3,0);
  digitalWrite(r3,0);
  
  delay(60000);
    }
 
  digitalWrite(y1,1); //enables the yellow lights 3
  digitalWrite(y2,1);
   
  digitalWrite(r2,0);
  digitalWrite(g3,0); 
  digitalWrite(r1,0);
  delay(5000);   
}
