#include <iostream>
#include <fstream>
#include "Matrix.h"

int main() {
    std::string filename;
    std::cout << "Enter input filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    int n;
    file >> n;

    // Practice 1: Initialize and read matrices A and B
    Matrix matA(n);
    Matrix matB(n);

    // Read Matrix A data
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            file >> val;
            matA.setElement(i, j, val);
        }
    }

    // Read Matrix B data
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            file >> val;
            matB.setElement(i, j, val);
        }
    }

    std::cout << "Matrix A:\n";
    matA.display();

    std::cout << "Matrix B:\n";
    matB.display();

    // Practice 2: Addition via Operator Overloading
    Matrix sumMat = matA + matB;
    std::cout << "A + B:\n";
    sumMat.display();

    // Practice 3: Multiplication via Operator Overloading
    Matrix prodMat = matA * matB;
    std::cout << "A * B:\n";
    prodMat.display();

    // Practice 4: Diagonal Sums
    std::cout << "Diagonal sums for Matrix A:\n";
    matA.displayDiagonalSums();

    // Practice 5: Swap Rows (default rows 0 and 1, let's swap 0 and 2 as per sample output)
    Matrix swappedRows = matA.swapRows(0, 2);
    std::cout << "Problem 5 - Rows 0 and 2 swapped:\n";
    swappedRows.display();

    // Practice 6: Swap Columns (default 0 and 1, let's swap 0 and 2 as per sample output)
    Matrix swappedCols = matA.swapColumns(0, 2);
    std::cout << "Problem 6 - Columns 0 and 2 swapped:\n";
    swappedCols.display();

    // Practice 7: Update Matrix Element (default row 0, col 0, val 100; sample output updates row 1, col 2 to 99)
    Matrix updatedMat = matA.updateElement(1, 2, 99);
    std::cout << "Problem 7 - Updated matrix:\n";
    updatedMat.display();

    file.close();
    return 0;
}
