//
// Created by Dell on 08.11.2022.
//

#include "serverMessage.h"

serverMessage::serverMessage(client* cl, char *buffer, int size) {
    this->cl = cl;
    this->buffer = new char[size];
    for (int i = 0; i < size; i++){
        this->buffer[i] = buffer[i];
    }
    this->size = size;
}
serverMessage::~serverMessage(){
    delete[] buffer;
}

int serverMessage::getType() {
    return (int)(this->buffer[0]);
}

client* serverMessage::getClient(){
    return cl;
}
char* serverMessage::getBuffer(){
    return buffer;
}