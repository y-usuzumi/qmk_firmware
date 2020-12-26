#pragma once

#include QMK_KEYBOARD_H

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
    // Duo left hand
    SWDUO_LEFT_LOWER_BOUND,
    SWDUO_Q,
    SWDUO_W,
    SWDUO_E,
    SWDUO_R,
    SWDUO_T,
    SWDUO_A,
    SWDUO_S,
    SWDUO_D,
    SWDUO_F,
    SWDUO_G,
    SWDUO_Z,
    SWDUO_X,
    SWDUO_C,
    SWDUO_V,
    SWDUO_B,
    SWDUO_LEFT_UPPER_BOUND,
    // Duo right hand
    SWDUO_RIGHT_LOWER_BOUND,
    SWDUO_Y,
    SWDUO_U,
    SWDUO_I,
    SWDUO_O,
    SWDUO_P,
    SWDUO_H,
    SWDUO_J,
    SWDUO_K,
    SWDUO_L,
    SWDUO_SCLN,
    SWDUO_N,
    SWDUO_M,
    SWDUO_COMM,
    SWDUO_DOT,
    SWDUO_SLSH,
    SWDUO_RIGHT_UPPER_BOUND,
    // Duo space
    SWDUO_SPC
};
