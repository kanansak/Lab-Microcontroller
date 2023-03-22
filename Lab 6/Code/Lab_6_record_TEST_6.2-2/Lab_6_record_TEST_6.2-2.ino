int sw = 12; 
volatile int i=0;
int ledpin1 = 2;
int ledpin2 = 0;
int ledpin3 = 4;
int ledpin4 = 16;
int ledpin5 = 17;
int ledpin6 = 5;
int ledpin7 = 18;
int ledpin8 = 19;
int stateSW = 1;
void setup() {
  Serial.begin(115200);
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
  digitalWrite(15,HIGH);
  digitalWrite(ledpin1,stateSW);
  digitalWrite(ledpin2,1);
  digitalWrite(ledpin3,1);
  digitalWrite(ledpin4,1);
  digitalWrite(ledpin5,1);
  digitalWrite(ledpin6,1);
  digitalWrite(ledpin7,1);
  digitalWrite(ledpin8,1);
}

void loop() {

    if(digitalRead(sw) == 0){
      stateSW = !stateSW;
  
    }
    digitalWrite(ledpin1,0);
    Serial.println(stateSW);
 
  
}
