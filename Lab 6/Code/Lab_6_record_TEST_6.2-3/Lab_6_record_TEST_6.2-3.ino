int ledpin1 = 2;
int ledpin2 = 0;
int ledpin3 = 4;
int ledpin4 = 16;
int ledpin5 = 17;
int ledpin6 = 5;
int ledpin7 = 18;
int ledpin8 = 19;
int sw = 12;
int swState = 0;
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
  pinMode(sw,INPUT);
  digitalWrite(ledpin1,swState);
  digitalWrite(15,HIGH);
  digitalWrite(ledpin1,1);
  digitalWrite(ledpin2,1);
  digitalWrite(ledpin3,1);
  digitalWrite(ledpin4,1);
  digitalWrite(ledpin5,1);
  digitalWrite(ledpin6,1);
  digitalWrite(ledpin7,1);
  digitalWrite(ledpin8,1);
  Serial.begin(115200);
}

void loop() {
    if(digitalRead(sw) == 0){
      if(digitalRead(sw) == 0){
        return ;
    }
    time = millis();
    digitalWrite(ledpin1,swState);
        delay(1000);
        digitalWrite(ledpin1,1);
        delay(1000);
        digitalWrite(ledpin2,swState);
        delay(1000);
        digitalWrite(ledpin2,1);
        delay(1000);
        digitalWrite(ledpin3,swState);
        delay(1000);
        digitalWrite(ledpin3,1);
        delay(1000);
        digitalWrite(ledpin4,swState);
        delay(1000);
        digitalWrite(ledpin4,1);
        delay(1000);
        digitalWrite(ledpin5,swState);
        delay(1000);
        digitalWrite(ledpin5,1);
        delay(1000);
        digitalWrite(ledpin6,swState);
        delay(1000);
        digitalWrite(ledpin6,1);
        delay(1000);
        digitalWrite(ledpin7,swState);
        delay(1000);
        digitalWrite(ledpin7,1);
        delay(1000);
        digitalWrite(ledpin8,swState);
        delay(1000);
        digitalWrite(ledpin8,1);
        delay(1000);
      }
      
}