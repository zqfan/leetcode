/* Copyright 2013 <ZhiQiang Fan>

   Validate if a given string is numeric.

   Some examples:
   "0" => true
   " 0.1 " => true
   "abc" => false
   "1 a" => false
   "2e10" => true

   Note: It is intended for the problem statement to be ambiguous.
   You should gather all requirements up front before implementing
   one.
*/
#include <cstdio>
#include <cassert>

class Solution {
  public:
  bool isNumber(const char *s) {
  }
};

int main() {
  Solution s;
  assert(s.isNumber("") == false);
  assert(s.isNumber("123"));
  assert(s.isNumber(".23"));
  assert(s.isNumber("1.23"));
  assert(s.isNumber("0xff"));
  assert(s.isNumber("0xfg") == false);
  assert(s.isNumber("123e-123"));
  assert(s.isNumber("0.123E200"));
  return 0;
}
