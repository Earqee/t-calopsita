#include "../util/header.h"
#include "../util/log.h"
#include "../main/server.h"
#include "../applications/serveruser.h"

class ApplicationServer : public Server {

private:

    std::map<std::string, std::string> database;

    void TransmitData2Steps(ServerUser &user, std::string &data) {
        /*Encript*/
        std::string encryptedData = Cripto(data);

        std::string dataSize = std::to_string(encryptedData.size());
        formatDataSizeString(dataSize);
        if(!TransmitData(user.refSocketData(), std::ref(dataSize)))
            user.refStatus() = DISCONNECTED;

        if(!TransmitData(user.refSocketData(), encryptedData))
            user.refStatus() = DISCONNECTED;
    }

    std::string ReceiveData2Steps(ServerUser &user) {

        std::string dataSizeReceived;
        if(!ReceiveData(user.refSocketData(), std::ref(dataSizeReceived), dataSizeStdAmountOfDigits))
            user.refStatus() = DISCONNECTED;

        std::string dataReceived;
        if(!ReceiveData(user.refSocketData(), std::ref(dataReceived), std::atoi(dataSizeReceived.c_str())))
            user.refStatus() = DISCONNECTED;
        /*Decript*/
        std::string decryptedData = Cripto(dataReceived);

        return decryptedData;
    }

protected:

    void HandleUserRequest() {
        Log log("Handling user requests.");

        while(true) {

            std::deque<ServerUser> &userQueue = tracker.refNonAuthenticated();

            while(!userQueue.empty()) {

                ServerUser *user = new ServerUser(userQueue.front());
                std::thread (&ApplicationServer::ThreadHandleUserRequest, this,
                    std::ref(userQueue), user).detach();
                userQueue.pop_front();
            }
        }
    }

    void ThreadHandleUserRequest(std::deque<ServerUser> &userQueue, ServerUser *user) {
        ServerUser &serverUser = *user;

        if(serverUser.refStatus() == CONNECTED) {
            /* Process user location */
            if(serverUser.refLocation() == NOT_AUTH)
                HandleUserAtAuth(serverUser);
            if(serverUser.refLocation() == AT_MENU)
                HandleUserAtMenu(serverUser);
            if(serverUser.refLocation() == AT_ORGANIZER)
                HandleUserAtOrganizer(serverUser);
            if(serverUser.refLocation() == AT_MESSENGER)
                HandleUserAtMessenger(serverUser);

            /* User still connected? */
            if(serverUser.refStatus() == CONNECTED) {
                userQueue.push_back(serverUser);
                return;
            }
        }
        free(user);
    }

    void HandleUserAtAuth(ServerUser &user) {
        Log log("Started authentication.");

        auto CreateUser = [&](ServerUser &user, std::stringstream &stream) {
            Log log("User creation.");

            std::string login, password, message;
            stream >> login >> password;
            if(!database.count(login)) {
                database[login] = password;
                message = "SUCCESS";
                TransmitData2Steps(user, message);
            } else {
                message = "FAILURE";
                TransmitData2Steps(user, message);
            }
        };

        auto LoginUser = [&](ServerUser &user, std::stringstream &stream) {
            Log log("User login.");

            /* Process received data */
            std::string login, password, message;
            stream >> login >> password;
            if(database[login] == password) {
                message = "SUCCESS";
                user.refLogin() = login;
                user.refLocation() = AT_MENU;
                TransmitData2Steps(user, message);
            } else {
                message = "FAILURE";
                TransmitData2Steps(user, message);
            }
        };

        while(true) {

            if(user.refStatus() == DISCONNECTED)
                return;

            /* Receive "HI <login> <password>"  or
             * Receive "CREATE <login> <password>" from client */
            std::string dataReceived = ReceiveData2Steps(user);

            std::string word;
            std::stringstream stream(dataReceived);
            stream >> word;
            if(word == "HI") {
                LoginUser(user, stream);
                return;
            }
            if(word == "CREATE")
                CreateUser(user, stream);
        }
    }

    void HandleUserAtMenu(ServerUser &user) {
        Log log("Handle user at menu.");

        /* Sent menu to client */
        std::string dataSent = user.getMenu();
        TransmitData2Steps(user, dataSent);

        /* Receive client input from menu options*/
        std::string dataReceived = ReceiveData2Steps(user);
        //std::cout << dataReceived << std::endl;

        /* Make changes in user location */
        if(dataReceived == "ORGANIZER")
            user.refLocation() = AT_ORGANIZER;
        if(dataReceived == "MESSENGER")
            user.refLocation() = AT_MESSENGER;
        if(dataReceived == "QUIT")
            user.refLocation() = NOT_AUTH;
    }

    void HandleUserAtOrganizer(ServerUser &user) {
        Log log("Handle user at organizer.");

        while(true) {

            if(user.refStatus() == DISCONNECTED)
                return;

            /* Send organizer menu to client */
            std::string dataSent = user.getOrganizerMenu();
            TransmitData2Steps(user, dataSent);

            /* Receive client input from menu options */
            std::string dataReceived = ReceiveData2Steps(user);

            if(dataReceived == "QUIT") {
                user.refLocation() = AT_MENU;
                return;
            }

            /* Make changes in database */
            std::string requestStatus = user.ProcessOrganizerRequest(dataReceived);
            TransmitData2Steps(user, requestStatus);
        }
    }

    void HandleUserAtMessenger(ServerUser &user) {
        Log log("Handle user at messenger menu.");

        while(true) {

            if(user.refStatus() == DISCONNECTED)
                return;

            /* Send messenger menu to client */
            std::string dataSent = user.getMessengerMenu();
            TransmitData2Steps(user, dataSent);

            /* Receive client input from messenger menu options */
            std::string dataReceived = ReceiveData2Steps(user);

            if(dataReceived == "QUIT") {
                user.refLocation() = AT_MENU;
                return;
            }

            /* Make changes in database */
            std::string requestStatus = user.ProcessMessengerRequest(user.refID(), user.refLogin(), dataReceived);
            TransmitData2Steps(user, requestStatus);
        }
    }

public:

    ApplicationServer(int &port) : Server(port) {
        HandleUserRequest();
    }
};

int main(int argc, char **argv) {
    int port = std::atoi(argv[1]);
    ApplicationServer applicationServer(port);
    return 0;
}
