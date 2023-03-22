void setup() {
  unit8_t const *p;
  unit8_t i;
  Serial.begin(115200);
  p=0;
  i=0;
  do{
    Serial.print( *p,HEX);
    Serial.print( ' ' );
    ++i;
    ++p;
    if( (i & 0xF) == 0 ){
      Serial.println();
    }
  }while(i != 0);
}

void loop() {
}
