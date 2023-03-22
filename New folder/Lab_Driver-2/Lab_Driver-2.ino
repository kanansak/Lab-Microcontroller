void setup() {
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(10,0);
  digitalWrite(9,0);
}

void loop() {
  digitalWrite(10,0);
  digitalWrite(9,1);
  delay(1000);
  digitalWrite(10,1);
  digitalWrite(9,0);
  delay(1000);
}
