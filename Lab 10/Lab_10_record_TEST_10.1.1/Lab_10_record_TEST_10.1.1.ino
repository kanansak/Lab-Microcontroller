int A = 5;
int B = 2;
int in1 = 0;
int in2 = 4;
int in3 = 16;
int in4 = 17;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop(){
  digitalWrite(A, HIGH); //ENABLE A
  digitalWrite(in1, HIGH); //CW
  digitalWrite(in2, LOW);
  digitalWrite(B, HIGH);//ENABLE B
  digitalWrite(in3, HIGH); //CW
  digitalWrite(in4, LOW);
  delay(1000);
  digitalWrite(A, HIGH); //ENABLE A
  digitalWrite(in1, LOW); //CCW
  digitalWrite(in2, HIGH);
  digitalWrite(B, HIGH);//ENABLE B
  digitalWrite(in3, LOW); //CCW
  digitalWrite(in4, HIGH);
  delay(1000);
  digitalWrite(A, LOW); //ENABLE A – Motor STOP
  digitalWrite(B, LOW); //ENABLE B – Motor STOP
}
