//
// Created by Dell on 31.10.2022.
//
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "server.h"

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define DEFAULT_CLIENT_NUMBER 30

using namespace std;

int clientHandle(SOCKET listenSocket, sockaddr_in address){
    int max_sd = listenSocket;
    int activity;
    char* message = "Hello, client!";
    char* buffer = new char[1024];
    //initialising client sockets
    SOCKET* clients = new SOCKET[DEFAULT_CLIENT_NUMBER];
    for (int i = 0; i < DEFAULT_CLIENT_NUMBER; i++){
        clients[i] = 0;
    }
    fd_set readfds;
    while(true) {
        FD_ZERO(&readfds);
        FD_SET(listenSocket, &readfds);
        for (int i = 0; i < DEFAULT_CLIENT_NUMBER; i++) {
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

        //acceptin new connection
        if (FD_ISSET(listenSocket, &readfds)) {
            sockaddr_in newAddress;
            int addressLen = sizeof newAddress;
            SOCKET newSocket = accept(listenSocket, (sockaddr *) &newAddress, &addressLen);
            if (newSocket < 0) {
                cout << "New client connection fail" << endl;
                return -1;
            }
            cout << "New Connection, fd: " << newSocket
                 << " ip: " << inet_ntoa(newAddress.sin_addr)
                 << " port: " << address.sin_port << endl;
            if (send(newSocket, message, strlen(message), 0) != strlen(message)) {
                cout << "send error";
            }
            for (int i = 0; i < DEFAULT_CLIENT_NUMBER; i++) {
                if (clients[i] == 0) {
                    clients[i] = newSocket;
                    cout << "adding client to client list" << endl;
                    break;
                }
            }
        }
        for (int i = 0; i < DEFAULT_CLIENT_NUMBER; i++) {
            sockaddr_in clientAddress;
            int addrSize = sizeof clientAddress;
            if (FD_ISSET(clients[i], &readfds) != 0) {
                int valRead;
                if (valRead = recv(clients[i], buffer, 1024, 0) == 0) {
                    cout << "Client disconnected" << endl;
                    getpeername(clients[i], (sockaddr *) &clientAddress, &addrSize);
                    cout << "fd: " << clients[i]
                         << " ip: " << inet_ntoa(clientAddress.sin_addr)
                         << " port: " << clientAddress.sin_port << endl;
                    closesocket(clients[i]);
                    clients[i] = 0;
                } else {
                    buffer[valRead] = '\0';
                    send(clients[i], buffer, strlen(buffer), 0);
                }
            }
        }
    }

}

int createServer(){
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    sockaddr_in address;


    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        cout << "WSAStartup failed with error: " <<  iResult << endl;
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    //getting address
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        cout << "getaddrinfo failed with error: " <<  iResult << endl;
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
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
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
        cout << "listen failed with error: " <<  WSAGetLastError() << endl;
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    iResult = clientHandle(ListenSocket,address);
    if (iResult == -1){
        cout << "handle failed" << endl;
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
}