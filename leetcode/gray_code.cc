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

The gray code is a binary numeral system where two successive values
differ in only one bit.
Given a non-negative integer n representing the total number of bits
in the code, print the sequence of gray code. A gray code sequence
must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to
the above definition.
For now, the judge is able to judge based on one instance of gray code
sequence. Sorry about that.
*/
#include <cstdio>
#include <cmath>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<int> grayCode(int n) {
    vector<int> r(1, 0);  // result
    if (n == 0)
      return r;
    r.push_back(1);
    for (int i = 1; i < n; i++) {
      int p = pow(2, i);
      for (int j = r.size() - 1; j >= 0; j--) {
        r.push_back(p+r[j]);
      }
    }
    return r;
  }
};

int main() {
  Solution s;
  vector<int> r = s.grayCode(4);
  for (int i = 0; i < r.size(); i++)
    printf("%d ", r[i]);
  printf("\n");
  return 0;
}
