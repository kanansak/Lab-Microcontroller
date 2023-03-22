void setup() {
 pinMode(15,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(0,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(16,OUTPUT);
 pinMode(17,OUTPUT);
 pinMode(18,OUTPUT);
 pinMode(19,OUTPUT); 
 digitalWrite(15,HIGH);
 digitalWrite(2,HIGH);
 digitalWrite(0,HIGH);
 digitalWrite(4,HIGH);
 digitalWrite(16,HIGH);
 digitalWrite(17,HIGH);
 digitalWrite(18,HIGH);
 digitalWrite(19,HIGH);
}

void loop() {
 digitalWrite(15,LOW);
 delay(250);
 digitalWrite(15,HIGH);

 digitalWrite(2,LOW);
 delay(250);
 digitalWrite(2,HIGH);

 digitalWrite(0,LOW);
 delay(250);
 digitalWrite(0,HIGH);

 digitalWrite(4,LOW);
 delay(250);
 digitalWrite(4,HIGH);

 digitalWrite(16,LOW);
 delay(250);
 digitalWrite(16,HIGH);

 digitalWrite(17,LOW);
 delay(250);
 digitalWrite(17,HIGH);

 digitalWrite(18,LOW);
 delay(250);
 digitalWrite(18,HIGH);

 digitalWrite(19,LOW);
 delay(250);
 digitalWrite(19,HIGH);
}
