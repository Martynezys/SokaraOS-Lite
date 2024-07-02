#include <minkoValekInfoCentrumBitmaps.h>
#include "driver/gpio.h"
#include <rom/ets_sys.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

#define TFT_BLACK   0x0000
#define TFT_GRAY    0x8410
#define TFT_WHITE   0xFFFF
#define TFT_RED     0xF800
#define TFT_ORANGE  0xFA60
#define TFT_YELLOW  0xFFE0  
#define TFT_LIME    0x07FF
#define TFT_GREEN   0x07E0
#define TFT_CYAN    0x07FF
#define TFT_AQUA    0x04FF
#define TFT_BLUE    0x001F
#define TFT_MAGENTA 0xF81F
#define TFT_PINK    0xF8FF

uint16_t TFT_MAIN = 0xFFFF;
uint16_t TFT_SEC = 0xF81F;
int mainMenuPosition = 1;
int settingsPosition = 1;

int x = 0;
int y = 0;
int size = 20;
uint16_t cursorColor = 0xF81F;
int lightState = 1;
bool case3Cleared = false;
bool isInSettings = false;


void setup() {
  //display setup
  tft.init();
  tft.setRotation(1);
  clearScreen();
  //button setup
  pinMode(0, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  //startup screen
  //loadingScreen();
  //setup code
  mainMenuScreen();
  osName();
}

void loop() {
  if(digitalRead(0) == 0  && isInSettings == false) {
    switch(mainMenuPosition) {
      case 1:
      mainMenuScreen();
      positionOne(29, 22, 30, cursorColor);
      mainMenuPosition = 2;
      osName();
      delay(100);
      break;
      case 2:
      mainMenuScreen();
      positionOne(71, 22, 30, cursorColor);
      mainMenuPosition = 3;
      osName();
      delay(100);
      break;
      case 3:
      mainMenuScreen();
      positionOne(108, 22, 30, cursorColor);
      mainMenuPosition = 4;
      osName();
      delay(100);
      break;
      case 4:
      mainMenuScreen();
      positionOne(148, 22, 30, cursorColor);
      mainMenuPosition = 5;
      osName();
      delay(100);
      break;
      case 5:
      mainMenuScreen();
      positionOne(188, 22, 30, cursorColor);
      mainMenuPosition = 6;
      osName();
      delay(100);
      break;
      case 6:
      mainMenuScreen();
      positionOne(27, 90, 30, cursorColor);
      mainMenuPosition = 7;
      osName();
      delay(100);
      break;
      case 7:
      mainMenuScreen();
      positionOne(68, 90, 30, cursorColor);
      mainMenuPosition = 8;
      osName();
      delay(100);
      break;
      case 8:
      mainMenuScreen();
      positionOne(108, 90, 30, cursorColor);
      mainMenuPosition = 9;
      osName();
      delay(100);
      break;
      case 9:
      mainMenuScreen();
      positionOne(150, 88, 30, cursorColor);
      mainMenuPosition = 10;
      osName();
      delay(100);
      break;
      case 10:
      mainMenuScreen();
      positionOne(185, 88, 30, cursorColor);
      mainMenuPosition = 11;
      osName();
      delay(100);
      break;
      case 11:
      mainMenuScreen();
      mainMenuPosition = 1;
      osName();
      delay(100);
      break;

      default:
      mainMenuScreen();
      delay(10);
      break;
    }
  }

  if(digitalRead(35) == 0 && isInSettings == false) {
    switch(mainMenuPosition) {
      case 2:
      
        switch(lightState) {
        case 1:
        TFT_MAIN = 0xF81F;
        cursorColor = 0xFFFF;
        lightState = 2;
        delay(100);
       break;
        case 2:
        TFT_MAIN = 0xFFFF;
       cursorColor = 0xF81F;
       lightState = 1;
       delay(100);
       break;
       }

      mainMenuScreen();
      delay(200);
      break;
      
      case 3:

      printSettings();
      delay(200);
      break;

      case 4:

      break;
      
      case 5:

      break;

      case 6:

      break;

      case 7:
      tft.setRotation(0);
      displaySyndra(syndra0, 135, 240, 0, 0);
      delay(100);
      break;

      case 8:

      break;

      case 9:

      break;

      case 10:

      break;

      case 11:
      tft.fillScreen(TFT_BLACK);
      delay(100);
      break;
      default:
      delay(10);
      break;
    }
  }

  if(digitalRead(0) == 0 && isInSettings == true) {
    switch(settingsPosition) {
      case 1:
        printSettings();
        positionTwo(30, 2, 10, 0x0000);
        settingsPosition = 2;
        delay(200);
      break;
      case 2:
        printSettings();
        positionTwo(30, 18, 10, 0x0000);
        settingsPosition = 3;
        delay(200);
      break;
      case 3:
        printSettings();
        positionTwo(30, 34, 10, 0x0000);
        settingsPosition = 4;
        delay(200);
      break;
      case 4:
        printSettings();
        positionTwo(30, 50, 10, 0x0000);
        settingsPosition = 5;
        delay(200);
      break;
      case 5:
        printSettings();
        positionTwo(30, 66, 10, 0x0000);
        settingsPosition = 6;
        delay(200);
      break;
      case 6:
        printSettings();
        positionTwo(30, 82, 10, 0x0000);
        settingsPosition = 7;
        delay(200);
      break;
      case 7:
        printSettings();
        positionTwo(30, 98, 10, 0x0000);
        settingsPosition = 8;
        delay(200);
      break;
      case 8:
        printSettings();
        positionTwo(30, 114, 10, 0x0000);
        settingsPosition = 1;
        delay(200);
      break;
    }
  }

  if(digitalRead(35) == 0 && isInSettings == true) {
    switch(settingsPosition) {
      case 1:

      break;
      case 2:
      clearScreen();
      break;
      case 3:

      break;
      case 4:

      break;
      case 5:

      break;
      case 6:

      break;
      case 7:

      break;
      case 8:

      break;
    }
  }

}

void clearScreen() {
  tft.fillScreen(TFT_BLACK);
}

void clearScreenW() {
  tft.fillScreen(TFT_WHITE);
}

void mainMenuScreen() {
  tft.drawBitmap(0,0,mainmenu, 240, 135, TFT_MAIN);
}

void printSettings() {
  clearScreenW();
  tft.setCursor(0, 0);
  tft.setTextFont(2);
  isInSettings = true;
  tft.println("       Message:");
  tft.println("       <3:");
  tft.println("       Info:");
  tft.println("       1:");
  tft.println("       2:");
  tft.println("       3:");
  tft.println("       4:");
  tft.println("       Exit:");
}

void loadingScreen() {
  tft.drawBitmap(0,0,startupLogo, 240, 135, TFT_MAIN);
  delay(2000);
  clearScreen();
  tft.drawBitmap(0,0,loading0, 240, 135, TFT_MAIN);
  delay(1000);
  clearScreen();
  tft.drawBitmap(0,0,loading1, 240, 135, TFT_MAIN);
  delay(500);
  clearScreen();
  tft.drawBitmap(0,0,loading2, 240, 135, TFT_MAIN);
  delay(250);
  clearScreen();
  tft.drawBitmap(0,0,loading3, 240, 135, TFT_MAIN);
  delay(500);
  clearScreen();
  tft.drawBitmap(0,0,loading4, 240, 135, TFT_MAIN);
  delay(1000);
  clearScreen();
  tft.drawBitmap(0,0,loading5, 240, 135, TFT_MAIN);
  delay(250);
  clearScreen();
  tft.drawBitmap(0,0,loading6, 240, 135, TFT_MAIN);
  delay(1500);
  clearScreen();
  tft.drawBitmap(0,0,loading7, 240, 135, TFT_MAIN);
  delay(500);
  clearScreen();
}


void displaySyndra(const unsigned char *syndra0, int width, int height, int x, int y) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      int pixelIndex = (row * width + col) / 2; // Calculate pixel index
      int pixelValue = pgm_read_byte(syndra0 + pixelIndex); // Read pixel value from PROGMEM

      // Extract the 4-bit grayscale value
      int grayscale = (pixelValue >> ((col % 2) * 4)) & 0x0F;

      tft.drawPixel(x + col, y + row, tft.color565(grayscale * 16, grayscale * 16, grayscale * 16));
    }
  }
}


