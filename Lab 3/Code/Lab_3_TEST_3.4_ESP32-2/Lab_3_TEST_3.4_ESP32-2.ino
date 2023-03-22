volatile int i = 0;
void setup()  {
  pinMode(12, INPUT);  //Select GATE
  pinMode(14, INPUT); //Input A
  pinMode(27, INPUT); //Input B
  pinMode(2, OUTPUT); //AND 
  pinMode(0, OUTPUT);//OR
  pinMode(4, OUTPUT);//NAND
  pinMode(16, OUTPUT);//NOR
  pinMode(17, OUTPUT);//NOT
  pinMode(5, OUTPUT);//A
  pinMode(18, OUTPUT);//B
  pinMode(19, OUTPUT);//Y
  pinMode(34, OUTPUT);
  digitalWrite(34,HIGH);
  Serial.begin(115200);

}

void loop() 
{
//==============Selcet GATE=========================
  int SelectGATE = digitalRead(12);
  if(SelectGATE == 1){
    delay(500);
    i++;
    Serial.println(i);
  }
  if(i>5){
    i=1;
  }
//==============INPUT Logic=========================
  int A = digitalRead(14);//Input A
  int B = digitalRead(27);//Input B
  if(A == 1)
    digitalWrite(5,HIGH);
  else 
    digitalWrite(5,LOW);
  if(B == 1)
    digitalWrite(18,HIGH);
  else
    digitalWrite(18,LOW);  
//==============Logic GATE============================
    //AND GATE
    if(i==1){
      digitalWrite(2,HIGH);
      digitalWrite(0,LOW);
      digitalWrite(4,LOW);
      digitalWrite(16,LOW);
      digitalWrite(17,LOW);
      if(A == HIGH && B == HIGH)
        digitalWrite(19,HIGH);
       else
        digitalWrite(19,LOW);
    }
    //OR GATE
    else if(i==2){
      digitalWrite(2,LOW);
      digitalWrite(0,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(16,LOW);
      digitalWrite(17,LOW);
      if(A == HIGH || B == HIGH)
        digitalWrite(19,HIGH);
      else
        digitalWrite(19,LOW);
    }
    //NAND GATE
    else if(i==3){
      digitalWrite(2,LOW);
      digitalWrite(0,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(16,LOW);
      digitalWrite(17,LOW);
      if(A == HIGH && B == HIGH)
        digitalWrite(19,LOW);
      else 
        digitalWrite(19,HIGH);
    }
    //NOR
    else if(i==4){
      digitalWrite(2,LOW);
      digitalWrite(0,LOW);
      digitalWrite(4,LOW);
      digitalWrite(16,HIGH);
      digitalWrite(17,LOW);
      if(A == HIGH || B == HIGH)
        digitalWrite(19,LOW);
      else if(A == LOW && B == LOW)
        digitalWrite(19,HIGH);
    }
    //NOT GATE
     else if(i==5){
      digitalWrite(2,LOW);
      digitalWrite(0,LOW);
      digitalWrite(4,LOW);
      digitalWrite(16,LOW);
      digitalWrite(17,HIGH);
      digitalWrite(19,HIGH);
      if(A == HIGH )
        digitalWrite(19,LOW);
      else if (B == HIGH)
        digitalWrite(19,LOW);
     }
}
