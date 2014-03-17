/* Copyright 2013 <ZhiQiang Fan>

   Given two binary strings, return their sum (also a binary string).

   For example,
   a = "11"
   b = "1"
   Return "100".
*/
#include <cstdio>
#include <string>
#include <cassert>
using std::string;

class Solution {
  public:
  string addBinary(string a, string b) {
    // i don't check the input whether they are valid format
    // i don't check the output if there is such "001" input
    string result;
    int i, j, s, d = 0;

    i = a.size() - 1;
    j = b.size() - 1;
    while (i >= 0 && j >= 0) {
      s = a[i] - '0' + b[j] - '0' + d;
      d = s / 2;
      result = string(1, s % 2 + '0') + result;
      i--;
      j--;
    }
    while (i >= 0) {
      s = a[i] - '0' + d;
      d = s / 2;
      result = string(1, s % 2 + '0') + result;
      i--;
    }
    while (j >= 0) {
      s = b[j] - '0' + d;
      d = s / 2;
      result = string(1, s % 2 + '0') + result;
      j--;
    }
    if (d == 1)
      result = string(1, '1') + result;

    return result;
  }
};

int main() {
  Solution s;
  assert(s.addBinary("11", "1").compare("100") == 0);
  assert(s.addBinary("11", "").compare("11") == 0);
  assert(s.addBinary("101", "10").compare("111") == 0);
  assert(s.addBinary("", "111").compare("111") == 0);
  assert(s.addBinary("001", "010").compare("011") == 0);
  return 0;
}
