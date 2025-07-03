#include <scratchcode.h>
#include <bitio.h>
#include <stdint.h>
#include <bitop.h>
#include <stdio.h>
#include <string.h>

void scratchcode() {
  uint8_t test = 0b100101;
  int firstBit = getBit(&test, 2);
  int secondBit = getBit(&test, 7);

  uint8_t result = firstBit << 1 | secondBit;
  uint8_t result2 = (test << 3) >> 4;
  uint8_t result3 = test << 3;
  result3 = result3 >> 4;

  printf("result2: %d\n", result2);
  printf("result3: %d\n", result3);
}
