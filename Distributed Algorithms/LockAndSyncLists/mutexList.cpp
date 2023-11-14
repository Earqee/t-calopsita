#include <iostream>
#include <mutex>
#include <thread>
#include <optional>
#include <fstream>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        std::mutex mtx;
        Node(T value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

public:
    LinkedList() {}

    void insert(T value) {
        std::unique_ptr<Node> new_node = std::make_unique<Node>(value);
        std::lock_guard<std::mutex> lg(head->mtx);
        new_node->next = std::move(head);
        head = std::move(new_node);
    }

    std::optional<T> search(T value) {
        Node* current = head.get();
        Node* prev = nullptr;

        while (current) {
            current->mtx.lock();
            if (prev) {
                prev->mtx.unlock();
            }

            if (current->data == value) {
                current->mtx.unlock();
                return {current->data};
            }

            prev = current;
            current = current->next.get();
        }

        if (prev) {
            prev->mtx.unlock();
        }
        return {};
    }

    bool remove(T value) {
        Node* current = head.get();
        Node* prev = nullptr;

        while (current) {
            current->mtx.lock();
            if (prev) {
                prev->mtx.unlock();
            }

            if (current->data == value) {
                if (prev) {
                    prev->next = std::move(current->next);
                } else {
                    head = std::move(current->next);
                }
                current->mtx.unlock();
                return true;
            }

            prev = current;
            current = current->next.get();
        }

        if (prev) {
            prev->mtx.unlock();
        }
        return false;
    }
};

void readInputAndExecute() {
    LinkedList<int> list;
    std::ifstream infile("in.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening in.txt" << std::endl;
        return;
    }

    std::ofstream outfile("out.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error opening out.txt for writing" << std::endl;
        return;
    }

    std::string operation;
    int value;

    while (infile >> operation >> value) {
        if (operation == "insert") {
            list.insert(value);
            outfile << "Inserted " << value << std::endl;
        } else if (operation == "search") {
            if (list.search(value)) {
                outfile << "Found " << value << " in the list" << std::endl;
            } else {
                outfile << value << " not found in the list" << std::endl;
            }
        } else if (operation == "remove") {
            if (list.remove(value)) {
                outfile << "Removed " << value << " from the list" << std::endl;
            } else {
                outfile << "Cannot remove " << value << " because it's not in the list" << std::endl;
            }
        }
    }

    infile.close();
    outfile.close();
}

int main() {
    readInputAndExecute();
    return 0;
}
