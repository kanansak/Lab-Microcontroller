int getAnalog0 = 0;
int valLight = 0;
void setup()  {
  Serial.begin(115200);
  pinMode(4,OUTPUT);
  digitalWrite(4,1);
}
void loop() {
  getAnalog0 = analogRead(A0);
  Serial.print("Analog Value = ");  
  Serial.println(getAnalog0);
  
  valLight = map(getAnalog0,0,1023,0,255);
  analogWrite(4,valLight);
}
