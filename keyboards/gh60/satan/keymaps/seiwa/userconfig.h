#pragma once

#include QMK_KEYBOARD_H

#define DEFAULT_LAYER_MAX 0xF

typedef union {
    uint32_t raw;
    struct {
        bool initialized :1;
        bool emacs_mode :1;
        uint8_t default_layer :4;
        uint8_t last_default_layer :4;
    };
} user_config_t;

extern user_config_t user_config;

void save_user_config(void);
void load_user_config(void);
