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

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1
and s2.
For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
#include <cstdio>
#include <cstring>  // memset
#include <string>
using std::string;

class Solution {
  public:
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();
    if (n1 + n2 != n3)
      return false;
    // s[i][j] is true means for s1.substr(0,i), s2.substr(0, j),
    // s3.substr(0, i+j=k) is interleaving
    // if s[i-1][j] and s1[i-1]==s3[k-1], s[i][j] is true
    // if s[i][j-1] and s2[j-1]==s3[k-1], s[i][j] is true
    bool s[n1+1][n2+1];
    memset(s, 0, sizeof(s));
    s[0][0] = true;  // empty is interleaving of two empty substr
    for (int k = 1; k <= n3; k++) {
      // test all possible in s1
      for (int i = 0; i <= n1 && i <= k; i++) {
        int j = k - i;
        if (i > 0 && s[i-1][j] && s1[i-1] == s3[k-1])
          s[i][j] = true;
        if (j > 0 && s[i][j-1] && s2[j-1] == s3[k-1])
          s[i][j] = true;
      }
    }
    return s[n1][n2];
  }
};

int main() {
  string s1 = "aabcc";
  string s2 = "dbbca";
  string s3 = "aadbbcbcac";
  Solution s;
  printf("%d\n", s.isInterleave(s1, s2, s3));
  s3 = "aadbbbaccc";
  printf("%d\n", s.isInterleave(s1, s2, s3));
  return 0;
}
