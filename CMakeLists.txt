cmake_minimum_required(VERSION 3.23)
project(serverclient)

set(CMAKE_CXX_STANDARD 14)

add_executable(serverclient cmake-build-debug/src/main.cpp cmake-build-debug/src/header.h cmake-build-debug/src/server.cpp cmake-build-debug/src/server.h cmake-build-debug/src/client.cpp cmake-build-debug/src/serverMessage.cpp cmake-build-debug/src/serverMessage.h cmake-build-debug/src/thsQueue.cpp cmake-build-debug/src/thsQueue.h cmake-build-debug/src/client.h cmake-build-debug/src/genID.cpp cmake-build-debug/src/msgHandle.cpp cmake-build-debug/src/msgHandle.h cmake-build-debug/src/msgGen.cpp cmake-build-debug/src/msgGen.h cmake-build-debug/src/appHelper.cpp cmake-build-debug/src/appHelper.h)
