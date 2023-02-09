#pragma once

#include <unordered_map>
#include <atomic>

#include "input/input.hpp"
#include "player_params.hpp"

namespace core {
    enum class ThreadsNames : std::uint8_t { kDisplay, kInput };
    class GameSynchronizer {
    public:
        [[noreturn]] void StartGameLoop();
    private:
        std::unordered_map<std::uint8_t, PlayerData> players_;
        input::InputData player_input_;
    };

} // core