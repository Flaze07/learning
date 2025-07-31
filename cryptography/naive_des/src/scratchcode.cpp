#include <bit_array.hpp>
#include <cstdio>
#include <scratchcode.hpp>
#include <string>
#include <des.hpp>
#include <vector>

using namespace std;

void scratchcode() {
  BitArray temp = BitArray::mergeBitArray({
    BitArray::fromNumber(255, 8),
    BitArray::fromNumber(255, 8),
    BitArray::fromNumber(255, 8),
    BitArray::fromNumber(255, 8),
    BitArray::fromNumber(255, 8),
    BitArray::fromNumber(255, 8),
  });

  BitArray result = f(temp, temp);
  printf("%s\n", result.toBinString().c_str());
}
