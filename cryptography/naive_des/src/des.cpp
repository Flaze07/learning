#include <algorithm>
#include <cstddef>
#include <bit_array.hpp>
#include <des.hpp>

string des(string input, string key) {
  BitArray inputBits = BitArray::fromString(input);
  BitArray keyBits = BitArray::fromString(key);

  BitArray permutedInput = permute(inputBits, ip);
  BitArray permutedKey = permute(keyBits, pc1);

  BitArray operatedInput = permutedInput;
  BitArray operatedKey = permutedKey;
  for (int i = 0; i < 16; ++i) {
    BitArray left = operatedInput.subArray(0, 32);
    BitArray right = operatedInput.subArray(32, 32);


  }
}

BitArray keyRound(BitArray input, int roundNumber) {

  BitArray left = input.subArray(0, 28);
  BitArray right = input.subArray(28, 28);

  if (
    roundNumber == 1 ||
    roundNumber == 2 ||
    roundNumber == 9 ||
    roundNumber == 16
  ) {
    left.rotateLeft(1);
    right.rotateLeft(1);
  } else {
    left.rotateLeft(2);
    right.rotateLeft(2);
  }

  BitArray merged = BitArray::mergeBitArray({ left, right });

  return merged;
}

BitArray sBox(BitArray input, array<size_t, 64> s) {
  BitArray row{2};
  BitArray col{4};

  row[0] = input[0];
  row[1] = input[5];

  col[0] = input[1];
  col[1] = input[2];
  col[2] = input[3];
  col[3] = input[4];

  size_t index = (row.toNumber() * 16) + col.toNumber();

  BitArray ret = BitArray::fromNumber(s[index], 4);

  return ret;
}

BitArray f(BitArray input, BitArray key) {
  BitArray expanded = permute(input, e);

  BitArray xored = expanded ^ key;

  vector<BitArray> converted;

  BitArray temp = xored.subArray(0, 6);
  BitArray sBoxResult = sBox(temp, s1);
  converted.push_back(sBoxResult);

  temp = xored.subArray(6, 6);
  sBoxResult = sBox(temp, s2);
  converted.push_back(sBoxResult);

  temp = xored.subArray(12, 6);
  sBoxResult = sBox(temp, s3);
  converted.push_back(sBoxResult);

  temp = xored.subArray(18, 6);
  sBoxResult = sBox(temp, s4);
  converted.push_back(sBoxResult);
 
  temp = xored.subArray(24, 6);
  sBoxResult = sBox(temp, s5);
  converted.push_back(sBoxResult);

  temp = xored.subArray(30, 6);
  sBoxResult = sBox(temp, s6);
  converted.push_back(sBoxResult);

  temp = xored.subArray(36, 6);
  sBoxResult = sBox(temp, s7);
  converted.push_back(sBoxResult);
 
  temp = xored.subArray(42, 6);
  sBoxResult = sBox(temp, s8);
  converted.push_back(sBoxResult);
 
  return BitArray::mergeBitArray(converted);
}
