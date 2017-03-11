/* Suppose a sorted array is rotated at some pivot unknown to you
   beforehand.

   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

   You are given a target value to search. If found in the array
   return its index, otherwise return -1.

   You may assume no duplicate exists in the array. */
/* it seems to be one of cracking the coding interview */
#include <iostream>
using namespace std;

class Solution {
public:
  int search(int A[], int n, int target) {
    // left of A, left of cur part, ..., middle of A,...
    int la, lc, ra, rc, ma, mc;
    la = 0;
    ra = n - 1;
    while (la <= ra) {
      ma = (la + ra) / 2;
      // if left is sorted, binary search target in left
      if (A[la] <= A[ma]) {
        lc = la;
        rc = ma;
        while (lc <= rc) {
          mc = (lc + rc)/2;
          if (A[mc] == target)
            return mc;
          else if (A[mc] > target)
            rc = mc - 1;
          else
            lc = mc + 1;
        }
        // if target is not in left, search right
        la = ma + 1;
      }
      // then right is sorted, binary search target in right
      else {
        lc = ma + 1;
        rc = ra;
        while (lc <= rc) {
          mc = (lc + rc)/2;
          if (A[mc] == target)
            return mc;
          else if (A[mc] > target)
            rc = mc - 1;
          else
            lc = mc + 1;
        }
        // if target is not in right, search left
        ra = ma;
      }
    }
    return -1; // not find
  }
};

int main() {
  Solution sol;
  int a[] = {5,1,3};
  int n;
  cin >> n;
  cout << sol.search(a, sizeof(a)/sizeof(int), n) << endl;
  return 0;
}
