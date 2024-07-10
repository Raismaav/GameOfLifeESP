//
// Created by Rafael Magana  on 09/07/24.
//

#ifndef GAME_H
#define GAME_H

#include "Matrix.h"

class Game {
private:
    static bool** cells;
    static Matrix* matrix;
    bool** buffer;
    int width, height;

    int countAliveNeighbors(int x, int yPosition);

public:
    Game(Matrix* matrix);
    void updateGame();
};

#endif // GAME_H//GAMEOFLIFEESP_GAME_H
