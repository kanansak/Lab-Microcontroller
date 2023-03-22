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
  if(b == 0){
    a++;
  }
  if(a<10)
  {  
    Serial.print("Round : ");
    Serial.println(a);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    delay(1000);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(4,LOW);
  }
}
