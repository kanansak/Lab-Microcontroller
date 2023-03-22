#include <analogWrite.h>
int getAnalog0 = 0;
void setup()  {
  pinMode(4, OUTPUT); //กำหนดภาวะ (Mode) ขา 4 เป็นขาส่งออก
  Serial.begin(115200);
}

void loop() {
  getAnalog0 = analogRead(36);
  int PWMValue = map(getAnalog0, 0, 4095, 0, 255); //กำหนดช่วงและเทียบค่า
  analogWrite(4, PWMValue);
  delay(2);
}
