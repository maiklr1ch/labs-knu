#include <iostream>
#include <vector>

using namespace std;

struct SquareMatrix {
    int matrixSize;
    vector<vector<int>> data;

    SquareMatrix(int n) : matrixSize(n), data(n, vector<int>(n, 0)) {}

    void generate() {
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }

    void print() {
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    SquareMatrix operator+(const SquareMatrix& other) const {
        SquareMatrix result(matrixSize);

        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    SquareMatrix operator*(const SquareMatrix& other) const {
        SquareMatrix result(matrixSize);

        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                for (int k = 0; k < matrixSize; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    int matrixSize;
    cout << "Enter matrix size: ";
    cin >> matrixSize;

    SquareMatrix m1(matrixSize);
    m1.generate();

    cout << "First:\n";
    m1.print();

    SquareMatrix m2(matrixSize);
    m2.generate();

    cout << "Second:\n";
    m2.print();

    SquareMatrix sum = m1 + m2;
    cout << "Add:\n";
    sum.print();

    SquareMatrix mult = m1 * m2;
    cout << "Multiply:\n";
    mult.print();

    return 0;
}
