#include "input/input.hpp"

namespace input {

    [[noreturn]] void GetPlayerInput(InputData &input_data) {
        core::PlayerDirection direction;
        while (true) {
            if (getchar() == '\033') { // if the first value is esc
                getchar(); // skip the [
                switch (getchar()) { // the real value
                    case 'A':
                        direction = core::PlayerDirection::kTop;
                        break;
                    case 'B':
                        direction = core::PlayerDirection::kDown;
                        break;
                    case 'C':
                        direction = core::PlayerDirection::kRight;
                        break;
                    case 'D':
                        direction = core::PlayerDirection::kLeft;
                        break;
                }
                std::lock_guard lock{input_data.read_write_mutex};
                input_data.player_next_direction.emplace(direction);
                input_data.is_exist_new_data_in_input.store(true);
            }
        }
    }

} // input