#include <bit_array.hpp>
#include <cstdio>
#include <scratchcode.hpp>
#include <string>
#include <des.hpp>
#include <vector>

using namespace std;

void scratchcode() {
  string temp1 = "abcdefgh";

  string encrypted = des(temp1, temp1);

  printf("%s\n", encrypted.c_str());

  string decrypted = desDecrypt(encrypted, temp1);

  printf("%s\n", decrypted.c_str());

  printf("\n");
}
