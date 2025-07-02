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

  printf("%d\n", firstBit);
  printf("%d\n", secondBit);
  printf("%d\n", result);
}
