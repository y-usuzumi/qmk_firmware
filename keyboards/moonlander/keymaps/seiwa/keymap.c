#include QMK_KEYBOARD_H
#include "version.h"
#include "keycodes.h"
#include "layout.c"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SW_ESC:
        process_grave_esc(KC_GESC, record);
        return false;
    case SW_SESC:
        uint8_t mods = get_mods();
        if (record->event.pressed) {
            if (mods & MOD_MASK_SHIFT) {
                register_code(KC_ESC);
            } else {
                register_code(KC_GRV);
            }
        } else {
            if (mods & MOD_MASK_SHIFT) {
                unregister_code(KC_ESC);
            } else {
                unregister_code(KC_GRV);
            }
        }
        return false;
    default:
        return true;
    }
}
