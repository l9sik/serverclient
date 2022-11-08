cmake_minimum_required(VERSION 3.23)
project(serverclient)

set(CMAKE_CXX_STANDARD 14)

add_executable(serverclient cmake-build-debug/src/main.cpp cmake-build-debug/src/header.h cmake-build-debug/src/server.cpp cmake-build-debug/src/server.h cmake-build-debug/src/client.cpp cmake-build-debug/src/message.cpp cmake-build-debug/src/message.h cmake-build-debug/src/thsQueue.cpp cmake-build-debug/src/thsQueue.h cmake-build-debug/src/client.h)
