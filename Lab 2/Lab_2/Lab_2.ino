void setup() {
  pinMode(16, OUTPUT);  //กำหนดภาวะ (Mode) ขา 16 เป็นขาส่งออก

}

void loop() {
  digitalWrite(16, LOW);  //เขียน/ส่งออกค่าสัญญาณดิจิทัลทางขา 16 เป็น 0
  delay(1000);    //หน่วง/ประวิงตามเวลาที่กำหนดไว้ก่อนทำงานบรรทัดถัดไป
  digitalWrite(16, HIGH); //เขียน/ส่งออกค่าสัญญาณดิจิทัลทางขา 16 เป็น 1
  delay(1000);


}
