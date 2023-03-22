void setup() {
  DDRD = B11111111;
}
void loop() {
        PORTD = B00000001;
        delay(500);
        PORTD = B00000010;
        delay(500);  
        PORTD = B00000100;
        delay(500);  
        PORTD = B00001000;
        delay(500);  
        PORTD = B00010000;
        delay(500);      
        PORTD = B00100000;
        delay(500);   
        PORTD = B01000000;
        delay(500);
        PORTD = B10000000;
        delay(500);               
}
