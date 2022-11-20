//
// Created by Dell on 08.11.2022.
//

#ifndef SERVERCLIENT_SERVERMESSAGE_H
#define SERVERCLIENT_SERVERMESSAGE_H

#include "header.h"



class serverMessage {
    client* cl;
    char* buffer;
    int size;
public:
    //to add: check for correct format while creating
    ~serverMessage();

    serverMessage(client *pClient, char *buffer, int size);
    serverMessage(client *pClient);
    static serverMessage* getSendMessages(client *pClient, int* size);
    int getType();
    client* getClient();
    char* getBuffer();
    int getSize();
};


#endif //SERVERCLIENT_SERVERMESSAGE_H
