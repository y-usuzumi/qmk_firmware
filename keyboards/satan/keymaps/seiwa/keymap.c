#include "satan.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BS 0   // Base layer
#define _CT 1   // Control layer
#define _ZZ 31  // The layer that governs them all

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BS] = KEYMAP_ANSI(
  KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, \
  TO(_CT), KC_LGUI, KC_LALT, KC_SPC ,                                                       TO(_CT), KC_RALT, KC_RGUI, KC_RCTL),

[_CT] = KEYMAP_ANSI(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , \
  KC_CAPS, _______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC , BL_INC , BL_TOGG, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_INS , KC_HOME, KC_PGUP, _______, _______,          TO(_ZZ), \
  _______,          KC_VOLD, KC_MUTE, KC_VOLU, BL_DEC , BL_TOGG, BL_INC , KC_DEL , KC_END , KC_PGDN, _______,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, KC_APP , _______),

[_ZZ] = KEYMAP_ANSI(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, TO(0)  , TO(1)  , TO(2)  , TO(3)  , TO(4)  , TO(5)  , TO(6)  , TO(7)  , TO(8)  , TO(9)  , _______, _______, _______, \
  _______, TO(10) , TO(11) , TO(12) , TO(13) , TO(14) , TO(15) , TO(16) , TO(17) , TO(18) , TO(19) , TO(30) ,          _______, \
  _______,          TO(20) , TO(21) , TO(22) , TO(23) , TO(24) , TO(25) , TO(26) , TO(27) , TO(28) , TO(29) ,          _______, \
  _______, _______, _______, _______,                                                       _______, _______, _______, _______),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
