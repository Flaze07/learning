#ifndef DES_H
#define DES_H

#include <stdint.h>

// out is 4 bit, in is 6 bit
void sBoxes(uint8_t out[1], uint8_t in[1], int s[64]);

// in is 56 bits or 7 bytes
void keyRound(uint8_t in[7], int round);
void fFunction(uint8_t out[4], uint8_t in[4], uint8_t key[5]);
void desEncrypt(uint8_t *out, uint8_t *in, uint8_t *key);

#endif
