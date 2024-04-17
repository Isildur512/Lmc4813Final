#include "Dictionary.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#define __CS 10
#define __DC 9

TFT_ILI9163C display = TFT_ILI9163C(__CS, 8, __DC);

enum {TUTORIAL, HUNTING, POLLINATING} state = TUTORIAL;
Dictionary flowers = new Dictionary();
int curSlide = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin();
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
  display.print(tutorialText[0]);
}

void hunting() {

}

void pollinating() {

}
