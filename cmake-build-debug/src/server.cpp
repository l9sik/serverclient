//
// Created by Dell on 31.10.2022.
//
#undef UNICODE
#include "header.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include "atomic"
#include "server.h"
#include "thsQueue.h"
#include "message.h"

#pragma comment (lib, "Ws2_32.lib")

using namespace std;

char *helloMessage = "hello from server!";

SOCKET clientSockets[DEFAULT_CLIENT_NUMBER];

atomic<bool> messageHandleRunning;
void messageHandle(thsQueue<message> &queue){
    int msgType = -1;
    while (msgType != 0) {
        while (queue.empty()){}
        message msg = queue.pop();
        msgType = msg.getType();
        //message handle
    }
    messageHandleRunning = false;
}

int clientHandle(SOCKET listenSocket, sockaddr_in address, int fromIndex) {

    int max_sd = listenSocket;
    int activity;
    char buffer[DEFAULT_BUFLEN];
    fd_set readfds;
    thsQueue<message> queue{};
    thread messageHandleThread = thread(messageHandle, ref(queue));
    messageHandleThread.join();
    SOCKET *clients = &clientSockets[fromIndex];
    while(messageHandleRunning) {
        FD_ZERO(&readfds);
        for (int i = 0; i < DEFAULT_CLIENT_NUMBER_THREAD; i++) {
            int sd = clients[i];
            if (sd > 0) {
                FD_SET(sd, &readfds);
            }
            if (sd > max_sd) max_sd = sd + 1;
        }

        activity = select(max_sd, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            cout << "activity error" << endl;
        }

        for (int i = 0; i < DEFAULT_CLIENT_NUMBER_THREAD; i++) {
            sockaddr_in clientAddress;
            int addrSize = sizeof clientAddress;
            if (FD_ISSET(clients[i], &readfds) != 0) {
                int valRead;
                if ((valRead = recv(clients[i], buffer, DEFAULT_BUFLEN, 0)) == 0) {
                    cout << "Client disconnected" << endl;
                    getpeername(clients[i], (sockaddr *) &clientAddress, &addrSize);
                    cout << "fd: " << clients[i]
                         << " ip: " << inet_ntoa(clientAddress.sin_addr)
                         << " port: " << clientAddress.sin_port << endl;
                    closesocket(clients[i]);
                    clients[i] = 0;
                } else {
                    message msg(clients[i], buffer, valRead);
                    queue.push(msg);
                }
            }
        }
    }
}

int masterSocketHandle(SOCKET listenSocket, sockaddr_in address) {
    char *buffer = new char[1024];
    //initialising client sockets
    for (int i = 0; i < DEFAULT_CLIENT_NUMBER; i++) {
        clientSockets[i] = 0;
    }


    int clientThreadsCount = DEFAULT_CLIENT_HANDLE_THREAD_COUNT(DEFAULT_CLIENT_NUMBER, DEFAULT_CLIENT_NUMBER_THREAD);
    thread *clientHandleThreads[clientThreadsCount];

    /*int fromIndex = 0;
    for (int i = 0; i < clientThreadsCount; i++)
    {
        thread temp(clientHandle, listenSocket, address, fromIndex);
        clientHandleThreads[i] = &temp;
        fromIndex = i * DEFAULT_CLIENT_NUMBER_THREAD;
    }*/

    while (messageHandleRunning) {
        sockaddr_in newAddress;
        int addressLen = sizeof newAddress;
        SOCKET newSocket = accept(listenSocket, (sockaddr *) &newAddress, &addressLen);
        if (newSocket == -1) {
            cout << "New client connection fail" << endl;
            return -1;
        }
        cout << "New Connection, fd: " << newSocket
             << " ip: " << inet_ntoa(newAddress.sin_addr)
             << " port: " << address.sin_port << endl;
        if (send(newSocket, helloMessage, strlen(helloMessage), 0) != strlen(helloMessage)) {
            cout << "send error";
        }
        for (int i = 0; i < DEFAULT_CLIENT_NUMBER; i++) {
            if (clientSockets[i] == 0) {
                clientSockets[i] = newSocket;
                cout << "adding client to client list, index: " << i << endl;
                break;
            }
        }
    }
}

int server::startServer() {
    WSADATA wsaData;
    int iResult;
    messageHandleRunning = true;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    sockaddr_in address;


    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        cout << "WSAStartup failed with error: " << iResult << endl;
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    //getting address
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        cout << "getaddrinfo failed with error: " << iResult << endl;
        WSACleanup();
        return 1;
    }

    //listen socket
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        cout << "socket failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(stoi(DEFAULT_PORT));

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int) result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        cout << "bind failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        cout << "listen failed with error: " << WSAGetLastError() << endl;
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    iResult = masterSocketHandle(ListenSocket, address);
    if (iResult == -1) {
        cout << "handle failed" << endl;
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    return 0;
}