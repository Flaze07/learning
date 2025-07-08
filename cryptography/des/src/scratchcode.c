#include <scratchcode.h>
#include <bitio.h>
#include <stdint.h>
#include <bitop.h>
#include <stdio.h>
#include <string.h>
#include <des.h>

void tempS(uint8_t out[1], uint8_t *in, int begin, int sBox[64]) {
  int firstBit = getBit(in, begin);
  int secondBit = getBit(in, begin + 5);

  int columnFirst = getBit(in, begin + 1);
  int columnSecond = getBit(in, begin + 2);
  int columnThird = getBit(in, begin + 3);
  int columnFourth = getBit(in, begin + 4);

  int rows = firstBit << 1 | secondBit;

  int columns = columnFirst << 3 |
    columnSecond << 2 |
    columnThird << 1 |
    columnFourth;

  int index = (rows * 16) + columns;

  out[0] = sBox[index];
}

void scratchcode() {
  char *c = "abcdefgh";

  char d[8];

  memcpy(d, c + 4, 4);
  memcpy(d + 4, c, 4);

  printf("%.8s\n", d);
}