void osName() {
  tft. setTextColor(TFT_BLACK);
  tft.setCursor(95, 0, 2);
  tft.println("Pavlii OS");
}

void positionOne(int x, int y, int size, uint16_t cursorColor) {
  // Top and bottom lines
  tft.drawLine(x, y, x + size - 1, y, cursorColor);
  tft.drawLine(x, y + size - 1, x + size - 1, y + size - 1, cursorColor);

  // Left and right lines
  tft.drawLine(x, y, x, y + size - 1, cursorColor);
  tft.drawLine(x + size - 1, y, x + size - 1, y + size - 1, cursorColor);
}

void positionTwo(int x, int y, int size, uint16_t cursorColor) {
  // Top and bottom lines
  tft.drawLine(x, y, x + size - 1, y, cursorColor);
  tft.drawLine(x, y + size - 1, x + size - 1, y + size - 1, cursorColor);

  // Left and right lines
  tft.drawLine(x, y, x, y + size - 1, cursorColor);
  tft.drawLine(x + size - 1, y, x + size - 1, y + size - 1, cursorColor);
}


/*
  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined
  tft.fillScreen(TFT_GREY);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'tft.println'
  //  or stay on the line is there is room for the text with tft.print)
  tft.setCursor(0, 0, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_WHITE,TFT_BLACK);  tft.setTextSize(1);
  // We can now plot text on screen using the "print" class
  tft.println("Hello World!");
  
  // Set the font colour to be yellow with no background, set to font 7
  tft.setTextColor(TFT_YELLOW); tft.setTextFont(2);
  tft.println(1234.56);
  
  // Set the font colour to be red with black background, set to font 4
  tft.setTextColor(TFT_RED,TFT_BLACK);    tft.setTextFont(4);
  tft.println((long)3735928559, HEX); // Should print DEADBEEF

  // Set the font colour to be green with black background, set to font 2
  tft.setTextColor(TFT_GREEN,TFT_BLACK);
  tft.setTextFont(2);
  tft.println("Groop");

  // Test some print formatting functions
  float fnumber = 123.45;
   // Set the font colour to be blue with no background, set to font 2
  tft.setTextColor(TFT_BLUE);    tft.setTextFont(2);
  tft.print("Float = "); tft.println(fnumber);           // Print floating point number
  tft.print("Binary = "); tft.println((int)fnumber, BIN); // Print as integer value in binary
  tft.print("Hexadecimal = "); tft.println((int)fnumber, HEX); // Print as integer number in Hexadecimal

  while(1) yield(); // We must yield() to stop a watchdog timeout.
  */