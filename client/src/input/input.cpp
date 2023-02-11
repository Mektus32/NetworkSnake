#include "input/input.hpp"

#include <ncurses.h>

namespace input {

    [[noreturn]] void GetPlayerInput(InputData &input_data) {
        core::PlayerDirection direction;

        while (true) {
            auto ch = getch();
            if (ch == KEY_DOWN || ch == KEY_UP || ch == KEY_LEFT || ch == KEY_RIGHT) {
                if (ch == KEY_UP) {
                    direction = core::PlayerDirection::kUp;
                } else if (ch == KEY_DOWN) {
                    direction = core::PlayerDirection::kDown;
                } else if (ch == KEY_RIGHT) {
                    direction = core::PlayerDirection::kRight;
                } else {
                    direction = core::PlayerDirection::kLeft;
                }
                std::lock_guard lock{input_data.read_write_mutex};
                input_data.player_next_direction.emplace(direction);
                input_data.is_exist_new_data_in_input.store(true);
            }
        }
    }

} // input