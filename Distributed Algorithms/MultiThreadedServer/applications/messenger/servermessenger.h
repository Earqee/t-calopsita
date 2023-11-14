
#ifndef PROJECT_BIRD_SERVER_MESSENGER_H
#define PROJECT_BIRD_SERVER_MESSENGER_H

#include "../../applications/messenger/messengeruser.h"

class ServerMessenger {

private:
    std::map<int, MessengerUser> userList;

public:
    ServerMessenger() {}

    std::string getMenu() {
        return "\nEnter <number>:\n<1> Listen messages.\n<2> List available users.\n<3> List messages from specific user.\n<4> Send message to specific user.\n";
    }

    std::string ProcessRequest(int &userID, std::string &userLogin, std::string &request) {

        std::string word;
        std::stringstream stream(request);
        stream >> word;

        if(word == "ENROLL") {
            userList[userID] = MessengerUser(userID, userLogin);
            return "Success enrolling.";
        }

        if(word == "USERS") {
            std::string response;
            for(auto element : userList) {
                MessengerUser &user = element.second;
                response.append("| User login <"+ user.refLogin()+"> id <"+std::to_string(user.refID())+"> available.");
            }
            return response;
        }

        if(word == "FROM") {
            int destID;
            stream >> destID;
            if(userList.count(userID)) {
                 std::vector<std::string>
                    messages = userList[userID].getMessagesFrom(destID);
                 std::string response;
                 for(std::string message : messages)
                     response.append("| User login <"+userList[destID].refLogin()+"> id <" +
                            std::to_string(destID) +"> sent :"
                            + message+"\n");
                 return response;
            }
        }

        if(word == "SEND") {
            int destID;
            std::string message;
            stream >> destID;
            getline(stream, message);
            if(userList.count(userID)) {
                userList[userID].insertMessageFrom(destID, message);
                return "Success sending.";
            }
        }

        return "Error. Have you entered a valid input?";
    }

};


#endif

