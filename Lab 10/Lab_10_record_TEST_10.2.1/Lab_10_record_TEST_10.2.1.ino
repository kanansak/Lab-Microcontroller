// Arduino stepper motor control code
#include <Stepper.h> // เรียกใช้ header ไฟล์ของมอเตอร์แบบขั้น
#define STEPS 32 //เปลี่ยนจำนวนขั้นของมอเตอร์
// สร้างอินสแตนซ์ (instance) ของคลาสมอเตอร์แบบขั้นโดยใช้จำนวนขั้น (Steps) และขา (Pins)
Stepper stepper(STEPS, 4, 16, 17, 5); //
int val = 0;

void setup() {
  Serial.begin(115200);
  stepper.setSpeed(200);
}

void loop() {
  if (Serial.available()>0)  {
    val = Serial.parseInt();
    stepper.step(val);
    Serial.println(val); //for debugging
  }
 }
