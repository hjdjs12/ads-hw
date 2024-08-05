cmake_minimum_required(VERSION 3.24)
project(rbtree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(rbtree
        main.cpp
        rbtree.cpp
        rbtree.h)
