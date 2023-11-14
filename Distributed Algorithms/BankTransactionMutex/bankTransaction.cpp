#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>

class BankAccount {
private:
    double balance;
    std::mutex accountMutex;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        balance += amount;
    }

    bool withdraw(double amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() {
        std::lock_guard<std::mutex> lock(accountMutex);
        return balance;
    }
};

std::mutex globalMutex;

void globalTransfer(BankAccount& from, BankAccount& to, double amount) {
    std::lock_guard<std::mutex> lock(globalMutex);
    if (from.withdraw(amount)) {
        to.deposit(amount);
    }
}

void objectBasedTransfer(BankAccount& from, BankAccount& to, double amount) {
    std::lock(from.accountMutex, to.accountMutex);
    std::lock_guard<std::mutex> lock1(from.accountMutex, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(to.accountMutex, std::adopt_lock);
    if (from.withdraw(amount)) {
        to.deposit(amount);
    }
}

void readInputAndExecute() {
    std::ifstream infile("in.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening in.txt" << std::endl;
        return;
    }

    double balance1, balance2;
    infile >> balance1 >> balance2;

    BankAccount account1(balance1);
    BankAccount account2(balance2);

    std::string operation;
    double amount;
    while (infile >> operation >> amount) {
        if (operation == "global") {
            globalTransfer(account1, account2, amount);
        } else if (operation == "object") {
            objectBasedTransfer(account1, account2, amount);
        }
    }

    infile.close();

    std::ofstream outfile("out.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error opening out.txt for writing" << std::endl;
        return;
    }
    outfile << "Account1 balance after transactions: " << account1.getBalance() << std::endl;
    outfile << "Account2 balance after transactions: " << account2.getBalance() << std::endl;
    outfile.close();
}

int main() {
    readInputAndExecute();
    return 0;
}
