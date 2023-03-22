void setup() {
  DDRD |= B11111111;
}

void loop() {
  for(int i=0;i<=7;i++){
    switch(i){
      case 0: 
          PORTD |= B00000001;
          delay(500);
          break;
      case 1:
          PORTD = PORTD << 1;
          delay(500);
          PORTD &= PORTD << 0;
          break;    
      case 2:
          PORTD = PORTD << 1;
          delay(500);
          PORTD &= PORTD << 0;
          break;    
      case 3:
          PORTD = PORTD << 1;
          delay(500);
          PORTD &= PORTD << 0;
          break;
      case 4:
          PORTD = PORTD << 1;
          delay(500);
          PORTD &= PORTD << 0;
          break;    
      case 5:
          PORTD = PORTD << 1;
          delay(500);
          PORTD &= PORTD << 0;
          break;    
      case 6:
          PORTD = PORTD << 1;
          delay(500);
          PORTD &= PORTD << 0;
          break;    
      case 7:
          PORTD = PORTD << 1;
          delay(500);
          PORTD &= PORTD << 0;
          break;                                
    }
  }
}
