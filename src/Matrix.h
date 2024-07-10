//
// Created by Rafael Magana  on 09/07/24.
//

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    bool** cells;
    int width, height;

public:
    Matrix(int size);
    Matrix(int width, int height);
    ~Matrix();

    void fillRandomly();
    bool getCell(int x, int y) const;
    void setCell(bool alive, int x, int y);
    bool** getCells() const;
    void setCells(bool** newCells);
    int getWidth() const;
    int getHeight() const;
};

#endif // MATRIX_H // MATRIX_H //GAMEOFLIFEESP_MATRIX_H
