int ledpin1 = 2;
int ledpin2 = 0;
int ledpin3 = 4;
int ledpin4 = 16;
int ledpin5 = 17;
int ledpin6 = 5;
int ledpin7 = 18;
int ledpin8 = 19;
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
    digitalWrite(ledpin1,0);
    delayMicroseconds(50);
    digitalWrite(ledpin1,1);
    delayMicroseconds(50);
    digitalWrite(ledpin2,0);
    delayMicroseconds(50);
    digitalWrite(ledpin2,1);
    delayMicroseconds(50);
    digitalWrite(ledpin3,0);
    delayMicroseconds(50);
    digitalWrite(ledpin3,1);
    delayMicroseconds(50);
    digitalWrite(ledpin4,0);
    delayMicroseconds(50);
    digitalWrite(ledpin4,1);
    delayMicroseconds(50);
    digitalWrite(ledpin5,0);
    delayMicroseconds(50);
    digitalWrite(ledpin5,1);
    delayMicroseconds(50);
    digitalWrite(ledpin6,0);
    delayMicroseconds(50);
    digitalWrite(ledpin6,1);
    delayMicroseconds(50);
    digitalWrite(ledpin7,0);
    delayMicroseconds(50);
    digitalWrite(ledpin7,1);
    delayMicroseconds(50);
    digitalWrite(ledpin8,0);
    delayMicroseconds(50);
    digitalWrite(ledpin8,1);
    delayMicroseconds(50);

}
