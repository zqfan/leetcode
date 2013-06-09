/* Copyright 2013 <ZhiQiang Fan>

   Find the contiguous subarray within an array (containing at least
   one number) which has the largest sum.

   For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
   the contiguous subarray [4,−1,2,1] has the largest sum = 6.

   Yet another problem of ctci
*/
#include <cstdio>

class Solution {
  public:
  int maxSubArray(int A[], int n) {
    int max_sum, sum, i;

    // invalid input
    if (n < 1)
      return 0;

    max_sum = A[0];
    sum = 0;
    for (i = 0; i < n; i++) {
      if (sum <= 0)
        sum = A[i];
      else
        sum += A[i];
      if (sum > max_sum)
        max_sum = sum;
    }

    return max_sum;
  }
};

int main() {
  int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution s;
  int r = s.maxSubArray(a, sizeof(a)/sizeof(int));
  printf("%d\n", r);
  return 0;
}
