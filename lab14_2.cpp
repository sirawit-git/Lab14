#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double matrix[][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void findLocalMax(const double matrix[][N], bool result[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                result[i][j] = false;
            } else {
                if (matrix[i][j] >= matrix[i - 1][j] &&
                    matrix[i][j] >= matrix[i + 1][j] &&
                    matrix[i][j] >= matrix[i][j - 1] &&
                    matrix[i][j] >= matrix[i][j + 1]) {
                    result[i][j] = true;
                } else {
                    result[i][j] = false;
                }
            }
        }
    }
}

void showMatrix(const bool matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double A[N][N];
    bool B[N][N];
    cout << "Input the matrix.....\n";
    inputMatrix(A);
    findLocalMax(A, B);
    cout << "Result is \n";
    showMatrix(B);
    return 0;
}
//Do not modify source code above this line 