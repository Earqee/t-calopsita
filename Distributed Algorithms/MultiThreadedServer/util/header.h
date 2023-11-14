#ifndef PROJECT_BIRD_HEADER_H
#define PROJECT_BIRD_HEADER_H

/* External dependences */
#include <bits/stdc++.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

/* Debugging */
#define DEBUG 1

/*Common namespaces */
#define INVALID -1
#define CHAR_SIZE 8

/* Server related */
#define maxNumOfConnections 64
#define dataSizeStdAmountOfDigits 5
#define defaultMaximumDataSize 256

/* ServerUser LOCATION */
#define NOT_AUTH -1
#define AT_MENU 0
#define AT_ORGANIZER 1
#define AT_MESSENGER 2

/* ServerUser STATUS*/
#define CONNECTED 0
#define DISCONNECTED 1

const int defaultFamily = AF_INET6;
const int defaultSocketType = SOCK_STREAM;
const int defaultProtocol = getprotobyname("tcp")->p_proto;

/* Utility functions */

void formatDataSizeString(std::string &data) {
    while(data.size()<dataSizeStdAmountOfDigits)
        data.insert(data.begin(), '0');
}

/* Simple xor encription-decryption */
std::string Cripto(std::string &data) {
    char xorKey = 'X';
    std::string xorData(data);
    if(!DEBUG)
        for(int i=0; i<xorData.size(); i++)
            xorData[i]^=xorKey;
    return xorData;
}

#endif

