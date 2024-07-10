//
// Created by Rafael Magana  on 09/07/24.
//

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Matrix.h"
#include "Game.h"
#include <chrono>

class GameOfLife {
private:
    Matrix matrix;
    Game game;
    std::chrono::time_point<std::chrono::system_clock> startTime;
    long totalTime;

public:
    GameOfLife(int size);
    GameOfLife(int width, int height);
    bool getCell(int posX, int posY);
    void initializeBoard();
    void step();
    long getTime();
};

#endif // GAMEOFLIFE_H // GAMEOFLIFE_H //GAMEOFLIFEESP_GAMEOFLIFE_H
