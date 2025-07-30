#include <bit_array.hpp>
#include <cstdio>
#include <scratchcode.hpp>
#include <string>
#include <des.hpp>
#include <vector>

using namespace std;

void scratchcode() {
  BitArray temp = BitArray::fromNumber(10, 8);
  printf("%lld\n", temp.toNumber());
}
