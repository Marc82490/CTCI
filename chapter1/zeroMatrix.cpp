#include <iostream>
#include <string>
#include <vector>
#include <set>

constexpr int M = 5;
constexpr int N = 4;

using namespace std;

void zeroMatrix(int matrix[M][N]) {
    set<int> rows{};
    set<int> cols{};

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

    cout << "BEFORE\n";
    for (int i{}; i < M; i++)
    {
        for (int j{}; j < N; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
    zeroMatrix(matrix);

    cout << "AFTER\n";
    for (int i{}; i < M; i++)
    {
        for (int j{}; j < N; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
}