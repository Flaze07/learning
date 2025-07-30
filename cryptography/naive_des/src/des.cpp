#include <algorithm>
#include <cstddef>
#include <bit_array.hpp>
#include <des.hpp>

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

  size_t index = (row.toUint64() * 16) + col.toUint64();

  BitArray ret = BitArray::fromUint64(s[index]);
  
  return ret;
}
