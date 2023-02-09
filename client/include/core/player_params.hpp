#pragma once

#include <cstdint>
#include <vector>
#include <atomic>
#include <mutex>

namespace core {

    enum class PlayerDirection : std::uint8_t { kTop, kRight, kDown, kLeft };

    struct Position {
        std::uint8_t x{};
        std::uint8_t y{};
    };

    struct PlayerState {
        std::uint8_t size{};
        std::uint8_t max_player_score{};
        PlayerDirection current_direction{};
        std::vector<Position> body;
    };

    struct PlayerData {
        std::atomic<bool> is_player_updating{true};
        PlayerState player_state;
    };

} // core