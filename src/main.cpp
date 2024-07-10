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
GameOfLife game = GameOfLife(SCREEN_WIDTH, SCREEN_WIDTH);

void setup()   {
    display.begin(i2c_Address, true);
    delay(250);
    display.clearDisplay();
    game.initializeBoard();
    display.display();

}


void loop() {
    display.clearDisplay();
    game.step();
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            if (game.getCell(i, j)) {
                display.drawPixel(i, j, SH110X_WHITE);
            }
        }
    }
    display.setCursor(1, 1);
    display.setTextColor(SH110X_BLACK, SH110X_WHITE);
    display.setTextSize(1);

    // use the display.print() function to print the step time
    display.print(game.getStepTime());
    display.print(" ms");
    display.display();


    delay(10);
}
