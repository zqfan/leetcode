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

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
 */
#include <cstdio>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
  public:
  bool isMatch(const char *s, const char *p) {
    string ss(s);
    string pp;  // element of p, remove all *
    vector<bool> single;  // indicate the element is single or not
    int i, j, k, l;
    for (i = 0; p[i]; i++) {
      if (p[i] != '*') {
        pp += string(1, p[i]);
        single.push_back(true);
      } else {
        single.back() = false;
      }
    }
    bool m[ss.size()+1][pp.size()+1];  // c99 style
    m[0][0] = true;  // nothing need compare
    for (j = 1; j <= pp.size(); j++)
      m[0][j] = m[0][j-1] && !single[j-1];  // single will always fail
    for (i = 1; i <= ss.size(); i++) {
      m[i][0] = false;  // ss is always single, it will fail
      for (j = 1; j <= pp.size(); j++) {
        // single must match one by one along with previous match
        if (single[j-1]) {
          m[i][j] = ss[i-1] == pp[j-1] || pp[j-1] == '.';
          m[i][j] = m[i][j] && m[i-1][j-1];
          continue;
        }
        // if any previous is match and the remain are same as p[j]
        for (k = 0; k <= i; k++) {
          if (!m[k][j-1])
            continue;
          for (l = k; l < i; l++) {  // remain part must exactly same
            if (ss[l] != pp[j-1] && pp[j-1] != '.')
              break;
          }
          if (l >= i)  // all remain part is same
            break;
        }
        m[i][j] = k <= i;  // there is a match in previous
      }
    }
    return m[ss.size()][pp.size()];
  }
};

int main() {
  char s[100];
  char p[100];
  printf("input two string, return if there are matched\n");
  scanf("%s %s", s, p);
  printf("%d\n", Solution().isMatch(s, p));
  return 0;
}
