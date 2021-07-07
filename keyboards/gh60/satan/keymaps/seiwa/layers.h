#pragma once

// NOTE: All these consts must be continuous numbers or it will BRICK the keyboard
#define _QWTY          0   // Qwerty
#define _DVRK          1   // Dvorak
#define _DVRKMOD       3   // Dvorak Modified
#define _DVRKMOD_MOD   4   // Dvorak Modified mod layer
#define _DUO           5   // Duo
#define _ARROW         6   // Arrow
#define _GOD           9   // God
#define _IDLE          10  // Idle layer. Must switch to other layers first
#define _CTL_IDLE      11  // Controls for Idle layer. Only ZZ switch is available
#define _CTL           12  // Controls 1
#define _CTL2          13  // Controls 2
#define _NUMP          14  // Numpad
#define _ZZ            15  // Layer switch

const extern uint8_t sw_default_layer_map[];
const extern uint8_t sw_ctl_map[];
const extern uint8_t sw_ctl2_map[];
const extern uint8_t sw_nump_map[];

char* get_layer_name(int number);
