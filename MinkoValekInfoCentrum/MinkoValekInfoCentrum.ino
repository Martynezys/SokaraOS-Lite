#include <minkoValekInfoCentrumBitmaps.h>
#include "driver/gpio.h"
#include <rom/ets_sys.h>
#include <TFT_eSPI.h> 
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
long randNumber;
int lolChampNumber = 0;

void setup() {
  //display setup
  tft.init();
  tft.setRotation(1);
  clearScreen();
  //button setup
  pinMode(0, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  //startup screen
  loadingScreen();
  //setup code
  mainMenuScreen();
}

void loop() {
  if(digitalRead(0) == 0  && isInSettings == false) {
    switch(mainMenuPosition) {
      case 1:
      mainMenuScreen();
      positionOne(29, 22, 30, cursorColor);
      mainMenuPosition = 2;
      delay(100);
      break;
      case 2:
      mainMenuScreen();
      positionOne(71, 22, 30, cursorColor);
      mainMenuPosition = 3;
      delay(100);
      break;
      case 3:
      mainMenuScreen();
      positionOne(108, 22, 30, cursorColor);
      mainMenuPosition = 4;
      delay(100);
      break;
      case 4:
      mainMenuScreen();
      positionOne(148, 22, 30, cursorColor);
      mainMenuPosition = 5;
      delay(100);
      break;
      case 5:
      mainMenuScreen();
      positionOne(188, 22, 30, cursorColor);
      mainMenuPosition = 6;
      delay(100);
      break;
      case 6:
      mainMenuScreen();
      positionOne(27, 90, 30, cursorColor);
      mainMenuPosition = 7;
      delay(100);
      break;
      case 7:
      mainMenuScreen();
      positionOne(68, 90, 30, cursorColor);
      mainMenuPosition = 8;
      delay(100);
      break;
      case 8:
      mainMenuScreen();
      positionOne(108, 90, 30, cursorColor);
      mainMenuPosition = 9;
      delay(100);
      break;
      case 9:
      mainMenuScreen();
      positionOne(150, 88, 30, cursorColor);
      mainMenuPosition = 10;
      delay(100);
      break;
      case 10:
      mainMenuScreen();
      positionOne(185, 88, 30, cursorColor);
      mainMenuPosition = 11;
      delay(100);
      break;
      case 11:
      mainMenuScreen();
      mainMenuPosition = 1;
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
      //light
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
      //lol champ roulette
      case 4:
      clearScreen();
      lolChampNumber = random(17);
      //lolChampNumber = 16;
      switch (lolChampNumber) {
        case 1: 
        tft.drawBitmap(60,7,cassiopeia, 120, 120, TFT_GREEN);
        delay(200);
        break;
        case 2: 
        tft.drawBitmap(60,7,diana, 124, 117, TFT_WHITE);
        delay(200);
        break;
        case 3: 
        tft.drawBitmap(60,7,jinx, 120, 120, TFT_BLUE);
        delay(200);
        break;
        case 4: 
        tft.drawBitmap(60,7,karma, 120, 120, TFT_GREEN);
        delay(200);
        break;
        case 5: 
        tft.drawBitmap(60,7,leona, 120, 120, TFT_YELLOW);
        delay(200);
        break;
        case 6: 
        tft.drawBitmap(60,7,lulu, 120, 120, TFT_PURPLE);
        delay(200);
        break;
        case 7: 
        tft.drawBitmap(60,7,morgana, 121, 119, TFT_PURPLE);
        delay(200);
        break;
        case 8: 
        tft.drawBitmap(60,7,nami, 122, 115, TFT_GREEN);
        delay(200);
        break;
        case 9: 
        tft.drawBitmap(60,7,neeko, 120, 120, TFT_PINK);
        delay(200);
        break;
        case 10: 
        tft.drawBitmap(60,7,senna, 120, 120, TFT_GREEN);
        delay(200);
        break;
        case 11: 
        tft.drawBitmap(60,7,sona, 120, 120, TFT_BLUE);
        delay(200);
        break;
        case 12: 
        tft.drawBitmap(60,7,syndra, 120, 120, TFT_PURPLE);
        delay(200);
        break;
        case 13: 
        tft.drawBitmap(60,7,veigar, 120, 120, TFT_PURPLE);
        delay(200);
        break;
        case 14: 
        tft.drawBitmap(60,7,velkoz, 116, 115, TFT_PINK);
        delay(200);
        break;
        case 15: 
        tft.drawBitmap(60,7,zyra, 121, 122, TFT_RED);
        delay(200);
        break;
        case 16: 
        tft.drawBitmap(60,7,soraka, 118, 115, TFT_PURPLE);
        delay(200);
        break;
      }

      break;
      // wifi finder
      case 5:
      clearScreen();
      tft.drawBitmap(0,0,ladypopular, 240, 135, TFT_MAGENTA);
      delay(200);
      break;
      //loop
      case 6:
      clearScreen();
      tft.drawBitmap(0,0,happy, 240, 135, TFT_YELLOW);
      delay(200);
      break;
      //image
      case 7:
      tft.setRotation(1);
      while (mainMenuPosition == 7) {
      clearScreen();
      tft.drawBitmap(0,0,leona0, 240, 135, TFT_YELLOW);
      delay(200);
      clearScreen();
      tft.drawBitmap(0,0,leona1, 240, 135, TFT_YELLOW);
      delay(200);
      }
      break;
      // fire
      case 8:
      clearScreen();
      tft.drawBitmap(0,0,stvorica, 240, 135, TFT_WHITE);
      delay(200);
      break;
      //bug fix
      case 9:
      tft.setRotation(1);
      clearScreen();
      mainMenuScreen();
      isInSettings = false;
      settingsPosition = 1;
      mainMenuPosition = 1;
      break;

      case 10:
      tft.setCursor(115, 62);
      clearScreenW();
      randNumber = random(7);
      tft.println(randNumber);
      delay(50);
      break;
      //turn off screen
      case 11:
      tft.fillScreen(TFT_BLACK);
      delay(100);
      break;
      // cycle
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
      //message
      case 2:
      clearScreenW();
      tft.setCursor(0, 0);
      tft.setTextColor(TFT_BLACK);
      tft.println("");
      tft.println("");
      tft.println("Uzivaj 18tky");
      tft.println("Pokoj od gormita");
      tft.println("A maj pici ostatnych");
      delay(200);
      break;
      //cool stuff
      case 3:
      clearScreen();
      tft.setCursor(0, 0);
      tft.setRotation(0);
      tft.setTextColor(TFT_BLACK);
      tft.drawBitmap(0,0,syndra0, 135, 240, TFT_MAGENTA);
      delay(200);
      break;
      //cat
      case 4:
      tft.setCursor(0, 0);
      clearScreenW();
      delay(200);
      break;
      //pointless info
      case 5:
      clearScreenW();
      tft.setCursor(0, 0);
      tft.println(" Hours spent: 56h");
      tft.println(" Lines of code: 509");
      tft.println(" Number of bitmaps: 34");
      tft.println(" ");
      delay(200);
      break;
      //technical info
      case 6:
      clearScreenW();
      tft.setCursor(0, 0);
      tft.println(" CHIPSET: ESPRESSIF-ESP32 Xtensa");
      tft.println(" DISPLAY: IPS ST7789V 1.14 Inch");
      tft.println(" MAX DIST: 300m");
      tft.println(" BLUETOOTH: YES");
      tft.println(" WIFI: YES");
      tft. setTextColor(TFT_MAGENTA);
      tft.println(" OS: PavliiOS");
      tft. setTextColor(TFT_BLACK);
      tft.println(" BOARD: LilyGO TTGO");
      tft.println(" CONNECTOR: USB-C");
      delay(200);
      break;
      //made by / for
      case 7:
      clearScreenW();
      tft.setCursor(0, 0);
      tft.println("");
      tft.println("");
      tft.println("");
      tft. setTextColor(TFT_RED);
      tft.println("Made by: Martynezys");
      tft. setTextColor(TFT_MAGENTA);
      tft.println("Made for: pavlinaniejecool");
      tft. setTextColor(TFT_BLACK);
      delay(200);
      break;
      //exit xd
      case 8:
      tft.setRotation(1);
      clearScreen();
      mainMenuScreen();
      delay(200);
      isInSettings = false;
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
  tft.setRotation(1);
  tft.drawBitmap(0,0,mainmenu, 240, 135, TFT_MAIN);
  osName();
}



void printSettings() {
  clearScreenW();
  tft.setCursor(0, 0);
  tft.setTextFont(2);
  isInSettings = true;
  tft.println("       Message:");
  tft.println("       Cool Stuff:");
  tft.println("       Cat:");
  tft.println("       Pointless info:");
  tft.println("       Technical info:");
  tft.println("       Made by / for:");
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