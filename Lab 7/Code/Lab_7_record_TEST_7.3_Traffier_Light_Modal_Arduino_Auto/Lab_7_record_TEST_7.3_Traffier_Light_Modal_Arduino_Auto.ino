int sw1 =10; //รับค่าสวิตซ์sw1 เป็นสวิตช์ใช้กดเพื่อเปลี่ยนโหมดเป็นAutoหรือManual
int sw2 =11; //รับค่าสวิตซ์sw2 เป็นสวิตช์ใช้กดเพื่อเลือกสถานะของสีไปจราจร
int sw3 = 12;
int sw4 = 13;
int inputsw1 = 1; //ตัวแปรเก็บค่าสวิตซ์sw1
int inputsw2 = 1; //ตัวแปรเก็บค่าสวิตซ์sw2
int inputsw3 = 1;
int inputsw4 = 1;
int LED_Red1 =1; //ออกขา1สีแดง
int LED_Y1 =2; // ออกขา2สีเหลือง
int LED_G1 =3; //ออกขา3สีเขียว
int LED_Red2 =4; //ออกขา4สีแดง
int LED_Y2 =5; // ออกขา5สีเหลือง
int LED_G2 =6; //ออกขา6สีเขียว
int LED_R3 =7; //ออกขา7สีแดง
int LED_Y3 =8; // ออกขา8สีเหลือง
int LED_G3 =9; //ออกขา9สีเขียว
int Atnumber =1; //ตัวเก็บลำดับการแสดงผลไฟLED
unsigned long previousMillis = 0; //เป็นฟังก์ชั่นที่เก็บประเภทของตัวเเปร
int VR1 = A0;
int VR2 = A1;
int VR3 = A2;


