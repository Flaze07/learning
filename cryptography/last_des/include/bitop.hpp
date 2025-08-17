#ifndef BITOP_HPP
#define BITOP_HPP

#include <string>
#include <bitset>
using namespace std;

template <size_t N>
bitset<N> rotL(bitset<N> bits, size_t amount);

template <size_t N>
bitset<N> rotR(bitset<N> bits, size_t amount);

string charToBinary(char c);

template <size_t N>
bitset<N> stringToBitset(string str);

template <size_t N, size_t M>
bitset<N> subBits(bitset<M> source, int start, int length); 

/**
 * template implementations
 */

template <size_t N>
bitset<N> rotL(bitset<N> bits, size_t amount) {
  return bits << amount | bits >> (N - amount);
}

template <size_t N>
bitset<N> rotR(bitset<N> bits, size_t amount) {
  return bits >> amount | bits << (N - amount);
}

template <size_t N>
bitset<N> stringToBitset(string str) {
  string binary = "";

  for(const auto& c : str) {
    binary += charToBinary(c);
  }

  return bitset<N>{binary};
}

template <size_t N, size_t M>
bitset<N> subBits(bitset<M> source, int start, int length) {
  bitset<N> result;

  int endIdx = start + length;

  int resultIdx = 0;
  for (int i = start; i < endIdx; ++i) {
    result[resultIdx++] = source[i];
  }

  return result;
}

template <size_t N>
bitset<N * 2> merge(const bitset<N>& left, const bitset<N>& right) {
    bitset<N * 2> result;

    // Place left half in upper N bits
    for (size_t i = 0; i < N; i++) {
        result[i + N] = left[i];
    }

    // Place right half in lower N bits
    for (size_t i = 0; i < N; i++) {
        result[i] = right[i];
    }

    return result;
}


#endif
