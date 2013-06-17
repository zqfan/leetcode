/* Copyright 2013 <ZhiQiang Fan>

   Given an unsorted integer array, find the first missing positive
   integer.

   For example,
   Given [1,2,0] return 3,
   and [3,4,-1,1] return 2.

   Your algorithm should run in O(n) time and uses constant space.
*/
#include <cstdio>
#include <algorithm>

class Solution {
public:
  // try to let A[i] holds i, so with one scan i can find the missing
  // one, if A[i] doesn't hold i, then put A[i] in the correct place,
  // and store the correct place's number, and process again.
  // the adjust position will cause O(n)
  int firstMissingPositive(int A[], int n) {
    int i;

    for (i = 0; i < n; i++) {
      if (A[i] > n || A[i] <= 0)
        continue;
      if (A[i] - 1 != i && A[A[i]-1] != A[i]) {
        std::swap(A[i], A[A[i]-1]);
        i--;
      }
    }

    for (i = 0; i < n; i++)
      if (A[i] - 1 != i)
        return i + 1;
    return n + 1;
  }
};

int main() {
  int A[] = {3, 4, 5, 1, 2};
  Solution sol;
  printf("%d\n", sol.firstMissingPositive(A, sizeof(A)/sizeof(int)));
  return 0;
}
