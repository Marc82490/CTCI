#include <iostream>
#include <vector>

#define N 4

using namespace std;

/* THE KEY TO THIS SOLUTION IS KNOWING THAT ROTATING AN NxN MATRIX 90 DEGREES IS THE SAME AS TRANSPOSING THE MATRIX
AND FLIPPING EACH ROW SYMMETRICALLY ABOUT THE Y-AXIS. */
void rotateMatrix(int matrix[][N]) {
    int len = N;

    // Loop through each row, then each column, and transpose the matrix about the diagonal.
    for (int i{}; i < len; i++)
    {
        for (int j{i}; j < len; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Loop through each row, flipping each row symmetrically about the Y-axis.
    for (int i{}; i < len; i++)
    {
        for (int j{}; j < (len / 2); j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][len - 1 - j];
            matrix[i][len - 1 - j] = temp;
        }
    }
}

int main() {
    int matrix[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    std::cout << "BEFORE\n";
    for (int i{}; i < N; i++)
    {
        for (int j{}; j < N; j++)
        {
            std::cout << matrix[i][j];
            std::cout << '\t';
        }
        std::cout << '\n';
    }

    rotateMatrix(matrix);
    std::cout << "AFTER\n";
    for (int i{}; i < N; i++)
    {
        for (int j{}; j < N; j++)
        {
            std::cout << matrix[i][j];
            std::cout << '\t';
        }
        std::cout << '\n';
    }
}