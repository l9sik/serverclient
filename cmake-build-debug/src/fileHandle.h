//
// Created by admin on 15.11.22.
//

#ifndef SERVERCLIENT_FILEHANDLE_H
#define SERVERCLIENT_FILEHANDLE_H

#include "header.h"

class fileHandle {
    std::mutex* getFileMutex(const std::string& path);
    std::mutex _lock;
    std::map<std::string, std::mutex*>* fileMutexes;
public:
    fileHandle();
    ~fileHandle();
    void addToFile(const std::string&, char* buffer, int size);
    char** getArrayFromFile(const std::string& path, int* bufsize, int tsize);
    void addMessageToChat(const std::string&, char* buffer, int size);
    int readInt(const std::string &path);
    int getNumOfHandledMessages(const std::string &path, int ID-chat);
};

struct clientInfo{
    char name[20];
    char surname[20];
};

struct chatInfo{
    int ID_chat;
    int lastMsg;
};


#endif //SERVERCLIENT_FILEHANDLE_H
