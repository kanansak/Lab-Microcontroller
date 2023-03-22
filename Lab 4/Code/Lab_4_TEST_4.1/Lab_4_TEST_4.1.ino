void setup()  {
   DDRB |= B00100000;
}
void loop() {
  PORTB |= B00100000;
  delay(1000);
  PORTB &= B11011111;
  delay(1000);
}
