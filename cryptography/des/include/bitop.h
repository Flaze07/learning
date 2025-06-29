#ifndef BITOP_H
#define BITOP_H

#include <stdint.h>

int getBit(uint8_t *bits, int idx);
void setBit(uint8_t *bits, int idx);
void clearBit(uint8_t *bits, int idx);

#endif
