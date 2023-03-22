
int valLight = 0;
void setup()  {
  Serial.begin(115200);
}
void loop() {
  unsigned int val = analogRead(36);
  Serial.print("Analog Value = ");  
  Serial.print(val);
  
  float realval = map(val,0,4095,0.0,3.3);
  Serial.print(" => ");
  Serial.println(realval);
  delay(500);
}
