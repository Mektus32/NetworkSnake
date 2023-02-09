#include "core/game_synchronizer.hpp"

#include <thread>
#include <functional>

#include "display/display.hpp"

namespace core {

    [[noreturn]] void core::GameSynchronizer::StartGameLoop() {
        std::thread input{input::GetPlayerInput, std::ref(player_input_)};
        input.detach();
        std::thread display{display::DrawPlayers, std::ref(players_)};
        display.detach();
//        std::pair<std::uint8_t, PlayerData> a{0, PlayerData{false, {0, 0, PlayerDirection::kLeft, {{0, 0}}}}}
//        players_.insert();
        while (true) {

        }

    }
} // core
