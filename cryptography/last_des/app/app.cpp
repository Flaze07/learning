#include <bitset>
#include <cstdio>
#include <bitop.hpp>
using namespace std;

int main() {
  string key = "abcdefgh";
  bitset<64> keyBits{stringToBitset<64>(key)};

  printf("%s\n", keyBits.to_string().c_str());
}
