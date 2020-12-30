#include "utils.h"

void send_key(uint16_t keycode) {
    register_code16(keycode);
    wait_ms(1);
    unregister_code16(keycode);
}
