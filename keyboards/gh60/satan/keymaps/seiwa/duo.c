#include "duo.h"

void swduo_flush_left(void);
void swduo_flush_right(void);

static inline uint16_t swduo_left_keycode_offset(uint16_t keycode) {
    return keycode - SWDUO_LEFT_LOWER_BOUND;
}

static inline uint16_t swduo_right_keycode_offset(uint16_t keycode) {
    return keycode - SWDUO_RIGHT_LOWER_BOUND;
}

static uint16_t swduo_left_pressed_keys[2];
static uint16_t swduo_right_pressed_keys[2];

void send_key(uint16_t keycode) {
    register_code16(keycode);
    wait_ms(1);
    unregister_code(keycode);
}

bool swduo_process_left(uint16_t keycode, keyrecord_t *record) {
    static uint8_t keys_pressed = 0;
    if (record->event.pressed) {
        // when any left key is pressed, handles right keys.
        swduo_flush_right();
        keys_pressed++;
        if (keys_pressed > 2) {
            return false;
        } else {
            swduo_left_pressed_keys[keys_pressed-1] = keycode;
        }
    } else {
        if (keys_pressed > 0) {
            keys_pressed--;
        }
        if (keys_pressed == 0) {
            swduo_flush_left();
        }
    }
    return false;
}

bool swduo_process_right(uint16_t keycode, keyrecord_t *record) {
    static uint8_t keys_pressed = 0;
    if (record->event.pressed) {
        // when any left key is pressed, handles right keys.
        swduo_flush_left();
        keys_pressed++;
        if (keys_pressed > 2) {
            return false;
        } else {
            swduo_right_pressed_keys[keys_pressed-1] = keycode;
        }
    } else {
        if (keys_pressed > 0) {
            keys_pressed--;
        }
        if (keys_pressed == 0) {
            swduo_flush_right();
        }
    }
    return false;
}

bool swduo_process_others(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SWDUO_SPC:
        if (record->event.pressed) {
            swduo_flush_left();
            swduo_flush_right();
        } else {
            send_key(KC_SPC);
        }
        break;
    }
    return false;
}

void swduo_flush_left() {
    if (swduo_left_pressed_keys[0] > swduo_left_pressed_keys[1] && swduo_left_pressed_keys[1] != 0) {
        // swap
        swduo_left_pressed_keys[0] ^= swduo_left_pressed_keys[1];
        swduo_left_pressed_keys[1] ^= swduo_left_pressed_keys[0];
        swduo_left_pressed_keys[0] ^= swduo_left_pressed_keys[1];
    }
    if (swduo_left_pressed_keys[0] != 0) {
        switch (swduo_left_pressed_keys[0]) {
        case SWDUO_Q:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_H);
                break;
            }
            break;
        case SWDUO_W:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_R);
                break;
            }
            break;
        case SWDUO_E:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_N);
                break;
            case SWDUO_A:
                send_key(KC_V);
                break;
            }
            break;
        case SWDUO_R:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_S);
                break;
            case SWDUO_A:
                send_key(KC_J);
                break;
            }
            break;
        case SWDUO_T:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_C);
                break;
            case SWDUO_A:
                send_key(KC_Z);
                break;
            }
            break;
        case SWDUO_A:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_A);
                break;
            case SWDUO_F:
                send_key(KC_B);
                break;
            case SWDUO_G:
                send_key(KC_K);
                break;
            case SWDUO_C:
                send_key(KC_X);
                break;
            case SWDUO_V:
                send_key(KC_Q);
                break;
            }
            break;
        case SWDUO_S:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_O);
                break;
            case SWDUO_D:
                send_key(KC_W);
                break;
            case SWDUO_C:
                send_key(KC_P);
                break;
            }
            break;
        case SWDUO_D:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_E);
                break;
            case SWDUO_F:
                send_key(KC_Y);
                break;
            case SWDUO_C:
                send_key(KC_G);
                break;
            }
            break;
        case SWDUO_F:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_I);
                break;
            }
            break;
        case SWDUO_G:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_U);
                break;
            }
            break;
        case SWDUO_Z:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_M);
                break;
            case SWDUO_V:
                send_key(KC_SLSH);
                break;
            }
            break;
        case SWDUO_X:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_L);
                break;
            case SWDUO_C:
                send_key(KC_DOT);
                break;
            case SWDUO_V:
                send_key(KC_SCLN);
                break;
            }
            break;
        case SWDUO_C:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_T);
                break;
            case SWDUO_V:
                send_key(KC_COMM);
                break;
            }
            break;
        case SWDUO_V:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_D);
                break;
            }
            break;
        case SWDUO_B:
            switch (swduo_left_pressed_keys[1]) {
            case 0:
                send_key(KC_F);
                break;
            }
            break;
        }
    }
    memset(swduo_left_pressed_keys, 0, sizeof(swduo_left_pressed_keys));
}

