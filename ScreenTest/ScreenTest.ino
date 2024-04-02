#include "Nokia_5110.h"
#include "Dictionary.h"
Nokia_5110 lcd = Nokia_5110(1, 2, 10, 13, 14);

enum {TUTORIAL, HUNTING, POLLINATING} state = TUTORIAL;
Dictionary flowers = new Dictionary();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  flowers("1", "Azalea");
}

void loop() {
  delay(1000);
  // put your main code here, to run repeatedly:
  if (state == TUTORIAL) {
    Serial.println("Hello World!");
  } else if (state == HUNTING) {
    Serial.println("It's arduinoing time");
  }
  delay(500);
  state = HUNTING;
}

void tutorial() {
  
}
