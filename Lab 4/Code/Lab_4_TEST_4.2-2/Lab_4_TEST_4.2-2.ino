void setup() {
  DDRB |= B11111111;
}

void loop() {
  for(int i=0;i<=7;i++){
    switch(i){
      case 0:
        PORTB |= B00000001;
        delay(500);
        PORTB &= B11111110;
        delay(500);
        break;
     case 1: 
        PORTB |= B00000010;
        delay(500);
        PORTB &= B11111101;
        delay(500);
        break;
     case 2: 
        PORTB |= B00000100;
        delay(500);
        PORTB &= B11111011;
        delay(500);
        break;
     case 3: 
        PORTB |= B00001000;
        delay(500);
        PORTB &= B11110111;
        delay(500);
        break;
     case 4: 
        PORTB |= B00010000;
        delay(500);
        PORTB &= B11101111;
        delay(500);
        break;
     case 5: 
        PORTB |= B00100000;
        delay(500);
        PORTB &= B1101111;
        delay(500);
        break;
     case 6: 
        PORTB |= B01000000;
        delay(500);
        PORTB &= B10111111;
        delay(500);
        break;
     case 7: 
        PORTB |= B10000000;
        delay(500); 
        PORTB &= B01111111;
        delay(500);
        break;              
     }
  }
}
