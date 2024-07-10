#include "GameOfLife.h"

GameOfLife::GameOfLife(int size) : matrix(size), game(&matrix), totalTime(0) {}

GameOfLife::GameOfLife(int width, int height) : matrix(width, height), game(&matrix), totalTime(0) {}

bool GameOfLife::getCell(int posX, int posY) {
    return matrix.getCell(posX, posY);
}

void GameOfLife::initializeBoard() {
    matrix.fillRandomly();
}

void GameOfLife::step() {
    auto start = std::chrono::system_clock::now();
    game.updateGame();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    totalTime = static_cast<long>(elapsed_seconds.count() * 1000);
}

long GameOfLife::getTime() {
    return totalTime;
}