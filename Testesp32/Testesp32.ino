void setup() {
  pinMode(23, OUTPUT);  //กำหนดภาวะ (Mode) ขา 13 เป็นขาส่งออก
}

void loop() {
 digitalWrite(23, LOW); //เขียน/ส่งออกค่าสัญญาณดิจิทัลทางขา 13 เป็น 0
  delay(1000);    //หน่วง/ประวิงตามเวลาที่กำหนดไว้ก่อนทำงานบรรทัดถัดไป
  digitalWrite(23, HIGH); //เขียน/ส่งออกค่าสัญญาณดิจิทัลทางขา 13 เป็น 1
  delay(1000);


}
