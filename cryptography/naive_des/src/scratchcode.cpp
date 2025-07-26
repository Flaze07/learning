#include <bit_array.hpp>
#include <cstdio>
#include <scratchcode.hpp>
#include <string>

using namespace std;

void scratchcode() {
  BitArray temp = BitArray::fromString("a");
  BitArray temp2 = BitArray::fromString("b");
  BitArray merged = BitArray::mergeBitArray({ temp, temp2 });

  string str = merged.toBinString();

  printf("%*s\n", (int)str.size(), str.c_str());

  BitArray result = merged.rotateLeft(2);

  // string resultStr = result.toBinString();

  // printf("after\n");
  // printf("%*s\n", (int)resultStr.size(), resultStr.c_str());
}
