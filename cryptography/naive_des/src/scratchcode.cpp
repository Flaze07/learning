#include <bit_array.hpp>
#include <cstdio>
#include <scratchcode.hpp>
#include <string>
#include <des.hpp>

using namespace std;

void scratchcode() {
  array<size_t, 64> ip_inverse{};
  for (size_t i = 0; i < 64; ++i) {
      ip_inverse[ip[i] - 1] = i + 1;
  }

  BitArray arr = BitArray::fromString("abcdefgh");

  BitArray permuted = permute(arr, ip);

  BitArray reverted = permute(permuted, ip_inverse);

  string s = reverted.toString();

  printf("%s\n", s.c_str());
}
