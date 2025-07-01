#include <scratchcode.h>
#include <bitio.h>
#include <stdint.h>
#include <bitop.h>
#include <stdio.h>

void scratchcode() {
  uint8_t num = 32;

  for (int i = 0; i < 8; ++i) {
    num = 32;
    printf("%d:", i);
    slowRotr(&num, 8, i, 2, 3);

    printBits(&num, 8); 
  }
}
