#include "Matrix.h"
#include <cstdlib> // Para rand() y srand()
#include <ctime> // Para time()

Matrix::Matrix(int size) : Matrix(size, size) {}

Matrix::Matrix(int width, int height) : width(width), height(height) {
    cells = new bool*[width];
    for(int i = 0; i < width; ++i) {
        cells[i] = new bool[height];
        for(int j = 0; j < height; ++j) {
            cells[i][j] = false;
        }
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < width; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Matrix::fillRandomly() {
    srand(time(0));
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            cells[i][j] = rand() % 2 == 1;
        }
    }
}

bool Matrix::getCell(int posX, int posY) const {
    return cells[posX][posY];
}

void Matrix::setCell(bool alive, int posX, int posY) {
    cells[posX][posY] = alive;
}

bool** Matrix::getCells() const {
    return cells;
}

void Matrix::setCells(bool** newCells) {
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            cells[i][j] = newCells[i][j];
        }
    }
}

int Matrix::getWidth() const {
    return width;
}

int Matrix::getHeight() const {
    return height;
}