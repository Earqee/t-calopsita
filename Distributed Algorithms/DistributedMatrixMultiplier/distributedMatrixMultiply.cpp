#include <iostream>
#include <vector>
#include <cmath>
#include <mpi.h>
#include <fstream>

using namespace std;

class Matrix {
    vector<vector<int>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

    void readFromInput(ifstream& in) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                in >> data[i][j];
            }
        }
    }

    void writeToOutput(ofstream& out) const {
        for (const auto& row : data) {
            for (int val : row) {
                out << val << " ";
            }
            out << endl;
        }
    }

    void multiply(const Matrix& A, const Matrix& B) {
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                for (int k = 0; k < A.cols; k++) {
                    data[i][j] += A.data[i][k] * B.data[k][j];
                }
            }
        }
    }

    int& operator()(int i, int j) {
        return data[i][j];
    }

    int* dataPtr() {
        return &data[0][0];
    }
};

class DistributedMatrixMultiplier {
    int rank, size, blockSize;

public:
    DistributedMatrixMultiplier() {
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
    }

    void multiply(Matrix& A, Matrix& B, Matrix& C, int n, int m) {
        int sqrtSize = sqrt(size);
        blockSize = n / sqrtSize;

        Matrix localA(blockSize, m);
        Matrix localB(m, blockSize);
        Matrix localC(blockSize, blockSize);

        MPI_Scatter(A.dataPtr(), blockSize * m, MPI_INT, localA.dataPtr(), blockSize * m, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scatter(B.dataPtr(), blockSize * m, MPI_INT, localB.dataPtr(), blockSize * m, MPI_INT, 0, MPI_COMM_WORLD);

        localC.multiply(localA, localB);

        MPI_Gather(localC.dataPtr(), blockSize * blockSize, MPI_INT, C.dataPtr(), blockSize * blockSize, MPI_INT, 0, MPI_COMM_WORLD);
    }

    int getRank() {
        return rank;
    }

    ~DistributedMatrixMultiplier() {
        MPI_Finalize();
    }
};

void testFunction() {
    int n, p, m;
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    cin >> n >> p >> m;

    Matrix A(n, p);
    Matrix B(p, m);
    Matrix C(n, m);

    A.readFromInput(inFile);
    B.readFromInput(inFile);

    DistributedMatrixMultiplier multiplier;
    multiplier.multiply(A, B, C, n, m);

    if (multiplier.getRank() == 0) {
        C.writeToOutput(outFile);
    }

    inFile.close();
    outFile.close();
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    testFunction();
    return 0;
}
