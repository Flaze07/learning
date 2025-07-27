#ifndef BIT_ARRAY_HPP
#define BIT_ARRAY_HPP

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

class BitArray {
public:
  BitArray(size_t size);
  BitArray &operator=(const BitArray &other);

  uint32_t &operator[](size_t index);
  const uint32_t &operator[](size_t index) const;

  BitArray operator&(const BitArray &other) const;
  BitArray operator|(const BitArray &other) const;
  BitArray operator^(const BitArray &other) const;

  BitArray operator<<(size_t amount) const;
  BitArray operator>>(size_t amount) const;
  BitArray rotateLeft(size_t amount) const;
  BitArray rotateRight(size_t amount) const;

  BitArray subArray(size_t startIdx, size_t length);

  string toBinString();
  uint64_t toUint64();
  string toString();
public:
  const size_t& size();
public:
  static BitArray fromString(const string &input);
  static BitArray fromUint64(const uint64_t &input);
  static BitArray mergeBitArray(vector<BitArray> bitArrays);
private:
  size_t m_size;
  std::vector<uint32_t> m_bits;
};

#endif
