int A = 5;
int B = 2;
int in1 = 0;
int in2 = 4;
int in3 = 16;
int in4 = 17;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}
void loop() {
  //ถอยหลัง
  digitalWrite(A, HIGH); //ENABLE A
  digitalWrite(in1, HIGH); //CCW
  digitalWrite(in2, LOW);
  digitalWrite(B, HIGH);//ENABLE B
  digitalWrite(in3, LOW); //CCW
  digitalWrite(in4, HIGH);
  delay(5000);
  //เดินหน้า
  digitalWrite(A, HIGH); //ENABLE A
  digitalWrite(in1, LOW); //CCW
  digitalWrite(in2, HIGH);
  digitalWrite(B, HIGH);//ENABLE B
  digitalWrite(in3, HIGH); //CW
  digitalWrite(in4, LOW);
  delay(5000);
  //เลี้ยวซ้าย
  digitalWrite(A, HIGH); //ENABLE A
  digitalWrite(in1, LOW); //CCW
  digitalWrite(in2, HIGH);
  digitalWrite(B, HIGH);//ENABLE B
  digitalWrite(in3, LOW); //CCW
  digitalWrite(in4, HIGH);
  delay(5000);
  //เลี้ยวขวา
  digitalWrite(A, HIGH); //ENABLE A
  digitalWrite(in1, HIGH); //CCW
  digitalWrite(in2, LOW);
  digitalWrite(B, HIGH);//ENABLE B
  digitalWrite(in3, HIGH); //CW
  digitalWrite(in4, LOW);
  delay(5000);
  digitalWrite(A, LOW); //ENABLE A – Motor STOP
  digitalWrite(B, LOW); //ENABLE B – Motor STOP
  delay(2000);
}
