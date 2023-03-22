void setup() {
  DDRD = B11111111;
}
void loop() {
  for(int i=0;i<99;i++)
  {
        PORTD |= B00000001;
        PORTD = PORTD<<1;  
        delay(500);
        PORTD &= PORTD<<0; 
        delay(500);
  }
}
