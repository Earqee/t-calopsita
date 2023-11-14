#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
#include <mutex>
#include <condition_variable>

void processData(int threadID, int start, int end, const std::vector<int>& data, std::vector<int>& results, std::mutex& dataMutex, std::condition_variable& phase1Ready, std::condition_variable& phase2Ready, bool& phase1Complete) {
    int sum = 0;
    
    for (int i = start; i < end; ++i) {
        sum += data[i] * data[i];
    }
    
    std::unique_lock<std::mutex> lock(dataMutex);
    results[threadID] = sum;
    
    phase1Ready.notify_one();
    
    phase1Ready.wait(lock, [&]{ return phase1Complete; });

    int phase2Result = std::accumulate(results.begin(), results.end(), 0);
    
    lock.unlock();

    phase2Ready.notify_one();
}

int main() {
    std::string inputFile = "in.txt";
    std::string outputFile = "out.txt";

    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    int numElements;
    input >> numElements;
    std::vector<int> data(numElements);

    for (int i = 0; i < numElements; ++i) {
        input >> data[i];
    }

    input.close();

    int numThreads;
    std::cout << "Enter the number of threads: ";
    std::cin >> numThreads;

    std::vector<std::thread> threads;

    std::vector<int> results(numThreads, 0);
    std::mutex dataMutex;
    std::condition_variable phase1Ready;
    std::condition_variable phase2Ready;
    bool phase1Complete = false;

    int chunkSize = numElements / numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; ++i) {
        int end = (i == numThreads - 1) ? numElements : start + chunkSize;
        threads.emplace_back(processData, i, start, end, std::ref(data), std::ref(results), std::ref(dataMutex), std::ref(phase1Ready), std::ref(phase2Ready), std::ref(phase1Complete));
        start = end;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lock(dataMutex);
        phase1Complete = true;
    }

    phase1Ready.notify_all();

    {
        std::unique_lock<std::mutex> lock(dataMutex);
        phase2Ready.wait(lock, [&]{ return results[numThreads - 1] != 0; });
    }

    int finalResult = results[numThreads - 1];

    std::ofstream output(outputFile);
    if (!output.is_open()) {
        /* I'm honestly sick of doing this s*. */
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    output << "Final Result: " << finalResult << std::endl;
    output.close();

    return 0;
}
