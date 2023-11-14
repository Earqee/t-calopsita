#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>

struct Student {
    std::string name;
    int score;
};

void readStudentData(const std::string& filename, std::vector<Student>& students, int& numThreads) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        exit(1);
    }

    input >> numThreads; // Read the number of threads
    int numStudents;
    input >> numStudents; // Read the number of students

    students.resize(numStudents);
    for (int i = 0; i < numStudents; ++i) {
        input >> students[i].name >> students[i].score;
    }

    input.close();
}

void calculateStatistics(const std::vector<Student>& students, double& average, int& minimum, int& maximum, std::mutex& mtx) {
    average = 0;
    minimum = std::numeric_limits<int>::max();
    maximum = std::numeric_limits<int>::min();

    for (const Student& student : students) {
        average += student.score;
        if (student.score < minimum) {
            minimum = student.score;
        }
        if (student.score > maximum) {
            maximum = student.score;
        }
    }

    average /= students.size();
}

int main() {
    std::string inputFile = "in.txt";
    std::string outputFile = "out.txt";
    
    int numThreads;
    std::vector<Student> students;
    readStudentData(inputFile, students, numThreads);

    std::vector<std::thread> threads;
    std::vector<double> threadAverages(numThreads, 0.0);
    std::vector<int> threadMinimums(numThreads, std::numeric_limits<int>::max());
    std::vector<int> threadMaximums(numThreads, std::numeric_limits<int>::min());
    std::mutex dataMutex;

    int chunkSize = students.size() / numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; ++i) {
        int end = (i == numThreads - 1) ? students.size() : start + chunkSize;
        threads.emplace_back(calculateStatistics, std::vector<Student>(students.begin() + start, students.begin() + end), std::ref(threadAverages[i]), std::ref(threadMinimums[i]), std::ref(threadMaximums[i]), std::ref(dataMutex));
        start = end;
    }

    for (std::thread& thread : threads) {
        thread.join();
    }

    double average = 0;
    int minimum = std::numeric_limits<int>::max();
    int maximum = std::numeric_limits<int>::min();

    for (int i = 0; i < numThreads; ++i) {
        average += threadAverages[i];
        if (threadMinimums[i] < minimum) {
            minimum = threadMinimums[i];
        }
        if (threadMaximums[i] > maximum) {
            maximum = threadMaximums[i];
        }
    }

    average /= numThreads;

    std::ofstream output(outputFile);
    if (!output.is_open()) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    output << "Average Score: " << average << std::endl;
    output << "Minimum Score: " << minimum << std::endl;
    output << "Maximum Score: " << maximum << std::endl;
    output.close();

    return 0;
}
