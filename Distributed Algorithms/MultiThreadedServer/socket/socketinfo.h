#ifndef PROJECT_BIRD_SOCKET_INFO_H
#define PROJECT_BIRD_SOCKET_INFO_H

#include "../util/header.h"
#include "../util/log.h"

class SocketInfo {

private:
    std::string host;
    std::string port;
    addrinfo specification;
    addrinfo *result;
public:
    SocketInfo(std::string host, std::string port) {
        this->host = host;
        this->port = port;
        setSpecification(defaultFamily, defaultSocketType, defaultProtocol);
    }
    ~SocketInfo() {
        freeaddrinfo(result);
    }

    void setSpecification(int ai_family,
            int ai_socktype,
            int ai_protocol) {
        /* Set default values to 0 */
        memset(&specification, 0, sizeof(addrinfo));
        /* Override other fields */
        this->specification.ai_family = ai_family;
        this->specification.ai_socktype = ai_socktype;
        this->specification.ai_protocol = ai_protocol;
    }

    addrinfo& refSpecification() {
        return specification;
    }

    addrinfo*& refResult() {
        return result;
    }
};

#endif
