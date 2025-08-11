#include <bitop.hpp>
#include <des.hpp>

array<bitset<48>, 16> generateSubKeys(bitset<64> keys) {
  array<bitset<48>, 16> result;

  bitset<56> permuted = permute(keys, pc1);

  bitset<28> left = subBits<28>(permuted, 0, 28);
  bitset<28> right = subBits<28>(permuted, 28, 28);

  for (int i = 1; i <= 16; ++i) {

  }
}
