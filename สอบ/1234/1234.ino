#define sw 16
#define relay 2
int swstate = 1;
void setup() {
  pinMode(sw,INPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  Serial.begin(115200);
  pinMode(23,OUTPUT);
  digitalWrite(23,HIGH);
}

void loop() {
  int data = digitalRead(sw);
  Serial.print("SW > ");
  Serial.println(data);
  unsigned int val = analogRead(39);
  Serial.print("Analog Value = ");  
  Serial.println(val);
  delay(1000);
  if( data== 1) {
    swstate = !swstate;   
   }
   digitalWrite(relay,swstate);
  if (val>=1024){
      digitalWrite(relay,LOW);
   }
}
