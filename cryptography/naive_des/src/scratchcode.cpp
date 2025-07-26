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

  printf("Origin: %d\n", (int)'a');
  printf("%*s\n", (int)str.size(), str.c_str());
}
