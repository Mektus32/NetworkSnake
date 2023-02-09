cmake_minimum_required(VERSION 3.24)
project(NetworkSnakeServer)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
#        include/
        src/main.cpp)

add_subdirectory(../libraries/network /tmp/network-snake/network-build)
include_directories(../libraries/)

target_link_libraries(${PROJECT_NAME} PUBLIC Network)

target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/libraries/network"
        )