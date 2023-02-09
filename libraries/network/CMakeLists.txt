cmake_minimum_required(VERSION 3.24)
project(Network)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} STATIC
        include/foo.hpp
        src/main.cpp)




