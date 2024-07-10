#include "GameOfLife.h"

GameOfLife::GameOfLife(int size) : matrix(size), game(&matrix) {}

GameOfLife::GameOfLife(int width, int height) : matrix(width, height), game(&matrix) {}

bool GameOfLife::getCell(int x, int y) {
    return matrix.getCell(x, y);
}

void GameOfLife::setCell(bool alive, int x, int y) {
    matrix.setCell(alive, x, y);
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

long GameOfLife::getStepTime() {
    return totalTime;
}