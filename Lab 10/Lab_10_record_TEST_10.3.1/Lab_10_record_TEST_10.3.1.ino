#include <ESP32Servo.h>
#include <ESP32_Servo.h>
Servo myServo;

void setup () {
  myServo.attach(36); 
}
void loop () {
  myServo.write(0); //ระบุตำแหน่งองศาที่ต้องการ
  delay(1000);  //ประวิงเวลาประมาณ 1 วินาที
  myServo.write(90);
  delay(1000);
  myServo.write(180);
  delay(1000);
}
