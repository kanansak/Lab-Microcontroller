void setup() {
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
}

void loop() {
  digitalWrite(4,LOW);
  delay(1000);
  digitalWrite(4,HIGH);
  delay(1000);
}
