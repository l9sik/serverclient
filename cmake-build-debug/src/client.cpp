#include "client.h"

client::client(){
    socket = -1;
    id = -1;
    state = STATE_UNDEFINED | STATE_OFFLINE;
}
client::client(SOCKET socket){
    this->socket = socket;
    id = -1;
    state = STATE_ONLINE | STATE_UNDEFINED;
}
client::client(SOCKET socket, int id){
    this->socket = socket;
    this->id = id;
    state = STATE_ONLINE;
}
client::client(SOCKET socket, int id, int state) {
    this->socket = socket;
    this->id = id;
    this->state = state;
    state = STATE_ONLINE;
    if (id < 1)
        state |= STATE_UNDEFINED;
}
int client::setID() {
    std::lock_guard<std::mutex> locker(_lock);
    int tempID = genID(FILE_ID_CLIENT);
    if (tempID > 0)
        state = state & (~(STATE_UNDEFINED));
    return tempID;
}
void client::setID(int id) {
    std::lock_guard<std::mutex> locker(_lock);
    this->id = id;
    if (id > 0)
        state = state & (~(STATE_UNDEFINED));
}
void client::setState(int state) {
    std::lock_guard<std::mutex> locker(_lock);
    this->state = state;
}
void client::setSocket(SOCKET socket) {
    std::lock_guard<std::mutex> locker(_lock);
    this->socket = socket;
    state = state | STATE_ONLINE;
    state = state & (~(STATE_OFFLINE));
}
SOCKET client::getSocket() {
    std::lock_guard<std::mutex> locker(_lock);
    return socket;
}
int client::getID(){
    std::lock_guard<std::mutex> locker(_lock);
    return id;
}
STATE client::getState(){
    std::lock_guard<std::mutex> locker(_lock);
    return state;
}
int client::toBytes(char *&buff) {
    std::lock_guard<std::mutex> locker(_lock);
    int size = sizeof (int);
    buff = new char[size];
    for (int i = 0; i < size; i++){
        buff[i] = ((char*)&id)[i];
    }
    return size;
}
bool client::isState(STATE state) {
    std::lock_guard<std::mutex> locker(_lock);
    return ((this->state & state) != 0);
}

void client::addState(STATE state){
    std::lock_guard<std::mutex> locker(_lock);
    this->state = this->state | state;
}
void client::removeState(STATE state){
    std::lock_guard<std::mutex> locker(_lock);
    this->state = this->state & (~(state));
}
