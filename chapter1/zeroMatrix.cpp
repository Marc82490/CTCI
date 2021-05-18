#include <iostream>
#include <string>
#include <vector>
#include <set>

constexpr int M = 5;
constexpr int N = 4;

// using namespace std;

void zeroMatrix(int matrix[M][N]) {
    // Keep track of which rows and columns have 0s
    std::set<int> rows{};
    std::set<int> cols{};

    // Loop through each row and column. If the position has a 0, note the row and column position.
    for (int i{}; i < M; i++)
    {
        for (int j{}; j < N; j++)
        {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    // Loop through each row and column. If either of its positions are in the 0-sets, zero out the position.
    for (int i{}; i < M; i++)
    {
        for (int j{}; j < N; j++)
        {
            if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int matrix[M][N] = {{1,2,3,4}, {5,6,0,8}, {9,10,11,12}, {13,14,15,16}, {0,18,19,20}};

    std::cout << "BEFORE\n";
    for (int i{}; i < M; i++)
    {
        for (int j{}; j < N; j++) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << '\n';
    }
    zeroMatrix(matrix);

    std::cout << "AFTER\n";
    for (int i{}; i < M; i++)
    {
        for (int j{}; j < N; j++) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << '\n';
    }
}