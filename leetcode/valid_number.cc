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

class Solution {
  public:
  bool isNumber(const char *s) {
    int i = -1;
    // ignore leading blank
    while (s[++i]) {
      if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        break;
    }
    if (!s[i]) return false;  // empty string
    // ignore leading +/-
    if (s[i] == '+' || s[i] == '-')
      i++;
    bool dp = false;  // has decimal point
    bool e = false;  // is exponent number
    bool ob = false;  // only blank, for trailing blanks
    bool d = false;  // at least has one digit character
    while (s[i]) {
      if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
        ob = true;
      } else if (ob) {
        // only blank is valid but not blank
        return false;
      } else if (s[i] == '.') {
        if (dp)
          return false;  // only one decimal point is valid
        else
          dp = true;
      } else if (s[i] == 'e' || s[i] == 'E') {
        if (e || !d) {  // unique e and at least one digit before it
          return false;
        } else {
          dp = e = true;  // the exponent part disable decimal point
          d = false;  // there must be at least one digit after 'e'
          if (s[i+1] == '+' || s[i+1] == '-')
            i++;  // jump over exponent part leading +/-
        }
      } else if ('0' > s[i] || s[i] > '9') {
        // deny character not in 0-9, also deny 16 based string
        return false;
      } else {  // 0-9
        d = true;
      }
      i++;
    }
    return d;  // must have digit character
  }
};

int main() {
  char str[100];
  Solution s;
  printf("input a string, i will judge it is numeric or not\n");
  scanf("%[^\n]", str);
  printf("%d\n", s.isNumber(str));
  return 0;
}
