//
// Created by admin on 14.11.22.
//

#ifndef SERVERCLIENT_APPHELPER_H
#define SERVERCLIENT_APPHELPER_H

#include "header.h"

class appHelper {
public:
    static int charArrToInt(char* arr);
    static void intToCharArr(int num, char* arr);
    static void saveID(std::string directoryPath, int id);
    static bool isID(std::string directoryPath, int id);
    static int* getIntArrayFromFile(std::string path, int* size);
    static long getFileSize(std::string path);
    
};


#endif //SERVERCLIENT_APPHELPER_H
