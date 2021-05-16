#include <iostream>
#include <vector>

#define N 4

using namespace std;

void rotateMatrix(int matrix[][N]) {
    int len = N;

    for (int i{}; i < len; i++)
    {
        for (int j{i}; j < len; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

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

    cout << "BEFORE\n";
    for (int i{}; i < N; i++)
    {
        for (int j{}; j < N; j++)
        {
            cout << matrix[i][j];
            cout << '\t';
        }
        cout << '\n';
    }

    rotateMatrix(matrix);
    cout << "AFTER\n";
    for (int i{}; i < N; i++)
    {
        for (int j{}; j < N; j++)
        {
            cout << matrix[i][j];
            cout << '\t';
        }
        cout << '\n';
    }
}