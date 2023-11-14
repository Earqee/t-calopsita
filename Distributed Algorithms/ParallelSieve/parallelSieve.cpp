#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <fstream>

void markMultiples(std::vector<bool>& sieve, int prime, int n) {
    for (int i = prime * prime; i <= n; i += prime) {
        sieve[i] = false;
    }
}

void parallelSieve(int n) {
    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    std::vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    int limit = sqrt(n);
    
    for (int p = 2; p <= limit; p++) {
        if (sieve[p]) {
            threads.push_back(std::thread(markMultiples, std::ref(sieve), p, n));
            
            if (threads.size() >= numThreads) {
                for (auto &t : threads) {
                    t.join();
                }
                threads.clear();
            }
        }
    }
    
    for (auto &t : threads) {
        t.join();
    }

    std::ofstream outfile("out.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error opening out.txt for writing" << std::endl;
        return;
    }

    for (int p = 2; p <= n; p++) {
        if (sieve[p]) {
            outfile << p << " ";
        }
    }
    outfile << std::endl;
    outfile.close();
}

void readInputAndRun() {
    std::ifstream infile("in.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening in.txt" << std::endl;
        return;
    }

    int n;
    infile >> n;
    infile.close();

    parallelSieve(n);
}

int main() {
    readInputAndRun();
    return 0;
}
