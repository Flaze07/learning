#include <bitop.h>

int getBit(uint8_t *bits, int idx) {
  int byteIdx = idx / 8;
  int bitIdx = idx % 8;

  uint8_t mask = 0x80 << bitIdx;

  return bits[byteIdx] & mask;
}

void setBit(uint8_t *bits, int idx) {
  int byteIdx = idx / 8;
  int bitIdx = idx % 8;

  uint8_t mask = 0x80 << bitIdx;
  bits[byteIdx] |= mask;
}

void clearBit(uint8_t *bits, int idx) {
  int byteIdx = idx / 8;
  int bitIdx = idx % 8;

  uint8_t mask = 0x80 << bitIdx;
  bits[byteIdx] &= ~mask;
}

