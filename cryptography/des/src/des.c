#include <bitop.h>
#include <des.h>
#include <string.h>

void sBoxes(uint8_t out[1], uint8_t *in, int begin, int s[64]) {
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

  out[0] = s[index];
}

void encryptKeyRound(uint8_t in[7], int round) {
  if (
    round == 1 ||
    round == 2 ||
    round == 9 ||
    round == 19
  ) {
    slowRotl(in, 56, 1, 0, 28);
    slowRotl(in, 56, 1, 28, 0);
  } else {
    slowRotl(in, 56, 2, 0, 28);
    slowRotl(in, 56, 2, 28, 0);
  }
}

void decryptKeyRound(uint8_t *in, int round) {
  if (round == 1) {
    return;
  }

  if (
    round == 2 ||
    round == 9 ||
    round == 16
  ) {
    slowRotr(in, 56, 1, 0, 28);
    slowRotr(in, 56, 1, 28, 0);
  } else {
    slowRotr(in, 56, 2, 0, 28);
    slowRotr(in, 56, 2, 0, 0);
  }
}

void fFunction(uint8_t out[4], uint8_t in[4], uint8_t key[6]) {
  uint8_t expanded[6];

  alterBits(expanded, in, e, 48);

  for (int i = 0; i < 6; ++i) {
    expanded[i] ^= key[i];
  }

  uint8_t sBoxed[8];

  sBoxes(&sBoxed[0], expanded, 0, s1);
  sBoxes(&sBoxed[1], expanded, 6, s2);
  sBoxes(&sBoxed[2], expanded, 12, s3);
  sBoxes(&sBoxed[3], expanded, 18, s4);
  sBoxes(&sBoxed[4], expanded, 24, s5);
  sBoxes(&sBoxed[5], expanded, 30, s6);
  sBoxes(&sBoxed[6], expanded, 36, s7);
  sBoxes(&sBoxed[7], expanded, 42, s8);

  uint8_t combined[4];

  for (int i = 0; i < 4; ++i) {
    combined[i] = (uint8_t) sBoxed[i * 2] << 4 | sBoxed[(i * 2) + 1];
  }

  alterBits(out, combined, p, 32);
}

// in: 64 bits, key: 64 bits
void desEncrypt(uint8_t out[8], uint8_t in[8], uint8_t key[8]) {
  uint8_t permutedPlaintext[8];
  uint8_t alteredKey[7];

  alterBits(permutedPlaintext, in, ip, 64);
  alterBits(alteredKey, key, pc1, 56);

  for (int i = 0; i < 16; ++i) {
    int round = i + 1;

    uint8_t left[4];
    uint8_t right[4];

    memcpy(left, permutedPlaintext, 4);
    memcpy(right, permutedPlaintext + 4, 4);

    encryptKeyRound(alteredKey, round);

    uint8_t roundKey[6];

    alterBits(roundKey, alteredKey, pc2, 48);

    uint8_t modifiedValue[4];
    fFunction(modifiedValue, right, roundKey);

    for (int i = 0; i < 4; ++i) {
      modifiedValue[i] ^= left[i];
    }

    memcpy(permutedPlaintext, right, 4);
    memcpy(permutedPlaintext + 4, modifiedValue, 4);
  }

  uint8_t reversed[8];
  memcpy(reversed, permutedPlaintext + 4, 4);
  memcpy(reversed + 4, permutedPlaintext, 4);

  alterBits(out, reversed, fp, 64);
}

void desDecrypt(uint8_t out[8], uint8_t in[8], uint8_t key[8]) {
  uint8_t permutedPlaintext[8];
  uint8_t alteredKey[7];

  alterBits(permutedPlaintext, in, ip, 64);
  alterBits(alteredKey, key, pc1, 56);

  for (int i = 15; i >= 0; i--) {
    int round = i + 1;

    uint8_t left[4];
    uint8_t right[4];

    memcpy(left, permutedPlaintext, 4);
    memcpy(right, permutedPlaintext + 4, 4);

    decryptKeyRound(alteredKey, round);

    uint8_t roundKey[6];

    alterBits(roundKey, alteredKey, pc2, 48);

    uint8_t modifiedValue[4];
    fFunction(modifiedValue, right, roundKey);

    for (int i = 0; i < 4; ++i) {
      modifiedValue[i] ^= left[i];
    }
    
    memcpy(permutedPlaintext, right, 4);
    memcpy(permutedPlaintext + 4, modifiedValue, 4);
  }

  uint8_t reversed[8];
  memcpy(reversed, permutedPlaintext + 4, 4);
  memcpy(reversed + 4, permutedPlaintext, 4);

  alterBits(out, reversed, fp, 64);
}
