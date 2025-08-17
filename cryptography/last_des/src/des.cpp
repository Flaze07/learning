#include <bitop.hpp>
#include <des.hpp>
#include <bitset>

array<bitset<48>, 16> generateSubKeys(bitset<64> keys) {
  array<bitset<48>, 16> result;

  bitset<56> permuted = permute(keys, pc1);

  bitset<28> left = subBits<28>(permuted, 28, 28);
  bitset<28> right = subBits<28>(permuted, 0, 28);

  for (int i = 1; i <= 16; ++i) {
    if (i == 1 ||
        i == 2 ||
        i == 9 ||
        i == 16) 
    {
      left = rotL(left, 1);
      right = rotL(left, 1);
    } else {
      left = rotL(left, 2);
      right = rotL(right, 2);
    }

    bitset<56> merged = merge<28>(left, right);

    bitset<48> key = permute(merged, pc2);
    result[i - 1] = key;
  }

  return result;
}
