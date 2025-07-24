#ifndef BIT_ARRAY_HPP
#define BIT_ARRAY_HPP

#include <stddef.h>
#include <stdint.h>
#include <vector>

class BitArray {
  BitArray(size_t size);
  BitArray& operator=(const BitArray& other);

  uint32_t& operator[](size_t index);
  const uint32_t& operator[](size_t index) const;


  BitArray operator&(const BitArray& other) const;
  BitArray operator|(const BitArray& other) const;
  BitArray operator^(const BitArray& other) const;

  BitArray operator<<(size_t amount) const;
  BitArray operator>>(size_t amount) const;
  BitArray rotateLeft(size_t amount) const;
  BitArray rotateRight(size_t amount) const;
private:
  size_t m_size;
  std::vector<uint32_t> m_bits;
};

#endif
