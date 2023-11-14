#ifndef PROJECT_BIRD_SOCKET_DATA_H
#define PROJECT_BIRD_SOCKET_DATA_H

#include "../util/header.h"

class SocketData {
private:
    int socketFD;
    sockaddr_in6 socketAddress;
    socklen_t socketAddressLen;
public:

    SocketData() {
        socketFD = INVALID;
        socketAddressLen = sizeof(socketAddress);
    }

    SocketData(const SocketData &socketData) {
        this->socketFD = socketData.socketFD;
        this->socketAddress = socketData.socketAddress;
        this->socketAddressLen = socketData.socketAddressLen;
    }

    int& refSocketFD() {
        return socketFD;
    }
    sockaddr_in6& refSocketAddress() {
        return socketAddress;
    }
    socklen_t& refSocketAddressLen() {
        return socketAddressLen;
    }
    sa_family_t& refSocketAddressFamily() {
        return socketAddress.sin6_family;
    }
    in6_addr& refSocketAddressAddr() {
        return socketAddress.sin6_addr;
    }
    uint16_t& refSocketAddressPort() {
        return socketAddress.sin6_port;
    }
    void configSocketAddress(sa_family_t family, in6_addr addr, uint16_t port) {
        refSocketAddressFamily() = family;
        refSocketAddressAddr() = addr;
        refSocketAddressPort() = port;
    }
};

#endif
