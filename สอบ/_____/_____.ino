#define relay 2
#define sw1 0
#define sw2 4
int modeClick = 0;
void setup() {
  pinMode(relay,OUTPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  digitalWrite(relay,LOW);
  Serial.begin(115200);
}

void loop() {
  unsigned int val = analogRead(39);
  int mode = digitalRead(sw1);
  if (mode == 1) {
    delay(250);
    modeClick = modeClick + 1;
    if (modeClick == 2) {
      modeClick = 0;
    }
  }
  //Serial.println(modeClick);
  Serial.println(val);
  delay(500);
  switch (modeClick) {
    case 0: 
         if(digitalRead(sw2) == 1) {
            digitalWrite(relay,HIGH);
         }else{
            digitalWrite(relay,LOW);
         }
      break;
    case 1: 
      if(val>=1024){
        Serial.println(val);
        digitalWrite(relay,HIGH);
      }else{
        digitalWrite(relay,LOW);
      }
      break;
  }
}
