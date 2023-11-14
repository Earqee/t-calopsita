#ifndef PROJECT_BIRD_SERVER_SOCKET_H
#define PROJECT_BIRD_SERVER_SOCKET_H

#include "../util/header.h"
#include "../util/log.h"
#include "../socket/socket.h"

class ServerSocket : public Socket {

private:

    bool CreateSocketAddress(int port) {
        Log log("Creating of socket address.");

        if(socketData.refSocketFD() == INVALID) {
            printf("Invalid socketFd.\n");
            return false;
        }

        /* Created socket connects to 'any incoming address' */
        socketData.configSocketAddress
            (AF_INET6, in6addr_any, htons(port));

        int bindStatus = bind(socketData.refSocketFD(),
                (sockaddr*) &socketData.refSocketAddress(), socketData.refSocketAddressLen());

        if(bindStatus == INVALID) {
            log.logCannot();
            if(errno == EBADF)
                log.logError("The socket argument is not a valid file descriptor.");
            if(errno == ENOTSOCK)
                log.logError("The descriptor socket is not a socket.");
            if(errno == EADDRNOTAVAIL)
                log.logError("The specified address is not available on this machine.");
            if(errno == EADDRINUSE)
                log.logError("Some other socket is already using the specified address.");
            if(errno == EINVAL)
                log.logError("The socket socket already has an address.");
            if(errno == EACCES)
                log.logError("You do not have permission to access the requested address.");
            return false;
        }
        return true;
    }

public:

    ServerSocket(int port) : Socket(port) {
        CreateSocket();
        CreateSocketAddress(port);
    }

};

#endif
