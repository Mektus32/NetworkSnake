#include "core/game_synchronizer.hpp"

#include <thread>
#include <functional>
#include <ncurses.h>

#include "display/display.hpp"

namespace core {

    namespace {

    } // namespace

    GameSynchronizer::GameSynchronizer() {
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();
    }

    GameSynchronizer::~GameSynchronizer() {
        endwin();
    }

    [[noreturn]] void core::GameSynchronizer::StartGameLoop() {
        std::thread input{input::GetPlayerInput, std::ref(player_input_)};
        input.detach();
        std::thread display{display::DrawPlayers, std::ref(players_)};
        display.detach();
        players_[0].is_player_updating = true;
        players_[0].player_state = {0, 0, PlayerDirection::kLeft, {{0, 0}}};
        while (true) {
        }

    }
} // core
