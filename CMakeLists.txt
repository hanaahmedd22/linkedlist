cmake_minimum_required(VERSION 3.29)
project(linkedlist)

set(CMAKE_CXX_STANDARD 20)

add_executable(linkedlist main.cpp
        Node.h
        linkedList.h)
