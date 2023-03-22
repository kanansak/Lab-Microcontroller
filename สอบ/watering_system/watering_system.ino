#define sw 12
#define relay 14
int swstate = 1;
void setup() {
  pinMode(sw,INPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  Serial.begin(115200);
}

void loop() {
  int data = digitalRead(sw);
  unsigned int val = analogRead(39);
  Serial.print("SW > ");
  Serial.println(data);
  Serial.print("Analog Value = ");  
  Serial.println(val);
  delay(1000);
//Manual
  if( data== 1) {
    swstate = !swstate;   
   }
    digitalWrite(relay,swstate);
//Automation 
  if (val>=2048){
      digitalWrite(relay,LOW);
   }
}
