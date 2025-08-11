#include <bitset>
#include <cstdio>
#include <bitop.hpp>
using namespace std;

int main() {
  string result = charToBinary('A');

  bitset<8> temp{result};

  for (int i = 0; i < 8; ++i) {
    printf("%d\n", temp.test(i));
  }
}
