#ifndef BITOP_H
#define BITOP_H

#include <stdint.h>

int getBit(uint8_t *bits, int idx);
void setBit(uint8_t *bits, int idx);
void clearBit(uint8_t *bits, int idx);

void alterBits(uint8_t *outs, uint8_t *in, int *tables, int size);

void rotl(uint8_t *bits, int size, int count);
void rotr(uint8_t *bits, int size, int count);

void slowRotl(uint8_t *bits, int size, int count, int offsetLeft, int offsetRight);
void slowRotr(uint8_t *bits, int size, int count, int offsetLeft, int offsetRight);

#endif
