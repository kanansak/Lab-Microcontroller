void setup()  {
  Serial.begin(115200);
  pinMode(16,OUTPUT);
  digitalWrite(16,HIGH);
}
void loop() {
  unsigned int val = analogRead(39);
  Serial.print("Analog Value = ");  
  Serial.print(val);
  
  float realval = (val*3.3)/4095;
  Serial.print(" => ");
  Serial.println(realval);
  delay(500);
  if(val>=1024){
    digitalWrite(2,HIGH);
  }else{
    digitalWrite(2,LOW);
  }
}
