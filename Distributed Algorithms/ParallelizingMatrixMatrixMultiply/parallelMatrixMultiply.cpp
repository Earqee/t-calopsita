#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <algorithm>
#include <numeric>

void readMatrix(const std::string& filename, std::vector<std::vector<int>>& matrix, int& rows, int& cols) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        exit(1);
    }

    input >> rows >> cols;
    matrix.resize(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            input >> matrix[i][j];
        }
    }

    input.close();
}

void parallelMatrixMultiplication(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int startRow, int endRow) {
    int colsA = A[0].size();
    int colsB = B[0].size();

    for (int i = startRow; i < endRow; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    std::string inputFile = "in.txt";
    std::string outputFile = "out.txt";

    int numThreads;
    int rowsA, colsA, colsB;

    std::vector<std::vector<int>> A, B, C;

    readMatrix(inputFile, A, rowsA, colsA);
    readMatrix(inputFile, B, rowsA, colsB);

    std::ifstream inputThreads(inputFile);
    if (!inputThreads.is_open()) {
        std::cerr << "Error: Unable to open input file for reading threads." << std::endl;
        return 1;
    }
    inputThreads >> numThreads;
    inputThreads.close();

    if (colsA != rowsA) {
        std::cerr << "Error: Matrix dimensions are incompatible for multiplication." << std::endl;
        return 1;
    }

    std::vector<std::thread> threads;

    int chunkSize = rowsA / numThreads;
    C.resize(rowsA, std::vector<int>(colsB, 0));

    for (int i = 0; i < numThreads; ++i) {
        int startRow = i * chunkSize;
        int endRow = (i == numThreads - 1) ? rowsA : (i + 1) * chunkSize;
        threads.emplace_back(parallelMatrixMultiplication, std::ref(A), std::ref(B), std::ref(C), startRow, endRow);
    }

    for (std::thread& thread : threads) {
        thread.join();
    }

    std::ofstream output(outputFile);
    if (!output.is_open()) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    output << rowsA << " " << colsB << std::endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            output << C[i][j] << " ";
        }
        output << std::endl;
    }

    output.close();

    return 0;
}
