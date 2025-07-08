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
  uint8_t temp[3]; 

  temp[0] = 0b01101110;
  temp[1] = 0b01101100;
  temp[2] = 0b11000000;

  uint8_t out[4];

  tempS(out, temp, 0, s1);
  tempS(out + 1, temp, 6, s2);
  tempS(out + 2, temp, 12, s3);
  tempS(out + 3, temp, 18, s4);
  
  uint8_t finalResult[2];

  printf("%d %d %d %d\n", out[0], out[1], out[2], out[3]);

  finalResult[0] = (uint8_t) out[0] << 4 | out[1];
  finalResult[1] = (uint8_t) out[2] << 4 | out[3];

  printBits(finalResult, 16);
}
