//
// Created by admin on 14.11.22.
//

#include "msgHandle.h"


msgHandle::msgHandle(thsQueue<serverMessage>* queue){
    this->queue = queue;
}

void sendIdentify(client* cl, bool state){
    int size;
    char* buffer = msgGen::genIdentify(cl->getID(), state, &size);
    int valResult = send(cl->getSocket(), buffer, size, 0);
    if (valResult < 0) {
        cl->setState(STATE_OFFLINE | STATE_UNDEFINED);
        closesocket(cl->getSocket());
    }
    delete[] buffer;
}

void msgHandle::identifyClient(serverMessage msg){
    client* cl = msg.getClient();
    cl->lock();
    bool isClient = true;
    if (cl->isState(STATE_ONLINE)){
        char* buffer = msg.getBuffer();
        int id = appHelper::charArrToInt(&buffer[1]);
        if (id == -1){
            id = cl->setID();
            appHelper::saveID(CLIENT, id);
            cl->removeState(STATE_UNDEFINED);
        }else{
            if (appHelper::isID(CLIENT_DIRECTORY, id)){
                cl->setID(id);
                cl->createSocketFile();
                cl->removeState(STATE_UNDEFINED);
            }else {
                isClient = false;
            }
        }
        sendIdentify(cl, isClient);
    }
    cl->unlock();
}

void msgHandle::textMessage(serverMessage msg) {
    client* cl = msg.getClient();
    cl->lock();
    if (cl->isState(STATE_ONLINE)) {
        if (cl->isState(STATE_UNDEFINED)) {
            sendIdentify(cl, false);
        } else if (cl->isState(STATE_ONLINE)) {
            char *buffer = msg.getBuffer();
            int fromID = appHelper::charArrToInt(&buffer[1]);
            int chatID = appHelper::charArrToInt(&buffer[1 + (sizeof(int))]);
            if (appHelper::isID(CHAT_DIRECTORY, chatID)) {
                MsgConverter msgconv(buffer, msg.getSize());
                char* fileMsg = msgconv.getBuff();
                int size = msgconv.getSize();
                if (size > 0) {
                    std::string path = CHAT_DIRECTORY;
                    path += "\\" + std::to_string(chatID) + "msgs.dat";
                    fileHandler->addMessageToChat(path, fileMsg, size);
                    sendIdentify(cl, true);
                }
            }
        }
    }
    cl->unlock();
}

void msgHandle::execute(serverMessage msg) {
    int func_num = msg.getType();
    if (func_num < numOfFunctions && func_num > -1 && commands[func_num] != NULL){
            commands[func_num](msg);
    }else
        std::cout << "UNKNOWN MESSAGE_TYPE" << std::endl;
}