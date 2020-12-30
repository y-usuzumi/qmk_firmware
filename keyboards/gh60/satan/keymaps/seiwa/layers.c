#include "layers.h"

const uint8_t sw_default_layer_map[] = {
    [0] = _IDLE,
    [1] = _QWTY,
    [2] = _DVRK,
    [3] = _DVRKMOD,
    [4] = _DUO
};

const uint8_t sw_ctl_map[] = {
    [0]   = _CTL_IDLE,
    [1]   = _CTL,
    [2]   = _CTL,
    [3]   = _CTL,
    [4]   = _CTL,
};

const uint8_t sw_ctl2_map[] = {
    [0]   = _CTL2,
    [1]   = _CTL2,
    [2]   = _CTL2,
    [3]   = _CTL2,
    [4]   = _CTL2,
};

const uint8_t sw_nump_map[] = {
    [0]   = _NUMP,  // Not likely to hit
    [1]   = _NUMP,
    [2]   = _NUMP,
    [3]   = _NUMP,
    [4]   = _NUMP,
};
