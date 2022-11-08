//
// Created by Dell on 08.11.2022.
//

#ifndef CLIENT_THSQUEUE_H
#define CLIENT_THSQUEUE_H

#include <mutex>
#include <queue>

template <class T>
class thsQueue {
    int sz;
    std::mutex _lock;
    std::queue<T> queue;
public:
    void push(T data);
    T front();
    T pop();
    int size();
    bool empty();
};


#endif //CLIENT_THSQUEUE_H
