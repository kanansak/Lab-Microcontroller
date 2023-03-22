void setup() {
  pinMode(10,OUTPUT);
  digitalWrite(10,1);
}

void loop() {
  digitalWrite(10,0);
  delay(1000);
  digitalWrite(10,1);
  delay(1000);
}
