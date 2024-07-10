#include "Game.h"

bool** Game::cells = nullptr;
Matrix* Game::matrix = nullptr;

Game::Game(Matrix* mat) {
    matrix = mat;
    cells = matrix->getCells();
    width = matrix->getWidth();
    height = matrix->getHeight();
    buffer = new bool*[width];
    for (int i = 0; i < width; ++i) {
        buffer[i] = new bool[height];
    }
}

void Game::updateGame() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int aliveNeighbors = countAliveNeighbors(i, j);
            buffer[i][j] = aliveNeighbors == 3 || (aliveNeighbors == 2 && cells[i][j]);
        }
    }
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            cells[i][j] = buffer[i][j];
        }
    }
    matrix->setCells(cells);
}

int Game::countAliveNeighbors(int x, int yPosition) {
    int alive = 0;
    int offsets[] = {-1, 0, 1};

    for (int dx : offsets) {
        for (int dy : offsets) {
            if (dx == 0 && dy == 0) continue;
            int xNeighbor = (x + dx + width) % width;
            int yNeighbor = (yPosition + dy + height) % height;
            if (cells[xNeighbor][yNeighbor]) alive++;
        }
    }
    return alive;
}