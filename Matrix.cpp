#include "Matrix.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>

Matrix::Matrix() : size(0) {}

Matrix::Matrix(int n) : size(n), data(n, std::vector<int>(n, 0)) {}

bool Matrix::readFromFile(const std::string& filename, std::ifstream& file) {
    if (!file.is_open()) return false;
    
    file >> size;
    data.assign(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> data[i][j];
        }
    }
    return true;
}

void Matrix::display() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Using setw(4) ensures numbers line up cleanly in columns
            std::cout << std::setw(4) << data[i][j];
        }
        std::cout << "\n";
    }
}

int Matrix::getSize() const {
    return size;
}

int Matrix::getElement(int r, int c) const {
    return data[r][c];
}

void Matrix::setElement(int r, int c, int val) {
    if (r >= 0 && r < size && c >= 0 && c < size) {
        data[r][c] = val;
    }
}

// Practice 2: Operator Overloading (+)
Matrix Matrix::operator+(const Matrix& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size for addition.");
    }
    Matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Practice 3: Operator Overloading (*)
Matrix Matrix::operator*(const Matrix& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size for multiplication.");
    }
    Matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Practice 4: Diagonal Sums
void Matrix::displayDiagonalSums() const {
    int mainSum = 0;
    int secondarySum = 0;
    for (int i = 0; i < size; ++i) {
        mainSum += data[i][i];
        secondarySum += data[i][size - 1 - i];
    }
    std::cout << "Main diagonal sum: " << mainSum << "\n";
    std::cout << "Secondary diagonal sum: " << secondarySum << "\n";
}

// Practice 5: Swap Rows (passed by value)
Matrix Matrix::swapRows(int r1, int r2) const {
    Matrix result = *this;
    if (r1 >= 0 && r1 < size && r2 >= 0 && r2 < size) {
        std::swap(result.data[r1], result.data[r2]);
    }
    return result;
}

// Practice 6: Swap Columns
Matrix Matrix::swapColumns(int c1, int c2) const {
    Matrix result = *this;
    if (c1 >= 0 && c1 < size && c2 >= 0 && c2 < size) {
        for (int i = 0; i < size; ++i) {
            std::swap(result.data[i][c1], result.data[i][c2]);
        }
    }
    return result;
}

// Practice 7: Update Matrix Element
Matrix Matrix::updateElement(int r, int c, int val) const {
    Matrix result = *this;
    if (r >= 0 && r < size && c >= 0 && c < size) {
        result.data[r][c] = val;
    }
    return result;
}
