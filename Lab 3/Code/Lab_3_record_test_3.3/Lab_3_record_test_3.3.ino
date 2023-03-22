void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(13)=1;
  digitalWrite(12)=2;
  digitalWrite(11)=3;
  digitalWrite(10)=4;
  digitalWrite(9)=5;
  digitalWrite(8)=6;
  digitalWrite(7)=7;
  digitalWrite(6)=8;
}

void loop() {
  for(int n=1;n<=8;n++){
    digitalWrite(n,LOW);
    delay(250);
    digitalWrite(n,HIGH);
    delay(250);
  }
}
