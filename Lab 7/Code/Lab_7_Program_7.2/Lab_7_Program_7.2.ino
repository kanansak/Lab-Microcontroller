int GetAnalog0;
void setup() {
  pinMode(4,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  GetAnalog0 = analogRead(A0);
  int mapValue = map(GetAnalog0,0,4095,0,255);
  analogWrite(4,mapValue);
  char str[50];
  sprintf(str,"A0 = %d,Map value = %d",GetAnalog0,mapValue);
  Serial.print(str);
}
