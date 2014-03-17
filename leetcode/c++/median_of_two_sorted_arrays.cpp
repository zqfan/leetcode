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

There are two sorted arrays A and B of size m and n respectively. Find
the median of the two sorted arrays. The overall run time complexity
should be O(log (m+n)).
*/
#include <algorithm>

class Solution {
  public:
  // NOTE(zqfan): This solution is **copied** from kedebug@github
  // url: https://github.com/kedebug/leetcode/blob/master/\
  // MedianofTwoSortedArrays/MedianofTwoSortedArrays.cpp
  // I think the point can be optimized is the recursive method
  // can be transformed to loop, but it will be a bit harder to
  // understand and a bit ugly, since the input size will not too
  // large, the recursive cost will not so large
  // This solution will call two times find_k if m+n is even, so it
  // will cost 0.5 times extra time compare to MIT algorithm
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m+n) & 0x01)
      return find_k(A, m, B, n, (m+n+1)/2);
    else
      return (find_k(A, m, B, n, (m+n)/2) +
              find_k(A, m, B, n, (m+n)/2+1)) / 2.0;
  }

  // Find k-th number from sorted a and b
  // The main idea is for each recursive call, remove some part of
  // the a or b. By compare the middle point of a and b, we can know
  // where the k-th locates, and remove the definitely useless part
  int find_k(int A[], int m, int B[], int n, int k) {
    if (m <= 0) return B[k-1];
    if (n <= 0) return A[k-1];
    if (k <= 1) return std::min(A[0], B[0]);

    int ret;
    if (m/2+n/2+2 > k) {  // k is in the lower part
      if (A[m/2] >= B[n/2])  // k is in A lower part or whole b
        ret = find_k(A, m/2, B, n, k);
      else  // k is in b lower part or whole a
        ret = find_k(A, m, B, n/2, k);
    } else {  // k is in higher part
      if (A[m/2] >= B[n/2])  // k is in whole a or b higher part
        ret = find_k(A, m, B+n/2+1, n-n/2-1, k-n/2-1);
      else  // k is in a higher part or whole b
        ret = find_k(A+m/2+1, m-m/2-1, B, n, k-m/2-1);
    }
    return ret;
  }
};

int main() {
  return 0;
}
