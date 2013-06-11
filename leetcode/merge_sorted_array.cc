/* Copyright 2013 <ZhiQiang Fan>

   Given two sorted integer arrays A and B, merge B into A as one
   sorted array.

   Note:
   You may assume that A has enough space to hold additional elements
   from B. The number of elements initialized in A and B are m and n
   respectively.
*/
#include <cstdio>

class Solution {
  public:
  void merge(int A[], int m, int B[], int n) {
    // write from end to front;
    int k = m + n;
    while (--k >= 0) {
      // B has no element left or A has element left and larger than B
      if (n <= 0 || (m > 0 && A[m - 1] > B[n - 1]))
        A[k] = A[--m];
      else
        A[k] = B[--n];
    }
  }
};

int main() {
  int a[9] = {0, 1, 3, 5, 7, 0, 0, 0, 0};
  int b[] = {2, 4, 6, 8};
  Solution s;
  s.merge(a, 5, b, sizeof(b)/sizeof(int));
  for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
