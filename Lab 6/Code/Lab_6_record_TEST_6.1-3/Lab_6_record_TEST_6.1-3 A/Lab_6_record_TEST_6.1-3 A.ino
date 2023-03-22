int ledpin1 = 2;

void setup() {
  pinMode(ledpin1,OUTPUT);
  pinMode(15,OUTPUT);
  digitalWrite(15,HIGH);
  //Serial.begin(115200);
}

void loop() {
    digitalWrite(ledpin1,LOW);
    delay(1000);
    digitalWrite(ledpin1,HIGH);
    delay(1000);
}
