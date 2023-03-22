#define relay 2
#define sw1 4
#define sw2 16
int modeClick = 0;
void setup() {
  pinMode(relay,OUTPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  digitalWrite(relay,HIGH);
  Serial.begin(115200);
}

void loop() {
  unsigned int val = analogRead(39);
  int mode = digitalRead(sw1);
  int data = digitalRead(sw2);
  
  if (mode == 1) {
    delay(250);
    modeClick = modeClick + 1;
    if (modeClick == 2) {
      modeClick = 0;
    }
  }
  Serial.print("Mode > ");
  Serial.println(modeClick);
  delay(500);
  switch (modeClick) {
    case 0: 
         if(data == 1) {
            digitalWrite(relay,LOW);
         }else{
            digitalWrite(relay,HIGH);
         }
      break;
    case 1: 
      if(val>=1024){
        Serial.println(val);
        digitalWrite(relay,LOW);
      }else{
        digitalWrite(relay,HIGH);
      }
      break;
  }
}
