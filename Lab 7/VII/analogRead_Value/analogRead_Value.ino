boolean sw1 = true;
void setup() {
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,INPUT);

}

void loop() {
  unsigned int val = analogRead(A0);
  Serial.print("Analog Value = ");
  
  boolean swread = digitalRead(12); delay(150);
  if(swread == 0) sw1 = !sw1;
  // volt = (val*5)/1023;
  float realval = map(val,0,1023,0.0,5.0);
  //folat realval = (val*5.0)/1023;
  Serial.println(realval);
  if(val < 512) {
    digitalWrite(7,0);
    digitalWrite(6,1);
  }
  else {
    digitalWrite(6,0);
    digitalWrite(7,1);
  }
  if(sw1 == false){
    digitalWrite(7,1);
    
  }
}
