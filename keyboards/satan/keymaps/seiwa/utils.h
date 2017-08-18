#ifndef SEIWA_UTILS_H
#define SEIWA_UTILS_H

#include<stdint.h>

#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n

static const char LogTable256[256] =
  {
    -1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
    LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
  };

uint32_t one_layer_higher_state(uint32_t state) {
  uint32_t r;
  register uint32_t t, tt; // temporaries
  if (tt = state >> 16)
    {
      r = (t = tt >> 8) ? 24 + LogTable256[t] : 16 + LogTable256[tt];
    }
  else
    {
      r = (t = v >> 8) ? 8 + LogTable256[t] : LogTable256[v];
    }
  return r;
}


#endif  // SEIWA_UTILS_H
