#include <bit_array.hpp>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

BitArray::BitArray(size_t size) {
  m_size = size;
  m_bits.resize(m_size);

  for (int i = 0; i < m_size; ++i) {
    m_bits[i] = 0;
  }
}

BitArray &BitArray::operator=(const BitArray &other) {
  m_size = other.m_size;

  for (int i = 0; i < m_size; ++i) {
    m_bits[i] = other.m_bits[i];
  }

  return *this;
}

uint32_t &BitArray::operator[](size_t index) { return m_bits[index]; }

const uint32_t &BitArray::operator[](size_t index) const {
  return m_bits[index];
}

BitArray BitArray::operator&(const BitArray &other) const {
  BitArray ret{m_size};

  for (int i = 0; i < m_size; ++i) {
    ret.m_bits[i] = m_bits[i] && other[i];
  }

  return ret;
}

BitArray BitArray::operator|(const BitArray &other) const {
  BitArray ret{m_size};

  for (int i = 0; i < m_size; ++i) {
    ret.m_bits[i] = m_bits[i] || other[i];
  }

  return ret;
}

BitArray BitArray::operator^(const BitArray &other) const {
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
  BitArray ret{m_size};
  ret = *this;

  int inverse = ret.m_size - amount;

  ret = (ret << amount) | (ret >> inverse);

  return ret;
}

BitArray BitArray::rotateRight(size_t amount) const {
  BitArray ret{m_size};
  ret = *this;

  int inverse = ret.m_size - amount;

  ret = (ret >> amount) | (ret << inverse);

  return ret;
}

string BitArray::toBinString() {
  string ret = "";
  ret.reserve(m_size * 2);

  int count = 0;
  for (int i = m_size - 1; i >= 0; --i, ++count) {
    if (count > 0 && count % 8 == 0) {
      ret += "\n";
    }

    if (m_bits[i] == 0) {
      ret += "0";
    } else {
      ret += "1";
    }
  }

  return ret;
}

uint64_t BitArray::toUint64() {
  uint32_t ret = 0;

  for (int i = 0; i < m_size; ++i) {
    ret += m_bits[i] * pow(2, i);
  }

  return ret;
}

BitArray BitArray::subArray(size_t startIdx, size_t length) {
  BitArray ret{length};

  int count = 0;
  for (int i = startIdx; i < startIdx + length; ++i, ++count) {
    ret[count] = m_bits[i];
  }

  return ret;
}

BitArray BitArray::fromString(const string &input) {
  BitArray ret{input.size() * 8};

  for (int i = 0; i < input.size(); ++i) {
    char temp = input[i];
    for (int j = 0; j < 8; ++j) {
      ret[(i * 8) + j] = temp % 2;
      temp = temp / 2;
    }
  }

  return ret;
}

BitArray BitArray::mergeBitArray(vector<BitArray> bitArrays) {
  size_t totalSize = 0;
  for (size_t i = 0; i < bitArrays.size(); ++i) {
    totalSize += bitArrays[i].m_size;
  }

  BitArray ret{totalSize};

  size_t idx = 0;
  for (size_t i = 0; i < bitArrays.size(); ++i) {
    for (size_t j = 0; j < bitArrays[i].m_size; ++j) {
      ret[idx++] = bitArrays[i][j];
    }
  }

  return ret;
}
