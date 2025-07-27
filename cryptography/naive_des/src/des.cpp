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
}
