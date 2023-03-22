unsigned int a;
void setup() {
  a=0;
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,INPUT);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}

void loop() {  
  int b= digitalRead(7);
  delay(250);
  if(b==0)digitalWrite(4,LOW);
  else if(b==1) digitalWrite(4,HIGH);
    Serial.println(b);
}
