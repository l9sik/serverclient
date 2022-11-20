//
// Created by admin on 19.11.22.
//

#ifndef SERVERCLIENT_MSGCONVERTER_H
#define SERVERCLIENT_MSGCONVERTER_H

#include "header.h"


class MsgConverter {
    char* msg;
    int msgSize;
    char* buff;
    int buffSize;
    void textMessage();
    void sendTextMessage(int chaID);
public:
    MsgConverter(char* msg, int size);
    ~MsgConverter();
    char* getBuff();
    int getSize();

    void toFile();
    void toSend(int chatID);
};


#endif //SERVERCLIENT_MSGCONVERTER_H
