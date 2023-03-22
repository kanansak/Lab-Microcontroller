/*int ledpin1 = 2;
int ledpin2 = 0;
int ledpin3 = 4;
int ledpin4 = 16;
int ledpin5 = 17;
int ledpin6 = 5;
int ledpin7 = 18;
int ledpin8 = 19;*/
void setup() {
  pinMode(2,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  Serial.begin(115200);
}

void loop() {
    digitalWrite(2,LOW);
    delay(1000);
    digitalWrite(2,HIGH);
    delay(1000);
    /*digitalWrite(ledpin2,0);
    delay(1000);
    digitalWrite(ledpin2,1);
    delay(1000);
    digitalWrite(ledpin3,0);
    delay(1000);
    digitalWrite(ledpin3,1);
    delay(1000);
    digitalWrite(ledpin4,0);
    delay(1000);
    digitalWrite(ledpin4,1);
    delay(1000);
    digitalWrite(ledpin5,0);
    delay(1000);
    digitalWrite(ledpin5,1);
    delay(1000);
    digitalWrite(ledpin6,0);
    delay(1000);
    digitalWrite(ledpin6,1);
    delay(1000);
    digitalWrite(ledpin7,0);
    delay(1000);
    digitalWrite(ledpin7,1);
    delay(1000);
    digitalWrite(ledpin8,0);
    delay(1000);
    digitalWrite(ledpin8,1);
    delay(1000);*/

}
