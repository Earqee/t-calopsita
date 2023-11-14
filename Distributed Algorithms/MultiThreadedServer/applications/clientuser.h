#ifndef PROJECT_BIRD_CLIENT_USER_H
#define PROJECT_BIRD_CLIENT_USER_H

#include "../util/header.h"
#include "../util/log.h"
#include "../applications/organizer/clientorganizer.h"
#include "../applications/messenger/clientmessenger.h"

class ClientUser {
private:

    ClientOrganizer clientOrganizer;
    ClientMessenger clientMessenger;
public:

    ClientUser() {}

    std::string HandleMenu() {
        std::string input;
        std::cin >> input;
        if(input == "1") return "ORGANIZER";
        if(input == "2") return "MESSENGER";
        return "QUIT";
    }

    std::string HandleOrganizerMenu() {
        return clientOrganizer.HandleMenu();
    }

    std::string HandleMessengerMenu() {
        return clientMessenger.HandleMenu();
    }
};

#endif