void swduo_flush_right() {
    if (swduo_right_pressed_keys[0] > swduo_right_pressed_keys[1] && swduo_right_pressed_keys[1] != 0) {
        // swap
        swduo_right_pressed_keys[0] ^= swduo_right_pressed_keys[1];
        swduo_right_pressed_keys[1] ^= swduo_right_pressed_keys[0];
        swduo_right_pressed_keys[0] ^= swduo_right_pressed_keys[1];
    }
    if (swduo_right_pressed_keys[0] != 0) {
        switch (swduo_right_pressed_keys[0]) {
        case SWDUO_Y:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_C);
                break;
            case SWDUO_SCLN:
                send_key(KC_Z);
                break;
            }
            break;
        case SWDUO_U:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_S);
                break;
            case SWDUO_SCLN:
                send_key(KC_J);
                break;
            }
            break;
        case SWDUO_I:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_N);
                break;
            case SWDUO_SCLN:
                send_key(KC_V);
                break;
            }
            break;
        case SWDUO_O:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_R);
                break;
            }
            break;
        case SWDUO_P:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_H);
                break;
            }
            break;
        case SWDUO_H:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_U);
                break;
            case SWDUO_SCLN:
                send_key(KC_K);
                break;
            }
            break;
        case SWDUO_J:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_I);
                break;
            case SWDUO_K:
                send_key(KC_Y);
                break;
            case SWDUO_SCLN:
                send_key(KC_B);
                break;
            }
            break;
        case SWDUO_K:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_E);
                break;
            case SWDUO_L:
                send_key(KC_W);
                break;
            case SWDUO_M:
                send_key(KC_G);
                break;
            }
            break;
        case SWDUO_L:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_O);
                break;
            case SWDUO_M:
                send_key(KC_P);
                break;
            }
            break;
        case SWDUO_SCLN:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_A);
                break;
            case SWDUO_M:
                send_key(KC_X);
                break;
            case SWDUO_N:
                send_key(KC_Q);
                break;
            }
            break;
        case SWDUO_N:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_F);
                break;
            }
            break;
        case SWDUO_M:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_D);
                break;
            case SWDUO_COMM:
                send_key(KC_COMM);
                break;
            case SWDUO_DOT:
                send_key(KC_SCLN);
                break;
            case SWDUO_SLSH:
                send_key(KC_SLSH);
                break;
            }
            break;
        case SWDUO_COMM:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_T);
                break;
            case SWDUO_DOT:
                send_key(KC_DOT);
                break;
            }
            break;
        case SWDUO_DOT:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_L);
                break;
            }
            break;
        case SWDUO_SLSH:
            switch (swduo_right_pressed_keys[1]) {
            case 0:
                send_key(KC_M);
                break;
            }
            break;
        }
    }
    memset(swduo_right_pressed_keys, 0, sizeof(swduo_right_pressed_keys));
}

#undef LOFFSET
#undef ROFFSET
