#include "dvrkmod.h"
#include "layers.h"
#include "keycodes.h"
#include "utils.h"

bool swdvrkmod_process(uint16_t keycode, keyrecord_t *record) {
    static uint8_t mod_pressed = 0;
    if (record->event.pressed) {
        mod_pressed++;
        if (mod_pressed == 1) {
            layer_on(_DVRKMOD_MOD);
        }
        switch (keycode) {
        case SWDM_LCTL:
            register_code(KC_LCTL);
            break;
        case SWDM_LALT:
            register_code(KC_LALT);
            break;
        case SWDM_LGUI:
            register_code(KC_LGUI);
            break;
        case SWDM_RCTL:
            register_code(KC_RCTL);
            break;
        case SWDM_RALT:
            register_code(KC_RALT);
            break;
        case SWDM_RGUI:
            register_code(KC_RGUI);
            break;
        }
    } else {
        switch (keycode) {
        case SWDM_LCTL:
            unregister_code(KC_LCTL);
            break;
        case SWDM_LALT:
            unregister_code(KC_LALT);
            break;
        case SWDM_LGUI:
            unregister_code(KC_LGUI);
            break;
        case SWDM_RCTL:
            unregister_code(KC_RCTL);
            break;
        case SWDM_RALT:
            unregister_code(KC_RALT);
            break;
        case SWDM_RGUI:
            unregister_code(KC_RGUI);
            break;
        }
        if (mod_pressed == 1) {
            layer_off(_DVRKMOD_MOD);
        }
        mod_pressed--;
    }
    return false;
}
