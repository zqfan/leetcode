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

Given n non-negative integers representing an elevation map where the
width of each bar is 1, compute how much water it is able to trap
after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include <cstdio>

class Solution {
  public:
  int trap(int A[], int n) {
    int ret = 0;
    int m = 0;
    int i = 0;
    for (int j = i + 1; j < n; j++) {
      // search higher bar
      if (A[j] >= A[i]) {
        ret += m;
        m = 0;
        i = j;
        continue;
      }
      // trapped water
      m += A[i] - A[j];
    }
    // from the highest bar to end is not computed
    // search reverse direction
    int k = n - 1;
    m = 0;
    for (int j = k; j >= i; j--) {
      if (A[j] >= A[k]) {
        ret += m;
        m = 0;
        k = j;
      }
      // trapped water
      m += A[k] - A[j];
    }
    return ret;
  }
};

int main() {
  int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  Solution s;
  printf("%d\n", s.trap(A, sizeof(A)/sizeof(int)));
  return 0;
}
