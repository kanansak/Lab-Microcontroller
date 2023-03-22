unsigned int a;
void setup() {
  a=0;
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
}

void loop() {
  
  if(a<10)
  {  
    a++;
    Serial.print("Round : ");
    Serial.println(a);
    digitalWrite(4,LOW);
    delay(1000);
    digitalWrite(4,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(4,LOW);
  }
}
