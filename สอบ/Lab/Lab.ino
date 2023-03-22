void setup()  {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
}
void loop() {
  unsigned int val = analogRead(39);
  Serial.print("Analog Value = ");  
  Serial.println(val);
  delay(500);
  /*if(val>=1024){
    digitalWrite(2,HIGH);
  }else{
    digitalWrite(2,LOW);
  }*/
}
