#pragma once

#include <queue>
#include <cstdint>
#include <memory>
#include <iostream>
#include <atomic>

#include "core/player_params.hpp"

namespace input {

    struct InputData {
        std::mutex read_write_mutex;
        std::atomic<bool> is_exist_new_data_in_input;
        std::queue<core::PlayerDirection> player_next_direction;
    };

    [[noreturn]] void GetPlayerInput(InputData& input_data);

} // input