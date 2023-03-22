volatile int i = 0;
void setup()  {
  pinMode(2, INPUT);  //Select GATE
  pinMode(3, INPUT); //Input A
  pinMode(4, INPUT); //Input B
  pinMode(13, OUTPUT); //AND 
  pinMode(12, OUTPUT);//OR
  pinMode(11, OUTPUT);//NAND
  pinMode(10, OUTPUT);//NOR
  pinMode(9, OUTPUT);//NOT
  pinMode(8, OUTPUT);//A
  pinMode(7, OUTPUT);//B
  pinMode(6, OUTPUT);//Y
  Serial.begin(9600);
}

void loop() {
//==============Selcet GATE=========================
  int SelectGATE = digitalRead(2);
  if(SelectGATE == 1){
    delay(500);
    i++;
    Serial.println(i);
  }
  if(i>5){
    i=1;
  }
//==============INPUT Logic=========================
  int A = digitalRead(3);
  int B = digitalRead(4);
  if(A == 1)
    digitalWrite(8,HIGH);
  else 
    digitalWrite(8,LOW);
  if(B == 1)
    digitalWrite(7,HIGH);
  else
    digitalWrite(7,LOW);  
//==============Logic GATE============================
  switch(i){
    //AND GATE
    digitalWrite(13,LOW);
    case 1:
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      if(A == HIGH && B == HIGH)
        digitalWrite(6,HIGH);
       else
        digitalWrite(6,LOW);   
    break;
    //OR GATE
    case 2:
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      if(A == HIGH || B == HIGH)
        digitalWrite(6,HIGH);
      else
        digitalWrite(6,LOW);
    break;
    //NAND GATE
    case 3:
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      if(A == HIGH && B == HIGH)
        digitalWrite(6,LOW);
      else 
        digitalWrite(6,HIGH);
    break;
    //NOR
    case 4:
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(9,LOW);
      if(A == HIGH || B == HIGH)
        digitalWrite(6,LOW);
      else if(A == LOW && B == LOW)
        digitalWrite(6,HIGH);
    break;
    //NOT GATE
    case 5:
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(6,HIGH);
      if(A == HIGH )
        digitalWrite(6,LOW);
      else if (B == HIGH)
        digitalWrite(6,LOW);
    break;
   }
}
