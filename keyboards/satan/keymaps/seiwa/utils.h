#ifndef SEIWA_UTILS_H
#define SEIWA_UTILS_H

#include<stdint.h>

#define SEIWA_LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n

static const uint8_t LogTable256[256] =
  {
    -1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    SEIWA_LT(4), SEIWA_LT(5), SEIWA_LT(5), SEIWA_LT(6), SEIWA_LT(6), SEIWA_LT(6), SEIWA_LT(6),
    SEIWA_LT(7), SEIWA_LT(7), SEIWA_LT(7), SEIWA_LT(7), SEIWA_LT(7), SEIWA_LT(7), SEIWA_LT(7), SEIWA_LT(7)
  };

uint8_t current_highest_layer_state(uint32_t state) {
  uint8_t r;
  register uint32_t t, tt; // temporaries
  if ((tt = state >> 16))
    {
      r = (t = tt >> 8) ? 24 + LogTable256[t] : 16 + LogTable256[tt];
    }
  else
    {
      r = (t = state >> 8) ? 8 + LogTable256[t] : LogTable256[state];
    }
  return r;
}


#endif  // SEIWA_UTILS_H
