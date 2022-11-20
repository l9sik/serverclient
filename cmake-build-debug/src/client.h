//
// Created by Dell on 08.11.2022.
//

#ifndef SERVERCLIENT_CLIENT_H
#define SERVERCLIENT_CLIENT_H

#include <winsock.h>
#include "header.h"

#define STATE int
#define STATE_UNDEFINED 1
#define STATE_ONLINE 2
#define STATE_OFFLINE 4
#define STATE_DISCONNECTED 5

class client{
    std::mutex _lock;
    SOCKET socket;
    int id;
    STATE state;
public:
    client(SOCKET socket, int id, STATE state);
    client(SOCKET socket, int id);
    client(SOCKET socket);
    client();
    void lock();
    void unlock();
    bool try_lock();
    void setID(int id);
    int setID();
    void setState(STATE state);
    void addState(STATE state);
    void removeState(STATE state);
    void setSocket(SOCKET socket);
    SOCKET getSocket();
    int getID();
    STATE getState();
    int toBytes(char*& buff);
    bool isState(STATE state);
    void createSocketFile();
};

#endif //SERVERCLIENT_CLIENT_H
