#include QMK_KEYBOARD_H

#define MODS_SHIFT  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _QWVIM      0   // Qwerty Vim
#define _CTQWVIM    1   // Controls
#define _QWEMACS    2   // Qwerty Emacs
#define _CTQWEMACS  3   // Controls
#define _IDLE       4   // Idle layer. Must switch to other layers first
#define _CTIDLE     5   // Controls
#define _DB         6   // Debugging
#define _ZZ         7   // Layer switch

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
[_QWVIM] = LAYOUT_60_ansi(
  KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

/* NOTE: deprecated */
/* [_CTQWVIM] = LAYOUT_60_ansi( */
/*   KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \ */
/*   KC_CAPS, _______, KC_UP  , _______, KC_MRWD, KC_MSTP, KC_MFFD, KC_PSCR, KC_SLCK, KC_PAUS, _______, BL_DEC , BL_INC , BL_TOGG, \ */
/*   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT, KC_INS , KC_HOME, KC_PGUP, _______, _______,          _______, \ */
/*   _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_DEL , KC_END , KC_PGDN, _______,          _______, \ */
/*   _______ , _______, _______, _______,                                                      _______, _______, KC_APP , _______), */

[_CTQWVIM] = LAYOUT_60_ansi(
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, KC_PGUP, KC_UP  , KC_PGDN, KC_MRWD, KC_MSTP, KC_MFFD, KC_PGUP, KC_UP  , KC_PGDN, KC_BSPC, KC_PSCR, KC_SLCK, KC_PAUS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , KC_INS ,          _______, \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_HOME, KC_DEL , KC_END , KC_BSLS,          _______, \
  _______ , _______, _______, _______,                                                      _______, _______, KC_APP , _______),

[_QWEMACS] = LAYOUT_60_ansi(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  SWF    , KC_LGUI, KC_LALT, KC_SPC ,                                                       SWF    , KC_RALT, KC_RGUI, KC_RCTL),

[_CTQWEMACS] = LAYOUT_60_ansi(
  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, KC_PGUP, KC_UP  , KC_PGDN, KC_MRWD, KC_MSTP, KC_MFFD, KC_PGUP, KC_UP  , KC_PGDN, KC_BSPC, KC_PSCR, KC_SLCK, KC_PAUS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , KC_INS ,          _______, \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_HOME, KC_DEL , KC_END , KC_BSLS,          _______, \
  _______ , _______, _______, _______,                                                      _______, _______, KC_APP , _______),

// The layer that does nothing (idle mode)
[_IDLE] = LAYOUT_60_ansi(
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , \
  KC_NO  ,          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , \
  SWF    , KC_NO  , KC_NO  , KC_NO  ,                                                       SWF    , KC_NO  , KC_NO  , KC_NO  ),

[_CTIDLE] = LAYOUT_60_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_ENT , \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

[_DB] = LAYOUT_60_ansi(
  RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),

[_ZZ] = LAYOUT_60_ansi(
  TG(_ZZ), SWDF1  , SWDF2  , SWDF3  , SWDF4  , SWDF5  , SWDF6  , SWDF7  , KC_NO  , KC_NO  , SWDF0  , KC_NO  , KC_NO  , SWLYCLR, \
  KC_NO  , TG(0)  , TG(1)  , TG(2)  , TG(3)  , TG(4)  , TG(5)  , TG(6)  , TG(7)  , TG(8)  , TG(9)  , KC_NO  , KC_NO  , KC_NO  , \
  KC_NO  , TG(10) , TG(11) , TG(12) , TG(13) , TG(14) , TG(15) , TG(16) , TG(17) , TG(18) , TG(19) , TG(30) ,          KC_NO  , \
  KC_NO  ,          TG(20) , TG(21) , TG(22) , TG(23) , TG(24) , TG(25) , TG(26) , TG(27) , TG(28) , TG(29) ,          KC_NO  , \
  SWF    , KC_NO  , KC_NO  , KC_NO  ,                                                       SWF    , KC_NO  , KC_NO  , KC_NO  )
};

const uint8_t swf_layer_map[] = {
  [0]               = _CTQWVIM,  // Not likely to hit
  [1UL << _QWVIM]   = _CTQWVIM,
  [1UL << _QWEMACS] = _CTQWEMACS,
  [1UL << _IDLE]    = _CTIDLE,
};

const uint8_t swdf_default_layer_map[] = {
  [0] = _IDLE,
  [1] = _QWVIM,
  [2] = _QWEMACS,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t swf_pending = 0;
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
      uint8_t ct_layer = swf_layer_map[default_layer_state];
      layer_on(ct_layer);
    } else {
      uint8_t ct_layer = swf_layer_map[default_layer_state];
      layer_off(ct_layer);
    }
    return false;
    // return true;  // Let QMK send the enter press/release events
  case SWLYCLR:
    layer_clear();
    return false;
  case SWDF0 ... SWDF7:
    if (record->event.pressed) {
      set_single_persistent_default_layer(swdf_default_layer_map[keycode - SWDF0]);
    }
    return false;
  case KC_ENT:
    if (record->event.pressed) {
      if (swf_pending == 2) {
        layer_on(_ZZ);
        return false;
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
