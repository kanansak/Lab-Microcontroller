byte FW = 8;
byte RV = 9;

void setup() {
  pinMode(FW,OUTPUT);
  pinMode(RV,OUTPUT);
  digitalWrite(FW,0);
  digitalWrite(RV,0);
  
}
void Forward(){
  digitalWrite(FW,1);//Forward
  digitalWrite(RV,0);
  delay(3000);
  digitalWrite(FW,0);//Stop
  digitalWrite(RV,0);
  delay(100);
}
void Reverse(){
  digitalWrite(FW,0);//Reverse
  digitalWrite(RV,1);
  delay(3000);
  digitalWrite(FW,0);//Stop
  digitalWrite(RV,0);
  delay(100);
}
void loop() {
  Forward();
  Reverse();
}
