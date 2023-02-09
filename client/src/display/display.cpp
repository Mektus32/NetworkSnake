#include "display/display.hpp"

#include <iostream>

namespace display {

    [[noreturn]] void DrawPlayers(std::unordered_map<std::uint8_t, core::PlayerData>& players) {
        while (true) {
            for (auto& player : players) {
                if (!player.second.is_player_updating.load()) {
                    std::cout << player.first;
                }
            }
        }
    }

} // display