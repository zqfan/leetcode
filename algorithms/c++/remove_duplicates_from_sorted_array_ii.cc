/* Copyright 2013 <ZhiQiang Fan>

   Follow up for "Remove Duplicates":
   What if duplicates are allowed at most twice?

   For example,
   Given sorted array A = [1,1,1,2,2,3],

   Your function should return length = 5, and A is now [1,1,2,2,3].
*/
#include <cstdio>

class Solution {
  public:
  int removeDuplicates(int A[], int n) {
    int count, i, j;

    // invalid input
    if (n < 1)
      return 0;

    count = 0;
    for (i = 0, j = 1; j < n; j++) {
      if (A[i] == A[j])
        count++;
      else
        count = 0;
      if (count >= 2)
        continue;
      A[++i] = A[j];
    }

    return i + 1;
  }
};

int main() {
  int a[] = {};
  Solution s;
  int n = s.removeDuplicates(a, sizeof(a)/sizeof(int));
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
