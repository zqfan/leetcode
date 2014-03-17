/* Copyright 2013 <ZhiQiang Fan>

   Given an array of non-negative integers, you are initially
   positioned at the first index of the array.

   Each element in the array represents your maximum jump length at
   that position.

   Determine if you are able to reach the last index.

   For example:
   A = [2,3,1,1,4], return true.

   A = [3,2,1,0,4], return false.
*/
#include <cstdio>

class Solution {
  public:
  bool canJump(int A[], int n) {
    int i, max_step;

    // invalid input
    if (n < 1)
      return false;

    for (max_step = A[0], i = 0; i < n - 1 && i <= max_step; i++) {
      if (i + A[i] > max_step)
        max_step = i + A[i];
    }

    return max_step >= n - 1;
  }
};

int main() {
  int a[] = {3, 2, 1, 0, 4};
  Solution s;
  printf("%d\n", s.canJump(a, sizeof(a)/sizeof(int)));
  return 0;
}
