/* Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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

Implement next permutation, which rearranges numbers into the
lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the
lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its
corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
  public:
  void nextPermutation(vector<int> &num) {
    int i, tmp;
    vector<int>::iterator p;
    // from right to left find first non-descend seq
    for (i = num.size() - 1; i > 0; i--) {
      if (num[i] > num[i-1])
        break;
    }
    // the entire vector is descend seq
    if (i == 0) {
      std::sort(num.begin(), num.end());
      return;
    }
    // swap first element larger than num[i-1]
    // It means slightly move to next permutation, which may jump too
    // far
    // sort it for upper_bound binary search
    std::sort(num.begin()+i, num.end());
    p = std::upper_bound(num.begin()+i, num.end(), num[i-1]);
    // there must be such an element, so no need to check p
    // swap(*p, num[i-1]), the following is a tricky to avoid extra
    // memory: swap(a, b): b = a - b; a = a - b; b = a + b;
    // however, i think a - b may cause overflow, like INT_MIN-INT_MAX
    tmp = *p;
    *p = num[i-1];
    num[i-1] = tmp;
    // now, i sort the previous range of non-descend seq, and get
    // next permutation
    std::sort(num.begin()+i, num.end());
  }
};

int main() {
  int a[] = {1, 1, 5};
  vector<int> num(a, a+sizeof(a)/sizeof(int));
  Solution s;
  s.nextPermutation(num);
  for (int i = 0; i < num.size(); i++)
    printf("%d ", num[i]);
  printf("\n");
  return 0;
}
