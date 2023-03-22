// I2C RTC MODULE
// AUTO SET TIME

#include <Wire.h>
#include <RTClib.h>

// หากใช้ DS3231 ใช้ RTC_DS3231 (ตามตัวอย่าง)
// หากใช้ DS1307 เปลี่ยนเป็น RTC_DS1307
// หากใช้ PCF8523 เปลี่ยนเป็น RTC_PCF8523
// และกำหนดให้เป็นชื่อ myRTC
RTC_DS1307 myRTC;

void setup(){
  // เริ่ม Serial เพื่อแสดงผลทาง Serial monitor
  Serial.begin(9600);

  // เริ่มการใช้งาน I2C
  Wire.begin();
  
  // รอจนกว่าจะเปิด Serial monitor
  while(!Serial){
    delay(50);
  }

  // ตั้งเวลาโดยเรียกใช้เวลาปัจจุบันจากคอมพิวเตอร์
  // ปล.ตรง __ คือพิมพ์ underscore 2 ครั้ง
  myRTC.adjust(DateTime(F(__DATE__),F(__TIME__)));

  // แสดงข้อความเมื่อตั้งเวลาเสร็จแล้ว
  Serial.println("Time setting done !");
}

void loop(){
  // ไม่ทำอะไรใน loop
}
