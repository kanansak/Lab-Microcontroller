int 1 = 2;
int 2 = 0;
int 3 = 4;
int 4 = 16;
int 5 = 17;
int 6 = 5;
int 7 = 18;
int 8 = 19;
void setup() {
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT);
  pinMode(ledpin4,OUTPUT);
  pinMode(ledpin5,OUTPUT);
  pinMode(ledpin6,OUTPUT);
  pinMode(ledpin7,OUTPUT);
  pinMode(ledpin8,OUTPUT);
  pinMode(15,OUTPUT);
  digitalWrite(15,HIGH);
  digitalWrite(ledpin1,1);
  digitalWrite(ledpin2,1);
  digitalWrite(ledpin3,1);
  digitalWrite(ledpin4,1);
  digitalWrite(ledpin5,1);
  digitalWrite(ledpin6,1);
  digitalWrite(ledpin7,1);
  digitalWrite(ledpin8,1);
}

void loop() {
  for(int i=0;i<=8;i++){
    digitalWrite(i,0);
    delay(1000);
    digitalWrite(i,1);
    delay(1000);
  }
    
}
