#include "Nokia_5110.h"
#include "Dictionary.h"
Nokia_5110 lcd = Nokia_5110(1, 2, 10, 13, 14);

enum {TUTORIAL, HUNTING, POLLINATING} state = TUTORIAL;
Dictionary flowers = new Dictionary();
int curSlide = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  flowers("1", "Azalea");
}

void loop() {
  delay(1000);
  // put your main code here, to run repeatedly:
  if (state == TUTORIAL) {
    tutorial();
  } else if (state == HUNTING) {
    hunting();
  } else {
    pollinating();
  }
  delay(500);
  state = HUNTING;
}

void tutorial() {
  String tutorialText[] = {
    "Hello! Welcome to Bees, Knees, and RFIDs: A Pollination Simulation! /n /n Press the button to go to the next slide.",
    "You will be directed to four different flower beds around campus, on a mission to carry the bee to each. /n /n Press the button to go to the next slide.",
    "When you reach a flower bed, press the bee's face directly into the special flower, and wait for the pollination process to finish! /n /n Press the button to go to the next slide.",
    "From there, you'll be promtped to go to the next flower bed! /n /n Press the button to go to the next slide."
    "Would you like to see this again? /n Yes /n No",
    "Alright, good luck!"
  };
  Serial.println(tutorialText[0]);
}

void hunting() {

}

void pollinating() {

}
