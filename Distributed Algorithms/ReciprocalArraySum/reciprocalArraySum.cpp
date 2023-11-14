#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <fstream>

void partialReciprocalSum(const std::vector<double>& arr, size_t start, size_t end, double& result) {
    result = 0.0;
    for (size_t i = start; i < end; ++i) {
        result += 1.0 / arr[i];
    }
}

int main() {
    std::string inputFile = "in.txt";
    std::string outputFile = "out.txt";

    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    size_t arraySize, numThreads;
    if (!(input >> arraySize >> numThreads)) {
        std::cerr << "Error: Unable to read array size and number of threads from input file." << std::endl;
        return 1;
    }

    std::vector<double> numbers(arraySize);

    for (size_t i = 0; i < arraySize; ++i) {
        if (!(input >> numbers[i])) {
            std::cerr << "Error: Unable to read data from input file." << std::endl;
            return 1;
        }
    }

    input.close();

    std::vector<std::thread> threads;

    size_t chunkSize = arraySize / numThreads;
    std::vector<double> partialResults(numThreads, 0.0);

    for (int i = 0; i < numThreads; ++i) {
        size_t start = i * chunkSize;
        size_t end = (i == numThreads - 1) ? arraySize : (i + 1) * chunkSize;
        threads.emplace_back(partialReciprocalSum, std::ref(numbers), start, end, std::ref(partialResults[i]));
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    double finalResult = std::accumulate(partialResults.begin(), partialResults.end(), 0.0);

    std::ofstream output(outputFile);
    if (!output.is_open()) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    output << "Reciprocal Array Sum: " << finalResult << std::endl;
    output.close();

    return 0;
}
