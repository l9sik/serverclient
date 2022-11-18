//
// Created by admin on 15.11.22.
//

#include "fileHandle.h"

void createFile(std::string path){
    std::ofstream fout(path);
    fout.close();
}

void addToFileImp(std::string path, char* buffer, int size){
    std::ofstream fout(path, std::ios::ate | std::ios::binary);
    if (!fout.is_open()){
        fout.write(buffer, size);
    }
    fout.close();
}

char** getArrayFromFileImp(const std::string& path, int *size, int tsize) {
    *size = (int)(appHelper::getFileSize(path) / sizeof(tsize));
    char** arr;
    arr = new char*[*size];
    for (int i = 0; i < *size; i++){
        arr[i] = new char[tsize];
    }
    std::ifstream fin(path, std::ios::binary);
    if (fin.is_open()){
        for (int i = 0; i < *size; i++){
            if (!fin.eof()){
                fin.read(arr[i], sizeof (tsize));
            }
        }
    }
    fin.close();
    return arr;
}

void addMessageToChatImp(const std::string &path, char* buffer, int size){
    std::ofstream fout(path, std::ios::binary | std::ios::ate);
    if (fout.is_open()) {
        long pos = (long) fout.tellp();
        if (pos == 0) {
            const int zero = 0;
            fout.write((char *) &zero, sizeof(int));
            pos += sizeof(int);
        }
        fout.write(buffer, size);
        fout.write((char *) &pos, sizeof(long));
        fout.close();
        int num = 0;
        std::fstream fin(path, std::ios::binary);
        fin.read((char *) &num, sizeof(int));
        num++;
        fin.write((char *) &num, sizeof(int));
        fin.close();
    }
}

int readIntImp(const std::string &path){
    std::ifstream fin(path, std::ios::binary);
    int num = -1;
    if (fin.is_open()){
        fin.read((char *)&num, sizeof(int));
    }
    fin.close();
    return num;
}

int getNumOfHandledMessagesImp(const std::string &path, int ID){
    std::ifstream fin(path, std::ios::binary);
    int num = -1;
    chatInfo temp = {0, 0};
    if (fin.is_open()){
        while (!fin.eof() && num < 0){
            fin.read((char *)&temp, sizeof(chatInfo));
            if (temp.ID_chat == ID){
                num = temp.lastMsg;
            }
        }
    }
    fin.close();
    return num;
}

fileHandle::fileHandle() {
    fileMutexes = new std::map<std::string, std::mutex*>();
}
fileHandle::~fileHandle() {
    delete fileMutexes;
}

std::mutex* fileHandle::getFileMutex(const std::string& path){
    auto pr = fileMutexes->find(path);
    if (pr == fileMutexes->end()){
        (*(fileMutexes))[path] = new std::mutex();
        pr = fileMutexes->find(path);
    }
    return pr->second;
}

void fileHandle::addToFile(const std::string& path, char* buffer, int size) {
    _lock.lock();
    std::unique_lock<std::mutex> file_locker(*(getFileMutex(path)));
    _lock.unlock();
    addToFileImp(path, buffer, size);
}
char** fileHandle::getArrayFromFile(const std::string& path, int* bufsize, int tsize) {
    _lock.lock();
    std::unique_lock<std::mutex> file_locker(*(getFileMutex(path)));
    _lock.unlock();
    return getArrayFromFileImp(path, bufsize, tsize);
}

void fileHandle::addMessageToChat(const std::string &path, char *buffer, int size) {
    _lock.lock();
    std::unique_lock<std::mutex> file_locker(*(getFileMutex(path)));
    _lock.unlock();
    addMessageToChatImp(path, buffer, size);
}
int fileHandle::readInt(const std::string &path){
    _lock.lock();
    std::unique_lock<std::mutex> file_locker(*(getFileMutex(path)));
    _lock.unlock();
    return readIntImp(path);
}

int fileHandle::getNumOfHandledMessages(const std::string &path, int ID) {
    _lock.lock();
    std::unique_lock<std::mutex> file_locker(*(getFileMutex(path)));
    _lock.unlock();
    return getNumOfHandledMessagesImp(path, ID);
}