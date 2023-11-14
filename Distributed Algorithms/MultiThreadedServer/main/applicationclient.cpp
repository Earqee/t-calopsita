#include "../util/header.h"
#include "../util/log.h"
#include "../main/client.h"
#include "../applications/clientuser.h"

class ApplicationClient : public Client {

private:

    ClientUser user;

    void TransmitData2Steps(std::string &data) {

        std::string encryptedData = Cripto(data);

        std::string dataSize = std::to_string(encryptedData.size());
        formatDataSizeString(dataSize);

        TransmitData(dataSize);
        TransmitData(encryptedData);
    }

    std::string ReceiveData2Steps() {
        std::string dataSizeReceived;
        ReceiveData(std::ref(dataSizeReceived), dataSizeStdAmountOfDigits);

        std::string dataReceived;
        ReceiveData(std::ref(dataReceived), std::atoi(dataSizeReceived.c_str()));

        std::string decryptedData = Cripto(dataReceived);
        return decryptedData;
    }

protected:

    bool AuthenticateUser() {
        Log log("Authentication began.");

        auto CreateUser = []() {
            Log log("Started creating user.");

            std::string login, password;

            std::cout << "Desired login: ";
            std::cin >> login;
            std::cout << "Desired password: ";
            std::cin >> password;

            return "CREATE " + login + " " + password;
        };

        auto LoginUser = []() {
            Log log("Started user login.");

            std::string login, password;

            std::cout << "Login: ";
            std::cin >> login;
            std::cout << "Password: ";
            std::cin >> password;

            return "HI " + login + " " + password;
        };

        while(true) {

            std::cout <<
            "\nWelcome to Project Bird!\n"
            "Enter <number> to proceed:\n"
            "<1> Login.\n<?> Create account.\n"
            "Input: ";

            std::string input;
            std::cin >> input;
            std::string dataSent;
            if(input == "1") {
                dataSent = LoginUser();
                TransmitData2Steps(dataSent);
                std::string response = ReceiveData2Steps();
                if(response == "SUCCESS")
                    return true;
            }
            else {
                dataSent = CreateUser();
                TransmitData2Steps(dataSent);
                std::string response = ReceiveData2Steps();
                if(response == "SUCCESS")
                    continue;
            }
            return false;
        }
    }

    std::string HandleUserAtMenu() {
        Log log("Handling user at menu.");

        /* Receive menu */
        std::string menuReceived = ReceiveData2Steps();
        std::cout << menuReceived;

        /* Process user input */
        std::string menuRequest = user.HandleMenu();
        //std::cout << menuRequest << std::endl;

        /*Transmit request to server */
        TransmitData2Steps(menuRequest);
        return menuRequest;
    }

    bool HandleUserAtOrganizer() {
        Log log("Handling user at organizer menu.");

        /* Receive organizer menu */
        std::string menuReceived = ReceiveData2Steps();
        std::cout << menuReceived;

        /* Process user input */
        std::string menuRequest = user.HandleOrganizerMenu();

        /*Transmit request to server */
        TransmitData2Steps(menuRequest);
        if(menuRequest == "QUIT")
            return false;

        /* Receive solicitation */
        std::string requestReceived = ReceiveData2Steps();
        std::cout << requestReceived << std::endl;
        return true;
    }

    bool HandleUserAtMessenger() {
        Log log("Handling user at messenger menu.");

        /* Receive messenger menu */
        std::string menuReceived = ReceiveData2Steps();
        std::cout << menuReceived;

        /* Process user input */
        std::string menuRequest = user.HandleMessengerMenu();
        /*Transmit request to server */
        TransmitData2Steps(menuRequest);
        if(menuRequest == "QUIT")
            return false;

        /* Receive solicitation */
        std::string requestReceived = ReceiveData2Steps();
        std::cout << requestReceived << std::endl;
        return true;
    }

public:

    ApplicationClient(char *serverIpv6Address, int &port)
        : Client(serverIpv6Address, port) {

        while(AuthenticateUser()) {

            std::string application = HandleUserAtMenu();

            if(application == "ORGANIZER")
                while(HandleUserAtOrganizer());
            if(application == "MESSENGER")
                while(HandleUserAtMessenger());
        }
    }
};

int main(int argc, char **argv) {
    char *serverIpv6Address = argv[1];
    int port = std::atoi(argv[argc-1]);
    ApplicationClient applicationClient(serverIpv6Address, port);
    free(serverIpv6Address);
    return 0;
}
