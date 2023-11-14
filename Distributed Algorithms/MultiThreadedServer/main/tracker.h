#ifndef PROJECT_BIRD_TRACKER_H
#define PROJECT_BIRD_TRACKER_H

#include "../util/header.h"
#include "../applications/serveruser.h"

class Tracker {

private:
    int nextNonAuthenticatedID = 0,
        nextAtOrganizedID = 0,
        nextAtMessenger = 0;
    std::deque<ServerUser> nonAuthenticated;
    std::deque<ServerUser> atOrganizer;
    std::deque<ServerUser> atMessenger;
public:

    void insertAtNonAuthenticated(SocketData &socketData) {
        nonAuthenticated.push_back(ServerUser(nextNonAuthenticatedID++, socketData));
    }

    void insertAtAtOrganizer(SocketData &socketData) {
        atOrganizer.push_back(ServerUser(nextNonAuthenticatedID++, socketData));
    }

    std::deque<ServerUser>& refNonAuthenticated() {
        return nonAuthenticated;
    }

    std::deque<ServerUser>& refAtOrganizer() {
        return atOrganizer;
    }

    std::deque<ServerUser>& refAtMessenger() {
        return atMessenger;
    }

    int countNonAuthenticated() {
        return nonAuthenticated.size();
    }

    int countAtOrganizer() {
        return atOrganizer.size();
    }

    int countAtMessenger() {
        return atMessenger.size();
    }

};

#endif
