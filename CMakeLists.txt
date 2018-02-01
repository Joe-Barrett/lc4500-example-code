cmake_minimum_required(VERSION 3.6)
project(lc4500_experimental)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        app.cpp
        tcp_client.h
        tcp_client.cpp
        packager.h
        common.h
        error.h
        packager.cpp
        commands.h
        commands.cpp init.cpp)
add_executable(lc4500_driver ${SOURCE_FILES})