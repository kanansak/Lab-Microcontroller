int i;
void setup() {
  i=0;
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13,LOW);
  delay(250);
  digitalWrite(13,HIGH);
  delay(250);
  i++;
  Serial.print("Round : ");
  Serial.println(i);
  digitalWrite(13,LOW);
  delay(1000);
  

}
