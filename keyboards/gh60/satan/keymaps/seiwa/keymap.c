#include QMK_KEYBOARD_H

#define MODS_SHIFT  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define DEFAULT_LAYER_IS(a) (default_layer_state == 1UL << a)

// NOTE: All these consts must be continuous numbers or it will BRICK the keyboard
#define _QW_VIM          0   // Qwerty Vim
#define _CTL_QW_VIM      1   // Controls
#define _NUMP_QW_VIM     2   // Numpad
#define _QW_EMACS        3   // Qwerty Emacs
#define _CTL_QW_EMACS    4   // Controls
#define _NUMP_QW_EMACS   5   // Numpad
#define _IDLE            6   // Idle layer. Must switch to other layers first
#define _CTL_IDLE        7   // Controls
#define _DB              8   // Debugging
#define _ZZ              9   // Layer switch

// Custom keycodes

enum my_keycodes {
  SWF                = SAFE_RANGE,
  SW_ENT,
  SW_NUMP,
  SW_LYCLR,
  SW_DF0,
  SW_DF1,
  SW_DF2,
  SW_DF3,
  SW_DF4,
  SW_DF5,
  SW_DF6,
  SW_DF7,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW_VIM] = LAYOUT_60_ansi(
  KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

[_CTL_QW_VIM] = LAYOUT_60_ansi(
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, KC_PGUP, KC_UP  , KC_PGDN, KC_MRWD, KC_MSTP, KC_MFFD, KC_PGUP, KC_UP  , KC_PGDN, KC_BSPC, KC_PSCR, KC_SLCK, KC_PAUS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , KC_INS ,          SW_ENT , \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_HOME, KC_DEL , KC_END , KC_BSLS,          _______, \
  _______, _______, _______, SW_NUMP,                                                       _______, _______, KC_APP , _______),

[_NUMP_QW_VIM] = LAYOUT_60_ansi(
  SW_ENT , _______, _______, _______, _______, _______, KC_NLCK, KC_P7  , KC_P8  , KC_P9,   _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4  , KC_P5  , KC_P6,   _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P1  , KC_P2  , KC_P3,   KC_PENT, _______,          SW_ENT , \
  _______,          _______, _______, _______, _______, _______, KC_PPLS, KC_P0  , KC_P0,   KC_PDOT, KC_PSLS,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

[_QW_EMACS] = LAYOUT_60_ansi(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

[_CTL_QW_EMACS] = LAYOUT_60_ansi(
  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, KC_PGUP, KC_UP  , KC_PGDN, KC_MRWD, KC_MSTP, KC_MFFD, KC_PGUP, KC_UP  , KC_PGDN, KC_BSPC, KC_PSCR, KC_SLCK, KC_PAUS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , KC_INS ,          SW_ENT , \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_HOME, KC_DEL , KC_END , KC_BSLS,          _______, \
  _______, _______, _______, SW_NUMP,                                                       _______, _______, KC_APP , _______),

[_NUMP_QW_EMACS] = LAYOUT_60_ansi(
  SW_ENT , _______, _______, _______, _______, _______, KC_NLCK, KC_P7  , KC_P8  , KC_P9,   _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4  , KC_P5  , KC_P6,   _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P1  , KC_P2  , KC_P3,   KC_PENT, _______,          SW_ENT , \
  _______,          _______, _______, _______, _______, _______, KC_PPLS, KC_P0  , KC_P0,   KC_PDOT, KC_PSLS,          _______, \
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

[_DB] = LAYOUT_60_ansi(
  RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

[_ZZ] = LAYOUT_60_ansi(
  TG(_ZZ), SW_DF1 , SW_DF2 , SW_DF3 , SW_DF4 , SW_DF5 , SW_DF6 , SW_DF7 , KC_NO  , KC_NO  , SW_DF0 , KC_NO  , KC_NO  , RESET, \
  KC_NO  , TG(0)  , TG(1)  , TG(2)  , TG(3)  , TG(4)  , TG(5)  , TG(6)  , TG(7)  , TG(8)  , TG(9)  , KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , TG(10) , TG(11) , TG(12) , TG(13) , TG(14) , TG(15) , TG(16) , TG(17) , TG(18) , TG(19) , TG(30) ,          KC_NO  , \
  KC_NO  ,          TG(20) , TG(21) , TG(22) , TG(23) , TG(24) , TG(25) , TG(26) , TG(27) , TG(28) , TG(29) ,          KC_NO  , \
  SWF    , KC_NO  , KC_NO  , SW_LYCLR,                                                      SWF    , KC_NO  , KC_NO  , KC_NO  )
};

const uint8_t sw_default_layer_map[] = {
    [0] = _IDLE,
    [1] = _QW_VIM,
    [2] = _QW_EMACS,
};

const uint8_t sw_f_map[] = {
  [0]                = _CTL_QW_VIM,  // Not likely to hit
  [1UL << _QW_VIM]   = _CTL_QW_VIM,
  [1UL << _QW_EMACS] = _CTL_QW_EMACS,
  [1UL << _IDLE]     = _CTL_IDLE,
};

const uint8_t sw_nump_map[] = {
  [0]                = _NUMP_QW_VIM,
  [1UL << _QW_VIM]   = _NUMP_QW_VIM,
  [1UL << _QW_EMACS] = _CTL_QW_EMACS,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t swf_pending = 0;
  static uint8_t sw_nump_toggle = 0;
  static uint8_t sw_ent_down = 0;
  switch (keycode) {
  case SWF:
    if (record->event.pressed) {
      swf_pending += 1;
    } else {
      swf_pending -= 1;
      if (swf_pending < 0)
        swf_pending = 0;
    }
    if (swf_pending) {
      uint8_t ct_layer = sw_f_map[default_layer_state];
      layer_on(ct_layer);
    } else {
      uint8_t ct_layer = sw_f_map[default_layer_state];
      layer_off(ct_layer);
    }
    return false;
    // return true;  // Let QMK send the enter press/release events
  case SW_NUMP:
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
  case SW_DF0 ... SW_DF7:
    if (record->event.pressed) {
      set_single_persistent_default_layer(sw_default_layer_map[keycode - SW_DF0]);
    }
    return false;
  case SW_ENT:
    if (record->event.pressed) {
      if (swf_pending == 2) {
        layer_on(_ZZ);
        return false;
      }
      uint8_t nump_layer = sw_nump_map[default_layer_state];
      if (sw_nump_toggle) {
          sw_nump_toggle = 0;
          layer_off(nump_layer);
          return false;
      }
      if (IS_LAYER_ON(nump_layer)) {
          sw_nump_toggle = 1;
          return false;
      }
      if (DEFAULT_LAYER_IS(_IDLE)) {
        return false;
      }
      sw_ent_down = 1;
      register_code(KC_ENT);
    } else {
        if (sw_ent_down) {
            sw_ent_down = 0;
            unregister_code(KC_ENT);
        }
    }
    break;
  case KC_RCTL:
    if (swf_pending == 2) {
      layer_clear();
      default_layer_set(1UL << 0);
      return false;
    }
    break;
  }
  return true;
}
