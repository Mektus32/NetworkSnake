#pragma once

#include <unordered_map>

#include "core/player_params.hpp"

namespace display {

    [[noreturn]] void DrawPlayers(std::unordered_map<std::uint8_t, core::PlayerData>& players);

} // display