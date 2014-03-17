/*
Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a
challenge, please do not see below and ask yourself what are the
possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie,
no given input specs). You are responsible to gather all the input
requirements up front.
*/
#include <cstdio>
#include <cstdlib>  // atoi, just for unit test
#include <climits>  // INT_MAX, INT_MIN
#include <string>

class Solution {
  public:
  // i test some case with cstdlib's function atoi, it is just accept
  // 10 based integer, so it is much simple, i just need to consider
  // +/-, overflow, and leading blank
  int atoi(const char *str) {
    unsigned int r;  // using unsigned to store overflow value
    unsigned int b;
    int i = -1;
    while (str[++i]) {
      // blank
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        break;
    }
    if (!str[i]) return 0;
    switch (str[i]) {
    case '-':
      r = _atoi(str+i+1);
      // negative bound
      b = static_cast<unsigned int>(INT_MAX) + 1;
      return r >= b ? INT_MIN : -static_cast<int>(r);
    case '+':
      i++;
    default:
      r = _atoi(str+i);
      return r >= INT_MAX ? INT_MAX : static_cast<int>(r);
    }
  }

  unsigned int _atoi(const char * str, int base = 10) {
    unsigned int r = 0;
    int i = -1;
    while (str[++i] != '\0') {
      if ('0' > str[i] || str[i] > '9')
        return r;
      if (r > INT_MAX/base)
        return static_cast<unsigned int>(INT_MAX)+1;
      r = r*base + str[i] - '0';
    }
    return r;
  }
};

int main() {
  Solution s;
  std::string str = "-12345678901234567890";
  printf("%d\n", s.atoi(str.c_str()) == atoi(str.c_str()));
  printf("%d\n", s.atoi("0111") == atoi("0111"));
  return 0;
}
