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
    ~Matrix(); // Destructor para liberar la memoria

    void fillRandomly();
    bool getCell(int posX, int posY) const;
    void setCell(bool alive, int posX, int posY);
    bool** getCells() const; // Proporciona acceso directo a la matriz de células
    void setCells(bool** newCells); // Permite la modificación directa de la matriz de células
    int getWidth() const; // Devuelve la anchura de la matriz
    int getHeight() const; // Devuelve la altura de la matriz
};

#endif // MATRIX_H // MATRIX_H //GAMEOFLIFEESP_MATRIX_H
