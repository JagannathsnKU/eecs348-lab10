#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>

class Matrix {
private:
    int size;
    std::vector<std::vector<int>> data;

public:
    // Constructors
    Matrix();
    Matrix(int n);

    // File reading & display
    bool readFromFile(const std::string& filename, std::ifstream& file);
    void display() const;

    // Getters and Setters
    int getSize() const;
    int getElement(int r, int c) const;
    void setElement(int r, int c, int val);

    // Operator Overloading
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // Required Operations (Practices 4, 5, 6, 7)
    void displayDiagonalSums() const;
    Matrix swapRows(int r1 = 0, int r2 = 1) const;
    Matrix swapColumns(int c1 = 0, int c2 = 1) const;
    Matrix updateElement(int r = 0, int c = 0, int val = 100) const;
};

#endif
