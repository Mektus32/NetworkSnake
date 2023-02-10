#include <core/game_synchronizer.hpp>

#include <stdlib.h>
#include <unistd.h>

#include <ncurses.h>

int main() {
    core::GameSynchronizer game_synchronizer;
    game_synchronizer.StartGameLoop();
    return 0;
}
