//
// Created by admin on 14.11.22.
//

#include "appHelper.h"

int appHelper::charArrToInt(char* arr){
    int num = 0;
    num = (num | (int)arr[0]);
    num = num << 8;
    num = (num | (int)arr[1]);
    num = num << 8;
    num = (num | (int)arr[2]);
    num = num << 8;
    num = (num | (int)arr[3]);
    return num;
}

void appHelper::intToCharArr(int num, char* arr){
    arr[0] = (char)((num >> 24) & 0xFF);
    arr[1] = (char)((num >> 16) & 0xFF);
    arr[2] = (char)((num >> 8) & 0xFF);
    arr[3] = (char)(num & 0xFF);
}

void appHelper::saveID(std::string directoryPath, int id) {
    std::string hash = std::to_string(id);
    std::ofstream fout(directoryPath + "\\" + hash + ".dat");
    fout.close();
}

bool appHelper::isID(std::string directoryPath, int id) {
    bool result = true;
    std::string hash = std::to_string(id);
    std::ifstream fout(directoryPath + "\\" + hash + ".dat", std::ios::binary);
    if (!fout.is_open()) {
        result = false;
    }
    fout.close();
    return result;
}
int* appHelper::getIntArrayFromFile(std::string path, int *size) {
    *size = (getFileSize(path) / sizeof(int));
    int* arr;
    arr = new int[*size];
    std::ifstream fin(path, std::ios::binary);
    if (fin.is_open()){
        for (int i = 0; i < *size; i++){
            if (!fin.eof()){
                fin.read((char*)(&arr[i]), sizeof (int));
            }
        }
    }
    fin.close();
}
long appHelper::getFileSize(std::string path) {
    std::ifstream fin(path, std::ios::binary | std::ios::ate);
    long pos = fin.tellg();
    fin.close();
    return pos;
}