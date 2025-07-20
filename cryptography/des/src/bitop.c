#include <bitop.h>

int getBit(uint8_t *bits, int idx) {
  int byteIdx = idx / 8;
  int bitIdx = idx % 8;

  uint8_t mask = 0x80 >> bitIdx;

  return (bits[byteIdx] & mask) ? 1 : 0;
}

int reversedGetBit(uint8_t *bits, int idx) {
  int byteIdx = idx / 8;
  int bitIdx = idx % 8;

  uint8_t mask = 0x1 << bitIdx;

  return (bits[byteIdx] & mask) ? 1 : 0;
}


void setBit(uint8_t *bits, int idx) {
  int byteIdx = idx / 8;
  int bitIdx = idx % 8;

  uint8_t mask = 0x80 >> bitIdx;
  bits[byteIdx] |= mask;
}

void clearBit(uint8_t *bits, int idx) {
  int byteIdx = idx / 8;
  int bitIdx = idx % 8;

  uint8_t mask = 0x80 >> bitIdx;
  bits[byteIdx] &= ~mask;
}

void alterBits(uint8_t *outs, uint8_t *in, int *tables, int size) {
  for (int i = 0; i < size; ++i) {
    int fromIdx = tables[i] - 1;
    int bit = getBit(in, fromIdx);

    if (bit) {
      setBit(outs, i);
    } else {
      clearBit(outs, i);
    }
  }
}

void rotl(uint8_t *bits, int size, int count) {
  int reverse = count - size;

  *bits = (*bits << count) | (*bits >> reverse);
}

void rotr(uint8_t *bits, int size, int count) {
  int reverse = count - size;

  *bits = (*bits >> count) | (*bits << reverse);
}

void slowRotl(uint8_t *bits, int size, int count, int offsetLeft, int offsetRight) {
  int start = offsetLeft;
  int end = size - offsetRight;

  while (count-- > 0) {
    int first = getBit(bits, start);
    for (int i = start; i < end; ++i) {
      int next;
      if (i + 1 < end) {
        next = getBit(bits, i + 1);
      } else {
        next = first;
      }

      if (next) {
        setBit(bits, i);
      } else {
        clearBit(bits, i);
      }
    }
  }
}

void slowRotr(uint8_t *bits, int size, int count, int offsetLeft, int offsetRight) {
  int start = offsetLeft;
  int end = size - offsetRight;

  while (count-- > 0) {
    int last = getBit(bits, end - 1);

    for (int i = end - 1; i >= start; --i) {
      int prev;
      if (i - 1 >= start) {
        prev = getBit(bits, i - 1);
      } else {
        prev = last;
      }

      if (prev) {
        setBit(bits, i);
      } else {
        clearBit(bits, i);
      }
    }
  }
}

