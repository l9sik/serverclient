//
// Created by Dell on 31.10.2022.
//

#ifndef SERVERCLIENT_HEADER_H
#define SERVERCLIENT_HEADER_H

#define WIN32_LEAN_AND_MEAN

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "27015"
#define DEFAULT_CLIENT_NUMBER_THREAD 30
#define DEFAULT_CLIENT_NUMBER 30
#define DEFAULT_CLIENT_HANDLE_THREAD_COUNT(a, b) ((a) / (b))
#define FILE_ID_CLIENT "..\\resource\\id-client.dat"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <fstream>
#include <thread>
#include "atomic"
#include "server.h"
#include "thsQueue.h"
#include "serverMessage.h"
#include "client.h"
#include "genID.cpp"
#include "msgHandle.h"
#include "msgGen.h"
#include "appHelper.h"

#endif //SERVERCLIENT_HEADER_H
