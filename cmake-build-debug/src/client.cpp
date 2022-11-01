//
// Created by Dell on 01.11.2022.
//

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "27015"

using namespace std;

int createClient(int argc, char **argv) {
    WSADATA wsadata;
    SOCKET connectSocket = INVALID_SOCKET;
    addrinfo *result = NULL, *ptr = NULL, hints;
    const char *msg = "Hello from client!";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        return 1;
    }

    iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (iResult != 0) {
        cout << "WSAStartup failed with error: " << iResult << endl;
        return 1;
    }
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        cout << "GetAddrInfo error with: " << iResult << endl;
        WSACleanup();
        return 1;
    }

    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        connectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (connectSocket == INVALID_SOCKET) {
            cout << "Socket failed with error: " << WSAGetLastError() << endl;
            WSACleanup();
            return 1;
        }

        iResult = connect(connectSocket, ptr->ai_addr, (int) ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(connectSocket);
            connectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (connectSocket == INVALID_SOCKET) {
        cout << "Unable to connect to server" << endl;
        WSACleanup();
        return 1;
    }

    iResult = send(connectSocket, msg, (int) strlen(msg), 0);
    if (iResult == SOCKET_ERROR) {
        cout << "send failed" << endl;
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }

    cout << "sent " << iResult << " bytes" << endl;

    iResult = shutdown(connectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR){
        cout << "shutDown error" << endl;
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }

    do {
        iResult = recv(connectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 ) {
            printf("Bytes received: %d\n", iResult);
        }else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());
    } while( iResult > 0 );

    closesocket(connectSocket);
    WSACleanup();

    return 0;
}
