#include <iostream>

#define MAX_ROWS 100
#define MAX_COLS 100

void transpose(char matrix[MAX_ROWS][MAX_COLS], char transposed[MAX_COLS][MAX_ROWS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    char matrix[MAX_ROWS][MAX_COLS];
    char transposed[MAX_COLS][MAX_ROWS];
    int rows, cols;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    std::cout << "Enter the matrix elements (single characters):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Element[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    transpose(matrix, transposed, rows, cols);

    std::cout << "Transposed matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
