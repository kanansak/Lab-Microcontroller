byte lamp = 10;

void setup() {
  pinMode(lamp,OUTPUT);
  digitalWrite(lamp,0);
  
}

void loop() {
  unsigned int light = analogRead(A0);//0-1023
  if(light < 100){
    digitalWrite(lamp,1);
  }else{
    digitalWrite(lamp,0);
  }
  
  
}
