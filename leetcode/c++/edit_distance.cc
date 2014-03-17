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

Given two words word1 and word2, find the minimum number of steps
required to convert word1 to word2. (each operation is counted as 1
step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <cstdio>
#include <cstring>  // memset
#include <string>
#include <algorithm>
using std::string;

class Solution {
  public:
  int minDistance(string word1, string word2) {
    // like longest common sequence, but with a little difference
    if (word1.size() < word2.size())
      return minDistance(word2, word1);
    int n1 = word1.size();
    int n2 = word2.size();
    if (n1 == 0 && n2 == 0) return 0;
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;
    int *p = new int[n2+1];  // previous line
    // for word1[-1], each word2[0-i] need i step, note the start of i
    for (int i = 0; i <= n2; i++)
      p[i] = i;
    int *c = new int[n2+1];  // current line
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n1; i++) {
      c[0] = i+1;  // for word2[-1], each word1[0-i] need i+1 step
      for (int j = 0; j < n2; j++) {
        // [i][j] = min([i-1][j-1]+{0,1},[i][j-1]+1,[i-1][j]+1)
        int m = p[j];
        if (word1[i] != word2[j]) m++;
        m = std::min(m, c[j]+1);
        c[j+1] = std::min(m, p[j+1]+1);
      }
      std::swap(p, c);
    }
    int ret = p[n2];
    delete []p;
    delete []c;
    return ret;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.minDistance("", ""));
  printf("%d\n", s.minDistance("sea", "ate"));
  return 0;
}
