void setup() {
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT); 
 digitalWrite(13,HIGH);
 digitalWrite(12,HIGH);
 digitalWrite(11,HIGH);
 digitalWrite(10,HIGH);
 digitalWrite(9,HIGH);
 digitalWrite(8,HIGH);
 digitalWrite(7,HIGH);
 digitalWrite(6,HIGH);
}

void loop() {
 digitalWrite(13,LOW);
 delay(250);
 digitalWrite(13,HIGH);

 digitalWrite(12,LOW);
 delay(250);
 digitalWrite(12,HIGH);

 digitalWrite(11,LOW);
 delay(250);
 digitalWrite(11,HIGH);

 digitalWrite(10,LOW);
 delay(250);
 digitalWrite(10,HIGH);

 digitalWrite(9,LOW);
 delay(250);
 digitalWrite(9,HIGH);

 digitalWrite(8,LOW);
 delay(250);
 digitalWrite(8,HIGH);

 digitalWrite(7,LOW);
 delay(250);
 digitalWrite(7,HIGH);

 digitalWrite(6,LOW);
 delay(250);
 digitalWrite(6,HIGH);
}
