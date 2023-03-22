volatile int i = 0;
void setup()  {
  pinMode(13, INPUT);  //กำหนดภาวะ (Mode) ขา GPIO2 เป็นขารับเข้า
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(13) == 0) {
    delay(250);
    i++;
    Serial.println(i);
  }
}
