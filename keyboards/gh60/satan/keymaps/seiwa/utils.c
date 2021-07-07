#include "userconfig.h"
#include "utils.h"
#include "layers.h"

void send_key(uint16_t keycode) {
    register_code16(keycode);
    wait_ms(1);
    unregister_code16(keycode);
}

void set_default_layer(uint8_t layer) {
    user_config.default_layer = layer;
    default_layer_set(1UL << sw_default_layer_map[layer]);
}

void push_default_layer(uint8_t layer) {
    user_config.last_default_layer = user_config.default_layer;
    set_default_layer(layer);
    uprintf("I:LAYER:PUSH:%s:%s\n", get_layer_name(user_config.default_layer), get_layer_name(user_config.last_default_layer));
}

void flip_last_default_layer() {
    if (user_config.last_default_layer == DEFAULT_LAYER_MAX) {
        return;
    }
    uint8_t temp_last_default_layer = user_config.last_default_layer;
    user_config.last_default_layer = user_config.default_layer;
    set_default_layer(temp_last_default_layer);
    uprintf("I:LAYER:FLIP:%s:%s\n", get_layer_name(user_config.default_layer), get_layer_name(user_config.last_default_layer));
}

bool is_capslock_on() {
    return host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK);
}

bool is_numlock_on() {
    return host_keyboard_leds() & (1<<USB_LED_NUM_LOCK);
}
