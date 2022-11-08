//
// Created by Dell on 08.11.2022.
//

#ifndef SERVERCLIENT_MESSAGE_H
#define SERVERCLIENT_MESSAGE_H

#include <winsock.h>
#include "header.h"


class message {
    SOCKET socket;
    char* buffer;
    int size;
public:
    message(SOCKET socket, char* buffer, int size);
    int getType();
};


#endif //SERVERCLIENT_MESSAGE_H
