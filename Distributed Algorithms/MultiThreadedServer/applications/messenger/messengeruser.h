#ifndef PROJECT_BIRD_MESSENGER_USER_H
#define PROJECT_BIRD_MESSENGER_USER_H

#include "../../util/header.h"
#include "../../util/log.h"

class MessengerUser {

private:
    int ID;
    std::string login;
    std::unordered_map<int, std::vector<std::string> > messages;

public:
    MessengerUser() {}

    MessengerUser(int &ID, std::string &login) {
        this->ID = ID;
        this->login = login;
    }

    int& refID() {
        return this->ID;
    }

    std::string& refLogin() {
        return this->login;
    }

    std::vector<std::string> getMessagesFrom(int &ID) {
        return this->messages[ID];
    }

    void insertMessageFrom(int &ID, std::string &message) {
        this->messages[ID].push_back(message);
    }

};

#endif
