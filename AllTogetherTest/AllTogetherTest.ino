#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EncoderButton.h>

#define RST_PIN 9         // Configurable, see typical pin layout above
#define SS_PIN 10         // Configurable, see typical pin layout above
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define ARRAYSIZE 6

int curText = 0;

EncoderButton eb1(2, 3, 4);

char *displayText[ARRAYSIZE] = {
  "     Welcome! \n \n Press the button to       begin!",
  "  Carry the bee to    discover the flora  around Georgia Tech's      campus.",
  "       - - - \n Look for the small  pink flowers nearby! \n",
  "       o - - \n Cross north through the stairs. Look for  the white flowers.",
  "       o o - \nKeep north. Look for   the small purple   flowers on the ground.",
  "       o o o \nAdventure complete.   Press button to      return to start."
};


/**
 * A function to handle the 'clicked' event
 * Can be called anything but requires EncoderButton& 
 * as its only parameter.
 * I tend to prefix with 'on' and suffix with the 
 * event type.
 */
void onEb1Clicked(EncoderButton& eb) {
  if (curText != 2 && curText != 3 && curText != 4) {
    curText += 1;
  }
  display.clearDisplay();
  if (curText == ARRAYSIZE) {
    curText = 0;
  }
}

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Link the event(s) to your function
  eb1.setClickHandler(onEb1Clicked);

  while (!Serial)
    ;                                 // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();                        // Init SPI bus
  mfrc522.PCD_Init();                 // Init MFRC522
  delay(4);                           // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
}

void loop() {
  eb1.update();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println((displayText[curText]));
  display.display();

  if(eb1.currentDuration() != 0) {
    display.clearDisplay();
  }

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  if (curText == 2 || curText == 3 || curText == 4) {
    curText += 1;
  }
}