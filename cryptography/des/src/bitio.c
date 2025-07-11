#include <bitio.h>
#include <bitop.h>
#include <math.h>
#include <stdio.h>

void printBits(uint8_t *bits, int size) {
  for (int i = 0; i < size; ++i) {
    int bit = getBit(bits, i);

    printf("%d ", bit);

    if (i % 8 == 0 && i > 0) {
      printf("\n");
    }
  }

  printf("\n");
}

void indexedPrintBits(uint8_t *bits, int size) {
  int digitCount = trunc(log10(size)) + 1;

  for (int i = 0; i < size; ++i) {
    int bit = getBit(bits, i);

    int currDigitCount = trunc(log10(i)) + 1;

    if (i == 0) {
      currDigitCount = 1;
    }

    int offset = digitCount - currDigitCount;

    printf("%*si:%d  ", offset, "", bit);

    if (i % 8 == 0 && i > 0) {
      printf("\n");
    }
  }

  printf("\n");
}
