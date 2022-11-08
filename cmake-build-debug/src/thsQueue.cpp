//
// Created by Dell on 08.11.2022.
//

#include "thsQueue.h"

template <class T>
T thsQueue<T>::front() {
    std::lock_guard<std::mutex> locker(_lock);
    return queue.front();
}

template <class T>
void thsQueue<T>::push(T data){
    std::lock_guard<std::mutex> locker(_lock);
    queue.push(data);
}
template <class T>
T thsQueue<T>::pop() {
    std::lock_guard<std::mutex> locker(_lock);
    return queue.pop();
}
template <class T>
int thsQueue<T>::size() {
    std::lock_guard<std::mutex> locker(_lock);
    return queue.size();
}
template <class T>
bool thsQueue<T>::empty() {
    std::lock_guard<std::mutex> locker(_lock);
    return queue.empty();
}