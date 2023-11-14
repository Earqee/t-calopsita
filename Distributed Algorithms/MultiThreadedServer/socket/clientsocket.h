#ifndef PROJECT_BIRD_CLIENT_SOCKET_H
#define PROJECT_BIRD_CLIENT_SOCKET_H

#include "../util/header.h"
#include "../util/log.h"
#include "../socket/socket.h"

class ClientSocket : public Socket {

private:

    bool CreateSocketAddress(char *serverIpv6Address, int &port) {
        Log log("Creating of socket address.");

        if(socketData.refSocketFD() == INVALID) {
            printf("Invalid socketFD.\n");
            return false;
        }

        in6_addr ipv6ServerAddress;

        int conversionStatus = inet_pton(AF_INET6, serverIpv6Address, &ipv6ServerAddress);

        if(conversionStatus == INVALID) {
            log.logCannot();
            if(errno == EAFNOSUPPORT)
                log.logError("Valid network address not provided.");
            return false;
        }

        socketData.configSocketAddress(AF_INET6, ipv6ServerAddress, htons(port));
        return true;
    }

public:

    ClientSocket(char *serverIpv6Address, int &port) : Socket(port) {
        CreateSocket();
        CreateSocketAddress(serverIpv6Address, port);
    }
};

#endif
