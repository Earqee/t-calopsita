#ifndef PROJECT_BIRD_SERVER_USER_H
#define PROJECT_BIRD_SERVER_USER_H

#include "../util/header.h"
#include "../util/log.h"
#include "../socket/socketdata.h"
#include "../applications/organizer/serverorganizer.h"
#include "../applications/messenger/servermessenger.h"

class ServerUser {

private:
    int ID,
        location = NOT_AUTH,
        status = CONNECTED;
    std::string login = "";
    SocketData socketData;
    ServerOrganizer serverOrganizer;
    ServerMessenger serverMessenger;
public:

    ServerUser(const ServerUser &serverUser) {
        this->ID = serverUser.ID;
        this->location = serverUser.location;
        this->status = serverUser.status;
        this->socketData = serverUser.socketData;
        this->serverOrganizer = serverUser.serverOrganizer;
    }

    ServerUser(int ID, SocketData &socketData) {
        this->ID = ID;
        this->socketData = socketData;
    }

    int getID() {
        return this->ID;
    }

    int& refID() {
        return this->ID;
    }

    std::string& refLogin() {
        return this->login;
    }

    int& refLocation() {
        return this->location;
    }

    int& refStatus() {
        return this->status;
    }

    SocketData& refSocketData() {
        return this->socketData;
    }

    std::string getMenu() {
        return "\nEnter <number> to proceed:\n<1> Organizer\n<2> Messenger\nInput: ";
    }

    std::string getOrganizerMenu() {
        return serverOrganizer.getMenu();
    }

    std::string getMessengerMenu() {
        return serverMessenger.getMenu();
    }

    std::string ProcessOrganizerRequest(std::string &request) {
        return serverOrganizer.ProcessRequest(request);
    }

    std::string ProcessMessengerRequest(int &userId, std::string &userLogin, std::string &request) {
        return serverMessenger.ProcessRequest(userId, userLogin, request);
    }

    bool operator<(const ServerUser &serverUser) const {
        return this->ID < serverUser.ID;
    }
};

#endif
