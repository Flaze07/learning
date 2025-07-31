#include <bit_array.hpp>
#include <cmath>
#include <cstdint>
#include <string>
#include <vector>
#include <cstdio>

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

  size_t startIdx = 0;
  for (size_t i = startIdx; i + amount < m_size; ++i) {
    ret[i] = m_bits[i + amount];
  }

  for (size_t i = m_size - amount; i < m_size; ++i) {
    ret[i] = 0;
  }

  return ret;
}

BitArray BitArray::operator>>(size_t amount) const {
  BitArray ret{m_size};
  ret = *this;

  int stopIdx = amount;

  for (int i = m_size - 1; i >= amount; --i) {
    ret[i] = m_bits[i - amount];
  }

  for (int i = amount - 1; i >= 0; --i) {
    ret[i] = 0;

    if (i == 0) {
      break;
    }
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

  for (int i = 0; i < m_size; ++i) {
    if (i > 0 && i % 8 == 0) {
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
    ret += m_bits[i] * pow(2, 63 - i);
  }

  return ret;
}

size_t BitArray::toNumber() {
  size_t ret = 0;
  for (int i = 0; i < m_size; ++i) {
    ret += m_bits[i] * pow(2, m_size - 1 - i);
  }

  return ret;
}

string BitArray::toString() {
  string ret = "";

  int charHolder = 0;
  int count = 0;
  for (int i = 0; i < m_size; ++i) {
    charHolder += pow(2, 7 - count) * m_bits[i];

    count += 1;
    if (count == 8) {
      char c = static_cast<char>(charHolder);
      ret += c;

      count = 0;
      charHolder = 0;
    }
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

const size_t& BitArray::size() {
  return m_size;
}

BitArray BitArray::fromString(const string &input) {
  vector<BitArray> bits;

  for (size_t i = 0; i < input.size(); ++i) {
    BitArray temp = BitArray::fromNumber((uint8_t) input[i], 8);
    bits.push_back(temp);
  }

  BitArray ret = BitArray::mergeBitArray(bits);

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

BitArray BitArray::fromNumber(size_t number, size_t bitCount) {
  BitArray ret{bitCount};

  vector<size_t>  bits;
  bits.reserve(bitCount);

  while(number > 0) {
    size_t remainder = number % 2;
    number = number / 2;

    bits.push_back(remainder);
  }

  int count = 1;
  for (size_t i = bitCount - bits.size(); i < ret.m_size; ++i) {
    ret[i] = bits[bits.size() - count];
    count += 1;
  }

  return ret;
}
