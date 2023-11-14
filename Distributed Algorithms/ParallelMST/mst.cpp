#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <fstream>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    std::vector<Edge> edges;
    Graph(int V, int E) : V(V), E(E) {
        edges.resize(E);
    }
};

struct Subset {
    int parent, rank;
};

int find(std::vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(std::vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void boruvkasMST(Graph& graph) {
    std::ofstream outfile("out.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error opening out.txt for writing" << std::endl;
        return;
    }

    int V = graph.V;
    int E = graph.E;
    std::vector<Edge> result(V);
    std::vector<Subset> subsets(V);
    int numThreads = std::thread::hardware_concurrency();

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int numTrees = V;
    int mstWeight = 0;

    while (numTrees > 1) {
        std::vector<int> cheapest(V, -1);
        std::vector<std::thread> threads;
        std::mutex mtx;

        for (int t = 0; t < numThreads; t++) {
            threads.emplace_back([&](int begin, int end) {
                for (int i = begin; i < end; i++) {
                    int set1 = find(subsets, graph.edges[i].src);
                    int set2 = find(subsets, graph.edges[i].dest);

                    if (set1 != set2) {
                        mtx.lock();
                        if (cheapest[set1] == -1 ||
                            graph.edges[cheapest[set1]].weight > graph.edges[i].weight)
                            cheapest[set1] = i;

                        if (cheapest[set2] == -1 ||
                            graph.edges[cheapest[set2]].weight > graph.edges[i].weight)
                            cheapest[set2] = i;
                        mtx.unlock();
                    }
                }
            }, t * E / numThreads, (t + 1) * E / numThreads);
        }

        for (auto& t : threads) {
            t.join();
        }

        for (int i = 0; i < V; i++) {
            if (cheapest[i] != -1) {
                int set1 = find(subsets, graph.edges[cheapest[i]].src);
                int set2 = find(subsets, graph.edges[cheapest[i]].dest);

                if (set1 != set2) {
                    mstWeight += graph.edges[cheapest[i]].weight;
                    outfile << "Edge " << graph.edges[cheapest[i]].src << " - "
                            << graph.edges[cheapest[i]].dest << " weight: "
                            << graph.edges[cheapest[i]].weight << std::endl;
                    unionSets(subsets, set1, set2);
                    numTrees--;
                }
            }
        }
    }
    outfile << "Total weight of MST: " << mstWeight << std::endl;
    outfile.close();
}

void readInputAndRun() {
    std::ifstream infile("in.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening in.txt" << std::endl;
        return;
    }

    int V, E;
    infile >> V >> E;

    Graph graph(V, E);
    for (int i = 0; i < E; ++i) {
        infile >> graph.edges[i].src >> graph.edges[i].dest >> graph.edges[i].weight;
    }

    infile.close();
    boruvkasMST(graph);
}

int main() {
    readInputAndRun();
    return 0;
}
