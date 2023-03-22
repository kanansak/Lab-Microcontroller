#include <DS1302.h>
// Init the DS1302
// DS1302 rtc([CE/RST], [I/O], [CLOCK]);
DS1302 rtc(2, 0, 4);
void setup() {
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  // Setup Serial connection
  Serial.begin(115200);
  // The following lines can be commented out to use the values already stored in the DS1302
  // ตั้งเวลาตรงนี้ เมื่อรันครั้งต่อไป ให้เอาคำสั่งตั้งเวลา 3 บรรทัดออก ไม่งั้นเวลาจะถูกต้องใหม่ทุกครั้งที่ทำงาน
  rtc.setDOW(WEDNESDAY);        // Set Day-of-Week to WEDNESDAY
  rtc.setTime(15, 13, 0);     // Set the time to 12:21:00 (24hr format)
  rtc.setDate(10, 11, 2021);   // Set the date to January 31th, 2018
  //
}
void loop() {
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());
  // Wait one second before repeating :)
  delay (1000);
}
