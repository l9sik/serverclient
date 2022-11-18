//
// Created by Dell on 08.11.2022.
//

#ifndef SERVERCLIENT_SERVERMESSAGE_H
#define SERVERCLIENT_SERVERMESSAGE_H

#include <winsock.h>
#include "header.h"


class serverMessage {
    client* cl;
    char* buffer;
    int size;
public:
    //to add: check for correct format while creating
    serverMessage(client* cl, char* buffer, int size);
    ~serverMessage();
    int getType();
    client* getClient();
    char* getBuffer();

    serverMessage(client *pClient, char *string, int i);
};


#endif //SERVERCLIENT_SERVERMESSAGE_H
