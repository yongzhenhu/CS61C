#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    unsigned tep = *reg;
    
    unsigned x = *reg;
    unsigned y = *reg;
    unsigned z = *reg;
    unsigned w = *reg;

    y = y >> 2;
    z = z >> 3;
    w = w >> 5;
    *reg = *reg >> 1;

    x = x & 1U; 
    y = y & 1U;
    z = z & 1U;
    w = w & 1U;

    x = x ^ y ^ z ^ w;
    x = x << 15;
    *reg = *reg ^ x;
    
}


