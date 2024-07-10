#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include "GameOfLife.h"

#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
GameOfLife game = GameOfLife(SCREEN_WIDTH, SCREEN_HEIGHT);

void setup()   {
    delay(250);
    display.begin(i2c_Address, true);
    display.clearDisplay();
    game.initializeBoard();
    display.display();

}


void loop() {
    display.clearDisplay();
    game.step();
    display.display();
    delay(1000);
}
