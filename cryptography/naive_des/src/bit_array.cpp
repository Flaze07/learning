#include <stdlib.h>
#include <bit_array.hpp>

BitArray::BitArray(size_t size) {
  m_size = size;
  m_bits.resize(m_size);

  for (int i = 0; i < m_size; ++i) {
    m_bits[i] = 0;
  }
}

BitArray& BitArray::operator=(const BitArray& other) {
  m_size = other.m_size;

  for (int i = 0; i < m_size; ++i) {
    m_bits[i] = other.m_bits[i];
  }

  return *this;
}

uint32_t& BitArray::operator[](size_t index) {
  return m_bits[index];
}

const uint32_t& BitArray::operator[](size_t index) const {
  return m_bits[index];
}


BitArray BitArray::operator&(const BitArray& other) const {
  BitArray ret{m_size};

  for (int i = 0; i < m_size; ++i) {
    ret.m_bits[i] = m_bits[i] && other[i];
  }

  return ret;
}

BitArray BitArray::operator|(const BitArray& other) const {
  BitArray ret{m_size};

  for (int i = 0; i < m_size; ++i) {
    ret.m_bits[i] = m_bits[i] || other[i];
  }

  return ret;
}

BitArray BitArray::operator^(const BitArray& other) const {
  BitArray ret{m_size};

  for (int i = 0; i < m_size; ++i) {
    if (m_bits[i] == other[i]) {
      ret[i] = 0;
    } else {
      ret[i] = 1;
    }
  }

  return ret;
}

BitArray BitArray::operator<<(size_t amount) const {
  BitArray ret{m_size};
  ret = *this;

  size_t startIdx = amount;
  for (size_t i = startIdx; i < m_size; ++i) {
    ret[i] = m_bits[i - amount];
  }

  return ret;
}

BitArray BitArray::operator>>(size_t amount) const {
  BitArray ret{m_size};
  ret = *this;

  size_t lastIdx = m_size - 1;
  size_t startIdx = lastIdx - amount;

  for (size_t i = startIdx; i >= 0; --i) {
    ret[i] = m_bits[i + amount];
  }

  return ret;
}

BitArray BitArray::rotateLeft(size_t amount) const {
  return *this;
}
BitArray BitArray::rotateRight(size_t amount) const {
  return *this;
}

