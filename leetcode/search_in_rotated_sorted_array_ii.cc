/* Copyright 2013 <ZhiQiang Fan>

   Follow up for "Search in Rotated Sorted Array":
   What if duplicates are allowed?

   Would this affect the run-time complexity? How and why?

   Write a function to determine if a given target is in the array.
*/
/* Yes, it affect the previous solution, 'cause i can no longer
   determine which part is in order and use binary search.
   for i.e. a[]=[1,2,1,1,1], mid is a[2], and a[0]<=a[2]<=a[1].

   So, i think the complexity drop to O(n).
*/
#include <cstdio>

class Solution {
  public:
  bool search(int A[], int n, int target) {
    for (int i = 0; i < n; i++)
      if (A[i] == target)
        return true;
    return false;
  }
};

int main() {
  int a[] = {1, 2, 1, 1, 1};
  Solution s;
  printf("%d\n", s.search(a, sizeof(a)/sizeof(int), 2));
  return 0;
}
