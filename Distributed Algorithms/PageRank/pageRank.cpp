#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

const double DAMPING_FACTOR = 0.85;
const double EPSILON = 1e-6;

struct Page {
    double rank = 1.0;
    std::vector<int> outgoing_links;
};

bool PageRank(std::vector<Page>& pages) {
    double change = 0;
    std::vector<double> new_ranks(pages.size(), 0.0);

    for (size_t i = 0; i < pages.size(); ++i) {
        for (int target : pages[i].outgoing_links) {
            new_ranks[target] += (pages[i].rank / pages[i].outgoing_links.size());
        }
    }

    for (size_t i = 0; i < pages.size(); ++i) {
        double old_rank = pages[i].rank;
        pages[i].rank = (1.0 - DAMPING_FACTOR) + DAMPING_FACTOR * new_ranks[i];
        change += std::abs(old_rank - pages[i].rank);
    }

    return change < EPSILON;
}

std::vector<Page> readInputFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    int numPages;
    file >> numPages;

    std::vector<Page> pages(numPages);
    for (int i = 0; i < numPages; ++i) {
        int numLinks;
        file >> numLinks;
        for (int j = 0; j < numLinks; ++j) {
            int link;
            file >> link;
            pages[i].outgoing_links.push_back(link);
        }
    }

    file.close();
    return pages;
}

void generateOutputFile(const std::vector<Page>& pages, const std::string& filename) {
    int iterations = 0;
    while (!PageRank(pages)) {
        ++iterations;
    }

    std::ofstream file(filename);
    if (file.is_open()) {
        file << "PageRank after " << iterations << " iterations:" << std::endl;
        for (size_t i = 0; i < pages.size(); ++i) {
            file << "Page " << i << ": " << pages[i].rank << std::endl;
        }
        file.close();
        std::cout << "Results written to " << filename << std::endl;
    } else {
        std::cerr << "Failed to open " << filename << std::endl;
    }
}

int main() {
    std::vector<Page> pages = readInputFile("in.txt");
    generateOutputFile(pages, "out.txt");
    return 0;
}