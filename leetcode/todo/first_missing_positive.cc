/* Copyright 2013 <ZhiQiang Fan>

   Given an unsorted integer array, find the first missing positive
   integer.

   For example,
   Given [1,2,0] return 3,
   and [3,4,-1,1] return 2.

   Your algorithm should run in O(n) time and uses constant space.
*/
#include <cstdio>

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    int i, min, max, sum, count;

    // invalid input produce invalid output
    if (n <= 0)
      return -1;

    for (i = 0; i < n; i++) {
      if (A[i] > 0)

    return (min + max) * (count + 1) / 2 - sum;
  }
};

int main() {
  int A[] = {3, 4, -1, 2};
  Solution sol;
  printf("%d\n", sol.firstMissingPositive(A, sizeof(A)/sizeof(int)));
  return 0;
}
