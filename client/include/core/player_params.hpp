#pragma once

#include <cstdint>
#include <deque>
#include <atomic>
#include <mutex>

namespace core {

    enum class PlayerDirection : std::uint8_t { kUp, kRight, kDown, kLeft };

    struct Position {
        std::uint8_t x{};
        std::uint8_t y{};
    };

    struct PlayerState {
        std::uint8_t current_score{};
        std::uint8_t max_player_score{};
        PlayerDirection current_direction{};
        std::deque<Position> body;
    };

    struct PlayerData {
        std::uint8_t player_id{};
        std::atomic<bool> is_player_updating{true};
        PlayerState player_state;
    };

} // core