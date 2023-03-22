volatile int i = 0;
void setup()  {
  pinMode(2, INPUT);  //กำหนดภาวะ (Mode) ขา GPIO2 เป็นขารับเข้า
  Serial.begin(115200);
}

void loop() {
  if(digitalRead(2) == 1) {
    delay(250);
    i++;
    Serial.println(i);
  }
}
