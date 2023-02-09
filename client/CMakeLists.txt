cmake_minimum_required(VERSION 3.24)
project(NetworkSnakeClient)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(${PROJECT_NAME}
#        include/
        src/main.cpp src/core/game_synchronizer.cpp include/core/game_synchronizer.hpp include/input/input.hpp include/core/player_params.hpp src/input/input.cpp include/display/display.hpp src/display/display.cpp)

#add_subdirectory(../libraries/network /tmp/network-snake/network-build)
include_directories(../libraries/)

target_link_libraries(${PROJECT_NAME} PUBLIC Network)

target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/libraries/network"
        )