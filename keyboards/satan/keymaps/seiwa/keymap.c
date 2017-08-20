#include "satan.h"
#include "utils.h"

#define MODS_SHIFT  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// 0 ~ 7: base layers
// 8 ~ 29: feature layers
// 30: debug
// 31: layer switch center
#define _QWVIM      0   // Qwerty Vim
#define _QWEMACS    1   // Qwerty Emacs
#define _CTQWVIM    8   // Controls
#define _CTQWEMACS  9   // Controls
#define _DB        30   // Debugging
#define _ZZ        31   // Layer switch

#define _______ KC_TRNS

// Custom keycodes

enum my_keycodes {
  SWF                = SAFE_RANGE,
  SWLYCLR,
  SWDF0,
  SWDF1,
  SWDF2,
  SWDF3,
  SWDF4,
  SWDF5,
  SWDF6,
  SWDF7
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWVIM] = KEYMAP_ANSI(
  KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

[_QWEMACS] = KEYMAP_ANSI(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

[_CTQWVIM] = KEYMAP_ANSI(
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, _______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC , BL_INC , BL_TOGG, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_INS , KC_HOME, KC_PGUP, _______, _______,          _______, \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_DEL , KC_END , KC_PGDN, _______,          _______, \
  _______ , _______, _______, _______,                                                      _______, _______, KC_APP , _______),

[_CTQWEMACS] = KEYMAP_ANSI(
  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, _______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC , BL_INC , BL_TOGG, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_INS , KC_HOME, KC_PGUP, _______, _______,          _______, \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_DEL , KC_END , KC_PGDN, _______,          _______, \
  _______ , _______, _______, _______,                                                      _______, _______, KC_APP , _______),

[_DB] = KEYMAP_ANSI(
  RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

[_ZZ] = KEYMAP_ANSI(
  TG(31) , SWDF0  , SWDF1  , SWDF2  , SWDF3  , SWDF4  , SWDF5  , SWDF6  , SWDF7  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , SWLYCLR, \
  KC_NO  , TG(0)  , TG(1)  , TG(2)  , TG(3)  , TG(4)  , TG(5)  , TG(6)  , TG(7)  , TG(8)  , TG(9)  , KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , TG(10) , TG(11) , TG(12) , TG(13) , TG(14) , TG(15) , TG(16) , TG(17) , TG(18) , TG(19) , TG(30) ,          KC_NO  , \
  KC_NO  ,          TG(20) , TG(21) , TG(22) , TG(23) , TG(24) , TG(25) , TG(26) , TG(27) , TG(28) , TG(29) ,          KC_NO  , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                                                       KC_NO  , KC_NO  , KC_NO  , KC_NO  )
};

const uint8_t swf_layer_map[] = {
  [0]               = _CTQWVIM,
  [1UL << _QWVIM]   = _CTQWVIM,
  [1UL << _QWEMACS] = _CTQWEMACS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool swf_pending;
  static uint8_t ct_layer;
  register bool continue_process = false;
  switch (keycode) {
  case SWF:
    if (record->event.pressed) {
      if (swf_pending) {
        layer_off(ct_layer);
        swf_pending = false;
        ct_layer = 0;
        layer_on(_ZZ);
      } else {
        swf_pending = true;
        ct_layer = swf_layer_map[default_layer_state];
        layer_on(ct_layer);
      }
    } else {
      layer_off(ct_layer);
      swf_pending = false;
      ct_layer = 0;
    }
    break;
    // return true;  // Let QMK send the enter press/release events
  case SWLYCLR:
    layer_clear();
    break;
  case SWDF0 ... SWDF7:
    set_single_persistent_default_layer(keycode - SWDF0);
    break;
  default:
    continue_process = true;
    break;
  }
  return continue_process;
}
