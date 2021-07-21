#include QMK_KEYBOARD_H
#include "version.h"
#include "keycodes.h"
#include "layout.c"


static void process_sw_gesc(keyrecord_t *record, uint16_t without_shift, uint16_t with_shift) {
    uint8_t mods = get_mods();
    if (record->event.pressed) {
        if (mods & MOD_MASK_SHIFT) {
            register_code(with_shift);
        } else {
            register_code(without_shift);
        }
    } else {
        if (mods & MOD_MASK_SHIFT) {
            unregister_code(with_shift);
        } else {
            unregister_code(without_shift);
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SW_ESC:
        process_sw_gesc(record, KC_ESC, KC_GRV);
        return false;
    case SW_GRV:
        process_sw_gesc(record, KC_GRV, KC_ESC);
        return false;
    default:
        return true;
    }
}
