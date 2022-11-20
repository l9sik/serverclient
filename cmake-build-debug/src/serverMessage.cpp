//
// Created by Dell on 08.11.2022.
//

#include "serverMessage.h"



serverMessage::serverMessage(client *pClient, char* buffer, int size){
    this->cl = cl;
    this->buffer = new char[size];
    for (int i = 0; i < size; i++) {
        this->buffer[i] = buffer[i];
    }
    this->size = size;
}

serverMessage::~serverMessage(){
    delete[] buffer;
}

serverMessage::serverMessage(client *pClient) {

}

serverMessage* getSendMessages(client *pClient, int* size){
    *size = 0;
    //to release
    int* msgSizes;
    char** fileMsgs = fileHandler->getClientSendMessages(pClient->getID(), msgSizes, size);
    MsgConverter msgconv(fileMsg, size);
    //to release
    msgconv.toSend(fileMsg, size);
    this->size = msgconv.getSize();
    char *convertBuff = msgconv.getBuff();
    for (int i = 0; i < this->size; i++) {
        this->buffer[i] = convertBuff[i];
    }
}

int serverMessage::getType() {
    return (int)buffer[0];
}

client* serverMessage::getClient(){
    return cl;
}
char* serverMessage::getBuffer(){
    return buffer;
}
int serverMessage::getSize(){
    return size;
}