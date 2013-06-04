/* Copyright 2013 <ZhiQiang Fan>

   Given n non-negative integers representing an elevation map where
   the width of each bar is 1, compute how much water it is able to
   trap after raining.

   For example,
   Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include <cstdio.h>

class Solution {
public:
  int trap(int A[], int n) {
    int high_left, high_right, low, i;
    high_left = high_right = 0;
    for (i = 1; i < n; i++) {
      if (A[i] > A[i-1])
  }
};

int main() {
  return 0;
}
