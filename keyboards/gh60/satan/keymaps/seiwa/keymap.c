#include QMK_KEYBOARD_H

#define GRAVE_ESC_ENABLE 1

#define MODS_SHIFT  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define DEFAULT_LAYER_IS(a) (default_layer_state == 1UL << a)

// NOTE: All these consts must be continuous numbers or it will BRICK the keyboard
#define _QWTY          0   // Qwerty Vim
#define _CTL_QWTY      1   // Controls
#define _NUMP_QWTY     2   // Numpad
#define _DVRK          3   // Dvorak Emacs
#define _CTL_DVRK      4   // Controls
#define _NUMP_DVRK     5   // Numpad
#define _IDLE          6   // Idle layer. Must switch to other layers first
#define _CTL_IDLE      7   // Controls
#define _ZZ            8   // Layer switch

// Custom keycodes

enum my_keycodes {
    SWF                = SAFE_RANGE,  // Seiwa Fn key
    SW_ENT,  // Seiwa Enter key
    SW_NUMP,  // temporarily switch to the numpad layer of the base layer
    SW_LYCLR,  // clear all layers
    SW_ESC,  // Seiwa Esc key. Vim mode = KC_GESC, Emacs mode = KC_GRV
    SW_SESC,  // Seiwa SWF+Esc key. Vim mode = KC_GRV, Emacs mode = KC_ESC
    SW_TGEMACS,  // Toggle between Emacs mode and Vim mode
    SW_SAVE,  // Save user config
    SW_DF0,
    SW_DF1,
    SW_DF2,
    SW_DF3,
    SW_DF4,
    SW_DF5,
    SW_DF6,
    SW_DF7,
};

typedef union {
    uint32_t raw;
    struct {
        bool initialized :1;
        bool emacs_mode :1;
        uint8_t default_layer :4;
    };
} user_config_t;

user_config_t user_config;

const uint8_t sw_default_layer_map[] = {
    [0] = _IDLE,
    [1] = _QWTY,
    [2] = _DVRK
};

const uint8_t sw_f_map[] = {
    [0]              = _CTL_QWTY,  // Not likely to hit
    [1UL << _QWTY]   = _CTL_QWTY,
    [1UL << _DVRK]   = _CTL_DVRK,
    [1UL << _IDLE]   = _CTL_IDLE,
};

