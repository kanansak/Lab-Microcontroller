int getAnalog0 = 0;
void setup()  {
  Serial.begin(115200);
}
void loop() {
  getAnalog0 = analogRead(36);
  Serial.print("Analog Value = ");  
  Serial.println(getAnalog0);
  delay(1000);
}
