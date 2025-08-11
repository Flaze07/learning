#include <algorithm>
#include <bitop.hpp>

string charToBinary(char c) {
  string result = "";

  int temp = static_cast<int>(c);

  while(temp > 0) {
    int remainder = temp % 2;
    temp = temp / 2;

    result.push_back(remainder == 0 ? '0' : '1');
  }

  for (int i = result.size(); i < 8; ++i) {
    result.push_back('0');
  }

  reverse(result.begin(), result.end());

  return result;
}
