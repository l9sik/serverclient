//
// Created by Dell on 08.11.2022.
//

#ifndef SERVERCLIENT_CLIENT_H
#define SERVERCLIENT_CLIENT_H

#include <winsock.h>
#include "header.h"

#define STATE int
#define STATE_DEFAULT 0
#define STATE_ONLINE 1
#define STATE_OFFLINE 2
#define STATE_DISCONNECTED 3

class client{
    SOCKET socket;
    int id;
    STATE state;

};

#endif //SERVERCLIENT_CLIENT_H