const uint8_t sw_nump_map[] = {
    [0]              = _NUMP_QWTY,  // Not likely to hit
    [1UL << _QWTY]   = _NUMP_QWTY,
    [1UL << _DVRK]   = _NUMP_DVRK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Qwerty
[_QWTY] = LAYOUT_60_ansi(
  SW_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

[_CTL_QWTY] = LAYOUT_60_ansi(
  SW_SESC, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, KC_PGUP, KC_UP  , KC_PGDN, KC_MRWD, KC_MSTP, KC_MFFD, KC_PGUP, KC_UP  , KC_PGDN, KC_BSPC, KC_PSCR, KC_SLCK, KC_PAUS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , KC_INS ,          SW_ENT , \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_HOME, KC_DEL , KC_END , KC_BSLS,          _______, \
  _______, _______, _______, SW_NUMP,                                                       _______, _______, KC_APP , _______),

[_NUMP_QWTY] = LAYOUT_60_ansi(
  SW_ENT , _______, _______, _______, _______, _______, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , _______, _______, _______, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_BSPC, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______,          SW_ENT , \
  _______,          _______, _______, _______, _______, _______, KC_PPLS, KC_P0  , KC_DEL , KC_PDOT, KC_PSLS,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

// Dvorak
[_DVRK] = LAYOUT_60_ansi(
  SW_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LBRC, KC_RBRC, KC_BSPC, \
  KC_TAB , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH, KC_EQL , KC_BSLS, \
  KC_LCTL, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,          KC_ENT , \
  KC_LSFT,          KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B    , KC_M   , KC_W   , KC_V   , KC_Z  ,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

[_CTL_DVRK] = LAYOUT_60_ansi(
  SW_SESC, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, KC_PGUP, KC_UP  , KC_PGDN, KC_MRWD, KC_MSTP, KC_MFFD, KC_PGUP, KC_UP  , KC_PGDN, KC_BSPC, KC_PSCR, KC_SLCK, KC_PAUS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , KC_INS ,          SW_ENT , \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_HOME, KC_DEL , KC_END , KC_BSLS,          _______, \
  _______, _______, _______, SW_NUMP,                                                       _______, _______, KC_APP , _______),

[_NUMP_DVRK] = LAYOUT_60_ansi(
  SW_ENT , _______, _______, _______, _______, _______, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , _______, _______, _______, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_BSPC, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______,          SW_ENT , \
  _______,          _______, _______, _______, _______, _______, KC_PPLS, KC_P0  , KC_DEL , KC_PDOT, KC_PSLS,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

// The layer that does nothing (idle mode)
[_IDLE] = LAYOUT_60_ansi(
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , \
  KC_NO  ,          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , \
  SWF    , KC_NO  , KC_NO  , KC_NO  ,                                                       SWF    , KC_NO  , KC_NO  , KC_NO  ),

[_CTL_IDLE] = LAYOUT_60_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          SW_ENT , \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

[_ZZ] = LAYOUT_60_ansi(
  TG(_ZZ), SW_DF1 , SW_DF2 , SW_DF3 , SW_DF4 , SW_DF5 , SW_DF6 , SW_DF7 , KC_NO  , KC_NO  , SW_DF0 , KC_NO  , KC_NO  , RESET, \
  KC_NO  , SW_TGEMACS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , _______, SW_SAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_NO  , \
  KC_NO  ,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_NO  , \
  SWF    , KC_NO  , KC_NO  , SW_LYCLR,                                                      SWF    , KC_NO  , KC_NO  , KC_NO  )
};

void save_user_config(void) {
    eeconfig_update_user(user_config.raw);
}

void load_user_config(void) {
    // Read user config from EEPROM
    user_config.raw = eeconfig_read_user();
    if (!user_config.initialized) {
        user_config.initialized = true;
        user_config.emacs_mode = 0;
        user_config.default_layer = 1;
        save_user_config();
    }
    default_layer_set(1UL << user_config.default_layer);
}

void keyboard_post_init_user(void) {
    load_user_config();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // How many SWF keys are pressed down simultaneously
    static uint8_t swf_pending = 0;
    // Is the SW_NUMP key pressed down
    static uint8_t sw_nump_toggle = 0;
    switch (keycode) {
    case SWF:
        if (record->event.pressed) {
            swf_pending += 1;
        } else {
            swf_pending -= 1;
            if (swf_pending < 0) {
                // Safeguard
                swf_pending = 0;
            }
        }
        if (swf_pending) {
            // Any number of SWF keys pressed, toggle on CTL layer.
            uint8_t ct_layer = sw_f_map[default_layer_state];
            layer_on(ct_layer);
        } else {
            // On release, toggle off CTL layer.
            uint8_t ct_layer = sw_f_map[default_layer_state];
            layer_off(ct_layer);
        }
        return false;
        // return true;  // Let QMK send the enter press/release events
    case SW_NUMP:
        // When SW_NUMP is pressed, we are in "Temporary Numpad" mode.
        // If then the user presses the SW_ENT without releasing SW_NUMP,
        // `sw_nump_toggle` will be enabled (see the SW_ENT case branch),
        // meaning we are in the "Permanent Numpad" mode. In this case,
        // releasing SW_NUMP should not toggle off the Numpad layer.
        if (sw_nump_toggle) {
            return false;
        }
        uint8_t nump_layer = sw_nump_map[default_layer_state];
        if (record->event.pressed) {
            layer_on(nump_layer);
        } else {
            layer_off(nump_layer);
        }
        return false;
    case SW_LYCLR:
        layer_clear();
        return false;
    case SW_ESC: {
        if (user_config.emacs_mode) {
            if (record->event.pressed) {
                register_code(KC_GRV);
            } else {
                unregister_code(KC_GRV);
            }
        } else {
            // WARNING!!! EXTREMELY HACKY WAY TO WORKAROUND THE ISSUE
            // WHERE register_code does not handle KC_GESC correctly!
            process_grave_esc(KC_GESC, record);
        }
        return false;
    }
    case SW_SESC: {
        uint16_t esc_keycode = user_config.emacs_mode ? KC_ESC : KC_GRV;
        if (record->event.pressed) {
            register_code(esc_keycode);
        } else {
            unregister_code(esc_keycode);
        }
        return false;
    }
    case SW_TGEMACS:
        if (record->event.pressed) {
            user_config.emacs_mode = !user_config.emacs_mode;
        }
        return false;
    case SW_SAVE:
        if (record->event.pressed) {
            save_user_config();
        }
        return false;
    case SW_DF0 ... SW_DF7:
        if (record->event.pressed) {
            uint8_t layer_index = sw_default_layer_map[keycode - SW_DF0];
            user_config.default_layer = layer_index;
            default_layer_set(1UL << layer_index);
        }
        return false;
    case SW_ENT:
        if (record->event.pressed) {
            if (swf_pending == 2) {
                // Two SWF keys pressed + SW_ENT -> ZZ layer
                layer_on(_ZZ);
                return false;
            }
            uint8_t nump_layer = sw_nump_map[default_layer_state];
            if (sw_nump_toggle) {
                // If in Permanent Numpad mode, exit
                sw_nump_toggle = 0;
                layer_off(nump_layer);
                return false;
            }
            if (IS_LAYER_ON(nump_layer)) {
                // If in temporary Numpad mode, enter Permanent Numpad mode
                sw_nump_toggle = 1;
                return false;
            }
            if (DEFAULT_LAYER_IS(_IDLE)) {
                // Do nothing in Idle layer (with one SWF key pressed). The reason this is needed is
                // that we should still allow switching to ZZ layer with both SWF keys pressed.
                return false;
            }
            register_code(KC_ENT);
        } else {
            // Might be possible to call `unregister_code` without any call of `register_code`.
            // Not sure if this is problematic.
            unregister_code(KC_ENT);
        }
        return false;
    case KC_RCTL:
        // Not sure if this is still needed.
        if (swf_pending == 2) {
            layer_clear();
            default_layer_set(1UL << 0);
            return false;
        }
        return true;
    default:
        // Process all other keycodes normally
        return true;
    }
}
