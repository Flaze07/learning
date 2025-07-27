#include <bit_array.hpp>
#include <cstdio>
#include <scratchcode.hpp>
#include <string>
#include <des.hpp>

using namespace std;

void scratchcode() {
  BitArray temp{6};
  temp[0] = 1;
  temp[1] = 0;
  temp[2] = 0;
  temp[3] = 1;
  temp[4] = 0;
  temp[5] = 1;

  BitArray row{2};
  row[0] = temp[0];
  row[1] = temp[5];

  BitArray col{4};
  col[0] = temp[1];
  col[1] = temp[2];
  col[2] = temp[3];
  col[3] = temp[4];

  printf("%lld: %s\n", row.toUint64(), row.toBinString().c_str());
  printf("%lld: %s\n", col.toUint64(), col.toBinString().c_str());
  printf("%lld: %s\n", temp.toUint64(), temp.toBinString().c_str());

}
