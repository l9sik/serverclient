//
// Created by Dell on 08.11.2022.
//

#include "message.h"

message::message(SOCKET socket, char *buffer, int size) {
    this->socket = socket;
    this->buffer = new char[DEFAULT_BUFLEN];
    for (int i = 0; i < size; i++){
        this->buffer[i] = buffer[i];
    }
    this->size = size;
}

int message::getType() {
    return (int)(this->buffer[0]);
}
