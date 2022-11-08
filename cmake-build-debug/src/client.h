//
// Created by Dell on 08.11.2022.
//

#ifndef SERVERCLIENT_CLIENT_H
#define SERVERCLIENT_CLIENT_H

#include <winsock.h>
#include "header.h"

#define STATE int
#define STATE_UNDEFINED 0
#define STATE_ONLINE 1
#define STATE_OFFLINE 2
#define STATE_DISCONNECTED 4

class client{
    SOCKET socket;
    int id;
    STATE state;
public:
    client(SOCKET socket, int id, STATE state);
    client(SOCKET socket);
    client();
    void setID(int id);
    int setID();
    void setState(STATE state);
    void setSocket(SOCKET socket);
    SOCKET getSocket();
    int getID();
    STATE getState();
    int toBytes(char* buff);
};

#endif //SERVERCLIENT_CLIENT_H
