byte FW = 8;
byte RV = 9;

void setup() {
  pinMode(FW,OUTPUT);
  pinMode(RV,OUTPUT);
  digitalWrite(FW,0);
  digitalWrite(RV,0);
  
}
void Forward(unsigned int sec){
  digitalWrite(FW,1);//Forward
  digitalWrite(RV,0);
  delay(sec*1000);
}
void Stop(unsigned int sec){
  digitalWrite(FW,0);//Stop
  digitalWrite(RV,0);
  delay(sec*100);
}
void Reverse(unsigned int sec){
  digitalWrite(FW,0);//Reverse
  digitalWrite(RV,1);
  delay(sec*1000);
}
void loop() {
  Forward(3);
  Stop(1);
  Reverse(3);
}
