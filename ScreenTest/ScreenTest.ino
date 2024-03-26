#include "Nokia_5110.h"
Nokia_5110 lcd = Nokia_5110(1, 2, 10, 13, 14);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.println("Hello World!");
  lcd.println("Hello! This is a Sheleah Push :)");
}
