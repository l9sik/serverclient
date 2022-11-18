//
// Created by admin on 14.11.22.
//

#ifndef SERVERCLIENT_MSGHANDLE_H
#define SERVERCLIENT_MSGHANDLE_H

#include "header.h"

#define CLIENT_DIRECTORY "..\\resource\\clients"
#define CHAT_DIRECTORY "..\\resource\\chats"

typedef void (*consumer)(serverMessage msg);
class msgHandle {
    const int numOfFunctions = 20;
    thsQueue<serverMessage>* queue;
    static void identifyClient(serverMessage msg);
    static void textMessage(serverMessage msg);
    constexpr static const consumer commands[numOfFunctions] {
        identifyClient, textMessage, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL};
public:
    msgHandle(thsQueue<serverMessage>* queue);
    void execute(serverMessage msg);
};


#endif //SERVERCLIENT_MSGHANDLE_H
