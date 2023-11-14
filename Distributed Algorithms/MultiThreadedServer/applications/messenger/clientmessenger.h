#ifndef PROJECT_BIRD_CLIENT_MESSENGER_H
#define PROJECT_BIRD_CLIENT_MESSENGER_H

#include "../../util/log.h"

class ClientMessenger {

private:

public:
    ClientMessenger() {}

    std::string HandleMenu() {
        Log log("Handling messenger menu.");

        std::string input;
        std::cin >> input;

        if(input == "1") return enroll();
        if(input == "2") return availableUsers();
        if(input == "3") return privateMessageFrom();
        if(input == "4") return sendPrivateMessage();
        return quit();
    }

    std::string enroll() {
        return "ENROLL";
    }

    std::string availableUsers() {
        return "USERS";
    }

    std::string privateMessageFrom() {
        std::cout << "Enter <id> : ";
        std::string id;
        std::cin >> id;
        return "FROM " + id;
    }

    std::string sendPrivateMessage() {
        std::cout << "Enter <id> <message> : ";
        std::string id, message;
        std::cin >> message;
        getline(std::cin, message);
        return "SEND " + id + " " + message;
    }

    std::string quit() {
        return "QUIT";
    }
};

#endif
