#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

bool swduo_process_left(uint16_t keycode, keyrecord_t *record);
bool swduo_process_right(uint16_t keycode, keyrecord_t *record);
bool swduo_process_others(uint16_t keycode, keyrecord_t *record);
