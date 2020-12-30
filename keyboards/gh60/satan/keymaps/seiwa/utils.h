#pragma once

#include QMK_KEYBOARD_H

void send_key(uint16_t keycode);
void set_default_layer(uint8_t layer);
void push_default_layer(uint8_t layer);
void flip_last_default_layer(void);
