/*
Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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

Given a string s1, we may represent it as a binary tree by
partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its
two children.
Given two strings s1 and s2 of the same length, determine if s2 is a
scrambled string of s1.
*/
#include <cstdio>
#include <cstring>  // memset
#include <string>
#include <algorithm>
using std::string;

class Solution {
  public:
  bool isScramble(string s1, string s2) {
    // NOTE(zqfan): This solution is learn from bysun@leetcode
    // url:http://discuss.leetcode.com/questions/262/scramble-string
    // Let f[i][j][l] indicates s1.substr(i, l) and s2.substr(j, l)
    // is scramble. to get f[i][j][l], we need to check n from 1 to l-1
    // f[i][j][n] && f[i+n][j+n][l-n] || f[i][j+l-n][n] &&
    // f[i+n][j][l-n], if any pair of sub range is true, then
    // f[i][j][l] is scramble
    int n = s1.size();
    if (n != s2.size()) return false;  // not same length
    if (n == 0) return true;  // s1 and s2 both empty
    bool f[n][n][n+1];
    memset(f, 0, sizeof(f));
    int i, j, k, l;
    // init f
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        f[i][j][1] = s1[i] == s2[j];
      }
    }
    for (i = n-1; i >= 0; i--) {
      for (j = n-1; j >= 0; j--) {
        // to avoid out of range
        int m = std::min(n-i, n-j);
        // try every length
        for (k = 2; k <= m; k++) {
          for (l = 1; l < k; l++) {
            // left compare left
            bool ll = f[i][j][l] && f[i+l][j+l][k-l];
            // left compare right
            bool lr = f[i][j+k-l][l] && f[i+l][j][k-l];
            // if any one is true, then f[i][j][k] is true
            f[i][j][k] = f[i][j][k] || ll || lr;
            // yes, it is scramble, break to avoid useless compute
            if (f[i][j][k]) break;
          }
        }
      }
    }
    return f[0][0][n];
  }
};

int main() {
  Solution s;
  printf("%d\n", s.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb"));
  return 0;
}