void LEDAUTO(); //เป็นฟังชันที่สร้างขึ้นให้เป็นไฟจราจรแบบอัตโนมัติ
void LEDMANUAL(); //เป็นฟังชันที่สร้างขึ้นให้เป็นไฟจราจรแบบแมนนวล
//void Lend();
void del_led();
void setup() {
 pinMode(sw1,INPUT);
 pinMode(sw2,INPUT);
 pinMode(sw3,INPUT);
 pinMode(sw4,INPUT);
 pinMode(LED_Red1,OUTPUT);
 pinMode(LED_Y1,OUTPUT);
 pinMode(LED_G1,OUTPUT);
 pinMode(LED_Red2,OUTPUT);
 pinMode(LED_Y2,OUTPUT);                 //เป็นการส่งสัญญาณขาออก
 pinMode(LED_G2,OUTPUT);
 pinMode(LED_R3,OUTPUT);
 pinMode(LED_Y3,OUTPUT);
 pinMode(LED_G3,OUTPUT);
digitalWrite(LED_Red1,HIGH);
digitalWrite(LED_Y1,HIGH);
digitalWrite(LED_G1,HIGH);                 //เป็นการเขียนสัญญาณให้LEDทุกดวงไม่ทำงาน
digitalWrite(LED_Red2,HIGH); 
digitalWrite(LED_Y2,HIGH);
digitalWrite(LED_G2,HIGH);
digitalWrite(LED_R3,HIGH);
digitalWrite(LED_Y3,HIGH);
digitalWrite(LED_G3,HIGH);
}
void loop() {
 if(digitalRead(sw1)==1){
 inputsw1++;
 delay(500);
 del_led(); //ปิดLEDทั้งหมด
 } 
 if(digitalRead(sw3)==1){
  inputsw2=1;
  inputsw4=1;
 inputsw3++;
 delay(500);
 del_led(); //ปิดLEDทั้งหมด
 }
if(digitalRead(sw2)==1){
  inputsw3=1;
  inputsw4=1;
 inputsw2++;
 delay(500);
 del_led(); //ปิดLEDทั้งหมด
 }
 if(digitalRead(sw4)==1){
  inputsw2=1;
  inputsw3=1;
 inputsw4++;
 delay(500);
 del_led(); //ปิดLEDทั้งหมด
 }
 

 //เช็คสวิตซ์//
 if(inputsw1==1){ //ถ้ากดสวิตซ์1ครั้งให้เข้าฟังก์ชันLEDAUTO();
 LEDAUTO();
 }
 if(inputsw1==2){ 
  LEDMANUAL();  //ถ้ากดอีกครั้งโปรแกรมจะเข้าฟังก์ชันLEDMANUAL();ถือว่าเป็นการกดLEDMANUAL();
 
 }
 
//เช็คสวิตซ์ป้องกันการกดสวิตซ์เกิน//
if(inputsw1==3){ //ถ้ากดสวิตซ์ตัวที่หนึ่งสามครั้งจะทำการวนกลับไปเป็นฟังก์ชัน
LEDAUTO();
 inputsw1=1;
 }
if(inputsw2==4){ //เป็นการกดสวิตซ์ตัวที่สองแบบMANUALและถ้ากดเกินเป็น7ครั้งจะทำการ
 inputsw2=1;
 
 }
//เช็คค่าเกินกว่าที่ระบุ//
if(inputsw3==4){
  inputsw3=1;
  }

  if(inputsw4==4){
  inputsw4=1;
  }
}
void LEDAUTO() {
 unsigned long currentMillis = millis();
 switch(Atnumber){



 case 1:
 digitalWrite(LED_G1, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่1ทำงาน
 digitalWrite(LED_Red1, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่1ไม่ทำงาน
digitalWrite(LED_Red2, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่2ทำงาน
 digitalWrite(LED_R3, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่3ทำงาน
 digitalWrite(LED_Y3, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแยกที่3ไม่ทำงาน
 break;
 case 2:
digitalWrite(LED_G1, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่1ไม่ทำงาน
 digitalWrite(LED_Y1, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแยกที่1ทำงาน
 digitalWrite(LED_R3, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่3ทำงาน
 digitalWrite(LED_Red2, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่2ทำงาน
 break;
 case 3:
 digitalWrite(LED_Y1, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแยกที่1ไม่ทำงาน
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่1ทำงาน
 digitalWrite(LED_Red2, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่2ไม่ทำงาน
 digitalWrite(LED_G2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่3ทำงาน
 break;
 case 4:
 digitalWrite(LED_Red1, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่1ทำงาน
 digitalWrite(LED_G2, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแยกที่2ไม่ทำงาน
 digitalWrite(LED_Y2, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่2ทำงาน
 digitalWrite(LED_R3, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่3ทำงาน
break;
 case 5:
 digitalWrite(LED_Red1, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่1ทำงาน
 digitalWrite(LED_Y2, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแยกที่2ไม่ทำงาน
 digitalWrite(LED_Red2, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่2ทำงาน
 digitalWrite(LED_R3, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแยกที่3ไม่ทำงาน
 digitalWrite(LED_G3, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่3ทำงาน
break;
 case 6:
 digitalWrite(LED_Y2, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแยกที่1ไม่ทำงาน
 digitalWrite(LED_Red1, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่1ทำงาน
 digitalWrite(LED_Red2, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่1ทำงาน
 digitalWrite(LED_G3, HIGH); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่1ไม่ทำงาน
 digitalWrite(LED_Y3, LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแยกที่1ทำงาน
 break;
 }

  if (currentMillis - previousMillis >= 30000||analogRead(VR1)>=512) { //currentMillisคือเวลาของบอร์ดArduino,previousMillisคือค่าเริ่มต้น
    previousMillis = currentMillis;
    Atnumber = 1;      //ติด 30000
  }
  else if (currentMillis - previousMillis >= 25000) {
    Atnumber = 6;
  }
  else if (currentMillis - previousMillis >= 20000||analogRead(VR2)>=512) {
    Atnumber = 5;      //ติด 20000
  }
  else if (currentMillis - previousMillis >= 17000) {
    Atnumber = 4;
  }
  else if (currentMillis - previousMillis >= 15000||analogRead(VR3)>=512) {
    Atnumber = 3;      //ติด 15000
  }
  else if (currentMillis - previousMillis >= 10000) {
    Atnumber = 2;
  }

 }
 void LEDMANUAL() { //ฟังชันการทำงานแบบ MANUAL
 switch(inputsw2){ 
 case 1:if(inputsw2==1&&inputsw3==1&&inputsw4==1){
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแถวที่1ทำงาน
 digitalWrite(LED_Red2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
}
 break;
 case 2:
 digitalWrite(LED_G1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแถวที่1ทำงาน
 digitalWrite(LED_Red2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 
 break;
 case 3:
 digitalWrite(LED_Y1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่1ทำงาน
 digitalWrite(LED_Red2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแถวที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 break;
 }
 
 switch(inputsw3){ 
 case 1:if(inputsw2==1&&inputsw3==1&&inputsw4==1){
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแถวที่1ทำงาน
 digitalWrite(LED_Red2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 }
 break;
 case 2:
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแถวที่1ทำงาน
 digitalWrite(LED_G2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 break;
 case 3:
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่1ทำงาน
 digitalWrite(LED_Y2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแถวที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 break;
 }

 switch(inputsw4){ 
 case 1:if(inputsw2==1&&inputsw3==1&&inputsw4==1){
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแถวที่1ทำงาน
 digitalWrite(LED_Red2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่2ทำงาน
 digitalWrite(LED_R3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 
 }break;
 case 2:
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเหลืองแถวที่1ทำงาน
 digitalWrite(LED_G3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่2ทำงาน
 digitalWrite(LED_Red2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 
 break;
 case 3:
 digitalWrite(LED_Red1,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่1ทำงาน
 digitalWrite(LED_Y3,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีเขียวแถวที่2ทำงาน
 digitalWrite(LED_Red2,LOW); //เป็นการเขียนให้สัญญาณไฟLEDสีแดงแถวที่3ทำงาน
 break;
 }
 }
 
void del_led(){
digitalWrite(LED_Red1,HIGH);
digitalWrite(LED_Y1,HIGH);
digitalWrite(LED_G1,HIGH);
digitalWrite(LED_Red2,HIGH);
digitalWrite(LED_Y2,HIGH);              //เป็นการเขียนสัญญาณให้LEDทุกดวงไม่ทำงาน
digitalWrite(LED_G2,HIGH);
digitalWrite(LED_R3,HIGH);
digitalWrite(LED_Y3,HIGH);
digitalWrite(LED_G3,HIGH);
}
