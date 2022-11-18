//
// Created by admin on 14.11.22.
//

#include "msgGen.h"

char* msgGen::genIdentify(int id, bool isClient, int *size){
    *size = SIZE_IDENTIFY;
    char* buffer = new char[*size];
    buffer[0] = TYPE_IDENTIFY;
    appHelper::intToCharArr(id, &buffer[1]);
    buffer[*size - 1] = (char)isClient;
    return buffer;
}