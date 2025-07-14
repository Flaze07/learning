#include <scratchcode.h>
#include <bitio.h>
#include <stddef.h>
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
  // uint8_t temp[8] = "abcdefgh";
  // uint8_t key[8] = "12345678";
  //
  // printf("plaintext:\n");
  // printBits(temp, 64);
  // printf("key:\n");
  // printBits(key, 64);
  //
  // printf("plaintext: %.8s\n", temp);
  //
  // uint8_t encrypted[8];
  //
  // printf("encrypting...\n");
  // desEncrypt(encrypted, temp, key);
  //
  // printf("encrypted: %.8s\n", encrypted);
  //
  // uint8_t decrypted[8];
  //
  // printf("decrypting...\n");
  // desDecrypt(decrypted, encrypted, key);
  //
  // printf("decrypted: %.8s\n", decrypted);
}
