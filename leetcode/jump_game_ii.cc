/* Copyright 2013 <ZhiQiang Fan>

   Given an array of non-negative integers, you are initially
   positioned at the first index of the array.

   Each element in the array represents your maximum jump length at
   that position.

   Your goal is to reach the last index in the minimum number of jumps.

   For example:
   Given array A = [2,3,1,1,4]

   The minimum number of jumps to reach the last index is 2. (Jump 1
   step from index 0 to 1, then 3 steps to the last index.)
*/
#include <cstdio>
#include <cstdlib>

class Solution {
  public:
  int jump(int A[], int n) {
    int i, j, k, max, r = 0;

    // process invalid input
    if (n <= 0)
      return 0;

    // process special case
    if (A[0] == 0)
      return 0;

    for (i = 0; i < n - 1; i = k) {
      r++;
      // reach the end
      if (i + A[i] >= n - 1)
        break;
      max = i + A[i];
      // find the longest jump
      for (j = i + 1; j < n && j <= i + A[i]; j++) {
        if (j + A[j] > max) {
          max = j + A[j];
          k = j;
        }
      }
    }

    return r;
  }
};

int main() {
  int a[] = {0};
  Solution s;
  printf("%d\n", s.jump(a, sizeof(a)/sizeof(int)));
  return 0;
}
